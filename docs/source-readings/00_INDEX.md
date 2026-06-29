# LRU 源码逐文件解读索引

本目录用于按阅读顺序解释 `GuangJiSuo/LRU` 工程源码。每份文档聚焦一个源码文件或一个强关联模块，目标是帮助理解代码结构、关键函数、数据流和阅读重点。

推荐阅读顺序：

1. `01_main_cpp.md` - 程序入口 `main.cpp`
2. `02_mainwindow_h.md` - 主窗口声明 `mainwindow.h`
3. `03_mainwindow_cpp.md` - 主窗口实现 `mainwindow.cpp`
4. `04_DataType_h.md` - 公共数据结构 `DataType.h`
5. `05_TaskMgr_h.md` - 任务调度器声明 `TaskMgr.h`
6. `06_TaskMgr_cpp.md` - 任务调度器实现 `TaskMgr.cpp`
7. `07_SCVehicle_h_cpp.md` - AGV 小车子系统 `SCVehicle.h/.cpp`
8. `08_LevelingSystem_h_cpp.md` - 调平子系统 `LevelingSystem.h/.cpp`
9. `09_MainLift_h_cpp.md` - 一级升降子系统 `MainLift.h/.cpp`
10. `10_CoverPlate_h_cpp.md` - 盖板/封门子系统 `CoverPlate.h/.cpp`
11. `11_Lift_h_cpp.md` - 二级升降/视觉/六自由度平台子系统 `Lift.h/.cpp`
12. `12_Pin_h_cpp.md` - 销子子系统 `Pin.h/.cpp`
13. `13_vision_source.md` - 视觉模块目录 `vision_source/`
14. `14_LRU_h_cpp.md` - OpenGL LRU 模型显示 `LRU.h/.cpp`

## 主线理解

整套程序可以按下面这条主线阅读：

```text
main.cpp
  -> MainWindow 创建界面和所有子系统
  -> MainWindow 连接 TaskMgr 与各子系统
  -> 用户点击开始任务
  -> TaskMgr 按 SystemStep 顺序发任务
  -> 子系统执行 ExeXXXTask(TaskInfo)
  -> 子系统反馈 sigStatusFeedback(eTaskStatus)
  -> TaskMgr 收到 Complete 后进入下一步，收到 Error 后暂停
```

## 每份文档的阅读方法

每份解读文档通常包含：

```text
文件定位
它负责什么
关键类/结构体/函数
数据流或信号槽关系
阅读重点
容易误解的点
```

先按顺序看完这些文档，再回头阅读源码，会比直接打开 `mainwindow.cpp` 从头到尾看更有效。