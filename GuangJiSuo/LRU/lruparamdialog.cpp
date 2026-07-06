#include "lruparamdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QLabel>
#include <QDialogButtonBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QDir>

// =============================================================================
// 静态 helper：JSON 文件路径
// =============================================================================
static QString jsonFilePath()
{
    return QApplication::applicationDirPath() + "/lru_params.json";
}

// =============================================================================
// 静态 helper：读取整个 JSON 对象
// =============================================================================
static QJsonObject readJsonFile()
{
    QFile file(jsonFilePath());
    if (!file.open(QIODevice::ReadOnly))
        return QJsonObject();
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    return doc.object();
}

// =============================================================================
// 静态 helper：写入 JSON 对象
// =============================================================================
static void writeJsonFile(const QJsonObject &obj)
{
    QFile file(jsonFilePath());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "LruParamDialog: 无法写入" << jsonFilePath();
        return;
    }
    file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));
    file.close();
}

// =============================================================================
// 静态 helper：LRUInnerParams ↔ QJsonObject
// =============================================================================
static QJsonObject paramsToJson(const LRUInnerParams &p)
{
    QJsonObject o;
    o["x_gap"] = p.x_gap;
    o["y_gap"] = p.y_gap;
    o["final_z"] = p.final_z;
    o["aruco_to_gapx"] = p.aruco_to_gapx;
    o["aruco_to_gapy"] = p.aruco_to_gapy;
    o["camera_to_lrux_50"] = p.camera_to_lrux_50;
    o["camera_to_lruy_50"] = p.camera_to_lruy_50;
    o["camera_to_lrux_16"] = p.camera_to_lrux_16;
    o["camera_to_lruy_16"] = p.camera_to_lruy_16;
    o["offset_x_50"] = p.offset_x_50;
    o["offset_y_50"] = p.offset_y_50;
    o["offset_x_16"] = p.offset_x_16;
    o["offset_y_16"] = p.offset_y_16;
    o["marker_id"] = p.marker_id;
    o["angle"] = p.angle;
    o["target_rx"] = p.target_rx;
    o["target_ry"] = p.target_ry;
    o["camera0_exposureTime"] = p.camera0_exposureTime;
    o["camera1_exposureTime"] = p.camera1_exposureTime;
    o["z0_tvec_x_offset"] = p.z0_tvec_x_offset;
    o["z0_tvec_y_offset"] = p.z0_tvec_y_offset;
    o["z1700_tvec_x_offset"] = p.z1700_tvec_x_offset;
    o["z1700_tvec_y_offset"] = p.z1700_tvec_y_offset;
    return o;
}

static LRUInnerParams jsonToParams(const QJsonObject &o, const LRUInnerParams &fallback)
{
    LRUInnerParams p = fallback; // 先用默认值填充
    if (o.contains("x_gap"))              p.x_gap = static_cast<float>(o["x_gap"].toDouble());
    if (o.contains("y_gap"))              p.y_gap = static_cast<float>(o["y_gap"].toDouble());
    if (o.contains("final_z"))            p.final_z = static_cast<float>(o["final_z"].toDouble());
    if (o.contains("aruco_to_gapx"))      p.aruco_to_gapx = static_cast<float>(o["aruco_to_gapx"].toDouble());
    if (o.contains("aruco_to_gapy"))      p.aruco_to_gapy = static_cast<float>(o["aruco_to_gapy"].toDouble());
    if (o.contains("camera_to_lrux_50"))  p.camera_to_lrux_50 = static_cast<float>(o["camera_to_lrux_50"].toDouble());
    if (o.contains("camera_to_lruy_50"))  p.camera_to_lruy_50 = static_cast<float>(o["camera_to_lruy_50"].toDouble());
    if (o.contains("camera_to_lrux_16"))  p.camera_to_lrux_16 = static_cast<float>(o["camera_to_lrux_16"].toDouble());
    if (o.contains("camera_to_lruy_16"))  p.camera_to_lruy_16 = static_cast<float>(o["camera_to_lruy_16"].toDouble());
    if (o.contains("offset_x_50"))        p.offset_x_50 = static_cast<float>(o["offset_x_50"].toDouble());
    if (o.contains("offset_y_50"))        p.offset_y_50 = static_cast<float>(o["offset_y_50"].toDouble());
    if (o.contains("offset_x_16"))        p.offset_x_16 = static_cast<float>(o["offset_x_16"].toDouble());
    if (o.contains("offset_y_16"))        p.offset_y_16 = static_cast<float>(o["offset_y_16"].toDouble());
    if (o.contains("marker_id"))          p.marker_id = o["marker_id"].toInt();
    if (o.contains("angle"))              p.angle = static_cast<float>(o["angle"].toDouble());
    if (o.contains("target_rx"))          p.target_rx = static_cast<float>(o["target_rx"].toDouble());
    if (o.contains("target_ry"))          p.target_ry = static_cast<float>(o["target_ry"].toDouble());
    if (o.contains("camera0_exposureTime")) p.camera0_exposureTime = o["camera0_exposureTime"].toInt();
    if (o.contains("camera1_exposureTime")) p.camera1_exposureTime = o["camera1_exposureTime"].toInt();
    if (o.contains("z0_tvec_x_offset"))   p.z0_tvec_x_offset = static_cast<float>(o["z0_tvec_x_offset"].toDouble());
    if (o.contains("z0_tvec_y_offset"))   p.z0_tvec_y_offset = static_cast<float>(o["z0_tvec_y_offset"].toDouble());
    if (o.contains("z1700_tvec_x_offset")) p.z1700_tvec_x_offset = static_cast<float>(o["z1700_tvec_x_offset"].toDouble());
    if (o.contains("z1700_tvec_y_offset")) p.z1700_tvec_y_offset = static_cast<float>(o["z1700_tvec_y_offset"].toDouble());
    return p;
}

// =============================================================================
// 公共静态方法
// =============================================================================
LRUInnerParams LruParamDialog::loadWithOverride(const QString &lruTypeName,
                                                 const LRUInnerParams &defaults)
{
    QJsonObject root = readJsonFile();
    if (root.contains(lruTypeName) && root[lruTypeName].isObject()) {
        return jsonToParams(root[lruTypeName].toObject(), defaults);
    }
    return defaults;
}

void LruParamDialog::saveOverride(const QString &lruTypeName,
                                   const LRUInnerParams &params)
{
    QJsonObject root = readJsonFile();
    root[lruTypeName] = paramsToJson(params);
    writeJsonFile(root);
}

void LruParamDialog::removeOverride(const QString &lruTypeName)
{
    QJsonObject root = readJsonFile();
    if (root.contains(lruTypeName)) {
        root.remove(lruTypeName);
        writeJsonFile(root);
    }
}

// =============================================================================
// 构造 / UI
// =============================================================================
LruParamDialog::LruParamDialog(const QString &lruTypeName,
                               const LRUInnerParams &currentParams,
                               QWidget *parent)
    : QDialog(parent),
      m_lruTypeName(lruTypeName),
      m_defaultParams(LRUpresetData().value(lruTypeName)),
      m_editedParams(currentParams)
{
    setWindowTitle(QString("二级升降参数设置 - 当前 LRU：%1").arg(lruTypeName));
    setMinimumSize(680, 600);
    resize(760, 680);
    setupUi(currentParams);
}

void LruParamDialog::setupUi(const LRUInnerParams &params)
{
    auto *mainLayout = new QVBoxLayout(this);

    // 提示标签
    auto *hintLabel = new QLabel(
        QString("正在编辑当前 LRU 类型 \"%1\" 的二级升降参数。保存后写入 lru_params.json，并立即生效。").arg(m_lruTypeName));
    hintLabel->setWordWrap(true);
    hintLabel->setStyleSheet("color: #555; margin-bottom: 4px;");
    mainLayout->addWidget(hintLabel);

    // 滚动区域
    auto *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    auto *scrollWidget = new QWidget;
    auto *formLayout = new QFormLayout(scrollWidget);
    formLayout->setLabelAlignment(Qt::AlignRight);

    // 通用 double spinbox 工厂
    auto makeDouble = [&](double val, double min, double max, int decimals, double step) {
        auto *sb = new QDoubleSpinBox;
        sb->setRange(min, max);
        sb->setDecimals(decimals);
        sb->setSingleStep(step);
        sb->setValue(val);
        sb->setMinimumWidth(120);
        return sb;
    };

    // === 目标位置参数 ===
    auto *gapGroup = new QGroupBox("目标位置参数");
    auto *gapForm = new QFormLayout(gapGroup);
    m_x_gap   = makeDouble(params.x_gap,   0, 500, 2, 0.5);
    m_y_gap   = makeDouble(params.y_gap,   0, 500, 2, 0.5);
    m_final_z = makeDouble(params.final_z, 0, 5000, 1, 5.0);
    gapForm->addRow("目标 X 间隙 (x_gap, mm)", m_x_gap);
    gapForm->addRow("目标 Y 间隙 (y_gap, mm)", m_y_gap);
    gapForm->addRow("最终上升高度 (final_z, mm)", m_final_z);
    formLayout->addRow(gapGroup);

    // === ArUco 码参数 ===
    auto *markerGroup = new QGroupBox("ArUco 码参数");
    auto *markerForm = new QFormLayout(markerGroup);
    m_marker_id = new QSpinBox;
    m_marker_id->setRange(0, 99);
    m_marker_id->setValue(params.marker_id);
    markerForm->addRow("ArUco 码编号 (marker_id)", m_marker_id);
    formLayout->addRow(markerGroup);

    // === 相机、码、LRU 的安装距离 ===
    auto *geoGroup = new QGroupBox("相机、码、LRU 的安装距离");
    auto *geoForm = new QFormLayout(geoGroup);
    m_aruco_to_gapx    = makeDouble(params.aruco_to_gapx,    -1000, 1000, 2, 1.0);
    m_aruco_to_gapy    = makeDouble(params.aruco_to_gapy,    -1000, 1000, 2, 1.0);
    m_camera_to_lrux_50 = makeDouble(params.camera_to_lrux_50, -1000, 1000, 2, 1.0);
    m_camera_to_lruy_50 = makeDouble(params.camera_to_lruy_50, -1000, 1000, 2, 1.0);
    m_camera_to_lrux_16 = makeDouble(params.camera_to_lrux_16, -1000, 1000, 2, 1.0);
    m_camera_to_lruy_16 = makeDouble(params.camera_to_lruy_16, -1000, 1000, 2, 1.0);
    geoForm->addRow("ArUco 码到目标缝隙 X 距离 (aruco_to_gapx, mm)", m_aruco_to_gapx);
    geoForm->addRow("ArUco 码到目标缝隙 Y 距离 (aruco_to_gapy, mm)", m_aruco_to_gapy);
    geoForm->addRow("50 型相机到 LRU X 距离 (camera_to_lrux_50, mm)", m_camera_to_lrux_50);
    geoForm->addRow("50 型相机到 LRU Y 距离 (camera_to_lruy_50, mm)", m_camera_to_lruy_50);
    geoForm->addRow("16 型相机到 LRU X 距离 (camera_to_lrux_16, mm)", m_camera_to_lrux_16);
    geoForm->addRow("16 型相机到 LRU Y 距离 (camera_to_lruy_16, mm)", m_camera_to_lruy_16);
    formLayout->addRow(geoGroup);

    // === 视觉测量补偿参数 ===
    auto *corrGroup = new QGroupBox("视觉测量补偿参数");
    auto *corrForm = new QFormLayout(corrGroup);
    m_offset_x_50 = makeDouble(params.offset_x_50, -100, 100, 2, 0.5);
    m_offset_y_50 = makeDouble(params.offset_y_50, -100, 100, 2, 0.5);
    m_offset_x_16 = makeDouble(params.offset_x_16, -100, 100, 2, 0.5);
    m_offset_y_16 = makeDouble(params.offset_y_16, -100, 100, 2, 0.5);
    m_z0_tvec_x_offset    = makeDouble(params.z0_tvec_x_offset,    -50, 50, 2, 0.1);
    m_z0_tvec_y_offset    = makeDouble(params.z0_tvec_y_offset,    -50, 50, 2, 0.1);
    m_z1700_tvec_x_offset = makeDouble(params.z1700_tvec_x_offset, -50, 50, 2, 0.1);
    m_z1700_tvec_y_offset = makeDouble(params.z1700_tvec_y_offset, -50, 50, 2, 0.1);
    corrForm->addRow("50 型视觉 X 修正量 (offset_x_50, mm)", m_offset_x_50);
    corrForm->addRow("50 型视觉 Y 修正量 (offset_y_50, mm)", m_offset_y_50);
    corrForm->addRow("16 型视觉 X 修正量 (offset_x_16, mm)", m_offset_x_16);
    corrForm->addRow("16 型视觉 Y 修正量 (offset_y_16, mm)", m_offset_y_16);
    corrForm->addRow("低位视觉 X 补偿 (z0_tvec_x_offset, mm)", m_z0_tvec_x_offset);
    corrForm->addRow("低位视觉 Y 补偿 (z0_tvec_y_offset, mm)", m_z0_tvec_y_offset);
    corrForm->addRow("高位视觉 X 补偿 (z1700_tvec_x_offset, mm)", m_z1700_tvec_x_offset);
    corrForm->addRow("高位视觉 Y 补偿 (z1700_tvec_y_offset, mm)", m_z1700_tvec_y_offset);
    formLayout->addRow(corrGroup);

    // 隐藏字段 — 保留数据完整性但不显示在 UI
    m_angle = makeDouble(params.angle, -180, 180, 2, 0.5);
    m_angle->setVisible(false);
    m_target_rx = makeDouble(params.target_rx, -10, 10, 4, 0.01);
    m_target_rx->setVisible(false);
    m_target_ry = makeDouble(params.target_ry, -10, 10, 4, 0.01);
    m_target_ry->setVisible(false);
    m_camera0_exposureTime = new QSpinBox;
    m_camera0_exposureTime->setRange(1, 10000000);
    m_camera0_exposureTime->setValue(params.camera0_exposureTime);
    m_camera0_exposureTime->setVisible(false);
    m_camera1_exposureTime = new QSpinBox;
    m_camera1_exposureTime->setRange(1, 10000000);
    m_camera1_exposureTime->setValue(params.camera1_exposureTime);
    m_camera1_exposureTime->setVisible(false);
    formLayout->addRow(m_angle);
    formLayout->addRow(m_target_rx);
    formLayout->addRow(m_target_ry);
    formLayout->addRow(m_camera0_exposureTime);
    formLayout->addRow(m_camera1_exposureTime);

    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea, 1);

    // 底部按钮
    auto *btnLayout = new QHBoxLayout;
    auto *restoreBtn = new QPushButton("恢复默认");
    restoreBtn->setToolTip("删除当前 LRU 的 JSON 覆盖值，恢复 LRUdatadef.h 默认参数");
    auto *saveBtn = new QPushButton("保存");
    saveBtn->setDefault(true);
    saveBtn->setStyleSheet("QPushButton { font-weight: bold; }");
    auto *cancelBtn = new QPushButton("取消");

    btnLayout->addWidget(restoreBtn);
    btnLayout->addStretch();
    btnLayout->addWidget(saveBtn);
    btnLayout->addWidget(cancelBtn);
    mainLayout->addLayout(btnLayout);

    connect(restoreBtn, &QPushButton::clicked, this, &LruParamDialog::onRestoreDefault);
    connect(saveBtn,    &QPushButton::clicked, this, &LruParamDialog::onSave);
    connect(cancelBtn,  &QPushButton::clicked, this, &QDialog::reject);
}

void LruParamDialog::collectParams(LRUInnerParams &out)
{
    out.x_gap      = static_cast<float>(m_x_gap->value());
    out.y_gap      = static_cast<float>(m_y_gap->value());
    out.final_z    = static_cast<float>(m_final_z->value());
    out.aruco_to_gapx   = static_cast<float>(m_aruco_to_gapx->value());
    out.aruco_to_gapy   = static_cast<float>(m_aruco_to_gapy->value());
    out.camera_to_lrux_50 = static_cast<float>(m_camera_to_lrux_50->value());
    out.camera_to_lruy_50 = static_cast<float>(m_camera_to_lruy_50->value());
    out.camera_to_lrux_16 = static_cast<float>(m_camera_to_lrux_16->value());
    out.camera_to_lruy_16 = static_cast<float>(m_camera_to_lruy_16->value());
    out.offset_x_50 = static_cast<float>(m_offset_x_50->value());
    out.offset_y_50 = static_cast<float>(m_offset_y_50->value());
    out.offset_x_16 = static_cast<float>(m_offset_x_16->value());
    out.offset_y_16 = static_cast<float>(m_offset_y_16->value());
    out.z0_tvec_x_offset    = static_cast<float>(m_z0_tvec_x_offset->value());
    out.z0_tvec_y_offset    = static_cast<float>(m_z0_tvec_y_offset->value());
    out.z1700_tvec_x_offset = static_cast<float>(m_z1700_tvec_x_offset->value());
    out.z1700_tvec_y_offset = static_cast<float>(m_z1700_tvec_y_offset->value());
    out.marker_id  = m_marker_id->value();
    out.angle      = static_cast<float>(m_angle->value());
    out.target_rx  = static_cast<float>(m_target_rx->value());
    out.target_ry  = static_cast<float>(m_target_ry->value());
    out.camera0_exposureTime = m_camera0_exposureTime->value();
    out.camera1_exposureTime = m_camera1_exposureTime->value();
}

void LruParamDialog::onSave()
{
    collectParams(m_editedParams);
    m_restoreRequested = false;
    accept();
}

void LruParamDialog::onRestoreDefault()
{
    auto answer = QMessageBox::question(
        this, "恢复默认",
        QString("确认恢复 \"%1\" 到 LRUdatadef.h 出厂默认值？\n"
                "这将删除 lru_params.json 中该类型的覆盖值。")
            .arg(m_lruTypeName),
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (answer != QMessageBox::Yes)
        return;

    m_editedParams = m_defaultParams;
    m_restoreRequested = true;
    accept();
}
