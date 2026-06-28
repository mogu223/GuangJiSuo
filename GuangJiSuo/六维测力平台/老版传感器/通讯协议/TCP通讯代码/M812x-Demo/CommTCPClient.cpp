#include "StdAfx.h"
#include "CommTCPClient.h"

CCommReceiveResponser::CCommReceiveResponser(void)
{
}

CCommReceiveResponser::~CCommReceiveResponser(void)
{
}

bool CCommReceiveResponser::OnReceiverData(BYTE* data, DWORD dataLen)
{
	if(data == NULL)
	{
		return false;
	}
	return true;
}

bool CCommReceiveResponser::OnNetworkFailure()
{
	return true;
}

CCommTCPClient::CCommTCPClient(CCommReceiveResponser* receiveResponser, bool isOpenThread)
{
	mReceiveResponser = receiveResponser;
	mSocket = INVALID_SOCKET;
	mEventTreadIsStop.SetEvent();
	mThread = NULL;


	mIsOpenThread = isOpenThread;
}

CCommTCPClient::~CCommTCPClient(void)
{
	Close();
}
bool CCommTCPClient::SetAddress(CString targetHost, CString targetPort, CString localHost, CString localPort)
{
	mTargetHost = targetHost;
	mTargetPort = targetPort;
	mLocalHost = localHost;
	mLocalPort = localPort;
	return true;
}
bool CCommTCPClient::Open()
{
	return Open(mTargetHost, mTargetPort, mLocalHost, mLocalPort);
}
bool CCommTCPClient::Open(CString targetHost, CString targetPort, CString localHost, CString localPort, int addressFamily)
{
	WORD versionRequested = MAKEWORD( 2, 2 );
	WSADATA wsaData;
	if ( WSAStartup( versionRequested, &wsaData ) != 0 )
	{
		CString errorStr;
		errorStr.Format(_T("WSAStartup error %d"), WSAGetLastError());


		return false;
	}
	Close();

	mSocket = socket(addressFamily, SOCK_STREAM, IPPROTO_TCP);
	if(mSocket == INVALID_SOCKET)
	{
		CString errorStr;
		errorStr.Format(_T("socket error %d"), WSAGetLastError());
		return false;
	}		

	//loca
	if(_T("") != localHost)
	{
		addrinfo addrinfoHintsLocal;
		addrinfo* addrinfoListLocal = NULL;
		
		memset(&addrinfoHintsLocal, 0, sizeof(addrinfoHintsLocal));
		addrinfoHintsLocal.ai_family = addressFamily;
		addrinfoHintsLocal.ai_socktype = SOCK_STREAM;
		addrinfoHintsLocal.ai_protocol = IPPROTO_TCP;	

		//if(getaddrinfo(converter.WS2S(localHost).c_str(), converter.WS2S(localPort).c_str(), &addrinfoHintsLocal, &addrinfoListLocal) != 0)
		if(getaddrinfo(WS2S(localHost).c_str(), 0, &addrinfoHintsLocal, &addrinfoListLocal) != 0)
		{
			CString errorStr;
			errorStr.Format(_T("getaddrinfo error %d"), WSAGetLastError());

			return false;;
		}
		if(addrinfoListLocal == NULL)
		{
			return false;
		}	
		memcpy(&mLocalAddress, &addrinfoListLocal[0], sizeof(addrinfo));

		if(bind(mSocket, mLocalAddress.ai_addr, mLocalAddress.ai_addrlen) == SOCKET_ERROR)
		{		
			CString errorStr;
			errorStr.Format(_T("bind error %d"), WSAGetLastError());
			return false;
		}
	}
	
	
	//KeepAlive
	BOOL bKeepAlive = TRUE;
	int nRet = setsockopt(mSocket, SOL_SOCKET, SO_KEEPALIVE, (char*)&bKeepAlive, sizeof(bKeepAlive));
	if(nRet !=0 )
	{		
		CString errorStr;
		errorStr.Format(_T("setsockopt error %d"), WSAGetLastError());
		return false;
	}

	struct tcp_keepalive {
		u_long  onoff;
		u_long  keepalivetime;
		u_long  keepaliveinterval;
	};

	tcp_keepalive inKeepAlive = {0};   
	unsigned long ulInLen = sizeof(tcp_keepalive);
	tcp_keepalive outKeepAlive = {0};   
	unsigned long ulOutLen = sizeof(tcp_keepalive);
	unsigned long ulBytesReturn = 0;
	//keep alive, 10s, 3times
	inKeepAlive.onoff  = 1;
	inKeepAlive.keepaliveinterval = 2000;  
	inKeepAlive.keepalivetime = 3;   
	
	nRet = WSAIoctl(mSocket,
		SIO_KEEPALIVE_VALS,    
		(LPVOID)&inKeepAlive,    
		ulInLen,    
		(LPVOID)&outKeepAlive,    
		ulOutLen,    
		&ulBytesReturn,    
		NULL,    
		NULL);    
	if(SOCKET_ERROR  == nRet)    
	{
		CString errorStr;
		errorStr.Format(_T("WSAIoctl error %d"), WSAGetLastError());

		return false;    
	} 
	
	int nNetTimeout=10000;//10s£¬

	if(setsockopt(mSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&nNetTimeout, sizeof(int)) == SOCKET_ERROR)
	{
		CString errorStr;
		errorStr.Format(_T("setsockopt SO_SNDTIMEO error %d"), WSAGetLastError());
	}
	//setsockopt(mSocket, SOL_SOCKET ,SO_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));



	//server
	addrinfo addrinfoHintsTarget;
	addrinfo* addrinfoListTarget = NULL;	
	memset(&addrinfoHintsTarget, 0, sizeof(addrinfoHintsTarget));
	addrinfoHintsTarget.ai_family = addressFamily;
	addrinfoHintsTarget.ai_socktype = SOCK_STREAM;
	addrinfoHintsTarget.ai_protocol = IPPROTO_TCP;
	if(getaddrinfo(WS2S(targetHost).c_str(), WS2S(targetPort).c_str(), &addrinfoHintsTarget, &addrinfoListTarget) != 0)
	{
		CString errorStr;
		errorStr.Format(_T("getaddrinfo error %d"), WSAGetLastError());
		return false;;
	}
	if(addrinfoListTarget == NULL)
	{
		return false;
	}	
	memcpy(&mServerAddress, &addrinfoListTarget[0], sizeof(addrinfo));
	
	if(ConnectToServer() == false)
	{

		return false;
	}
	mTargetHost = targetHost;
	mTargetPort = targetPort;
	mLocalHost = localHost;
	mLocalPort = localPort;
	mAddressFamily = addressFamily;

	return true;
}
bool CCommTCPClient::Close()
{
	if(IsConnected() == true)
	{
		CloseThread();
	}
	if(mSocket != INVALID_SOCKET)
	{
		closesocket(mSocket);
		mSocket = INVALID_SOCKET;
	}
	

	return true;
}
bool CCommTCPClient::ReConnect()
{
	shutdown(mSocket, SD_BOTH);
	if(connect(mSocket, mServerAddress.ai_addr, mServerAddress.ai_addrlen) == SOCKET_ERROR)
	{
		CString errorStr;
		errorStr.Format(_T("ConnectToServer connect error %d"), WSAGetLastError());
		return false;
	}
	return true;
}

bool CCommTCPClient::IsConnected()
{
	if(INVALID_SOCKET == mSocket)
	{
		return false;
	}else
	{
		return true;
	}
	return true;
}


bool CCommTCPClient::OnReceiverData(BYTE* data, DWORD dataLen)
{
	mReceiveResponser->OnReceiverData(data, dataLen);
	return true;
}
bool CCommTCPClient::OnNetworkFailure()
{
	mReceiveResponser->OnNetworkFailure();
	return true;
}

bool CCommTCPClient::OnSendData(CString command)
{
	std::string commandString = WS2S(command);

	BYTE* data = (BYTE*)commandString.c_str();
	DWORD dataLen = commandString.length();
	return OnSendData(data, dataLen);
}
bool CCommTCPClient::OnSendData(BYTE* data, DWORD dataLen)
{
	if(data == NULL)
	{
		TRACE(_T("SendPacket error: packet == NULL"));
		return false;
	}

	if(dataLen <= 0)
	{
		TRACE(_T("SendPacket error: GetPacketLen <= 0"));
		return false;
	}
	if(mSocket == INVALID_SOCKET)
	{
		TRACE(_T("SendPacket error: mSocket == INVALID_SOCKET"));
		return false;
	}
	if( WaitForSingleObject(mEventTreadIsStop, 1) == WAIT_OBJECT_0)//if stop, re connection
	{
		TRACE("WaitForSingleObject CCommTCPClient::SendPacket 2\n");
		if(Open() == false)
		{
			TRACE(_T("SendPacket ReOpen == false"));
		}
	}
	TRACE("WaitForSingleObject CCommTCPClient::SendPacket 3\n");
	mSendTimeBegin = GetTickCount();
	int sendRet = send(mSocket, (char*)data, dataLen, 0);
	mSendTimeEnd = GetTickCount();
	if( sendRet != dataLen )
	{
		TRACE("WaitForSingleObject CCommTCPClient::SendPacket 4\n");
		CString errorStr;
		errorStr.Format(_T("send error %d %d"), sendRet, WSAGetLastError());
		TRACE(errorStr);
		return false;
	}	
	TRACE("WaitForSingleObject CCommTCPClient::SendPacket 5\n");
	return true;
}


///////////////////////////////
bool CCommTCPClient::ConnectToServer()
{
	/*
	if(connect(mSocket, mServerAddress.ai_addr, mServerAddress.ai_addrlen) == SOCKET_ERROR)
	{
		CString errorStr;
		errorStr.Format(_T("ConnectToServer connect error %d"), WSAGetLastError());
		mLogFile.WriteLogFile(errorStr);
		return false;
	}
	*/
	bool bConnected = false;
	unsigned long uFlag = 1;
	int nRet = ioctlsocket(mSocket, FIONBIO, (unsigned long*)&uFlag);
	if(nRet == SOCKET_ERROR)
	{	
		return false;
	}
	if(connect(mSocket, mServerAddress.ai_addr, mServerAddress.ai_addrlen) == -1)
	{
		struct timeval timeout = {0};
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;
		
		fd_set fdWrite;
		FD_ZERO(&fdWrite);
		FD_SET(mSocket, &fdWrite);
		
		int nError = -1;
		int nLen = sizeof(int);
		
		nRet = select(mSocket, 0, &fdWrite, 0, &timeout);
		if (nRet > 0)
		{
			getsockopt(mSocket, SOL_SOCKET, SO_ERROR, (char*)&nError, &nLen);
			if (nError != 0)
			{
				bConnected = false;
			}
			bConnected = true;
		}else
		{
			bConnected = false;
		} 
	}
	uFlag = 0;
	ioctlsocket(mSocket, FIONBIO, (unsigned long*)&uFlag);

	if(bConnected == false)
	{
		return false;
	}



	if(OpenThread() == false)
	{
		return false;
	}	
	return true;
}








////////////////////////////////////////////////////////
UINT __cdecl CommTCPClientReceiverThread(LPVOID pParam)
{
	CCommTCPClient* receiver = (CCommTCPClient*)pParam;
	if(receiver == NULL)
	{
		return -1;
	}
	receiver->mEventTreadIsStop.ResetEvent();

	DWORD dataBufferLen = 8192;//8K
	BYTE* dataBuffer = new BYTE[dataBufferLen];
	memset(dataBuffer, 0, dataBufferLen);
	DWORD recvDataLen = 0;

	fd_set readfds;	
	fd_set writefds;
	fd_set exceptfds;
	memset(&readfds, 0, sizeof(fd_set));
	memset(&writefds, 0, sizeof(fd_set));
	memset(&exceptfds, 0, sizeof(fd_set));
	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 1;

	FD_SET(receiver->mSocket, &readfds);
	FD_SET(receiver->mSocket, &writefds);
	FD_SET(receiver->mSocket, &exceptfds);

	while(true)
	{
		TRACE("WaitForSingleObject CommTCPClientReceiverThread 1\n");
		if( WaitForSingleObject(receiver->mEventStopThread, 1) == WAIT_OBJECT_0)//us stop
		{
			TRACE("WaitForSingleObjectCommTCPClientReceiverThread 2\n");
			break;
		}
		TRACE("WaitForSingleObject CommTCPClientReceiverThread 3\n");
		recvDataLen = recv(receiver->mSocket, (char*)dataBuffer, dataBufferLen, 0);
		if( (recvDataLen > 0)&&(recvDataLen <=dataBufferLen) )
		{
			//ReceiverData
			receiver->OnReceiverData(dataBuffer, recvDataLen);
			memset(dataBuffer, 0, recvDataLen);
		}else if( recvDataLen == 0)
		{			
		}else
		{
			int errorCode = WSAGetLastError();
			if(WSAETIMEDOUT == errorCode)//The connection has been dropped because of a network failure or because the peer system failed to respond.
			{
				receiver->OnNetworkFailure();
				break;
			}
		}			

	}
	if(receiver->mSocket != INVALID_SOCKET)
	{
		closesocket(receiver->mSocket);
		receiver->mSocket = INVALID_SOCKET;
	}
	TRACE("CommTCPClientReceiverThread exited");
	delete dataBuffer;
	receiver->mEventTreadIsStop.SetEvent();
	AfxEndThread(0, TRUE);//kill
	
	return 0;
}

bool CCommTCPClient::OpenThread()
{
	if(mIsOpenThread == false)
	{
		return true;
	}

	mEventStopThread.ResetEvent();
	mEventTreadIsStop.ResetEvent();
	mThread = AfxBeginThread(	CommTCPClientReceiverThread,
		                        this,
								THREAD_PRIORITY_NORMAL,
								0,
								CREATE_SUSPENDED,
								NULL);
	mThread->m_bAutoDelete = TRUE; 
	//run
	if(mThread != NULL)
	{
		mThread->ResumeThread();
	}	

	return true;
}
bool CCommTCPClient::CloseThread()
{
	if(mThread == NULL)
	{
		return true;
	}
	if(mSocket != INVALID_SOCKET)
	{
		closesocket(mSocket);
	}

	mEventStopThread.SetEvent();
	
	TRACE("WaitForSingleObject CCommTCPClient::CloseThread 1\n");
	WaitForSingleObject(mEventTreadIsStop, INFINITE);//get stop
	TRACE("WaitForSingleObject CCommTCPClient::CloseThread 2\n");
	WaitForSingleObject(mThread, INFINITE);//get stop
	TRACE("WaitForSingleObject CCommTCPClient::CloseThread 3\n");
	mThread = NULL;
	mEventTreadIsStop.SetEvent();	

	
	return true;
}



std::string CCommTCPClient::WS2S(CString inputs)
{
	return WChar2Ansi(inputs.GetBuffer(inputs.GetLength()));
}
std::string CCommTCPClient::WS2S(wstring& inputws)
{
	return WChar2Ansi(inputws.c_str()); 
}

std::string CCommTCPClient::WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen<= 0) 
	{
		return std::string("");
	}
	char* pszDst = new char[nLen];
	if (NULL == pszDst)
	{
		return std::string("");
	}
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen -1] = 0;
	std::string strTemp(pszDst);
	delete [] pszDst;
	return strTemp;
}