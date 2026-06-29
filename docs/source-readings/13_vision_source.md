# 13 - vision_source 视觉模块源码解读

源码目录：`GuangJiSuo/LRU/vision_source/`

## 目录定位

`vision_source` 是项目的视觉模块目录。

它主要负责：

```text
1. 大恒工业相机控制
2. 双相机图像采集
3. ArUco marker 检测
4. 位姿解算
5. DM/DataMatrix 码检测
6. 光源控制
7. 激光/距离相关传感器
8. 图像显示
9. UDP 通信
```

它不是独立运行的主程序，而是被 `MainWindow` 和 `Lift` 调用。

最重要的关系是：

```text
Lift 持有大恒相机、ArUco 检测器、光源控制器
    ↓
视觉结果用于二级升降和六自由度平台修正
```

---

## 1. dahengTwoCams_qt_vs

源码：

```text
vision_source/dahengTwoCams_qt_vs.h
vision_source/dahengTwoCams_qt_vs.cpp
```

### 文件定位

这是大恒双相机控制模块。

它继承：

```cpp
QMainWindow
```

说明它本身也有一个 Qt 窗口界面。

### 主要职责

```text
初始化大恒 Galaxy SDK
枚举相机设备
过滤 USB 相机
打开指定设备
开始/停止采集
设置曝光
获取最新图像帧 cv::Mat
接收 LRU 参数并调整相机参数
更新视觉 UI
```

### 关键字段

```cpp
#define DEVICE_CONTS 2
```

表示最多同时操作 2 台设备。

```cpp
CDeviceProcess* m_pDeviceProcess[DEVICE_CONTS];
```

每台相机对应一个 `CDeviceProcess` 对象。

```cpp
int camera0_exposureTime = 200000;
int camera1_exposureTime = 200000;
```

两台相机的曝光时间初始值。

### 关键函数

```cpp
bool OpenDeviceByIndex(int deviceIndex);
void StartCaptureByIndex(int deviceIndex);
bool visionprocess();
cv::Mat getlatestframe(int deviceIndex);
void setShutter_us(int deviceIndex, double dExposureUs);
void onParamsReceived(const LRUInnerParams &params);
```

其中：

| 函数 | 作用 |
|---|---|
| `OpenDeviceByIndex` | 按索引打开相机 |
| `StartCaptureByIndex` | 启动指定相机采集 |
| `visionprocess` | 一键式启动视觉流程 |
| `getlatestframe` | 获取最新图像帧 |
| `setShutter_us` | 设置曝光时间 |
| `onParamsReceived` | 根据 LRU 类型更新曝光等参数 |

---

## 2. ArucoDetector

源码：

```text
vision_source/arucoDetector.h
vision_source/arucodetector.cpp
```

### 文件定位

`ArucoDetector` 是 ArUco marker 检测和位姿计算模块。

它负责从图像里找到 marker，并估计相机和目标之间的平面位置关系。

### 核心结构体

#### ArucoResult

```cpp
struct ArucoResult {
    bool detected;
    int id;
    std::vector<cv::Point2f> cornerPixels;
};
```

表示检测结果：

```text
是否检测到
marker id
四个角点像素坐标
```

#### PoseResult

```cpp
struct PoseResult {
    bool valid;
    cv::Vec3d rvec;
    cv::Vec3d tvec;
    cv::Mat rotationMatrix;
    double roll;
    double pitch;
    double yaw;
    double reprojectionError;
};
```

表示完整位姿结果：

```text
旋转向量
平移向量
旋转矩阵
roll/pitch/yaw 欧拉角
重投影误差
```

#### PlanarPose

```cpp
struct PlanarPose {
    bool valid;
    double x;
    double y;
    double yaw;
};
```

表示简化的平面位姿。

对装配任务来说，通常更关心：

```text
x 偏移
y 偏移
yaw 角度偏差
```

### 关键函数

```cpp
ArucoResult detectOneArucoCode(cv::Mat &image);
PlanarPose processImage(cv::Mat &image, float z);
PoseResult solvePnPPose(...);
rotationVectorToEuler(...);
sortCornersTLTRBRBL(...);
onParamsReceived(const LRUInnerParams &params);
```

### 参数依赖

ArucoDetector 内部有很多偏移参数：

```cpp
aruco_to_gapx
aruco_to_gapy
camera_to_lrux_50
camera_to_lruy_50
camera_to_lrux_16
camera_to_lruy_16
marker_id
angle_offset
```

这些参数来自 `LRUdatadef.h`，通过 `onParamsReceived()` 更新。

这说明：

```text
不同 LRU 类型对应不同 marker、不同相机偏移、不同目标补偿。
```

---

## 3. CDeviceProcess / CGXBitmap

源码：

```text
vision_source/CDeviceProcess.h/.cpp
vision_source/CGXBitmap.h/.cpp
```

### 文件定位

这两个模块通常是大恒相机 SDK 的封装层。

大致职责：

```text
CDeviceProcess：设备打开、关闭、采集、回调、帧数据管理
CGXBitmap：把相机图像数据转换成可显示的 Bitmap/QImage
```

阅读时不建议一开始深入 SDK 细节。

先看：

```text
dahengTwoCams_qt_vs 如何调用它们
getlatestframe() 如何拿到 cv::Mat
```

---

## 4. dmdetected

源码：

```text
vision_source/dmdetected.h/.cpp
```

### 文件定位

`DMDetected` 可能负责 DataMatrix/二维码检测。

它在 `CoverPlate` 中被使用：

```cpp
DMDetected* dmcamera;
```

说明盖板/封门流程可能需要识别某些码，用于确认部件或状态。

阅读重点：

```text
检测入口函数
状态更新信号
是否和 CoverPlate 状态机联动
```

---

## 5. guangzilasersensor

源码：

```text
vision_source/guangzilasersensor.h/.cpp
```

### 文件定位

这是激光测距传感器模块。

它在 `MainWindow` 中被创建：

```cpp
lasersensor = new guangziLaserSensor("COM11", this);
lasersensor->openSerialPort();
```

也被 `MainLift` 引用。

作用可能是：

```text
测量一级升降距离
测量目标距离
辅助安全判断
更新 UI 距离标签
```

---

## 6. lightsourcecontroller

源码：

```text
vision_source/lightsourcecontroller.h/.cpp
```

### 文件定位

光源控制器模块。

MainWindow 中创建：

```cpp
lightcontroller = new LightSourceController(this);
lightcontroller->openSerial();
```

并传给 Lift：

```cpp
m_lift = new Lift(zm, dahengForm, lightcontroller, this);
```

这说明光源主要服务于视觉检测。

阅读重点：

```text
串口打开
亮度设置
lightBrightness 信号
MainWindow 中 light1/light2 控件如何联动
```

---

## 7. udpcommunication

源码：

```text
vision_source/udpcommunication.h/.cpp
```

### 文件定位

UDP 通信模块。

`Lift` 中有：

```cpp
UdpCommunication* m_SixDof;
```

MainWindow 连接：

```cpp
m_lift->m_SixDof->poseFeedback -> MainWindow::update_six_platform
```

所以 `udpcommunication` 很可能用于和六自由度平台通信。

阅读重点：

```text
发送什么 UDP 命令
接收什么位姿反馈
poseFeedback 信号携带哪些数据
是否有到位状态判断
```

---

## 视觉模块主数据流

```text
MainWindow 选择 LRU 类型
    ↓
paramsSelected(LRUInnerParams)
    ↓
Lift::onParamsReceived
ArucoDetector::onParamsReceived
dahengTwoCams_qt_vs::onParamsReceived
    ↓
设置 marker_id / offset / 曝光等参数
    ↓
大恒相机采图 cv::Mat
    ↓
ArucoDetector 检测 marker
    ↓
输出 x/y/yaw 或 gap 信息
    ↓
Lift 根据结果执行自动抬升/修正
    ↓
MainWindow / LiftMonitor 显示检测结果
```

---

## 视觉模块和 Lift 的关系

`vision_source` 不是孤立模块，它主要被 `Lift` 使用。

特别是：

```text
dahengTwoCams_qt_vs：提供图像
ArucoDetector：识别 marker 和计算位姿
LightSourceController：保证照明
UdpCommunication：驱动/读取六自由度平台状态
```

这些最终服务于：

```text
二级升降和 LRU 精定位
```

---

## 阅读重点

建议顺序：

```text
1. dahengTwoCams_qt_vs.h/.cpp
   先看相机怎么打开、怎么采图、怎么返回 cv::Mat

2. arucoDetector.h/.cpp
   看 marker 怎么检测、位姿怎么计算、offset 怎么用

3. lightsourcecontroller.h/.cpp
   看光源如何控制

4. udpcommunication.h/.cpp
   看六自由度平台如何通信

5. dmdetected.h/.cpp
   看 DM/二维码检测如何服务 CoverPlate

6. guangzilasersensor.h/.cpp
   看激光测距如何更新 UI 或辅助升降
```

---

## 易误解点

### 1. 大恒相机模块不是最终算法

它主要负责采图。真正位置计算在 ArucoDetector。

### 2. ArUco 的参数来自 LRUdatadef

不同 LRU 的 marker_id 和 offset 不同，所以不能只看 ArucoDetector 默认值。

### 3. vision_source 服务多个子系统

```text
Lift 使用 ArUco + 大恒相机 + 光源 + 六自由度平台
CoverPlate 使用 DMDetected
MainLift / MainWindow 使用激光测距
```

---

## 下一步

读完视觉模块后，进入：

```text
LRU.h / LRU.cpp
```

也就是 OpenGL 3D 模型显示模块。