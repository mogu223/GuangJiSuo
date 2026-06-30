// CoverPlateStateMachine.h
#ifndef COVERPLATESTATEMACHINE_H
#define COVERPLATESTATEMACHINE_H

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/euml/common.hpp>
#include <zmotioncontrol.h>
#include <QObject>

class CoverPlate;

// 事件定义（精简重复事件，统一事件类型）
struct EventMotor4At80 {};                  // 电机4位置到达80
struct EventMotor11At0 {};                  // 电机11位置到达0
struct EventMotor78At80 {};                 // 电机7、8位置均到达80
struct EventMotor11At50 {};                 // 电机11位置到达50
struct EventMotor910At0 {};                 // 电机9、10位置均为0
struct EventMotor78At0 {};                  // 电机7、8位置均到达0
struct EventUnknownConditionMet {};         // 满足特定未知条件
struct EventMotor910At15 {};                // 电机9、10位置均为15
struct EventMotor12At0 {};                  // 电机12位置为0

// 状态机前端定义
namespace msm = boost::msm;
namespace msmf = boost::msm::front;
namespace mpl = boost::mpl;

class CoverPlateStateMachine_ : public msmf::state_machine_def<CoverPlateStateMachine_>
{
public:
    CoverPlateStateMachine_(CoverPlate* coverPlate, ZMotionControl* zm)
        : m_coverPlate(coverPlate), m_zm(zm) {}

    // 状态定义（保持不变）
    struct TakePlateCompleted : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm&) {
            qDebug() << "进入取盖板完成状态";
        }
    };

    struct Descending : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入下降状态，电机11开始反转";
            fsm.m_zm->MoveSingleAbs(11, 0);
        }
    };

    struct ForwardTransverse : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入正向横移状态，电机7、8开始正转";
            fsm.m_zm->MoveSingleAbs(7, 80);
            fsm.m_zm->MoveSingleAbs(8, 80);
        }
    };

    struct Ascending : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入抬升状态，电机11开始正转";
            fsm.m_zm->MoveSingleAbs(11, 50);
        }
    };

    struct FingerReleasing : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入手指松开状态，电机9、10开始反转";
            fsm.m_zm->MoveSingleAbs(9, 0);
            fsm.m_zm->MoveSingleAbs(10, 0);
        }
    };

    struct TakeDoorCompleted : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入取封门完成状态，电机11开始反转";
            fsm.m_zm->MoveSingleAbs(11, 0);
        }
    };

    struct ReverseTransverse : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入反向横移状态，电机7、8开始反转";
            fsm.m_zm->MoveSingleAbs(7, 0);
            fsm.m_zm->MoveSingleAbs(8, 0);
        }
    };

    struct LongitudinalMove : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入纵移状态，电机5、6开始运动";
            // 预留电机5、6运动逻辑
        }
    };

    struct FingerClamping : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入手指夹紧状态，电机9、10开始正转";
            // 根据前序状态判断目标位置
            if (fsm.last_state_is<Ascending>()) {
                // 从抬升状态进入时的目标位置
                if (fsm.previous_state_was<LongitudinalMove>()) {
                    fsm.m_zm->MoveSingleAbs(9, 15);
                    fsm.m_zm->MoveSingleAbs(10, 15);
                } else {
                    fsm.m_zm->MoveSingleAbs(9, 0);
                    fsm.m_zm->MoveSingleAbs(10, 0);
                }
            }
        }
    };

    struct FixPlateCompleted : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm& fsm) {
            qDebug() << "进入盖盖板完成状态，电机11开始反转";
            fsm.m_zm->MoveSingleAbs(11, 0);
        }
    };

    struct FixDoorCompleted : msmf::state<> {
        template <class Event, class Fsm>
        void on_entry(Event const&, Fsm&) {
            qDebug() << "进入盖封门完成状态";
        }
    };

    // 初始状态
    typedef TakePlateCompleted initial_state;

    // 状态转移表（修正重复项，按流程顺序梳理）
    struct transition_table : mpl::vector<
                                  // 取盖板完成 -> 下降（电机4到位）
                                  msmf::Row<TakePlateCompleted, EventMotor4At80, Descending, msmf::none, msmf::none>,

                                  // 下降 -> 正向横移（电机11到位0）
                                  msmf::Row<Descending, EventMotor11At0, ForwardTransverse, msmf::none, msmf::none>,

                                  // 正向横移 -> 抬升（电机7、8到位80）
                                  msmf::Row<ForwardTransverse, EventMotor78At80, Ascending, msmf::none, msmf::none>,

                                  // 抬升 -> 手指松开（电机11到位50）
                                  msmf::Row<Ascending, EventMotor11At50, FingerReleasing, msmf::none, msmf::none>,

                                  // 手指松开 -> 取封门完成（电机9、10到位0）
                                  msmf::Row<FingerReleasing, EventMotor910At0, TakeDoorCompleted, msmf::none, msmf::none>,

                                  // 取封门完成 -> 反向横移（电机11到位0）
                                  msmf::Row<TakeDoorCompleted, EventMotor11At0, ReverseTransverse, msmf::none, msmf::none>,

                                  // 反向横移 -> 纵移（电机7、8到位0）
                                  msmf::Row<ReverseTransverse, EventMotor78At0, LongitudinalMove, msmf::none, msmf::none>,

                                  // 纵移 -> 抬升（未知条件满足）
                                  msmf::Row<LongitudinalMove, EventUnknownConditionMet, Ascending, msmf::none, msmf::none>,

                                  // 抬升 -> 手指夹紧（电机11到位50，从纵移过来）
                                  msmf::Row<Ascending, EventMotor11At50, FingerClamping, msmf::none, msmf::none>,

                                  // 手指夹紧 -> 下降（电机9、10到位15）
                                  msmf::Row<FingerClamping, EventMotor910At15, Descending, msmf::none, msmf::none>,

                                  // 正向横移 -> 取盖板完成（二次横移到位80）
                                  msmf::Row<ForwardTransverse, EventMotor78At80, TakePlateCompleted, msmf::none, msmf::none>,

                                  // 取盖板完成 -> 反向横移（电机12到位0）
                                  msmf::Row<TakePlateCompleted, EventMotor12At0, ReverseTransverse, msmf::none, msmf::none>,

                                  // 反向横移 -> 抬升（二次反向横移到位0）
                                  msmf::Row<ReverseTransverse, EventMotor78At0, Ascending, msmf::none, msmf::none>,

                                  // 手指松开 -> 盖盖板完成（二次手指松开到位0）
                                  msmf::Row<FingerReleasing, EventMotor910At0, FixPlateCompleted, msmf::none, msmf::none>,

                                  // 盖盖板完成 -> 正向横移（电机11到位0）
                                  msmf::Row<FixPlateCompleted, EventMotor11At0, ForwardTransverse, msmf::none, msmf::none>,

                                  // 正向横移 -> 纵移（三次横移到位80）
                                  msmf::Row<ForwardTransverse, EventMotor78At80, LongitudinalMove, msmf::none, msmf::none>,

                                  // 纵移 -> 抬升（二次未知条件满足）
                                  msmf::Row<LongitudinalMove, EventUnknownConditionMet, Ascending, msmf::none, msmf::none>,


                                  // 手指夹紧 -> 下降（电机9、10到位0）
                                  msmf::Row<FingerClamping, EventMotor910At0, Descending, msmf::none, msmf::none>,

                                  // 下降 -> 反向横移（二次下降到位0）
                                  msmf::Row<Descending, EventMotor11At0, ReverseTransverse, msmf::none, msmf::none>,

                                  // 反向横移 -> 抬升（三次反向横移到位0）
                                  msmf::Row<ReverseTransverse, EventMotor78At0, Ascending, msmf::none, msmf::none>,

                                  // 抬升 -> 盖封门完成（四次抬升到位50）
                                  msmf::Row<Ascending, EventMotor11At50, FixDoorCompleted, msmf::none, msmf::none>
                                  > {};

    // 辅助判断前序状态（用于手指夹紧状态的动作区分）
    template <class State>
    bool last_state_is() const {
        return typeid(current_state_type) == typeid(State);
    }

    template <class State>
    bool previous_state_was() const {
        return typeid(previous_state_type) == typeid(State);
    }

    // 未处理事件
    template <class Fsm, class Event>
    void no_transition(Event const& e, Fsm&, int state) {
        qDebug() << "未处理的事件: " << typeid(e).name() << "，当前状态: " << state;
    }

    CoverPlate* m_coverPlate;
    ZMotionControl* m_zm;
    // 用于记录状态转移历史（辅助判断）
    typedef typename msm::back::state_machine<CoverPlateStateMachine_>::state_type current_state_type;
    typedef typename msm::back::state_machine<CoverPlateStateMachine_>::state_type previous_state_type;
};

// 状态机后端定义
typedef msm::back::state_machine<CoverPlateStateMachine_> CoverPlateStateMachine;

#endif // COVERPLATESTATEMACHINE_H
