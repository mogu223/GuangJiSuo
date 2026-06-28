#pragma once
#include <fstream>
#include <Mstcpip.h>
#include <ws2tcpip.h>
using namespace std;

class CCommReceiveResponser
{
public:
	CCommReceiveResponser(void);
	~CCommReceiveResponser(void);

	virtual bool OnReceiverData(BYTE* data, DWORD dataLen);
	virtual bool OnNetworkFailure();
};


class CCommTCPClient
{
public:
	CCommTCPClient(CCommReceiveResponser* receiveResponser, bool isOpenThread=true);
	~CCommTCPClient(void);
	bool SetAddress(CString targetHost, CString targetPort, CString localHost, CString localPort);
	bool Open();
	bool Open(CString targetHost, CString targetPort, CString localHost, CString localPort, int addressFamily=AF_INET);
	bool Close();

	bool ReConnect();


	bool IsConnected();


	bool OnReceiverData(BYTE* data, DWORD dataLen);
	bool OnNetworkFailure();

	bool OnSendData(CString command);
	bool OnSendData(BYTE* data, DWORD dataLen);
public:
	CCommReceiveResponser* mReceiveResponser;
	CEvent mEventStopThread;
	CEvent mEventTreadIsStop;

	SOCKET mSocket;
	CString mTargetHost;
	CString mTargetPort;
	CString mLocalHost;
	CString mLocalPort;
	int mAddressFamily;
	addrinfo mLocalAddress;
	addrinfo mServerAddress;
	

	DWORD mSendTimeBegin;
	DWORD mSendTimeEnd;
private:
	bool ConnectToServer();

	bool mIsOpenThread;
	CWinThread* mThread;
	bool OpenThread();
	bool CloseThread();


	std::string WS2S(CString inputs);
	std::string WS2S(wstring& inputws);
	std::string WChar2Ansi(LPCWSTR pwszSrc);

	
};
