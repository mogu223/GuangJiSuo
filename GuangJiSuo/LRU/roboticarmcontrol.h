#ifndef ROBOTICARMCONTROL_H
#define ROBOTICARMCONTROL_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <QDebug>
#include <QTime>
#include <QRandomGenerator>
using namespace std;
using namespace Eigen;

// 定义 DH 参数结构体
struct DHParameters {
    double a;      // 连杆长度
    double alpha;  // 连杆扭转角
    double d;      // 偏移量
    double theta;
};
// 定义几何体类型
enum class ShapeType {
    Cylinder, // 圆柱体
    RectangularPrism // 添加长方体类型

};

// 轴的几何信息
struct AxisShape {
    ShapeType type;
    Eigen::Vector3d position; // 形状的中心位置
    double length;            // 对于长方体，这表示最长边长
    double width;             // 长方体的次边
    double height;            // 长方体的高
    double radius;            // 圆柱体的半径（如果是长方体，这里可以忽略）
};



// 机械臂类
class RoboticArm {
public:
    double base_X=90,base_Y=0,base_Z=-160;
    double l0=200,l1=152.5,l1Z=-135.5,l2=228.5,l2X=118,l3=290;
    // 设置关节角度的限位
    vector<pair<double, double>> joint_limits = {
        {-180, 180},    // Joint 1 limits
        {-75, 75},  // Joint 2 limits
        {-180, 180},    // Joint 3 limits
        //{0, 0},            // Joint 4 fixed
        {-120, 120},  // Joint 5 limits
        //{0, 0},            // Joint 6 fixed
        {-180, 180}     // Joint 7 limits
        // {-1000,1000},
        // {-1750,1750},
        // {-1100,1100}
    };
    //轴末端到几何中心的偏移用于包围盒
    // vector<pair<double, double>> offsetFromCenter={

    //     {0,0,45},
    //     {},
    //     {},
    //     {},
    //     {}
    // }
    // 接受 DH 参数
    RoboticArm(const std::vector<DHParameters>& dhParams);

    // 计算正运动学，传入每个关节的 theta 角(用于正运动)
    std::vector<Vector3d> calculateForwardKinematics(const std::vector<double>& thetas);
    // 计算正运动学，传入每个关节的 theta 角（用于DE算法）
    std::vector<Vector3d> DEcalculateForwardKinematics(const std::vector<double>& thetas);
    //std::vector<Eigen::Vector3d> calculatecoordinate(const std::vector<double>& thetas);

    // 限制关节角度在范围内
    void limitJointAngles(vector<double>& thetas) {
        for (size_t i = 0; i < thetas.size(); ++i) {
            if (thetas[i] < joint_limits[i].first) {
                thetas[i] = joint_limits[i].first;  // 限制到最小值
            } else if (thetas[i] > joint_limits[i].second) {
                thetas[i] = joint_limits[i].second;  // 限制到最大值
            }
        }
    }


    // // 计算两圆柱体的碰撞
    // bool checkCylinderCollision(const AxisShape& cyl1, const AxisShape& cyl2);
    // // 计算圆柱体与长方体的碰撞
    // bool checkCollisionRectangularPrismAndCylinder(const AxisShape& rect, const AxisShape& cylinder);
    // //计算长方体之间的碰撞
    // bool checkCollisionRectangularPrisms(const AxisShape& rect1, const AxisShape& rect2);


    // // 计算不同几何体之间的碰撞
    // bool checkCollision(const AxisShape& shape1, const AxisShape& shape2);

    // //计算路径碰撞
    // bool checkPathCollision(const std::vector<double>& start_thetas, const std::vector<double>& end_thetas, int num_steps) ;
    //插值生成
    std::vector<std::vector<double>> interpolateTrajectory(const std::vector<double>& start_thetas, const std::vector<double>& end_thetas, int num_steps);



private:
    std::vector<DHParameters> dhParameters; // 存储 DH 参数
};


// 差分进化算法
class DifferentialEvolution {
public:
    DifferentialEvolution(RoboticArm &arm_):arm(arm_)
    {
        srand(static_cast<unsigned int>(time(0)));
    }

    vector<double> optimize(const vector<double>& initialtheta,const Vector3d& position_goal);
    // 随机数生成器
    double randDouble(double min, double max) {
        // 使用 rand() 生成随机数，并将其映射到 [-180, 180] 范围
        double randomValue = min + ((rand() % 1000  / 1000.0)) * (max - min);
        return randomValue;
    }
private:
    RoboticArm arm;
    int population_size=150;
    int max_iter=800;
    double F=0.95;  // 变异因子
    double CR=0.7; // 交叉概率
    enum{Xnum=5};
    vector<double> weights={0.2,0.4,0.3,0.2,0.1};//计算角度变化的各轴权重值
    vector<vector<double>> population;
    double lamadaDeltaThetaInit=0.05;//目标函数中角度变化权重
    double lamadaDeltaTheta;//目标函数中角度变化权重

    // 初始化种群
    void initializePopulation();

    // 变异操作
    vector<double> mutate(const vector<double>& x1, const vector<double>& x2, const vector<double>& x3);

    // 交叉操作
    vector<double> crossover(const vector<double>& target, const vector<double>& mutant);

    // 函数：计算加权运动量
    double computeWeightedMovement(const vector<double>& initialtheta,const std::vector<double> &thetas);

    // 目标函数
    double Fitness(const vector<double>& initialtheta,const std::vector<double> &thetas,const Vector3d& position_goal);

    // 获取当前种群中最优的解
    vector<double> getBestSolution(const vector<double> &initialtheta,const Vector3d& position_goal);

    void adjustLamadaDeltaThetas(const double currentIter);

};


#endif // ROBOTICARMCONTROL_H
