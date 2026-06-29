# 12 - Pin.h / Pin.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/Pin.h
GuangJiSuo/LRU/Pin.cpp
```

## 文件定位

`Pin` 是销子机构子系统。

相比 `LevelingSystem`、`CoverPlate`、`Lift`，`Pin` 当前代码结构明显更简单。

它主要负责：

```text
1. 接收销子任务
2. 判断销子任务状态
3. 急停
4. 向 TaskMgr 反馈任务状态
```

但从当前结构看，`Pin` 可能还没有完整并入主自动流程。

---

## 一、Pin.h 结构

### 1. 类声明

```cpp
class Pin: public QObject
```

继承 `QObject`，支持 Qt 信号槽。

---

## 2. 构造函数

```cpp
explicit Pin(ZMotionControl* zm, QObject *parent = nullptr);
```

构造函数接收 `ZMotionControl* zm`，说明销子动作也依赖正运动控制器。

---

## 3. 任务状态

```cpp
eTaskStatus m_TaskStatus;
```

和其他子系统一致，Pin 也有自己的任务状态结构。

理论上它可以通过：

```cpp
sigStatusFeedback(eTaskStatus)
```

向 TaskMgr 反馈状态。

---

## 4. 状态监测定时器

```cpp
QTimer* m_statusMonitorTimer;
```

说明 Pin 也可能周期性判断任务状态，不过具体是否充分使用要看 `Pin.cpp`。

---

## 5. 主要槽函数

```cpp
void JudgeTaskStatus(bool status);
void ExePinTask(TaskInfo info);
void emergencyStop();
```

含义：

| 函数 | 作用 |
|---|---|
| `JudgeTaskStatus(bool status)` | 根据布尔状态判断销子任务是否完成/失败 |
| `ExePinTask(TaskInfo info)` | TaskMgr 调用的销子任务入口 |
| `emergencyStop()` | 急停 |

---

## 6. 反馈信号

```cpp
void sigStatusFeedback(eTaskStatus);
```

用于反馈给 TaskMgr。

---

# 二、Pin 在当前架构中的特殊点

`TaskMgr.h` 中有：

```cpp
void sigExecPinTask(TaskInfo);
```

`MainWindow` 里也连接了：

```cpp
TaskMgr::sigExecPinTask -> Pin::ExePinTask
Pin::sigStatusFeedback -> TaskMgr::slotSubSysStateChanged
```

但是 `DataType.h` 的 `eSubSystem` 当前没有列出 `Pin`：

```cpp
enum class eSubSystem:int
{
    Vehicle,
    Levelling,
    MainLift,
    CoverPlate,
    Lift
};
```

而 `TaskMgr::processStep()` 当前主流程中也没有 Pin 步骤。

所以目前判断：

```text
Pin 类存在，TaskMgr 也预留了 Pin 信号，MainWindow 也做了连接；
但 Pin 尚未完整进入 SystemStep 主自动流程。
```

它可能是：

```text
1. 预留功能
2. 后续要接入自动流程
3. 主要通过 MainWindow 手动按钮控制
4. 和 PMC 电机/IO 控制逻辑混在主窗口中
```

---

## 三、Pin.cpp 阅读重点

读 `Pin.cpp` 时重点看：

```text
Pin 构造函数
ExePinTask(TaskInfo info)
JudgeTaskStatus(bool status)
emergencyStop()
sigStatusFeedback 发出位置
```

尤其要确认：

```text
1. m_TaskStatus.sys 被设置成什么
2. TaskType=1/2 是否有区别
3. 是否实际控制 ZMotion 轴
4. 任务完成条件是什么
5. 错误条件是什么
```

---

## 四、和 MainWindow 的关系

`mainwindow.h` 中有很多和销子/IO/PMC 相关的按钮函数，例如：

```text
on_btn_IOForward_pressed()
on_btn_IOForward_released()
on_btn_IOBackward_pressed()
on_btn_IOBackward_released()
on_btn_PMCConnect_clicked()
on_btn_PMCSpeedForward_pressed()
on_btn_PMCSpeedBackward_pressed()
on_btn_LightClamp_clicked()
on_btn_LightRelease_clicked()
```

这些可能和销子、夹紧、灯箱固定/松开等动作有关。

所以理解 Pin 时，除了 `Pin.cpp`，还应该搜索 MainWindow 中这些按钮函数。

---

## 五、Pin 在自动流程中的可能位置

如果未来要纳入自动流程，可能会放在：

```text
二级抬升完成后 -> 销子动作 -> 二级下降
```

或者：

```text
盖板动作前后 -> 销子锁定/释放
```

但当前 `SystemStep` 中没有它，所以不能直接断定它已经参与完整自动流程。

---

## 阅读重点

优先看：

```text
Pin.h
Pin.cpp
TaskMgr 是否调用 sigExecPinTask
DataType.h 是否加入 Pin 枚举
MainWindow 中 IO/PMC 相关槽函数
```

---

## 易误解点

### 1. 有 Pin 类不等于已经进入主流程

需要看 `SystemStep` 和 `processStep()` 是否派发 Pin。

### 2. Pin 可能和主窗口里的 IO/PMC 控制相关

销子动作不一定全部封装在 `Pin.cpp` 里，可能有一部分还在 `MainWindow` 按钮槽函数中。

### 3. eSubSystem 没有 Pin 是一个结构不一致点

如果要让 Pin 正式进入自动调度，应该考虑：

```text
1. eSubSystem 增加 Pin
2. SystemStep 增加 Pin 步骤
3. processStep() 增加 dispatchTask(Pin, ...)
4. Pin 正确设置 m_TaskStatus.sys
```

---

## 下一步

读完 Pin 后，进入：

```text
vision_source/
```

也就是视觉模块。