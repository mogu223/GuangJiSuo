#include "roboticarmcontrol.h"


RoboticArm::RoboticArm(const std::vector<DHParameters>& dhParams) : dhParameters(dhParams) {}

std::vector<Vector3d> RoboticArm::calculateForwardKinematics(const std::vector<double>& thetas) {
    Eigen::Matrix4d T_total = Eigen::Matrix4d::Identity();
    std::vector<Eigen::Vector3d> jointPositions; // 存储每个关节的位置
    Eigen::Vector4d  T_base(0, 0, 0, 1); // 通过流操作赋值
    // 计算每个连杆的转换矩阵
    for (size_t i = 0; i < dhParameters.size(); i++) {
        Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
        const auto& params = dhParameters[i];
        double theta;
        if(i==3||i==5)
             theta = 0;
        else if(i==4)
             theta = (thetas[3]+params.theta)/180*M_PI;
        else if(i==6)
             theta = (thetas[4] + params.theta) / 180 * M_PI;
        else
             theta = (thetas[i]+params.theta)/180*M_PI;

        T(0,0) = cos(theta);
        T(0,1) = -sin(theta);
        T(0,2) = 0;
        T(0,3) = params.a;

        T(1,0) = sin(theta) * cos(params.alpha);
        T(1,1) = cos(theta) * cos(params.alpha);
        T(1,2) = -sin(params.alpha);
        T(1,3) = -sin(params.alpha) * params.d;

        T(2,0) = sin(theta) * sin(params.alpha);
        T(2,1) = cos(theta) * sin(params.alpha);
        T(2,2) = cos(params.alpha);
        T(2,3) = cos(params.alpha) * params.d;

        T(3,0) = 0;
        T(3,1) = 0;
        T(3,2) = 0;
        T(3,3) = 1; // 齐次坐标

        // 计算当前关节的坐标
        T_total *= T;
        Eigen::Vector4d  transformedPosition=T_total * T_base;

        // 输出前三个坐标以 Vector3d 的形式
        Eigen::Vector3d result(transformedPosition[0], transformedPosition[1], transformedPosition[2]);

        jointPositions.push_back(result); // 提取当前末端的位置
    }
    return jointPositions;


}

std::vector<Vector3d> RoboticArm::DEcalculateForwardKinematics(const std::vector<double> &thetas)
{
    Eigen::Matrix4d T_total = Eigen::Matrix4d::Identity();
    std::vector<Eigen::Vector3d> jointPositions; // 存储每个关节的位置
    Eigen::Vector4d  T_base(0, 0, 0, 1); // 通过流操作赋值
    // 计算每个连杆的转换矩阵
    for (size_t i = 0; i < dhParameters.size(); i++) {
        Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
        const auto& params = dhParameters[i];
        double theta;
            theta = (thetas[i]+params.theta)/180*M_PI;

        T(0,0) = cos(theta);
        T(0,1) = -sin(theta);
        T(0,2) = 0;
        T(0,3) = params.a;

        T(1,0) = sin(theta) * cos(params.alpha);
        T(1,1) = cos(theta) * cos(params.alpha);
        T(1,2) = -sin(params.alpha);
        T(1,3) = -sin(params.alpha) * params.d;

        T(2,0) = sin(theta) * sin(params.alpha);
        T(2,1) = cos(theta) * sin(params.alpha);
        T(2,2) = cos(params.alpha);
        T(2,3) = cos(params.alpha) * params.d;

        T(3,0) = 0;
        T(3,1) = 0;
        T(3,2) = 0;
        T(3,3) = 1; // 齐次坐标

        // 计算当前关节的坐标
        T_total *= T;
        Eigen::Vector4d  transformedPosition=T_total * T_base;

        // 输出前三个坐标以 Vector3d 的形式
        Eigen::Vector3d result(transformedPosition[0], transformedPosition[1], transformedPosition[2]);

        jointPositions.push_back(result); // 提取当前末端的位置
    }
    return jointPositions;
}

// bool RoboticArm::checkCylinderCollision(const AxisShape &cyl1, const AxisShape &cyl2)
// {
//     // 计算两圆柱体之间的距离，并比较其半径
//     double distance = (cyl1.position - cyl2.center).norm();
//     return distance < (cyl1.radius + cyl2.radius);
// }

// bool RoboticArm::checkCollisionRectangularPrismAndCylinder(const AxisShape &rect, const AxisShape &cylinder)
// {
//     // 判断圆柱体圆心是否落在长方体的平面包围盒内
//     Eigen::Vector3d diff = cylinder.position - rect.position;

//     // 判断圆柱体中心是否在长方体的水平投影范围内
//     if (std::abs(diff.x()) > rect.length / 2 + cylinder.radius) return false;
//     if (std::abs(diff.y()) > rect.width / 2 + cylinder.radius) return false;

//     // 检查沿 Z 方向（高度）的交叠
//     double rect_min_z = rect.position.z() - rect.height / 2;
//     double rect_max_z = rect.position.z() + rect.height / 2;
//     double cylinder_min_z = cylinder.position.z() - cylinder.length / 2;
//     double cylinder_max_z = cylinder.position.z() + cylinder.length / 2;

//     if (rect_min_z > cylinder_max_z || rect_max_z < cylinder_min_z) return false;

//     // 如果通过了所有检查，则发生碰撞
//     return true;
// }

// bool RoboticArm::checkCollisionRectangularPrisms(const AxisShape &rect1, const AxisShape &rect2)
// {
//     // 检查 X 轴方向的交叠
//     if (std::abs(rect1.position.x() - rect2.position.x()) > (rect1.length + rect2.length) / 2) return false;

//     // 检查 Y 轴方向的交叠
//     if (std::abs(rect1.position.y() - rect2.position.y()) > (rect1.width + rect2.width) / 2) return false;

//     // 检查 Z 轴方向的交叠
//     if (std::abs(rect1.position.z() - rect2.position.z()) > (rect1.height + rect2.height) / 2) return false;

//     // 如果通过了所有检查，则发生碰撞
//     return true;
// }



// bool RoboticArm::checkCollision(const AxisShape &shape1, const AxisShape &shape2)
// {


//     if (shape1.type == ShapeType::Cylinder && shape2.type == ShapeType::Cylinder) {
//         return checkCylinderCollision(shape1, shape2);
//     }
//     else if (shape1.type == ShapeType::RectangularPrism && shape2.type == ShapeType::Cylinder) {
//         return checkCollisionRectangularPrismAndCylinder(shape1, shape2);
//     }
//     else if (shape1.type == ShapeType::Cylinder && shape2.type == ShapeType::RectangularPrism) {
//         return checkCollisionRectangularPrismAndCylinder(shape2, shape1);
//     }
//     else if (shape1.type == ShapeType::RectangularPrism && shape2.type == ShapeType::RectangularPrism) {
//         return checkCollisionRectangularPrisms(shape1, shape2);
//     }
//     // 其他碰撞类型检测...
//     return false; // 默认无碰撞
// }

// bool RoboticArm::checkPathCollision(const std::vector<double> &start_thetas, const std::vector<double> &end_thetas, int num_steps)
// {
//     // 生成从 start_thetas 到 end_thetas 的轨迹
//     std::vector<std::vector<double>> trajectory = interpolateTrajectory(start_thetas, end_thetas, num_steps);

//     // 对每个中间点进行碰撞检测
//     for (const auto& thetas : trajectory) {
//         // 检查是否发生碰撞
//         std::vector<AxisShape> current_axes;
//         std::vector<Eigen::Vector3d> joint_positions = calculateForwardKinematics(thetas);

//         // 对每个关节的坐标进行偏移
//         // for (auto& position : joint_positions) {
//         //     position.x() += dx;  // 对x坐标加偏移量
//         //     position.y() += dy;  // 对y坐标加偏移量
//         //     position.z() += dz;  // 对z坐标加偏移量
//         // }
//         current_axes.push_back(AxisShape{ShapeType::RectangularPrism, joint_positions[0], 100, 50, 40, 0}); // 轴0: 长方体,最长边，次边，高
//         current_axes.push_back(AxisShape{ShapeType::Cylinder, joint_positions[1], 20, 100, 0});  // 轴1: 圆柱体，半径20，高度100
//         current_axes.push_back(AxisShape{ShapeType::Cylinder, joint_positions[2], 20, 100, 0});  // 轴2: 圆柱体，半径20，高度100
//         current_axes.push_back(AxisShape{ShapeType::Cylinder, joint_positions[3], 20, 100, 0});  // 轴3: 圆柱体，半径20，高度100
//         current_axes.push_back(AxisShape{ShapeType::Cylinder, joint_positions[4], 20, 100, 0});  // 轴4: 圆柱体，半径20，高度100

//         // 检查每对轴的碰撞
//         for (size_t i = 0; i < current_axes.size(); ++i) {
//             for (size_t j = i + 1; j < current_axes.size(); ++j) {
//                 if(i==1&&j==2||i==3&&j==4)//12轴34轴不检测碰撞
//                     continue;
//                 if (checkCollision(current_axes[i], current_axes[j])) {
//                     return true; // 发现碰撞
//                 }
//             }
//         }
//     }
//     return false; // 无碰撞
// }

std::vector<std::vector<double> > RoboticArm::interpolateTrajectory(const std::vector<double> &start_thetas, const std::vector<double> &end_thetas, int num_steps)
{
    std::vector<std::vector<double>> trajectory;
    for (int i = 0; i <= num_steps; ++i) {
        std::vector<double> intermediate_thetas;
        for (size_t j = 0; j < start_thetas.size(); ++j) {
            double theta = start_thetas[j] + (end_thetas[j] - start_thetas[j]) * i / num_steps;
            intermediate_thetas.push_back(theta);
        }
        trajectory.push_back(intermediate_thetas);
    }
    return trajectory;
}

// std::vector<Eigen::Vector3d> RoboticArm::calculatecoordinate(const std::vector<double> &thetas)
// {

//     // 角度转换为弧度
//     std::vector<double> theta(thetas.size());
//     for (size_t i = 0; i < thetas.size(); i++) {
//         theta[i] = thetas[i] * M_PI / 180.0; // 直接进行弧度转换
//     }

//     std::vector<Eigen::Vector3d> jointPositions(dhParameters.size()); // Resize vector

//     // 基座
//     jointPositions[0] = Eigen::Vector3d(base_X, base_Y, base_Z);

//     // 第一节
//     jointPositions[1][0] = jointPositions[0][0] + l0 * cos(theta[0]);
//     jointPositions[1][1] = jointPositions[0][1] + l0 * sin(theta[0]);
//     jointPositions[1][2] = jointPositions[0][2]+  l1Z; // 假设在同一平面上

//     // 第二节
//     jointPositions[2][0] = jointPositions[1][0] + l1 * cos(theta[1]) * cos(theta[0]);
//     jointPositions[2][1] = jointPositions[1][1] + l1 * cos(theta[1]) * sin(theta[0]);
//     jointPositions[2][2] = jointPositions[1][2] + l1 * sin(theta[1]);

//     // 第三节
//     jointPositions[3][0] = jointPositions[2][0] + l2* cos(theta[1])  * cos(theta[0])+l2X*cos(theta[2])*sin(theta[0])* cos(theta[1]) ;
//     jointPositions[3][1] = jointPositions[2][1] + l2 * cos(theta[1]) * sin(theta[0])+l2X*cos(theta[2])*cos(theta[0])* cos(theta[1]) ;
//     jointPositions[3][2] = jointPositions[2][2]+  l2X*sin(theta[2])+ l2 * sin(theta[1]);

//     // 第四节
//     jointPositions[4][0] = jointPositions[3][0]-l2X*cos(theta[2])*sin(theta[0])* cos(theta[1])  + l3 * cos(theta[1]) * cos(theta[0]) * cos(theta[3])* cos(theta[2]);
//     jointPositions[4][1] = jointPositions[3][1]-l2X*cos(theta[2])*cos(theta[0])* cos(theta[1])  + l3 * cos(theta[1]) * sin(theta[0]) * cos(theta[3])* cos(theta[2]);
//     jointPositions[4][2] = jointPositions[3][2] +l3 * cos(theta[3])* cos(theta[2])* sin(theta[1])-l2X*sin(theta[2]);

//     return jointPositions;

// }

double DifferentialEvolution::Fitness(const vector<double>& initialtheta,const std::vector<double> &thetas,const Vector3d &position_goal)
{
    // 假设末端执行器的位置是返回的计算结果中的最后一个位置
    std::vector<Eigen::Vector3d> positions = arm.calculateForwardKinematics(thetas);
    Eigen::Vector3d position_actual = positions.back();  // 获取最后一个位置，即末端执行器的位置

    double error_norm = 100*(position_actual - position_goal).norm();  // 欧几里得距离

    double error_deltaThetas=computeWeightedMovement(initialtheta,thetas);//计算各轴角度权重变化

    double error=error_norm+lamadaDeltaTheta*error_deltaThetas;
    // if (error > 1) {
    //     // 遍历关节角度
    //     for (int i = 0; i < thetas.size(); i++) {
    //         // 跳过索引为 3 和 5 的关节
    //         if (i == 3 || i == 5) {
    //             continue;
    //         }

    //         // 检查当前关节角度是否接近限值的 90%
    //         if (thetas[i] <= (joint_limits[i].first * 0.9) || thetas[i] >= (joint_limits[i].second * 0.9)) {
    //             // 如果误差大于1，则调整误差
    //             error *= 2;
    //             break; // 一旦找到一个关节不符合条件，立即退出循环
    //         }
    //     }
    // }
    // // 生成每个轴的形状
    // std::vector<AxisShape> current_axes;
    // current_axes.push_back(AxisShape{ShapeType::Cube, positions[0], 0, 0, 50});  // 轴0: 立方体，边长50
    // current_axes.push_back(AxisShape{ShapeType::Cylinder, positions[1], 20, 100, 0});  // 轴1: 圆柱体，半径20，高度100
    // current_axes.push_back(AxisShape{ShapeType::Cylinder, positions[2], 20, 100, 0});  // 轴2: 圆柱体，半径20，高度100
    // current_axes.push_back(AxisShape{ShapeType::Cylinder, positions[3], 20, 100, 0});  // 轴3: 圆柱体，半径20，高度100
    // current_axes.push_back(AxisShape{ShapeType::Cylinder, positions[4], 20, 100, 0});  // 轴4: 圆柱体，半径20，高度100

    // // 检查是否发生碰撞
    // double collision_penalty = 0.0;
    // for (size_t i = 0; i < current_axes.size(); ++i) {
    //     for (size_t j = i + 1; j < current_axes.size(); ++j) {
    //         if (arm.checkCollision(current_axes[i], current_axes[j])) {
    //             collision_penalty += 1000.0;  // 发生碰撞，增加惩罚
    //         }
    //     }
    // }
    // if(error<10)
    //     // 检查运动路径是否有碰撞
    //     if (arm.checkPathCollision(initialtheta, thetas, 10)) { // 10表示插值的步数
    //         error += 1000.0; // 如果发生碰撞，增加较大惩罚
    //     }

    return error;
}



vector<double> DifferentialEvolution::optimize(const vector<double>& initialtheta,const Vector3d &position_goal)
{
    QRandomGenerator myGenerator;
    myGenerator.seed(QDateTime::currentMSecsSinceEpoch());  // Optional: Set a custom seed
    initializePopulation();
    vector<double> best;
    double bestFitness;
    for (int iter = 0; iter < max_iter; ++iter) {
        adjustLamadaDeltaThetas(iter);
        for (int i = 0; i < population_size; ++i) {

            // 变异操作
            int r1 = myGenerator.generate() % population_size, r2 = myGenerator.generate() % population_size, r3 =myGenerator.generate() % population_size;
            vector<double> mutant = mutate(population[r1], population[r2], population[r3]);
            // 交叉操作
            vector<double> trial = crossover(population[i], mutant);

            double trial_fitness=Fitness(initialtheta,trial, position_goal);
            double population_fitness=Fitness(initialtheta,population[i], position_goal);
            // 选择操作
            if (trial_fitness <population_fitness )
            {
                //qDebug()<<r1<<r2<<r3;

                //adjustF(trial_fitness,population_fitness);
                //qDebug()<<F;
                population[i] = trial;
            }

            //cout << "trial_fitness: " << trial_fitness << endl;
        }

        // 打印每代最优解
        best = getBestSolution(initialtheta,position_goal);

        bestFitness=Fitness(initialtheta,best, position_goal);

        // cout << "Generation " << iter << " Best Solution: ";
        // for (double theta : best) {
        //     cout << theta << " ";
        // }
        // cout << "Fitness: " << bestFitness << endl;

        if(bestFitness<1){
            cout<<iter;
            cout << "bestFitness: " << bestFitness << endl;
            return best;


        }

    }
    cout << "bestFitness: " << bestFitness << endl;
    return best;
}

void DifferentialEvolution::initializePopulation()
{
    population.clear();

    for (int i = 0; i < population_size; ++i) {
        vector<double> q(Xnum);
        for (int j = 0; j < Xnum; j++) {
            q[j] = randDouble(arm.joint_limits[j].first, arm.joint_limits[j].second);  // 随机生成关节角度
        }
        arm.limitJointAngles(q);  // 限制关节角度在有效范围内
        population.push_back(q);
    }
}

vector<double> DifferentialEvolution::mutate(const vector<double> &x1, const vector<double> &x2, const vector<double> &x3)
{
    vector<double> mutant(Xnum);
    for (int i = 0; i < Xnum; ++i) {

        mutant[i] = x1[i] + F * (x2[i] - x3[i]);
    }
    arm.limitJointAngles(mutant);  // 限制变异结果
    return mutant;
}

vector<double> DifferentialEvolution::crossover(const vector<double> &target, const vector<double> &mutant)
{
    vector<double> trial(Xnum);
    for (int i = 0; i < Xnum; ++i) {

        trial[i] = (randDouble(0, 1) < CR) ? mutant[i] : target[i];
    }
    arm.limitJointAngles(trial);  // 限制变异结果

    return trial;
}

double DifferentialEvolution::computeWeightedMovement(const vector<double> &initialtheta, const std::vector<double> &thetas)
{
    double totalMovement = 0.0;
    int n = initialtheta.size();

    // 确保initialtheta和weights的大小一致
    if (n != weights.size()) {
        std::cerr << "Error: The size of initialtheta and weights must be the same!" << std::endl;
        return -1.0;
    }

    // 计算加权运动量
    for (int i = 0; i < n; ++i) {
        totalMovement += weights[i] * std::abs(initialtheta[i]-thetas[i]);  // 使用绝对值来确保角度变化量为正
    }

    return totalMovement;
}

vector<double> DifferentialEvolution::getBestSolution(const vector<double> &initialtheta, const Vector3d &position_goal)
{
    vector<double> best = population[0];
    double best_fitness = Fitness(initialtheta,best, position_goal);  // 计算第一个解的适应度
    for (const auto& q : population) {
        double q_fitness = Fitness(initialtheta,q, position_goal);  // 计算当前解的适应度
        if (q_fitness < best_fitness) {
            best = q;
            best_fitness = q_fitness;
        }
    }
    return best;
}

void DifferentialEvolution::adjustLamadaDeltaThetas(const double currentIter)
{
    // if(currentIter<max_iter/vDeltaThetaInit)
    // {
    //     lamadaDeltaTheta=lamadaDeltaThetaInit;
    // }
    // else
    // {
        //vDeltaTheta=  1+(vDeltaThetaInit -1) * exp(-50 * static_cast<double>(currentIter) / max_iter);

        //lamadaDeltaTheta=lamadaDeltaThetaInit-(currentIter-max_iter/vDeltaTheta)/(max_iter/vDeltaTheta)*lamadaDeltaThetaInit;


    // }
    lamadaDeltaTheta= (lamadaDeltaThetaInit) * exp(-max_iter/25 * static_cast<double>(currentIter) / max_iter);

}
