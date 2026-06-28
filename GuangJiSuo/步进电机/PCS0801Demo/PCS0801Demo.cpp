// PCS0801Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PCS0801Demo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

#define ERROR_HANDLE()	if(RET_SUCCESS != result){ClosePort();return;}

void SensorTest(void)
{
	DWORD dwVersion = 0;
	DWORD dwCapValue = 0;
	PUSIResult result = RET_SUCCESS;
	SetPlatformType(PCS0801);
	if(RET_SUCCESS == OpenPort(11,9600))
	{
		printf("打开串口成功！\n");
		result = GetFirmwareVersion(255,&dwVersion);
		ERROR_HANDLE();
		printf("version:0x%X.\n",dwVersion);

		result = SetCapTriger1(255,0x800000); //设置触发值1
		ERROR_HANDLE();

		result = SetCapTriger2(255,0x800000); //设置触发值2
		ERROR_HANDLE();

		result = SetCapTriger3(255,0x800000); //设置触发值3
		ERROR_HANDLE();

		result = SetCapTriger4(255,0x800000); //设置触发值4
		ERROR_HANDLE();
		
		for(int i = 0;i<10;i++) //读取电容值
		{
			result = GetCapValue(255,&dwCapValue);
			printf("cap value:0x%X\n",dwCapValue);
			Sleep(500);
		}
		ClosePort();
	}
	else
	{
		printf("打开串口失败！\n");
	}
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
			SensorTest();
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
