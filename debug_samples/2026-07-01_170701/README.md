# 二级升降自动抬升诊断日志样本

## 基本信息

- 测试时间：未提供完整现场测试时间；本样本整理时间为 2026-07-01 17:07:01。样本来源日志时间覆盖 2026-05-26、2026-06-24、2026-06-25。
- 当前 commit sha：938f2ce747f5a69564cba8b22df4aa63ccf42341
- LRU 类型：未提供；平台反馈样本中车辆信息为 vehicle_id=AMB-01，model=AMB-150。
- 目标点位：未提供；日志中出现 task_1、closest_target=LM3。
- 是否完整自动抬升：未知，本地未找到完整二级升降自动抬升闭环日志。
- z=0 是否检测：否，本地未找到 z=0 视觉检测日志或图片。
- z=1700 是否检测：否，本地未找到 z=1700 视觉检测日志或图片。
- 是否发生碰撞：未知，本地未找到明确碰撞记录。
- 最终是否进入孔洞：未知，本地未找到进孔结果记录。
- 现场观察到的偏差方向和大约误差：未提供，未记录到偏左/偏右/偏前/偏后误差值。

## 样本来源

- `auto_lift_fsm.jsonl`：从 `GuangJiSuo/LRU/crash_log.txt` 中抽取取盖板/状态切换相关记录。
- `secondary_lift.jsonl`：从 `GuangJiSuo/LRU/crash_log.txt` 中抽取升降、横移、纵移等动作状态记录。
- `platform_command.jsonl`：从 `GuangJiSuo/LRU/release/crash_log.txt` 中抽取 UDP 绑定失败、响应超时、通信测试失败等命令/通信记录。
- `platform_feedback.jsonl`：从 `GuangJiSuo/LRU/release/log_2026-06-24` 中抽取少量平台反馈字段，不包含完整大日志。
- `leveling.jsonl`：从 `GuangJiSuo/LRU/release/log_2026-06-24` 中抽取 roll、pitch、angle、acc_x、acc_y、acc_z 等调平相关字段。
- `lru_params.jsonl`：由 `GuangJiSuo/LRU/param.ini` 转换为 key/value JSONL。
- `camera_runtime.jsonl`：从 `GuangJiSuo/LRU/crash_log.txt` 中抽取相机标定文件打开失败记录。
- `calibration_snapshot/`：复制当前本地 `camera_calibration_50.json` 和 `camera_calibration_16.json`。
- `config_snapshot/`：复制当前本地 `5DOFGantryArm.pro`、`param.ini`、`release_param.ini`。

## 缺失日志文件

- `vision_aruco.jsonl`：本地未找到 ArUco 检测运行日志。
- `force_sensor.jsonl`：本地未找到本次测试的力传感器运行日志。
- `manual_measurement.json`：本地未找到现场手工测量记录。
- `images/z0_raw*.png`：本地未找到匹配 z0 raw 命名或内容的图片。
- `images/z0_annotated*.png`：本地未找到匹配 z0 annotated 命名或内容的图片。
- `images/z1700_raw*.png`：本地未找到匹配 z1700 raw 命名或内容的图片。
- `images/z1700_annotated*.png`：本地未找到匹配 z1700 annotated 命名或内容的图片。

## 未提交内容

- 未提交大视频、全量连续帧、`build/`、`exe`、`dll` 或 release 构建产物。
- `GuangJiSuo/LRU/release/log_2026-06-24` 等原始运行日志体积较大，仅抽取少量 JSONL 样本。
