# 06 - TaskMgr.cpp 源码解读

源码路径：`GuangJiSuo/LRU/TaskMgr.cpp`

## 文件定位

`TaskMgr.cpp` 是自动任务调度器的具体实现。

如果说 `TaskMgr.h` 定义了“有哪些步骤和接口”，那么 `TaskMgr.cpp` 就定义了：

```text
怎么开始任务
怎么派发任务
怎么接收子系统反馈
完成后怎么进入下一步
出错后怎么暂停
错误恢复后怎么继续
```

这是理解自动流程的核心文件。

---

## 构造函数

```cpp
TaskMgr::TaskMgr(QObject* parent) : QObject(parent)
{
    loadCurrentStepFromIni();
    CurrentStepGet = new QTimer(this);
    connect(CurrentStepGet,&QTimer::timeout,this,&TaskMgr::saveCurrentStepToIni);
    CurrentStepGet->start(200);
    m_errorOccurred = false;
}
```

含义：

```text
1. 从 ini 文件读取当前步骤
2. 创建定时器
3. 每 200ms 保存一次当前步骤
4. 初始化错误标志为 false
```

这个设计说明作者希望自动流程的当前步骤能持久化，便于断点恢复或异常后查看状态。

注意：源码里保存和读取使用的 ini 文件名可能不一致，需要后续检查：

```text
saveCurrentStepToIni() 使用 param.ini
loadCurrentStepFromIni() 使用 SystemThreshold.ini
```

如果这不是故意设计，就可能是一个潜在问题。

---

## startTask()

```cpp
void TaskMgr::startTask() {
    m_currentStep = SystemStep::Step_Veh_Forward;
    processStep();
}
```

这是自动任务开始入口。

含义：

```text
每次开始安装流程，都从 AGV 前进开始
```

然后调用 `processStep()` 进行第一步派发。

---

## slotSubSysStateChanged()

这是 TaskMgr 最重要的反馈处理函数。

子系统执行任务后，会发：

```cpp
sigStatusFeedback(eTaskStatus)
```

MainWindow 把它连接到：

```cpp
TaskMgr::slotSubSysStateChanged(eTaskStatus status)
```

### 1. 记录当前状态

```cpp
m_currentSystem = status.sys;
m_subSystemStatus[m_currentSystem] = status;
```

把当前子系统状态放入 `QMap`。

### 2. 通知主界面更新状态

```cpp
emit sigStatusInfo(status);
```

主窗口可以根据这个信号打印状态、刷新 UI、写日志。

### 3. 写入数据库

```cpp
DatabaseManager::getInstance()->logTaskStatus(status);
```

每次子系统状态变化都会进入数据库。

### 4. 完成状态处理

```cpp
if (status.state == eTaskstate::Complete)
{
    if (!m_errorOccurred)
    {
        if(AllowContinue){
            m_currentStep = static_cast<SystemStep>(static_cast<int>(m_currentStep) + 1);
            processStep();
        }
    }
}
```

逻辑：

```text
如果子系统完成
且当前没有错误
且允许自动继续
    当前步骤 + 1
    调用 processStep() 派发下一步
```

这是整个自动流程推进的核心。

### 5. 错误状态处理

```cpp
else if (status.state == eTaskstate::Error)
{
    m_errorOccurred = true;
    emit sigError(status);
    DatabaseManager::getInstance()->logError(...);
}
```

逻辑：

```text
如果子系统报错
    标记错误发生
    通知 UI
    记录错误日志
    不再继续下一步
```

---

## dispatchTask()

```cpp
void TaskMgr::dispatchTask(eSubSystem sys, int taskType)
```

这是任务派发函数。

它先构造 `TaskInfo`：

```cpp
TaskInfo taskinfo;
taskinfo.TaskType = taskType;
```

然后根据子系统类型发信号。

例如：

```cpp
case eSubSystem::Vehicle:
    emit sigExeVehTask(taskinfo);
    break;
```

可以理解为：

```text
把抽象任务 sys + taskType 转换成具体 Qt 信号
```

任务类型含义：

```text
1：正向任务
2：反向任务
```

---

## processStep()

这是自动流程状态机。

它读取当前步骤 `m_currentStep`，然后派发对应子系统任务。

核心逻辑：

```cpp
switch (m_currentStep)
{
case Step_Veh_Forward:
    dispatchTask(Vehicle, 1);
    break;
case Step_Levelling_Forward:
    dispatchTask(Levelling, 1);
    break;
case Step_MainLift_Forward:
    dispatchTask(MainLift, 1);
    break;
...
}
```

完整流程：

```text
Step_Veh_Forward          -> Vehicle, TaskType=1
Step_Levelling_Forward    -> Levelling, TaskType=1
Step_MainLift_Forward     -> MainLift, TaskType=1
Step_CoverPlate_Forward   -> CoverPlate, TaskType=1
Step_Lift_Forward         -> Lift, TaskType=1
Step_Lift_Backward        -> Lift, TaskType=2
Step_CoverPlate_Backward  -> CoverPlate, TaskType=2
Step_MainLift_Backward    -> MainLift, TaskType=2
Step_Levelling_Backward   -> Levelling, TaskType=2
Step_Veh_Backward         -> Vehicle, TaskType=2
Step_Done                 -> 任务结束并重置步骤
```

### 错误检查

`processStep()` 开头有：

```cpp
if (m_errorOccurred)
{
    return;
}
```

所以只要出现错误，自动派发就会停止。

---

## resumeFromError()

```cpp
void TaskMgr::resumeFromError()
```

错误恢复逻辑。

流程：

```text
如果当前存在错误
    检查子系统错误是否解决
    如果解决：m_errorOccurred=false，继续 processStep()
    如果未解决：弹窗提示
```

注意：这里继续的是当前步骤，不是从头开始。

---

## checkSubsystemErrorsResolved()

```cpp
bool TaskMgr::checkSubsystemErrorsResolved()
```

遍历 `m_subSystemStatus`，只要还有任何子系统状态为 Error，就返回 false。

这用于防止错误未解决时继续自动流程。

---

## EmitsigExeXXXTask 系列函数

例如：

```cpp
void TaskMgr::EmitsigExeVehTask1()
{
    m_currentStep = SystemStep::Step_Veh_Forward;
    dispatchTask(eSubSystem::Vehicle, 1);
}
```

这些函数用于手动或调试执行某一步。

特点：

```text
先把 m_currentStep 设置到对应步骤
再 dispatchTask
```

原因是：如果不设置当前步骤，子系统完成后 `slotSubSysStateChanged()` 会把当前步骤 +1，导致下一步不对。

---

## saveCurrentStepToIni()

```cpp
QSettings settings("param.ini", QSettings::IniFormat);
settings.setValue("TaskMgr/currentstep", static_cast<int>(m_currentStep));
```

每隔 200ms 保存当前步骤到 `param.ini`。

---

## loadCurrentStepFromIni()

```cpp
QSettings settings("SystemThreshold.ini", QSettings::IniFormat);
int stepValue = settings.value("TaskMgr/currentstep").toInt();
m_currentStep = static_cast<SystemStep>(stepValue);
```

从 `SystemThreshold.ini` 读取步骤。

这里和保存函数的 `param.ini` 不一致。需要后续确认：

```text
如果是笔误，则恢复步骤不会读到刚保存的值。
如果是故意设计，则需要文档说明两个 ini 的职责。
```

---

## 最重要的流程图

```text
TaskMgr::startTask()
    ↓
m_currentStep = Step_Veh_Forward
    ↓
processStep()
    ↓
dispatchTask(Vehicle, 1)
    ↓
emit sigExeVehTask(TaskInfo)
    ↓
SCVehicle::ExeVehTask(TaskInfo)
    ↓
SCVehicle 完成后 emit sigStatusFeedback(eTaskStatus)
    ↓
TaskMgr::slotSubSysStateChanged(status)
    ↓
status.state == Complete
    ↓
m_currentStep + 1
    ↓
processStep()
    ↓
下一个子系统
```

---

## 阅读重点

一定要看懂这四个函数：

```text
startTask()
processStep()
dispatchTask()
slotSubSysStateChanged()
```

这四个函数看懂，自动流程就基本清楚。

---

## 易误解点

### 1. TaskMgr 不是直接执行任务

它只是发信号。真正执行任务的是子系统。

### 2. Complete 后通过枚举值 +1 进入下一步

```cpp
m_currentStep = static_cast<SystemStep>(static_cast<int>(m_currentStep) + 1);
```

这要求 `SystemStep` 枚举顺序必须严格等于任务顺序。如果以后插入步骤，要特别小心。

### 3. Pin 没有进入 processStep 主流程

虽然有 `sigExecPinTask`，但 `processStep()` 当前没有派发 Pin 步骤。

### 4. ini 文件名不一致需要核查

保存当前步骤用 `param.ini`，读取当前步骤用 `SystemThreshold.ini`。这可能是 bug 或遗留问题。

---

## 下一步

读完 `TaskMgr.cpp` 后，进入第一个子系统：

```text
SCVehicle.h / SCVehicle.cpp
```

目标是理解 AGV 如何接收 TaskMgr 的任务，并如何根据 AGV JSON 状态反馈 Complete。