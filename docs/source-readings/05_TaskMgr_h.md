# 05 - TaskMgr.h 源码解读

源码路径：`GuangJiSuo/LRU/TaskMgr.h`

## 文件定位

`TaskMgr.h` 是自动任务调度器的声明文件。

它定义了：

```text
TaskMgr 类
自动流程步骤 SystemStep
调度器发给子系统的信号
子系统反馈给调度器的槽函数
手动触发某个子系统任务的接口
错误恢复和步骤保存接口
```

可以把它理解为：

```text
自动任务流程的大脑声明
```

---

## TaskMgr 类

```cpp
class TaskMgr: public QObject
```

它继承 `QObject`，说明它使用 Qt 的信号槽机制。

这很重要，因为自动流程不是直接函数调用，而是通过信号槽发任务、收反馈。

---

## 构造函数

```cpp
TaskMgr(QObject* parent = nullptr);
```

构造函数会在 `TaskMgr.cpp` 中初始化当前步骤、定时保存步骤等。

---

## startTask()

```cpp
void startTask();
```

这是开始自动任务的入口。

一般由主窗口按钮触发，例如用户点击“开始任务”。

它的作用是：

```text
把当前步骤设置为第一个步骤，然后调用 processStep()
```

---

## resumeFromError()

```cpp
void resumeFromError();
```

这是错误恢复入口。

当某个子系统报错后，TaskMgr 会暂停流程。问题处理完以后，调用这个函数尝试继续当前步骤。

注意：它不是从头开始，而是尝试从当前步骤继续。

---

## m_errorOccurred

```cpp
bool m_errorOccurred = false;
```

表示当前自动流程是否处于错误暂停状态。

当子系统反馈 `eTaskstate::Error` 时，这个值会变成 `true`。

`processStep()` 开头会检查它：

```text
如果有错误，就不继续派发下一步任务。
```

---

## AllowContinue

```cpp
bool AllowContinue = true;
```

这个变量用于控制完成后是否自动进入下一步。

如果 `AllowContinue=false`，即使子系统反馈 Complete，也不会自动继续。

这类变量常用于：

```text
调试模式
单步执行
暂停自动流程
```

---

# 核心：SystemStep

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

这是自动流程的顺序表。

对应中文流程：

```text
1. AGV驶至终点
2. 车身调平
3. 一级抬升
4. 取盖板
5. 二级抬升
6. 二级下降
7. 盖盖板
8. 一级下降
9. 车身触地
10. AGV退回原点
11. 任务完成
```

这是整个项目最重要的流程定义之一。

---

## StepToString()

```cpp
inline QString StepToString(SystemStep step)
```

把枚举步骤转换成中文字符串。

用途：

```text
UI 显示
日志记录
调试输出
数据库记录
```

例如：

```cpp
Step_Veh_Forward -> "AGV驶至终点"
```

---

## m_currentStep

```cpp
SystemStep m_currentStep;
```

表示当前自动流程进行到哪一步。

TaskMgr 的核心逻辑就是围绕这个变量：

```text
当前步骤是什么
    -> 派发哪个子系统任务
    -> 完成后 m_currentStep + 1
```

---

# signals：TaskMgr 发出的信号

这些信号是 TaskMgr 发给各个子系统的“命令”。

```cpp
void sigExeVehTask(TaskInfo);
void sigExecLevellingTask(TaskInfo);
void sigExecMainLiftTask(TaskInfo);
void sigExecCoverPlateTask(TaskInfo);
void sigExecLiftTask(TaskInfo);
void sigExecPinTask(TaskInfo);
```

含义：

| 信号 | 目标子系统 |
|---|---|
| `sigExeVehTask` | AGV 小车 |
| `sigExecLevellingTask` | 调平系统 |
| `sigExecMainLiftTask` | 一级升降 |
| `sigExecCoverPlateTask` | 盖板机构 |
| `sigExecLiftTask` | 二级升降 |
| `sigExecPinTask` | 销子机构 |

这些信号会在 `MainWindow` 中连接到各个子系统的 `ExeXXXTask(TaskInfo)` 槽函数。

---

## 发给 MainWindow 的信号

```cpp
void sigAllTasksDone();
void sigError(eTaskStatus);
void sigStatusInfo(eTaskStatus);
```

含义：

| 信号 | 作用 |
|---|---|
| `sigAllTasksDone` | 所有任务完成时通知主窗口 |
| `sigError` | 子系统报错时通知主窗口处理错误 |
| `sigStatusInfo` | 每次子系统状态变化时通知主窗口更新 UI/日志 |

---

# public slots：TaskMgr 接收的槽函数

## slotSubSysStateChanged()

```cpp
void slotSubSysStateChanged(eTaskStatus);
```

这是 TaskMgr 最重要的反馈入口。

每个子系统执行完成或出错后，会发：

```cpp
sigStatusFeedback(eTaskStatus)
```

MainWindow 会把这个信号连接到：

```cpp
TaskMgr::slotSubSysStateChanged(eTaskStatus)
```

这个槽函数决定：

```text
Complete -> 进入下一步
Error -> 暂停并通知 UI
Running/Ready -> 更新状态信息
```

---

## 手动触发槽函数

```cpp
void EmitsigExeVehTask1();
void EmitsigExeVehTask2();
void EmitsigExeLevelingTask1();
void EmitsigExeLevelingTask2();
void EmitsigExeMainLiftTask1();
void EmitsigExeMainLiftTask2();
void EmitsigExeCoverPlateTask1();
void EmitsigExeCoverPlateTask2();
void EmitsigExeLiftTask1();
void EmitsigExeLiftTask2();
void EmitsigExePinTask();
```

这些函数用于界面单独执行某一步任务。

命名中的 `1` 和 `2` 对应：

```text
1：正向任务
2：反向任务
```

例如：

```text
EmitsigExeVehTask1 -> AGV 正向任务
EmitsigExeVehTask2 -> AGV 反向任务
```

它们通常用于调试、手动测试、单步执行。

---

## checkSubsystemErrorsResolved()

```cpp
bool checkSubsystemErrorsResolved();
```

用于判断错误是否已经解除。

`resumeFromError()` 会调用它。

---

## saveCurrentStepToIni() / loadCurrentStepFromIni()

```cpp
void saveCurrentStepToIni();
void loadCurrentStepFromIni();
```

用于保存和读取当前步骤。

目的可能是：

```text
程序异常退出后恢复当前任务步骤
调试时记录流程位置
错误恢复时保留进度
```

注意：需要看 `.cpp` 里使用的是哪个 ini 文件，是否一致。

---

## processStep()

```cpp
void processStep();
```

这是 TaskMgr 的核心执行函数。

它读取 `m_currentStep`，然后调用 `dispatchTask(...)` 发出对应子系统任务。

---

# private 区域

## startNextStep()

```cpp
void startNextStep();
```

声明了但需要看 `.cpp` 是否实际使用。如果没有实现或没被调用，可能是遗留设计。

---

## dispatchTask()

```cpp
void dispatchTask(eSubSystem sys, int taskType);
```

这是任务派发函数。

参数：

```text
sys：目标子系统
taskType：任务类型，1 正向，2 反向
```

它会把子系统枚举转换成具体信号。

---

## m_subSystemStatus

```cpp
QMap<eSubSystem, eTaskStatus> m_subSystemStatus;
```

用于记录子系统状态。

键是子系统枚举，值是该子系统最近一次反馈的任务状态。

---

## CurrentStepGet

```cpp
QTimer* CurrentStepGet;
```

定时器，用于周期性保存当前步骤到 ini 文件。

---

## m_currentSystem

```cpp
eSubSystem m_currentSystem;
```

记录当前正在处理或最近反馈的子系统。

错误提示时会用它查当前子系统状态。

---

## TaskMgr.h 的核心理解

`TaskMgr.h` 定义了自动任务的大结构：

```text
有哪些步骤
每一步对应哪个子系统
TaskMgr 会发哪些命令信号
子系统会如何反馈状态
错误如何暂停和恢复
```

---

## 易误解点

### 1. TaskMgr 不直接控制电机

TaskMgr 不直接调用运动控制器，也不直接控制相机或 AGV。

它只负责：

```text
调度顺序
发信号
收状态
切换步骤
```

真正控制硬件的是各子系统类。

### 2. SystemStep 是上位机流程，不是 AGV 任务状态

`SystemStep` 是整个安装/拆卸流程的步骤。

AGV 自己的任务状态在 `nVehicleDataType::TaskStatus` 中。

### 3. Pin 信号存在，但主流程中未明显使用

`TaskMgr` 有 `sigExecPinTask`，但 `SystemStep` 中没有 Pin 步骤。后续需要结合 `Pin.cpp` 和主界面按钮确认销子机构使用方式。

---

## 下一步

读完 `TaskMgr.h` 后，进入：

```text
TaskMgr.cpp
```

重点看：

```text
startTask()
processStep()
dispatchTask()
slotSubSysStateChanged()
resumeFromError()
```
