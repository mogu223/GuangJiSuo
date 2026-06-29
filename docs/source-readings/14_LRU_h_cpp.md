# 14 - LRU.h / LRU.cpp 源码解读

源码路径：

```text
GuangJiSuo/LRU/LRU.h
GuangJiSuo/LRU/LRU.cpp
```

## 文件定位

`LRU` 是 OpenGL 3D 模型显示模块。

它负责：

```text
1. 加载 STL 模型
2. 读取模型顶点和法线
3. 创建 OpenGL 缓冲区
4. 绘制 LRU 模型
5. 绘制天花板/参考面
6. 支持鼠标旋转、平移、缩放视图
7. 根据电机位置更新模型位置
```

它不是自动任务调度核心，也不直接控制硬件。它主要用于可视化。

可以把它理解为：

```text
LRU 三维数字模型显示控件
```

---

## 一、LRU.h 结构

### 1. 类声明

```cpp
class LRU : public QOpenGLWidget, protected QOpenGLFunctions
```

这说明 `LRU` 是一个 Qt OpenGL 控件。

| 基类 | 作用 |
|---|---|
| `QOpenGLWidget` | 可以嵌入 Qt 界面的 OpenGL 绘图窗口 |
| `QOpenGLFunctions` | 提供跨平台 OpenGL 函数封装 |

---

## 2. 构造和析构

```cpp
explicit LRU(QWidget *parent = nullptr);
~LRU();
```

构造函数初始化模型状态、OpenGL buffer、当前位置和姿态。

析构函数会清理 OpenGL 资源。

---

## 3. 加载 STL 模型

```cpp
bool loadSTLModel(const QString &fileName);
```

这是外部调用入口，用于加载一个 STL 文件。

大致流程：

```text
读取 STL 文件
    ↓
得到 vertices 和 normals
    ↓
保存到 m_vertices / m_normals
    ↓
初始化或更新 OpenGL buffer
    ↓
触发重绘
```

---

## 4. 坐标绑定

```cpp
void updateModelPosition(float motorXPosition,
                         float motorYPosition,
                         float motorZPosition,
                         float rotationAngleY);
```

这个函数用于根据电机位置更新模型显示位置。

它的意义是：

```text
真实机构位置变化
    ↓
更新三维模型位置/角度
    ↓
界面上的模型跟着变化
```

---

## 5. OpenGL 生命周期函数

```cpp
void paintGL() override;
void initializeGL() override;
```

Qt OpenGL 控件的核心函数：

| 函数 | 作用 |
|---|---|
| `initializeGL()` | 初始化 OpenGL 环境、着色器、缓冲区等 |
| `paintGL()` | 每次需要重绘时调用 |

---

## 6. 鼠标交互

```cpp
void mousePressEvent(QMouseEvent *event) override;
void mouseMoveEvent(QMouseEvent *event) override;
void mouseReleaseEvent(QMouseEvent *event) override;
void wheelEvent(QWheelEvent *event) override;
```

说明模型视图支持鼠标操作，例如：

```text
左键旋转
中键平移
滚轮缩放
```

具体行为要看 `LRU.cpp` 的实现。

---

## 7. 模型数据

```cpp
QVector<float> m_vertices;
QVector<float> m_normals;
```

`m_vertices` 保存模型顶点。

`m_normals` 保存法线，用于光照计算。

STL 模型通常由很多三角面组成，每个三角面有三个顶点和法线。

---

## 8. OpenGL 资源

```cpp
QOpenGLShaderProgram *m_shaderProgram;
QOpenGLBuffer m_vertexBuffer;
QOpenGLBuffer m_normalBuffer;
QOpenGLVertexArrayObject m_vao;
```

含义：

| 成员 | 作用 |
|---|---|
| `m_shaderProgram` | 顶点/片段着色器程序 |
| `m_vertexBuffer` | 顶点缓冲区 |
| `m_normalBuffer` | 法线缓冲区 |
| `m_vao` | 顶点数组对象，记录 buffer 和属性绑定关系 |

---

## 9. 坐标和姿态

```cpp
QVector3D m_currentPosition;
QQuaternion m_currentOrientation;
QVector3D m_mappingTranslation;
QQuaternion m_mappingRotation;
QVector3D m_mappingScale;
```

这些用于控制模型在 3D 空间中的位置、旋转和缩放。

其中：

```text
m_currentPosition：当前模型位置
m_currentOrientation：当前模型姿态
m_mappingTranslation：坐标映射平移
m_mappingRotation：坐标映射旋转
m_mappingScale：坐标映射缩放
```

---

## 二、LRU.cpp 重点

## 1. 构造函数

构造函数初始化：

```text
shaderProgram = nullptr
顶点/法线 buffer 类型
当前位置为 0
初始姿态为单位四元数
映射平移为 0
映射旋转为 0
映射缩放为 1
数据加载标志 false
鼠标状态 false
```

这表示刚创建控件时还没有加载 STL 模型。

---

## 2. 析构函数

```cpp
LRU::~LRU()
{
    cleanupGLResources();
}
```

OpenGL 资源需要手动清理，避免显存泄漏或上下文释放错误。

---

## 3. loadSTLModel()

这是模型加载核心。

流程：

```text
1. 调用 readSTLFile(fileName, vertices, normals)
2. 如果读取失败，返回 false
3. 保存 vertices 和 normals
4. 设置 m_dataLoaded = true
5. 清理旧 OpenGL 资源
6. 初始化 shader/buffer 或更新 buffer
7. 计算模型 x/y/z 范围
8. 触发 update() 重绘
```

### 计算模型范围

函数会把顶点分成 x/y/z 三组，然后计算：

```cpp
min_x / max_x
min_y / max_y
min_z / max_z
```

这些范围用于后续计算模型中心点和相机视角。

---

## 4. render()

`render()` 是真正绘制模型的函数。

核心流程：

```text
检查 OpenGL 错误
检查顶点/法线是否为空
检查 OpenGL 上下文是否有效
makeCurrent()
设置 viewport
清屏
启用深度测试
绑定 shader
设置 model/view/projection 矩阵
设置光源位置
绑定 VAO
调用 glDrawArrays 绘制三角形
绘制天花板
释放 VAO 和 shader
doneCurrent()
```

---

## 5. model/view/projection 矩阵

`render()` 中设置了三个矩阵：

```cpp
modelMatrix
viewMatrix
projectionMatrix
```

这三个矩阵是 3D 渲染基础。

### modelMatrix

```cpp
model.scale(0.001f * m_mappingScale);
model.translate(m_mappingTranslation);
model.rotate(m_mappingRotation);
```

控制模型自身的缩放、平移和旋转。

`0.001f` 说明 STL 模型尺寸可能是毫米，显示时缩放到米或更适合屏幕的比例。

### viewMatrix

```cpp
view.lookAt(cameraPosition, targetPosition, upDirection);
```

控制摄像机怎么看模型。

代码中相机放在模型中心上方一定距离，看向模型中心。

### projectionMatrix

```cpp
projection.perspective(45.0f, aspect, 0.1f, farPlane);
```

使用透视投影。45 度视角，按窗口宽高比设置画面。

---

## 6. 着色器

`initializeGLResources()` 中直接用字符串定义 shader。

### 顶点着色器

它接收：

```text
a_position：顶点位置
a_normal：顶点法线
```

并计算：

```text
v_normal
v_position
gl_Position
```

### 片段着色器

它根据光源方向和法线计算简单漫反射：

```text
normal
lightDir
diff
color
FragColor
```

最终模型颜色大致是蓝绿色，并根据光照明暗变化。

---

## 7. renderCeiling()

`LRU` 还包含天花板相关数据：

```cpp
m_ceilingVertices
m_ceilingNormals
m_ceilingVertexBuffer
m_ceilingNormalBuffer
m_ceilingVao
```

这说明除了 LRU 模型，还会画一个天花板或参考平面。

可能用途：

```text
显示 LRU 与安装环境之间的位置关系
提供空间参考
辅助观察模型姿态
```

---

## 8. updateModelPosition()

这个函数用于把真实机构位置映射到 3D 模型。

参数：

```text
motorXPosition
motorYPosition
motorZPosition
rotationAngleY
```

说明模型位置可能跟随三轴运动和绕 Y 轴旋转。

理解方式：

```text
运动控制器读到的轴位置
    ↓
updateModelPosition(...)
    ↓
更新模型平移/旋转
    ↓
update() 触发 OpenGL 重绘
```

---

## LRU 模块和其他模块的关系

| 模块 | 关系 |
|---|---|
| `MainWindow` | 可能创建并显示 LRU 控件 |
| `lrumonitor` | 可能使用 LRU 控件显示模型状态 |
| `ZMotionControl` | 提供电机位置，间接驱动模型更新 |
| `STL` 文件 | 模型数据来源 |
| `QSS/UI` | LRU 控件嵌入界面显示 |

---

## 阅读重点

优先看：

```text
LRU 构造函数
loadSTLModel()
readSTLFile()
initializeGL()
initializeGLResources()
render()
updateModelPosition()
paintGL()
鼠标事件函数
```

---

## 易误解点

### 1. LRU.cpp 不是控制逻辑

它主要是 3D 可视化，不是自动安装流程的核心控制器。

### 2. STL 模型只是显示，不等于真实机构状态

真实机构状态来自运动控制器，模型只是根据位置数据做可视化。

### 3. OpenGL 资源需要上下文

代码中多次使用：

```cpp
makeCurrent();
doneCurrent();
```

这是因为 OpenGL buffer、shader 等资源必须在有效 OpenGL 上下文中操作。

### 4. 顶点和法线必须匹配

如果 STL 读取出的顶点或法线为空，`render()` 会直接返回，不绘制。

---

## 何时需要深入读 LRU.cpp

如果你的目标是理解自动安装流程，`LRU.cpp` 可以后看。

如果你的目标是：

```text
修改 3D 模型显示
让模型跟随电机实时运动
更换 STL 模型
调整视角、颜色、光照、缩放
显示天花板/环境参考
```

那就需要详细阅读 `LRU.cpp`。

---

## 阅读结束后的整体回顾

到这里，主线源码已经基本读完：

```text
main.cpp：启动程序
mainwindow.h/cpp：创建 UI 和所有子系统，连接信号槽
DataType.h：定义公共数据结构
TaskMgr.h/cpp：自动流程调度
SCVehicle：AGV 小车
LevelingSystem：调平
MainLift：一级升降
CoverPlate：盖板/封门
Lift：二级升降 + 视觉 + 六自由度平台 + 力检测
Pin：销子机构
vision_source：相机、ArUco、光源、激光、UDP
LRU：3D 模型显示
```

下一步如果要继续深入，建议选择一个具体目标：

```text
看自动流程：继续深入 TaskMgr + 各 ExeXXXTask
看视觉定位：深入 Lift + ArucoDetector + dahengTwoCams
看硬件控制：深入 ZMotionControl + 各子系统动作函数
看 UI：深入 MainWindow 按钮槽函数和 .ui 文件
看 3D：深入 LRU.cpp 和 STLModel/
```