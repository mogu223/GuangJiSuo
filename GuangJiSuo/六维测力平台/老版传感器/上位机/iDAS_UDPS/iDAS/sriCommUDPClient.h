#ifndef SRI_COMM_UDP_CLIENT_H
#define SRI_COMM_UDP_CLIENT_H

#include "sriCommDefine.h"
#include "sriCommParser.h"

class CSRICommUDPClient
{
public:
	CSRICommUDPClient();
	~CSRICommUDPClient();

	bool OpenUDPServer(std::string ipLocalServer, int portLocalServer);//Local Server
	bool CloseUDP();

	bool Connect();
	bool Disconnect();
	bool ReConnect();

	bool OnReceivedData(sockaddr_in remotrSockaddr,BYTE* data, int dataLen);
	bool OnSendData(BYTE* data, int dataLen);

	bool AddCommParser(CSRICommParser* parser);

	bool SetNetworkFailureCallbackFunction(SRICommNetworkFailureCallbackFunction networkFailureCallback);

	std::string GetLastError();

	std::string mIpLocalServer;
	int mPortLocalServer;
	std::string mIpLocal;//不使用，//监听所有IP
	int mPortLocal;
private:


	struct sockaddr_in mServaddr;//远程服务器地址
	SOCKET mSocket;
	//struct sockaddr_in mLocalAddr;
	//struct sockaddr_in mLocalServerAddr;

	addrinfo mServerAddress;

	//bool ConnectUDP();

	bool SetKeepAlive();

	std::thread mThread;
	bool mIsStopThread;
	bool mIsTreadStoped;
	bool OpenThread();
	bool CloseThread();
	void UDPClientReceiverThread(int code);

	
	bool CheckTimeoutError();
	bool OnNetworkFailure();

	std::vector<CSRICommParser*> mParserList;

	SRICommNetworkFailureCallbackFunction mNetworkFailureCallback;

	std::string mLastError;
	void GetLastSocketError(std::string functionName);
};

#endif

