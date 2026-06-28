#coding=utf-8
import copy
import json
import math
import numpy
import sys
sys.setrecursionlimit(1000000)

class Model:
    def __init__(self, shape, width, length):
        self.shape = shape
        self.width = width
        self.length = length


class Pos:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Pos(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Pos(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        return Pos(scalar * self.x, scalar * self.y)

    def __rmul__(self, scalar):
        return Pos(1 / scalar * self.x, 1 / scalar * self.y)


class CleanRect:
    def __init__(self, enter, polygon):
        self.enter = enter
        self.polygon = polygon


class CleanRobot:
    def __init__(self, model, cleanWidth, minTurnRadius, cleanRect, normalPosList, maxId):
        self.model = model
        self.cleanWidth = cleanWidth
        self.minTurnRadius = minTurnRadius
        self.cleanRect = cleanRect
        self.normalPosList = normalPosList
        self.maxId = maxId

        self.obstacleList = []
        self.setObstacleList()  # 提取边界和障碍物

        self.min_x_coord = 0  # 地图索引信息
        self.max_x_coord = 0
        self.min_y_coord = 0
        self.max_y_coord = 0
        self.min_x_index = 0
        self.max_x_index = 0
        self.min_y_index = 0
        self.max_y_index = 0
        self.setGridInfo()  # 设置栅格化信息

        self.gridMap = []  # 地图栅格化
        self.setGridMap()

    def setObstacleList(self):  # 将障碍物点 和 边界点 作为障碍物存起来
        for i in range(len(self.normalPosList)):
            self.obstacleList.append(self.normalPosList[i])
        for i in range(len(self.cleanRect.polygon)):  # 边界点需要考虑机器人宽度，不能稠密也不能太稀疏
            p1_index = i % len(self.cleanRect.polygon)
            p2_index = (i + 1) % len(self.cleanRect.polygon)
            p1 = self.cleanRect.polygon[p1_index]
            p2 = self.cleanRect.polygon[p2_index]
            dist = math.hypot(p1.x - p2.x, p1.y - p2.y)
            count = math.ceil(dist / self.cleanWidth) * 3  # 边界点不能太少
            self.obstacleList.append(p1)
            for j in range(count):
                self.obstacleList.append(p1 + (p2 - p1) * (j / count))

    def setGridInfo(self):
        x = []
        y = []
        for i in range(len(self.obstacleList)):
            x.append(self.obstacleList[i].x)
            y.append(self.obstacleList[i].y)
        self.min_x_coord = numpy.min(x)
        self.max_x_coord = numpy.max(x)
        self.min_y_coord = numpy.min(y)
        self.max_y_coord = numpy.max(y)
        self.min_x_index = 0
        self.min_y_index = 0
        self.max_x_index = math.ceil((self.max_x_coord - self.min_x_coord) / self.cleanWidth)
        self.max_y_index = math.ceil((self.max_y_coord - self.min_y_coord) / self.cleanWidth)

    def index2Coord(self, indPos):
        pos_x = self.min_x_coord +  indPos.x * self.cleanWidth # + 0.5 * self.cleanWidth 不应该加半宽
        pos_y = self.min_y_coord +  indPos.y * self.cleanWidth # + 0.5 * self.cleanWidth
        return Pos(pos_x, pos_y)

    def coord2Index(self, corPos):
        pos_x = int((corPos.x - self.min_x_coord) / self.cleanWidth)
        pos_y = int((corPos.y - self.min_y_coord) / self.cleanWidth)
        return Pos(pos_x, pos_y)

    def coordPath2IndexPath(self, pathIndex):
        pathCoord = []
        for i in range(len(pathIndex)):
            pathCoord.append(self.index2Coord(pathIndex[i]))
        return pathCoord

    def setGridMap(self):
        self.gridMap = [[0 for col in range(self.max_y_index + 1)] for raw in range(self.max_x_index + 1)]
        for i in range(len(self.obstacleList)):
            tmp_ind = self.coord2Index(self.obstacleList[i])
            self.gridMap[tmp_ind.x][tmp_ind.y] = 1

    def getStartPos(self):
        return self.coord2Index(self.cleanRect.enter)


def getBasicCleanRobot(path):
    # 根据 json 路径，生成包含基础信息的机器人

    # 读取 json 数据
    json_data = json.loads(open(path, 'r').read())

    # 创建所需 json 数据
    model = Model(json_data["model"]["shape"], json_data["model"]["width"], json_data["model"]["length"])

    cleanWidth = json_data["cleanWidth"]

    minTurnRadius = json_data["minTurnRadius"]

    enter = Pos(json_data["cleanRect"]["enter"]["x"], json_data["cleanRect"]["enter"]["y"])
    polygon = []
    for i in range(len(json_data["cleanRect"]["polygon"])):
        polygon.append(Pos(json_data["cleanRect"]["polygon"][i]["x"], json_data["cleanRect"]["polygon"][i]["y"]))
    cleanRect = CleanRect(enter, polygon)

    normalPosList = []
    for i in range(len(json_data["normalPosList"])):
        normalPosList.append(Pos(json_data["normalPosList"][i]["x"], json_data["normalPosList"][i]["y"]))

    maxID = json_data["maxId"]

    cleanRobot = CleanRobot(model, cleanWidth, minTurnRadius, cleanRect, normalPosList, maxID)

    # 返回数据
    return cleanRobot


# 定义 ROOM 清扫方法
class PosIndex:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return PosIndex(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return PosIndex(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        return PosIndex(scalar * self.x, scalar * self.y)

    def __rmul__(self, scalar):
        return PosIndex(1 / scalar * self.x, 1 / scalar * self.y)


class RoomPathPlan:
    ''''
    牛耕法路径规划
    输入：栅格地图，二维列表[[],[],...]
    输出：[(x1,y1),(x2,y2),...]
    对严格凸多边形有效，否则可能会漏路径
    '''

    def __init__(self, gridMap, curPosIndex):
        self.gridMap = gridMap
        self.curPosIndex = curPosIndex
        self.connected_region_list = []  # 当前点在的连通域
        self.con_min_x = len(self.gridMap)  # 连通域的顶点，此顶点和牛耕方向有关
        self.con_max_x = 0
        self.con_min_y = len(self.gridMap[0])
        self.con_max_y = 0
        self.direction = ''  # 牛耕方向，‘x’ or 'y'
        self.pos_LU = PosIndex(0, 0)
        self.pos_LD = PosIndex(0, 0)
        self.pos_RU = PosIndex(0, 0)
        self.pos_RD = PosIndex(0, 0)
        self.startIndexPos = PosIndex(0, 0)  # 牛耕起点
        self.actionList = []  # 牛耕动作
        self.boustrophedonPath = []

    def getConnectedRegion(self):
        row = self.curPosIndex.x
        col = self.curPosIndex.y
        visited = set()
        connected_region = []

        def dfs(i, j):
            if (i, j) in visited:
                return
            visited.add((i, j))
            connected_region.append((i, j))

            # 检查上下左右四个方向的相邻位置
            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            for di in range(len(directions)):
                dx = directions[di][0]
                dy = directions[di][1]
                new_i, new_j = i + dx, j + dy
                if 0 <= new_i < len(self.gridMap) and 0 <= new_j < len(self.gridMap[0]) \
                        and self.gridMap[new_i][new_j] == self.gridMap[i][j]:
                    dfs(new_i, new_j)

        dfs(row, col)  # 计算，让它递归

        self.connected_region_list = [[0 for col in range(len(self.gridMap[0]) + 1)] for raw in
                                      range(len(self.gridMap) + 1)]
        for i in range(len(connected_region)):
            tmp = connected_region[i]
            self.connected_region_list[tmp[0]][tmp[1]] = 1
            if self.con_min_x > tmp[0]:
                self.con_min_x = tmp[0]
            if self.con_max_x < tmp[0]:
                self.con_max_x = tmp[0]
            if self.con_min_y > tmp[1]:
                self.con_min_y = tmp[1]
            if self.con_max_y < tmp[1]:
                self.con_max_y = tmp[1]

    def calBoustrophedonStartIndexPos(self):
        # 计算牛耕四个顶点
        if self.direction == 'y':
            self.pos_LU.x = self.con_min_x
            self.pos_LD.x = self.con_min_x
            self.pos_RU.x = self.con_max_x
            self.pos_RD.x = self.con_max_x
            y0_min = len(self.connected_region_list[self.con_min_x])
            y0_max = 0
            y1_min = len(self.connected_region_list[self.con_max_x])
            y1_max = 0
            for i in range(len(self.connected_region_list[self.con_min_x])):
                if self.connected_region_list[self.con_min_x][i] == 1:
                    if y0_min > i:
                        y0_min = i
                    if y0_max < i:
                        y0_max = i
            for i in range(len(self.connected_region_list[self.con_max_x])):
                if self.connected_region_list[self.con_max_x][i] == 1:
                    if y1_min > i:
                        y1_min = i
                    if y1_max < i:
                        y1_max = i
            self.pos_LU.y = y0_max
            self.pos_LD.y = y0_min
            self.pos_RU.y = y1_max
            self.pos_RD.y = y1_min
        if self.direction == 'x':
            self.pos_LU.y = self.con_max_y
            self.pos_LD.y = self.con_max_y
            self.pos_RU.y = self.con_min_y
            self.pos_RD.y = self.con_min_y
            x0_min = len(self.connected_region_list)
            x0_max = 0
            x1_min = len(self.connected_region_list)
            x1_max = 0
            for i in range(len(self.connected_region_list)):
                if self.connected_region_list[i][self.con_max_y] == 1:
                    if x0_min > i:
                        x0_min = i
                    if x0_max < i:
                        x0_max = i
            for i in range(len(self.connected_region_list)):
                if self.connected_region_list[i][self.con_min_y] == 1:
                    if x1_min > i:
                        x1_min = i
                    if x1_max < i:
                        x1_max = i
            self.pos_LU.x = x0_max
            self.pos_LD.x = x0_min
            self.pos_RU.x = x1_max
            self.pos_RD.x = x1_min
        # print("牛耕顶点:", '(', self.pos_LU.x, ' ', self.pos_LU.y, ')',
        #       '(', self.pos_LD.x, ' ', self.pos_LD.y, ')',
        #       '(', self.pos_RU.x, ' ', self.pos_RU.y, ')',
        #       '(', self.pos_RD.x, ' ', self.pos_RD.y, ')')

        # 寻找四个顶点中的最近点作为牛耕起点
        tmp_list = [self.pos_LU, self.pos_LD, self.pos_RU, self.pos_RD]
        tmp_dist = math.hypot(tmp_list[0].x - self.curPosIndex.x, tmp_list[0].y - self.curPosIndex.y)
        tmp_index = 0
        for i in range(len(tmp_list)):
            if tmp_dist > math.hypot(tmp_list[i].x - self.curPosIndex.x, tmp_list[i].y - self.curPosIndex.y):
                tmp_index = i
                tmp_dist = math.hypot(tmp_list[i].x - self.curPosIndex.x, tmp_list[i].y - self.curPosIndex.y)
        self.startIndexPos = tmp_list[tmp_index]
        # print("self.startPosIndex : ", self.startIndexPos.x, self.startIndexPos.y,
        #       " for self.curPosIndex : ", self.curPosIndex.x, self.curPosIndex.y)

    def calActionList(self):
        self.actionList = [PosIndex(0, 0), PosIndex(0, 0), PosIndex(0, 0)]  # 确保只有三个动作
        if self.direction == 'y':
            # y 方向牛耕
            action = PosIndex(0, 1)  # 上
            if self.connected_region_list[self.startIndexPos.x + action.x][self.startIndexPos.y + action.y] == 1:
                # 上不堵
                self.actionList[0] = action
                self.actionList[1] = action * -1
            # elif self.connected_region_list[self.startIndexPos.x - action.x][self.startIndexPos.y - action.y] == 1:
            else:
                # 下不堵
                self.actionList[0] = action * -1
                self.actionList[1] = action
            action2 = PosIndex(1, 0)  # 右
            if self.connected_region_list[self.startIndexPos.x + action2.x][self.startIndexPos.y + action2.y] == 1:
                # 右不堵
                self.actionList[2] = action2
            # elif self.connected_region_list[self.startIndexPos.x - action2.x][self.startIndexPos.y - action2.y] == 1:
            else:
                # 左不堵
                self.actionList[2] = action2 * -1
        elif self.direction == 'x':
            # x 方向牛耕
            action = PosIndex(1, 0)  # 上
            if self.connected_region_list[self.startIndexPos.x + action.x][self.startIndexPos.y + action.y] == 1:
                # 上不堵
                self.actionList[0] = action
                self.actionList[1] = action * -1
            elif self.connected_region_list[self.startIndexPos.x - action.x][self.startIndexPos.y - action.y] == 1:
                # 下不堵
                self.actionList[0] = action * -1
                self.actionList[1] = action
            action2 = PosIndex(0, 1)  # 右
            if self.connected_region_list[self.startIndexPos.x + action2.x][self.startIndexPos.y + action2.y] == 1:
                # 右不堵
                self.actionList[2] = action2
            elif self.connected_region_list[self.startIndexPos.x - action2.x][self.startIndexPos.y - action2.y] == 1:
                # 左不堵
                self.actionList[2] = action2 * -1

    def getBoustrophedonPath(self):
        # 计算当前位置所在的连通域
        self.getConnectedRegion()

        # 确当牛耕方向，是横向还是纵向  当前为以最长边牛耕
        if (self.con_max_x - self.con_min_x) >= (self.con_max_y - self.con_min_y):
            self.direction = 'x'
        else:
            self.direction = 'y'

        # 计算牛耕四个顶点 并 找以最近顶点最为牛耕起点
        self.calBoustrophedonStartIndexPos()

        # 根据 牛耕方向 和 牛耕起点 制定牛耕动作序列， 三动作列表【前进，后退，转向】
        self.calActionList()

        # 牛耕算法主函数
        self.boustrophedonPath = []
        self.boustrophedonPath.append(self.startIndexPos)
        cir_index = 0
        lineGo = self.boustrophedonPath[-1] + self.actionList[cir_index]  # 直走
        turnGo = self.boustrophedonPath[-1] + self.actionList[2]  # 转向
        lineTurnGo = self.boustrophedonPath[-1] + self.actionList[cir_index] + self.actionList[2]  # 直走 + 转向
        lineTurnGoOn = True

        while not (self.connected_region_list[lineGo.x][lineGo.y] == 0
                   and self.connected_region_list[turnGo.x][turnGo.y] == 0):  # 直走和转向没路时搜路停止
            if self.connected_region_list[lineGo.x][lineGo.y] == 0 \
                    or (lineTurnGoOn and self.connected_region_list[lineTurnGo.x][lineTurnGo.y] == 0):
                # print("turnGo")
                self.boustrophedonPath.append(turnGo)
                cir_index = (cir_index + 1) % 2  # 轮询下一个直行
                lineTurnGoOn = False
            else:
                # print("lineGo")
                self.boustrophedonPath.append(lineGo)
            if self.connected_region_list[lineTurnGo.x][lineTurnGo.y] == 1:
                lineTurnGoOn = True

            lineGo = self.boustrophedonPath[-1] + self.actionList[cir_index]  # 直走
            turnGo = self.boustrophedonPath[-1] + self.actionList[2]  # 转向
            lineTurnGo = self.boustrophedonPath[-1] + self.actionList[cir_index] + self.actionList[2]  # 直走 + 转向

        return self.boustrophedonPath


def mergePath(pathCoord):
    mergedPath = []
    if len(pathCoord) > 2:
        mergedPath.append(pathCoord[0])
        for i in range(1, len(pathCoord) - 1):
            last_x = mergedPath[-1].x
            last_y = mergedPath[-1].y
            cur_x = pathCoord[i].x
            cur_y = pathCoord[i].y
            next_x = pathCoord[i + 1].x
            next_y = pathCoord[i + 1].y
            same_x = last_x == cur_x and cur_x == next_x
            same_y = last_y == cur_y and cur_y == next_y
            if same_x or same_y:
                continue
            mergedPath.append(pathCoord[i])
        mergedPath.append(pathCoord[-1])
        return mergedPath
    else:
        return pathCoord


def generateLMData(iLM, iLMInstance, Index):
    iLMData = copy.deepcopy(iLMInstance)
    iLMData["centerPos"]["x"] = iLM.x * 100
    iLMData["centerPos"]["y"] = iLM.y * 100
    iLMData["itemType"] = 1232

    tmpJson = json.loads(iLMData["json"])
    tmpJson["instanceName"] = 'LM{}'.format(Index)
    tmpJson["pos"]["x"] = iLM.x
    tmpJson["pos"]["y"] = iLM.y

    iLMData["json"] = json.dumps(tmpJson)

    return iLMData


def generateLineData(LM1, LM2, iLineInstance):
    js1 = json.loads(LM1["json"])
    startPos_x = js1["pos"]["x"]
    startPos_y = js1["pos"]["y"]
    name1 = js1["instanceName"]

    js2 = json.loads(LM2["json"])
    endPos_x = js2["pos"]["x"]
    endPos_y = js2["pos"]["y"]
    name2 = js2["instanceName"]

    newName1 = name1 + "-" + name2
    newName2 = name2 + "-" + name1
    controlPos1_x = startPos_x + 0.3 * (endPos_x - startPos_x)
    controlPos1_y = startPos_y + 0.3 * (endPos_y - startPos_y)
    controlPos2_x = startPos_x + 0.7 * (endPos_x - startPos_x)
    controlPos2_y = startPos_y + 0.7 * (endPos_y - startPos_y)

    # 赋值
    iLineData = copy.deepcopy(iLineInstance)
    tmpJson = json.loads(iLineData["json"])
    jsdata0 = json.loads(tmpJson["data0"])
    jsdata0["instanceName"] = newName1
    jsdata0["startPos"]["instanceName"] = name1
    jsdata0["startPos"]["pos"]["x"] = startPos_x
    jsdata0["startPos"]["pos"]["y"] = startPos_y
    jsdata0["endPos"]["instanceName"] = name2
    jsdata0["endPos"]["pos"]["x"] = endPos_x
    jsdata0["endPos"]["pos"]["y"] = endPos_y
    jsdata0["controlPos1"]["x"] = controlPos1_x
    jsdata0["controlPos1"]["y"] = controlPos1_y
    jsdata0["controlPos2"]["x"] = controlPos2_x
    jsdata0["controlPos2"]["y"] = controlPos2_y
    tmpJson["data0"] = json.dumps(jsdata0)

    jsdata1 = json.loads(tmpJson["data1"])
    jsdata1["instanceName"] = newName2
    jsdata1["startPos"]["instanceName"] = name2
    jsdata1["startPos"]["pos"]["x"] = endPos_x
    jsdata1["startPos"]["pos"]["y"] = endPos_y
    jsdata1["endPos"]["instanceName"] = name1
    jsdata1["endPos"]["pos"]["x"] = startPos_x
    jsdata1["endPos"]["pos"]["y"] = startPos_y
    jsdata1["controlPos1"]["x"] = controlPos2_x
    jsdata1["controlPos1"]["y"] = controlPos2_y
    jsdata1["controlPos2"]["x"] = controlPos1_x
    jsdata1["controlPos2"]["y"] = controlPos1_y
    tmpJson["data1"] = json.dumps(jsdata1)

    iLineData["json"] = json.dumps(tmpJson)

    return iLineData


def clearPath2RoboshopFormat(clearPath, maxId, inputPath, outputPath):
    # 将路径点转化为 roboshop 定义的格式
    formatLMData = []
    iLMInstance = {
        "centerPos": {
            "x": 0,
            "y": 0
        },
        "itemType": 1232,
        "json": "{\"className\":\"LocationMark\",\"instanceName\":\"LM0\",\"pos\":{\"x\":0,\"y\":0},\"property\":[{\"key\":\"spin\",\"type\":\"bool\",\"value\":\"ZmFsc2U=\",\"boolValue\":false}],\"ignoreDir\":true}"
    }
    startIndex = maxId + 1
    for i in range(len(clearPath)):
        iLM = clearPath[i]
        iLMData = generateLMData(iLM, iLMInstance, startIndex)
        formatLMData.append(iLMData)
        startIndex = startIndex + 1
        # print(iLMData)

    formatLineData = []
    iLineInstance = {
        "centerPos": {
            "x": 0,
            "y": 0
        },
        "itemType": 1234,
        "json": "{\"curve\":\"DegenerateBezier\",\"data0\":\"{\\\"className\\\":\\\"DegenerateBezier\\\",\\\"instanceName\\\":\\\"LM3-LM2\\\",\\\"startPos\\\":{\\\"instanceName\\\":\\\"LM3\\\",\\\"pos\\\":{\\\"x\\\":11.045,\\\"y\\\":-1.006}},\\\"endPos\\\":{\\\"instanceName\\\":\\\"LM2\\\",\\\"pos\\\":{\\\"x\\\":7.616,\\\"y\\\":-0.237}},\\\"controlPos1\\\":{\\\"x\\\":9.823,\\\"y\\\":0.791},\\\"controlPos2\\\":{\\\"x\\\":8.757,\\\"y\\\":0.963},\\\"property\\\":[{\\\"key\\\":\\\"direction\\\",\\\"type\\\":\\\"int\\\",\\\"value\\\":\\\"MA==\\\",\\\"int32Value\\\":0},{\\\"key\\\":\\\"movestyle\\\",\\\"type\\\":\\\"int\\\",\\\"value\\\":\\\"MA==\\\",\\\"int32Value\\\":0}]}\",\"data1\":\"{\\\"className\\\":\\\"DegenerateBezier\\\",\\\"instanceName\\\":\\\"LM2-LM3\\\",\\\"startPos\\\":{\\\"instanceName\\\":\\\"LM2\\\",\\\"pos\\\":{\\\"x\\\":7.616,\\\"y\\\":-0.237}},\\\"endPos\\\":{\\\"instanceName\\\":\\\"LM3\\\",\\\"pos\\\":{\\\"x\\\":11.045,\\\"y\\\":-1.006}},\\\"controlPos1\\\":{\\\"x\\\":8.757,\\\"y\\\":0.963},\\\"controlPos2\\\":{\\\"x\\\":9.823,\\\"y\\\":0.791},\\\"property\\\":[{\\\"key\\\":\\\"direction\\\",\\\"type\\\":\\\"int\\\",\\\"value\\\":\\\"MA==\\\",\\\"int32Value\\\":0},{\\\"key\\\":\\\"movestyle\\\",\\\"type\\\":\\\"int\\\",\\\"value\\\":\\\"MA==\\\",\\\"int32Value\\\":0}]}\",\"direction\":2}"
    }
    for i in range(len(formatLMData) - 1):
        iLineData = generateLineData(formatLMData[i], formatLMData[i + 1], iLineInstance)
        formatLineData.append(iLineData)

    totalData = formatLineData + formatLMData

    # 生成文件
    with open(outputPath, "w") as file:
        file.write(json.dumps(totalData))
    file.close()


def main(inputPath,outputPath):
    # 获取包含基础信息的清洁机器人
    clean_robot = getBasicCleanRobot(inputPath)

    # 获取牛耕路径（输入:栅格地图，当前位置）
    RPP = RoomPathPlan(clean_robot.gridMap, clean_robot.getStartPos())
    pathIndex = RPP.getBoustrophedonPath()  # 栅格牛耕路径

    # 栅格转换为坐标
    pathCoord = clean_robot.coordPath2IndexPath(pathIndex)

    # 路径点数据合并，防止站点过多
    mergedPath = mergePath(pathCoord)

    # 将路径坐标【（），（），。。。，（）】 转化为 RoboShop 结构
    clearPath2RoboshopFormat(mergedPath, clean_robot.maxId, inputPath, outputPath)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(sys.argv[0], ", ERROR")
    else:
        main(sys.argv[1],sys.argv[2])
