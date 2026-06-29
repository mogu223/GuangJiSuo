# 08 - LevelingSystem.h / LevelingSystem.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/LevelingSystem.h
GuangJiSuo/LRU/LevelingSystem.cpp
```

## 文件定位

`LevelingSystem` 是车身调平子系统。

它负责：

```text
1. 控制四个脚座/调平电机
2. 检测脚座是否触地
3. 根据角度传感器执行车身调平
4. 控制车身恢复触地
5. 监控电机状态和错误
6. 将任务状态反馈给 TaskMgr
7. 采集电机电流写入数据库
```

可以把它理解为自动流程中的第二步：

```text
AGV 到位后 -> 车身调平
```

---

## 一、LevelingSystem.h 结构

### 1. 类声明

```cpp
class LevelingSystem : public QObject
```

继承 `QObject`，使用 Qt 信号槽。

TaskMgr 会通过信号调用：

```cpp
ExeLevellingTask(TaskInfo info)
```

子系统执行完后会发：

```cpp
sigStatusFeedback(eTaskStatus)
```

---

## 2. 构造函数

```cpp
explicit LevelingSystem(ZMotionControl* zm, QSettings* iniRead, QObject *parent = nullptr);
```

构造函数接收两个关键对象：

| 参数 | 作用 |
|---|---|
| `ZMotionControl* zm` | 控制调平电机/运动轴 |
| `QSettings* iniRead` | 读取调平阈值参数 |

这说明调平逻辑既依赖运动控制器，也依赖配置文件中的阈值。

---

## 3. LevelingState

```cpp
enum class LevelingState {
    Idle,
    ForContact,
    ForBalance
};
```

用于描述自动调平内部阶段：

| 阶段 | 含义 |
|---|---|
| `Idle` | 空闲 |
| `ForContact` | 正在检测脚座触地 |
| `ForBalance` | 正在执行调平 |

这说明“调平正向任务”不是一个动作，而是两个阶段：

```text
脚座触地 -> 执行调平
```

---

## 4. 标志位

```cpp
bool m_isAutoBalance = false;
bool m_isAutotToGround = false;
bool m_isManualBalance = false;
bool m_isManualToGround = false;
```

含义：

| 变量 | 作用 |
|---|---|
| `m_isAutoBalance` | 自动调平完成标志 |
| `m_isAutotToGround` | 自动车身触地完成标志 |
| `m_isManualBalance` | 手动调平完成标志 |
| `m_isManualToGround` | 手动车身触地完成标志 |

这些标志会被状态检测函数用来判断是否进入 `Complete`。

---

## 5. 阈值参数

```cpp
float AngleXThreshold;
float AngleYThreshold;
float FrontLeftFootCurrentThreshold;
float FrontRightFootCurrentThreshold;
float RearLeftFootCurrentThreshold;
float RearRightFootCurrentThreshold;
```

调平需要两个维度的判断：

```text
角度是否在允许范围内
四个脚座电机电流是否达到触地阈值
```

这说明调平不是只靠位置，而是结合角度和电流判断。

---

## 6. 对 TaskMgr 的接口

```cpp
void ExeLevellingTask(TaskInfo info);
```

这是 TaskMgr 调用的总入口。

内部会根据：

```cpp
info.TaskType
```

分成：

```text
TaskType=1：正向任务，脚座触地 + 调平
TaskType=2：反向任务，车身触地/恢复
```

---

# 二、LevelingSystem.cpp 重点

## 1. 构造函数

构造函数中先绑定子系统身份：

```cpp
m_TaskStatus.sys = eSubSystem::Levelling;
```

这意味着它后续发给 TaskMgr 的状态都会标记为：

```text
调平子系统
```

然后创建多个定时器：

```cpp
m_balanceMonitorTimer
m_statusMonitorTimer
detectionTimer
restartTimer
m_currentCollectionTimer
```

用途大致是：

| 定时器 | 用途 |
|---|---|
| `m_balanceMonitorTimer` | 调平阶段监控 |
| `m_statusMonitorTimer` | 子系统状态监测 |
| `detectionTimer` | 脚座触地检测 |
| `restartTimer` | 车身恢复触地检测 |
| `m_currentCollectionTimer` | 周期性采集电流写入数据库 |

---

## 2. 读取阈值

构造函数从 ini 中读取：

```cpp
AngleXThreshold
AngleYThreshold
FrontLeftFootCurrentThreshold
FrontRightFootCurrentThreshold
RearLeftFootCurrentThreshold
RearRightFootCurrentThreshold
```

说明这些不是硬编码参数，而是可以通过配置文件调整。

---

## 3. collectMotorCurrents()

```cpp
void LevelingSystem::collectMotorCurrents()
```

当子系统处于 Running 状态时，循环采集 0~3 号电机电流，并写入数据库。

逻辑：

```text
如果当前状态是 Running
    遍历四个调平电机
    读取电机电流
    写入数据库 logSensorData
```

这说明系统不只是控制动作，还会记录运行过程数据，便于后期追溯。

---

## 4. getSubSystemState()

这是调平子系统状态判断核心。

它按顺序判断：

### 4.1 是否有轴错误

```cpp
for (int i = 0; i < 4; ++i) {
    if (m_zm->GetAxisStatus(i) != MyAxisSatus::正常状态) {
        hasAxisError = true;
    }
}
```

如果任意轴错误：

```text
m_currentState = Error
```

### 4.2 是否有任意轴正在运动

```cpp
if (m_zm->GetAxisMType(i) != AxisMType::Idle)
```

只要任意轴不空闲：

```text
m_currentState = Running
```

### 4.3 所有轴空闲时判断是否完成

如果所有轴空闲，并且：

```cpp
m_isAutoBalance || m_isAutotToGround
```

则判定：

```text
m_currentState = Complete
```

否则：

```text
m_currentState = Ready
```

这就是调平子系统向 TaskMgr 反馈 Complete 的依据。

---

## 5. handleStateTransition()

这个函数负责把内部状态变化转换成 `eTaskStatus` 并发出去。

流程：

```text
判断状态是否变化
    ↓
如果变为 Complete 或 Error，计算任务耗时
    ↓
更新 m_TaskStatus.state
    ↓
如果 Error，写入 m_TaskStatus.info
    ↓
emit sigStatusFeedback(m_TaskStatus)
```

这是调平系统和 TaskMgr 的反馈出口。

---

## 6. monitorSubsystemStatus()

```cpp
void LevelingSystem::monitorSubsystemStatus()
{
    getSubSystemState();
    handleStateTransition(m_currentState);
}
```

这是状态监测定时器的回调。

也就是说，调平系统不是动作执行完直接立刻回调，而是通过定时器周期检查状态，发现状态变化后反馈。

---

## 7. ExeLevellingTask()

```cpp
void LevelingSystem::ExeLevellingTask(TaskInfo info)
```

TaskMgr 调用它。

核心逻辑：

```text
TaskType=1 -> ExeLevelTask1()
TaskType=2 -> ExeLevelTask2()
```

---

## 8. ExeLevelTask1()

这是正向任务。

流程：

```text
启动调平监测定时器
启动状态监测定时器
记录任务开始时间
如果当前阶段是 Idle 或 ForContact：
    FeetToGround()
    当前阶段设为 ForContact
如果当前阶段是 ForBalance：
    BalanceBody()
```

然后定时检查内部阶段：

```text
ForContact 阶段：
    如果 ForLevelOK 为 true
        切到 ForBalance
        BalanceBody()

ForBalance 阶段：
    如果 m_isAutoBalance 为 true
        停止监测
        状态回到 Idle
```

所以正向调平完整逻辑是：

```text
脚座触地 -> 自动调平 -> 完成
```

---

## 9. ExeLevelTask2()

这是反向任务。

流程：

```text
启动状态监测定时器
记录任务开始时间
调用 BodyToGround()
定时等待 m_isAutotToGround=true
```

反向任务可以理解为：

```text
车身恢复触地 / 脚座收回
```

---

## 10. IsManualBalance()

手动调平接管逻辑。

如果当前任务类型是正向，并且角度满足阈值：

```text
m_isManualBalance = true
提示可恢复自动调度
```

这说明系统允许自动流程出错或暂停后由人工手动调平，然后恢复自动流程。

---

## LevelingSystem 在自动流程中的位置

```text
TaskMgr dispatchTask(Levelling, 1)
    ↓
LevelingSystem::ExeLevellingTask(TaskType=1)
    ↓
ExeLevelTask1()
    ↓
FeetToGround()
    ↓
BalanceBody()
    ↓
状态监测 Complete
    ↓
emit sigStatusFeedback
    ↓
TaskMgr 进入一级升降
```

反向流程：

```text
TaskMgr dispatchTask(Levelling, 2)
    ↓
LevelingSystem::ExeLevellingTask(TaskType=2)
    ↓
ExeLevelTask2()
    ↓
BodyToGround()
    ↓
Complete
```

---

## 阅读重点

优先看：

```text
构造函数
ExeLevellingTask()
ExeLevelTask1()
ExeLevelTask2()
getSubSystemState()
handleStateTransition()
monitorSubsystemStatus()
FeetToGround()
BalanceBody()
BodyToGround()
```

---

## 易误解点

### 1. 调平不是单一步骤

正向调平至少包括：

```text
脚座触地
自动调平
```

### 2. Complete 依赖标志位，不只是电机停止

所有轴 Idle 只是条件之一。还要看 `m_isAutoBalance` 或 `m_isAutotToGround`。

### 3. 状态由定时器周期检测

子系统状态不是所有动作完成后直接返回，而是 `m_statusMonitorTimer` 周期判断。

### 4. 电流数据会持续写数据库

Running 状态下会采集电机电流，这对后期故障分析有用。

---

## 下一步

读完调平系统后，进入：

```text
MainLift.h / MainLift.cpp
```

即一级升降子系统。