#ifndef SRI_COMM_MANAGER_H
#define SRI_COMM_MANAGER_H

#include "sriCommDefine.h"
#include "sriCommUDPClient.h"
#include "sriCommATParser.h"
#include "sriCommM8218Parser.h"
#include "sriSensorForceDataCircular.h"
#include"sriSensorData.h"
#include <unordered_map>


class CSRICommManager
{
public:
	CSRICommManager();
	~CSRICommManager();

	bool Init(std::string ipLocalServer, int portLocalServer);
	bool Run();
	bool Stop();
	bool sriStartSample(int sampRate);
	bool sriStopSample();

	bool SendCommand(std::string command, std::string parames, double timeOutS);
	
	bool OnNetworkFailure(std::string infor);//通讯失败
	bool OnCommACK(std::string command);//ACK应答数据处理
	bool OnCommM8218(float fx, float fy, float fz, float mx, float my, float mz, UINT16 packetNum, sockaddr_in remotrSockaddr, BYTE sensorId, BYTE protocolNo);//GSD数据处理
	bool SetSensorDataZero(BYTE sensorId);
	bool SetAllSensorDataZero();

	bool GetData(BYTE sensorId, std::vector<ForceSensorData>& forceSensorDataVector);
	bool GetRealtimeData(BYTE sensorId, ForceSensorData& forceSensorDataVector);
	bool GetOnlineSensorsId(std::vector<BYTE>& sensorId);
	bool GetAllSensorRealtimeData(std::vector<ForceSensorData>& forceSensorDataVector);
	bool GetAllSensorData(std::vector < std::vector<ForceSensorData>>& forceSensorDataVector);

	bool GetAllSensorRealtimeData(std::unordered_map<BYTE, ForceSensorData>& forceSensorDataMap);
	bool GetAllSensorData(std::unordered_map<BYTE, std::vector<ForceSensorData>>& forceSensorDataMap);


private:
	struct SensorConnectManagerStruct
	{
		sockaddr_in RemotrSockAddr;
		std::shared_ptr<CSRISensorData> SRISensorDataManeger;
		std::chrono::time_point<std::chrono::high_resolution_clock> LastPacketTime;
		bool Online;//是否在线
	};


	struct SensorDataPacketInfos
	{
		//BYTE sensorId;
		UINT16 packetNum;//包编号//数据接收
		std::chrono::high_resolution_clock::time_point timestamp;
		UINT16 startPacketNum;
	};

	std::thread mCheckSensorThread;
	bool mIsStopThread = false;
	bool mIsTreadStoped = false;
	bool mIsBindCallbackFunction = false;

	CSRICommUDPClient mUDPClient;
	CSRICommATParser mATParser;//AT指令解析器
	CSRICommM8218Parser mM8218Parser;//GSD数据解析器

	//CSRISensorForceDataCircular mCSRISensorForceDataCircular;

	bool mSetSensorDataZeroFlag=false;
	bool mIsGetACK;
	std::string mCommandACK;
	std::string mParamesACK;
	std::string mSensorName;

	//ForceSensorData mForceSensorDataZero;//传感器零点

	bool BindCallbackFunction();


	//数据解析完后处理使用变量
	UINT16 LatestPackageNum;
	std::vector<SensorDataPacketInfos> FirstIdPacketInfosCache;
	int FirstIdPacketInfosCacheCount = 10;
	

	//std::unordered_map<BYTE, std::shared_ptr<CSRISensorData>> mSensorDataMap;
	//std::unordered_map<BYTE, sockaddr_in> mRemoteSockAddrMap;
	//std::unordered_map<BYTE, std::chrono::time_point<std::chrono::high_resolution_clock>> mLastPacketTimeMap;


	std::unordered_map<BYTE, SensorConnectManagerStruct> mSensorConnectManagerStructMap;


	std::unordered_map<BYTE, SensorDataPacketInfos> mSensorDataStartPacketNumMap;//所有传感器第一包数据的包编号用于后面处理对齐


	BYTE mFirstPacketNumSensorID;//以第一个数据包的起始作为包编号，后面的通过起始包编号的差对齐包编号

	void CheckSensorThreadFuction(int code);
	bool OnStartCheckSensorThread();

	bool GetSpecifiedPackageNumData(BYTE id, INT16 targetNum, ForceSensorData& data);
};


#endif

