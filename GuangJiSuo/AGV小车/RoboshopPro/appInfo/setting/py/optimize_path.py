# coding=utf-8
import math
import json as js
# import matplotlib.pyplot as plt
import time
import copy
import numpy as np
import sys
import os

epslion_pi = 1e-6
max_vx = 1.0
max_vw = 45.0 / 180.0 * math.pi
L = 1.5
total_samp_points = 1001
tg = 1 / (total_samp_points - 1)

weight_kappa = 1.0
weight_dkappa = 1.0
weight_distance = 1.

init_kappa = 0.
init_dkappa = 0.
init_length = 0.
init_distance1 = 0.
init_distance2 = 0.


def f5OrderByDis(p0, p5, d1, d2, theta1, theta2):
    """做直线拼接的高级三阶贝塞尔曲线生成，调用f5order()

    Arg:
        p0 (list): 第一个控制点
        p5 (list): 第六个控制点（最后一个控制点）
        d1 (float): 第二个控制点到第一个控制点的距离
        d2 (float): 第五个控制点到第六个控制点的距离
        theta1(float): 第一条直线的偏转角
        theta2(float): 第二条直线的偏转角
    Returns:
        list: 曲线的一个维度点的序列
    """
    # 计算控制点的坐标
    p1 = [0, 0]
    p2 = [0, 0]
    p3 = [0, 0]
    p4 = [0, 0]
    if abs(theta1 - math.pi / 2) < epslion_pi:
        p1[0] = p0[0]
        p1[1] = p0[1] + d1
        p2[0] = p0[0]
        p2[1] = p0[1] + d1
    elif abs(theta1 + math.pi / 2) < epslion_pi:
        p1[0] = p0[0]
        p1[1] = p0[1] - d1
        p2[0] = p0[0]
        p2[1] = p0[1] - d1
    else:
        p1[0] = p0[0] + d1 * math.cos(theta1)
        p1[1] = p0[1] + d1 * math.sin(theta1)
        p2[0] = p0[0] + d1 * math.cos(theta1)
        p2[1] = p0[1] + d1 * math.sin(theta1)

    if abs(theta2 - math.pi / 2) < epslion_pi:
        p3[0] = p5[0]
        p3[1] = p5[1] + d2
        p4[0] = p5[0]
        p4[1] = p5[1] + d2
    elif abs(theta2 + math.pi / 2) < epslion_pi:
        p3[0] = p5[0]
        p3[1] = p5[1] - d2
        p4[0] = p5[0]
        p4[1] = p5[1] - d2
    else:
        p3[0] = p5[0] + d2 * math.cos(theta2)
        p3[1] = p5[1] + d2 * math.sin(theta2)
        p4[0] = p5[0] + d2 * math.cos(theta2)
        p4[1] = p5[1] + d2 * math.sin(theta2)
    # 通过控制点坐标得到高级贝塞尔曲线上的采样点
    smap_points = f5Order(p0, p1, p2, p3, p4, p5)
    control_points = np.array([p0, p1, p2, p3, p4, p5])
    return (smap_points, control_points)


def f5OrderAtT(p0, p1, p2, p3, p4, p5, t):
    s = 1 - t
    x = (p0[0] * s * s * s * s * s
         + 5.0 * p1[0] * s * s * s * s * t
         + 10.0 * p2[0] * s * s * s * t * t
         + 10.0 * p3[0] * s * s * t * t * t
         + 5.0 * p4[0] * s * t * t * t * t
         + p5[0] * t * t * t * t * t)
    y = (p0[1] * s * s * s * s * s
         + 5.0 * p1[1] * s * s * s * s * t
         + 10.0 * p2[1] * s * s * s * t * t
         + 10.0 * p3[1] * s * s * t * t * t
         + 5.0 * p4[1] * s * t * t * t * t
         + p5[1] * t * t * t * t * t)
    v = [x, y]
    return v


def f3OrderAtT(p0, p1, p2, p3, t):
    s = 1 - t
    x = (p0[0] * s * s * s
         + 3.0 * p1[0] * s * s * t
         + 3.0 * p2[0] * s * t * t
         + p3[0] * t * t * t)
    y = (p0[1] * s * s * s
         + 3.0 * p1[1] * s * s * t
         + 3.0 * p2[1] * s * t * t
         + p3[1] * t * t * t)
    v = [x, y]
    return v


def f5Order(p0, p1, p2, p3, p4, p5):
    """高级三阶贝塞尔曲线的参数方程

    Args:
        p0 (list): 第一个控制点
        p1 (list): 第二个控制点
        p2 (list): 第三个控制点
        p3 (list): 第四个控制点
        p4 (list): 第五个控制点
        p5 (list): 第六个控制点

    Returns:
        list: 曲线点的序列
    """
    dt = tg
    t = np.arange(0, 1.0, dt)
    s = 1 - t

    x = (p0[0] * s ** 5
         + 5.0 * p1[0] * s ** 4 * t
         + 10.0 * p2[0] * s ** 3 * t ** 2
         + 10.0 * p3[0] * s ** 2 * t ** 3
         + 5.0 * p4[0] * s * t ** 4
         + p5[0] * t ** 5)

    y = (p0[1] * s ** 5
         + 5.0 * p1[1] * s ** 4 * t
         + 10.0 * p2[1] * s ** 3 * t ** 2
         + 10.0 * p3[1] * s ** 2 * t ** 3
         + 5.0 * p4[1] * s * t ** 4
         + p5[1] * t ** 5)

    v = np.column_stack((x, y))
    return v


def calpointfortheta(p0, p1, p2, p3, p4, p5):
    """高级三阶贝塞尔曲线的参数方程

    Args:
        p0 (list): 第一个控制点
        p1 (list): 第二个控制点
        p2 (list): 第三个控制点
        p3 (list): 第四个控制点
        p4 (list): 第五个控制点
        p5 (list): 第六个控制点

    Returns:
        list: 曲线点的序列
    """
    dt = tg
    t = []
    v = []
    t[0] = 0.
    t[1] = dt
    t[2] = 1.0 - dt
    t[3] = 1.0
    for i in range(len(t)):
        s = 1 - t[i]
        x = (p0[0] * s * s * s * s * s
             + 5.0 * p1[0] * s * s * s * s * t
             + 10.0 * p2[0] * s * s * s * t * t
             + 10.0 * p3[0] * s * s * t * t * t
             + 5.0 * p4[0] * s * t * t * t * t
             + p5[0] * t * t * t * t * t)
        y = (p0[1] * s * s * s * s * s
             + 5.0 * p1[1] * s * s * s * s * t
             + 10.0 * p2[1] * s * s * s * t * t
             + 10.0 * p3[1] * s * s * t * t * t
             + 5.0 * p4[1] * s * t * t * t * t
             + p5[1] * t * t * t * t * t)
        v.append([x, y])
    return v


def f4Order(p0, p1, p2, p3, p4):
    dt = tg
    t = np.arange(0, 1.0, dt)
    s = 1 - t

    x = (p0[0] * s ** 4
         + 4.0 * p1[0] * s ** 3 * t
         + 6.0 * p2[0] * s ** 2 * t ** 2
         + 4.0 * p3[0] * s * t ** 3
         + p4[0] * t ** 4)

    y = (p0[1] * s ** 4
         + 4.0 * p1[1] * s ** 3 * t
         + 6.0 * p2[1] * s ** 2 * t ** 2
         + 4.0 * p3[1] * s * t ** 3
         + p4[1] * t ** 4)

    v = np.column_stack((x, y))
    return v


def f3Order(p0, p1, p2, p3):
    dt = tg
    t = np.arange(0, 1.0, dt)
    s = 1 - t

    x = (p0[0] * s ** 3
         + 3.0 * p1[0] * s ** 2 * t
         + 3.0 * p2[0] * s * t ** 2
         + p3[0] * t ** 3)

    y = (p0[1] * s ** 3
         + 3.0 * p1[1] * s ** 2 * t
         + 3.0 * p2[1] * s * t ** 2
         + p3[1] * t ** 3)

    v = np.column_stack((x, y))
    return v


def f2Order(p0, p1, p2):
    dt = tg
    t = np.arange(0, 1.0, dt)
    s = 1 - t

    x = (p0[0] * s ** 2
         + 2.0 * p1[0] * s * t
         + p2[0] * t ** 2)

    y = (p0[1] * s ** 2
         + 2.0 * p1[1] * s * t
         + p2[1] * t ** 2)

    v = np.column_stack((x, y))
    return v


def curve(xdpts, ydpts, xddpts, yddpts):
    """依据参数方程获得曲率

    Args:
        xdpts (list): 对x的导数
        ydpts (list): 对y的导数
        xddpts (list): 对x的二阶导数read

    Returns:
        list: 曲率
    """
    cross = xdpts * yddpts - ydpts * xddpts
    k = cross / np.power(np.abs(xdpts + 1j * ydpts), 3)
    return k


def geoCurve(points):
    points = np.array(points)
    n = len(points)
    k = np.zeros(n)

    dxi = np.diff(points, axis=0)
    dxi_norm = np.linalg.norm(dxi, axis=1)
    dxi_norm[dxi_norm < 1e-6] = 1e-6

    dxip1 = dxi[1:]

    cross_value = dxi[:-1, 0] * dxip1[:, 1] - dxi[:-1, 1] * dxip1[:, 0]
    dot_value = dxi[:-1, 0] * dxip1[:, 0] + dxi[:-1, 1] * dxip1[:, 1]

    dphi = np.arctan2(cross_value, dot_value)

    k[1:-1] = dphi / dxi_norm[1:]
    k[0] = 2 * k[1] - k[2]
    k[-1] = 2 * k[-2] - k[-3]

    return k


def computeCurvatureChange(dx, ddx, dddx, dy, ddy, dddy):
    # 根据参数方程求解曲率变化率的解析解
    a = dx * ddy - dy * ddx
    b = dx * dddy - dy * dddx
    c = dx * ddx + dy * ddy
    d = dx * dx + dy * dy
    return abs((b * d - 3.0 * a * c) / (d * d * d))


def df5OrderAtT(control_points, t):
    """
    高级贝塞尔曲线求解位于t处的点的导函数值
    Args:
        p0: 控制点一的坐标
        p1: 控制点二的坐标
        p2: 控制点三的坐标
        p3: 控制点四的坐标
        p4: 控制点五的坐标
        p5: 控制点六的坐标
        t: 参数方程参数t

    Returns:

    """
    dpoints = np.diff(control_points, axis=0) * 5
    s = 1 - t
    dx = (dpoints[0][0] * s * s * s * s
          + 4.0 * dpoints[1][0] * s * s * s * t
          + 6.0 * dpoints[2][0] * s * s * t * t
          + 4.0 * dpoints[3][0] * s * t * t * t
          + dpoints[4][0] * t * t * t * t)
    dy = (dpoints[0][1] * s * s * s * s
          + 4.0 * dpoints[1][1] * s * s * s * t
          + 6.0 * dpoints[2][1] * s * s * t * t
          + 4.0 * dpoints[3][1] * s * t * t * t
          + dpoints[4][1] * t * t * t * t)
    return [dx, dy]


def simpson38(func, L, R, control_points):
    """
    使用3/8辛普森算法求高级贝塞尔曲线弧长，
    Args:
        func:
        L:
        R:

    Returns:

    """
    mid_L = (2 * L + R) / 3.0
    mid_R = (L + 2 * R) / 3.0
    dx = (func(control_points, L)[0] +
          3.0 * func(control_points, mid_L)[0] +
          3.0 * func(control_points, mid_R)[0] +
          func(control_points, R)[0]) * (R - L) / 8.0
    dy = (func(control_points, L)[1] +
          3.0 * func(control_points, mid_L)[1] +
          3.0 * func(control_points, mid_R)[1] +
          func(control_points, R)[1]) * (R - L) / 8.0
    return math.pow(dx ** 2 + dy ** 2, 0.5)


def adaptiveSimpson38(func, L, R, control_points, eps=0.05):
    """
    自适应辛普森算法求高级贝塞尔曲线弧长
    Args:
        func:
        L:
        R:
        eps:

    Returns:

    """
    mid = (L + R) / 2.0
    ST = simpson38(func, L, R, control_points)
    SL = simpson38(func, L, mid, control_points)
    SR = simpson38(func, mid, R, control_points)
    ans = SL + SR - ST
    if (abs(ans) <= 15.0 * eps):
        return SL + SR + ans / 15.0
    return adaptiveSimpson38(func, L, mid, control_points, eps / 2.0) + adaptiveSimpson38(func, mid, R, control_points,
                                                                                          eps / 2.0)


def find_intersection(x1, y1, theta1, x2, y2, theta2):
    # 计算两条射线的参数
    cos_theta1 = math.cos(theta1)
    sin_theta1 = math.sin(theta1)
    cos_theta2 = math.cos(theta2)
    sin_theta2 = math.sin(theta2)

    # 解方程
    determinant = cos_theta1 * sin_theta2 - cos_theta2 * sin_theta1

    if abs(determinant) < 1e-6:  # 如果行列式接近零，说明射线平行或重叠
        return False

    t = ((x2 - x1) * sin_theta2 - (y2 - y1) * cos_theta2) / determinant
    s = ((x2 - x1) * sin_theta1 - (y2 - y1) * cos_theta1) / determinant

    if t >= 0 and s >= 0:  # 确保t和s都是非负的
        intersection_x = x1 + t * cos_theta1
        intersection_y = y1 + t * sin_theta1
        return (intersection_x, intersection_y)
    else:
        return False

def computeSmoothingCostInit(points, control_points):
    # dpoints = np.diff(control_points, axis=0) * 5
    # dsamp_point = f4Order(dpoints[0], dpoints[1], dpoints[2], dpoints[3], dpoints[4])
    #
    # ddpoints = np.diff(dpoints, axis=0) * 4
    # ddsamp_point = f3Order(ddpoints[0], ddpoints[1], ddpoints[2], ddpoints[3])
    #
    # dddpoints = np.diff(ddpoints, axis=0) * 3
    # dddsamp_point = f2Order(dddpoints[0], dddpoints[1], dddpoints[2])
    #
    # dkappas = np.array(
    #     [computeCurvatureChange(dsamp_point[i][0], ddsamp_point[i][0], dddsamp_point[i][0], dsamp_point[i][1],
    #                             ddsamp_point[i][1], dddsamp_point[i][1]) for i in range(len(points))])
    #
    # jiaquan_kappas = np.abs(curve(dsamp_point[:, 0], dsamp_point[:, 1], ddsamp_point[:, 0], ddsamp_point[:, 1]))

    jiaquan_kappas = np.abs(geoCurve(points))
    # 计算点之间的差值
    diff = np.diff(points, axis=0)
    # 计算差值的平方和
    squared_sum = np.sum(diff ** 2, axis=1)
    # 计算欧几里得距离
    distances = np.sqrt(squared_sum)
    arclength = np.sum(distances)
    dkappas = np.abs(np.diff(jiaquan_kappas)) / distances

    dkappa_mean = np.mean(dkappas)
    jiaquan_kappa_max = np.max(jiaquan_kappas)

    return (jiaquan_kappa_max + dkappa_mean + arclength / total_samp_points, jiaquan_kappa_max, dkappa_mean, arclength)

def computeSmoothingCostEccentric(points, control_points):
    # dpoints = np.diff(control_points, axis=0) * 5
    # dsamp_point = f4Order(dpoints[0], dpoints[1], dpoints[2], dpoints[3], dpoints[4])
    #
    # ddpoints = np.diff(dpoints, axis=0) * 4
    # ddsamp_point = f3Order(ddpoints[0], ddpoints[1], ddpoints[2], ddpoints[3])
    #
    # dddpoints = np.diff(ddpoints, axis=0) * 3
    # dddsamp_point = f2Order(dddpoints[0], dddpoints[1], dddpoints[2])
    #
    # dkappas = np.array(
    #     [computeCurvatureChange(dsamp_point[i][0], ddsamp_point[i][0], dddsamp_point[i][0], dsamp_point[i][1],
    #                             ddsamp_point[i][1], dddsamp_point[i][1]) for i in range(len(points))])
    #
    # jiaquan_kappas = np.abs(curve(dsamp_point[:, 0], dsamp_point[:, 1], ddsamp_point[:, 0], ddsamp_point[:, 1]))

    jiaquan_kappas = np.abs(geoCurve(points))
    # 计算点之间的差值
    diff = np.diff(points, axis=0)
    # 计算差值的平方和
    squared_sum = np.sum(diff ** 2, axis=1)
    # 计算欧几里得距离
    distances = np.sqrt(squared_sum)
    arclength = np.sum(distances)
    dkappas = np.abs(np.diff(jiaquan_kappas)) / distances

    dkappa_mean = np.mean(dkappas)
    jiaquan_kappa_max = np.max(jiaquan_kappas)

    return (weight_kappa * jiaquan_kappa_max/init_kappa + weight_dkappa * dkappa_mean/init_dkappa + weight_distance * arclength / total_samp_points / init_length, jiaquan_kappa_max, dkappa_mean, arclength)


def computeTimeCostEccentric(points, control_points):
    jiaquan_kappas = np.abs(geoCurve(points))

    # 计算点之间的差值
    diff = np.diff(points, axis=0)
    # 计算差值的平方和
    squared_sum = np.sum(diff ** 2, axis=1)
    # 计算欧几里得距离
    distances = np.sqrt(squared_sum)
    # 计算线路长度
    arclength = np.sum(distances)

    dkappas = np.abs(np.diff(jiaquan_kappas)) / distances

    dkappa_mean = np.mean(dkappas)
    kappa_max = np.max(dkappas)

    return (dkappa_mean + arclength / total_samp_points, kappa_max, dkappas)


def computeTimeOptCost(points, control_points):
    """
    计算时间最优代价，考虑单舵轮车执行机构的转向和加速能力，为了减少约束的引入，考虑最大速度和最大加速度， 并且默认速度规划是依据曲率计算舵轮角度
    这里默认车辆全程保持最大线速度行驶，舵轮角速度初始值为0
    :param points: 路径采样点
    :param control_points: 控制点
    :return:
    """
    dpoints = np.diff(control_points, axis=0) * 5
    dsamp_point = f4Order(dpoints[0], dpoints[1], dpoints[2], dpoints[3], dpoints[4])
    # 计算采样点处的二阶导数值
    ddpoints = np.diff(dpoints, axis=0) * 4
    ddsamp_point = f3Order(ddpoints[0], ddpoints[1], ddpoints[2], ddpoints[3])
    # 分段线路还是简化成直线吧，比较简单
    # 计算分段线路长度
    length = []
    for i in range(len(points) - 1):
        length_seg = math.sqrt((points[i + 1][0] - points[i][0]) ** 2 + (points[i + 1][1] - points[i][1]) ** 2)
        length.append(length_seg)
    # 计算各点处的曲率，用于计算线路长度和舵角
    kappa = []
    for i in range(len(points)):
        kpath = abs(curve(dsamp_point[i][0], dsamp_point[i][1], ddsamp_point[i][0], ddsamp_point[i][1]))
        kappa.append(kpath)
    # 计算各点处的舵角
    rangle = []
    for i in range(len(kappa)):
        rangle_pt = math.atan(kappa[i] * L)
        rangle.append(rangle_pt)
    # 计算在每一段线路在舵角转速约束下的耗时
    t = []
    for i in range(len(rangle) - 1):
        t_seg = math.fabs(rangle[i + 1] - rangle[i]) / max_vw
        t.append(t_seg)
    # 计算约束下的最大速度和总耗时
    total_t = 0.
    for i in range(len(t)):
        v_dream = length[i] / t[i]
        if v_dream > max_vx:
            t[i] = length[i] / max_vx
        total_t = total_t + t[i]
    return total_t


def calculateInitialValuePoint(sepoints, theta, search_dis1, search_dis2):
    """
    通过搜索计算最小曲率变化率代价
    :param points: 起点和终点位置
    :param theta: 直线的倾角
    :return: 最优控制距离
    """
    step1 = search_dis1/20
    step2 = search_dis2/20
    start = 0.05
    end_1 = search_dis1
    end_2 = search_dis2
    dis1 = [start + i * step1 for i in range(int((end_1 - start) / step1) + 1)]
    dis2 = [start + i * step2 for i in range(int((end_2 - start) / step2) + 1)]
    min_cost = 1e10
    for i in range(len(dis1)):
        for j in range(len(dis2)):
            # 计算在控制距离dis1和dis2下的采样点
            points = f5OrderByDis(sepoints[0], sepoints[1], dis1[i], dis2[j], theta[0], theta[1])
            # 计算在控制距离dis1和dis2下的曲率变化率之和 points[0] 采样点  points[1] 控制点
            cur_cost, kappa, dkappa, length = computeSmoothingCostInit(points[0], points[1])
            if min_cost > cur_cost:
                min_cost = cur_cost
                global init_distance1, init_distance2, init_kappa, init_dkappa, init_length
                init_distance1 = dis1[i]
                init_distance2 = dis2[i]
                init_kappa = kappa
                init_dkappa = dkappa
                init_length = length


def gradientDescentCurvatureSumMinEccentric(sepoints, theta):
    """使用梯度下降计算最优控制点

    Args:
        sepoints(list):起点和终点的位置
        theta(list)   : 曲线的偏转角度[-pi,pi]

    Returns:
        list: [控制点一，控制点二]
    """
    global total_samp_points
    total_samp_points = 1001
    global tg
    tg = 1 / (total_samp_points - 1)
    sedistance = math.sqrt(abs(sepoints[0][0] - sepoints[1][0]) ** 2 + abs(sepoints[0][1] - sepoints[1][1]) ** 2)
    # 设置搜索起点 dis1 dis2 和 下降步长, 收敛条件 最大迭代次数
    # 步长 设置在1e-3时，跳过最优解，目前的看来似乎补偿设置为2*1e-4 ~ 5*1e-4之间可以保持相对稳定
    # 先搜索，确定一个相对优秀的初始距离,搜索步长是10cm，最大搜索距离是两米或者凸空间的极限
    res = find_intersection(sepoints[0][0], sepoints[0][1], theta[0], sepoints[1][0], sepoints[1][1], theta[1])
    search_dist1 = 2.0
    search_dist2 = 2.0
    dis_to_start = 2.0
    dis_to_end = 2.0
    if res:
        # print(res)
        dis_to_start = math.sqrt((sepoints[0][0] - res[0]) ** 2 + (sepoints[0][1] - res[1]) ** 2)
        dis_to_end = math.sqrt((sepoints[1][0] - res[0]) ** 2 + (sepoints[1][1] - res[1]) ** 2)
        search_dist1 = min(dis_to_start, 2.0)
        search_dist2 = min(dis_to_end, 2.0)
        print(dis_to_start,dis_to_end)
    calculateInitialValuePoint(sepoints, theta, search_dist1, search_dist2)
    dis1, dis2 = init_distance1, init_distance2
    if sedistance > 1.5:
        step = 0.002 * math.exp(sedistance)
        it_stop = 2e-4
    elif sedistance > 0.5:
        step = 0.0002 * math.exp(sedistance)
        it_stop = 1e-4
    else:
        step = 0.00002 * sedistance
        it_stop = 1e-6
    dis_pre1, dis_pre2 = 1.0, 1.0
    control_points = np.zeros(total_samp_points)
    points = np.zeros(total_samp_points)
    max_it, it = 300, 0
    while (abs(dis_pre1 - dis1) > it_stop or abs(dis_pre2 - dis2)) > it_stop and it < max_it:
        it += 1
        dis_pre1, dis_pre2 = dis1, dis2
        # 计算在控制距离dis1和dis2下的采样点
        points = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis2, theta[0], theta[1])
        # 计算在控制距离dis1和dis2下的曲率变化率之和 points[0] 采样点  points[1] 控制点
        # 我们希望dis2的取值尽可能更大一些
        cur_cost = computeSmoothingCostEccentric(points[0], points[1])[0]
        # print("dis1 = ", dis1, ", dis2 = ", dis2, ",cur_cost = ", cur_cost)
        # cur_cost = computeSmoothingCostDe(points[0],points[1])
        control_points = points[1]
        # 计算dis-eps,dis+eps时的曲率变化率之和
        eps = 1e-6
        dis_increase1, dis_decrease1, dis_increase2, dis_decrease2 = dis1 + eps, dis1 - eps, dis2 + eps, dis2 - eps
        points_increase1 = f5OrderByDis(sepoints[0], sepoints[1], dis_increase1, dis2, theta[0], theta[1])
        points_decrease1 = f5OrderByDis(sepoints[0], sepoints[1], dis_decrease1, dis2, theta[0], theta[1])
        points_increase2 = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis_increase2, theta[0], theta[1])
        points_decrease2 = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis_decrease2, theta[0], theta[1])
        cost_increase1 = computeSmoothingCostEccentric(points_increase1[0], points_increase1[1])[0]
        cost_decrease1 = computeSmoothingCostEccentric(points_decrease1[0], points_decrease1[1])[0]
        cost_increase2 = computeSmoothingCostEccentric(points_increase2[0], points_increase2[1])[0]
        cost_decrease2 = computeSmoothingCostEccentric(points_decrease2[0], points_decrease2[1])[0]
        # 计算在dis1,dis2两个方向上的梯度
        gradient1 = (cost_increase1 - cost_decrease1) / (2 * eps)
        gradient2 = (cost_increase2 - cost_decrease2) / (2 * eps)
        # print("gradient1 = ", gradient1, " ,gradient2 = ", gradient2)
        #
        dis1 = dis1 - gradient1 * step
        dis2 = dis2 - gradient2 * step
    # 对比一下曲率计算
    # xl, yl, cl2 = [], [], []
    # for i in range(len(points[0])):
    #     xl.append(points[0][i][0])
    #     yl.append(points[0][i][1])

    # 如果计算出来的距离小于0，说明极值点在另一侧，不适合梯度下降，使用搜索结果
    print(dis1,dis2)
    if dis1 < 0. or dis2 < 0. or dis1 > 1000. or dis2 > 1000.:
        dis1 = init_distance1
        dis2 = init_distance2
        points = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis2, theta[0], theta[1])
        control_points = points[1]
    return control_points, cur_cost, it


def gradientDescentTime(sepoints, theta):
    """使用梯度下降计算最优控制点

    Args:
        sepoints(list):起点和终点的位置
        theta(list)   : 曲线的偏转角度[-pi,pi]

    Returns:
        list: [控制点一，控制点二]
    """
    global total_samp_points
    total_samp_points = 1001
    global tg
    tg = 1 / (total_samp_points - 1)
    sedistance = math.sqrt(abs(sepoints[0][0] - sepoints[1][0]) ** 2 + abs(sepoints[0][1] - sepoints[1][1]) ** 2)
    # 设置搜索起点 dis1 dis2 和 下降步长, 收敛条件 最大迭代次数
    # 步长 设置在1e-3时，跳过最优解，目前的看来似乎补偿设置为2*1e-4 ~ 5*1e-4之间可以保持相对稳定
    dis1, dis2 = 0.2 * sedistance, 0.2 * sedistance
    if sedistance > 1.5:
        step = 0.002 * math.exp(sedistance)
        it_stop = 2e-4
    elif sedistance > 0.5:
        step = 0.0002 * math.exp(sedistance)
        it_stop = 1e-4
    else:
        step = 0.00002 * sedistance
        it_stop = 1e-6
    dis_pre1, dis_pre2 = 1.0, 1.0
    control_points = []
    points = []
    max_it, it = 300, 0
    while (abs(dis_pre1 - dis1) > it_stop or abs(dis_pre2 - dis2)) > it_stop and it < max_it:
        # print("dis1 = ",dis1, ", dis2 = ",dis2)
        it += 1
        dis_pre1, dis_pre2 = dis1, dis2
        # 计算在控制距离dis1和dis2下的采样点
        points = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis2, theta[0], theta[1])
        # 计算在控制距离dis1和dis2下的曲率变化率之和 points[0] 采样点  points[1] 控制点
        # 我们希望dis2的取值尽可能更大一些
        cur_cost, _, _ = computeTimeCostEccentric(points[0], points[1])
        # cur_cost = computeTimeOptCost(points[0], points[1])
        # cur_cost = computeSmoothingCostDe(points[0],points[1])
        control_points = points[1]
        # 计算dis-eps,dis+eps时的曲率变化率之和
        eps = 1e-7
        dis_increase1, dis_decrease1, dis_increase2, dis_decrease2 = dis1 + eps, dis1 - eps, dis2 + eps, dis2 - eps
        points_increase1 = f5OrderByDis(sepoints[0], sepoints[1], dis_increase1, dis2, theta[0], theta[1])
        points_decrease1 = f5OrderByDis(sepoints[0], sepoints[1], dis_decrease1, dis2, theta[0], theta[1])
        points_increase2 = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis_increase2, theta[0], theta[1])
        points_decrease2 = f5OrderByDis(sepoints[0], sepoints[1], dis1, dis_decrease2, theta[0], theta[1])
        cost_increase1, _, _ = computeTimeCostEccentric(points_increase1[0], points_increase1[1])
        cost_decrease1, _, _ = computeTimeCostEccentric(points_decrease1[0], points_decrease1[1])
        cost_increase2, _, _ = computeTimeCostEccentric(points_increase2[0], points_increase2[1])
        cost_decrease2, _, _ = computeTimeCostEccentric(points_decrease2[0], points_decrease2[1])
        # cost_increase1 = computeTimeOptCost(points_increase1[0], points_increase1[1])
        # cost_decrease1 = computeTimeOptCost(points_decrease1[0], points_decrease1[1])
        # cost_increase2 = computeTimeOptCost(points_increase2[0], points_increase2[1])
        # cost_decrease2 = computeTimeOptCost(points_decrease2[0], points_decrease2[1])
        # 计算在dis1,dis2两个方向上的梯度
        gradient1 = (cost_increase1 - cost_decrease1) / (2 * eps)
        gradient2 = (cost_increase2 - cost_decrease2) / (2 * eps)
        #
        dis1 = dis1 - gradient1 * step
        dis2 = dis2 - gradient2 * step
    # 对比一下曲率计算
    # xl, yl, cl2 = [], [], []
    # for i in range(len(points[0])):
    #     xl.append(points[0][i][0])
    #     yl.append(points[0][i][1])
    # plt.figure()
    # plt.plot(xl,yl)
    # plt.show()

    return control_points, cur_cost, it


def optimizeBeziertTime(target_line, theta1, theta2):
    """
    单纯的优化一条贝塞尔曲线，要求起点和终点的点位必须带有方向，没有方向的点位将取默认值
    Args:
        start_name: 起点点位
        end_name: 终点点位

    Returns:

    """
    startLM_pos = target_line["startPos"]["pos"]
    endLM_pos = target_line["endPos"]["pos"]
    spoint = [startLM_pos["x"], startLM_pos["y"]]
    epoint = [endLM_pos["x"], endLM_pos["y"]]
    sepoint = [spoint, epoint]
    # 处理单双线路的还缺
    control_points, _, it = gradientDescentTime(sepoint, [theta1, theta2])
    # if it >= 300: # 说明梯度下降算法没能收敛
    control1 = {"x": control_points[2][0], "y": control_points[2][1]}
    control2 = {"x": control_points[3][0], "y": control_points[3][1]}

    target_line["controlPos1"] = control1
    target_line["controlPos2"] = control2
    return control1, control2


def optimizeBeziertSmooth(target_line, theta1, theta2):
    """
    单纯的优化一条贝塞尔曲线，要求起点和终点的点位必须带有方向，没有方向的点位将取默认值
    Args:
        start_name: 起点点位
        end_name: 终点点位

    Returns:

    """
    startLM_pos = target_line["startPos"]["pos"]
    endLM_pos = target_line["endPos"]["pos"]
    spoint = [startLM_pos["x"], startLM_pos["y"]]
    epoint = [endLM_pos["x"], endLM_pos["y"]]
    sepoint = [spoint, epoint]
    # 处理单双线路的还缺
    control_points, _, it = gradientDescentCurvatureSumMinEccentric(sepoint, [theta1, theta2])
    # if it >= 300: # 说明梯度下降算法没能收敛
    control1 = {"x": control_points[2][0], "y": control_points[2][1]}
    control2 = {"x": control_points[3][0], "y": control_points[3][1]}

    target_line["controlPos1"] = control1
    target_line["controlPos2"] = control2
    return control1, control2


def optimizeBeziertL(start_point, end_point, theta1, theta2):
    """
    单纯的优化一条贝塞尔曲线，要求起点和终点的点位必须带有方向，没有方向的点位将取默认值
    Args:
        start_name: 起点点位
        end_name: 终点点位

    Returns:

    """
    startLM_pos = start_point
    endLM_pos = end_point
    spoint = [startLM_pos["x"], startLM_pos["y"]]
    epoint = [endLM_pos["x"], endLM_pos["y"]]
    sepoint = [spoint, epoint]
    # 处理单双线路的还缺
    control_points, _, it = gradientDescentTime(sepoint, [theta1, theta2])
    # if it >= 300: # 说明梯度下降算法没能收敛
    control1 = {"x": control_points[2][0], "y": control_points[2][1]}
    control2 = {"x": control_points[3][0], "y": control_points[3][1]}

    return control1, control2


def save(target_line, save_path = ''):
    map = target_line
    with open(save_path, 'w', encoding="utf-8") as f:
        js.dump(map, f, indent=4, ensure_ascii=False)


def getPathDir(l):
    """
    计算线路方向 rad
    Args:
        l: 线路名称

    Returns: 线路方向 rad

    """
    start_x = l["startPos"]["pos"].get("x", 0)
    start_y = l["startPos"]["pos"].get("y", 0)
    end_x = l["endPos"]["pos"].get("x", 0)
    end_y = l["endPos"]["pos"].get("y", 0)
    return math.atan2(end_y - start_y, end_x - start_x)


def getPathDirDB(l, forward):
    """

    Args:
        l: 高级贝塞尔曲线
        forward: 是否计算起点方向

    Returns: 方向

    """
    theta = 0.
    cp0 = [l["startPos"]["pos"]["x"], l["startPos"]["pos"]["y"]]
    cp1 = [l["controlPos1"]["x"], l["controlPos1"]["y"]]
    cp2 = [l["controlPos2"]["x"], l["controlPos2"]["y"]]
    cp3 = [l["endPos"]["pos"]["x"], l["endPos"]["pos"]["y"]]
    if forward:
        p1 = f5OrderAtT(cp0, cp1, cp1, cp2, cp2, cp3, 0.001)
        theta = math.atan2(cp0[1] - p1[1], cp0[0] - p1[0])
    else:
        p1 = f5OrderAtT(cp0, cp1, cp1, cp2, cp2, cp3, 0.999)
        theta = math.atan2(cp3[1] - p1[1], cp3[0] - p1[0])
    return theta


def getPathDirB(l, forward):
    """

    Args:
        l: 高级贝塞尔曲线
        forward: 是否计算起点方向

    Returns: 方向

    """
    theta = 0.
    cp0 = [l["startPos"]["pos"]["x"], l["startPos"]["pos"]["y"]]
    cp1 = [l["controlPos1"]["x"], l["controlPos1"]["y"]]
    cp2 = [l["controlPos2"]["x"], l["controlPos2"]["y"]]
    cp3 = [l["endPos"]["pos"]["x"], l["endPos"]["pos"]["y"]]
    if forward:
        p1 = f3OrderAtT(cp0, cp1, cp2, cp3, 0.001)
        theta = math.atan2(cp0[1] - p1[1], cp0[0] - p1[0])
    else:
        p1 = f3OrderAtT(cp0, cp1, cp2, cp3, 0.999)
        theta = math.atan2(cp3[1] - p1[1], cp3[0] - p1[0])
    return theta


def addPoint(lm1pos, lm2pos, L, name=None, dir=0):
    """
    添加一个和lm1，lm2共线，且距离lm2为1m的AP站点
    Args:
        lm1pos:
        lm2pos:
        L:
        name:

    Returns:

    """
    dist = math.hypot(lm1pos["x"] - lm2pos["x"], lm1pos["y"] - lm2pos["y"])
    lm4_pos = {"x": 0.0, "y": 0.0}
    lm4_pos["x"] = L / dist * (lm1pos["x"] - lm2pos["x"]) + lm2pos["x"]
    lm4_pos["y"] = L / dist * (lm1pos["y"] - lm2pos["y"]) + lm2pos["y"]
    return lm4_pos


def normalize_theta(theta):
    """弧度归一化

    Args:
        theta (_type_): 弧度

    Returns:
        _type_: _description_
    """
    if theta >= -math.pi and theta < math.pi:
        return theta
    multiplier = math.floor(theta / (2 * math.pi))
    theta = theta - multiplier * 2 * math.pi
    if theta >= math.pi:
        theta = theta - 2 * math.pi
    if theta < -math.pi:
        theta = theta + 2 * math.pi
    return theta


def optimizeItem(name=' ',save_path = ''):
    """
    读取图元文件
    Args:
        name: 图元文件的文件名称

    Returns:

    """
    target_line_name = " "
    optimize_type = ""
    items = []
    target_line1 = dict()
    target_line0 = dict()
    target_line = []
    points_list = []  # 图元中的点集, 完整格式
    lines_list = []  # 图元中的线集  完整格式
    lines_data_list = []  # json数据
    theta1, theta2 = 0., 0.  # 目标朝向
    bidirection = False  # 目标线路单双行的标志位
    org_js = dict()
    try:
        if os.path.exists(name) :
            with open(name, encoding='UTF-8') as fid:
                org_js = js.load(fid)
        else:
            print("Not found file")
    except UnicodeDecodeError as e:
        try:
            with open(name, encoding='gbk') as fid:
                org_js = js.load(fid)
        except UnicodeDecodeError as e:
            print(e)
    for v in org_js:
        if v == "type":
            optimize_type = org_js[v]
    if optimize_type == "optimizeLline":
        optimizeLline(org_js, target_line_name, target_line, points_list, lines_list, theta1, theta2, save_path)
    elif optimize_type == "optimizeCurve":
        optimizeCurve(org_js, target_line_name, target_line, target_line1, target_line0, points_list, lines_list,
                      lines_data_list, theta1, theta2, bidirection, save_path)
    elif optimize_type == "optimizeTline":
        optimizeTline(org_js, target_line_name, target_line, target_line1, target_line0, points_list, lines_list,
                      lines_data_list, theta1, theta2, bidirection,save_path)
    else:
        print("type is not legal :", optimize_type)


def optimizeCurve(org_js, target_line_name, target_line, target_line1, target_line0, points_list, lines_list,
                  lines_data_list, theta1, theta2, bidirection,save_path = ''):
    for v in org_js:
        if v == "selectedItems":
            target_line_name = org_js[v]
    for v in org_js:
        if v == "items":
            items = org_js[v]
            for i in range(len(items)):
                if items[i]["itemType"] == 1234:  # 线类型
                    target_line_json = items[i]["json"]
                    tmp_line = js.loads(target_line_json)
                    tmp_line0 = js.loads(tmp_line["data0"])
                    if tmp_line["direction"] == 2:
                        tmp_line1 = js.loads(tmp_line["data1"])
                        if tmp_line0["instanceName"] == target_line_name[0] or tmp_line1["instanceName"] == \
                                target_line_name[0]:  # 是需要优化的目标线段
                            target_line0 = js.loads(tmp_line["data0"])
                            target_line1 = js.loads(tmp_line["data1"])
                            target_line.append(items[i])
                            bidirection = True
                        else:
                            lines_data_list.append(tmp_line0)
                            lines_list.append(items[i])
                    elif tmp_line["direction"] == 1 or tmp_line["direction"] == 0:
                        if tmp_line0["instanceName"] == target_line_name[0]:  # 是需要优化的目标线段
                            target_line0 = js.loads(tmp_line["data0"])
                            target_line.append(items[i])
                        else:
                            lines_data_list.append(tmp_line0)
                            lines_list.append(items[i])
                if items[i]["itemType"] == 1232:  # 点类型，获取的意义只在于保存，方便写入结果
                    points_list.append(items[i])
            for i in range(len(lines_data_list)):
                # 获得目标方向
                if lines_data_list[i]["startPos"]["instanceName"] == target_line0["startPos"]["instanceName"]:
                    if lines_data_list[i]["className"] == "DegenerateBezier":
                        theta1 = normalize_theta(getPathDirDB(lines_data_list[i], True))
                    elif lines_data_list[i]["className"] == "StraightPath":
                        theta1 = normalize_theta(getPathDir(lines_data_list[i]) + math.pi)
                    elif lines_data_list[i]["className"] == "BezierPath":
                        theta1 = normalize_theta(getPathDirB(lines_data_list[i], True))
                    else:
                        theta1 = normalize_theta(getPathDir(lines_data_list[i]) + math.pi)
                elif lines_data_list[i]["endPos"]["instanceName"] == target_line0["startPos"]["instanceName"]:
                    if lines_data_list[i]["className"] == "DegenerateBezier":
                        theta1 = normalize_theta(getPathDirDB(lines_data_list[i], False))
                    elif lines_data_list[i]["className"] == "StraightPath":
                        theta1 = normalize_theta(getPathDir(lines_data_list[i]))
                    elif lines_data_list[i]["className"] == "BezierPath":
                        theta1 = normalize_theta(getPathDirB(lines_data_list[i], False))
                    else:
                        theta1 = normalize_theta(getPathDir(lines_data_list[i]))
                elif lines_data_list[i]["startPos"]["instanceName"] == target_line0["endPos"]["instanceName"]:
                    if lines_data_list[i]["className"] == "DegenerateBezier":
                        theta2 = normalize_theta(getPathDirDB(lines_data_list[i], True))
                    elif lines_data_list[i]["className"] == "StraightPath":
                        theta2 = normalize_theta(getPathDir(lines_data_list[i]) + math.pi)
                    elif lines_data_list[i]["className"] == "BezierPath":
                        theta2 = normalize_theta(getPathDirB(lines_data_list[i], True))
                    else:
                        theta2 = normalize_theta(getPathDir(lines_data_list[i]) + math.pi)
                elif lines_data_list[i]["endPos"]["instanceName"] == target_line0["endPos"]["instanceName"]:
                    if lines_data_list[i]["className"] == "DegenerateBezier":
                        theta2 = normalize_theta(getPathDirDB(lines_data_list[i], False))
                    elif lines_data_list[i]["className"] == "StraightPath":
                        theta2 = normalize_theta(getPathDir(lines_data_list[i]))
                    elif lines_data_list[i]["className"] == "BezierPath":
                        theta2 = normalize_theta(getPathDirB(lines_data_list[i], False))
                    else:
                        theta2 = normalize_theta(getPathDir(lines_data_list[i]))

                else:
                    print("Error path data", lines_data_list[i]["instanceName"])
    start_time = time.time()
    c1, c2 = optimizeBeziertSmooth(target_line0, theta1, theta2)
    end_time = time.time()
    elapsed_time = end_time - start_time
    #print(f"代码执行耗时：{elapsed_time}秒")
    if bidirection:
        target_line1["controlPos1"] = c2
        target_line1["controlPos2"] = c1
    if bidirection:
        data_dict = dict()

        data_dict["curve"] = "DegenerateBezier"

        str_data0 = js.dumps(target_line0, separators=(',', ':'), indent=4)
        data_dict["data0"] = str_data0

        str_data1 = js.dumps(target_line1, separators=(',', ':'), indent=4)
        str_data1_p1 = dict()
        data_dict["data1"] = str_data1

        data_dict["direction"] = 2

        data_dict = js.dumps(data_dict, separators=(',', ':'), indent=4)
    else:
        data_dict = dict()

        data_dict["curve"] = "DegenerateBezier"

        str_data0 = js.dumps(target_line0, separators=(',', ':'), indent=4)
        data_dict["data0"] = str_data0

        data_dict["direction"] = 1

        data_dict = js.dumps(data_dict, separators=(',', ':'), indent=4)

    target_line[0]["json"] = data_dict
    save(target_line,save_path)


def optimizeLline(org_js, max_line_length, target_line, points_list, lines_list, theta1, theta2, save_path = ''):
    maxID = 0
    for v in org_js:
        if v == "maxLineLength":
            max_line_length = org_js[v]
        if v == "maxId":
            maxID = org_js[v]
    for v in org_js:
        if v == "items":
            items = org_js[v]
            for i in range(len(items)):
                if items[i]["itemType"] == 1234:  # 线类型
                    lines_list.append(items[i])
                if items[i]["itemType"] == 1232:  # 点类型
                    points_list.append(items[i])
    # 判断中间站点和两侧站点
    mid_point = dict()
    mid_point_name = ""
    other_point1, other_point2 = dict(), dict()
    line1_json = js.loads(lines_list[0]["json"])
    line2_json = js.loads(lines_list[1]["json"])

    line1 = js.loads(line1_json["data0"])
    line2 = js.loads(line2_json["data0"])
    line1_ = dict()
    line2_ = dict()
    if line1_json["direction"] == 2:
        line1_ = js.loads(line1_json["data1"])
    if line2_json["direction"] == 2:
        line2_ = js.loads(line2_json["data1"])
    # 获取线路长度
    p1 = copy.deepcopy(line1["startPos"]["instanceName"])
    p2 = copy.deepcopy(line1["endPos"]["instanceName"])
    line1_length = math.sqrt((line1["startPos"]["pos"]["x"] - line1["endPos"]["pos"]["x"]) ** 2 + (
            line1["startPos"]["pos"]["y"] - line1["endPos"]["pos"]["y"]) ** 2)
    p3 = copy.deepcopy(line2["startPos"]["instanceName"])
    p4 = copy.deepcopy(line2["endPos"]["instanceName"])
    line2_length = math.sqrt((line2["startPos"]["pos"]["x"] - line2["endPos"]["pos"]["x"]) ** 2 + (
            line2["startPos"]["pos"]["y"] - line2["endPos"]["pos"]["y"]) ** 2)

    new_point1_pos, new_point2_pos = dict(), dict()
    LM1 = "LM" + str(maxID + 1)
    LM2 = "LM" + str(maxID + 2)
    seflag = ""
    # 获得线路方向, 更新直线线路
    if p1 == p3:
        seflag = "13"
        mid_point = copy.deepcopy(line1["startPos"])
        other_point1 = copy.deepcopy(line1["endPos"])
        other_point2 = copy.deepcopy(line2["endPos"])
        theta1 = normalize_theta(getPathDir(line1) + math.pi)
        theta2 = normalize_theta(getPathDir(line2) + math.pi)
        if line1_length > max_line_length:
            new_point1_pos = addPoint(other_point1["pos"], mid_point["pos"], max_line_length)
            line1["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
            line1["startPos"]["instanceName"] = LM1
            line1["instanceName"] = line1["startPos"]["instanceName"] + line1["endPos"]["instanceName"]
            if line1_json["direction"] == 2:
                line1_["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
                line1_["endPos"]["instanceName"] = LM1
                line1_["instanceName"] = line1_["startPos"]["instanceName"] + "-" + line1_["endPos"]["instanceName"]
        else:
            new_point1_pos = copy.deepcopy(other_point1["pos"])
            LM1 = line1["endPos"]["instanceName"]
        if line2_length > max_line_length:
            new_point2_pos = addPoint(other_point2["pos"], mid_point["pos"], max_line_length)
            line2["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
            line2["startPos"]["instanceName"] = LM2
            line2["instanceName"] = line2["startPos"]["instanceName"] + "-" + line2["endPos"]["instanceName"]
            if line2_json["direction"] == 2:
                line2_["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
                line2_["endPos"]["instanceName"] = LM2
                line2_["instanceName"] = line2_["startPos"]["instanceName"] + "-" + line2_["endPos"]["instanceName"]
        else:
            new_point2_pos = copy.deepcopy(other_point2["pos"])
            LM2 = line2["endPos"]["instanceName"]
    elif p1 == p4:
        seflag = "14"
        mid_point = copy.deepcopy(line1["startPos"])
        other_point1 = copy.deepcopy(line1["endPos"])
        other_point2 = copy.deepcopy(line2["startPos"])
        theta1 = normalize_theta(getPathDir(line1) + math.pi)
        theta2 = normalize_theta(getPathDir(line2))
        if line1_length > max_line_length:
            new_point1_pos = addPoint(other_point1["pos"], mid_point["pos"], max_line_length)
            line1["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
            line1["startPos"]["instanceName"] = LM1
            line1["instanceName"] = line1["startPos"]["instanceName"] + "-" + line1["endPos"]["instanceName"]
            if line1_json["direction"] == 2:
                line1_["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
                line1_["endPos"]["instanceName"] = LM1
                line1_["instanceName"] = line1_["startPos"]["instanceName"] + "-" + line1_["endPos"]["instanceName"]
        else:
            new_point1_pos = copy.deepcopy(other_point1["pos"])
            LM1 = line1["endPos"]["instanceName"]
        if line2_length > max_line_length:
            new_point2_pos = addPoint(other_point2["pos"], mid_point["pos"], max_line_length)
            line2["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
            line2["endPos"]["instanceName"] = LM2
            line2["instanceName"] = line2["startPos"]["instanceName"] + "-" + line2["endPos"]["instanceName"]
            if line2_json["direction"] == 2:
                line2_["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
                line2_["startPos"]["instanceName"] = LM2
                line2_["instanceName"] = line2_["startPos"]["instanceName"] + "-" + line2_["endPos"]["instanceName"]
        else:
            new_point2_pos = copy.deepcopy(other_point2["pos"])
            LM2 = line2["startPos"]["instanceName"]
    elif p2 == p3:
        seflag = "23"
        mid_point = copy.deepcopy(line1["endPos"])
        other_point1 = copy.deepcopy(line1["startPos"])
        other_point2 = copy.deepcopy(line2["endPos"])
        theta1 = normalize_theta(getPathDir(line1))
        theta2 = normalize_theta(getPathDir(line2) + math.pi)
        if line1_length > max_line_length:
            new_point1_pos = addPoint(other_point1["pos"], mid_point["pos"], max_line_length)
            line1["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
            line1["endPos"]["instanceName"] = LM1
            line1["instanceName"] = line1["startPos"]["instanceName"] + "-" + line1["endPos"]["instanceName"]
            if line1_json["direction"] == 2:
                line1_["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
                line1_["startPos"]["instanceName"] = LM1
                line1_["instanceName"] = line1_["startPos"]["instanceName"] + "-" + line1_["endPos"]["instanceName"]
        else:
            new_point1_pos = copy.deepcopy(other_point1["pos"])
            LM1 = line1["startPos"]["instanceName"]
        if line2_length > max_line_length:
            new_point2_pos = addPoint(other_point2["pos"], mid_point["pos"], max_line_length)
            line2["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
            line2["startPos"]["instanceName"] = LM2
            line2["instanceName"] = line2["startPos"]["instanceName"] + "-" + line2["endPos"]["instanceName"]
            if line2_json["direction"] == 2:
                line2_["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
                line2_["endPos"]["instanceName"] = LM2
                line2_["instanceName"] = line2_["startPos"]["instanceName"] + "-" + line2_["endPos"]["instanceName"]
        else:
            new_point2_pos = copy.deepcopy(other_point2["pos"])
            LM2 = line2["endPos"]["instanceName"]
    elif p2 == p4:
        seflag = "24"
        mid_point = copy.deepcopy(line1["endPos"])
        other_point1 = copy.deepcopy(line1["startPos"])
        other_point2 = copy.deepcopy(line2["startPos"])
        theta1 = normalize_theta(getPathDir(line1))
        theta2 = normalize_theta(getPathDir(line2))
        if line1_length > max_line_length:
            new_point1_pos = addPoint(other_point1["pos"], mid_point["pos"], max_line_length)
            line1["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
            line1["endPos"]["instanceName"] = LM1
            line1["instanceName"] = line1["startPos"]["instanceName"] + "-" + line1["endPos"]["instanceName"]
            if line1_json["direction"] == 2:
                line1_["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
                line1_["startPos"]["instanceName"] = LM1
                line1_["instanceName"] = line1_["startPos"]["instanceName"] + "-" + line1_["endPos"]["instanceName"]
        else:
            new_point1_pos = copy.deepcopy(other_point1["pos"])
            LM1 = line1["startPos"]["instanceName"]
        if line2_length > max_line_length:
            new_point2_pos = addPoint(other_point2["pos"], mid_point["pos"], max_line_length)
            line2["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
            line2["endPos"]["instanceName"] = LM2
            line2["instanceName"] = line2["startPos"]["instanceName"] + "-" + line2["endPos"]["instanceName"]
            if line2_json["direction"] == 2:
                line2_["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
                line2_["startPos"]["instanceName"] = LM2
                line2_["instanceName"] = line2_["startPos"]["instanceName"] + "-" + line2_["endPos"]["instanceName"]
        else:
            new_point2_pos = copy.deepcopy(other_point2["pos"])
            LM2 = line2["startPos"]["instanceName"]

    new_line = copy.deepcopy(lines_list[0])  # 新线路
    # 把修改后的原线路序列化回去
    if line1_length > max_line_length:
        str_line1_data0 = js.dumps(line1, separators=(',', ':'), indent=4)
        line1_json["data0"] = str_line1_data0
        if line1_json["direction"] == 2:
            str_line1_data1 = js.dumps(line1_, separators=(',', ':'), indent=4)
            line1_json["data1"] = str_line1_data1
        str_line1_json = js.dumps(line1_json, separators=(',', ':'), indent=4)
        lines_list[0]["json"] = str_line1_json
    else:
        lines_list.pop(0)
    if line2_length > max_line_length:
        str_line2_data0 = js.dumps(line2, separators=(',', ':'), indent=4)
        line2_json["data0"] = str_line2_data0
        if line2_json["direction"] == 2:
            str_line2_data1 = js.dumps(line2_, separators=(',', ':'), indent=4)
            line2_json["data1"] = str_line2_data1
        str_line2_json = js.dumps(line2_json, separators=(',', ':'), indent=4)
        if len(lines_list) == 1:
            lines_list[0]["json"] = str_line2_json
        else:
            lines_list[1]["json"] = str_line2_json
    else:
        if len(lines_list) == 1:
            lines_list.pop(0)
        elif len(lines_list) == 2:
            lines_list.pop(1)

    # 找到需要被删除的站点
    delete_point = dict()
    new_points_list = []
    for i in range(len(points_list)):
        point_json = js.loads(points_list[i]["json"])
        if point_json["instanceName"] == mid_point["instanceName"]:
            delete_point = copy.deepcopy(points_list[i])
        else:
            new_points_list.append(points_list[i])
    # 调用优化函数
    # start_time = time.time()
    c1, c2 = optimizeBeziertL(new_point1_pos, new_point2_pos, theta1, theta2)
    # end_time = time.time()
    # elapsed_time = end_time - start_time
    # print(f"代码执行耗时：{elapsed_time}秒")

    # 构造出新线路 和 新点位
    new_point1 = copy.deepcopy(delete_point)
    new_point2 = copy.deepcopy(delete_point)  # 新点位
    delete_point_json = js.loads(delete_point["json"])
    new_point1_json, new_point2_json = copy.deepcopy(delete_point_json), copy.deepcopy(delete_point_json)

    new_point1_json["pos"] = new_point1_pos
    new_point2_json["pos"] = new_point2_pos

    new_point1_json["instanceName"] = LM1
    new_point2_json["instanceName"] = LM2

    str_point1_json = js.dumps(new_point1_json, separators=(',', ':'), indent=4)
    str_point2_json = js.dumps(new_point2_json, separators=(',', ':'), indent=4)
    new_point1["json"] = str_point1_json
    new_point2["json"] = str_point2_json

    new_point1["centerPos"]["x"] = new_point1_pos["x"] * 100
    new_point2["centerPos"]["x"] = new_point2_pos["x"] * 100
    new_point1["centerPos"]["y"] = new_point1_pos["y"] * 100
    new_point2["centerPos"]["y"] = new_point2_pos["y"] * 100
    if line1_length > max_line_length:
        new_points_list.append(new_point1)
    else:
        LM1 = other_point1["instanceName"]
    if line2_length > max_line_length:
        new_points_list.append(new_point2)
    else:
        LM2 = other_point2["instanceName"]
    if line1_json["direction"] == 2 and line2_json["direction"] == 2:  # 新线路是双行线
        new_line_json = js.loads(new_line["json"])
        new_line_data0 = js.loads(new_line_json["data0"])
        new_line_data1 = js.loads(new_line_json["data1"])

        new_line_data0["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
        new_line_data0["startPos"]["instanceName"] = LM1
        new_line_data0["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
        new_line_data0["endPos"]["instanceName"] = LM2
        new_line_data0["controlPos1"] = c1
        new_line_data0["controlPos2"] = c2
        new_line_data0["className"] = "DegenerateBezier"
        new_line_data0["instanceName"] = LM1 + "-" + LM2

        new_line_data1["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
        new_line_data1["startPos"]["instanceName"] = LM2
        new_line_data1["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
        new_line_data1["endPos"]["instanceName"] = LM1
        new_line_data1["controlPos1"] = c2
        new_line_data1["controlPos2"] = c1
        new_line_data1["className"] = "DegenerateBezier"
        new_line_data0["instanceName"] = LM2 + "-" + LM1

        str_data0 = js.dumps(new_line_data0, separators=(',', ':'), indent=4)
        str_data1 = js.dumps(new_line_data1, separators=(',', ':'), indent=4)
        new_line_json["data0"] = str_data0
        new_line_json["data1"] = str_data1
        new_line_json["curve"] = "DegenerateBezier"

        str_json = js.dumps(new_line_json, separators=(',', ':'), indent=4)
        new_line["json"] = str_json
    elif line1_json["direction"] != 2:
        new_line_json = js.loads(new_line["json"])
        new_line_data0 = js.loads(new_line_json["data0"])
        if seflag == "13" or seflag == "14":
            new_line_data0["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
            new_line_data0["endPos"]["instanceName"] = LM1
            new_line_data0["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
            new_line_data0["startPos"]["instanceName"] = LM2
            new_line_data0["controlPos1"] = c2
            new_line_data0["controlPos2"] = c1
            new_line_data0["instanceName"] = LM2 + "-" + LM1
        else:
            new_line_data0["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
            new_line_data0["startPos"]["instanceName"] = LM1
            new_line_data0["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
            new_line_data0["endPos"]["instanceName"] = LM2
            new_line_data0["controlPos1"] = c1
            new_line_data0["controlPos2"] = c2
            new_line_data0["instanceName"] = LM1 + "-" + LM2
        new_line_data0["className"] = "DegenerateBezier"

        str_data0 = js.dumps(new_line_data0, separators=(',', ':'), indent=4)
        new_line_json = dict()
        new_line_json["data0"] = str_data0
        new_line_json["curve"] = "DegenerateBezier"
        new_line_json["direction"] = copy.deepcopy(line1_json["direction"])

        str_json = js.dumps(new_line_json, separators=(',', ':'), indent=4)
        new_line["json"] = str_json
    elif line2_json["direction"] != 2:
        new_line_json = js.loads(new_line["json"])
        new_line_data0 = js.loads(new_line_json["data0"])
        if seflag == "24" or seflag == "14":
            new_line_data0["endPos"]["pos"] = copy.deepcopy(new_point1_pos)
            new_line_data0["endPos"]["instanceName"] = LM1
            new_line_data0["startPos"]["pos"] = copy.deepcopy(new_point2_pos)
            new_line_data0["startPos"]["instanceName"] = LM2
            new_line_data0["controlPos1"] = c2
            new_line_data0["controlPos2"] = c1
            new_line_data0["instanceName"] = LM2 + "-" + LM1
        else:
            new_line_data0["startPos"]["pos"] = copy.deepcopy(new_point1_pos)
            new_line_data0["startPos"]["instanceName"] = LM1
            new_line_data0["endPos"]["pos"] = copy.deepcopy(new_point2_pos)
            new_line_data0["endPos"]["instanceName"] = LM2
            new_line_data0["controlPos1"] = c1
            new_line_data0["controlPos2"] = c2
            new_line_data0["instanceName"] = LM1 + "-" + LM2
        new_line_data0["className"] = "DegenerateBezier"
        str_data0 = js.dumps(new_line_data0, separators=(',', ':'), indent=4)
        new_line_json = dict()
        new_line_json["data0"] = str_data0
        new_line_json["curve"] = "DegenerateBezier"
        new_line_json["direction"] = copy.deepcopy(line2_json["direction"])

        str_json = js.dumps(new_line_json, separators=(',', ':'), indent=4)
        new_line["json"] = str_json
    lines_list.append(new_line)

    res_js = []
    for i in range(len(new_points_list)):
        res_js.append(new_points_list[i])
    for i in range(len(lines_list)):
        res_js.append(lines_list[i])

    with open(save_path, 'w', encoding="utf-8") as f:
        js.dump(res_js, f, indent=4, ensure_ascii=False)


def optimizeTline(org_js, target_line_name, target_line, target_line1, target_line0, points_list, lines_list,
                  lines_data_list, theta1, theta2, bidirection,save_path = ''):
    print()


#
# optimizeItem("testL.items")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(sys.argv[0], ", 未指定图元文件/文件目录")
    else:
        optimizeItem(sys.argv[1],sys.argv[2])
