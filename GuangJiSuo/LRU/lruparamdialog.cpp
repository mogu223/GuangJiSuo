#include "lruparamdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QDir>

// =============================================================================
// 静态 helper：JSON 文件路径（优先当前工作目录，兼容旧 exe 目录）
// =============================================================================
static QString primaryJsonFilePath()
{
    return QDir::current().absoluteFilePath("lru_params.json");
}

static QString legacyJsonFilePath()
{
    return QCoreApplication::applicationDirPath() + "/lru_params.json";
}

static QString jsonFilePath()
{
    return primaryJsonFilePath();
}

// =============================================================================
// 静态 helper：读取整个 JSON 对象
// =============================================================================
static QJsonObject readJsonFile()
{
    QString primary = primaryJsonFilePath();
    QString legacy = legacyJsonFilePath();
    QString path = QFile::exists(primary) ? primary : legacy;

    QFile file(path);
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
    QFile file(primaryJsonFilePath());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "LruParamDialog: 无法写入" << primaryJsonFilePath();
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
    setWindowTitle("二级升降参数设置");
    setMinimumSize(680, 600);
    resize(760, 680);
    setupUi(currentParams);
}

bool LruParamDialog::promptSaveUnsavedChanges()
{
    if (!m_paramsDirty)
        return true; // continue switching

    auto answer = QMessageBox::question(
        this, "未保存修改",
        QString("当前 LRU 类型 \"%1\" 的参数已修改，是否保存后再切换？")
            .arg(m_lruTypeName),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
        QMessageBox::Save);

    if (answer == QMessageBox::Save) {
        collectParams(m_editedParams);
        saveOverride(m_lruTypeName, m_editedParams);
        return true;
    } else if (answer == QMessageBox::Discard) {
        return true;
    }
    return false; // Cancel
}

void LruParamDialog::onLruTypeChanged(int index)
{
    Q_UNUSED(index)
    QString newType = m_lruTypeCombo->currentText();
    if (newType == m_lruTypeName)
        return;

    if (!promptSaveUnsavedChanges()) {
        // revert combo selection
        m_lruTypeCombo->setCurrentText(m_lruTypeName);
        return;
    }

    m_lruTypeName = newType;
    m_defaultParams = LRUpresetData().value(m_lruTypeName);
    m_editedParams = loadWithOverride(m_lruTypeName, m_defaultParams);
    m_paramsDirty = false;

    setWindowTitle(QString("二级升降参数设置 - 当前 LRU：%1").arg(m_lruTypeName));
    emit lruTypeChanged(m_lruTypeName);

    // 重建 UI 以反映新类型参数
    QLayout *oldLayout = layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }
    setupUi(m_editedParams);
}

void LruParamDialog::setupUi(const LRUInnerParams &params)
{
    auto *mainLayout = new QVBoxLayout(this);

    // 顶部 LRU 类型下拉框
    auto *typeLayout = new QHBoxLayout;
    typeLayout->addWidget(new QLabel("LRU 类型："));
    m_lruTypeCombo = new QComboBox;
    m_lruTypeCombo->addItems(LRUpresetData().keys());
    m_lruTypeCombo->setCurrentText(m_lruTypeName);
    connect(m_lruTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &LruParamDialog::onLruTypeChanged);
    typeLayout->addWidget(m_lruTypeCombo);
    typeLayout->addStretch();
    mainLayout->addLayout(typeLayout);

    // 提示标签
    auto *hintLabel = new QLabel(
        QString("正在编辑 LRU 类型 \"%1\" 的二级升降参数。保存后写入当前工作目录/lru_params.json，并立即生效。").arg(m_lruTypeName));
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
        connect(sb, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                [this](double) { m_paramsDirty = true; });
        return sb;
    };
    auto makeInt = [&](int val, int min, int max) {
        auto *sb = new QSpinBox;
        sb->setRange(min, max);
        sb->setValue(val);
        connect(sb, QOverload<int>::of(&QSpinBox::valueChanged),
                [this](int) { m_paramsDirty = true; });
        return sb;
    };

    // === ArUco 码参数 ===
    auto *markerGroup = new QGroupBox("ArUco 码参数");
    auto *markerForm = new QFormLayout(markerGroup);
    m_marker_id = makeInt(params.marker_id, 0, 99);
    markerForm->addRow("ArUco 码编号", m_marker_id);
    formLayout->addRow(markerGroup);

    // === 几何距离 ===
    auto *geoGroup = new QGroupBox("几何距离");
    auto *geoForm = new QFormLayout(geoGroup);
    m_aruco_to_gapx    = makeDouble(params.aruco_to_gapx,    -1000, 1000, 2, 1.0);
    m_aruco_to_gapy    = makeDouble(params.aruco_to_gapy,    -1000, 1000, 2, 1.0);
    m_camera_to_lrux_50 = makeDouble(params.camera_to_lrux_50, -1000, 1000, 2, 1.0);
    m_camera_to_lruy_50 = makeDouble(params.camera_to_lruy_50, -1000, 1000, 2, 1.0);
    m_camera_to_lrux_16 = makeDouble(params.camera_to_lrux_16, -1000, 1000, 2, 1.0);
    m_camera_to_lruy_16 = makeDouble(params.camera_to_lruy_16, -1000, 1000, 2, 1.0);
    geoForm->addRow("ArUco 到孔洞前边中点：车头方向 (aruco_to_gapx, mm)", m_aruco_to_gapx);
    geoForm->addRow("ArUco 到孔洞前边中点：车左方向 (aruco_to_gapy, mm)", m_aruco_to_gapy);
    geoForm->addRow("50mm 相机到 LRU 前边中点：车头方向 (camera_to_lrux_50, mm)", m_camera_to_lrux_50);
    geoForm->addRow("50mm 相机到 LRU 前边中点：车左方向 (camera_to_lruy_50, mm)", m_camera_to_lruy_50);
    geoForm->addRow("16mm 相机到 LRU 前边中点：车头方向 (camera_to_lrux_16, mm)", m_camera_to_lrux_16);
    geoForm->addRow("16mm 相机到 LRU 前边中点：车左方向 (camera_to_lruy_16, mm)", m_camera_to_lruy_16);
    formLayout->addRow(geoGroup);

    // === 最终上升高度 ===
    auto *heightGroup = new QGroupBox("最终上升高度");
    auto *heightForm = new QFormLayout(heightGroup);
    m_final_z = makeDouble(params.final_z, 0, 5000, 1, 5.0);
    heightForm->addRow("最终上升高度 (final_z, mm)", m_final_z);
    formLayout->addRow(heightGroup);

    // 隐藏字段 — 保留数据完整性但不显示在 UI
    m_x_gap = makeDouble(params.x_gap, 0, 500, 2, 0.5);
    m_x_gap->setVisible(false);
    m_y_gap = makeDouble(params.y_gap, 0, 500, 2, 0.5);
    m_y_gap->setVisible(false);
    m_offset_x_50 = makeDouble(params.offset_x_50, -100, 100, 2, 0.5);
    m_offset_x_50->setVisible(false);
    m_offset_y_50 = makeDouble(params.offset_y_50, -100, 100, 2, 0.5);
    m_offset_y_50->setVisible(false);
    m_offset_x_16 = makeDouble(params.offset_x_16, -100, 100, 2, 0.5);
    m_offset_x_16->setVisible(false);
    m_offset_y_16 = makeDouble(params.offset_y_16, -100, 100, 2, 0.5);
    m_offset_y_16->setVisible(false);
    m_z0_tvec_x_offset    = makeDouble(params.z0_tvec_x_offset,    -50, 50, 2, 0.1);
    m_z0_tvec_x_offset->setVisible(false);
    m_z0_tvec_y_offset    = makeDouble(params.z0_tvec_y_offset,    -50, 50, 2, 0.1);
    m_z0_tvec_y_offset->setVisible(false);
    m_z1700_tvec_x_offset = makeDouble(params.z1700_tvec_x_offset, -50, 50, 2, 0.1);
    m_z1700_tvec_x_offset->setVisible(false);
    m_z1700_tvec_y_offset = makeDouble(params.z1700_tvec_y_offset, -50, 50, 2, 0.1);
    m_z1700_tvec_y_offset->setVisible(false);
    m_angle = makeDouble(params.angle, -180, 180, 2, 0.5);
    m_angle->setVisible(false);
    m_target_rx = makeDouble(params.target_rx, -10, 10, 4, 0.01);
    m_target_rx->setVisible(false);
    m_target_ry = makeDouble(params.target_ry, -10, 10, 4, 0.01);
    m_target_ry->setVisible(false);
    m_camera0_exposureTime = makeInt(params.camera0_exposureTime, 1, 10000000);
    m_camera0_exposureTime->setVisible(false);
    m_camera1_exposureTime = makeInt(params.camera1_exposureTime, 1, 10000000);
    m_camera1_exposureTime->setVisible(false);
    formLayout->addRow(m_x_gap);
    formLayout->addRow(m_y_gap);
    formLayout->addRow(m_offset_x_50);
    formLayout->addRow(m_offset_y_50);
    formLayout->addRow(m_offset_x_16);
    formLayout->addRow(m_offset_y_16);
    formLayout->addRow(m_z0_tvec_x_offset);
    formLayout->addRow(m_z0_tvec_y_offset);
    formLayout->addRow(m_z1700_tvec_x_offset);
    formLayout->addRow(m_z1700_tvec_y_offset);
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
    m_paramsDirty = false;
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
