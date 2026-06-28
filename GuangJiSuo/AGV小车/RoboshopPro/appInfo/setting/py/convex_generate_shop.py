# coding=utf-8
import json
import numpy as np
import sys
#from scipy.ndimage import binary_dilation

class GridMap:
    """栅格地图类，用于表示和处理二维障碍物地图"""

    def __init__(self, width, height, resolution=1.0, origin=(0, 0)):
        """
        初始化栅格地图

        参数:
            width: 地图宽度(栅格数)
            height: 地图高度(栅格数)
            resolution: 每个栅格的大小(米/栅格)
            origin: 地图原点坐标(x, y)
        """
        self.width = width
        self.height = height
        self.resolution = resolution
        self.origin = origin
        # 初始化栅格地图，0表示自由空间，1表示障碍物
        self.grid = np.zeros((height, width), dtype=np.int8)
        self.expansion_map = np.zeros((height, width), dtype=np.int8)
        for i in range(height):
            self.grid[i, 0] = 1
            self.grid[i,width-1] = 1
        for i in range(width):
            self.grid[0,i] = 1
            self.grid[height-1,i] = 1

    def world_to_grid(self, x, y):
        """将世界坐标转换为栅格坐标"""
        grid_x = int((x - self.origin[0]) / self.resolution)
        grid_y = int((y - self.origin[1]) / self.resolution)
        return grid_x, grid_y

    def grid_to_world(self, grid_x, grid_y):
        """将栅格坐标转换为世界坐标"""
        x = grid_x * self.resolution + self.origin[0]
        y = grid_y * self.resolution + self.origin[1]
        return x, y

    def is_inside(self, grid_x, grid_y):
        """检查栅格坐标是否在地图范围内"""
        return 0 <= grid_x < self.width and 0 <= grid_y < self.height

    def is_obstacle(self, grid_x, grid_y):
        """检查栅格是否为障碍物"""
        if not self.is_inside(grid_x, grid_y):
            return True  # 地图外默认为障碍物
        return self.grid[grid_y, grid_x] == 1

    def set_grid_obstacle(self, grid_x, grid_y):
        """设置栅格为障碍物"""
        if self.is_inside(grid_x, grid_y):
            self.grid[grid_y, grid_x] = 1

    def set_world_obstacle(self, world_x, world_y):
        """设置栅格为障碍物"""
        grid_x, grid_y = self.world_to_grid(world_x, world_y)
        if self.is_inside(grid_x, grid_y):
            self.grid[grid_y, grid_x] = 1

    def expansive_obstacle(self, expansion):
#        """使用形态学膨胀优化障碍物扩展"""
#        # 创建膨胀结构元素（正方形）
#        structure = np.ones((2 * expansion + 1, 2 * expansion + 1), dtype=bool)

#        # 使用binary_dilation进行高效膨胀
#        self.expansion_map = binary_dilation(
#            self.grid,
#            structure=structure,
#            iterations=1
#        ).astype(np.uint8)

        return self.grid


    def clear_obstacle(self, grid_x, grid_y):
        """清除栅格的障碍物"""
        if self.is_inside(grid_x, grid_y):
            self.grid[grid_y, grid_x] = 0

    def get_world_point_form_grid(self, grid_x, grid_y):
        world_x = grid_x * self.resolution + self.origin[0]
        world_y = grid_y * self.resolution + self.origin[1]
        return world_x, world_y

def fill_free_space_with_rectangles(obstacle_map, min_size=2):
    """
    在自由空间中填充最大矩形

    参数:
    obstacle_map: 障碍物地图 (0=自由空间, 1=障碍物)
    min_size: 最小矩形尺寸 (宽度或高度最小值)
    visualize: 是否可视化结果

    返回:
    rectangles: 填充的矩形列表 [(top, left, height, width), ...]
    coverage: 自由空间覆盖率
    """
    # 1. 确保输入是二值图像
    obstacle_map = np.where(obstacle_map > 0, 1, 0).astype(np.uint8)
    free_space = 1 - obstacle_map

    # 2. 计算自由空间面积
    total_free_area = np.sum(free_space)
    if total_free_area == 0:
        print("警告: 没有自由空间!")
        return [], 0.0

    # 3. 初始化工作地图
    work_map = free_space.copy()
    rectangles = []
    covered_area = 0

    # 4. 主循环 - 寻找并放置最大矩形
    while True:
        # 寻找最大矩形
        rect = find_largest_rectangle(work_map, min_size)

        # 如果没有找到合适的矩形，结束
        if rect is None:
            break

        top, left, height, width = rect
        area = height * width

        # 添加矩形到结果
        rectangles.append(rect)
        covered_area += area

        # 更新工作地图（将矩形区域置为0）
        work_map[top:top + height, left:left + width] = 0

        # 打印进度
        print(f"添加矩形: 位置({top},{left}), 尺寸{width}x{height}, 面积={area}像素")

    # 5. 计算覆盖率
    coverage = covered_area / total_free_area

    return rectangles, coverage

def find_largest_rectangle(free_map, min_size=2):
    """
    在自由空间地图中寻找最大矩形

    参数:
    free_map: 自由空间地图 (1=自由空间, 0=已覆盖或障碍)
    min_size: 最小矩形尺寸

    返回:
    (top, left, height, width) 或 None
    """
    # 获取地图尺寸
    rows, cols = free_map.shape

    # 初始化高度矩阵
    heights = np.zeros(cols, dtype=int)

    max_area = 0
    max_rect = None

    # 逐行处理
    for i in range(rows):
        # 更新高度数组
        heights = (heights + 1) * free_map[i]
        heights[free_map[i] == 0] = 0

        # 初始化左右边界数组
        left_bound = np.zeros(cols, dtype=int)
        right_bound = np.zeros(cols, dtype=int)

        # 计算左边界
        stack = []
        for j in range(cols):
            while stack and heights[stack[-1]] >= heights[j]:
                stack.pop()
            left_bound[j] = stack[-1] + 1 if stack else 0
            stack.append(j)

        # 计算右边界
        stack = []
        for j in range(cols - 1, -1, -1):
            while stack and heights[stack[-1]] >= heights[j]:
                stack.pop()
            right_bound[j] = stack[-1] - 1 if stack else cols - 1
            stack.append(j)

        # 计算每个位置的最大矩形面积
        for j in range(cols):
            h = heights[j]
            w = right_bound[j] - left_bound[j] + 1

            # 检查最小尺寸
            if h < min_size or w < min_size:
                continue

            area = h * w

            # 更新最大矩形
            if area > max_area:
                max_area = area
                max_rect = (i - h + 1, left_bound[j], h, w)
    return max_rect
def convert_numpy_data(data):
    """递归转换 NumPy 数据类型为 JSON 可序列化的基本类型"""
    if isinstance(data, (np.ndarray, np.generic)):
        return data.tolist()  # 将 NumPy 数组/标量转换为 Python 列表/标量
    elif isinstance(data, list):
        return [convert_numpy_data(item) for item in data]
    elif isinstance(data, tuple):
        return tuple(convert_numpy_data(item) for item in data)
    elif isinstance(data, dict):
        return {key: convert_numpy_data(value) for key, value in data.items()}
    return data

def create_and_save_json(file_path, data=None):
    """
    创建 JSON 数据并保存到文件

    参数:
    file_path (str): 保存 JSON 文件的路径
    data (dict, optional): 要保存的初始数据。默认为空字典。
    data = [(world_x, world_y, width, world_width, world_height),(),()...]
    返回:
    bool: 操作成功返回 True，失败返回 False
    """
    print("convex_data=", data)
    serializable_data = convert_numpy_data(data)
    print("serializable_data=", serializable_data)
    json_data = {}
    try:
        # 可嵌套其他数据结构
        json_data["convex"] = serializable_data
        # 将数据写入 JSON 文件
        with open(file_path, 'w', encoding='utf-8') as f:
            # ensure_ascii=False 确保中文等非 ASCII 字符正确保存
            # indent=2 使输出格式更美观
            json.dump(json_data, f, ensure_ascii=False, indent=2)

        print(f"JSON 数据已成功保存到 {file_path}")
        return True

    except Exception as e:
        print(f"保存 JSON 时出错: {e}")
        return False

if __name__ == "__main__":
    # 打开JSON文件（文件路径需正确）
    with open(sys.argv[1], 'r', encoding='utf-8') as f:
        # 解析JSON数据为Python字典
        data = json.load(f)
    # 打印解析后的内容
    print("解析后的Python对象类型:", type(data))  # <class 'dict'>
    print("header:", data['header'])
    print("mapType:", data['header']['mapType'])
    print("mapName:", data['header']['mapName'])
    print("minPos:", data['header']['minPos'])
    print("maxPos:", data['header']['maxPos'])
    print("resolution:", data['header']['resolution'])
    print("normalPosList:", len(data['normalPosList']))
    x_min = data['header']['minPos']['x']
    y_min = data['header']['minPos']['y']
    x_max = data['header']['maxPos']['x']
    y_max = data['header']['maxPos']['y']
    # resolution = data['header']['resolution']
    resolution = 0.2
    obstacles = data['normalPosList']
    width = int((x_max - x_min)/resolution)
    height = int((y_max - y_min)/resolution)
    # 创建一个10x10的栅格地图，每个栅格大小为1米
    grid_map = GridMap(width=width, height=height, resolution=resolution, origin=(x_min, y_min))
    for obstacle in obstacles:
        try:
            grid_map.set_world_obstacle(obstacle["x"], obstacle["y"])
        except:
            continue
    robot_radius = sys.argv[2]
#    expansion_map = grid_map.expansive_obstacle(int(robot_radius/resolution))

    # 填充自由空间
    rectangles, coverage = fill_free_space_with_rectangles(
        grid_map.grid,
        min_size=4
    )
    # 打印结果
    print(f"\n填充完成! 共使用 {len(rectangles)} 个矩形")
    print(f"自由空间覆盖率: {coverage:.2%}")
    convex_data = []
    for i, (top, left, height, width) in enumerate(rectangles):
        world_x, world_y = grid_map.get_world_point_form_grid(left, top)
        world_width = width * resolution
        world_height = height * resolution
        # print(f"矩形 {i + 1}: 位置({world_x},{world_y}), 尺寸{world_width}x{world_height}, 面积={width * height * resolution * resolution}")
        # print(f"矩形 {i + 1}: 位置({top},{left}), 尺寸{width}x{height}, 面积={width * height}像素")
        point0 = {"x": world_x, "y": world_y}
        point1 = {"x": world_x + world_width, "y": world_y}
        point2 = {"x": world_x + world_width, "y": world_y + world_height}
        point3 = {"x": world_x, "y": world_y + world_height}
        convex_data.append({"points": [point0, point1, point2, point3], "id": i + 1})
    print("convex_data=",convex_data)
    create_and_save_json(sys.argv[3], convex_data)
