# 02 - mainwindow.h 源码解读

源码路径：`GuangJiSuo/LRU/mainwindow.h`

## 文件定位

`mainwindow.h` 是 `MainWindow` 类的声明文件。它不会直接告诉你每个函数怎么实现，但它能告诉你整个上位机系统有哪些功能、有哪些成员对象、有哪些按钮入口、连接了哪些子系统。

可以把它理解为：

```text
主窗口能力清单 + 系统模块清单
```

---

## MainWindow 是什么

```cpp
class MainWindow : public QMainWindow
```

说明 `MainWindow` 是 Qt 的主窗口类。

它继承 `QMainWindow`，所以它拥有菜单栏、工具栏、状态栏、中心控件等能力。项目里的 `mainwindow.ui` 会通过 `ui->setupUi(this)` 加载到这个类上。

---

## include 区域说明

`mainwindow.h` 的 include 非常多，这说明 `MainWindow` 直接依赖很多模块。

重点 include：

```cpp
#include "TaskMgr.h"
#include "SCVehicle.h"
#include "LevelingSystem.h"
#include "MainLift.h"
#include "CoverPlate.h"
#include "Lift.h"
#include "Pin.h"
```

这些是自动流程的核心对象。

还包括：

```cpp
#include "vision_source/dahengTwoCams_qt_vs.h"
#include "vision_source/dmdetected.h"
#include "vision_source/guangzilasersensor.h"
#include "DatabaseManager.h"
#include "SerialSensor.h"
#include "LRUdatadef.h"
#include "SharedMemory/sharedmemorymanager.h"
```

说明主窗口还负责视觉、传感器、数据库、LRU 参数、共享内存相机等。

---

## public 区域

```cpp
explicit MainWindow(QWidget *parent = nullptr);
~MainWindow();
```

这是构造函数和析构函数。

阅读时要重点看 `mainwindow.cpp` 里的构造函数，因为它负责创建对象、初始化线程、连接信号槽。

---

## protected 区域

```cpp
void closeEvent(QCloseEvent *event) override;
```

这是重写关闭窗口事件。

常见用途：

```text
关闭设备连接
停止线程
保存参数
释放相机/运动控制器资源
提示用户确认退出
```

这个项目涉及大量硬件，所以 `closeEvent` 很可能很重要。

---

## private slots 区域

Qt 中 `slots` 是可以被信号触发的函数。

`mainwindow.h` 中大量函数名类似：

```cpp
void on_btnXXX_clicked();
```

这是 Qt Designer 常见自动连接命名规则：

```text
on_控件对象名_信号名()
```

例如：

```cpp
void on_btn_StartTask_clicked();
```

通常对应 UI 上对象名为 `btn_StartTask` 的按钮被点击。

---

## 槽函数分组理解

不要逐个死记槽函数。应该按功能分组。

### 1. 运动控制器和轴控制

例如：

```cpp
on_btnInitBus_clicked()
on_btnConnect_clicked()
on_btnEnableAxis_clicked()
on_btnDisableAxis_clicked()
on_btnEmergencyStop_clicked()
```

这些一般对应正运动控制器连接、初始化、使能、断开、急停等。

---

### 2. 串口传感器

例如：

```cpp
on_btnOpenForceCOM_clicked()
on_btnOpenAngleCOM_clicked()
on_btnOpenDistanceCOM_clicked()
onForceDataReceived(...)
onAngleDataReceived(...)
onDistanceDataReceived(...)
onBatteryDataReceived(...)
```

这些对应力传感器、角度传感器、距离传感器、电池传感器。

---

### 3. 调平系统

例如：

```cpp
on_btn_FeetToGround_clicked()
on_btn_BodyToGround_clicked()
on_btn_BalanceBody_clicked()
on_btn_PosBodyUp_clicked()
on_btn_PosBodyDown_clicked()
```

这些是调平相关按钮入口。

---

### 4. 六自由度平台和六维力传感器

例如：

```cpp
on_btn_PlatformOpen_clicked()
on_btn_PlatformGo_clicked()
on_btn_PlatformStop_clicked()
update_six_platform(...)
onSixAxisSensorDataReady(...)
```

这些和六自由度平台运动、位姿反馈、六维力数据更新有关。

---

### 5. 视觉模块

例如：

```cpp
on_btn_secondary_lift_clicked()
on_btn_CheckStatus_clicked()
on_btn_StatusModifyLatter_clicked()
slot_updateGapInfo(nsTaskMgr::DetectedDisplayData vision_data)
onLight1ValueChanged(int value)
onLight2ValueChanged(int value)
onComboChanged(const QString &text)
```

这些说明主窗口接收视觉检测数据，调节光源亮度，并根据 LRU 类型选择参数。

---

### 6. AGV 小车通信

例如：

```cpp
on_btn_CnntPushSvr_clicked()
on_btn_CnntNavigateSvr_clicked()
on_btn_CnntStatusSvr_clicked()
on_btn_CnntControlSvr_clicked()
on_btn_AGVReLocation_clicked()
on_btn_AGVPauseNavigate_clicked()
on_btn_AGVContinueNavigate_clicked()
on_btn_AGVCancelNavigate_clicked()
```

这些对应 AGV 的四路 TCP 通讯、重定位、暂停/继续/取消导航。

---

### 7. 自动任务调度

最重要的是：

```cpp
on_btn_StartTask_clicked()
on_btn_StopTask_clicked()
on_btn_PauseTask_clicked()
on_btn_ContinueTask_clicked()
```

以及单步执行按钮：

```cpp
on_btn_ExeVehTaskForward_clicked()
on_btn_ExeLevelTaskForward_clicked()
on_btn_ExeMainLiftTaskForward_clicked()
on_btn_ExeCoverPlateTaskForward_clicked()
on_btn_ExeLiftTaskForward_clicked()
```

这些是 UI 到 `TaskMgr` 的入口。

---

## private 成员变量

这是理解 `mainwindow.h` 最重要的部分。

### 1. UI 指针

```cpp
Ui::MainWindow *ui;
```

这是 Qt Designer 生成的 UI 对象。所有界面控件一般通过 `ui->xxx` 访问。

---

### 2. 配置文件

```cpp
QSettings *iniRead;
QSettings *iniReadThreshold;
```

用于读取 `.ini` 配置，例如电机参数、阈值、系统参数。

---

### 3. 运动控制器

```cpp
ZMotionControl* zm;
```

这是控制运动轴的核心对象。多个子系统都会依赖它。

---

### 4. 视觉与传感器

```cpp
dahengTwoCams_qt_vs *dahengForm;
LightSourceController* lightcontroller;
guangziLaserSensor* lasersensor;
DMDetected* dmcamera;
```

这些分别对应：

```text
大恒双相机
光源控制
激光测距传感器
DM 读码器
```

---

### 5. 串口传感器和线程

```cpp
SerialSensor *m_forceSensor;
SerialSensor *m_angleSensor;
SerialSensor *m_distanceSensor;
SerialSensor *m_battery;

QThread *m_forceThread;
QThread *m_angleThread;
QThread *m_distanceThread;
QThread *m_batteryThread;
```

说明传感器读取放在独立线程中。

---

### 6. 任务调度和子系统对象

```cpp
TaskMgr *m_TaskMgr;
SCVehicle *m_vehicle;
LevelingSystem *m_levelingSystem;
MainLift *m_mainLift;
CoverPlate *m_coverPlate;
Lift *m_lift;
Pin *m_pin;
```

这是全项目最重要的一组成员。

理解方式：

```text
m_TaskMgr：自动流程调度器
m_vehicle：AGV 小车
m_levelingSystem：调平子系统
m_mainLift：一级升降
m_coverPlate：盖板/封门机构
m_lift：二级升降 + 视觉 + 六自由度平台
m_pin：销子机构
```

---

## 这个文件暴露出的架构特点

### 1. MainWindow 是中心控制器

`MainWindow` 直接持有几乎所有子系统对象，所以它是当前项目的集成中心。

优点：

```text
所有模块都能在一个地方连接起来，调试方便
```

缺点：

```text
类过大，职责过多，后续维护难度较高
```

---

### 2. 项目是事件驱动架构

大量函数是按钮槽函数、定时器槽函数、传感器回调、网络回调。

所以不要用“从第一行执行到最后一行”的方式理解它。应该用事件触发方式理解。

---

### 3. 自动任务和手动按钮并存

`mainwindow.h` 里既有自动任务按钮，也有大量手动控制按钮。这说明系统既支持自动流程，也支持人工调试/手动接管。

---

## 阅读重点

读 `mainwindow.h` 时优先看：

```text
1. include 了哪些子系统
2. private slots 中有哪些功能入口
3. private 成员变量中有哪些核心对象
4. TaskMgr 和各子系统对象声明
5. 传感器、视觉、数据库、线程成员
```

不建议第一遍就逐个理解所有按钮函数。

---

## 下一步

读完 `mainwindow.h` 后，进入：

```text
mainwindow.cpp
```

重点看构造函数，因为它会告诉你这些成员对象如何被创建、如何通过信号槽连接起来。