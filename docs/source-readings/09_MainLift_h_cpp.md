# 09 - MainLift.h / MainLift.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/MainLift.h
GuangJiSuo/LRU/MainLift.cpp
```

## 文件定位

`MainLift` 是一级升降子系统。

它负责：

```text
1. 一级升降正向抬升
2. 一级升降反向下降
3. 手动升降
4. 急停
5. 状态监测
6. 电机电流采集
7. 使用激光测距传感器辅助判断位置/距离
8. 向 TaskMgr 反馈任务状态
```

在自动流程中，它位于调平之后、取盖板之前：

```text
AGV 到位 -> 调平 -> 一级抬升 -> 取盖板
```

---

## 一、MainLift.h 结构

### 1. 类声明

```cpp
class MainLift: public QObject
```

继承 `QObject`，使用 Qt 信号槽。

TaskMgr 会通过信号调用：

```cpp
ExeMainLiftTask(TaskInfo info)
```

MainLift 执行完成后通过：

```cpp
sigStatusFeedback(eTaskStatus)
```

反馈给 TaskMgr。

---

## 2. 构造函数

```cpp
explicit MainLift(ZMotionControl* zm, QObject *parent = nullptr);
```

构造函数接收 `ZMotionControl* zm`。

这说明一级升降主要通过正运动控制器控制轴或电机。

---

## 3. 自动/手动标志位

```cpp
bool m_isAutotUp = false;
bool m_isAutoDown = false;
bool m_isManualUp = false;
bool m_isManualDown = false;
```

含义：

| 变量 | 作用 |
|---|---|
| `m_isAutotUp` | 自动上升完成标志 |
| `m_isAutoDown` | 自动下降完成标志 |
| `m_isManualUp` | 手动上升完成/可恢复标志 |
| `m_isManualDown` | 手动下降完成/可恢复标志 |

这些变量会参与状态判定。

---

## 4. 激光测距传感器

```cpp
guangziLaserSensor* laser;
```

一级升降持有一个激光测距传感器指针。

这说明一级升降不是只按电机位置运动，也可能读取距离传感器判断当前位置或安全距离。

---

## 5. TaskMgr 入口

```cpp
void ExeMainLiftTask(TaskInfo info);
```

这是 TaskMgr 调用的入口。

应重点查看它如何根据 `TaskType` 分发：

```text
TaskType=1 -> ExeMainLiftTask1()
TaskType=2 -> ExeMainLiftTask2()
```

---

## 6. 正向/反向任务

```cpp
void ExeMainLiftTask1();
void ExeMainLiftTask2();
```

通常可以理解为：

```text
ExeMainLiftTask1：一级抬升
ExeMainLiftTask2：一级下降
```

---

## 7. 状态监测

```cpp
void getSubSystemState();
void handleStateTransition(eTaskstate newState);
void monitorSubsystemStatus();
```

这和 `LevelingSystem` 的模式类似：

```text
周期读取轴状态
判断 Ready / Running / Complete / Error
状态变化时 emit sigStatusFeedback
```

---

## 二、MainLift.cpp 阅读重点

虽然具体实现需要逐行看 `MainLift.cpp`，但根据类结构，可以先按下面顺序阅读。

### 1. 构造函数

重点看：

```text
是否绑定 m_TaskStatus.sys = eSubSystem::MainLift
创建了哪些定时器
读取了哪些 ini 阈值
初始化了哪些电机/轴编号
是否初始化激光传感器
```

### 2. ExeMainLiftTask()

重点看它如何处理：

```cpp
info.TaskType
```

预期逻辑：

```text
TaskType=1：调用 ExeMainLiftTask1()
TaskType=2：调用 ExeMainLiftTask2()
```

### 3. ExeMainLiftTask1()

重点看：

```text
启动哪个轴
目标位置是多少
是否使用激光距离作为到位条件
是否启动状态监测定时器
何时设置 m_isAutotUp=true
```

### 4. ExeMainLiftTask2()

重点看：

```text
下降动作如何执行
是否有下限位/距离保护
何时设置 m_isAutoDown=true
```

### 5. getSubSystemState()

重点看状态如何判断：

```text
轴错误 -> Error
轴运动 -> Running
轴空闲 + 完成标志 -> Complete
轴空闲 + 无完成标志 -> Ready
```

### 6. handleStateTransition()

重点看它是否和其他子系统一致：

```text
计算任务耗时
更新 m_TaskStatus.state
错误时写 m_TaskStatus.info
emit sigStatusFeedback(m_TaskStatus)
```

---

## MainLift 在自动流程中的位置

正向流程：

```text
TaskMgr dispatchTask(MainLift, 1)
    ↓
MainLift::ExeMainLiftTask(TaskType=1)
    ↓
ExeMainLiftTask1()
    ↓
一级抬升
    ↓
Complete
    ↓
TaskMgr 进入 CoverPlate 正向任务
```

反向流程：

```text
TaskMgr dispatchTask(MainLift, 2)
    ↓
MainLift::ExeMainLiftTask(TaskType=2)
    ↓
ExeMainLiftTask2()
    ↓
一级下降
    ↓
Complete
    ↓
TaskMgr 进入 Levelling 反向任务
```

---

## 这个子系统和其他模块的关系

| 相关模块 | 关系 |
|---|---|
| `TaskMgr` | 派发一级升降任务，接收状态反馈 |
| `ZMotionControl` | 执行实际轴运动 |
| `guangziLaserSensor` | 提供距离信息 |
| `DatabaseManager` | 记录运行过程数据 |
| `MainWindow` | 提供按钮入口和 UI 显示 |
| `LiftMonitor` | 显示升降相关监控信息 |

---

## 阅读重点

优先看：

```text
MainLift 构造函数
ExeMainLiftTask()
ExeMainLiftTask1()
ExeMainLiftTask2()
getSubSystemState()
handleStateTransition()
monitorSubsystemStatus()
collectMotorCurrents()
```

---

## 易误解点

### 1. MainLift 是一级升降，不是二级升降

二级升降在 `Lift` 类中。`MainLift` 只负责一级抬升/下降。

### 2. laser 不等于视觉相机

这里的 `guangziLaserSensor* laser` 是激光测距，不是大恒相机视觉。

### 3. Complete 通常不是函数直接返回

和其他子系统一样，完成状态往往由定时器周期检查后反馈，而不是动作函数直接返回。

---

## 下一步

读完一级升降后，进入：

```text
CoverPlate.h / CoverPlate.cpp
```

也就是取盖板/盖盖板/封门机构。