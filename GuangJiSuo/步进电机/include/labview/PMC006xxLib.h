#ifndef __PMC006XX_LIB_H
#define __PMC006XX_LIB_H



/**************************************宏定义**************************************/
//外部停止
#ifndef EXTSTOP1
#define EXTSTOP1	0x1
#endif

#ifndef EXTSTOP2
#define EXTSTOP2	0x2
#endif

/**************************************类型定义**************************************/
typedef enum
{
	RET_SUCCESS = 0,  //操作成功
	RET_GENERAL_ERR,//通用错误
	RET_LOG_CREATE_FAIL,  //创建LOG文件失败
	RET_COMM_OPEN_FAIL, //打开串口失败
	RET_COMM_NOT_OPEN,  //串口未打开
	RET_COMM_WRITE_TIMEOUT,  //写命令超时
	RET_COMM_READ_TIMEOUT,  //读命令超时
	RET_CMDHEAD_ERROR,   //命令头错误
	RET_RESP_ADDR_ERROR,   //响应地址错误
	RET_CMD_NOTSUPPORT,   //命令不支持
	RET_UPDATEFILE_OPEN_FAIL, //升级文件打开失败
	RET_UPDATE_CRC_ERROR, //升级出现CRC error
	RET_UPDATE_NOT_RESPONSE, //升级过程无响应
}PUSIResult;

typedef enum
{
	PMC006B4 = 0,  //PMC006平台
	PMC006B3 = 1,  //PIO002平台
	PIO002B2 = 2,   //PIO002B2平台
	PCS0801 = 3,  //PCS0801平台
}PLATFORM_TYPE;

#ifdef __cplusplus
extern "C" {
#endif
/**************************************类型定义**************************************/
/**************************************类型定义**************************************/
typedef void (__stdcall *TraceCallback)(TCHAR* strTrace); //跟踪回调函数定义
typedef void (__stdcall *UpdateCallback)(DWORD dwPercent); //升级回调函数定义

/**************************************导出函数声明**************************************/
void __stdcall SetTraceCallback(TraceCallback callback); //设置跟踪回调
void __stdcall SetPlatformType(PLATFORM_TYPE platformType); //设置平台类型
PUSIResult __stdcall SetLogPath(WCHAR* strLogPath); //初始化LOG
PUSIResult __stdcall OpenPort(UINT portnr, DWORD baud); //初始化通信端口
PUSIResult __stdcall SetPortHandle(HANDLE handle); //设置通信端口句柄
PUSIResult __stdcall ClosePort(void); //关闭通信端口
//system control
PUSIResult __stdcall GetFirmwareVersion(DWORD dwAddress,DWORD* pVersion); //获取固件版本
PUSIResult __stdcall SetAddress(DWORD dwAddress,DWORD dwNewAddr); //设置控制器地址
PUSIResult __stdcall EnterBootloader(DWORD dwAddress); //进入bootloader模式
PUSIResult __stdcall SaveAllPara(DWORD dwAddress); //保存所有参数
//GPIO
PUSIResult __stdcall SetIOValue(DWORD dwAddress,DWORD dwIOValue); //设置IO端口的值
PUSIResult __stdcall GetIOValue(DWORD dwAddress,DWORD *pIOValue); //获取IO端口的值
//offline cmd
PUSIResult __stdcall RunOfflineCmd(DWORD dwAddress,DWORD dwPointer); //运行当前用户指令
PUSIResult __stdcall SetCurrentOfflineCmd(DWORD dwAddress,DWORD dwCmd); //设置控制器命令buffer的当前指令
PUSIResult __stdcall GetCurrentOfflineCmd(DWORD dwAddress,DWORD *pCmd); //获取控制器命令buffer的当前指令
PUSIResult __stdcall SetCmdBuffPointer(DWORD dwAddress,DWORD dwPointer); //设置当前命令buffer指针
PUSIResult __stdcall GetCmdBuffPointer(DWORD dwAddress,DWORD *pPointer); //获取当前命令buffer指针
PUSIResult __stdcall SetCmdBuffCmdCount(DWORD dwAddress,DWORD dwCmdCount); //设置命令buffer总数
PUSIResult __stdcall GetCmdBuffCmdCount(DWORD dwAddress,DWORD *pCmdCount); //获取命令buffer总数
PUSIResult __stdcall SetOfflineAutoRun(DWORD dwAddress,BOOL bRun); //设置离线自动运行
PUSIResult __stdcall SaveCmdBuffer(DWORD dwAddress); //保存命令buffer所有指令
//update
void __stdcall SetUpdateCallback(UpdateCallback callback); //设置升级过程回调,用于显示百分比
PUSIResult __stdcall UpdateApplication(DWORD dwAddress,TCHAR *strAppPath); //升级应用
PUSIResult __stdcall GetDebugData(DWORD dwAddress,DWORD *pDebugData);

PUSIResult __stdcall SetVelocityMode(DWORD dwAddress,BOOL bVelocityMode); //设置速度模式
PUSIResult __stdcall StartStep(DWORD dwAddress,DWORD dwStepNum); //启动步进
PUSIResult __stdcall AbortStep(DWORD dwAddress); //当前步进命令中止	
PUSIResult __stdcall SetMicroStep(DWORD dwAddress,DWORD dwMicroStep); //设置细分数
PUSIResult __stdcall GetMicroStep(DWORD dwAddress,DWORD* pMicroStep); //获取细分数
PUSIResult __stdcall SetMotorPosition(DWORD dwAddress,int nMotorPos); //设置马达位置
PUSIResult __stdcall GetMotorPosition(DWORD dwAddress,int* pMotorPos); //获取马达位置
PUSIResult __stdcall SetDirection(DWORD dwAddress,BOOL bReverse); //设置转动方向
PUSIResult __stdcall SetVelocity(DWORD dwAddress,DWORD dwVelocity); //设置转动速度
PUSIResult __stdcall GetVelocity(DWORD dwAddress,DWORD *pVelocity); //获取转动速度
PUSIResult __stdcall SetVelocityCompFactor(DWORD dwAddress,DWORD dwVelocityComp); //设置速度补偿因子
PUSIResult __stdcall GetVelocityCompFactor(DWORD dwAddress,DWORD *pVelocityComp); //获取速度补偿因子
PUSIResult __stdcall SetStartVelocity(DWORD dwAddress,DWORD dwStartVelocity); //设置启动速度
PUSIResult __stdcall GetStartVelocity(DWORD dwAddress,DWORD *pStartVelocity); //获取启动速度
PUSIResult __stdcall SetStopVelocity(DWORD dwAddress,DWORD dwStopVelocity); //设置停止速度
PUSIResult __stdcall GetStopVelocity(DWORD dwAddress,DWORD *pStopVelocity); //获取停止速度
PUSIResult __stdcall SetAccCoff(DWORD dwAddress,DWORD dwCoff); //设置加速系数
PUSIResult __stdcall GetAccCoff(DWORD dwAddress,DWORD *pCoff);//获取加速系数
PUSIResult __stdcall SetDecCoff(DWORD dwAddress,DWORD dwCoff); //设置减速系数
PUSIResult __stdcall GetDecCoff(DWORD dwAddress,DWORD *pCoff); //获取减速系数
PUSIResult __stdcall SetMaxCurrent(DWORD dwAddress,DWORD dwMaxCurrent); //设置最大电流
PUSIResult __stdcall GetMaxCurrent(DWORD dwAddress,DWORD *pMaxCurrent); //获取最大电流
PUSIResult __stdcall SetCurrCompFactor(DWORD dwAddress,DWORD dwCompFactor); //设置电流补偿因子
PUSIResult __stdcall GetCurrCompFactor(DWORD dwAddress,DWORD *pCompFactor); //获取电流补偿因子
PUSIResult __stdcall SetExtStopEnable(DWORD dwAddress,DWORD dwStopEnable); //设置外部紧急停止使能
PUSIResult __stdcall SetExtStopTrigerMode(DWORD dwAddress,DWORD dwTrigerMode); //设置外部紧急停止触发方式
PUSIResult __stdcall GetExtStopTrigerMode(DWORD dwAddress,DWORD *pTrigerMode); //获取外部紧急停止触发方式
PUSIResult __stdcall ClearExtStop(DWORD dwAddress,DWORD dwExtStop); //清除外部停止
PUSIResult __stdcall SetCurrentAutoDecay(DWORD dwAddress,BOOL bEnable); //设置电流衰减使能
PUSIResult __stdcall SetCurrentDecayFactor(DWORD dwAddress,DWORD dwDecayFactor); //设置电流衰减因子
PUSIResult __stdcall GetCurrentDecayFactor(DWORD dwAddress,DWORD *pDecayFactor); //获取电流衰减因子
PUSIResult __stdcall SetOfflineEnable(DWORD dwAddress,BOOL bEnable); //设置离线使能
PUSIResult __stdcall GetControllerStatus1(DWORD dwAddress,DWORD *pStatus); //获取控制器状态1
PUSIResult __stdcall GetControllerStatus2(DWORD dwAddress,DWORD *pStatus); //获取控制器状态2

PUSIResult __stdcall GetStallConfig(DWORD dwAddress,DWORD *pStallConfig); //获取堵转配置
PUSIResult __stdcall SetStallConfig(DWORD dwAddress,DWORD dwStallConfig); //设置堵转配置
PUSIResult __stdcall GetStallTriger(DWORD dwAddress,DWORD *pTriger); //获取堵转触发值
PUSIResult __stdcall SetStallTriger(DWORD dwAddress,DWORD dwTriger); //设置堵转触发值
PUSIResult __stdcall GetStallTrigerLength(DWORD dwAddress,DWORD *pTrigerLen); //获取堵转触发长度
PUSIResult __stdcall SetStallTrigerLength(DWORD dwAddress,DWORD dwTrigerLen); //设置堵转触发长度
PUSIResult __stdcall ClearStallFlag(DWORD dwAddress); //清除堵转标志位



#ifdef __cplusplus
}
#endif

#endif
