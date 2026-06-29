# 01 - main.cpp 源码解读

源码路径：`GuangJiSuo/LRU/main.cpp`

## 文件定位

`main.cpp` 是整个 Qt 程序的入口文件。它不包含业务控制逻辑，主要负责启动应用、加载界面样式、创建主窗口、安装日志和崩溃处理器。

可以把它理解为：

```text
程序启动器
```

它完成初始化后，把真正的控制权交给 `MainWindow`。

---

## 主要 include

```cpp
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include "loghandler.h"
#include "DataType.h"
#include "CrashHandler.h"
```

含义：

| include | 作用 |
|---|---|
| `mainwindow.h` | 主窗口类。真正的 UI 和系统初始化都在 MainWindow 中完成 |
| `QApplication` | Qt 桌面应用程序对象，负责事件循环和 UI 框架 |
| `QFile` | 用来读取 QSS 样式表资源 |
| `loghandler.h` | 安装 Qt 日志处理器，将 qDebug/qWarning 等输出接管 |
| `DataType.h` | 使用项目里的自定义结构体，例如 `DetectedDisplayData` |
| `CrashHandler.h` | 安装崩溃处理逻辑，可能用于生成 dump 或记录异常 |

---

## main 函数结构

`main()` 的核心顺序：

```text
创建 QApplication
  -> 读取 QSS 样式表
  -> 注册 Qt 元类型
  -> 创建 MainWindow
  -> 显示 MainWindow
  -> 安装日志处理器
  -> 安装崩溃处理器
  -> 进入事件循环
```

---

## 关键代码解读

### 1. 创建 Qt 应用对象

```cpp
QApplication a(argc, argv);
```

这是所有 Qt Widgets 桌面程序的基础。它负责：

```text
窗口系统初始化
事件循环
鼠标键盘事件分发
信号槽运行环境
应用级样式和资源管理
```

没有 `QApplication`，后面的 `MainWindow` 无法正常显示。

---

### 2. 读取 QSS 样式

```cpp
QString qss;
QFile file(":/MyQss.qss");
file.open(QFile::ReadOnly);
qss = file.readAll();
file.close();
a.setStyleSheet(qss);
```

这段代码从 Qt 资源系统里读取 `MyQss.qss`，然后把它设置为整个应用的样式表。

`:/MyQss.qss` 里的 `:/` 表示 Qt 资源路径，不是普通磁盘文件路径。对应资源一般在 `.qrc` 文件里，例如 `QSS.qrc`。

QSS 可以理解为 Qt 版 CSS，用来控制按钮、标签、表格、窗口等控件样式。

---

### 3. 注册自定义元类型

```cpp
qRegisterMetaType<nsTaskMgr::DetectedDisplayData>("nsTaskMgr::DetectedDisplayData");
```

`DetectedDisplayData` 是项目自定义结构体，用来传递视觉检测结果，例如角度和两个距离/间隙数据。

Qt 的信号槽如果跨线程传递自定义类型，需要先注册类型，否则运行时可能报错：

```text
Cannot queue arguments of type 'xxx'
```

所以这行说明：

```text
DetectedDisplayData 会通过 Qt 信号槽传递，而且可能跨线程。
```

---

### 4. 创建并显示主窗口

```cpp
MainWindow w;
w.show();
```

这两行之后，程序进入真正的上位机主界面。

`MainWindow` 构造函数中会初始化：

```text
UI
运动控制器
传感器线程
AGV 通讯
视觉模块
光源控制
TaskMgr
各硬件子系统
数据库和图表
```

所以真正阅读项目时，`main.cpp` 看完后应该马上进入 `mainwindow.h` 和 `mainwindow.cpp`。

---

### 5. 安装日志处理器

```cpp
LogHandler::Get().installMessageHandler();
```

这行一般用于接管 Qt 的日志输出，例如：

```cpp
qDebug()
qInfo()
qWarning()
qCritical()
```

安装后，这些日志可能会被统一写入文件、数据库或 UI 日志窗口。

---

### 6. 安装崩溃处理器

```cpp
CrashHandler::install();
```

这行通常用于捕获程序崩溃，例如访问空指针、数组越界、非法内存访问等。

常见用途：

```text
生成 minidump
记录崩溃堆栈
方便现场问题定位
```

这和 `.pro` 文件中链接 `DbgHelp` 库对应。

---

### 7. 进入 Qt 事件循环

```cpp
return a.exec();
```

`a.exec()` 会启动 Qt 的事件循环。之后程序不会像普通命令行程序一样顺序执行完退出，而是一直等待事件：

```text
用户点击按钮
定时器 timeout
TCP 收到数据
串口收到数据
窗口重绘
线程信号返回
```

所以 Qt 程序的逻辑不是从上到下一直执行，而是事件驱动。

---

## 这个文件的阅读重点

读 `main.cpp` 只需要理解四点：

```text
1. 程序入口在 main()
2. UI 样式从 Qt 资源里加载
3. 自定义视觉数据类型被注册给 Qt 信号槽系统
4. 真正主逻辑在 MainWindow
```

---

## 这个文件不需要深究的点

```text
QSS 具体样式内容
LogHandler 内部怎么写日志
CrashHandler 内部怎么生成 dump
```

这些可以后面按需要再看。

---

## 下一步

读完 `main.cpp` 后，下一步看：

```text
mainwindow.h
```

目的：先看 `MainWindow` 声明了哪些子系统对象、按钮槽函数和成员变量。