#ifndef LRUDATADEF_H
#define LRUDATADEF_H

#include <QString>
#include <QMap>
#include <QMetaType>
#include <limits>

// 矩形框对角点未配置哨兵值：表示该 LRU 类型尚未标定矩形对角点。
// 视觉层检测到此值时不会静默使用，而是提示"需要重新标定"。
static constexpr float LRU_RECT_UNSET = -9999.0f;

// 内层结构体：纯聚合结构体，无构造函数
//六自由度平台坐标系下的参数
struct LRUInnerParams {
    float x_gap;//
    float y_gap;
    float final_z;
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
    int marker_id;
    float angle;
    float target_rx;
    float target_ry;
    int camera0_exposureTime;
    int camera1_exposureTime;
    // PnP tvec 修正偏移（Z≈0 / Z≈1700）
    float z0_tvec_x_offset;
    float z0_tvec_y_offset;
    float z1700_tvec_x_offset;
    float z1700_tvec_y_offset;

    // ===== 矩形框对齐模型（前左角 + 后右角两个对角点确定矩形）=====
    // 坐标系：+X = 车头方向, +Y = 车左方向, 单位 mm
    // 孔洞相对 ArUco 中心的两点（会随 markerYaw 旋转到平台坐标）
    float hole_front_left_x;   // 孔洞前左角 X（车头为正）
    float hole_front_left_y;   // 孔洞前左角 Y（车左为正）
    float hole_rear_right_x;   // 孔洞后右角 X（车头为正）
    float hole_rear_right_y;   // 孔洞后右角 Y（车左为正）
    // LRU 相对相机中心的两点（不随 ArUco yaw 旋转）
    // 50mm = 相机标定工况 camera_calibration_50.json (z≈0)
    float lru50_front_left_x;  // LRU前左角 X（车头为正）
    float lru50_front_left_y;  // LRU前左角 Y（车左为正）
    float lru50_rear_right_x;  // LRU后右角 X（车头为正）
    float lru50_rear_right_y;  // LRU后右角 Y（车左为正）
    // 16mm = 相机标定工况 camera_calibration_16.json (z≈1700)
    float lru16_front_left_x;  // LRU前左角 X（车头为正）
    float lru16_front_left_y;  // LRU前左角 Y（车左为正）
    float lru16_rear_right_x;  // LRU后右角 X（车头为正）
    float lru16_rear_right_y;  // LRU后右角 Y（车左为正）
};
Q_DECLARE_METATYPE(LRUInnerParams)

// ==============================================
// 【唯一修改点】用内联函数返回静态常量数据
// 消除 non-POD static 警告，且线程安全、初始化安全
// ==============================================
inline const QMap<QString, LRUInnerParams>& LRUpresetData()
{
    // 函数内 static：第一次调用时初始化，绝对安全
    static const QMap<QString, LRUInnerParams> LRU_DATA = {
   // 格式：{"字符串名称", {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10}}
   {"安装车右片架",   {7.0f,4.0f,
                     2655.0f,
                     41.73f,71.95f,
                     62.5f,84.0f,
                     17.5f,84.0f,
                     5.0f,-12.0f,
                     0.0f,0.0f,
                     1,
                     0.0f,
                     -0.11f,0.57f,
                     500000,300000,
                     -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右片架",   {7.0f,4.0f,
                     2655.0f,
                     41.73f,71.95f,
                     62.5f,84.0f,
                     17.5f,84.0f,
                     0.0f,0.0f,
                     0.0f,0.0f,
                     1,
                     0.0f,
                     -0.11f,0.57f,
                     500000,300000,
                     -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},


   {"安装车右右隔板玻璃",   {7.0f,30.0f,
                           2655.0f,
                           41.73f,71.95f,
                           57.5f,112.0f,
                           12.5f,112.0f,
                           -8.5f,0.0f,
                           -6.0f,0.0f,
                           1,
                           0.0f,
                           -0.11f,0.57f,
                           500000,300000,
                           -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右右隔板玻璃",   {7.0f,30.0f,
                           2655.0f,
                           41.73f,71.95f,
                           57.5f,112.0f,
                           12.5f,112.0f,
                           -8.5f,0.0f,
                           -6.0f,0.0f,
                           1,
                           0.0f,
                           -0.11f,0.57f,
                           500000,300000,
                           -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},


   {"安装车右左隔板玻璃",   {7.0f,20.0f,
                           2675.0f,
                           41.73f,71.95f,
                           57.5f,112.0f,
                           12.5f,112.0f,
                           -8.5f,0.0f,
                           -6.0f,0.0f,
                           1,
                           0.0f,
                           -0.11f,0.57f,
                           500000,300000,
                           -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右左隔板玻璃",   {7.0f,20.0f,
                           2675.0f,
                           41.73f,71.95f,
                           57.5f,112.0f,
                           12.5f,112.0f,
                           -8.5f,0.0f,
                           -6.0f,0.0f,
                           1,
                           0.0f,
                           -0.11f,0.57f,
                           500000,300000,
                           -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},


   {"安装车右中灯箱",   {12.0f,3.0f,
                       2695.0f,
                       41.73f,605.95f,
                       52.5f,620.0f,
                       7.5f,620.0f,
                       -2.17f,-9.5f,
                       -1.88f,-6.66f,
                       1,
                       0.0f,
                       -0.11f,0.57f,
                       500000,300000,
                       -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右中灯箱",   {12.0f,3.0f,
                       2695.0f,
                       41.73f,605.95f,
                       52.5f,620.0f,
                       7.5f,620.0f,
                       0.0f,0.0f,
                       0.0f,0.0f,
                       1,
                       0.0f,
                       -0.11f,0.57f,
                       500000,300000,
                       -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},


   {"安装车右侧灯箱",   {12.0f,5.0f,
                       2695.0f,
                       45.9f,-159.9f,
                       52.5f,-157.0f,
                       7.5f,-157.0f,
                       -2.0f,-10.0f,
                       -2.34f,-8.62f,
                       0,
                       0.0f,
                       -0.11f,0.57f,
                       500000,300000,
                       -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右侧灯箱",   {12.0f,5.0f,
                       2695.0f,
                       45.73f,-160.0f,
                       52.5f,-157.0f,
                       7.5f,-157.0f,
                       0.0f,0.0f,
                       0.0f,0.0f,
                       0,
                       0.0f,
                       -0.11f,0.57f,
                       500000,300000,
                       -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},


   {"安装车右片窗",   {7.25f,12.0f,
                     2600.0f,
                     295.73f-32.0f,30.95f,
                     202.5f,52.0f,
                     157.5f,52.0f,
                     -3.0f,-8.0f,
                     -7.0f,0.0f,
                     1,
                     0.0f,
                     -0.11f,0.57f,
                     500000,300000,
                     -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   {"拆卸车右片窗",   {7.25f,12.0f,
                     2600.0f,
                     295.73f-32.0,30.95f,
                     202.5f,52.0f,
                     157.5f,52.0f,
                     0.0f,0.0f,
                     0.0f,0.0f,
                     1,
                     0.0f,
                     -0.11f,0.57f,
                     500000,300000,
                     -0.3f,7.1f,7.3f,3.3f,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,
                     LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET,LRU_RECT_UNSET}},
   };
    return LRU_DATA;
}

#endif // LRUDATADEF_H
