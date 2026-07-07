#ifndef LRUPARAMDIALOG_H
#define LRUPARAMDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "LRUdatadef.h"

// =============================================================================
// LruParamDialog — LRU 参数编辑窗口
// 编辑当前 comboBox_LRUdata 选中的 LRU 类型参数，
// 保存到 lru_params.json（运行时覆盖），或恢复 LRUdatadef.h 默认值
// =============================================================================
class LruParamDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LruParamDialog(const QString &lruTypeName,
                            const LRUInnerParams &currentParams,
                            QWidget *parent = nullptr);

    /// 返回用户确认后的参数（点击"保存"后有效）
    LRUInnerParams editedParams() const { return m_editedParams; }
    /// 用户是否请求恢复默认
    bool restoreRequested() const { return m_restoreRequested; }
    /// 当前选中的 LRU 类型
    QString selectedLruType() const { return m_lruTypeName; }

    // ---- 静态 JSON 持久化 helpers ----
    /// 加载 lru_params.json，对同名 LRU 覆盖默认值；没有的字段保留默认
    static LRUInnerParams loadWithOverride(const QString &lruTypeName,
                                           const LRUInnerParams &defaults);
    /// 保存当前 LRU 参数到 lru_params.json
    static void saveOverride(const QString &lruTypeName,
                             const LRUInnerParams &params);
    /// 删除 lru_params.json 中该 LRU 的覆盖值
    static void removeOverride(const QString &lruTypeName);

signals:
    void lruTypeChanged(const QString &lruTypeName);

private slots:
    void onSave();
    void onRestoreDefault();
    void onLruTypeChanged(int index);

private:
    void setupUi(const LRUInnerParams &params);
    void collectParams(LRUInnerParams &out);
    bool promptSaveUnsavedChanges();
    /// 校验矩形对角点参数是否完整标定。
    /// 返回空字符串表示通过；否则返回未标定的组名用于弹窗提示。
    QString validateRectParams() const;
    /// 收集参数并在未标定字段仍存在时要求用户显式确认是否按当前值保存。
    bool collectAndConfirmParamsForSave();

    QString m_lruTypeName;
    LRUInnerParams m_defaultParams;
    LRUInnerParams m_editedParams;
    bool m_restoreRequested = false;
    bool m_paramsDirty = false;

    // 矩形框对角点初始 unset 状态跟踪（12 个字段，与 m_hole_*/m_lru50_*/m_lru16_* 顺序对应）
    // true 表示该字段初始为 LRU_RECT_UNSET（未标定）。
    // valueChanged 或保存时显式确认后，该字段会被视为已确认，因此合法的 0 坐标也可以保存。
    bool m_rectUnset[12] = {false};

    QComboBox *m_lruTypeCombo = nullptr;

    // UI widgets
    QDoubleSpinBox *m_x_gap = nullptr;
    QDoubleSpinBox *m_y_gap = nullptr;
    QDoubleSpinBox *m_final_z = nullptr;
    QDoubleSpinBox *m_aruco_to_gapx = nullptr;
    QDoubleSpinBox *m_aruco_to_gapy = nullptr;
    QDoubleSpinBox *m_camera_to_lrux_50 = nullptr;
    QDoubleSpinBox *m_camera_to_lruy_50 = nullptr;
    QDoubleSpinBox *m_camera_to_lrux_16 = nullptr;
    QDoubleSpinBox *m_camera_to_lruy_16 = nullptr;
    QDoubleSpinBox *m_offset_x_50 = nullptr;
    QDoubleSpinBox *m_offset_y_50 = nullptr;
    QDoubleSpinBox *m_offset_x_16 = nullptr;
    QDoubleSpinBox *m_offset_y_16 = nullptr;
    QDoubleSpinBox *m_z0_tvec_x_offset = nullptr;
    QDoubleSpinBox *m_z0_tvec_y_offset = nullptr;
    QDoubleSpinBox *m_z1700_tvec_x_offset = nullptr;
    QDoubleSpinBox *m_z1700_tvec_y_offset = nullptr;
    QSpinBox *m_marker_id = nullptr;

    // 矩形框对齐模型 — UI widgets（前左角 + 后右角）
    // 孔洞相对 ArUco
    QDoubleSpinBox *m_hole_front_left_x = nullptr;
    QDoubleSpinBox *m_hole_front_left_y = nullptr;
    QDoubleSpinBox *m_hole_rear_right_x = nullptr;
    QDoubleSpinBox *m_hole_rear_right_y = nullptr;
    // LRU 相对相机（50mm 工况）
    QDoubleSpinBox *m_lru50_front_left_x = nullptr;
    QDoubleSpinBox *m_lru50_front_left_y = nullptr;
    QDoubleSpinBox *m_lru50_rear_right_x = nullptr;
    QDoubleSpinBox *m_lru50_rear_right_y = nullptr;
    // LRU 相对相机（16mm 工况）
    QDoubleSpinBox *m_lru16_front_left_x = nullptr;
    QDoubleSpinBox *m_lru16_front_left_y = nullptr;
    QDoubleSpinBox *m_lru16_rear_right_x = nullptr;
    QDoubleSpinBox *m_lru16_rear_right_y = nullptr;

    // 保留但不在主界面显示的字段（用隐藏 spinbox 保持数据完整）
    QDoubleSpinBox *m_angle = nullptr;
    QDoubleSpinBox *m_target_rx = nullptr;
    QDoubleSpinBox *m_target_ry = nullptr;
    QSpinBox *m_camera0_exposureTime = nullptr;
    QSpinBox *m_camera1_exposureTime = nullptr;
};

#endif // LRUPARAMDIALOG_H
