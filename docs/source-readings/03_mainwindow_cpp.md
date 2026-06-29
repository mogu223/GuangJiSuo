# 03 - mainwindow.cpp 源码解读

源码路径：`GuangJiSuo/LRU/mainwindow.cpp`

## 文件定位

`mainwindow.cpp` 是 `MainWindow` 的实现文件，也是整个上位机项目中最核心、最重的文件之一。

它负责把 UI、硬件、传感器、任务调度、视觉系统和数据库全部连接起来。

可以把它理解为：

```text
系统集成中心
```

---

## 阅读原则

不要从第一行一直读到最后一行。这个文件太大，应该按功能块读。

推荐阅读顺序：

```text
1. MainWindow::MainWindow() 构造函数
2. 子系统对象创建位置
3. TaskMgr 和子系统的 connect
4. on_btn_StartTask_clicked()
5. handleTaskError(...)
6. 各子系统手动按钮槽函数
7. 数据库、图表、调试按钮等辅助功能
```

---

## 构造函数是重点

```cpp
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ...
}
```

这段的意义是：

```text
创建主窗口对象
加载 mainwindow.ui
初始化所有硬件、线程、子系统和信号槽连接
```

`ui->setupUi(this)` 会把 Qt Designer 设计的界面加载到 `MainWindow`。

---

## 1. UI 和表格初始化

构造函数中创建了系统状态表格模型：

```cpp
m_tableModel = new QStandardItemModel(this);
m_tableModel->setColumnCount(2);
m_tableModel->setHorizontalHeaderLabels({"时间", "提示信息"});
ui->tableView_SystemStatus->setModel(m_tableModel);
```

这说明主界面有一个状态信息表格，用来显示时间和提示信息。

日志/状态输出不是简单打印到控制台，而是会被送到 UI 表格中。

---

## 2. 配置文件和运动控制器初始化

```cpp
iniRead = new QSettings("param.ini", QSettings::IniFormat);
zm = ZMotionControl::getinstance();
```

`iniRead` 用于读取 `param.ini` 参数。

`zm` 是正运动控制器单例对象，后面多个子系统都会使用它。

可以理解成：

```text
ZMotionControl 是底层运动控制入口
MainWindow 拿到它以后，把它传给各个执行机构
```

---

## 3. 运动状态回调线程

```cpp
zm->startCallbackThread([this](ZmotionStatus* status) {
    handleDataFetched(status);
});
```

这段说明运动控制器有一个后台数据采集线程。

它的含义是：

```text
ZMotionControl 在后台读取运动控制器状态
读取到 ZmotionStatus 后回调 MainWindow::handleDataFetched(status)
```

这里的 lambda 是把成员函数包装成回调函数。

---

## 4. 串口传感器和线程

构造函数中创建了多个传感器：

```cpp
m_forceSensor = new SerialSensor(SensorType::FORCE_SENSOR);
m_angleSensor = new SerialSensor(SensorType::ANGLE_SENSOR);
m_distanceSensor = new SerialSensor(SensorType::DISTANCE_SENSOR);
m_battery = new SerialSensor(SensorType::BATTERY_SENSOR);
```

分别对应：

```text
力传感器
角度传感器
距离传感器
电池传感器
```

随后创建对应线程并把对象移动进去：

```cpp
m_forceSensor->moveToThread(m_forceThread);
m_angleSensor->moveToThread(m_angleThread);
m_distanceSensor->moveToThread(m_distanceThread);
m_battery->moveToThread(m_batteryThread);
```

这说明传感器读数不会阻塞主界面。

### Qt::QueuedConnection

很多 connect 使用：

```cpp
Qt::QueuedConnection
```

这通常用于跨线程信号槽。意思是信号不会立即直接调用槽函数，而是投递到目标线程的事件队列中执行。

---

## 5. 硬件急停信号

```cpp
connect(ZMotionControl::getinstance(),
        &ZMotionControl::sig_EmergencyStopPressed,
        this,
        &MainWindow::onEmergencyStopPressed,
        Qt::QueuedConnection);
```

这说明运动控制层检测到急停后，会通知 MainWindow。

急停属于安全关键逻辑，后续应重点查看：

```cpp
onEmergencyStopPressed()
on_btn_AllRapidStop_clicked()
各子系统 emergencyStop()
```

---

## 6. TaskMgr 和子系统对象创建

这是自动任务流程最关键的对象初始化：

```cpp
m_TaskMgr = new TaskMgr(this);
m_vehicle = new SCVehicle(this);
m_levelingSystem = new LevelingSystem(zm, iniRead, this);
m_mainLift = new MainLift(zm, this);
m_coverPlate = new CoverPlate(zm, this);
m_pin = new Pin(zm, this);
```

后面又创建：

```cpp
m_lift = new Lift(zm, dahengForm, lightcontroller, this);
```

对象含义：

| 对象 | 作用 |
|---|---|
| `m_TaskMgr` | 自动任务调度器 |
| `m_vehicle` | AGV 小车 |
| `m_levelingSystem` | 调平系统 |
| `m_mainLift` | 一级升降 |
| `m_coverPlate` | 取盖板/盖盖板/封门机构 |
| `m_lift` | 二级升降 + 视觉 + 六自由度平台 |
| `m_pin` | 销子机构 |

---

## 7. 视觉和六自由度平台初始化

```cpp
dahengForm = new dahengTwoCams_qt_vs(this);
lightcontroller = new LightSourceController(this);
lightcontroller->openSerial();
m_lift = new Lift(zm, dahengForm, lightcontroller, this);
```

这里说明：

```text
大恒相机对象和光源控制对象先创建
然后作为参数传给 Lift
```

这意味着 `Lift` 是视觉和二级升降的集成点。

### LRU 参数下发

```cpp
connect(this, &MainWindow::paramsSelected,
        m_lift, &Lift::onParamsReceived);
connect(this, &MainWindow::paramsSelected,
        m_lift->m_vision_detected, &ArucoDetector::onParamsReceived);
connect(this, &MainWindow::paramsSelected,
        m_lift->m_dahengCamera, &dahengTwoCams_qt_vs::onParamsReceived);
```

这表示当用户选择某种 LRU 类型后，参数会同时发给：

```text
Lift
ArucoDetector
大恒相机模块
```

所以 LRU 类型会影响：

```text
二级升降目标
视觉 offset
marker_id
相机曝光
```

---

## 8. TaskMgr 到子系统的信号连接

这是最重要的一组 connect：

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

含义：

```text
TaskMgr 决定当前步骤
    ↓
发出某个 sigExecXXXTask 信号
    ↓
对应子系统的 ExeXXXTask 被调用
```

这就是自动流程“发命令”的路径。

---

## 9. 子系统反馈给 TaskMgr

第二组关键连接：

```cpp
connect(m_vehicle, &SCVehicle::sigStatusFeedback,
        m_TaskMgr, &TaskMgr::slotSubSysStateChanged);
```

其他子系统同理。

含义：

```text
子系统完成或出错
    ↓
发出 sigStatusFeedback(eTaskStatus)
    ↓
TaskMgr::slotSubSysStateChanged 收到状态
    ↓
TaskMgr 决定进入下一步或暂停
```

所以 MainWindow 是把两边接起来：

```text
TaskMgr -> 子系统
子系统 -> TaskMgr
```

---

## 10. TaskMgr 和 UI 的连接

```cpp
connect(m_TaskMgr, &TaskMgr::sigStatusInfo,
        this, &MainWindow::slotPrintStatus);

connect(m_TaskMgr, &TaskMgr::sigError,
        this, &MainWindow::handleTaskError);
```

含义：

```text
状态信息 -> 主界面显示
错误信息 -> 主界面处理错误并暂停
```

`handleTaskError()` 是异常流程重点。读自动调度时必须看。

---

## 11. 监控窗口

构造函数中还创建了多个监控窗口：

```cpp
monitor = new lrumonitor(this);
agvmonitor = new AGVMonitor(this);
levelmonitor = new LevelMonitor(zm, this);
liftmonitor = new LiftMonitor(zm, this);
coverplatemonitor = new CoverPlateMonitor(zm, this);
pinmonitor = new PinMonitor(this);
CoverPlate3D = new NewForm(this);
```

这些不是主流程控制器，而是状态显示/调试窗口。

---

## 12. mainwindow.cpp 的核心价值

`mainwindow.cpp` 的核心不是某一个算法，而是连接所有模块。

它的核心结构可以总结为：

```text
初始化 UI
初始化硬件对象
初始化线程
初始化子系统
连接信号槽
启动定时器
响应按钮事件
处理状态反馈
```

---

## 阅读重点

第一遍只看这些：

```text
MainWindow::MainWindow()
m_TaskMgr 和各子系统 new 的位置
TaskMgr -> 子系统 connect
子系统 -> TaskMgr connect
m_lift / dahengForm / lightcontroller 的创建关系
on_btn_StartTask_clicked()
handleTaskError()
```

不要第一遍就看全部按钮函数。

---

## 易误解点

### 1. MainWindow 不是单纯 UI

它不仅显示界面，还承担了系统集成和对象生命周期管理。

### 2. 自动流程不是按钮逐个调用

自动流程主要通过 `TaskMgr` 的信号槽驱动，而不是主窗口手动顺序调用每个子系统函数。

### 3. Lift 比名字复杂

`Lift` 不只是升降，它还拿到了大恒相机、光源控制、六自由度平台和视觉检测对象，是最复杂子系统之一。

---

## 下一步

读完 `mainwindow.cpp` 的构造函数后，下一步看：

```text
DataType.h
```

因为你需要理解 `TaskInfo`、`eTaskStatus`、`eSubSystem` 这些数据结构，才能继续读 `TaskMgr`。