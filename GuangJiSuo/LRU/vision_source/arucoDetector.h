#ifndef ARUCODETECTOR_H
#define ARUCODETECTOR_H
#pragma execution_character_set("utf-8")
#include <QObject>
#include <QImage>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <limits>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>
#include <QDebug>
#include <QMessageBox>
#include <opencv2/imgproc.hpp>
#include <cmath>
#include <algorithm>
#include <QElapsedTimer>
#include "LRUdatadef.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


class ArucoDetector : public QObject
{
    Q_OBJECT
public:
    struct ArucoResult {
        bool detected;
        int id;
        std::vector<cv::Point2f> cornerPixels;
    };

    struct PoseResult {
        bool valid;
        cv::Vec3d rvec;             // 旋转向量
        cv::Vec3d tvec;             // 平移向量（mm，相机系）
        cv::Mat   rotationMatrix;   // 3x3 旋转矩阵
        double    roll;             // 绕X轴，单位：度
        double    pitch;            // 绕Y轴，单位：度
        double    yaw;              // 绕Z轴，单位：度
        double    reprojectionError;// 平均重投影误差（像素）
    };
    struct PlanarPose {
        bool   valid;   // 是否有效
        double x;       // 平移 X（mm，相机系）
        double y;       // 平移 Y（mm，相机系）
        double yaw;     // 绕Z轴旋转角（度）
    };

    // 详细单帧检测结果（用于多帧门控）
    struct DetailedFrameResult {
        bool   valid = false;         // 通过所有质量门控
        bool   targetIdFound = false; // 是否检测到目标 marker_id
        bool   hasFourCorners = true; // 角点是否完整(4个)
        bool   cornersInBounds = true;// 角点是否贴边或出画
        bool   pnpSuccess = false;    // PnP 是否成功
        double reprojectionError = 0; // 重投影误差(px)
        double x = 0, y = 0, yaw = 0; // 平台坐标结果
        QString failureReason;        // 失败原因文本

        // 搜索线索（即使检测失败也尽可能填充，用于六自由度找码）
        bool   targetSeen = false;      // 是否看到目标 marker（不一定通过质量门控）
        double markerCenterX = 0;       // marker 角点中心 X（像素）
        double markerCenterY = 0;       // marker 角点中心 Y（像素）
        double imageCenterX = 1296.0;   // 图像中心 X（2592/2）
        double imageCenterY = 972.0;    // 图像中心 Y（1944/2）
        double markerOffsetPxX = 0;     // marker 中心偏离图像中心的 X 像素偏移
        double markerOffsetPxY = 0;     // marker 中心偏离图像中心的 Y 像素偏移
        bool   hasPnpHint = false;      // 是否有 PnP tvec 可用
        double hintTvecX = 0;           // PnP tvec X（mm, 相机系，修正前）
        double hintTvecY = 0;           // PnP tvec Y（mm, 相机系，修正前）
        bool   hasSearchHint = false;   // 综合是否有任何搜索线索
    };

    explicit ArucoDetector(QObject *parent = nullptr);

    ArucoResult detectOneArucoCode(cv::Mat &image);
    ArucoDetector::PlanarPose processImage(cv::Mat &image, float z);

    // 详细单帧检测（含完整质量门控）
    DetailedFrameResult processImageDetailed(cv::Mat &image, float z);

    // 基于 IPPE_SQUARE 的 PnP 位姿求解（对齐 Python 版本）
    PoseResult solvePnPPose(const std::vector<cv::Point2f> &cornerPixels,
                            float arucoSizeMm);

    // 设置 ArUco 码物理边长(mm)
    void setMarkerSizeMm(float sizeMm);
    // 设置角点边界门控像素数
    void setCornerBorderMarginPx(int marginPx);
    // 设置重投影误差阈值(px)
    void setReprojectionErrorMaxPx(double maxPx);

    // 旋转向量 → 欧拉角（内旋 X-Y-Z，即外旋 Z-Y-X，单位：度）
    static void rotationVectorToEuler(const cv::Vec3d &rvec,
                                      double &roll, double &pitch, double &yaw);

    std::vector<cv::Point2f> sortCornersTLTRBRBL(const std::vector<cv::Point2f>& pts);

    float x_offset;
    float y_offset;
    float rz_offset;

public slots:
    void onParamsReceived(const LRUInnerParams &params);

private:
    bool readCameraParamsFromJson(const QString &jsonPath);
    QString resolveCameraParamsPath(const QString &jsonPath) const;
    void clearCameraParams();
    bool failCameraParamsRead(const QString &message);
    QString getCameraParamsFile(float z);

private:
    float m_markerSizeMm = 40.0f;         // ArUco 码物理边长(mm)
    int   m_cornerBorderMarginPx = 5;     // 角点贴边门控(像素)
    double m_reprojectionErrorMaxPx = 2.5;// 重投影误差阈值(px)

    cv::Mat m_intrinsicMatrix;
    cv::Mat m_distCoeffs;
    cv::Mat m_rotationMatrix;
    cv::Mat m_translationVector;

    float aruco_to_gapx;
    float aruco_to_gapy;
    float camera_to_lrux_50;
    float camera_to_lruy_50;
    float camera_to_lrux_16;
    float camera_to_lruy_16;

    float offset_x_50;
    float offset_y_50;
    float offset_x_16;
    float offset_y_16;
    int   marker_id;
    float angle_offset;

    float z0_tvec_x_offset;
    float z0_tvec_y_offset;
    float z1700_tvec_x_offset;
    float z1700_tvec_y_offset;

    // ===== 矩形框对齐模型参数（与 LRUInnerParams 对应）=====
    // 坐标系：+X = 车头方向, +Y = 车左方向, 单位 mm
    // 默认初始化为 LRU_RECT_UNSET，确保 onParamsReceived() 调用前
    // processImageDetailed() 能正确识别"未配置"并提示，不会用随机值通过检查。
    // 孔洞相对 ArUco 中心（随 markerYaw 旋转）
    float m_hole_front_left_x = LRU_RECT_UNSET;
    float m_hole_front_left_y = LRU_RECT_UNSET;
    float m_hole_rear_right_x = LRU_RECT_UNSET;
    float m_hole_rear_right_y = LRU_RECT_UNSET;
    // LRU 相对相机中心（不随 ArUco yaw 旋转）
    float m_lru50_front_left_x = LRU_RECT_UNSET;
    float m_lru50_front_left_y = LRU_RECT_UNSET;
    float m_lru50_rear_right_x = LRU_RECT_UNSET;
    float m_lru50_rear_right_y = LRU_RECT_UNSET;
    float m_lru16_front_left_x = LRU_RECT_UNSET;
    float m_lru16_front_left_y = LRU_RECT_UNSET;
    float m_lru16_rear_right_x = LRU_RECT_UNSET;
    float m_lru16_rear_right_y = LRU_RECT_UNSET;

    cv::aruco::Dictionary         m_arucoDict;
    cv::aruco::DetectorParameters m_parameters;
    cv::Ptr<cv::aruco::ArucoDetector> m_detector;

signals:
    void arucoUpdateUI(QString str);
};

#endif // ARUCODETECTOR_H
