# 07 - SCVehicle.h / SCVehicle.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/SCVehicle.h
GuangJiSuo/LRU/SCVehicle.cpp
```

## 文件定位

`SCVehicle` 是 AGV 小车子系统。

它负责：

```text
1. 建立 AGV 的多路 TCP 连接
2. 发送导航、控制、状态查询命令
3. 接收 AGV 推送的 JSON 状态
4. 解析 AGV 实时状态 VehicleSts
5. 根据 AGV 状态判断任务 Running / Complete / Ready
6. 向 TaskMgr 反馈 eTaskStatus
```

可以把它理解为：

```text
AGV 通讯适配层 + AGV 子系统任务执行器
```

---

## 一、SCVehicle.h 结构

### 1. 类声明

```cpp
class SCVehicle: public QObject
```

继承 `QObject`，说明它使用 Qt 信号槽。

它会接收 TaskMgr 的任务信号，也会把任务状态反馈给 TaskMgr。

---

## 2. 四类 TCP 连接

头文件中有四组连接函数：

```cpp
connectPushHost()
connectNavigateHost()
connectStatusHost()
connectControlHost()
```

对应四个 TCP 对象：

```cpp
SCStatusTcp *m_robot_push;
SCStatusTcp *m_robot_navigate;
SCStatusTcp *m_robot_status;
SCStatusTcp *m_robot_control;
```

可以这样理解：

| TCP 对象 | 作用 |
|---|---|
| `m_robot_push` | 接收 AGV 主动推送的实时状态 |
| `m_robot_navigate` | 发送导航任务链命令 |
| `m_robot_status` | 查询状态，例如控制权所有者、PGV 数据 |
| `m_robot_control` | 控制 API，例如上传地图、重定位 |

这说明 AGV 通信不是一个 socket 解决全部问题，而是按 API 类型分多路连接。

---

## 3. 对外控制能力

头文件里有这些函数：

```cpp
uploadMapToRobot(...)
relocateRobot(...)
pauseCurrentNavigation()
resumeCurrentNavigation()
cancelCurrentNavigation()
queryControlOwner()
translateRobot(...)
rotateRobot(...)
```

说明 AGV 模块支持：

```text
上传地图
重定位
暂停导航
继续导航
取消导航
查询控制权
平移
旋转
```

---

## 4. TaskMgr 接口

```cpp
void ExeVehTask(TaskInfo info);
```

这是 TaskMgr 发任务时调用的槽函数。

MainWindow 中会连接：

```cpp
TaskMgr::sigExeVehTask -> SCVehicle::ExeVehTask
```

也就是说：

```text
TaskMgr 派发 Vehicle 任务
    ↓
SCVehicle::ExeVehTask(TaskInfo)
```

---

## 5. 反馈信号

```cpp
void sigStatusFeedback(eTaskStatus);
```

这是 SCVehicle 向 TaskMgr 反馈任务状态的信号。

当 AGV 状态变成 Running / Complete / Ready 时，会通过这个信号发回调度器。

---

# 二、SCVehicle.cpp 重点

## 1. 构造函数

构造函数中创建了四个 `SCStatusTcp` 对象：

```cpp
m_robot_push = new SCStatusTcp(this);
m_robot_navigate = new SCStatusTcp(this);
m_robot_status = new SCStatusTcp(this);
m_robot_control = new SCStatusTcp(this);
```

然后把自身绑定为 Vehicle 子系统：

```cpp
m_TaskStatus.sys = eSubSystem::Vehicle;
```

这行很关键。后续发给 TaskMgr 的 `eTaskStatus` 会带上：

```text
我是 Vehicle 子系统
```

---

## 2. TCP 信号连接

构造函数中把 `SCStatusTcp` 的信号连接到对应槽函数。

以 PushHost 为例：

```cpp
connect(m_robot_push, &SCStatusTcp::sigJsonData,
        this, &SCVehicle::RecvPushHostJsonData);
```

含义：

```text
AGV 推送 TCP 收到 JSON
    ↓
SCStatusTcp 解析出 JSON 字符串
    ↓
发 sigJsonData
    ↓
SCVehicle::RecvPushHostJsonData 处理
```

所以 AGV 的实时状态入口是：

```cpp
RecvPushHostJsonData(QString jsonData)
```

---

## 3. 定时查询控制权

```cpp
GetHandleInfo = new QTimer(this);
connect(GetHandleInfo, &QTimer::timeout, this, [=](){
    if(isConnectedStatusHost()){
        queryControlOwner();
    }
});
GetHandleInfo->start(200);
```

含义：

```text
每 200ms 如果状态服务器已连接，就查询控制权所有者
```

控制权可能和 AGV 手柄/远程控制有关。

---

## 4. ExeVehTask()

```cpp
void SCVehicle::ExeVehTask(TaskInfo info)
```

这是 TaskMgr 发给 AGV 的任务执行入口。

核心逻辑：

```cpp
m_TaskStatus.taskinfo.TaskType = info.TaskType;
```

先把任务类型保存到 `m_TaskStatus`，后续反馈给 TaskMgr 时会带上这个信息。

然后判断正向/反向：

```cpp
if(info.TaskType == 1)
{
    sendControlCommandToVehicle(m_TaskStatus.taskinfo.TaskListName);
}
else if(info.TaskType == 2)
{
    sendControlCommandToVehicle("task_0");
}
```

理解：

```text
TaskType=1：执行当前任务链名
TaskType=2：执行 task_0，可能表示返回原点任务链
```

注意：这里正向任务使用的是 `m_TaskStatus.taskinfo.TaskListName`，而不是 `info.TaskListName`。如果外部传入的 `TaskInfo` 没有同步到 `m_TaskStatus.taskinfo` 的其他字段，可能会导致任务链名为空或默认值。这个点后续值得核查。

---

## 5. RecvPushHostJsonData()

这是 AGV 实时状态处理核心。

流程：

```text
收到 AGV JSON
    ↓
parseJsonToVehicleSts(jsonData, veh_sts)
    ↓
读取 veh_sts.task_status
    ↓
根据 AGV 状态转换成 eTaskstate
    ↓
emit sigStatusFeedback(m_TaskStatus)
```

### AGV 正在运行

```cpp
if(current_status == TaskStatus::RUNNING)
{
    m_TaskStatus.state = eTaskstate::Running;
    emit sigStatusFeedback(m_TaskStatus);
}
```

表示 AGV 任务开始运行，上报 Running。

### AGV 从 Running 切到 Completed

```cpp
if(m_last_veh_status.task_status == TaskStatus::RUNNING &&
   current_status == TaskStatus::COMPLETED)
{
    m_TaskStatus.state = eTaskstate::Complete;
    emit sigStatusFeedback(m_TaskStatus);
}
```

这是 AGV 任务完成判定。

注意：它要求“上一状态是 RUNNING，当前状态是 COMPLETED”。这样可以避免一上来就读到 COMPLETED 而误判任务完成。

### AGV 无任务

```cpp
if(current_status == TaskStatus::NONE)
{
    m_TaskStatus.state = eTaskstate::Ready;
    emit sigStatusFeedback(m_TaskStatus);
}
```

表示小车当前空闲或无导航任务。

---

## 6. parseJsonToVehicleSts()

```cpp
bool SCVehicle::parseJsonToVehicleSts(const QString& jsonString, VehicleSts& vehSts)
```

这个函数把 AGV 推送 JSON 转成 `VehicleSts` 结构体。

解析内容包括：

```text
blocked
battery_level
block_reason
task_status
reloc_status
loadmap_status
is_stop
emergency
target_station
errors / warnings
charging
current_station
current_map
brake
soft_emc
tasklist_status
pgvs
finished_path
unfinished_path
```

这部分代码是 AGV 状态数据进入上位机的入口。

---

## 7. sendControlCommandToVehicle()

```cpp
void SCVehicle::sendControlCommandToVehicle(const QString &TaskListName)
```

这个函数向 AGV 发送“执行预存任务链”的命令。

它构造 JSON：

```json
{"name":"任务链名称"}
```

然后调用：

```cpp
SendData2NavigateHost(0x0C22, jsonData, "", number, 0)
```

所以 `0x0C22` 很可能是 AGV 导航 API 中“执行任务链”的命令号。

---

## 8. RecvStatusJsonData()

这个函数处理状态服务器返回的数据。

其中包括 PGV 数据：

```cpp
double tagDiffAngleRaw = pgvObj["tag_diff_angle"].toDouble();
double tagDiffX = pgvObj["tag_diff_x"].toDouble();
double tagDiffY = pgvObj["tag_diff_y"].toDouble();
```

然后发信号：

```cpp
emit sigPGVDataUpdated(tagDiffAngle, tagDiffX, tagDiffY);
```

说明 AGV 的二维码/PGV 数据会更新 UI 或用于位置校正。

---

## 9. AGV 地图和重定位

源码中还实现了：

```cpp
uploadMapToRobot(...)
relocateRobot(...)
```

`uploadMapToRobot` 会读取 `.smap` 地图文件，并通过 ControlHost 发送。

`relocateRobot` 会构造重定位 JSON，包括：

```text
isAuto
x
y
angle
length
home
```

这说明上位机不仅执行预设任务链，也能对 AGV 进行地图加载和重定位控制。

---

## SCVehicle 在自动流程中的位置

```text
TaskMgr::processStep()
    ↓
dispatchTask(Vehicle, 1 或 2)
    ↓
emit sigExeVehTask(TaskInfo)
    ↓
SCVehicle::ExeVehTask(TaskInfo)
    ↓
AGV 执行任务链
    ↓
AGV PushHost 推送 JSON 状态
    ↓
SCVehicle::RecvPushHostJsonData
    ↓
AGV 状态 RUNNING / COMPLETED 转换为 eTaskstate
    ↓
emit sigStatusFeedback(eTaskStatus)
    ↓
TaskMgr::slotSubSysStateChanged
```

---

## 阅读重点

优先看：

```text
SCVehicle::SCVehicle()
ExeVehTask(TaskInfo info)
RecvPushHostJsonData(QString jsonData)
parseJsonToVehicleSts(...)
sendControlCommandToVehicle(...)
RecvStatusJsonData(...)
```

---

## 易误解点

### 1. SCVehicle 不直接控制电机

它控制的是 AGV 通讯和导航命令，不是本机 ZMotion 运动轴。

### 2. PushHost 是状态入口，NavigateHost 是命令出口

不要混淆：

```text
NavigateHost：发任务链命令
PushHost：收实时状态，判断任务完成
```

### 3. TaskType=2 被硬编码为 task_0

反向任务当前写死执行 `task_0`。需要结合 AGV 任务链配置确认 `task_0` 是否就是返回原点。

### 4. block_reason 的 Error 处理目前被注释

代码里检测到 blocked 时，错误反馈部分被注释了。这意味着 AGV 被阻挡当前可能不会直接让 TaskMgr 进入 Error，需要后续确认是否有其他安全逻辑处理。

---

## 下一步

读完 AGV 子系统后，进入：

```text
LevelingSystem.h / LevelingSystem.cpp
```

也就是自动流程的第二步：车身调平。