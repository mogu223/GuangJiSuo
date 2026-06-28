;//Config.ini
         [robot]
         appSkin=skin1          ;//皮肤名称（appInfo/images/skin1） 
         queryTimeValue=500     ;//定时查询19204时间
         isShowMaximized=false  ;//最大化显示
         isBootSoftware=false   ;//开启自动启动
         robotDebugMode=true    ;//是否显示参数中带有Debug字符的参数
         logMode=-1             ;//日志打印模式（-1不打印日志，0打印info级别日志，1打印所有日志）
         socketTimeOut=1000     ;//连接超时时间
         ControlTimeOutMs=30    ;//手动控制定时器间隔 ms
         isNotCorrectionMap = 0 ;//0自动矫正地图   1不自动矫正地图
;//LayoutConfig.ini
         [layout]
         TabsMenuActions= ;//记录标签
         RoMainWindow=    ;//记录主窗口布局
         defalutTabs=     ;//默认的标签
		 
;//ParameterComparison.txt
		参数中文对照表及显示排序
		
;//TaskConfig.ini
		视频模块中IP，端口号等配置信息
		
;//TaskTagConfig.json
		任务链树形标签
;//ButtonShowConfig.ini
  按钮隐藏显示配置文件

;//robomapConfig.ini
	[params]
	allowAdsorptionMinimumAngle = 6 ;// angle%30 可吸附最小值如：35 = 30 