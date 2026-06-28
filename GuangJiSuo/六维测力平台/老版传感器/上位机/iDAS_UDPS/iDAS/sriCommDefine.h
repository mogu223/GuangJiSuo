#ifndef SRI_COMM_DEFINE_H
#define SRI_COMM_DEFINE_H

#define IS_WINDOWS_OS  0


#ifdef  IS_WINDOWS_OS
	#include <stdio.h>
	#include <tchar.h>
	#include <string.h>
    #include <string>
	#include <iostream>

	#include <thread> 
	#include <mutex>

	#include <ctime>
	#include <chrono>
	#include <vector>

	#include <winsock2.h>
	#include <WS2tcpip.h> 
	#include <SDKDDKVer.h>

	#include <cmath>  // 引入数学库，用于处理浮点数的绝对值
	#include <cstdlib> // 引入标准库，用于处理整数的绝对值
    #pragma comment(lib, "ws2_32.lib")
	#include "sriSensorDataDefine.h"


//struct ForceSensorData
//{
//	float sensorId;
//	float channels[6];//力数据，分别是FX-MZ,单位N/Nm
//	UINT16 packetNum;//包编号
//	float momentArm_X;//X方向的力臂，单位mm
//	float momentArm_Y;
//};
#include <functional>

	typedef std::function<bool(std::string)> SRICommNetworkFailureCallbackFunction;
	typedef std::function<bool(std::string)> SRICommATCallbackFunction;
	typedef std::function<bool(float fx, float fy, float fz, float mx, float my, float mz,INT16 packetNum, sockaddr_in remotrSockaddr,BYTE sensorId, BYTE protocolNo)> SRICommM8218CallbackFunction;

#else
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include <string>
	#include <iostream>

	#include<errno.h>
	#include<sys/types.h>
	#include<sys/socket.h>
	#include <sys/ioctl.h>
	#include<netinet/in.h>
	#include<arpa/inet.h>
	#include<netinet/tcp.h>
	#include<unistd.h>

	#include <thread>
	#include <mutex>

	#include <ctime>
	#include <sys/time.h>        //gettimeofday()

	#include <vector>
	#include <algorithm>

#include <functional>

	typedef std::function<bool(std::string)> SRICommNetworkFailureCallbackFunction;
	typedef std::function<bool(std::string)> SRICommATCallbackFunction;
	typedef std::function<bool(float fx, float fy, float fz, float mx, float my, float mz)> SRICommM8218CallbackFunction;

	typedef  unsigned char BYTE;

	#ifndef max
	#define max(a,b)            (((a) > (b)) ? (a) : (b))
	#endif

	#ifndef min
	#define min(a,b)            (((a) < (b)) ? (a) : (b))
	#endif

#endif


#endif
