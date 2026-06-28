#include "sriCommUDPClient.h"



CSRICommUDPClient::CSRICommUDPClient()
{
	mIpLocalServer = "";
	mPortLocalServer = 0;
	mIpLocal = "";
	mPortLocal = 0;

	mSocket = -1;

	mNetworkFailureCallback = NULL;
	mLastError = "";

	mIsTreadStoped = true;

#ifdef  IS_WINDOWS_OS
	WSADATA wsaData;
	WORD  wVersionRequested = MAKEWORD(2, 2);
	//Specify the WinSock specification version as version 2.2
	//指定WinSock规范版本为2.2版本
	WSAStartup(wVersionRequested, &wsaData);
#endif
}


CSRICommUDPClient::~CSRICommUDPClient()
{
	mParserList.clear();	
}



//Open UDP communication
//打开UDP通讯
bool CSRICommUDPClient::OpenUDPServer( std::string ipLocalServer, int portLocalServer)
{	
	int localPort;

	WORD versionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(versionRequested, &wsaData) != 0)
	{
		return false;
	}

	CloseUDP();

	if (portLocalServer > 0)
	{
		localPort = portLocalServer;
	}
	else
	{
		localPort = 4008;
	}

	mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//IPPROTO_UDP
	if (-1 == mSocket)
	{
		GetLastSocketError("socket()");
		return false;
	}


	// 设置非阻塞模式
	u_long mode = 1; // 1表示非阻塞模式
	if (ioctlsocket(mSocket, FIONBIO, &mode) == SOCKET_ERROR) {
		std::cerr << "Failed to set non-blocking mode: " << WSAGetLastError() << std::endl;
		closesocket(mSocket);
		WSACleanup();
		return false;
	}



	// 绑定本地地址和端口
	struct sockaddr_in local_addr;
	memset(&local_addr, 0, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = INADDR_ANY;
	local_addr.sin_port = htons(localPort);
	int ret = bind(mSocket, (struct sockaddr*)&local_addr, sizeof(local_addr));
	if (ret < 0) {
		std::cerr << "Failed to bind socket to local address" << std::endl;
		//close(sockfd);
		return false;
	}

	return true;
}




bool CSRICommUDPClient::CloseUDP()
{
	CloseThread();

	if (mSocket != -1)
	{
#ifdef  IS_WINDOWS_OS
		closesocket(mSocket);
#else
		close(mSocket);
#endif
		mSocket = -1;
	}
	
	//
	return true;
}

//UDP connect
bool CSRICommUDPClient::Connect()
{
	if (OpenThread() == false)
	{
		GetLastSocketError("OpenThread()");
		return false;
	}

	return true;
}

bool CSRICommUDPClient::Disconnect()
{
	//shutdown(mSocket, 2);
	return true;
}

bool CSRICommUDPClient::ReConnect()
{
	//Disconnect();
	//return ConnectUDP();
	return true;
}






//Create UDP client receiver thread
//创建UDP数据接收线程
bool CSRICommUDPClient::OpenThread()
{
	//if (mThread.joinable()) 
	//{
	//	// 若线程仍在运行，先关闭
	//	mThread.join();
	//}

	if (mThread.joinable()==false) 
	{
		mThread = std::thread(&CSRICommUDPClient::UDPClientReceiverThread, this, 0);
	}
	mIsStopThread = false;
	mIsTreadStoped = false;

	return true;
}
bool CSRICommUDPClient::CloseThread()
{
	mIsStopThread = true;
	std::clock_t start = clock();
	while (true)
	{
		if (mIsTreadStoped == true)
		{
			break;
		}
		std::clock_t end = clock();
		double span = static_cast<double>(end - start)/ CLOCKS_PER_SEC;;
		if (span >= 0.1)//1s
		{
			return false;
		}
	}
	return true;
}

//UDP client receiver thread fuction
//UDP数据接收线程函数
void CSRICommUDPClient::UDPClientReceiverThread(int code)
{
	mIsStopThread = false;
	mIsTreadStoped = false;

	int dataBufferLen = 8192;//8K
	BYTE* dataBuffer = new BYTE[dataBufferLen];
	memset(dataBuffer, 0, dataBufferLen);
	int recvDataLen = 0;

	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
	memset(&readfds, 0, sizeof(fd_set));
	memset(&writefds, 0, sizeof(fd_set));
	memset(&exceptfds, 0, sizeof(fd_set));
	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 1;
	FD_SET(mSocket, &readfds);
	FD_SET(mSocket, &writefds);
	FD_SET(mSocket, &exceptfds);


	//addrinfo clientAddress;
	//memset(&clientAddress, 0, sizeof(addrinfo));
	//memcpy(&clientAddress, &mLocalAddr, sizeof(addrinfo));
	//int clientAddrLen = clientAddress.ai_addrlen;
	while (true)
	{
		if (mIsStopThread == true)
		{
			//break;
			Sleep(20);
		}

		memset(dataBuffer, 0, dataBufferLen);
		socklen_t serverAddrLen = sizeof(mServaddr);
 		recvDataLen = recvfrom(mSocket, (char*)dataBuffer, dataBufferLen, 0, (struct sockaddr*)&mServaddr, &serverAddrLen);
		if ((recvDataLen > 0) && (recvDataLen <= dataBufferLen))//
		{
			OnReceivedData(mServaddr,dataBuffer, recvDataLen);
			memset(dataBuffer, 0, recvDataLen);
		}
		else if (recvDataLen == 0)
		{
			continue;
		}
		else
		{
			if (CheckTimeoutError() == true)
			{
				GetLastSocketError("recv() Timeout"); 
				//break;
				Sleep(20);
			}
			
		}

	}
	delete dataBuffer;
	mIsTreadStoped = true;
}
//Process the received data
//处理接收到的数据
bool CSRICommUDPClient::OnReceivedData(sockaddr_in remotrSockaddr,BYTE* data, int dataLen)
{
	for (size_t i = 0; i < mParserList.size(); ++i)
	{
		CSRICommParser* parser = mParserList[i];
		if (parser != NULL)
		{
			parser->OnReceivedData(remotrSockaddr,data, dataLen);
		}
	}
	return true;
}
//Check if the connection timed out
//检测连接超时
bool CSRICommUDPClient::CheckTimeoutError()
{
#ifdef  IS_WINDOWS_OS
	int errorCode = WSAGetLastError();
	if (WSAETIMEDOUT == errorCode)//
	{
		return true;
	}
#else
	//#define ETIMEDOUT       110     /* Connection timed out */  
	if (ETIMEDOUT == errno)
	{
		return true;
	}
#endif
	return false;
}
//Network Failure
//网络故障处理
bool CSRICommUDPClient::OnNetworkFailure()
{
	for (size_t i = 0; i < mParserList.size(); ++i)
	{
		CSRICommParser* parser = mParserList[i];
		if (parser != NULL)
		{
			parser->OnNetworkFailure(mLastError);
		}
	}
	if (mNetworkFailureCallback != NULL)
	{
		mNetworkFailureCallback(mLastError);
	}
	return true;
}


//UDP send string
//UDP发送字符串
bool CSRICommUDPClient::OnSendData(BYTE* data, int dataLen)
{
	if (data == NULL)
	{
		return false;
	}
	if (dataLen <= 0)
	{
		return false;
	}
	try
	{
		int sendRet = sendto(mSocket, (char*)data, dataLen, 0, (struct sockaddr*)&mServaddr, sizeof(mServaddr));
		if (sendRet != dataLen)
		{
			GetLastSocketError("send()");			
			return false;
		}
	}
	catch (std::exception ex)
	{
		mLastError = ex.what();
		OnNetworkFailure();
		return false;
	}
	return true;
}
//Add parser
//添加解析器
bool CSRICommUDPClient::AddCommParser(CSRICommParser* parser)
{
	mParserList.push_back(parser);
	return true;
}

bool CSRICommUDPClient::SetNetworkFailureCallbackFunction(SRICommNetworkFailureCallbackFunction networkFailureCallback)
{
	mNetworkFailureCallback = networkFailureCallback;
	return true;
}

std::string CSRICommUDPClient::GetLastError()
{
	return mLastError;
}

//获取错误信息
void CSRICommUDPClient::GetLastSocketError(std::string functionName = "")
{
	mLastError = "";
	#ifdef  IS_WINDOWS_OS
		char buffer[2048];
		memset(buffer, 0, 2048);
		//sprintf(buffer, "Socket %s error: %d\n", functionName.data(), WSAGetLastError());
		mLastError = buffer;
	#else
		char buffer[2048];
		memset(buffer, 0, 2048);
		sprintf(buffer, "Socket %s error: %s(errno: %d)\n", functionName.data(), strerror(errno), errno);
		mLastError = buffer;
	#endif

	OnNetworkFailure();
}