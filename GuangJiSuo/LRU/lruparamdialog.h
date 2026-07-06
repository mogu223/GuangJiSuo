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

    QString m_lruTypeName;
    LRUInnerParams m_defaultParams;
    LRUInnerParams m_editedParams;
    bool m_restoreRequested = false;
    bool m_paramsDirty = false;

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

    // 保留但不在主界面显示的字段（用隐藏 spinbox 保持数据完整）
    QDoubleSpinBox *m_angle = nullptr;
    QDoubleSpinBox *m_target_rx = nullptr;
    QDoubleSpinBox *m_target_ry = nullptr;
    QSpinBox *m_camera0_exposureTime = nullptr;
    QSpinBox *m_camera1_exposureTime = nullptr;
};

#endif // LRUPARAMDIALOG_H
