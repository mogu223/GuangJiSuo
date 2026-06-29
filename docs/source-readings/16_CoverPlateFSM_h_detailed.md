# 16 - CoverPlateFSM.h 详细源码解读

源码路径：`GuangJiSuo/LRU/CoverPlateFSM.h`

## 0. 先说明：为什么不是 CoverPlateFSM.cpp

仓库中没有发现 `CoverPlateFSM.cpp`。

实际状态机代码在：

```text
GuangJiSuo/LRU/CoverPlateFSM.h
```

这是合理的，因为该文件使用了 Boost MSM 模板状态机：

```cpp
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>
```

模板类和大量状态定义通常需要放在头文件里，否则编译器在实例化模板时看不到完整实现。

所以这里解读的是：

```text
CoverPlateFSM.h = CoverPlateFSM 的实际实现文件
```

---

## 1. 文件定位

`CoverPlateFSM.h` 是盖板/封门机构的状态机定义文件。

它定义了：

```text
1. 全局盖板/电机位置缓存 GlobalMotorPos
2. 状态机事件 Event
3. 状态机守卫条件 Guard
4. 公共动作状态 State
5. 取盖板专属状态
6. 盖封门专属状态
7. BaseFSM 基类
8. 四个具体状态机前端
9. FSMBackend 后端封装
10. 四个状态机 typedef
```

可以把它理解成：

```text
盖板机构动作流程说明书 + 状态机代码实现
```

---

## 2. 使用的核心技术：Boost MSM

这个文件使用 Boost MSM 构造有限状态机。

状态机的基本概念是：

```text
当前状态 + 事件 -> 下一个状态
```

例如：

```text
下降至39 + LoweringDone -> 正向横移至1132
```

在代码中写成：

```cpp
boost::msm::front::Row<Lowering, LoweringDone, ForwardTransverseMovement>
```

含义：

```text
当前状态 Lowering
收到事件 LoweringDone
切换到 ForwardTransverseMovement
```

---

## 3. GlobalMotorPos 命名空间

```cpp
namespace GlobalMotorPos {
    static float coverPlatePos[4] = {0.0f};
    static float borrowPos[2] = {0.0f};
    static float FingerPos[2] = {0.0f};
    static bool leftSymbol = false;
    static bool rightSymbol = false;
    static bool center_rSymbol = false;
    static bool center_lSymbol = false;
    static float DMVal[3] = {0.0f};
}
```

这个命名空间保存盖板流程中跨状态共享的临时数据。

主要内容：

| 变量 | 作用 |
|---|---|
| `coverPlatePos[4]` | 保存电机 5/6/7/8 的盖板位置 |
| `borrowPos[2]` | 保存纵移借位前的位置 |
| `FingerPos[2]` | 保存手指电机位置 |
| `leftSymbol/rightSymbol` | 选择左/右盖板 |
| `center_rSymbol/center_lSymbol` | 选择中间盖板相关标志 |
| `DMVal[3]` | 保存 DM 读码值 |

这些变量由 `CoverPlate.cpp`、状态机状态和守卫条件共同使用。

---

## 4. 盖板机构运动映射注释

源码注释写明：

```cpp
//托举电机: Forward-下降
//横移电机: 均设置Forward-靠近电机端
//手指电机: 均设置Forward-两手指远离
//纵移电机: 均设置Forward-靠近电机端
```

这几行非常重要，因为同样是 Forward，不同机械轴的实际空间意义不同。

简单理解：

```text
轴 11：托举/升降
轴 7/8：横移
轴 9/10：手指/夹爪
轴 5/6：纵移
```

后续状态里的 `moveMotorAbs`、`moveMotorOpp` 都要结合这个运动映射理解。

---

## 5. 事件定义

事件都是空结构体，例如：

```cpp
struct AngleAdjustDone{};
struct XAdjustDone{};
struct LiftingDone {};
struct LoweringDone {};
struct FingerReleasingDone {};
struct FingerClampingDone {};
struct ForwardTransverseMovementDone {};
```

这些事件本身不携带数据，只表示“某个动作完成”。

事件一般由 `CoverPlate.cpp::checkEvents()` 触发。

例如：

```text
检测到轴 11 到达 55
    -> process_event(LoweringDone_55())
```

或者：

```text
DM 角度满足阈值
    -> process_event(AngleAdjustDone())
```

所以：

```text
CoverPlateFSM.h 定义事件
CoverPlate.cpp 判断事件何时发生
```

---

## 6. 守卫条件 Guard

守卫条件用于决定某条状态转移是否允许发生。

例如：

```cpp
struct GuardLeftCoverPlate {
    bool operator()(...) const {
        return GlobalMotorPos::leftSymbol;
    }
};
```

含义：

```text
只有选择了左侧盖板，这条状态转移才允许执行。
```

目前定义了：

```text
GuardLeftCoverPlate
GuardRightCoverPlate
GuardCenter_lCoverPlate
```

这些用于处理左/右/中间盖板的不同借位动作。

---

## 7. 公共状态定义

状态是具体动作。每个状态一般继承：

```cpp
boost::msm::front::state<>
```

并实现：

```cpp
template <class Event,class FSM>
void on_entry(Event const&, FSM& fsm)
```

`on_entry` 表示进入该状态时执行的动作。

### 7.1 Lowering：下降至39

```cpp
fsm.moveMotorAbs(11, 39);
```

进入该状态时，轴 11 下降到 39。

注释说是“防止封门压线”。

### 7.2 Lifting：抬升至12

```cpp
fsm.moveMotorAbs(11, 12);
```

进入该状态时，轴 11 抬升到 12。

注释说是“封门没过梢钉”。

### 7.3 ForwardTransverseMovement：正向横移至1132

```cpp
fsm.moveMotorAbs(7, 1132);
fsm.moveMotorAbs(8, 1132);
```

轴 7、8 横移到 1132。

### 7.4 ReverseTransverseMovement：反向横移至0

```cpp
fsm.moveMotorAbs(7, 0);
fsm.moveMotorAbs(8, 0);
```

横移机构回零。

### 7.5 ReverseLongitudinalMovement：持续纵移

```cpp
fsm.moveSingleV(5);
fsm.moveSingleV(6);
QVector<float> currentVal = fsm.getDmValues();
GlobalMotorPos::setDmValues(...);
```

这不是绝对位置移动，而是持续运动，同时记录当前 DM 值。

后续 `CoverPlate.cpp::checkEvents()` 会检测 DM 值是否变化，然后触发 `ReverseLongitudinalMovementDone`。

---

## 8. 手指相关状态

### 8.1 FingerReleasing：手指松开至10

```cpp
fsm.moveMotorAbs(9, 10);
fsm.moveMotorAbs(10, 10);
```

轴 9、10 移到 10，表示手指松开。

### 8.2 FingerClamping：手指夹紧至11.5

```cpp
fsm.moveMotorAbs(9, 11.5);
fsm.moveMotorAbs(10, 11.5);
```

用于夹紧封门流程。

### 8.3 FingerClampingDur：手指持续夹紧

```cpp
fsm.moveSingleV(9);
fsm.moveSingleV(10);
```

让手指持续运动。

`CoverPlate.cpp::checkEvents()` 会检测手指电流，超过阈值后停止，并触发 `FingerClampingDurDone`。

### 8.4 FingerClampingOpp：手指相对夹紧

```cpp
float pos9 = fsm.getMotorPosition(9);
float pos10 = fsm.getMotorPosition(10);
GlobalMotorPos::setFingerPosBatch(pos9, pos10);
fsm.moveMotorOpp(9, -12);
fsm.moveMotorOpp(10, -12);
```

先记录当前手指位置，再相对移动 -12。

这用于基于当前位置进行夹取。

---

## 9. 封门横移状态

### 9.1 MoveForAntiHanging：取封门横移至1132

```cpp
fsm.moveMotorAbs(7, 1132);
fsm.moveMotorAbs(8, 1132);
```

用于摘取/防挂动作。

### 9.2 MoveForHanging：挂封门横移至1157

```cpp
fsm.moveMotorAbs(7, 1157);
fsm.moveMotorAbs(8, 1157);
```

用于悬挂封门。

---

## 10. DM 读码调整状态

这些状态用于根据 DM 读码结果进行姿态调整。

### 10.1 AngleAdjust：角度调整

```cpp
float relativeAngle = (currentVals1[2] / 10 - 90) * pi / 180;
float distance = 980.0f * tan(relativeAngle);
fsm.moveMotorOpp(5, -distance);
```

含义：

```text
从 DM 读码结果取角度
目标角度是 90°
根据偏角计算一侧纵移补偿距离
移动电机 5 修正角度
```

这里 980.0f 表示两个纵移丝杆之间距离。

### 10.2 XAdjust / XAdjustAdvance

```cpp
float relativeX = currentVals2[1] / 10;
fsm.moveMotorOpp(5, relativeX);
fsm.moveMotorOpp(6, relativeX);
```

根据 DM 的 X 值调整轴 5、6。

### 10.3 YAdjust / YAdjustAdvance

```cpp
float relativeY = currentVals3[0] / 10 - 4;
fsm.moveMotorOpp(7, relativeY);
fsm.moveMotorOpp(8, relativeY);
```

根据 DM 的 Y 值调整轴 7、8。

---

## 11. 机构恢复状态

### 11.1 MyRecover：横、纵移机构初始

```cpp
fsm.moveMotorAbs(5, 81);
fsm.moveMotorAbs(6, 47);
fsm.moveMotorAbs(7, 0);
fsm.moveMotorAbs(8, 0);
```

用于盖封门前恢复机构初始姿态。

### 11.2 MyPlateRecover1：横移姿态恢复

从 `param.ini` 读取之前保存的 Pos7、Pos8，然后移动轴 7、8。

### 11.3 MyPlateRecover2：纵移姿态恢复

从 `param.ini` 读取之前保存的 Pos5、Pos6，然后移动轴 5、6。

这与取盖板时保存姿态有关：

```text
取盖板时记录位置
盖盖板时恢复位置
```

---

## 12. 完成状态

定义了四个完成状态：

```text
TakeFloorCompleted
TakePlateCompleted
CoverPlateCompleted
CoverFloorCompleted
```

它们进入时只做一件事：

```cpp
emit fsm.sigStateChanged(name());
```

外层 `CoverPlate.cpp::onFsmStateChanged()` 会监听这些名字，并决定是否设置自动完成标志。

当前外层会对以下两个设置 TaskMgr 完成标志：

```text
TakePlateCompleted -> m_isAutoOpen = true
CoverPlateCompleted -> m_isAutoClose = true
```

---

## 13. MyPlate 命名空间

`MyPlate` 里定义取/盖盖板专属状态。

典型状态包括：

```text
Lowering1：取盖板下降至55
Lowering2：取盖板下降至23
MoveTo_55：取盖高度至55
Lifting1：取盖板上升至0
FingerNear1：手指靠拢至-25
FingerNear2：手指靠拢至-50
ReverseTransverseMovement：反向横移至100
LongitudinalMoveto50：纵移至50
LongitudinalMovement：纵移至0
MyPlateRecover1：横移姿态恢复
MyPlateRecover2：纵移姿态恢复
ForwardLongitudinalForBorrow：正向相对纵移324
ForwardLongitudinalForCenterBorrow：正向相对纵移320
ReverseLongitudinalForBorrow：反向相对纵移-324
```

这说明取盖板过程很复杂，包含：

```text
下降
横移
纵移
手指靠拢
DM 识别和调整
借位补偿
抬升
夹紧
复位
```

---

## 14. MyCoverFloor 命名空间

这里定义盖封门专属状态：

```text
Lowering1：盖封门下降至15
Lifting1：盖封门上升至11
```

用于 `CoverFloorFSMFront`。

---

## 15. BaseFSM_QObject

```cpp
class BaseFSM_QObject : public QObject
```

这个类把 Qt 信号能力单独抽出来。

它定义信号：

```cpp
void sigStateChanged(const QString& stateName);
```

并保存：

```cpp
ZMotionControl* m_zm;
DMDetected* m_dm;
```

Boost MSM 自身不是 Qt QObject，所以这里用一个 QObject 基类把 Qt 信号能力接进去。

---

## 16. BaseFSM 模板类

```cpp
template <class Derived>
class BaseFSM : public BaseFSM_QObject,
                public boost::msm::front::state_machine_def<Derived>
```

这是所有前端状态机的公共基类。

它提供：

```text
m_enableEntryActions
moveMotorAbs
moveMotorOpp
moveSingleV
moveSingleStop
getMotorPosition
getDmValues
no_transition
```

### 16.1 m_enableEntryActions

```cpp
bool m_enableEntryActions = true;
```

如果为 false，状态会切换，但状态入口中的运动动作不会执行。

用于：

```text
手动模式
调试模式
只跑状态机不动硬件
```

### 16.2 no_transition

```cpp
void no_transition(...) {}
```

如果状态机收到当前状态不支持的事件，直接忽略，不报错。

优点：不容易因为多余事件崩溃。

缺点：错误事件可能被静默吞掉，调试时不容易发现流程不对。

---

## 17. TakeFloorFSMFront：取封门状态机

初始状态：

```cpp
typedef Lowering initial_state;
```

转换表：

```text
Lowering
  + LoweringDone
  -> ForwardTransverseMovement

ForwardTransverseMovement
  + ForwardTransverseMovementDone
  -> Lifting

Lifting
  + LiftingDone
  -> MoveForHanging

MoveForHanging
  + HangingDone
  -> FingerReleasing

FingerReleasing
  + FingerReleasingDone
  -> TakeFloorCompleted
```

中文流程：

```text
下降至39
-> 正向横移至1132
-> 抬升至12
-> 挂封门横移至1157
-> 手指松开至10
-> 取封门完成
```

---

## 18. TakePlateFSMFront：取盖板状态机

初始状态：

```cpp
typedef MyPlate::Lowering1 initial_state;
```

关键流程大致是：

```text
取盖板下降至55
-> 反向横移至100
-> 纵移至50
-> 手指靠拢至-25
-> 持续纵移，等待 DM 值变化
-> X/Y/角度预调整和精调整
-> 抬升至0
-> 手指持续夹紧
-> 回到取盖高度55
-> 纵移回0
-> 正向横移至1132
-> 取盖板完成
```

实际转换表里还包含左/右/中间盖板借位相关分支：

```text
ForwardLongitudinalForBorrow
ReverseLongitudinalForBorrow
ForwardLongitudinalForCenterBorrow
```

这些分支受 `GlobalMotorPos` 中的盖板选择标志影响。

---

## 19. CoverPlateFSMFront：盖盖板状态机

初始状态：

```cpp
typedef MyPlate::MyPlateRecover1 initial_state;
```

转换表：

```text
横移姿态恢复
-> 纵移姿态恢复
-> 抬升至0
-> 手指松开至-25
-> 下降至55
-> 盖盖板完成
```

这说明盖盖板流程依赖取盖板时保存的位置。

先恢复姿态，再释放盖板。

---

## 20. CoverFloorFSMFront：盖封门状态机

初始状态：

```cpp
typedef MyRecover initial_state;
```

转换表：

```text
恢复机构初始
-> 手指松开至10
-> 正向横移至1132
-> 悬挂移动至1157
-> 抬升至12
-> 手指夹紧至11.5
-> 摘取移动至1132
-> 下降至39
-> 反向横移至0
-> 抬升至11
-> 盖封门完成
```

这是四个状态机中较完整的一条反向封门流程。

---

## 21. FSMBackend 后端封装

```cpp
template <class FrontFSM>
class FSMBackend : public boost::msm::back::state_machine<FrontFSM>
```

Boost MSM 分前端和后端。

这里：

```text
FrontFSM：定义状态、事件、转换表
FSMBackend：真正运行状态机，并绑定运动控制接口
```

### 21.1 绑定状态变化信号

```cpp
QObject::connect(&frontFSM, &BaseFSM_QObject::sigStateChanged,
                 [this](const QString& stateName) {
                     m_currentStateName = stateName;
                 });
```

每次状态变化都记录当前状态名。

### 21.2 绑定运动控制接口

```cpp
frontFSM.moveMotorAbs = [this](int motor, float position) {
    m_zm->MoveSingleAbs(motor, position);
};
```

类似地还绑定了：

```text
moveMotorOpp -> MoveSingleOpp
moveSingleV -> SingleVMove(..., Backward)
moveSingleStop -> SingleVMove(..., Cancel)
getMotorPosition -> GetAxisDpos
getDmValues -> dmcamera->getValues()
```

这就是状态机能控制电机和读取 DM 值的原因。

---

## 22. 四个状态机 typedef

文件末尾：

```cpp
typedef FSMBackend<TakeFloorFSMFront> TakeFloorFSM;
typedef FSMBackend<TakePlateFSMFront> TakePlateFSM;
typedef FSMBackend<CoverPlateFSMFront> CoverPlateFSM;
typedef FSMBackend<CoverFloorFSMFront> CoverFloorFSM;
```

也就是说，`CoverPlate.cpp` 中 new 的四个对象其实都是 `FSMBackend<某个Front>` 的实例。

---

## 23. CoverPlateFSM.h 和 CoverPlate.cpp 如何配合

### CoverPlateFSM.h 负责：

```text
定义状态
定义状态进入时执行什么动作
定义事件
定义事件触发后的状态转换表
```

### CoverPlate.cpp 负责：

```text
启动具体状态机
每 200ms 检查现实世界状态
电机到位/电流到阈值/DM 达标后投递事件
监听完成状态
向 TaskMgr 反馈 Complete/Error
```

组合起来就是：

```text
状态机发运动命令
    ↓
电机运动
    ↓
CoverPlate.cpp 检测到位
    ↓
向状态机 process_event(...)
    ↓
状态机进入下一状态
```

---

## 24. 重点事件来源表

| 事件 | 主要触发来源 |
|---|---|
| `LiftingDone` | 轴 11 到达指定抬升位置 |
| `LoweringDone` | 轴 11 到达指定下降位置 |
| `ForwardTransverseMovementDone` | 轴 7/8 到达 1132 |
| `ReverseTransverseMovementDone` | 轴 7/8 回到 0 |
| `FingerReleasingDone` | 轴 9/10 到达松开位置 |
| `FingerClampingDone` | 轴 9/10 到达夹紧位置 |
| `FingerClampingDurDone` | 手指电流超过阈值并停止 |
| `AngleAdjustDone` | DM 角度接近目标 90° |
| `XAdjustDone` | DM X 接近目标 |
| `YAdjustDone` | DM Y 接近目标 |
| `MyPlateRecoverDone1/2` | 盖板姿态恢复到保存坐标 |

这些事件多数在 `CoverPlate.cpp::checkEvents()` 中投递。

---

## 25. 代码中需要注意的点

### 25.1 全局静态变量放在头文件中

`GlobalMotorPos` 里使用了 `static` 变量。

在头文件中使用 `static`，每个编译单元可能有自己的副本。当前项目里如果多个 `.cpp` 都包含该头文件并读写这些变量，理论上可能出现副本不一致风险。

不过如果实际只在少数路径中使用，可能暂时没暴露问题。更稳妥的长期方案是改成 `.cpp` 中定义的全局对象，或单例/共享上下文对象。

### 25.2 no_transition 静默忽略事件

状态机收到不匹配事件时不会报错。

优点是系统不容易因为重复事件崩溃。

缺点是调试困难。建议后续至少打印 debug 日志。

### 25.3 状态动作里有硬编码位置

例如：

```text
39、12、1132、1157、55、23、-25、-50、324、320、81、47
```

这些机械参数最好集中配置化，否则后续调试设备时容易漏改。

### 25.4 QTimer::singleShot 中捕获 fsm 引用

多个调整状态中有：

```cpp
QTimer::singleShot(1000, &fsm, [&fsm](){ ... });
```

一般情况下如果 fsm 生命周期足够长没问题，但如果状态机在定时器触发前被销毁或停止，需要注意潜在风险。

---

## 26. 阅读重点

优先看：

```text
GlobalMotorPos
事件定义
公共状态 Lowering / Lifting / ForwardTransverseMovement / Finger 系列
AngleAdjust / XAdjust / YAdjust
BaseFSM / FSMBackend
TakeFloorFSMFront transition_table
TakePlateFSMFront transition_table
CoverPlateFSMFront transition_table
CoverFloorFSMFront transition_table
```

如果只想看主线，先看四个状态机的转换表。

---

## 27. 最短理解路径

```text
1. 先看事件定义：知道状态机靠哪些事件推进
2. 再看状态定义：知道每个状态进入时控制哪些电机
3. 再看 transition_table：知道动作顺序
4. 最后回到 CoverPlate.cpp::checkEvents：看事件如何被触发
```

---

## 28. 总结

`CoverPlateFSM.h` 是盖板机构的动作流程核心。

它把复杂动作拆成状态：

```text
下降
抬升
横移
纵移
手指夹紧/松开
DM 视觉调整
姿态恢复
完成
```

再通过事件把状态串起来。

真正的运行方式是：

```text
状态机进入状态 -> 下发电机动作
CoverPlate.cpp 监测动作是否完成 -> process_event 推进状态机
状态机进入完成状态 -> CoverPlate.cpp 设置完成标志 -> TaskMgr 进入下一步
```

所以理解盖板机构时，必须同时看：

```text
CoverPlate.cpp
CoverPlateFSM.h
```

一个负责“外部检测和调度”，一个负责“动作顺序和状态转换”。