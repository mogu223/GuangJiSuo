# 15 - CoverPlate.cpp 详细源码解读

源码路径：`GuangJiSuo/LRU/CoverPlate.cpp`

## 1. 文件定位

`CoverPlate.cpp` 是盖板/封门子系统的外层控制器实现。

它不是直接把每一步运动逻辑全部写死在一个函数里，而是负责：

```text
1. 初始化盖板机构相关对象
2. 创建 DM 读码器
3. 创建四个 Boost MSM 状态机
4. 启动/停止对应状态机
5. 周期性检查电机位置、电流、DM 读码结果
6. 根据检查结果向状态机投递事件
7. 根据状态机完成状态更新任务标志
8. 向 TaskMgr 反馈 Ready / Running / Complete / Error
9. 急停时停止电机和状态机
```

可以把它理解成：

```text
CoverPlate.cpp = 状态机调度外壳 + 事件检测器 + TaskMgr 反馈层
CoverPlateFSM.h = 具体动作状态机定义
```

---

## 2. 盖板机构涉及哪些动作

从代码看，盖板机构不是单一动作，而是包含四类流程：

```text
1. TakeSealDoor：取封门
2. TakePlate：取盖板
3. FixPlate：盖盖板
4. FixSealDoor：盖封门
```

对应四个状态机对象：

```cpp
m_takeFloorFsm   // 取封门状态机
m_takePlateFsm   // 取盖板状态机
m_coverPlateFsm  // 盖盖板状态机
m_coverFloorFsm  // 盖封门状态机
```

---

## 3. 构造函数

```cpp
CoverPlate::CoverPlate(ZMotionControl* zm, QObject *parent)
    : QObject(parent), m_zm(zm)
```

构造函数接收 `ZMotionControl* zm`。

这说明盖板机构实际运动由正运动控制器执行。

---

## 4. 绑定子系统身份

```cpp
m_TaskStatus.sys = eSubSystem::CoverPlate;
```

这行非常重要。

`CoverPlate` 后面向 `TaskMgr` 反馈 `eTaskStatus` 时，`sys` 字段会告诉调度器：

```text
当前反馈来自盖板子系统
```

---

## 5. 读取配置文件

```cpp
iniReadThreshold = new QSettings("param.ini", QSettings::IniFormat);
iniReadPOS = new QSettings("param.ini", QSettings::IniFormat);
```

两个 `QSettings` 都读 `param.ini`。

当前代码中：

```text
iniReadThreshold：预留给阈值读取
iniReadPOS：读取/保存盖板姿态恢复位置
```

后面盖盖板时会从 `/Motorpos/Pos5` 到 `/Motorpos/Pos8` 读取之前保存的位置。

---

## 6. 初始化 DM 读码器

```cpp
dmcamera = new DMDetected(this);
dmcamera->connectToDevice();
```

DM 读码器用于盖板流程中的位置/二维码识别。

在 `checkEvents()` 中会读取：

```cpp
dmcamera->getValues();
```

并根据读码结果触发视觉调整完成事件。

---

## 7. 初始化四个状态机

```cpp
m_takeFloorFsm = new TakeFloorFSM(this, zm, dmcamera);
m_takePlateFsm = new TakePlateFSM(this, zm, dmcamera);
m_coverPlateFsm = new CoverPlateFSM(this, zm, dmcamera);
m_coverFloorFsm = new CoverFloorFSM(this, zm, dmcamera);
```

这里的状态机类型来自 `CoverPlateFSM.h`。

每个状态机都拿到：

```text
QObject parent
ZMotionControl* zm
DMDetected* dmcamera
```

这说明状态机内部可以：

```text
控制电机
读取 DM 值
发出状态变化信号
```

---

## 8. 连接状态机状态变化信号

```cpp
connect(&m_takeFloorFsm->getFrontFSM(), &TakeFloorFSMFront::sigStateChanged, this, &CoverPlate::onFsmStateChanged);
connect(&m_takePlateFsm->getFrontFSM(), &TakePlateFSMFront::sigStateChanged, this, &CoverPlate::onFsmStateChanged);
connect(&m_coverPlateFsm->getFrontFSM(), &CoverPlateFSMFront::sigStateChanged, this, &CoverPlate::onFsmStateChanged);
connect(&m_coverFloorFsm->getFrontFSM(), &CoverFloorFSMFront::sigStateChanged, this, &CoverPlate::onFsmStateChanged);
```

四个状态机只要进入新状态，都会发 `sigStateChanged`。

外层统一交给：

```cpp
CoverPlate::onFsmStateChanged(const QString& stateName)
```

这个函数负责判断是否进入完成状态。

---

## 9. 两个核心定时器

### 9.1 事件检测定时器

```cpp
m_eventCheckTimer = new QTimer(this);
connect(m_eventCheckTimer, &QTimer::timeout, this, &CoverPlate::checkEvents);
```

每 200ms 检查一次电机位置、电流和 DM 值。

它的作用是：

```text
外部现实世界已经到位了吗？
如果到位，就向状态机投递对应事件。
```

### 9.2 子系统状态监测定时器

```cpp
m_statusMonitorTimer = new QTimer(this);
connect(m_statusMonitorTimer, &QTimer::timeout, this, &CoverPlate::monitorSubsystemStatus);
```

它负责判断 CoverPlate 子系统整体状态：

```text
Ready / Running / Complete / Error
```

---

## 10. 电流采集

```cpp
m_currentCollectionTimer = new QTimer(this);
connect(m_currentCollectionTimer, &QTimer::timeout, this, &CoverPlate::collectMotorCurrents);
m_currentCollectionTimer->start(300);
```

每 300ms 调用一次 `collectMotorCurrents()`。

```cpp
if (m_currentState == eTaskstate::Running) {
    for(int i = 5; i < 12; i++) {
        float current = m_zm->GetMotorCurrent(i);
        DatabaseManager::getInstance()->logSensorData(sensorType, current);
    }
}
```

含义：

```text
盖板机构运行时，记录 5~11 号电机电流到数据库。
```

这有助于后期分析卡滞、碰撞、过载等问题。

---

## 11. 盖板选择函数

### 11.1 选择左右盖板

```cpp
void CoverPlate::ChooseCoverPlate(bool symbol)
{
    GlobalMotorPos::setCoverPlateSymbol(symbol);
}
```

`symbol=true` 代表左侧盖板，`false` 代表右侧盖板。

实际状态存在 `GlobalMotorPos` 命名空间中。

### 11.2 选择中间盖板

```cpp
void CoverPlate::ChooseMiddleCoverPlate(bool symbol)
{
    GlobalMotorPos::setCenterSymbol(symbol);
}
```

中间盖板选择会影响状态机里的守卫条件和借位方向。

### 11.3 重置选择

```cpp
void CoverPlate::ResetChoose()
{
    GlobalMotorPos::resetCoverPlateSymbol();
}
```

清空左/右/中间选择标志。

---

## 12. getSubSystemState()

这个函数判断盖板子系统当前整体状态。

它检查的是 5~11 号轴。

### 12.1 先检查轴错误

```cpp
for (int i = 5; i < 12; ++i) {
    if (m_zm->GetAxisStatus(i) != MyAxisSatus::正常状态) {
        hasAxisError = true;
        m_errorInfo += QString("轴 %1 错误 : %2").arg(i).arg(AxisStatusQstr(...));
    }
}
```

只要任意轴异常：

```cpp
m_currentState = eTaskstate::Error;
return;
```

### 12.2 再检查是否有轴运动

```cpp
if (m_zm->GetAxisMType(i) != AxisMType::Idle)
```

只要 5~11 号轴任意一个不空闲：

```cpp
m_currentState = eTaskstate::Running;
return;
```

### 12.3 所有轴空闲时判断是否完成

```cpp
if (allAxesIdle) {
    if (m_isAutoOpen || m_isAutoClose) {
        m_currentState = eTaskstate::Complete;
        ...
    } else {
        m_currentState = eTaskstate::Ready;
    }
}
```

也就是说，电机停了不一定等于任务完成。

必须满足：

```text
所有轴空闲
并且 m_isAutoOpen 或 m_isAutoClose 被置为 true
```

才会反馈 Complete。

---

## 13. handleStateTransition()

这个函数负责把内部状态变成 `eTaskStatus`，然后发给 TaskMgr。

核心逻辑：

```text
如果状态发生变化：
    更新 m_lastState
    清空旧错误信息
    如果 Complete 或 Error，计算耗时
    更新 m_TaskStatus.state
    如果 Error，写入 m_TaskStatus.info
    emit sigStatusFeedback(m_TaskStatus)
```

这和其他子系统的模式一致。

---

## 14. monitorSubsystemStatus()

```cpp
void CoverPlate::monitorSubsystemStatus()
{
    getSubSystemState();
    handleStateTransition(m_currentState);
}
```

这是状态监测定时器的回调。

它把状态判断和状态上报串起来。

---

## 15. ExeCoverPlateTask()

```cpp
void CoverPlate::ExeCoverPlateTask(TaskInfo info)
{
    m_TaskStatus.taskinfo.TaskType = info.TaskType;
    if(info.TaskType == 1) {
        CoverPlateTask1();
    }
    else if(info.TaskType == 2){
        CoverPlateTask2();
    }
}
```

这是 TaskMgr 调用 CoverPlate 的入口。

含义：

```text
TaskType=1 -> 正向任务
TaskType=2 -> 反向任务
```

---

## 16. 当前正向/反向任务实际逻辑

### 16.1 当前 CoverPlateTask1()

```cpp
void CoverPlate::CoverPlateTask1()
{
    m_taskStartTime = QDateTime::currentDateTime();
    TakePlate();
}
```

当前激活代码只执行 `TakePlate()`。

也就是说，虽然源码里有 `TakeSealDoor()`，但当前自动正向任务没有先执行取封门。

下面被注释掉的旧逻辑才是：

```text
先 TakeSealDoor()
等 TakeFloorCompleted
再启动 TakePlateFSM
```

这点很重要。当前自动流程比注释中的完整流程更简化。

### 16.2 当前 CoverPlateTask2()

```cpp
void CoverPlate::CoverPlateTask2()
{
    m_taskStartTime = QDateTime::currentDateTime();
    FixPlate();
}
```

当前激活代码只执行 `FixPlate()`。

注释中的旧逻辑是：

```text
先 FixPlate()
等 CoverPlateCompleted
再启动 CoverFloorFSM
```

但这部分当前被注释掉了。

---

## 17. 四个动作入口

### 17.1 TakeSealDoor()

```cpp
stopAllFSMs();
m_statusMonitorTimer->start(200);
m_eventCheckTimer->start(200);
m_takeFloorFsm->start();
istakeFloorFsmOpen = true;
```

含义：

```text
停止其他状态机
启动状态监测
启动事件检查
启动取封门状态机
标记取封门状态机打开
```

### 17.2 TakePlate()

```cpp
stopAllFSMs();
m_eventCheckTimer->start(200);
m_statusMonitorTimer->start(200);
m_takePlateFsm->start();
istakePlateFsmOpen = true;
```

启动取盖板状态机。

### 17.3 FixPlate()

```cpp
stopAllFSMs();
m_eventCheckTimer->start(200);
m_statusMonitorTimer->start(200);
m_coverPlateFsm->start();
iscoverPlateFsmOpen = true;
```

启动盖盖板状态机。

### 17.4 FixSealDoor()

```cpp
stopAllFSMs();
m_eventCheckTimer->start(200);
m_statusMonitorTimer->start(200);
m_coverFloorFsm->start();
iscoverFloorFsmOpen = true;
```

启动盖封门状态机。

---

## 18. stopAllFSMs()

```cpp
if (m_takeFloorFsm) m_takeFloorFsm->stop();
istakeFloorFsmOpen = false;
...
```

这个函数会停止四个状态机，并清空四个打开标志。

目的：

```text
保证同一时间只有一个状态机运行。
```

---

## 19. DisableAllFSMs()

```cpp
m_takeFloorFsm->getFrontFSM().m_enableEntryActions = false;
...
```

这个函数不是停止状态机，而是禁用状态进入时的动作。

在 `CoverPlateFSM.h` 里，每个状态 `on_entry` 通常会判断：

```cpp
if (fsm.m_enableEntryActions) {
    执行动作
}
```

所以禁用后，状态可以切换，但不会真的下发运动控制命令。

这可能用于：

```text
手动模式
模拟流程
调试状态机
安全暂停
```

---

## 20. onFsmStateChanged()

```cpp
void CoverPlate::onFsmStateChanged(const QString& stateName)
```

这是四个状态机状态变化的统一回调。

关键完成判断：

```cpp
if (stateName == "TakePlateCompleted") {
    emit sigSymbolChanged(CoverPlateSymbol::TakePlateComplete);
    m_eventCheckTimer->stop();
    m_isAutoOpen = true;
}
else if (stateName == "CoverPlateCompleted") {
    emit sigSymbolChanged(CoverPlateSymbol::CoverPlateComplete);
    m_eventCheckTimer->stop();
    m_isAutoClose = true;
}
```

这说明当前自动流程真正触发 Complete 的是：

```text
TakePlateCompleted -> m_isAutoOpen = true
CoverPlateCompleted -> m_isAutoClose = true
```

随后 `getSubSystemState()` 检测到轴空闲 + 标志为 true，就反馈 `eTaskstate::Complete`。

另外：

```cpp
CoverFloorCompleted -> CoverDoorComplete
TakeFloorCompleted -> TakeDoorComplete
```

这两个只发 UI 标志，没有设置 `m_isAutoOpen/m_isAutoClose`。

---

## 21. checkEvents() 是最核心的桥梁

状态机本身只知道“收到某事件后进入下一状态”。

但事件什么时候发生？由 `checkEvents()` 判断。

它每 200ms 检查：

```text
电机 5/6/7/8/9/10/11 是否到达指定位置
手指电流是否超过阈值
DM 读码值是否发生变化
DM 角度/X/Y 是否满足阈值
```

然后向当前打开的状态机投递事件：

```cpp
m_takePlateFsm->process_event(...);
m_coverPlateFsm->process_event(...);
m_takeFloorFsm->process_event(...);
m_coverFloorFsm->process_event(...);
```

### 21.1 机构恢复事件

```cpp
isRecover1 = axis5≈81 && axis6≈47
isRecover2 = axis7≈0 && axis8≈0
```

满足后给盖封门状态机投递：

```cpp
MyRecoverDone()
```

### 21.2 托举电机事件

轴 11 到不同位置会触发不同事件：

```text
axis11≈12 -> LiftingDone
axis11≈0  -> LiftingDone
axis11≈11 -> LiftingDone
axis11≈39 -> LoweringDone
axis11≈55 -> LoweringDone / LoweringDone_55
axis11≈23 -> LoweringDone
```

这说明轴 11 是托举/升降轴。

### 21.3 横移事件

轴 7、8 到位触发：

```text
1132 -> ForwardTransverseMovementDone
1157 -> HangingDone
0    -> ReverseTransverseMovementDone
100  -> ReverseTransverseMovementTo100
```

### 21.4 手指夹紧电流判断

```cpp
if(abs(m_zm->GetFingerCurrent(10)) > 14) ...
if(abs(m_zm->GetFingerCurrent(11)) > 14) ...
```

两个手指电流都超过阈值后：

```cpp
m_takePlateFsm->process_event(FingerClampingDurDone());
```

这说明“夹紧完成”不完全靠位置，也靠电流判断。

### 21.5 手指位置事件

轴 9、10 到不同位置触发：

```text
≈11.5 -> FingerClampingDone
≈-25  -> FingerNear1Done
≈-50  -> FingerNear2Done
≈10   -> FingerReleasingDone
≈-20  -> FingerReleasingDone
```

### 21.6 纵移事件

轴 5、6 到不同位置触发：

```text
≈50 -> LongitudinalMoveto50Done
≈0  -> LongitudinalMovementDone
相对借位 ±324 / 320 -> 借位完成事件
```

### 21.7 DM 读码事件

```cpp
QVector<float> CurrentDMVal = dmcamera->getValues();
```

如果 DM 值发生变化，触发：

```cpp
ReverseLongitudinalMovementDone()
```

如果 DM 值满足阈值：

```text
角度接近 90° -> AngleAdjustDone
X 接近 0     -> XAdjustDone / XAdjustAdvanceDone
Y 接近 4     -> YAdjustDone / YAdjustAdvanceDone
```

这说明取盖板过程中会做基于 DM 读码结果的姿态调整。

---

## 22. IsManualCoverPlate()

这个函数用于手动任务处理。

它连接状态机完成信号，如果检测到：

```text
TakeFloorCompleted -> 提示手动取盖板完成
CoverPlateCompleted -> 提示手动盖盖板完成
```

问题点：这里每次调用都会重新 connect lambda，如果多次调用可能造成重复连接和重复弹窗。后续可考虑使用 `Qt::UniqueConnection` 或调用前断开旧连接。

---

## 23. emergencyStop()

```cpp
for(int i = 5; i < 12; i++)
{
    m_zm->SingleVMove(i, Cancel);
}
```

急停时停止 5~11 号轴。

注意：它只取消运动，没有看到同时 `stopAllFSMs()`。如果急停后状态机仍处于打开状态，后续 `checkEvents()` 是否还会投递事件，需要结合上层急停逻辑确认。

---

## 24. STOPAllFSMs()

```cpp
void CoverPlate::STOPAllFSMs()
{
    stopAllFSMs();
}
```

这是对外暴露的停止所有状态机接口。

---

## 25. CoverPlate.cpp 的主流程

### 正向当前实际流程

```text
TaskMgr -> ExeCoverPlateTask(TaskType=1)
    ↓
CoverPlateTask1()
    ↓
TakePlate()
    ↓
启动 TakePlateFSM
    ↓
checkEvents() 按电机位置/电流/DM 值投递事件
    ↓
TakePlateCompleted
    ↓
onFsmStateChanged(): m_isAutoOpen = true
    ↓
getSubSystemState(): 轴空闲 + m_isAutoOpen
    ↓
emit sigStatusFeedback(Complete)
```

### 反向当前实际流程

```text
TaskMgr -> ExeCoverPlateTask(TaskType=2)
    ↓
CoverPlateTask2()
    ↓
FixPlate()
    ↓
启动 CoverPlateFSM
    ↓
checkEvents() 投递恢复/抬升/下降等事件
    ↓
CoverPlateCompleted
    ↓
onFsmStateChanged(): m_isAutoClose = true
    ↓
getSubSystemState(): 轴空闲 + m_isAutoClose
    ↓
emit sigStatusFeedback(Complete)
```

---

## 26. 代码中的关键轴号

从 `CoverPlate.cpp` 和 `CoverPlateFSM.h` 看：

| 轴号 | 推测功能 |
|---|---|
| 5、6 | 纵移机构 |
| 7、8 | 横移机构 |
| 9、10 | 手指/夹爪机构 |
| 11 | 托举/升降机构 |

这是根据函数名、注释和到位判断推断的。后续应结合机械图纸或 `zmotioncontrol` 轴定义确认。

---

## 27. 当前代码需要注意的点

### 27.1 自动流程目前只执行取盖板/盖盖板

`CoverPlateTask1()` 当前只调用 `TakePlate()`。

`CoverPlateTask2()` 当前只调用 `FixPlate()`。

完整的“取封门 + 取盖板”和“盖盖板 + 盖封门”流程存在注释代码中，但没有启用。

### 27.2 完成状态只对 TakePlateCompleted / CoverPlateCompleted 设置自动标志

`TakeFloorCompleted` 和 `CoverFloorCompleted` 只发 UI 标志，不会设置 `m_isAutoOpen/m_isAutoClose`。

这和当前自动流程只走取盖板/盖盖板是一致的。

### 27.3 checkEvents 中硬编码位置很多

例如：

```text
81、47、1132、1157、39、55、23、100、-25、-50、324、320
```

这些是机械动作关键参数，后续维护时最好集中配置化。

### 27.4 急停是否停止状态机需要确认

`emergencyStop()` 只取消轴运动，`STOPAllFSMs()` 单独存在。上层急停时最好同时停轴和停状态机。

---

## 28. 阅读重点

优先看这些函数：

```text
CoverPlate::CoverPlate()
ExeCoverPlateTask()
CoverPlateTask1()
CoverPlateTask2()
TakePlate()
FixPlate()
TakeSealDoor()
FixSealDoor()
checkEvents()
onFsmStateChanged()
getSubSystemState()
handleStateTransition()
stopAllFSMs()
emergencyStop()
```

如果只想理解主流程，最关键的是：

```text
ExeCoverPlateTask -> TakePlate/FixPlate -> checkEvents -> onFsmStateChanged -> getSubSystemState -> sigStatusFeedback
```

---

## 29. 和 CoverPlateFSM.h 的关系

`CoverPlate.cpp` 不直接定义每个动作的状态迁移。

它只负责：

```text
启动哪个状态机
检查外部条件
向状态机发送事件
接收状态机完成信号
反馈 TaskMgr
```

具体动作顺序在：

```text
CoverPlateFSM.h
```

也就是下一份文档。