#include "CoverPlateStateMachine.h"
#include <QTimer>
#include <QDebug>

// 状态机实现
CoverPlateStateMachine::CoverPlateStateMachine(ZMotionControl* zm, QObject *parent)
    : QObject(parent), m_zm(zm), m_currentState(nullptr)
{
    m_processTimer = new QTimer(this);
    connect(m_processTimer, &QTimer::timeout, this, &CoverPlateStateMachine::onProcess);

    // 创建所有状态实例
    m_takePlateCompleted = new TakePlateCompletedState(this, this);
    m_descendState = new DescendState(this, this);
    m_forwardTransverseState = new ForwardTransverseState(this, this);
    m_liftState = new LiftState(this, this);
    m_fingerReleaseState = new FingerReleaseState(this, this);
    m_takeSealDoorCompleted = new TakeSealDoorCompletedState(this, this);
    m_reverseTransverseState = new ReverseTransverseState(this, this);
    m_longitudinalMovementState = new LongitudinalMovementState(this, this);
    m_fingerClampState = new FingerClampState(this, this);
    m_coverPlateCompleted = new CoverPlateCompletedState(this, this);
    m_coverSealDoorCompleted = new CoverSealDoorCompletedState(this, this);
}

CoverPlateStateMachine::~CoverPlateStateMachine()
{
    stop();
}

void CoverPlateStateMachine::start()
{
    // 从取盖板完成状态开始
    transitionTo(m_takePlateCompleted);
    m_processTimer->start(200);
}

void CoverPlateStateMachine::stop()
{
    m_processTimer->stop();
    if (m_currentState) {
        m_currentState->exit();
        m_currentState = nullptr;
    }
    //清零所有计数器
}

void CoverPlateStateMachine::transitionTo(State* state)
{
    if (!state || state == m_currentState) return;

    if (m_currentState) {
        m_currentState->exit();
    }

    m_currentState = state;
    m_currentState->enter();
    emit stateChanged(state->name());
}

void CoverPlateStateMachine::onProcess()
{
    if (m_currentState) {
        m_currentState->process();
    }
}

// 具体状态实现
//取盖板完成状态
void TakePlateCompletedState::enter()
{
    qDebug() << "进入取盖板完成状态";
}
void TakePlateCompletedState::process()
{
    // 检查二级升降电机是否下降到位
    float pos11 = m_machine->getMotionControl()->GetAxisDpos(11);
    if (qAbs(pos11) < 0.1) { // 转换到反向横移状态
        m_machine->transitionTo(m_machine->getMotionControl()->getinstance() ? m_machine->currentState()->parent()->findChild<ReverseTransverseState*>() : nullptr);
    }
}
void TakePlateCompletedState::exit()
{
    qDebug() << "离开取盖板完成状态";
}


//下降状态
void DescendState::enter()
{
    qDebug() << "进入下降状态";
    m_machine->getMotionControl()->MoveSingleAbs(11, 0);// 电机11反转至0
}
void DescendState::process()
{
    float pos7 = m_machine->getMotionControl()->GetAxisDpos(7);
    float pos8 = m_machine->getMotionControl()->GetAxisDpos(8);
    float pos11 = m_machine->getMotionControl()->GetAxisDpos(11);
    if (qAbs(pos11) < 0.1) {
        if(abs(pos7) < 0.1 && abs(pos8) < 0.1)// 转换到正向横移状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<ForwardTransverseState*>());
        else if(abs(pos7 - 80) < 0.1 && abs(pos8 - 80) < 0.1)// 转换到反向横移状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<ReverseTransverseState*>());
    }
}
void DescendState::exit()
{
    qDebug() << "离开下降状态";
}


//正向横移状态
void ForwardTransverseState::enter()
{
    qDebug() << "进入正向横移状态";
    m_machine->getMotionControl()->MoveSingleAbs(7, 80);//电机7、8开始正转，目标位置80
    m_machine->getMotionControl()->MoveSingleAbs(8, 80);//这里后续换成7、8多轴协同补偿运动
}
void ForwardTransverseState::process()
{
    float pos7 = m_machine->getMotionControl()->GetAxisDpos(7);
    float pos8 = m_machine->getMotionControl()->GetAxisDpos(8);
    float pos9 = m_machine->getMotionControl()->GetAxisDpos(9);
    float pos10 = m_machine->getMotionControl()->GetAxisDpos(10);

    if (qAbs(pos7 - 80) < 0.1 && qAbs(pos8 - 80) < 0.1) {
        if(abs(pos9 - 15) < 0.1 && abs(pos10 - 15) < 0.1)// 转换到抬升状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<LiftState*>());
        else if()// 转换到取盖板完成状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<TakePlateCompletedState*>());
        else if(abs(pos9) < 0.1 && abs(pos10) < 0.1)// 转换到纵向调整状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<LongitudinalMovementState*>());
    }
}
void ForwardTransverseState::exit()
{
    qDebug() << "离开正向横移状态";
}


//上升状态
void LiftState::enter()
{
    qDebug() << "进入抬升状态";
    m_machine->getMotionControl()->MoveSingleAbs(11, 50);
}
void LiftState::process()
{
    float pos9 = m_machine->getMotionControl()->GetAxisDpos(9);
    float pos10 = m_machine->getMotionControl()->GetAxisDpos(10);
    float pos11 = m_machine->getMotionControl()->GetAxisDpos(11);
    if (qAbs(pos11 - 50) < 0.1) {
        if(abs(pos9 - 15) < 0.1 && abs(pos10 - 15) < 0.1)// 转换到手指松开状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<FingerReleaseState*>());
        else if(abs(pos9) < 0.1 && abs(pos10) < 0.1)// 转换到手指夹紧状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<FingerClampState*>());
        else if()//转换到盖封门完成状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<CoverSealDoorCompletedState*>());
    }
}
void LiftState::exit()
{
    qDebug() << "离开抬升状态";
}


//手指松开状态
void FingerReleaseState::enter()
{
    qDebug() << "进入手指松开状态";
    m_machine->getMotionControl()->MoveSingleAbs(9, 0);
    m_machine->getMotionControl()->MoveSingleAbs(10, 0);
}
void FingerReleaseState::process()
{
    float pos9 = m_machine->getMotionControl()->GetAxisDpos(9);
    float pos10 = m_machine->getMotionControl()->GetAxisDpos(10);

    if (qAbs(pos9) < 0.1 && qAbs(pos10) < 0.1) {
        if () //取封门完成状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<TakeSealDoorCompletedState*>());
        else if () //取盖板完成状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<CoverPlateCompletedState*>());
    }
}
void FingerReleaseState::exit()
{
    qDebug() << "离开手指松开状态";
}


//取封门完成状态
void TakeSealDoorCompletedState::enter()
{
    qDebug() << "进入取封门完成状态";
    m_machine->getMotionControl()->MoveSingleAbs(11, 0);
}
void TakeSealDoorCompletedState::process()
{
    float pos11 = m_machine->getMotionControl()->myZmotionStatus->allAxisStatus[11].posi;
    if (qAbs(pos11) < 0.1) {// 转换为反向横移状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<ReverseTransverseState*>());
    }
}
void TakeSealDoorCompletedState::exit()
{
    qDebug() << "离开取封门完成状态";
}


//反向横移状态
void ReverseTransverseState::enter()
{
    qDebug() << "进入反向横移状态";
    m_machine->getMotionControl()->MoveSingleAbs(7, 0);//电机7、8开始反转，目标位置0
    m_machine->getMotionControl()->MoveSingleAbs(8, 0);
}
void ReverseTransverseState::process()
{
    float pos7 = m_machine->getMotionControl()->GetAxisDpos(7);
    float pos8 = m_machine->getMotionControl()->GetAxisDpos(8);
    float pos9 = m_machine->getMotionControl()->GetAxisDpos(9);
    float pos10 = m_machine->getMotionControl()->GetAxisDpos(10);

    if (qAbs(pos7) < 0.1 && qAbs(pos8) < 0.1) {
        if(abs(pos9 - 15) < 0.1 && abs(pos10 - 15) < 0.1)// 转换到抬升状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<LiftState*>());
        else if(abs(pos9) < 0.1 && abs(pos10) < 0.1)// 转换到纵向调整状态
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<LongitudinalMovementState*>());
    }
}
void ReverseTransverseState::exit()
{
    qDebug() << "离开反向横移状态";
}


//纵向调整状态
void LongitudinalMovementState::enter()
{
    qDebug() << "进入纵移状态";
    // 这里可以添加电机5、6的运动逻辑
}
void LongitudinalMovementState::process()
{
    // 满足特定条件后转换状态(条件待写)
    bool conditionMet = true;

    if (conditionMet)
    m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<LiftState*>());
}
void LongitudinalMovementState::exit()
{
    qDebug() << "离开纵移状态";
}


//手指夹紧状态
void FingerClampState::enter()
{
    qDebug() << "进入手指夹紧状态";
    m_machine->getMotionControl()->MoveSingleAbs(9, 15);
    m_machine->getMotionControl()->MoveSingleAbs(10, 15);
}
void FingerClampState::process()
{
    float pos9 = m_machine->getMotionControl()->GetAxisDpos(9);
    float pos10 = m_machine->getMotionControl()->GetAxisDpos(10);

    if (abs(pos9 - 15) < 0.1 && abs(pos10 - 15) < 0.1)
    m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<DescendState*>());
}
void FingerClampState::exit()
{
    qDebug() << "离开手指夹紧状态";
}


//盖盖板完成状态
void CoverPlateCompletedState::enter()
{
    qDebug() << "进入盖盖板完成状态";
    m_machine->getMotionControl()->MoveSingleAbs(11, 0);
}
void CoverPlateCompletedState::process()
{
    float pos11 = m_machine->getMotionControl()->myZmotionStatus->allAxisStatus[11].posi;
    if (qAbs(pos11) < 0.1) {
        m_machine->transitionTo(static_cast<CoverPlateStateMachine*>(parent())->currentState()->parent()->findChild<ForwardTransverseState*>());
    }
}
void CoverPlateCompletedState::exit()
{
    qDebug() << "离开盖盖板完成状态";
}


//盖封门完成状态
void CoverSealDoorCompletedState::enter()
{
    qDebug() << "进入盖封门完成状态";
    emit static_cast<CoverPlateStateMachine*>(parent())->processCompleted();// 整个反向流程完成，发送完成信号
}
void CoverSealDoorCompletedState::process()
{
    float pos4 = m_machine->getMotionControl()->GetAxisDpos(4);// 检查一级升降电机是否到达指定位置，后面换成激光测距传感器
    if (qAbs(pos4 - 80) < 0.1) { // 转换到下降状态
        m_machine->transitionTo(m_machine->getMotionControl()->getinstance() ? m_machine->currentState()->parent()->findChild<DescendState*>() : nullptr);
    }
}
void CoverSealDoorCompletedState::exit()
{
    qDebug() << "离开盖封门完成状态";
}
