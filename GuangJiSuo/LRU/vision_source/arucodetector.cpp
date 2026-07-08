#include "arucoDetector.h"
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QStringList>

ArucoDetector::ArucoDetector(QObject *parent) : QObject(parent)
{
    aruco_to_gapx  = 0.0f;
    aruco_to_gapy  = 0.0f;
    camera_to_lrux_50 = 0.0f;
    camera_to_lruy_50 = 0.0f;
    camera_to_lrux_16 = 0.0f;
    camera_to_lruy_16 = 0.0f;
    marker_id    = 0;
    angle_offset = 0.0f;

    x_offset  = 0.0f;
    y_offset  = 0.0f;
    rz_offset = 0.0f;

    // 1. 初始化字典
    m_arucoDict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

    // 2. 初始化检测参数（与 Python 版本一致）
    m_parameters = cv::aruco::DetectorParameters();
    m_parameters.minMarkerPerimeterRate   = 0.077;
    m_parameters.cornerRefinementMethod   = cv::aruco::CORNER_REFINE_APRILTAG; // 亚像素精炼
    m_parameters.adaptiveThreshWinSizeMin = 9;
    m_parameters.adaptiveThreshWinSizeMax = 53;
    m_parameters.adaptiveThreshConstant   = 7;

    // 3. 初始化检测器
    m_detector = cv::makePtr<cv::aruco::ArucoDetector>(m_arucoDict, m_parameters);
}

ArucoDetector::ArucoResult ArucoDetector::detectOneArucoCode(cv::Mat &image)
{
    ArucoResult result;
    result.detected = false;

    if (m_intrinsicMatrix.empty() || m_distCoeffs.empty()) {
        qWarning() << "相机参数为空！";
        return result;
    }

    if (image.empty()) {
        qWarning() << "图片为空！";
        return result;
    }

    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> corners;

    m_detector->detectMarkers(image, corners, ids);

    if (ids.empty()) {
        qWarning() << "二维码ID为空，检测失败！";
        return result;
    }

    // 图像中心 (2592x1944)
    const cv::Point2f imageCenter(1296.0f, 972.0f);

    // 1. 收集所有 ID 匹配的二维码索引
    std::vector<size_t> matchingIndices;
    for (size_t i = 0; i < ids.size(); ++i) {
        if (ids[i] == marker_id) {
            matchingIndices.push_back(i);
        }
    }

    if (matchingIndices.empty()) {
        qWarning() << "未找到目标ID(" << marker_id << ")，检测失败！";
        return result;
    }

    int selectedIndex = -1;

    // 2. 多个匹配时，选中心离图像中心最近的那个
    if (matchingIndices.size() == 1) {
        selectedIndex = static_cast<int>(matchingIndices[0]);
    } else {
        float minDistSq = std::numeric_limits<float>::max();

        for (size_t idx : matchingIndices) {
            const auto &currentCorners = corners[idx];

            cv::Point2f markerCenter(0.0f, 0.0f);
            for (const auto &p : currentCorners) {
                markerCenter.x += p.x;
                markerCenter.y += p.y;
            }
            markerCenter.x /= 4.0f;
            markerCenter.y /= 4.0f;

            float dx = markerCenter.x - imageCenter.x;
            float dy = markerCenter.y - imageCenter.y;
            float distSq = dx * dx + dy * dy;

            if (distSq < minDistSq) {
                minDistSq = distSq;
                selectedIndex = static_cast<int>(idx);
            }
        }
    }

    std::vector<cv::Point2f> markerCorners = corners[selectedIndex];
    markerCorners = sortCornersTLTRBRBL(markerCorners);
    result.id           = ids[selectedIndex];
    result.detected     = true;
    result.cornerPixels = markerCorners;

    return result;
}

// =============================================================================
//                    PnP 位姿求解
// =============================================================================
ArucoDetector::PoseResult
ArucoDetector::solvePnPPose(const std::vector<cv::Point2f> &cornerPixels,
                            float arucoSizeMm)
{
    PoseResult pose;
    pose.valid = false;
    pose.reprojectionError = std::numeric_limits<double>::max();

    // 参数检查
    if (cornerPixels.size() != 4) {
        qWarning() << "PnP失败：角点数量必须为4";
        return pose;
    }
    if (m_intrinsicMatrix.empty() || m_distCoeffs.empty()) {
        qWarning() << "PnP失败：相机内参或畸变系数为空";
        return pose;
    }

    cv::Point2f mid1 = (cornerPixels[0] + cornerPixels[1]) * 0.5f;
    cv::Point2f mid2 = (cornerPixels[2] + cornerPixels[3]) * 0.5f;
    float dx = mid2.x - mid1.x;
    float dy = mid2.y - mid1.y;
    // 与 y 轴的夹角，单位：弧度
    double angleRad = std::atan2(dx, dy);
    // 转成角度
    double angleDeg = angleRad * 180.0 / CV_PI;

    // 1. 构造 marker 平面 4 个 3D 点（IPPE_SQUARE 要求的固定顺序）
    //    左上、右上、右下、左下（Y-up 标准 marker 坐标系）
    const float half = arucoSizeMm / 2.0f;
    std::vector<cv::Point3f> objectPoints = {
        cv::Point3f(-half,  half, 0.f),
        cv::Point3f( half,  half, 0.f),
        cv::Point3f( half, -half, 0.f),
        cv::Point3f(-half, -half, 0.f)
    };

    // 2. 调用 solvePnPGeneric 拿到 IPPE_SQUARE 的多解（通常 2 个）
    std::vector<cv::Mat> rvecs, tvecs;
    int solutions = 0;
    try {
        solutions = cv::solvePnPGeneric(
            objectPoints,
            cornerPixels,
            m_intrinsicMatrix,
            m_distCoeffs,
            rvecs,
            tvecs,
            false,                      // 不使用 extrinsicGuess
            cv::SOLVEPNP_IPPE_SQUARE
            );
    } catch (const cv::Exception &e) {
        qWarning() << "solvePnPGeneric 异常：" << e.what();
        return pose;
    }

    if (solutions <= 0 || rvecs.empty() || tvecs.empty()) {
        qWarning() << "PnP求解失败：无有效解";
        return pose;
    }

    cv::Vec3d bestRvec, bestTvec;
    double    bestErr   = std::numeric_limits<double>::max();
    double    bestR22   = -2.0;   // R(2,2) 取值范围 [-1,1]，初始给一个不可能值
    bool      foundPositiveZ = false;
    cv::Vec3d fallbackRvec, fallbackTvec;
    double    fallbackErr = std::numeric_limits<double>::max();
    for (size_t i = 0; i < rvecs.size(); ++i) {
        cv::Vec3d rv(rvecs[i].at<double>(0),
                     rvecs[i].at<double>(1),
                     rvecs[i].at<double>(2));
        cv::Vec3d tv(tvecs[i].at<double>(0),
                     tvecs[i].at<double>(1),
                     tvecs[i].at<double>(2));
        // 重投影误差
        std::vector<cv::Point2f> projected;
        cv::projectPoints(objectPoints, rv, tv,
                          m_intrinsicMatrix, m_distCoeffs, projected);
        double sumErr = 0.0;
        for (size_t k = 0; k < projected.size(); ++k) {
            double dx = projected[k].x - cornerPixels[k].x;
            double dy = projected[k].y - cornerPixels[k].y;
            sumErr += std::sqrt(dx * dx + dy * dy);
        }
        double meanErr = sumErr / static_cast<double>(projected.size());
        // 计算 marker 法向朝向相机的程度：旋转矩阵 R(2,2)
        cv::Mat Ri;
        cv::Rodrigues(rv, Ri);
        double r22 = Ri.at<double>(2, 2);   // 越接近 1，越正对相机
        // fallback：所有解里误差最小的
        if (meanErr < fallbackErr) {
            fallbackErr  = meanErr;
            fallbackRvec = rv;
            fallbackTvec = tv;
        }
        // 只考虑 Z>0 的物理合法解
        if (tv[2] <= 0) continue;
        // ★ 选解策略：
        //   1) 若 r22 明显更大（差 > 0.05，约 18°）→ 直接选它
        //   2) 若 r22 差不多 → 选 reprojErr 更小的
        bool takeIt = false;
        if (!foundPositiveZ) {
            takeIt = true;
        } else {
            double dR = r22 - bestR22;
            if (dR > 0.05) {
                takeIt = true;                          // 法向明显更朝向相机
            } else if (std::abs(dR) <= 0.05 && meanErr < bestErr) {
                takeIt = true;                          // 法向接近，比误差
            }
        }
        if (takeIt) {
            bestRvec = rv;
            bestTvec = tv;
            bestErr  = meanErr;
            bestR22  = r22;
            foundPositiveZ = true;
        }
    }

    if (foundPositiveZ) {
        pose.rvec              = bestRvec;
        pose.tvec              = bestTvec;
        pose.reprojectionError = bestErr;
    } else {
        pose.rvec              = fallbackRvec;
        pose.tvec              = fallbackTvec;
        pose.reprojectionError = fallbackErr;
    }

    // 4. 旋转向量 -> 旋转矩阵
    cv::Rodrigues(pose.rvec, pose.rotationMatrix);

    // 5. 旋转矩阵 -> 欧拉角（度）
    rotationVectorToEuler(pose.rvec, pose.roll, pose.pitch, pose.yaw);
    pose.yaw = angleDeg;

    pose.valid = true;
    return pose;
}

// =============================================================================
//   旋转向量 -> 欧拉角（内旋 X-Y-Z，等价于外旋 Z-Y-X），与 Python 版本保持一致
//   roll  = 绕 X 轴
//   pitch = 绕 Y 轴
//   yaw   = 绕 Z 轴
// =============================================================================
void ArucoDetector::rotationVectorToEuler(const cv::Vec3d &rvec,
                                          double &roll,
                                          double &pitch,
                                          double &yaw)
{
    cv::Mat R;
    cv::Rodrigues(rvec, R);

    double r00 = R.at<double>(0, 0);
    double r10 = R.at<double>(1, 0);
    double r20 = R.at<double>(2, 0);
    double r21 = R.at<double>(2, 1);
    double r22 = R.at<double>(2, 2);
    double r11 = R.at<double>(1, 1);
    double r12 = R.at<double>(1, 2);

    double sy = std::sqrt(r00 * r00 + r10 * r10);
    bool singular = sy < 1e-6;

    double x, y, z;
    if (!singular) {
        x = std::atan2(r21, r22);
        y = std::atan2(-r20, sy);
        z = std::atan2(r10, r00);
    } else {
        // gimbal lock：pitch ≈ ±90°
        x = std::atan2(-r12, r11);
        y = std::atan2(-r20, sy);
        z = 0.0;
    }

    // 弧度 -> 度
    roll  = x * 180.0 / M_PI;
    pitch = y * 180.0 / M_PI;
    yaw   = z * 180.0 / M_PI;
}

void ArucoDetector::clearCameraParams()
{
    m_intrinsicMatrix.release();
    m_distCoeffs.release();
    m_rotationMatrix.release();
    m_translationVector.release();
}

bool ArucoDetector::failCameraParamsRead(const QString &message)
{
    qWarning() << message;
    arucoUpdateUI(message);
    clearCameraParams();
    return false;
}

QString ArucoDetector::resolveCameraParamsPath(const QString &jsonPath) const
{
    QFileInfo directInfo(jsonPath);
    if (directInfo.isAbsolute() && directInfo.exists() && directInfo.isFile()) {
        return directInfo.absoluteFilePath();
    }

    QStringList candidates;
    candidates << QCoreApplication::applicationDirPath() + QDir::separator() + jsonPath;
    candidates << QDir::currentPath() + QDir::separator() + jsonPath;
    candidates << jsonPath;

    for (const QString &candidate : candidates) {
        QFileInfo info(candidate);
        if (info.exists() && info.isFile()) {
            return info.absoluteFilePath();
        }
    }

    return QString();
}

bool ArucoDetector::readCameraParamsFromJson(const QString &jsonPath)
{
    clearCameraParams();

    const QString resolvedPath = resolveCameraParamsPath(jsonPath);
    if (resolvedPath.isEmpty()) {
        QString msg = QString("相机标定文件不存在: %1, appDir=%2, cwd=%3")
                          .arg(jsonPath)
                          .arg(QCoreApplication::applicationDirPath())
                          .arg(QDir::currentPath());
        return failCameraParamsRead(msg);
    }

    QFile file(resolvedPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString msg = QString("相机标定文件无法打开: %1, error=%2")
                          .arg(resolvedPath)
                          .arg(file.errorString());
        return failCameraParamsRead(msg);
    }

    QByteArray data = file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError || !doc.isObject()) {
        QString msg = QString("相机标定JSON解析失败: %1, offset=%2, error=%3")
                          .arg(resolvedPath)
                          .arg(parseError.offset)
                          .arg(parseError.errorString());
        return failCameraParamsRead(msg);
    }

    QJsonObject obj = doc.object();

    // 读取内参矩阵
    if (!obj.contains("camera_matrix") || !obj["camera_matrix"].isArray()) {
        return failCameraParamsRead(QString("相机标定参数缺失: camera_matrix, file=%1").arg(resolvedPath));
    }
    {
        const QJsonArray arr = obj["camera_matrix"].toArray();
        if (arr.size() != 3) {
            return failCameraParamsRead(QString("相机标定参数格式错误: camera_matrix 必须为3x3, file=%1").arg(resolvedPath));
        }
        m_intrinsicMatrix = cv::Mat::zeros(3, 3, CV_64F);
        for (int i = 0; i < 3; ++i) {
            if (!arr[i].isArray() || arr[i].toArray().size() != 3) {
                return failCameraParamsRead(QString("相机标定参数格式错误: camera_matrix 必须为3x3, file=%1").arg(resolvedPath));
            }
            const QJsonArray row = arr[i].toArray();
            for (int j = 0; j < 3; ++j) {
                if (!row[j].isDouble()) {
                    return failCameraParamsRead(QString("相机标定参数格式错误: camera_matrix 包含非数字, file=%1").arg(resolvedPath));
                }
                m_intrinsicMatrix.at<double>(i, j) = row[j].toDouble();
            }
        }
    }

    // 读取畸变系数（二维数组形式 [[k1,k2,p1,p2,k3]]）
    if (!obj.contains("distortion_coefficients") || !obj["distortion_coefficients"].isArray()) {
        return failCameraParamsRead(QString("相机标定参数缺失: distortion_coefficients, file=%1").arg(resolvedPath));
    }
    {
        const QJsonArray outerArr = obj["distortion_coefficients"].toArray();
        if (outerArr.size() < 1 || !outerArr[0].isArray()) {
            return failCameraParamsRead(QString("相机标定参数格式错误: distortion_coefficients, file=%1").arg(resolvedPath));
        }
        const QJsonArray innerArr = outerArr[0].toArray();
        if (innerArr.size() < 4) {
            return failCameraParamsRead(QString("相机标定参数格式错误: distortion_coefficients 至少需要4个数, file=%1").arg(resolvedPath));
        }
        m_distCoeffs = cv::Mat::zeros(innerArr.size(), 1, CV_64F);
        for (int i = 0; i < innerArr.size(); ++i) {
            if (!innerArr[i].isDouble()) {
                return failCameraParamsRead(QString("相机标定参数格式错误: distortion_coefficients 包含非数字, file=%1").arg(resolvedPath));
            }
            m_distCoeffs.at<double>(i) = innerArr[i].toDouble();
        }
    }

    // 读取旋转矩阵
    if (!obj.contains("rotation_matrix") || !obj["rotation_matrix"].isArray()) {
        return failCameraParamsRead(QString("相机标定参数缺失: rotation_matrix, file=%1").arg(resolvedPath));
    }
    {
        const QJsonArray arr = obj["rotation_matrix"].toArray();
        if (arr.size() != 3) {
            return failCameraParamsRead(QString("相机标定参数格式错误: rotation_matrix 必须为3x3, file=%1").arg(resolvedPath));
        }
        m_rotationMatrix = cv::Mat::zeros(3, 3, CV_64F);
        for (int i = 0; i < 3; ++i) {
            if (!arr[i].isArray() || arr[i].toArray().size() != 3) {
                return failCameraParamsRead(QString("相机标定参数格式错误: rotation_matrix 必须为3x3, file=%1").arg(resolvedPath));
            }
            const QJsonArray row = arr[i].toArray();
            for (int j = 0; j < 3; ++j) {
                if (!row[j].isDouble()) {
                    return failCameraParamsRead(QString("相机标定参数格式错误: rotation_matrix 包含非数字, file=%1").arg(resolvedPath));
                }
                m_rotationMatrix.at<double>(i, j) = row[j].toDouble();
            }
        }
    }

    // 读取平移向量
    if (!obj.contains("translation_vector") || !obj["translation_vector"].isArray()) {
        return failCameraParamsRead(QString("相机标定参数缺失: translation_vector, file=%1").arg(resolvedPath));
    }
    {
        const QJsonArray arr = obj["translation_vector"].toArray();
        if (arr.size() != 3) {
            return failCameraParamsRead(QString("相机标定参数格式错误: translation_vector 必须为3个数, file=%1").arg(resolvedPath));
        }
        m_translationVector = cv::Mat::zeros(3, 1, CV_64F);
        for (int i = 0; i < 3; ++i) {
            if (!arr[i].isDouble()) {
                return failCameraParamsRead(QString("相机标定参数格式错误: translation_vector 包含非数字, file=%1").arg(resolvedPath));
            }
            m_translationVector.at<double>(i) = arr[i].toDouble();
        }
    }

    return true;
}

QString ArucoDetector::getCameraParamsFile(float z)
{
    if (-0.5 <= z && z <= 0.5) {
        return "vision/resource/calibration_results_opcv/camera_calibration_50.json";
    } else if(1699.5 <=z && z<= 1700.5) {
        return "vision/resource/calibration_results_opcv/camera_calibration_16.json";
    }
    return QString();
}

ArucoDetector::PlanarPose ArucoDetector::processImage(cv::Mat &image, float z)
{
    // 内部调用详细检测，降级返回 PlanarPose
    DetailedFrameResult detailed = processImageDetailed(image, z);
    PlanarPose result{false, 0.0, 0.0, 0.0};
    if (detailed.valid) {
        result.valid = true;
        result.x = detailed.x;
        result.y = detailed.y;
        result.yaw = detailed.yaw;
    }
    return result;
}

ArucoDetector::DetailedFrameResult ArucoDetector::processImageDetailed(cv::Mat &image, float z)
{
    DetailedFrameResult result;

    // 1. 读取相机参数
    QString paramsFile = getCameraParamsFile(z);
    if (paramsFile.isEmpty()) {
        result.failureReason = QString("当前高度(%1)无匹配相机标定参数").arg(z, 0, 'f', 1);
        qWarning() << result.failureReason;
        return result;
    }
    if (!readCameraParamsFromJson(paramsFile)) {
        result.failureReason = QString("读取相机标定参数失败: %1").arg(paramsFile);
        qWarning() << result.failureReason;
        return result;
    }

    // 2. 检测 ArUco 码
    ArucoResult detection = detectOneArucoCode(image);
    if (!detection.detected) {
        result.failureReason = "检测二维码失败";
        qWarning() << result.failureReason;
        return result;
    }
    result.targetIdFound = true;

    // ★ 搜索线索：计算 marker 中心与图像中心的偏移
    {
        result.targetSeen = true;
        result.imageCenterX = image.cols / 2.0;
        result.imageCenterY = image.rows / 2.0;
        double cx = 0, cy = 0;
        for (const auto &pt : detection.cornerPixels) {
            cx += pt.x;
            cy += pt.y;
        }
        cx /= detection.cornerPixels.size();
        cy /= detection.cornerPixels.size();
        result.markerCenterX = cx;
        result.markerCenterY = cy;
        result.markerOffsetPxX = cx - result.imageCenterX;
        result.markerOffsetPxY = cy - result.imageCenterY;
        result.hasSearchHint = true;
    }

    // 3. 检查角点数量
    if (detection.cornerPixels.size() != 4) {
        result.hasFourCorners = false;
        result.failureReason = QString("角点数量为%1，预期4个").arg(detection.cornerPixels.size());
        qWarning() << result.failureReason;
        return result;
    }

    // 4. 检查角点是否贴边或出画
    int margin = m_cornerBorderMarginPx;
    int w = image.cols;
    int h = image.rows;
    for (const auto &pt : detection.cornerPixels) {
        if (pt.x <= margin || pt.x >= (w - margin) ||
            pt.y <= margin || pt.y >= (h - margin)) {
            result.cornersInBounds = false;
            result.failureReason = "角点贴边或出画";
            qWarning() << result.failureReason;
            return result;
        }
    }

    // 5. PnP 解算
    PoseResult pose = solvePnPPose(detection.cornerPixels, m_markerSizeMm);
    if (!pose.valid) {
        result.pnpSuccess = false;
        result.failureReason = "PnP位姿计算失败";
        qWarning() << result.failureReason;
        return result;
    }
    result.pnpSuccess = true;
    result.reprojectionError = pose.reprojectionError;

    // ★ 搜索线索：存储修正前的 PnP tvec
    {
        result.hasPnpHint = true;
        result.hintTvecX = pose.tvec[0];
        result.hintTvecY = pose.tvec[1];
        result.hasSearchHint = true;
    }

    // 6. 检查重投影误差
    if (pose.reprojectionError > m_reprojectionErrorMaxPx) {
        result.failureReason = QString("重投影误差过大: %1 px (阈值: %2)")
                                   .arg(pose.reprojectionError, 0, 'f', 2)
                                   .arg(m_reprojectionErrorMaxPx, 0, 'f', 1);
        qWarning() << result.failureReason;
        return result;
    }

    // 7. 打印位姿信息到文件日志
    qInfo() << QString("PnP成功 | 重投影误差: %1 px | tvec(mm): X=%2 Y=%3 Z=%4 | Euler(deg): Roll=%5 Pitch=%6 Yaw=%7")
                   .arg(pose.reprojectionError, 0, 'f', 4)
                   .arg(pose.tvec[0], 0, 'f', 2)
                   .arg(pose.tvec[1], 0, 'f', 2)
                   .arg(pose.tvec[2], 0, 'f', 2)
                   .arg(pose.roll,  0, 'f', 2)
                   .arg(pose.pitch, 0, 'f', 2)
                   .arg(pose.yaw,   0, 'f', 2);

    // 8. 矩形框对齐模型：用"前左角 + 后右角"两个对角点确定矩形框
    //    坐标系：+X = 车头方向 (Forward), +Y = 车左方向 (Left), 单位 mm
    //
    //    孔洞矩形：前左角、后右角填写为"相对 ArUco 中心"的 X/Y，
    //              需随 ArUco 当前 yaw 旋转到平台坐标。
    //    LRU  矩形：前左角、后右角填写为"相对相机中心"的 X/Y，
    //              不随 ArUco yaw 旋转。
    //
    //    误差输出：
    //      result.x   = 孔洞中心X - LRU中心X
    //      result.y   = 孔洞中心Y - LRU中心Y
    //      result.yaw = 孔洞矩形方向角 - LRU矩形方向角
    //
    //    运动层补偿方向约定（不要在这里反过来）：
    //      X/Y：平台 x + result.x，y + result.y
    //      Yaw：平台 rz - result.yaw

    double markerForwardMm = -pose.tvec[1];
    double markerLeftMm    =  pose.tvec[0];
    double markerYawDeg    =  pose.yaw;

    // ---- 选取当前高度对应的 LRU 矩形参数 ----
    // 50mm = 相机标定工况 camera_calibration_50.json (z≈0)
    // 16mm = 相机标定工况 camera_calibration_16.json (z≈1700)
    // 注意：50mm/16mm 是相机标定工况名，不是二级高度。
    double lruFLx = 0, lruFLy = 0, lruRRx = 0, lruRRy = 0;
    bool lruRectConfigured = false;
    if (-0.5 <= z && z <= 0.5) {
        lruFLx = m_lru50_front_left_x;  lruFLy = m_lru50_front_left_y;
        lruRRx = m_lru50_rear_right_x;  lruRRy = m_lru50_rear_right_y;
        lruRectConfigured = (m_lru50_front_left_x != LRU_RECT_UNSET &&
                             m_lru50_front_left_y != LRU_RECT_UNSET &&
                             m_lru50_rear_right_x != LRU_RECT_UNSET &&
                             m_lru50_rear_right_y != LRU_RECT_UNSET);
    } else if (1699.5 <= z && z <= 1700.5) {
        lruFLx = m_lru16_front_left_x;  lruFLy = m_lru16_front_left_y;
        lruRRx = m_lru16_rear_right_x;  lruRRy = m_lru16_rear_right_y;
        lruRectConfigured = (m_lru16_front_left_x != LRU_RECT_UNSET &&
                             m_lru16_front_left_y != LRU_RECT_UNSET &&
                             m_lru16_rear_right_x != LRU_RECT_UNSET &&
                             m_lru16_rear_right_y != LRU_RECT_UNSET);
    }

    // 检查孔洞矩形是否已标定
    bool holeRectConfigured = (m_hole_front_left_x != LRU_RECT_UNSET &&
                               m_hole_front_left_y != LRU_RECT_UNSET &&
                               m_hole_rear_right_x != LRU_RECT_UNSET &&
                               m_hole_rear_right_y != LRU_RECT_UNSET);

    if (!holeRectConfigured || !lruRectConfigured) {
        result.failureReason = QString("该 LRU 类型未配置矩形对角点参数（%1），需要重新标定")
                                   .arg(!holeRectConfigured ? "孔洞" : "LRU");
        qWarning() << result.failureReason;
        return result;
    }

    // ---- 工具函数：2D 点与 yaw 旋转 ----
    struct Point2d { double x; double y; }; // x=forward(+X), y=left(+Y)

    // 将"相对 ArUco 中心"的点按 markerYaw 旋转到平台坐标。
    // ★ yaw 旋转方向集中封装于此 ★
    // 如果实机确认 yaw 旋转方向相反，只在这里调整符号，并写清原因。
    auto rotateByYaw = [](Point2d p, double yawDeg) -> Point2d {
        double a = yawDeg * M_PI / 180.0;
        double c = std::cos(a);
        double s = std::sin(a);
        return { p.x * c - p.y * s,
                 p.x * s + p.y * c };
    };

    auto center = [](Point2d a, Point2d b) -> Point2d {
        return { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0 };
    };

    // 对角线方向角（度），rearRight - frontLeft 向量
    auto diagonalAngleDeg = [](Point2d frontLeft, Point2d rearRight) -> double {
        double dx = rearRight.x - frontLeft.x;
        double dy = rearRight.y - frontLeft.y;
        return std::atan2(dy, dx) * 180.0 / M_PI;
    };

    // 归一化角度到 [-180, 180]
    auto normalizeAngleDeg = [](double deg) -> double {
        while (deg > 180.0)  deg -= 360.0;
        while (deg <= -180.0) deg += 360.0;
        return deg;
    };

    // ---- 计算孔洞矩形两点（平台坐标）----
    Point2d marker = { markerForwardMm, markerLeftMm };
    Point2d holeFL = { m_hole_front_left_x, m_hole_front_left_y };
    Point2d holeRR = { m_hole_rear_right_x, m_hole_rear_right_y };
    Point2d holeFLRot = rotateByYaw(holeFL, markerYawDeg);
    Point2d holeRRRot = rotateByYaw(holeRR, markerYawDeg);
    Point2d holeFLPlatform = { marker.x + holeFLRot.x, marker.y + holeFLRot.y };
    Point2d holeRRPlatform = { marker.x + holeRRRot.x, marker.y + holeRRRot.y };
    Point2d holeCenter = center(holeFLPlatform, holeRRPlatform);
    double  holeAngle  = diagonalAngleDeg(holeFLPlatform, holeRRPlatform);

    // ---- 计算 LRU 矩形两点（平台坐标，不旋转）----
    Point2d lruFL = { lruFLx, lruFLy };
    Point2d lruRR = { lruRRx, lruRRy };
    Point2d lruCenter = center(lruFL, lruRR);
    double  lruAngle  = diagonalAngleDeg(lruFL, lruRR);

    // ---- 输出误差 ----
    result.x   = holeCenter.x - lruCenter.x;
    result.y   = holeCenter.y - lruCenter.y;
    result.yaw = normalizeAngleDeg(holeAngle - lruAngle);

    result.valid = true;

    // ---- 简短摘要日志（不刷大量逐帧日志到 UI，详细内容留在文件日志）----
    qInfo() << QString("检测成功：X=%1 Y=%2 yaw=%3，孔洞中心=(%4, %5)，LRU中心=(%6, %7)")
                   .arg(result.x, 0, 'f', 2).arg(result.y, 0, 'f', 2).arg(result.yaw, 0, 'f', 2)
                   .arg(holeCenter.x, 0, 'f', 2).arg(holeCenter.y, 0, 'f', 2)
                   .arg(lruCenter.x, 0, 'f', 2).arg(lruCenter.y, 0, 'f', 2);

    return result;
}

void ArucoDetector::setMarkerSizeMm(float sizeMm)
{
    m_markerSizeMm = sizeMm;
}

void ArucoDetector::setCornerBorderMarginPx(int marginPx)
{
    m_cornerBorderMarginPx = marginPx;
}

void ArucoDetector::setReprojectionErrorMaxPx(double maxPx)
{
    m_reprojectionErrorMaxPx = maxPx;
}

void ArucoDetector::onParamsReceived(const LRUInnerParams &params)
{
    aruco_to_gapx  = params.aruco_to_gapx;
    aruco_to_gapy  = params.aruco_to_gapy;
    camera_to_lrux_50 = params.camera_to_lrux_50;
    camera_to_lruy_50 = params.camera_to_lruy_50;
    camera_to_lrux_16 = params.camera_to_lrux_16;
    camera_to_lruy_16 = params.camera_to_lruy_16;
    offset_x_50 = params.offset_x_50;
    offset_y_50 = params.offset_y_50;
    offset_x_16 = params.offset_x_16;
    offset_y_16 = params.offset_y_16;
    marker_id = params.marker_id;
    qInfo() << "ArucoDetector: marker_id 已同步为" << marker_id;
    z0_tvec_x_offset    = params.z0_tvec_x_offset;
    z0_tvec_y_offset    = params.z0_tvec_y_offset;
    z1700_tvec_x_offset = params.z1700_tvec_x_offset;
    z1700_tvec_y_offset = params.z1700_tvec_y_offset;

    // 矩形框对齐模型参数
    m_hole_front_left_x  = params.hole_front_left_x;
    m_hole_front_left_y  = params.hole_front_left_y;
    m_hole_rear_right_x  = params.hole_rear_right_x;
    m_hole_rear_right_y  = params.hole_rear_right_y;
    m_lru50_front_left_x = params.lru50_front_left_x;
    m_lru50_front_left_y = params.lru50_front_left_y;
    m_lru50_rear_right_x = params.lru50_rear_right_x;
    m_lru50_rear_right_y = params.lru50_rear_right_y;
    m_lru16_front_left_x = params.lru16_front_left_x;
    m_lru16_front_left_y = params.lru16_front_left_y;
    m_lru16_rear_right_x = params.lru16_rear_right_x;
    m_lru16_rear_right_y = params.lru16_rear_right_y;
}




std::vector<cv::Point2f> ArucoDetector::sortCornersTLTRBRBL(const std::vector<cv::Point2f>& pts)
{
    std::vector<cv::Point2f> ordered(4);
    // 1. 找左上和右下：用 x + y
    int tlIndex = 0, brIndex = 0;
    float minSum = pts[0].x + pts[0].y;
    float maxSum = minSum;
    for (int i = 1; i < 4; ++i) {
        float sum = pts[i].x + pts[i].y;
        if (sum < minSum) {
            minSum = sum;
            tlIndex = i;
        }
        if (sum > maxSum) {
            maxSum = sum;
            brIndex = i;
        }
    }
    // 2. 找右上和左下：用 x - y
    int trIndex = 0, blIndex = 0;
    float minDiff = pts[0].x - pts[0].y;
    float maxDiff = minDiff;
    for (int i = 1; i < 4; ++i) {
        float diff = pts[i].x - pts[i].y;
        if (diff < minDiff) {
            minDiff = diff;
            blIndex = i;
        }
        if (diff > maxDiff) {
            maxDiff = diff;
            trIndex = i;
        }
    }
    ordered[0] = pts[tlIndex]; // 左上
    ordered[1] = pts[trIndex]; // 右上
    ordered[2] = pts[brIndex]; // 右下
    ordered[3] = pts[blIndex]; // 左下
    return ordered;
}

