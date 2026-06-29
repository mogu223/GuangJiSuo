# LRU 源码阅读指南

本文档按建议阅读顺序解释 `GuangJiSuo/LRU` 工程，目标不是逐行翻译代码，而是帮助快速建立源码地图：每个文件负责什么、应该先看哪里、模块之间如何连接。

推荐阅读顺序：

```text
main.cpp
mainwindow.h / mainwindow.cpp
DataType.h
TaskMgr.h / TaskMgr.cpp
SCVehicle
LevelingSystem / MainLift / CoverPlate / Lift / Pin
vision_source
LRU.h / LRU.cpp
```

---

## 0. 先建立整体模型

这个项目是一个 C++/Qt 工业上位机工程，核心不是单个算法，而是把多个硬件子系统组织成一个自动化流程。

可以先按三层理解：

```text
第一层：Qt 程序入口和主界面
main.cpp -> MainWindow

第二层：任务调度层
TaskMgr 负责决定当前该哪个子系统执行

第三层：硬件子系统层
SCVehicle / LevelingSystem / MainLift / CoverPlate / Lift / Pin / vision_source / LRU
```

更具体的数据流大致是：

```text
用户点击“开始任务”
        ↓
MainWindow 调用 TaskMgr::startTask()
        ↓
TaskMgr 根据当前步骤发出某个子系统执行信号
        ↓
对应子系统执行 ExeXXXTask(TaskInfo info)
        ↓
子系统执行完成或出错后发 sigStatusFeedback(eTaskStatus)
        ↓
TaskMgr::slotSubSysStateChanged(eTaskStatus status)
        ↓
如果完成，进入下一步；如果出错，暂停并通知 MainWindow
```

所以读代码时不要从所有按钮开始看。先抓住这条主线：

```text
main.cpp -> MainWindow 构造函数 -> TaskMgr -> 子系统 ExeXXXTask -> sigStatusFeedback
```

---

## 1. main.cpp

### 文件定位

`main.cpp` 是程序入口。它决定程序启动时先做什么。

主要动作：

```text
1. 创建 QApplication
2. 加载 QSS 样式表
3. 注册自定义 Qt 元类型
4. 创建 MainWindow
5. 显示主窗口
6. 安装日志处理器
7. 安装崩溃处理器
8. 进入 Qt 事件循环
```

### 关键理解

这一行是 Qt 桌面程序的基础：

```cpp
QApplication a(argc, argv);
```

它创建整个 Qt 应用对象。没有它，Qt 的界面、事件循环、信号槽都无法正常工作。

这一段读取样式表：

```cpp
QFile file(":/MyQss.qss");
file.open(QFile::ReadOnly);
qss = file.readAll();
file.close();
a.setStyleSheet(qss);
```

说明项目的界面样式被放进了 Qt 资源文件，例如 `QSS.qrc`。

这一行很重要：

```cpp
qRegisterMetaType<nsTaskMgr::DetectedDisplayData>("nsTaskMgr::DetectedDisplayData");
```

它把 `DetectedDisplayData` 注册给 Qt 元对象系统。原因是这个结构体可能会跨线程通过信号槽传递。如果不注册，Qt 可能在运行时报类型无法排队传递的错误。

程序真正进入主逻辑是在这里：

```cpp
MainWindow w;
w.show();
```

所以 `main.cpp` 只需要粗读。看懂它以后，直接进入 `mainwindow.h / mainwindow.cpp`。

---

## 2. mainwindow.h / mainwindow.cpp

### 文件定位

`MainWindow` 是整个上位机的中心类。

它同时负责：

```text
1. 主界面 UI
2. 设备初始化
3. 串口传感器线程
4. 正运动控制器连接
5. AGV 小车通信
6. 调平、升降、盖板、销子等子系统对象创建
7. 视觉、大恒相机、光源、六自由度平台连接
8. TaskMgr 自动任务调度连接
9. 数据库、图表、日志、状态监控窗口
10. 大量按钮槽函数
```

所以 `MainWindow` 是一个“大总管”。读它时不要试图一次看完全部函数。

### 先看 mainwindow.h

`mainwindow.h` 的价值是：你可以先看到系统有哪些能力。

重点看三类内容。

第一类：头文件 include。

例如：

```cpp
#include "TaskMgr.h"
#include "SCVehicle.h"
#include "LevelingSystem.h"
#include "MainLift.h"
#include "CoverPlate.h"
#include "Lift.h"
#include "Pin.h"
```

这说明 `MainWindow` 直接持有任务调度器和所有子系统对象。

第二类：按钮槽函数。

例如：

```cpp
void on_btn_StartTask_clicked();
void on_btn_ExeVehTaskForward_clicked();
void on_btn_ExeLevelTaskForward_clicked();
void on_btn_ExeMainLiftTaskForward_clicked();
```

Qt 的自动连接规则里，`on_控件名_信号名()` 往往对应 UI 上某个按钮。看到这类函数时，可以理解为“界面按钮入口”。

第三类：成员变量。

重点看这些：

```cpp
TaskMgr *m_TaskMgr;
SCVehicle *m_vehicle;
LevelingSystem *m_levelingSystem;
MainLift *m_mainLift;
CoverPlate *m_coverPlate;
Lift *m_lift;
Pin *m_pin;
```

这些就是自动任务链的主要对象。

### 再看 mainwindow.cpp 的构造函数

`MainWindow::MainWindow()` 是最重要的部分之一。构造函数里完成大量初始化。

重点看这几块。

#### 2.1 UI 初始化

```cpp
ui->setupUi(this);
```

这行会把 `mainwindow.ui` 设计出来的界面真正加载到 `MainWindow` 对象上。

#### 2.2 传感器和线程初始化

代码中创建了多个 `SerialSensor`：

```cpp
m_forceSensor = new SerialSensor(SensorType::FORCE_SENSOR);
m_angleSensor = new SerialSensor(SensorType::ANGLE_SENSOR);
m_distanceSensor = new SerialSensor(SensorType::DISTANCE_SENSOR);
m_battery = new SerialSensor(SensorType::BATTERY_SENSOR);
```

然后把它们移动到不同 `QThread` 里：

```cpp
m_forceSensor->moveToThread(m_forceThread);
m_angleSensor->moveToThread(m_angleThread);
m_distanceSensor->moveToThread(m_distanceThread);
```

这说明力、角度、距离、电池等传感器不是都在 UI 主线程里读，而是分线程处理，避免界面卡死。

#### 2.3 正运动控制器初始化

```cpp
zm = ZMotionControl::getinstance();
```

`zm` 是运动控制核心对象。后面的调平、一级升降、盖板、二级升降、销子等机构，基本都需要它控制电机/轴。

#### 2.4 TaskMgr 和子系统创建

这段是自动任务链的核心：

```cpp
m_TaskMgr = new TaskMgr(this);
m_vehicle = new SCVehicle(this);
m_levelingSystem = new LevelingSystem(zm, iniRead, this);
m_mainLift = new MainLift(zm, this);
m_coverPlate = new CoverPlate(zm, this);
m_pin = new Pin(zm, this);
m_lift = new Lift(zm, dahengForm, lightcontroller, this);
```

可以这样理解：

```text
TaskMgr：调度大脑
SCVehicle：AGV 小车
LevelingSystem：车身调平
MainLift：一级升降
CoverPlate：取/盖盖板
Lift：二级升降 + 视觉 + 六自由度平台 + 力检测
Pin：销子机构
```

#### 2.5 TaskMgr 到子系统的连接

这是最重要的信号槽关系之一：

```cpp
connect(m_TaskMgr, &TaskMgr::sigExeVehTask,
        m_vehicle, &SCVehicle::ExeVehTask);

connect(m_TaskMgr, &TaskMgr::sigExecLevellingTask,
        m_levelingSystem, &LevelingSystem::ExeLevellingTask);

connect(m_TaskMgr, &TaskMgr::sigExecMainLiftTask,
        m_mainLift, &MainLift::ExeMainLiftTask);

connect(m_TaskMgr, &TaskMgr::sigExecCoverPlateTask,
        m_coverPlate, &CoverPlate::ExeCoverPlateTask);

connect(m_TaskMgr, &TaskMgr::sigExecLiftTask,
        m_lift, &Lift::ExeLiftTask);

connect(m_TaskMgr, &TaskMgr::sigExecPinTask,
        m_pin, &Pin::ExePinTask);
```

这表示：

```text
TaskMgr 发信号
    ↓
对应子系统开始执行任务
```

#### 2.6 子系统反馈给 TaskMgr

另一组连接是反向反馈：

```cpp
connect(m_vehicle, &SCVehicle::sigStatusFeedback,
        m_TaskMgr, &TaskMgr::slotSubSysStateChanged);
```

其他子系统类似。

这表示：

```text
子系统完成/出错
    ↓
发出 sigStatusFeedback(eTaskStatus)
    ↓
TaskMgr 收到状态
    ↓
决定继续下一步，还是暂停报错
```

### MainWindow 的阅读建议

先不要逐个读所有 `on_btn_xxx_clicked()`。

建议顺序：

```text
1. 构造函数 MainWindow::MainWindow()
2. 找 m_TaskMgr 和各子系统创建位置
3. 找 TaskMgr 和子系统的 connect
4. 找 on_btn_StartTask_clicked()
5. 找 handleTaskError()
6. 再按功能看具体按钮函数
```

---

## 3. DataType.h

### 文件定位

`DataType.h` 是项目的公共数据类型文件。它定义了很多枚举、结构体和状态转换函数。

它不负责执行动作，但它定义了各模块之间通信时用的数据格式。

### 主要命名空间

这个文件里主要有两个命名空间：

```cpp
namespace nVehicleDataType
namespace nsTaskMgr
```

可以这样理解：

```text
nVehicleDataType：AGV 小车和传感器相关数据
nsTaskMgr：任务调度相关数据
```

### nVehicleDataType

这里定义了 AGV 状态、阻挡原因、导航任务状态等。

例如：

```cpp
enum class BlockReason
```

表示 AGV 被阻挡的原因：

```text
超声
激光
防跌落传感器
碰撞传感器
红外传感器
锁车开关
动态障碍物
虚拟激光
3D 相机
距离传感器
DI 超声
```

```cpp
enum class TaskStatus
```

表示 AGV 当前任务状态：

```text
NONE
WAITING
RUNNING
SUSPENDED
COMPLETED
FAILED
CANCELED
OVERTIME
```

```cpp
struct VehicleSts
```

是 AGV 实时状态结构体，里面包含：

```text
是否被阻挡
阻挡原因
电池电量
任务状态
是否静止
急停状态
是否充电
错误列表
当前站点
当前地图
任务路径
二维码信息
重定位状态
地图加载状态
控制权所有者
```

这说明 AGV 模块不是只发一个“前进/后退”命令，而是持续解析小车回传的完整状态。

### nsTaskMgr

这里定义自动任务调度用的数据。

#### TaskInfo

```cpp
struct TaskInfo
{
    int TaskType = 0;
    QString LRU = "无";
    QString TaskListName = "无";
    QString TargetStation = "无";
};
```

`TaskInfo` 是 TaskMgr 发给子系统的任务参数。

目前最重要的是：

```text
TaskType = 1：正向任务
TaskType = 2：反向任务
```

例如：

```text
Vehicle + TaskType=1：AGV 去目标点
Vehicle + TaskType=2：AGV 返回原点
Lift + TaskType=1：二级抬升
Lift + TaskType=2：二级下降
```

#### eTaskstate

```cpp
enum class eTaskstate
{
    Init,
    Ready,
    Running,
    Complete,
    Error
};
```

这是所有子系统向 TaskMgr 反馈的统一状态。

#### eSubSystem

```cpp
enum class eSubSystem
{
    Vehicle,
    Levelling,
    MainLift,
    CoverPlate,
    Lift
};
```

这是自动流程中参与调度的子系统枚举。

注意：`Pin` 在 `TaskMgr` 里有信号，但 `eSubSystem` 当前没有列出 `Pin`。这说明销子系统可能还没完全纳入主自动流程，或者后来设计有变。

#### eTaskStatus

```cpp
struct eTaskStatus
{
    eSubSystem sys;
    TaskInfo taskinfo;
    eTaskstate state;
    double duration = 0.0f;
    QString info = "无";
};
```

这是最关键的数据结构之一。子系统完成任务或报错时，会用它告诉 TaskMgr：

```text
我是哪个子系统
我执行的是什么任务
现在是完成、运行、错误还是准备状态
耗时多久
附加信息是什么
```

### DataType.h 的阅读建议

先看这些：

```text
TaskInfo
eTaskstate
eSubSystem
eTaskStatus
VehicleSts
```

读懂这些，后面看 `TaskMgr` 和各子系统反馈会轻松很多。

---

## 4. TaskMgr.h / TaskMgr.cpp

### 文件定位

`TaskMgr` 是自动任务调度器。它不直接控制硬件，而是决定“当前该哪个子系统执行”。

### 核心状态机

`TaskMgr.h` 里定义了自动流程步骤：

```cpp
enum class SystemStep
{
    Step_Veh_Forward,
    Step_Levelling_Forward,
    Step_MainLift_Forward,
    Step_CoverPlate_Forward,
    Step_Lift_Forward,
    Step_Lift_Backward,
    Step_CoverPlate_Backward,
    Step_MainLift_Backward,
    Step_Levelling_Backward,
    Step_Veh_Backward,
    Step_Done
};
```

对应中文流程：

```text
AGV驶至终点
车身调平
一级抬升
取盖板
二级抬升
二级下降
盖盖板
一级下降
车身触地
AGV退回原点
任务完成
```

这就是项目的主自动流程。

### startTask()

```cpp
void TaskMgr::startTask() {
    m_currentStep = SystemStep::Step_Veh_Forward;
    processStep();
}
```

含义：每次开始任务，都从 AGV 前进开始。

### processStep()

`processStep()` 根据当前 `m_currentStep` 决定发哪个任务。

例如：

```cpp
case SystemStep::Step_Veh_Forward:
    dispatchTask(eSubSystem::Vehicle, 1);
    break;
```

含义是：当前步骤是 AGV 前进，于是向 Vehicle 子系统发送 `TaskType=1` 的任务。

整体模式：

```text
当前步骤
    ↓
dispatchTask(子系统, 任务类型)
    ↓
发出对应信号
    ↓
子系统执行
```

### dispatchTask()

`dispatchTask()` 把子系统枚举转换成具体信号。

例如：

```cpp
case eSubSystem::Vehicle:
    emit sigExeVehTask(taskinfo);
    break;
```

这就是 TaskMgr 和子系统之间的“命令出口”。

### slotSubSysStateChanged()

这是 TaskMgr 的反馈入口。

子系统完成后，会发：

```cpp
sigStatusFeedback(eTaskStatus)
```

MainWindow 已经把这个信号连接到：

```cpp
TaskMgr::slotSubSysStateChanged(eTaskStatus status)
```

这个函数判断：

```text
如果 status.state == Complete：
    当前步骤 + 1
    processStep()

如果 status.state == Error：
    标记 m_errorOccurred = true
    通知 UI
    写错误日志到数据库
```

所以 TaskMgr 的核心就是：

```text
发任务 -> 等反馈 -> 完成则下一步 -> 出错则暂停
```

### 错误恢复

`resumeFromError()` 用于错误处理后的恢复。

它会先检查 `checkSubsystemErrorsResolved()`，如果错误消失，则继续当前步骤。

注意：这是“从当前步骤继续”，不是从头开始。

### TaskMgr 的阅读建议

重点读四个函数：

```text
startTask()
processStep()
dispatchTask()
slotSubSysStateChanged()
```

如果这四个函数看懂，自动流程就基本清楚了。

---

## 5. SCVehicle

### 文件定位

`SCVehicle` 是 AGV 小车子系统。

它负责和 AGV 建立多路 TCP 通信，发送导航/控制命令，解析小车实时状态，并向 TaskMgr 反馈任务完成状态。

### 四类 TCP 连接

`SCVehicle.h` 中可以看到四类连接：

```cpp
connectPushHost()
connectNavigateHost()
connectStatusHost()
connectControlHost()
```

大致对应：

| 连接 | 作用 |
|---|---|
| PushHost | 接收 AGV 推送的实时状态 |
| NavigateHost | 发送导航相关命令 |
| StatusHost | 查询状态，例如控制权所有者 |
| ControlHost | 控制类 API，例如重定位、上传地图 |

### 主要能力

`SCVehicle` 支持：

```text
上传地图
AGV 重定位
暂停导航
继续导航
取消导航
查询控制权所有者
平移
旋转
接收状态推送
解析 JSON 状态
执行调度任务 ExeVehTask(TaskInfo)
```

### 和 TaskMgr 的关系

TaskMgr 发出：

```cpp
sigExeVehTask(TaskInfo)
```

MainWindow 连接到：

```cpp
SCVehicle::ExeVehTask(TaskInfo info)
```

然后 AGV 执行对应任务。

执行完成后，SCVehicle 发：

```cpp
sigStatusFeedback(eTaskStatus)
```

TaskMgr 收到后进入下一步。

### 阅读建议

先读：

```text
SCVehicle.h
ExeVehTask(TaskInfo info)
RecvPushHostJsonData(QString info)
parseJsonToVehicleSts(...)
sigStatusFeedback 发出位置
```

重点不是 TCP 细节，而是看 AGV 如何判断“任务完成”。

---

## 6. LevelingSystem / MainLift / CoverPlate / Lift / Pin

这些是自动任务链中的执行机构。它们共同特点是：

```text
1. 继承 QObject
2. 持有 ZMotionControl* m_zm
3. 有 ExeXXXTask(TaskInfo info)
4. 有 eTaskStatus m_TaskStatus
5. 完成或出错后发 sigStatusFeedback(eTaskStatus)
6. 通常有状态监测 QTimer
```

也就是说，它们都遵循同一种调度接口。

---

### 6.1 LevelingSystem

`LevelingSystem` 是车身调平系统。

它负责：

```text
脚座触地
车身上升/下降
自动调平
手动调平
急停
电机电流采集
调平状态监测
```

关键变量：

```cpp
bool m_isAutoBalance;
bool m_isAutotToGround;
bool m_isManualBalance;
bool m_isManualToGround;
```

这些表示当前是自动调平、自动触地、手动调平还是手动触地。

关键阈值：

```cpp
AngleXThreshold
AngleYThreshold
FrontLeftFootCurrentThreshold
FrontRightFootCurrentThreshold
RearLeftFootCurrentThreshold
RearRightFootCurrentThreshold
```

说明调平判断依赖角度阈值和四个脚座电机电流阈值。

阅读重点：

```text
ExeLevellingTask(TaskInfo info)
ExeLevelTask1()
ExeLevelTask2()
FeetToGround()
BalanceBody()
getSubSystemState()
handleStateTransition()
```

---

### 6.2 MainLift

`MainLift` 是一级升降系统。

它负责：

```text
一级上升
一级下降
手动升降
急停
激光测距辅助
电流采集
状态监测
```

它也持有：

```cpp
ZMotionControl* m_zm;
guangziLaserSensor* laser;
eTaskStatus m_TaskStatus;
```

说明一级升降不仅控制电机，还可能使用激光测距传感器判断位置或安全距离。

阅读重点：

```text
ExeMainLiftTask(TaskInfo info)
ExeMainLiftTask1()
ExeMainLiftTask2()
IsManualLift()
getSubSystemState()
monitorSubsystemStatus()
```

---

### 6.3 CoverPlate

`CoverPlate` 是盖板/封门机构。

它负责：

```text
取封门
取盖板
盖盖板
盖封门
选择左/右/中盖板
DM 读码器检测
状态机控制
电机电流采集
```

关键点是它内部有多个 FSM：

```cpp
TakeFloorFSM* m_takeFloorFsm;
TakePlateFSM* m_takePlateFsm;
CoverPlateFSM* m_coverPlateFsm;
CoverFloorFSM* m_coverFloorFsm;
```

FSM 是有限状态机。这里说明“取封门、取盖板、盖盖板、盖封门”每个动作可能由多个小步骤组成，不是简单一条电机命令。

阅读重点：

```text
ExeCoverPlateTask(TaskInfo info)
CoverPlateTask1()
CoverPlateTask2()
TakeSealDoor()
TakePlate()
FixPlate()
FixSealDoor()
checkEvents()
onFsmStateChanged(...)
stopAllFSMs()
```

---

### 6.4 Lift

`Lift` 是二级升降系统，也是最复杂的执行子系统之一。

它不仅控制二级升降，还集成：

```text
大恒相机
ArUco 视觉检测
光源控制
六自由度平台 UDP 通信
六维力传感器数据
碰撞检测
脱离检测
LRU 参数
自动抬升/自动下降
```

关键对象：

```cpp
UdpCommunication* m_SixDof;
LightSourceController *m_lightcontroller;
ArucoDetector *m_vision_detected;
dahengTwoCams_qt_vs *m_dahengCamera;
```

这说明二级升降不是单纯上下运动，而是结合视觉和六自由度平台进行精定位。

关键检测：

```cpp
CheckCollision();
CheckDetach();
SetForceData(SixForeData* data);
```

说明它根据六维力数据判断碰撞或 LRU 是否挂上/脱离。

关键视觉流程：

```cpp
vision_detected();
auto_vision_detected();
auto_lift();
auto_descent();
onParamsReceived(const LRUInnerParams &params);
```

`onParamsReceived()` 用于接收某种 LRU 类型的预设参数。

阅读重点：

```text
ExeLiftTask(TaskInfo info)
ExeLiftTask1()
ExeLiftTask2()
SetForceData(...)
CheckCollision()
CheckDetach()
vision_detected()
auto_lift()
auto_descent()
onParamsReceived(...)
```

---

### 6.5 Pin

`Pin` 是销子机构。

当前 `Pin.h` 比其他子系统简单很多。

它包含：

```cpp
ExePinTask(TaskInfo info)
JudgeTaskStatus(bool status)
emergencyStop()
sigStatusFeedback(eTaskStatus)
```

但是 `DataType.h` 的 `eSubSystem` 当前没有明确列出 `Pin`，而 `TaskMgr` 里虽然有 `sigExecPinTask`，但自动流程 `SystemStep` 没有把 Pin 放进主步骤链。

所以目前判断：

```text
Pin 可能是预留/半集成子系统，或者主要通过界面手动控制，尚未完整纳入主自动流程。
```

阅读重点：

```text
Pin.h
Pin.cpp
ExePinTask(TaskInfo info)
MainWindow 中和 IOForward / IOBackward / PMC 相关的槽函数
```

---

## 7. vision_source

### 文件定位

`vision_source` 是视觉模块目录。

从工程文件和头文件看，主要包含：

```text
大恒相机控制
ArUco 标记识别
DM/DataMatrix 读码
图像显示
光源控制
激光传感器
UDP 通信
```

### dahengTwoCams_qt_vs

这是大恒双相机模块。

它负责：

```text
初始化大恒相机 API
枚举设备
过滤 USB 相机
打开指定设备
开始采集
停止采集
设置曝光
获取最新帧 cv::Mat
接收 LRU 参数更新相机曝光等配置
```

关键函数：

```cpp
OpenDeviceByIndex(int deviceIndex)
StartCaptureByIndex(int deviceIndex)
visionprocess()
getlatestframe(int deviceIndex)
setShutter_us(int deviceIndex, double dExposureUs)
onParamsReceived(const LRUInnerParams &params)
```

### ArucoDetector

这是 ArUco 视觉定位模块。

它负责：

```text
检测 ArUco marker
根据 marker 四个角点计算位姿
读取相机标定参数
计算平面位姿 x/y/yaw
根据 LRU 参数更新 offset、marker_id 等
```

关键结构体：

```cpp
ArucoResult
PoseResult
PlanarPose
```

关键函数：

```cpp
detectOneArucoCode(cv::Mat &image)
processImage(cv::Mat &image, float z)
solvePnPPose(...)
rotationVectorToEuler(...)
onParamsReceived(const LRUInnerParams &params)
```

### 视觉模块和 Lift 的关系

`Lift` 持有：

```cpp
dahengTwoCams_qt_vs *m_dahengCamera;
ArucoDetector *m_vision_detected;
LightSourceController *m_lightcontroller;
```

所以视觉模块主要服务于二级升降和 LRU 精定位。

阅读建议：

```text
先看 dahengTwoCams_qt_vs.h：理解相机怎么打开、怎么取图
再看 arucoDetector.h/.cpp：理解 marker 怎么识别、位姿怎么解算
最后看 Lift.cpp：看识别结果如何用于自动抬升/下降
```

---

## 8. LRU.h / LRU.cpp

### 文件定位

`LRU` 是 OpenGL 3D 显示模块。

它继承自：

```cpp
QOpenGLWidget
```

说明它是一个可以嵌入 Qt 界面的 OpenGL 绘图控件。

### 主要功能

```text
加载 STL 模型
读取 STL 顶点和法线
创建 OpenGL buffer
绘制模型
绘制天花板
鼠标旋转/平移/缩放视图
根据电机位置更新模型位置
```

### 关键函数

```cpp
bool loadSTLModel(const QString &fileName);
void updateModelPosition(float motorXPosition, float motorYPosition, float motorZPosition, float rotationAngleY);
void initializeGL() override;
void paintGL() override;
bool readSTLFile(...);
void render();
void initializeGLResources();
void updateBuffers();
```

### loadSTLModel()

这个函数做：

```text
1. 读取 STL 文件
2. 得到顶点 vertices 和法线 normals
3. 设置 m_dataLoaded = true
4. 清理旧 OpenGL 资源
5. 初始化或更新 buffer
6. 计算模型 x/y/z 范围
7. 触发 update() 重绘
```

### render()

`render()` 做真正绘制：

```text
1. 检查 OpenGL 错误
2. 清屏
3. 启用深度测试
4. 绑定 shader
5. 设置 model/view/projection 矩阵
6. 绑定 VAO
7. glDrawArrays 绘制 STL 三角面
8. 绘制天花板
9. 释放 OpenGL 资源
```

### 阅读建议

如果你主要目标是理解控制逻辑，`LRU.cpp` 可以放后面看。它更偏 3D 显示，不是自动任务调度核心。

如果你要理解模型如何跟随机构运动，则重点看：

```text
updateModelPosition(...)
render()
modelMatrix 设置位置
```

---

## 9. 最关键的主流程图

把上面所有模块串起来，可以得到主流程：

```text
main.cpp
  ↓
MainWindow::MainWindow()
  ↓
创建 TaskMgr 和各子系统
  ↓
connect(TaskMgr 信号 -> 子系统 ExeXXXTask)
  ↓
connect(子系统 sigStatusFeedback -> TaskMgr::slotSubSysStateChanged)
  ↓
用户点击 StartTask
  ↓
TaskMgr::startTask()
  ↓
TaskMgr::processStep()
  ↓
SCVehicle::ExeVehTask(TaskType=1)
  ↓
AGV 到位后反馈 Complete
  ↓
LevelingSystem::ExeLevellingTask(TaskType=1)
  ↓
MainLift::ExeMainLiftTask(TaskType=1)
  ↓
CoverPlate::ExeCoverPlateTask(TaskType=1)
  ↓
Lift::ExeLiftTask(TaskType=1)
  ↓
Lift::ExeLiftTask(TaskType=2)
  ↓
CoverPlate::ExeCoverPlateTask(TaskType=2)
  ↓
MainLift::ExeMainLiftTask(TaskType=2)
  ↓
LevelingSystem::ExeLevellingTask(TaskType=2)
  ↓
SCVehicle::ExeVehTask(TaskType=2)
  ↓
任务结束
```

---

## 10. 新手阅读策略

不要从 `mainwindow.cpp` 的几千行开始硬读。建议这样做：

### 第一遍：只看结构

```text
main.cpp
mainwindow.h 的成员变量和槽函数
TaskMgr.h 的 SystemStep
eTaskStatus / TaskInfo / eSubSystem
```

目标：知道系统有哪些模块。

### 第二遍：看自动流程

```text
MainWindow 构造函数里的 connect
TaskMgr::startTask
TaskMgr::processStep
TaskMgr::dispatchTask
TaskMgr::slotSubSysStateChanged
```

目标：知道任务怎么从一个子系统流到下一个子系统。

### 第三遍：看单个子系统

按顺序看：

```text
SCVehicle
LevelingSystem
MainLift
CoverPlate
Lift
Pin
```

每个子系统只抓三个问题：

```text
1. ExeXXXTask 收到 TaskInfo 后做什么？
2. 它怎么判断 Complete / Error？
3. 它在哪里 emit sigStatusFeedback？
```

### 第四遍：看视觉和 3D

最后再看：

```text
vision_source
LRU.h / LRU.cpp
```

目标：理解视觉定位和模型显示，不要一开始被 OpenCV/OpenGL 细节拖住。

---

## 11. 当前代码结构的注意点

### 11.1 MainWindow 过重

`MainWindow` 同时处理 UI、硬件初始化、任务连接、传感器线程、数据库、图表、视觉和调试按钮。阅读时必须分块看。

### 11.2 TaskMgr 是线性状态机

当前自动流程是严格顺序执行。每个步骤完成后，`m_currentStep + 1`。这简单清晰，但复杂异常恢复和并行动作能力有限。

### 11.3 Pin 似乎没有完整纳入主流程

`TaskMgr` 有 Pin 信号，`Pin` 也有 `ExePinTask`，但 `SystemStep` 和 `eSubSystem` 当前没有完整体现 Pin。后续需要确认销子机构到底是自动流程的一部分，还是手动/局部流程。

### 11.4 Lift 是最复杂子系统

`Lift` 同时涉及二级升降、视觉、力传感器、六自由度平台和光源控制。阅读时不要先看细节，先看 `ExeLiftTask` 如何分发正向/反向任务。

---

## 12. 最短阅读路径

如果只想最快看懂项目主线，按这个最短路径：

```text
main.cpp
  看程序怎么进入 MainWindow

mainwindow.h
  看 MainWindow 有哪些子系统对象

mainwindow.cpp 构造函数
  看对象如何初始化，信号槽如何连接

DataType.h
  看 TaskInfo / eTaskStatus / eSubSystem

TaskMgr.h / TaskMgr.cpp
  看自动任务步骤和状态流转

SCVehicle.h / LevelingSystem.h / MainLift.h / CoverPlate.h / Lift.h
  看每个子系统的 ExeXXXTask 和 sigStatusFeedback
```

读完这条路径，就能理解项目的大框架。之后再深入具体硬件动作。