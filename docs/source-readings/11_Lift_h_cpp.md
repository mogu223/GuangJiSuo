# 11 - Lift.h / Lift.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/Lift.h
GuangJiSuo/LRU/Lift.cpp
```

## 文件定位

`Lift` 是二级升降子系统，但它不是单纯“升降电机”类。

它同时集成了：

```text
1. 二级升降运动控制
2. 大恒工业相机
3. ArUco 视觉检测
4. 光源控制
5. 六自由度平台 UDP 通信
6. 六维力传感器数据
7. 碰撞检测
8. 脱离检测
9. LRU 参数接收与补偿
10. 自动抬升 / 自动下降
11. 向 TaskMgr 反馈任务状态
```

可以把它理解为：

```text
二级精定位与装配核心子系统
```

这是项目中最复杂的执行子系统之一。

---

## 一、Lift.h 结构

### 1. 类声明

```cpp
class Lift: public QObject
```

继承 `QObject`，通过信号槽和 MainWindow、TaskMgr、视觉模块、六自由度平台交互。

---

## 2. 构造函数

```cpp
explicit Lift(ZMotionControl* zm,
              dahengTwoCams_qt_vs *dahengCamera,
              LightSourceController* lightcontrol,
              QObject *parent = nullptr);
```

构造函数接收三个关键依赖：

| 参数 | 作用 |
|---|---|
| `ZMotionControl* zm` | 二级升降运动控制 |
| `dahengTwoCams_qt_vs* dahengCamera` | 大恒相机图像采集 |
| `LightSourceController* lightcontrol` | 光源亮度控制 |

这说明 `Lift` 是运动 + 视觉 + 光源的组合模块。

---

## 3. 六维力传感器数据

```cpp
float Check_ForceInfo[6] = {0.0f};
float LastCheck_ForceInfo[6] = {0.0f};
bool  isforceOver = false;
bool  istorqueOver = false;
float Threshold[6] = {100.0f};
```

这部分用于碰撞或力矩超限检测。

六个维度对应：

```text
Fx / Fy / Fz / Mx / My / Mz
```

`Threshold[6]` 是力/力矩阈值。

---

## 4. 视觉和六自由度平台对象

```cpp
UdpCommunication* m_SixDof;
LightSourceController *m_lightcontroller;
ArucoDetector *m_vision_detected;
dahengTwoCams_qt_vs *m_dahengCamera;
```

含义：

| 成员 | 作用 |
|---|---|
| `m_SixDof` | 六自由度平台 UDP 通信 |
| `m_lightcontroller` | 光源控制 |
| `m_vision_detected` | ArUco 视觉检测 |
| `m_dahengCamera` | 大恒相机采图 |

这说明 `Lift` 通过视觉识别和平台动作实现精定位。

---

## 5. 自动动作标志

```cpp
bool autolift = false;
bool autodescent = false;
bool detected_flag = false;

bool m_isHalfAutoLiftUp = false;
bool m_isAutoLiftDown = false;
bool m_isManualLiftUp = false;
bool m_isManualLiftDown = false;
```

含义：

```text
autolift：正在/完成自动抬升逻辑
autodescent：正在/完成自动下降逻辑
detected_flag：视觉检测结果标志
m_isHalfAutoLiftUp：半自动上升完成标志
m_isAutoLiftDown：自动下降完成标志
m_isManualLiftUp / Down：手动模式标志
```

这些变量会参与任务完成判断。

---

## 6. TaskMgr 入口

```cpp
void ExeLiftTask(TaskInfo info);
```

TaskMgr 派发二级升降任务时调用。

预期分发：

```text
TaskType=1 -> ExeLiftTask1()，二级抬升
TaskType=2 -> ExeLiftTask2()，二级下降
```

---

## 7. 视觉相关函数

```cpp
bool StatusModifyLatte();
bool auto_StatusModifyLatte();
bool vision_detected();
bool auto_vision_detected();
bool auto_lift();
void stop_auto_lift();
void waitSixDof();
bool auto_descent();
```

这些是 Lift 的复杂部分。

大致可以理解为：

```text
检查六自由度平台状态
执行视觉识别
根据识别结果修正位置
自动抬升
等待平台到位
自动下降
```

具体细节需要结合 `Lift.cpp` 逐函数看。

---

## 8. LRU 参数接收

```cpp
void onParamsReceived(const LRUInnerParams &params);
```

MainWindow 中选择 LRU 类型后，会把参数发给 Lift。

这些参数可能包括：

```text
目标 gap
最终 z
相机到 LRU 的偏移
ArUco 到 gap 的偏移
marker_id
曝光值
角度补偿
```

这说明 Lift 的运动和视觉补偿不是固定的，而是随 LRU 类型变化。

---

## 9. 碰撞检测和脱离检测

```cpp
void SetForceData(SixForeData* data);
void CheckCollision();
void CheckDetach();
```

`SetForceData` 接收六维力传感器数据。

`CheckCollision` 判断是否碰撞或力/力矩超限。

`CheckDetach` 判断 LRU 是否成功挂上或是否脱离。

---

## 10. 反馈信号

```cpp
void sigStatusFeedback(eTaskStatus);
void LiftUpdateUI(QString str);
void lift_updateGapInfo(nsTaskMgr::DetectedDisplayData vision_data);
void isCollision(bool symbol, QString Info);
void isDetach(bool symbol);
void sendBrightnessValueToMainWindow(const int &value);
void sigAutoLiftFinalSixDofCoordinates(float x, float y);
```

这些信号分别用于：

```text
反馈任务状态给 TaskMgr
更新主界面日志
更新视觉间隙信息
通知碰撞状态
通知挂接/脱离状态
调整光源亮度
反馈最终六自由度平台坐标
```

---

# 二、Lift.cpp 阅读重点

读 `Lift.cpp` 时建议分四条线看。

---

## 线索一：TaskMgr 任务线

重点函数：

```text
ExeLiftTask(TaskInfo info)
ExeLiftTask1()
ExeLiftTask2()
getSubSystemState()
handleStateTransition()
monitorSubsystemStatus()
```

目标：看 Lift 如何接收 TaskMgr 的任务，又如何反馈 Complete / Error。

---

## 线索二：视觉定位线

重点函数：

```text
vision_detected()
auto_vision_detected()
onParamsReceived(...)
lift_updateGapInfo(...)
```

目标：看大恒相机图像如何进入 ArUcoDetector，识别结果如何转换成 gap、角度、偏移。

---

## 线索三：六自由度平台线

重点函数：

```text
StatusModifyLatte()
auto_StatusModifyLatte()
waitSixDof()
sigAutoLiftFinalSixDofCoordinates
```

目标：看二级升降是否通过六自由度平台做位姿修正。

---

## 线索四：安全检测线

重点函数：

```text
SetForceData(...)
CheckCollision()
CheckDetach()
setcollisionState(...)
```

目标：看六维力数据如何触发碰撞、脱离判断和急停。

---

## Lift 在自动流程中的位置

正向流程：

```text
TaskMgr dispatchTask(Lift, 1)
    ↓
Lift::ExeLiftTask(TaskType=1)
    ↓
视觉识别 / 平台修正 / 二级抬升
    ↓
Complete
    ↓
TaskMgr 进入 Lift 反向任务
```

反向流程：

```text
TaskMgr dispatchTask(Lift, 2)
    ↓
Lift::ExeLiftTask(TaskType=2)
    ↓
二级下降 / 脱离或挂接检测
    ↓
Complete
    ↓
TaskMgr 进入 CoverPlate 反向任务
```

---

## 与其他模块的关系

| 模块 | 关系 |
|---|---|
| `TaskMgr` | 派发二级升降正/反向任务，接收反馈 |
| `ZMotionControl` | 控制二级升降运动轴 |
| `dahengTwoCams_qt_vs` | 提供大恒相机图像 |
| `ArucoDetector` | 检测 ArUco marker，计算位置/角度 |
| `LightSourceController` | 控制视觉光源亮度 |
| `UdpCommunication` | 和六自由度平台通信 |
| `MainWindow` | 转发六维力数据，显示 UI，选择 LRU 参数 |
| `LRUdatadef.h` | 提供不同 LRU 的预设参数 |

---

## 阅读重点

优先看：

```text
Lift 构造函数
ExeLiftTask()
ExeLiftTask1()
ExeLiftTask2()
onParamsReceived(...)
vision_detected()
auto_lift()
auto_descent()
SetForceData(...)
CheckCollision()
CheckDetach()
getSubSystemState()
handleStateTransition()
```

---

## 易误解点

### 1. Lift 不是 MainLift

`MainLift` 是一级升降。

`Lift` 是二级升降，并且还包含视觉、力控、六自由度平台逻辑。

### 2. Lift 是最复杂子系统

读它不要一开始就陷入每个视觉计算细节。先抓住：

```text
TaskMgr 如何调用它
它如何完成正/反向任务
视觉结果如何影响运动
力传感器如何影响安全判断
```

### 3. LRU 参数会影响 Lift 行为

不同 LRU 类型对应不同偏移和目标参数，所以看 Lift 时要结合 `LRUdatadef.h`。

---

## 下一步

读完 Lift 后，进入：

```text
Pin.h / Pin.cpp
```

也就是销子子系统。