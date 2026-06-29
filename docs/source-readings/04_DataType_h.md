# 04 - DataType.h 源码解读

源码路径：`GuangJiSuo/LRU/DataType.h`

## 文件定位

`DataType.h` 是项目的公共数据类型定义文件。

它本身不执行硬件动作，也不负责 UI，而是定义各模块之间交流时使用的数据结构、枚举和状态转换函数。

可以把它理解为：

```text
项目公共语言表
```

如果不先看懂 `DataType.h`，后面看 `TaskMgr`、`SCVehicle`、`LevelingSystem`、`Lift` 时会很吃力。

---

## 主要结构

这个文件主要分为两个命名空间：

```cpp
namespace nVehicleDataType
namespace nsTaskMgr
```

可以这样理解：

| 命名空间 | 作用 |
|---|---|
| `nVehicleDataType` | AGV 小车、导航、地图、传感器、阻挡原因等数据 |
| `nsTaskMgr` | 自动任务调度系统的数据，包括任务信息、子系统、任务状态 |

---

# 一、nVehicleDataType

这个命名空间主要服务于 `SCVehicle`，也就是 AGV 小车子系统。

---

## 1. BlockReason

```cpp
enum class BlockReason:int
```

表示 AGV 被阻挡或减速的原因。

主要值：

```text
Ultrasonic      超声
Laser           激光
Fallingdown     防跌落传感器
Collision       碰撞传感器
Infrared        红外传感器
Lock            锁车开关
DynamicBlock    动态障碍物
VirtualLaser    虚拟激光
ThreeDCamera    3D 相机
DistanceSensor  距离传感器
DILaser         DI 超声
```

用途：

```text
AGV 推送实时状态时，如果 blocked=true，就可以通过 block_reason 判断为什么被阻挡。
```

---

## 2. TaskStatus

```cpp
enum class TaskStatus:int
```

这是 AGV 自己的任务状态，不是整个上位机 TaskMgr 的状态。

主要值：

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

`SCVehicle` 会解析 AGV 推送 JSON 里的 `task_status`，然后根据它判断小车任务是否正在运行或完成。

例如：

```text
RUNNING -> SCVehicle 向 TaskMgr 反馈 Running
COMPLETED -> SCVehicle 向 TaskMgr 反馈 Complete
```

---

## 3. TcpSvrType

```cpp
enum class TcpSvrType:int
{
    PushSvr,
    NavigateSvr,
    StatusSvr,
    ControlSvr
};
```

用于区分 AGV 的不同 TCP 服务。

| 类型 | 作用 |
|---|---|
| `PushSvr` | 推送服务，接收实时状态 |
| `NavigateSvr` | 导航服务，发送导航/任务链命令 |
| `StatusSvr` | 状态服务，查询控制权等状态 |
| `ControlSvr` | 控制服务，重定位、上传地图等 |

---

## 4. RelocStatus / LoadmapStatus

```cpp
enum class RelocStatus:int
enum class LoadmapStatus:int
```

分别表示：

```text
AGV 重定位状态
地图加载状态
```

这些状态会被转换成中文字符串，用于 UI 显示。

---

## 5. SensorType

```cpp
enum SensorType {
    BATTERY_SENSOR,
    FORCE_SENSOR,
    ANGLE_SENSOR,
    DISTANCE_SENSOR
};
```

表示串口传感器类型。

`MainWindow` 创建传感器时会用：

```cpp
new SerialSensor(SensorType::FORCE_SENSOR);
new SerialSensor(SensorType::ANGLE_SENSOR);
new SerialSensor(SensorType::DISTANCE_SENSOR);
new SerialSensor(SensorType::BATTERY_SENSOR);
```

这说明不同传感器共用 `SerialSensor` 类，但通过 `SensorType` 区分解析逻辑或 UI 显示。

---

## 6. VehErrors

```cpp
struct VehErrors
{
    int code;
    QString date_time;
    QString desc;
    int times;
};
```

表示 AGV 返回的错误或警告。

字段含义：

| 字段 | 含义 |
|---|---|
| `code` | 错误代码 |
| `date_time` | 错误时间 |
| `desc` | 错误描述 |
| `times` | 出现次数 |

`SCVehicle::parseJsonToVehicleSts()` 会从 JSON 中解析 `errors` 和 `warnings`，放入这个结构体。

---

## 7. TasklistStatus

```cpp
struct TasklistStatus
{
    int taskid;
    QString taskListName;
    TaskStatus task_status;
};
```

表示 AGV 当前任务链状态。

注意：它和 TaskMgr 的任务不是同一层。

```text
TasklistStatus：AGV 内部预存任务链状态
TaskMgr：上位机整体自动流程状态
```

---

## 8. PGVInfo

```cpp
struct PGVInfo
```

表示 AGV 二维码/PGV 检测信息。

字段包括：

```text
设备地址
错误代码
是否检测到二维码 ID
绝对 X 坐标是否有效
```

这说明 AGV 可能通过 PGV/二维码进行定位或校准。

---

## 9. VehicleSts

```cpp
struct VehicleSts
```

这是 AGV 实时状态的核心结构体。

它包含很多字段，说明 AGV 状态不是一个简单布尔值，而是一整包信息。

重点字段：

```text
blocked             是否被阻挡
block_reason        阻挡原因
battery_level       电池电量
task_status         当前任务状态
is_stop             底盘是否静止
emergency           急停是否激活
charging            是否充电
errors              错误列表
current_station     当前最近站点
current_map         当前地图
brake               是否抱闸
soft_emc            是否软急停
tasklist_status     任务链状态
slowed              是否减速
slow_reason         减速原因
task_type           导航类型
target_dist         剩余路径距离
finished_path       已经过路径
unfinished_path     未经过路径
pgvs                二维码/PGV 信息
reloc_status        重定位状态
loadmap_status      地图加载状态
target_station      目标站点
locked              手柄是否激活
nickName            控制权所有者名字
```

`SCVehicle` 会持续解析 AGV JSON，并更新这个结构体。

---

# 二、nsTaskMgr

这个命名空间定义自动任务调度系统的数据结构。

---

## 1. TaskInfo

```cpp
struct TaskInfo
{
    int TaskType = 0;
    QString LRU = "无";
    QString TaskListName = "无";
    QString TargetStation = "无";
};
```

这是 TaskMgr 发给子系统的任务信息。

核心字段是：

```text
TaskType
```

当前含义：

```text
0：暂无任务
1：正向任务
2：反向任务
```

正向/反向根据子系统不同有不同语义：

| 子系统 | TaskType=1 | TaskType=2 |
|---|---|---|
| Vehicle | AGV 去目标点 | AGV 回原点 |
| Levelling | 车身调平/脚座触地 | 车身触地/恢复 |
| MainLift | 一级抬升 | 一级下降 |
| CoverPlate | 取封门/取盖板 | 盖盖板/盖封门 |
| Lift | 二级抬升 | 二级下降 |

`LRU`、`TaskListName`、`TargetStation` 用于记录当前 LRU 类型、AGV 任务链名和目标站点。

---

## 2. eTaskstate

```cpp
enum class eTaskstate:int
{
    Init,
    Ready,
    Running,
    Complete,
    Error
};
```

这是所有子系统向 TaskMgr 反馈时使用的统一任务状态。

可以理解为：

```text
子系统执行状态标准格式
```

含义：

| 状态 | 含义 |
|---|---|
| `Init` | 初始化 |
| `Ready` | 准备好/空闲 |
| `Running` | 正在执行 |
| `Complete` | 完成 |
| `Error` | 出错 |

---

## 3. eSubSystem

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

这是参与自动调度的子系统枚举。

当前包括：

```text
AGV 小车
调平系统
一级升降
盖板机构
二级升降
```

注意：`Pin` 当前没有列进 `eSubSystem`。这说明销子系统可能尚未完整纳入主自动流程，或者后续设计有变。

---

## 4. eTaskStatus

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

这是自动任务系统最重要的状态包。

子系统每次反馈时，都会告诉 TaskMgr：

```text
我是哪个子系统：sys
我执行的任务信息：taskinfo
我现在状态：state
耗时多久：duration
附加信息/错误信息：info
```

例如：

```text
sys = Vehicle
TaskType = 1
state = Complete
duration = 12.5
info = 无
```

表示 AGV 正向任务完成，耗时 12.5 秒。

---

## 5. LevelSymbol

```cpp
enum class LevelSymbol
```

调平标志位，用于 UI 或监控窗口更新。

包括：

```text
FeetToGround0
FeetToGround1
FeetToGround2
FeetToGround3
Balance
Restart
```

这表示四个脚座触地、调平完成、重启/恢复等状态。

---

## 6. CoverPlateSymbol

```cpp
enum class CoverPlateSymbol
```

盖板机构标志位：

```text
TakeDoorComplete   取封门完成
TakePlateComplete  取盖板完成
CoverPlateComplete 盖盖板完成
CoverDoorComplete  盖封门完成
```

`CoverPlate` 子系统会通过信号把这些状态发给主窗口或监控窗口。

---

## 7. SixDofPlatformData

```cpp
struct SixDofPlatformData
```

六自由度平台状态数据。

字段包括：

```text
x/y/z
rx/ry/rz
motion_mode
servo_enabled
target_reached
alarmText
hasClientConnected
```

用于描述六自由度平台当前位置、姿态、伺服状态、是否到位、是否报警等。

---

## 8. DetectedDisplayData

```cpp
struct DetectedDisplayData
{
    float angle;
    float rho1;
    float rho2;
};
```

这是视觉检测显示数据。

`main.cpp` 中注册了这个类型：

```cpp
qRegisterMetaType<nsTaskMgr::DetectedDisplayData>("nsTaskMgr::DetectedDisplayData");
```

说明它会通过 Qt 信号槽传递，可能跨线程传给 UI。

---

## 9. SixForeData

```cpp
struct SixForeData
{
    float Fx;
    float Fy;
    float Fz;
    float Mx;
    float My;
    float Mz;
};
```

这里名字可能想表达 `SixForceData`，但源码中写的是 `SixForeData`。

它表示六维力传感器数据：

```text
Fx/Fy/Fz：三个方向力
Mx/My/Mz：三个方向力矩
```

`Lift` 会使用这类数据进行碰撞检测、脱离检测等。

---

## 10. Q_DECLARE_METATYPE

```cpp
Q_DECLARE_METATYPE(nsTaskMgr::DetectedDisplayData)
```

这行告诉 Qt 元对象系统：`DetectedDisplayData` 是一个可以注册和传递的类型。

配合 `main.cpp` 的 `qRegisterMetaType` 使用。

---

## 阅读重点

优先理解这些：

```text
TaskInfo
eTaskstate
eSubSystem
eTaskStatus
VehicleSts
DetectedDisplayData
SixForeData
```

这些是后面看调度、AGV、二级升降、视觉数据传递的基础。

---

## 易误解点

### 1. AGV 的 TaskStatus 和 TaskMgr 的 eTaskstate 不是一个东西

```text
TaskStatus：AGV 自己反馈的导航任务状态
 eTaskstate：上位机对子系统任务的统一状态
```

`SCVehicle` 会把 AGV 的 `TaskStatus::COMPLETED` 转换成上位机的 `eTaskstate::Complete`。

### 2. TaskType 是简单数字，但语义依赖子系统

`TaskType=1` 不一定永远是“上升”。对不同子系统含义不同。

### 3. Pin 没有进入 eSubSystem

虽然项目有 `Pin` 类和 `sigExecPinTask`，但 `eSubSystem` 当前没列出 Pin，这一点后续读 Pin 时要注意。

---

## 下一步

读完 `DataType.h` 后，进入：

```text
TaskMgr.h
TaskMgr.cpp
```

因为 `TaskMgr` 正是用 `TaskInfo` 和 `eTaskStatus` 串起整个自动流程。