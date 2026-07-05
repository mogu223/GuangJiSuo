# denzios/change 相对 main 的最新进度

生成日期：2026-07-06

## 对比范围

- 对比分支：`origin/main...origin/denzios/change`
- `origin/main`：`938f2ce`，提交信息为“添加 LRU 代表性运行和故障日志样本”
- `origin/denzios/change`：`1fff700`，提交信息为“fix: align six-dof search directions with vehicle axes”
- 本次统计：13 个分支提交，56 个文件变化，约 9098 行新增、1065 行删除
- 说明：生成本文档时尝试 `git fetch origin --prune` 失败，原因是当前环境无法通过本机代理连接 GitHub。因此本文基于本地已有的 `origin/main` 与 `origin/denzios/change` 引用。

## 总体结论

`denzios/change` 已经把二级升降的视觉对位从“单帧检测 + 固定补偿”推进为“多帧检测 + 质量门控 + 闭环补偿 + 六自由度搜索找码 + 可视化 LRU 参数调整”的版本。

核心变化集中在 LRU 二级升降子系统：

- `Lift.cpp` 的主要实现迁移到 `LiftSubsystem.cpp`，新增自动抬升闭环、自动下降隔离逻辑、多帧检测和六自由度搜索找码。
- ArUco 检测增加详细帧结果、PnP 质量判断、可配置 marker 物理边长、重投影误差门控、角点贴边判断和搜索线索输出。
- 自动抬升在 z≈0 和 z≈1700 两个高度分别检测、补偿、复测，并增加跨高度一致性判断。
- 新增 LRU 参数调整弹窗，支持按当前 LRU 类型调整 gap、final_z、相机到 LRU、ArUco 到 gap、offset、marker_id、z0/z1700 tvec 修正偏移等参数。
- 多帧检测失败时，六自由度平台会尝试平移找码；最新提交已按实机坐标约定修正方向：`+X=车头/前`，`+Y=车左/左`。
- `.gitignore` 已整理，避免构建产物、第三方依赖、日志和大体积样本误提交。

## 领域约定

当前分支代码按以下约定工作：

- 六自由度平台坐标：`+X` 为车头方向，也就是前；`+Y` 为车左方向，也就是左。
- 找码搜索方向：前为 `X+`，后为 `X-`，左为 `Y+`，右为 `Y-`。
- z≈0 使用 `deviceIndex = 1`；z≈1700 使用 `deviceIndex = 0`。
- 自动抬升补偿仍沿用现有闭环约定：X 残差通过 `平台X += xCorr` 补偿，Y 残差通过 `平台Y -= yCorr` 补偿。
- 视觉输出的 `x/y/yaw` 是用于 LRU gap 对位的结果，不是原始像素坐标，也不是直接的 OpenCV 相机坐标。

## 自动抬升闭环

主要文件：

- `GuangJiSuo/LRU/LiftSubsystem.cpp`
- `GuangJiSuo/LRU/Lift.h`
- `GuangJiSuo/LRU/param.ini`

新增流程：

1. z≈0 阶段调用 `runAutoLiftVisionStage(1, "z≈0", ...)`。
2. 每次视觉检测不再只取一帧，而是调用 `detectMultiFrameWithSixDofSearch()`。
3. 单批默认采样 15 帧，至少 8 帧有效。
4. 有效帧先取中位数，再剔除 x/y/yaw 跳变值。
5. 若残差已在阈值内，需要连续稳定达到 `StablePassCount` 才算通过。
6. 若 yaw 超阈值，先补 yaw；否则补 x/y。
7. 自动补偿使用 `CorrectionGain=0.70`，即每次只补 70%。
8. 补偿后立即复测。
9. 如果复测残差比补偿前增大超过 `ResidualGrowthStopRatio=1.10`，执行软停止。
10. z≈1700 阶段再次检测和补偿。
11. z≈0 与 z≈1700 的残差做一致性检查，当前阈值为 x/y 1.5mm、yaw 0.3deg。
12. 通过后再升到 `final_z_lift`。

主要配置项在 `param.ini`：

- `VisionGeometry/MarkerSizeMm=40.0`
- `VisionQuality/FrameCount=15`
- `VisionQuality/MinValidFrames=8`
- `VisionQuality/ReprojectionErrorMaxPx=2.5`
- `VisionQuality/CornerBorderMarginPx=5`
- `VisionQuality/JumpXyMm=2.0`
- `VisionQuality/JumpYawDeg=1.0`
- `AutoLiftControl/SettleXyMm=0.15`
- `AutoLiftControl/SettleYawDeg=0.15`
- `AutoLiftControl/StablePassCount=2`
- `AutoLiftControl/MaxCorrectionCommandsPerHeight=5`
- `AutoLiftControl/CorrectionGain=0.70`
- `AutoLiftControl/ResidualGrowthStopRatio=1.10`
- `AutoLiftControl/CrossHeightXyMm=1.5`
- `AutoLiftControl/CrossHeightYawDeg=0.3`

## 多帧检测和图像质量判断

主要文件：

- `GuangJiSuo/LRU/vision_source/arucoDetector.h`
- `GuangJiSuo/LRU/vision_source/arucodetector.cpp`
- `GuangJiSuo/LRU/LiftSubsystem.cpp`

新增能力：

- `DetailedFrameResult` 描述单帧检测结果，包括是否找到目标 marker、角点是否完整、角点是否贴边、PnP 是否成功、重投影误差、x/y/yaw、失败原因和搜索线索。
- `processImageDetailed()` 取代单纯 `processImage()`，用于多帧门控。
- PnP marker 物理边长通过 `VisionGeometry/MarkerSizeMm` 配置，不再硬编码为 40mm。
- 重投影误差阈值通过 `VisionQuality/ReprojectionErrorMaxPx` 配置，不再硬编码。
- 检测失败时也尽量保留搜索线索，包括 marker 中心相对图像中心的像素偏移，以及修正前的 PnP `tvecX/tvecY`。
- 对 z≈0 和 z≈1700 分别支持 `tvec` 偏移修正参数：
  - `z0_tvec_x_offset`
  - `z0_tvec_y_offset`
  - `z1700_tvec_x_offset`
  - `z1700_tvec_y_offset`

暂未加入的质量判断：

- marker 图像面积判断暂未加入，因为目前还没有确认标准图片面积或稳定阈值。

## 六自由度平移找码

主要文件：

- `GuangJiSuo/LRU/LiftSubsystem.cpp`

新增流程：

1. 原点先进行多帧检测。
2. 如果原点检测有效，直接返回结果。
3. 如果原点检测失败且启用搜索，根据 PnP 或像素偏移线索决定平台移动方向。
4. 定向找码最多默认 2 次。
5. 定向找码失败后，可进入四方向盲扫兜底。
6. 在搜索位置检测成功后，把结果换算回原点坐标。
7. 最后平台回原点，方便后续抬升。

当前代码默认值：

- `EnableSixDofSearch=true`
- `SearchSafetyLeftMm=70`
- `SearchSafetyRightMm=70`
- `SearchSafetyForwardMm=25`
- `SearchSafetyBackwardMm=70`
- `SearchDistanceRatio=0.70`
- `MaxDirectedSearchMoves=2`
- `EnableBlindFallback=true`

注意：这些 `VisionSearch` 项目前由代码默认值提供，当前 `param.ini` 还没有显式写入这一段。

最新方向修复：

- PnP 线索先从相机系转平台系：
  - `platformHintX = -camY`
  - `platformHintY = camX`
- 像素线索按同一方向近似：
  - `platformHintX = -py`
  - `platformHintY = px`
- 平移安全夹紧已按平台真实坐标修正：
  - X 限制前后：`[-SearchSafetyBackwardMm, +SearchSafetyForwardMm]`
  - Y 限制右左：`[-SearchSafetyRightMm, +SearchSafetyLeftMm]`
- 盲扫顺序为：前、后、左、右。

## LRU 参数可视化调整

主要文件：

- `GuangJiSuo/LRU/lruparamdialog.cpp`
- `GuangJiSuo/LRU/lruparamdialog.h`
- `GuangJiSuo/LRU/mainwindow.cpp`
- `GuangJiSuo/LRU/mainwindow.h`
- `GuangJiSuo/LRU/mainwindow.ui`
- `GuangJiSuo/LRU/LRUdatadef.h`

新增能力：

- 在二级升降界面增加“参数调整”按钮。
- 点击按钮后弹出当前 LRU 类型的参数编辑窗口。
- 参数编辑后立即写入并通过 `paramsSelected` 信号同步给：
  - `Lift::onParamsReceived`
  - `ArucoDetector::onParamsReceived`
  - `dahengTwoCams_qt_vs::onParamsReceived`
- 支持恢复当前 LRU 类型的默认参数。
- 当前覆盖参数保存到程序运行目录下的 `lru_params.json`。

支持可视化调整的字段包括：

- `x_gap`
- `y_gap`
- `final_z`
- `aruco_to_gapx`
- `aruco_to_gapy`
- `camera_to_lrux_50`
- `camera_to_lruy_50`
- `camera_to_lrux_16`
- `camera_to_lruy_16`
- `offset_x_50`
- `offset_y_50`
- `offset_x_16`
- `offset_y_16`
- `marker_id`
- `z0_tvec_x_offset`
- `z0_tvec_y_offset`
- `z1700_tvec_x_offset`
- `z1700_tvec_y_offset`

迁移注意：

- `lru_params.json` 是运行时生成文件，不是源码默认参数。若工作机已经通过弹窗调过参数，迁移时需要单独保留或复制该文件。
- 如果不复制 `lru_params.json`，程序会回到 `LRUdatadef.h` 中的默认预设值。

## 自动下降路径

主要文件：

- `GuangJiSuo/LRU/LiftSubsystem.cpp`

当前状态：

- 自动下降分为两条路径。
- 路径 A：如果刚完成过 `auto_lift`，下降直接按轨迹回到 1700，再回到 0，不重复视觉补偿。
- 路径 B：如果不是刚完成自动抬升，则保留“降到 1700 -> 检测 + 调整 -> 降到 0”的逻辑。
- 路径 B 已改用多帧检测和六自由度找码，但仍保留固定 4 轮循环：
  - `for (int i = 0; i <= 3 && autodescent; ++i)`

仍需后续考虑：

- 路径 B 还没有像 `auto_lift` 一样引入稳定计数和残差增大停止逻辑。
- 如果下降路径在实机上出现过度调整或耗时过长，建议后续把路径 B 也改成与 `runAutoLiftVisionStage()` 类似的闭环 helper。

## 工程结构和构建文件

主要变化：

- `GuangJiSuo/LRU/Lift.cpp` 删除，新增 `GuangJiSuo/LRU/LiftSubsystem.cpp`。
- `.pro` 从 `Lift.cpp` 切换到 `LiftSubsystem.cpp`。
- `.pro` 新增 `lruparamdialog.cpp/.h`。
- `lrumonitor.cpp` 重命名为 `lrumonitor_window.cpp`。
- `STLModel/rrglwidget.*` 重命名为 `STLModel/coverplaterrglwidget.*`。
- `STLModel/stlfileloader.*` 重命名为 `STLModel/coverplatestlfileloader.*`。
- `ui_mainwindow.h` 随 UI 改动更新。

依赖注意：

- 本分支仍依赖 Qt 5.15.2 MSVC2019 32bit、OpenCV、Daheng、ZMotion、iDAS、Eigen 等本地依赖。
- `.gitignore` 会忽略 `.lib`、`.dll`、构建输出和 `GuangJiSuo/LRU/bin/`，因此纯 Git checkout 不一定包含全部运行/链接依赖。
- 迁移到工作机时，如果不是在已有完整工程目录上更新 Git，仍需要复制第三方依赖目录和运行时 DLL。

## 调试样本和参考材料

新增目录：

- `debug_samples/2026-07-01_170701/`
- `GuangJiSuo/取盖板参数/...`

用途：

- `debug_samples` 保存少量 JSONL、配置快照和相机标定快照，用于回看自动抬升、平台命令、平台反馈、二级升降、调平、LRU 参数等信息。
- `.gitignore` 已允许小型 debug sample metadata、JSON、Markdown、PNG 提交，同时继续阻止视频、原始帧和大体积数据进入仓库。

## 已知风险和需要实机确认

以下事项不是纯代码审查能完全证明的，需要工作机或实机验证：

1. 六自由度平台实际方向：确认 `X+` 确实向车头、`Y+` 确实向车左。
2. 视觉残差方向：平台 `X+10mm` 后视觉 x 是否按预期变化，平台 `Y+10mm` 后视觉 y 是否按预期变化。
3. yaw 方向：平台 `Rz+1deg` 后视觉 yaw 是否按当前补偿逻辑预期变化。
4. 找码标签：日志显示“前/后/左/右”时，平台实际移动方向是否一致。
5. z≈0 与 z≈1700：两高度下相机、标定文件和视觉残差方向是否一致。
6. `convertSearchResultToOrigin()`：搜索位置检测成功后换算回原点的结果，是否接近回原点后重新检测结果。
7. 下降路径 B：固定 4 轮检测补偿是否会过度调整。
8. `final_z_lift`：如果未正确下发 LRU 参数，默认值仍可能是 0，需要在调度流程中确认参数一定先到达。

## 当前验证状态

- 已做 Git 级别核对：`denzios/change` 本地分支与 `origin/denzios/change` 同步到 `1fff700`。
- 最近一次已知推送成功：`1fff700 fix: align six-dof search directions with vehicle axes`。
- 文档生成时未重新跑 Qt 全量编译。
- 文档生成时远端 fetch 未成功，因此“最新”以本地已有远端引用为准。

## 建议下一步

1. 在工作机或实机上按小步长验证平台方向、视觉残差方向、yaw 方向和找码方向。
2. 手动跑 Qt Release 编译，确认 `.pro`、新增 dialog、重命名文件和依赖路径全部通过。
3. 如果实机方向验证通过，再考虑把 `VisionSearch` 默认项显式写入 `param.ini`，便于现场调整。
4. 如果下降路径 B 表现不稳定，再把它改造成与自动抬升一致的“检测 -> 小比例补偿 -> 复测 -> 稳定计数 -> 残差增大停止”闭环。
