# 10 - CoverPlate.h / CoverPlate.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/CoverPlate.h
GuangJiSuo/LRU/CoverPlate.cpp
```

## 文件定位

`CoverPlate` 是盖板/封门机构子系统。

它负责：

```text
1. 取封门
2. 取盖板
3. 盖盖板
4. 盖封门
5. 选择左/右/中盖板
6. 调用多个有限状态机 FSM
7. 使用 DM 读码器辅助识别
8. 监控电机状态和电流
9. 向 TaskMgr 反馈任务状态
```

在自动流程中，它位于一级升降和二级升降之间：

```text
一级抬升 -> 取盖板 -> 二级抬升
二级下降 -> 盖盖板 -> 一级下降
```

---

## 一、CoverPlate.h 结构

### 1. 类声明

```cpp
class CoverPlate: public QObject
```

继承 `QObject`，通过 Qt 信号槽与 TaskMgr、MainWindow、监控窗口交互。

---

## 2. 构造函数

```cpp
explicit CoverPlate(ZMotionControl* zm, QObject *parent = nullptr);
```

构造函数接收 `ZMotionControl* zm`，说明盖板机构由正运动控制器控制多个电机/轴。

---

## 3. 标志位

```cpp
CoverPlateSymbol symbol;

bool m_isManualOpen = false;
bool m_isManualClose = false;
bool m_isAutoOpen = false;
bool m_isAutoClose = false;
```

这些变量用于记录盖板机构当前动作状态。

| 变量 | 含义 |
|---|---|
| `m_isManualOpen` | 手动打开/取盖板状态 |
| `m_isManualClose` | 手动关闭/盖盖板状态 |
| `m_isAutoOpen` | 自动打开/取盖板完成标志 |
| `m_isAutoClose` | 自动关闭/盖盖板完成标志 |

`CoverPlateSymbol` 用于向 UI/监控窗口反馈取封门、取盖板、盖盖板、盖封门等阶段完成。

---

## 4. DM 读码器

```cpp
DMDetected* dmcamera;
```

这说明盖板机构中涉及读码器或二维码/DataMatrix 检测。

可能用途：

```text
识别盖板/封门编号
确认目标部件
辅助定位或流程确认
```

---

## 5. 多个状态机 FSM

```cpp
TakeFloorFSM* m_takeFloorFsm;
TakePlateFSM* m_takePlateFsm;
CoverPlateFSM* m_coverPlateFsm;
CoverFloorFSM* m_coverFloorFsm;
```

这是 CoverPlate 最重要的结构。

FSM 是有限状态机。这里四个状态机分别对应：

| 状态机 | 作用 |
|---|---|
| `TakeFloorFSM` | 取封门 |
| `TakePlateFSM` | 取盖板 |
| `CoverPlateFSM` | 盖盖板 |
| `CoverFloorFSM` | 盖封门 |

说明盖板动作不是简单一条电机命令，而是由多个动作阶段组成。

---

## 6. 对 TaskMgr 的入口

```cpp
void ExeCoverPlateTask(TaskInfo info);
```

TaskMgr 调用这个函数执行盖板子系统任务。

预期分发：

```text
TaskType=1 -> CoverPlateTask1()，整体取封门 + 取盖板
TaskType=2 -> CoverPlateTask2()，整体盖盖板 + 盖封门
```

---

## 7. 正向任务函数

```cpp
void TakeSealDoor();
void TakePlate();
void CoverPlateTask1();
```

正向任务大致含义：

```text
取封门
取盖板
```

`CoverPlateTask1()` 很可能是正向自动流程总入口。

---

## 8. 反向任务函数

```cpp
void FixPlate();
void FixSealDoor();
void CoverPlateTask2();
```

反向任务大致含义：

```text
盖盖板
盖封门
```

`CoverPlateTask2()` 很可能是反向自动流程总入口。

---

## 9. 状态机控制函数

```cpp
void DisableAllFSMs();
void STOPAllFSMs();
void stopAllFSMs();
```

这些用于停止或禁用所有状态机，常见于：

```text
急停
错误处理
切换动作
手动接管
```

---

## 10. 盖板选择

```cpp
void ChooseCoverPlate(bool symbol);
void ChooseMiddleCoverPlate(bool symbol);
void ResetChoose();
```

说明系统支持不同盖板位置或类型选择，例如左/右/中盖板。

---

# 二、CoverPlate.cpp 阅读重点

根据头文件结构，读 `CoverPlate.cpp` 时应按下面顺序。

## 1. 构造函数

重点看：

```text
是否绑定 m_TaskStatus.sys = eSubSystem::CoverPlate
创建了哪些 FSM
FSM 状态变化信号如何连接
DM 读码器如何初始化
定时器如何初始化
读取了哪些 ini 参数
```

---

## 2. ExeCoverPlateTask()

这是 TaskMgr 调用入口。

重点看它是否按 TaskType 分发：

```text
TaskType=1 -> 正向取盖板流程
TaskType=2 -> 反向盖盖板流程
```

---

## 3. CoverPlateTask1()

正向总流程。

重点看：

```text
是否先取封门，再取盖板
两个动作之间如何判断完成
用哪个 FSM
如何更新 m_isAutoOpen
```

---

## 4. CoverPlateTask2()

反向总流程。

重点看：

```text
是否先盖盖板，再盖封门
用哪个 FSM
如何更新 m_isAutoClose
```

---

## 5. checkEvents()

头文件注释写着：

```text
间隔 200ms 检查是否触发状态机事件
```

这通常是 CoverPlate 的核心控制循环。

阅读时要看：

```text
检查哪些电机位置/电流/传感器状态
什么时候触发 FSM 下一事件
什么时候判定完成
什么时候报错
```

---

## 6. onFsmStateChanged()

这个函数接收 FSM 状态变化。

用途可能包括：

```text
更新 UI
记录日志
判断某个阶段是否完成
触发下一个状态机
```

---

## 7. getSubSystemState()

和其他子系统类似，用于判断：

```text
Error
Running
Complete
Ready
```

重点看判断依据：

```text
电机 5~11 状态
状态机是否完成
自动开/关标志位
错误信息 m_errorInfo
```

---

## CoverPlate 在自动流程中的位置

正向：

```text
TaskMgr dispatchTask(CoverPlate, 1)
    ↓
CoverPlate::ExeCoverPlateTask(TaskType=1)
    ↓
CoverPlateTask1()
    ↓
取封门 + 取盖板
    ↓
Complete
    ↓
TaskMgr 进入 Lift 正向任务
```

反向：

```text
TaskMgr dispatchTask(CoverPlate, 2)
    ↓
CoverPlate::ExeCoverPlateTask(TaskType=2)
    ↓
CoverPlateTask2()
    ↓
盖盖板 + 盖封门
    ↓
Complete
    ↓
TaskMgr 进入 MainLift 反向任务
```

---

## 这个子系统和其他模块的关系

| 模块 | 关系 |
|---|---|
| `TaskMgr` | 派发正向/反向任务，接收反馈 |
| `ZMotionControl` | 控制盖板相关电机 |
| `DMDetected` | 读码器识别或状态确认 |
| `CoverPlateFSM.h` | 各动作有限状态机定义 |
| `DatabaseManager` | 记录运行数据和错误 |
| `CoverPlateMonitor` | 显示盖板机构状态 |
| `MainWindow` | 提供手动按钮和状态展示 |

---

## 阅读重点

优先看：

```text
CoverPlate 构造函数
ExeCoverPlateTask()
CoverPlateTask1()
CoverPlateTask2()
TakeSealDoor()
TakePlate()
FixPlate()
FixSealDoor()
checkEvents()
onFsmStateChanged()
getSubSystemState()
handleStateTransition()
```

---

## 易误解点

### 1. CoverPlate 不只是“盖板”

它同时管：

```text
封门
盖板
取
盖
选择盖板
读码器
状态机
```

### 2. FSM 是理解这个模块的关键

如果不看 `CoverPlateFSM.h`，直接看 `CoverPlate.cpp` 可能会觉得流程分散。

### 3. 同一时间只允许一个 FSM 运行

头文件里有：

```cpp
iscoverPlateFsmOpen
istakePlateFsmOpen
istakeFloorFsmOpen
iscoverFloorFsmOpen
```

说明代码在防止多个状态机同时动作。

---

## 下一步

读完盖板机构后，进入：

```text
Lift.h / Lift.cpp
```

也就是二级升降、视觉、六自由度平台和力检测最复杂的子系统。