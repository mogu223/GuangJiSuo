// PMC006Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PMC006Demo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//方向定义
#define MOTOR_FORWARD	0
#define MOTOR_REVERSE	1
//控制器类型
#define PLATFORM_TYPE	PMC006A4
//一体泵的最大行程步数
#define PUMP_MAX_RANGE	40000

// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

#define ERROR_HANDLE(closePort,errInfo)	if(RET_SUCCESS != result){\
	printf(errInfo);\
	if(TRUE == closePort){\
		ClosePort();\
	}\
	return result;\
}

/*****************PMC006A4S一体泵测试*****************/
//一体泵找原点
PUSIResult PumpHome(DWORD dwAddress)
{
	PUSIResult result = RET_SUCCESS;
	DWORD dwStatus = 0;
	DWORD dwIOValue;
	//打开传感器电源
	result = SetIOValue(dwAddress,0xA2); //GPIO8输出1
	ERROR_HANDLE(FALSE,"SetIOValue");
	Sleep(100);
	//获取端口值
	result = GetIOValue(dwAddress,&dwIOValue);
	ERROR_HANDLE(FALSE,"GetIOValue");
	//清除外部紧急停止1
	result = ClearExtStop(dwAddress,0x01);
	ERROR_HANDLE(FALSE,"ClearExtStop");

	//在限位时先远离原点开关一定步数，再执行找原点以保证精度
	if(dwIOValue&0x04){ //在限位是高电平，不在限位低电平 
		//反向转动
		result = SetDirection(dwAddress,MOTOR_REVERSE); //设置转动方向
		ERROR_HANDLE(FALSE,"SetDirection");
		//启动步进
		result = StartStep(dwAddress,2000);
		ERROR_HANDLE(FALSE,"StartStep");
		//等待步进完成
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
		while(dwStatus&0x1)   //判断忙状态，忙则等待转动完成
		{
			Sleep(50);
			result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
			ERROR_HANDLE(FALSE,"GetControllerStatus1");
		}
	}
	//不在限位时找原点	
	//打开外部紧急停止1
	result = SetExtStopEnable(dwAddress,0x01);
	ERROR_HANDLE(FALSE,"SetExtStopEnable");
	//反向转动
	result = SetDirection(dwAddress,MOTOR_FORWARD); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	//启动步进
	result = StartStep(dwAddress,PUMP_MAX_RANGE + 5000); //超过行程的步数
	ERROR_HANDLE(FALSE,"StartStep");
	//等待步进完成
	result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
	ERROR_HANDLE(FALSE,"GetControllerStatus1");
	while(dwStatus&0x1)   //判断忙状态，忙则等待转动完成
	{
		Sleep(50);
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
	}
	//马达位置清零
	result = SetMotorPosition(dwAddress,0);
	ERROR_HANDLE(FALSE,"SetMotorPosition");

	return result;
}
//一体泵吸液
//dwStepNum:吸液走的步数
PUSIResult PumpSuction(DWORD dwAddress,DWORD dwStepNum)
{
	PUSIResult result = RET_SUCCESS;
	DWORD dwStatus = 0;
	int nMotorPos = 0;
	DWORD dwTargetPos = 0; //目标位置
	//获取马达位置
	result = GetMotorPosition(dwAddress,&nMotorPos);
	ERROR_HANDLE(FALSE,"GetMotorPosition");
	//printf("当前马达位置：%d\n",nMotorPos);
	dwTargetPos = (DWORD)abs(nMotorPos) + dwStepNum;
	if(dwTargetPos > PUMP_MAX_RANGE){
		printf("目标位置超过行程!!\n");
		return RET_GENERAL_ERR;
	}
	//吸液远离限位方向走，需要先清除外部停止，否则上次如果外部停止有效则无法启动电机转动
	//清除外部紧急停止1
	result = ClearExtStop(dwAddress,0x01);
	ERROR_HANDLE(FALSE,"ClearExtStop");
	//反向转动
	result = SetDirection(dwAddress,MOTOR_REVERSE); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	//设置转动速度
	result = SetVelocity(dwAddress,2000);
	ERROR_HANDLE(FALSE,"SetVelocity");
	//启动步进
	result = StartStep(dwAddress,dwStepNum); 
	ERROR_HANDLE(FALSE,"StartStep");
	//等待步进完成
	result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
	ERROR_HANDLE(FALSE,"GetControllerStatus1");
	while(dwStatus&0x1)   //判断忙状态，忙则等待转动完成
	{
		Sleep(50);
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
	}
	return result;
}
//一体泵排液
//dwStepNum:排液走的步数
PUSIResult PumpDrainage(DWORD dwAddress,DWORD dwStepNum)
{
	PUSIResult result = RET_SUCCESS;
	DWORD dwStatus = 0;
	//排液不需要先清除外部停止，否则到限位之后电机还会继续前进撞到结构限位
	//反向转动
	result = SetDirection(dwAddress,MOTOR_FORWARD); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	//设置转动速度
	result = SetVelocity(dwAddress,2000);
	ERROR_HANDLE(FALSE,"SetVelocity");
	//启动步进
	result = StartStep(dwAddress,dwStepNum); 
	ERROR_HANDLE(FALSE,"StartStep");
	//等待步进完成
	result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
	ERROR_HANDLE(FALSE,"GetControllerStatus1");
	while(dwStatus&0x1)   //判断忙状态，忙则等待转动完成
	{
		Sleep(50);
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
	}
	if(dwStatus&0x02){ //EXT1
		printf("原点限位触发!!\n");
	}
	return result;
}

//一体泵电磁阀开关
PUSIResult ValveSwitch(DWORD dwAddress,BOOL bOn)
{
	PUSIResult result = RET_SUCCESS;
	if(TRUE == bOn){
		//设置电磁阀驱动电压点空比
		result = SetCoil(dwAddress,100);
	}else{
		result = SetCoil(dwAddress,0);		
	}
	ERROR_HANDLE(FALSE,"SetCoil");
	return result;
}

/*****************通用功能测试*****************/
//位置模式测试
PUSIResult PosModeTest(DWORD dwAddress) 
{
	PUSIResult result = RET_SUCCESS;
	DWORD dwStatus = 0;
	result = SetVelocity(dwAddress,2000);//设置转动速度
	ERROR_HANDLE(FALSE,"SetVelocity");
	//正向转动
	result = SetDirection(dwAddress,MOTOR_REVERSE); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	result = StartStep(dwAddress,6400); //启动步进
	ERROR_HANDLE(FALSE,"StartStep");
	Sleep(50);
	//等待步进完成
	result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
	ERROR_HANDLE(FALSE,"GetControllerStatus1");
	while(dwStatus&0x1)   //判断忙状态，忙则等待转动完成
	{
		Sleep(50);
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
	}
	//反向转动
	result = SetDirection(dwAddress,MOTOR_FORWARD); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	result = StartStep(dwAddress,6400); //启动步进
	ERROR_HANDLE(FALSE,"StartStep");
	Sleep(50);
	//等待步进完成
	result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
	ERROR_HANDLE(FALSE,"GetControllerStatus1");
	while(dwStatus&0x1)  
	{
		Sleep(50);
		result = GetControllerStatus1(dwAddress,&dwStatus); //获取控制器状态
		ERROR_HANDLE(FALSE,"GetControllerStatus1");
	}
	return result;
}

//速度模式测试
PUSIResult VelocityModeTest(DWORD dwAddress) 
{
	PUSIResult result = RET_SUCCESS;
	DWORD dwStatus = 0;
	result = SetVelocity(dwAddress,2000);//设置转动速度
	ERROR_HANDLE(FALSE,"SetVelocity");
	//正向转动
	result = SetDirection(dwAddress,MOTOR_REVERSE); //设置转动方向
	ERROR_HANDLE(FALSE,"SetDirection");
	//进入速度模式
	result = SetVelocityMode(dwAddress,TRUE);
	ERROR_HANDLE(FALSE,"SetVelocityMode");

	result = StartStep(dwAddress,6400); //启动步进
	ERROR_HANDLE(FALSE,"StartStep");

	Sleep(3000);
	result = AbortStep(dwAddress);
	ERROR_HANDLE(FALSE,"AbortStep");

	return result;
}


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
			DWORD dwStatus = 0;
			DWORD dwVersion = 0;
			UINT nPortNr = 0;
			char szFunc[20];
			PUSIResult result = RET_SUCCESS;
			SetPlatformType(PLATFORM_TYPE);
			printf("请输入串口号：\n");
			scanf("%d",&nPortNr);
			if(RET_SUCCESS == OpenPort(nPortNr,9600))
			{
				DWORD dwAddress = 0;
				DWORD dwTestType = 0;
				DWORD dwStepNum = 0;
				printf("打开串口成功！\n");
				printf("请输入控制器地址：\n");
				scanf("%d",&dwAddress);
				result = GetFirmwareVersion(dwAddress,&dwVersion);
				ERROR_HANDLE(TRUE,"");
				printf("version:0x%X.\n",dwVersion);
				result = SetMaxCurrent(dwAddress,1200); //设置最大电流
				ERROR_HANDLE(TRUE,"");
				result = SetMicroStep(dwAddress,16); //设置细分数
				ERROR_HANDLE(TRUE,"");
				result = SetAccCoff(dwAddress,5); //设置加速度细数5
				ERROR_HANDLE(TRUE,"");
				result = SetDecCoff(dwAddress,5); //设置减速度细数5
				ERROR_HANDLE(TRUE,"");
				while(1){
					printf("**************测试功能选择**************\n");
					printf("请选择测试类型：\n");
					printf("  1、位置模式\n");
					printf("  2、速度模式\n");
					printf("  3、一体泵找原点\n");
					printf("  4、一体泵吸液\n");
					printf("  5、一体泵排液\n");
					printf("  6、一体泵开电磁阀\n");
					printf("  7、一体泵关电磁阀\n");
					printf("  8、退出\n");
					printf("****************************************\n");
					scanf("%d",&dwTestType);
					printf("选择类型：%d\n",dwTestType);
					switch(dwTestType)
					{
					case 1:		
						result = PosModeTest(dwAddress); //位置模式
						strcpy(szFunc,"PosModeTest");
						break;
					case 2:		
						result = VelocityModeTest(dwAddress); //速度模式
						strcpy(szFunc,"VelocityModeTest");
						break;
					case 3:	
						result = PumpHome(dwAddress);//一体泵找原点
						strcpy(szFunc,"PumpHome");
						break;
					case 4:		
						printf("请输入吸液走的步数：\n");
						scanf("%d",&dwStepNum);
						result = PumpSuction(dwAddress,dwStepNum);//一体泵吸液
						strcpy(szFunc,"PumpSuction");
						break;
					case 5:		
						printf("请输入排液走的步数：\n");
						scanf("%d",&dwStepNum);
						result = PumpDrainage(dwAddress,dwStepNum);//一体泵排液
						strcpy(szFunc,"PumpDrainage");
						break;
					case 6:
						result = ValveSwitch(dwAddress,TRUE); //开电磁阀
						break;
					case 7:
						result = ValveSwitch(dwAddress,FALSE); //关电磁阀
						break;
					default:
						goto ExitTest;						
					}
					if (RET_SUCCESS != result)
					{
						printf("%s fail!\n",szFunc);							
					}	
				}
ExitTest:
				ClosePort();
			}
			else
			{
				printf("打开串口失败！\n");
			}
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
