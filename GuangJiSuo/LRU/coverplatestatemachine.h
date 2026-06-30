#ifndef COVERPLATESTATEMACHINE_H
#define COVERPLATESTATEMACHINE_H

#include <QObject>
#include "zmotioncontrol.h"

// 前置声明
class CoverPlateStateMachine;

// 状态基类
class State : public QObject
{
    Q_OBJECT
public:
    explicit State(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : QObject(parent), m_machine(machine) {}
    virtual ~State() = default;
    virtual void enter() = 0;// 进入状态时的操作
    virtual void process() = 0;// 状态处理函数
    virtual void exit() = 0; // 离开状态时的操作
    virtual QString name() const = 0;// 获取状态名称

protected:
    CoverPlateStateMachine* m_machine;
};

// 状态机类
class CoverPlateStateMachine : public QObject
{
    Q_OBJECT
public:
    explicit CoverPlateStateMachine(ZMotionControl* zm, QObject *parent = nullptr);
    ~CoverPlateStateMachine();
    void start();// 启动状态机
    void stop(); // 停止状态机
    void transitionTo(State* state);// 转换到指定状态
    State* currentState() const { return m_currentState; }// 获取当前状态
    ZMotionControl* getMotionControl() { return m_zm; }// 获取运动控制器
    void onProcess();// 状态处理定时器触发

private:
    ZMotionControl* m_zm;
    State* m_currentState;
    QTimer* m_processTimer;

    // 所有状态实例
    State* m_takePlateCompleted;
    State* m_descendState;
    State* m_forwardTransverseState;
    State* m_liftState;
    State* m_fingerReleaseState;
    State* m_takeSealDoorCompleted;
    State* m_reverseTransverseState;
    State* m_longitudinalMovementState;
    State* m_fingerClampState;
    State* m_coverPlateCompleted;
    State* m_coverSealDoorCompleted;

    int counter0 = 0;
    int counter1 = 0;
    int counter2 = 0;

signals:
    // 状态变化信号
    void stateChanged(QString stateName);
    // 流程完成信号
    void processCompleted();
};

// 具体状态类
class TakePlateCompletedState : public State
{
    Q_OBJECT
public:
    explicit TakePlateCompletedState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "TakePlateCompleted"; }
};

class DescendState : public State
{
    Q_OBJECT
public:
    explicit DescendState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "DescendState"; }
};

class ForwardTransverseState : public State
{
    Q_OBJECT
public:
    explicit ForwardTransverseState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "ForwardTransverseState"; }
};

class LiftState : public State
{
    Q_OBJECT
public:
    explicit LiftState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "LiftState"; }
};

class FingerReleaseState : public State
{
    Q_OBJECT
public:
    explicit FingerReleaseState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "FingerReleaseState"; }
};

class TakeSealDoorCompletedState : public State
{
    Q_OBJECT
public:
    explicit TakeSealDoorCompletedState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "TakeSealDoorCompleted"; }
};

class ReverseTransverseState : public State
{
    Q_OBJECT
public:
    explicit ReverseTransverseState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "ReverseTransverseState"; }
};

class LongitudinalMovementState : public State
{
    Q_OBJECT
public:
    explicit LongitudinalMovementState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "LongitudinalMovementState"; }
};

class FingerClampState : public State
{
    Q_OBJECT
public:
    explicit FingerClampState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "FingerClampState"; }
};

class CoverPlateCompletedState : public State
{
    Q_OBJECT
public:
    explicit CoverPlateCompletedState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "CoverPlateCompleted"; }
};

class CoverSealDoorCompletedState : public State
{
    Q_OBJECT
public:
    explicit CoverSealDoorCompletedState(CoverPlateStateMachine* machine, QObject *parent = nullptr)
        : State(machine, parent) {}

    void enter() override;
    void process() override;
    void exit() override;
    QString name() const override { return "CoverSealDoorCompleted"; }
};

#endif // COVERPLATESTATEMACHINE_H
