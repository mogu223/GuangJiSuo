#include "sriCommManager.h"
#include <cstdlib> 

int mLastPacketNum = -1;
//bool mFirstRealing = false;

CSRICommManager::CSRICommManager() 
{
	//mFirstRealing = true;
	mLastPacketNum = -1;
}


CSRICommManager::~CSRICommManager()
{
}
//初始化
bool CSRICommManager::Init(std::string ipLocalServer, int portLocalServer)
{
	mUDPClient.OpenUDPServer(ipLocalServer, portLocalServer);
	BindCallbackFunction();

	//启动接收线程
	if (mUDPClient.Connect() == false)
	{
		return false;
	}
	OnStartCheckSensorThread();
	return true;
}

bool CSRICommManager::BindCallbackFunction()
{
	if (mIsBindCallbackFunction == false)
	{
		mUDPClient.AddCommParser(&mATParser);
		mUDPClient.AddCommParser(&mM8218Parser);


		//bind Network communication failure processing function	
		//绑定网络通讯失败处理函数 
		SRICommNetworkFailureCallbackFunction networkFailureCallback = std::bind(&CSRICommManager::OnNetworkFailure, this, std::placeholders::_1);
		mUDPClient.SetNetworkFailureCallbackFunction(networkFailureCallback);

		//bind ACK command Processing function
		//绑定ACK指令处理函数   	
		SRICommATCallbackFunction atCallback = std::bind(&CSRICommManager::OnCommACK, this, std::placeholders::_1);
		mATParser.SetATCallbackFunction(atCallback);

		//bind M8128 Data processing function
		//绑定M8128数据处理函数
		SRICommM8218CallbackFunction m8218Callback = std::bind(&CSRICommManager::OnCommM8218, this,
			std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
			std::placeholders::_4, std::placeholders::_5, std::placeholders::_6,
			std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10);
		mM8218Parser.SetM8218CallbackFunction(m8218Callback);
		mIsBindCallbackFunction = true;
	}
	return true;
}

//启动
bool CSRICommManager::Run()
{
	return true;
}


bool CSRICommManager::sriStartSample(int sampRate)
{
	return true;
}

bool CSRICommManager::sriStopSample()
{
	if (SendCommand("GSD", "STOP", 0) == false)
	{
		//GSD has no ACK
		return false;
	}
	return true;
}

bool CSRICommManager::Stop()
{
	mUDPClient.CloseUDP();
	return true;
}

//通讯异常函数
bool CSRICommManager::OnNetworkFailure(std::string infor)
{
	printf("OnNetworkFailure = %s\n", infor.data());
	return true;
}


//send command 
//发送命令
bool CSRICommManager::SendCommand(std::string command, std::string parames,double timeOutS)
{
	int timeOutMs = (int)(timeOutS * 1000);
	mIsGetACK = false;
	mCommandACK = "";
	mParamesACK = "";

	//Combination command
	//组合AT指令
	std::string atCommand = "AT+" + command + "=" + parames + "\r\n";
	printf("[%d]->>>>>>>>>>>>>>>>>>>>>>SendCommand:::%s", mUDPClient.mPortLocalServer, atCommand.data());
	if (mUDPClient.OnSendData((BYTE*)atCommand.data(), (int)atCommand.length()) == false)
	{
		return false;
	}

	if (timeOutS == 0)//timeOutS=0：不进行验证，比如AT+GSD=STOP
	{
		return true;
	}


	//wait ACK
#ifdef  IS_WINDOWS_OS
	std::clock_t start = clock();
	while (true)
	{
		if ((mIsGetACK == true)&& (mCommandACK == command))
		{
			break;
		}
		if (parames == "")
		{
			break;
		}
		std::clock_t end = clock();
		long span = end - start;
		if (span >= timeOutMs)//10000,10s
		{
			return false;
		}
	}
#else
	timeval start, end;
	gettimeofday(&start, NULL);
	while (true)
	{
		if ((mIsGetACK == true)&& (mCommandACK == command))
		{
			break;
		}
		gettimeofday(&end, NULL);
		long span = 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000;
		if (span >= timeOutMs)//10s
		{
			return false;
		}
	}
#endif
	if (parames != "")
	{
		printf("ACK+%s=%s", mCommandACK.data(), mParamesACK.data());
	}

	//
	return true;
}

//ACK command processing
//ACK应答处理
bool CSRICommManager::OnCommACK(std::string command)
{

	printf("-------------------ACKcommand=%s", command.data());

	int index = (int)command.find('=');
	if (index == -1)
	{
		mCommandACK = command;
		mParamesACK = "";
	}
	else
	{
		mCommandACK = command.substr(0, index);
		mParamesACK = command.substr(index+1);
	}
	mCommandACK = mCommandACK.substr(4);	
	if ((int)command.find("$OK") != -1)
	{
		mIsGetACK = true;//应答正确		
	}
	else
	{
		mIsGetACK = false;//应答错误		 
	}
	

	return true;
}



//M8128 data
//M8128数据
bool CSRICommManager::OnCommM8218(float fx, float fy, float fz, float mx, float my, float mz,UINT16 packetNum, sockaddr_in remotrSockaddr, BYTE sensorId,BYTE protocolNo)
{
	
	//UINT16 num = packetNum;
	//检测传感器ID是否初次连接
	if (mSensorConnectManagerStructMap.find(sensorId) == mSensorConnectManagerStructMap.end())
	{
		if (mSensorConnectManagerStructMap.size() == 0)
			mFirstPacketNumSensorID = sensorId;//记录第一个传感器起始包编号，后面其他传感器以第一个对齐

		//初次连接保存连接状态信息
		SensorConnectManagerStruct  sensorConnectManager;
		sensorConnectManager.LastPacketTime = std::chrono::high_resolution_clock::now();
		sensorConnectManager.RemotrSockAddr = remotrSockaddr;
		sensorConnectManager.SRISensorDataManeger= std::make_shared<CSRISensorData>(sensorId);
		sensorConnectManager.Online = true;
		mSensorConnectManagerStructMap[sensorId] = sensorConnectManager;

		if (protocolNo != 0x16)
		{
			return true;//心跳包不处理数据
		}

		//如果不是第一个传感器，包编号和第一个对齐
		UINT16 startPacketNum = packetNum;
		if (mFirstPacketNumSensorID != sensorId)
		{
			int endIndex = FirstIdPacketInfosCache.size() - 1;
			startPacketNum = FirstIdPacketInfosCache[endIndex].packetNum;
			if (FirstIdPacketInfosCache.size() > 2)
			{

				for (int i = endIndex-1; i >=0 ; i--)
				{
					auto duration = std::chrono::duration_cast<std::chrono::microseconds>(FirstIdPacketInfosCache[endIndex].timestamp - FirstIdPacketInfosCache[i].timestamp);
					int us = duration.count();
					if (us >= 1000)
						break;
					//小于1ms认为是接收延迟，对齐的时候以1ms内最早的点
					//解决两个同事上电，由于接收原因第一个传感器包接收到2个或者以上的数据包（时间差在1ms内），但第二个传感器才接收到第1个数据包.这种情况应该是把两个上传的第一包作为起始
					//，这样在脉冲触发的时候才不会丢包（不这样做可能丢掉第一个传感器前面的数据包）
					startPacketNum = FirstIdPacketInfosCache[i].packetNum;
				}
			}		
		}

		//
		SensorDataPacketInfos sensorData;
		sensorData.packetNum = packetNum;
		//sensorData.sensorId = sensorId;
		sensorData.timestamp = std::chrono::high_resolution_clock::now();
		sensorData.startPacketNum = startPacketNum;
		mSensorDataStartPacketNumMap[sensorId] = sensorData;//记录起始包编号


	}

	mSensorConnectManagerStructMap[sensorId].Online = true;	
	mSensorConnectManagerStructMap[sensorId].LastPacketTime = std::chrono::high_resolution_clock::now();



	if (protocolNo != 0x16)
	{
		mSensorConnectManagerStructMap[sensorId].SRISensorDataManeger->OnSensorDataReceive_HB(fx, fy, fz, mx, my, mz, packetNum);
		return true;//心跳包不处理数据
	}

	if (sensorId != mFirstPacketNumSensorID)//包编号，后面其他传感器以第一个对齐
	{	

		packetNum = (packetNum- mSensorDataStartPacketNumMap[sensorId].packetNum+ mSensorDataStartPacketNumMap[sensorId].startPacketNum)%65536;
		if (packetNum < 0)
			packetNum += 65536;

	}
	else
	{
		SensorDataPacketInfos sensorData;
		sensorData.packetNum = packetNum;
		sensorData.timestamp = std::chrono::high_resolution_clock::now();
		sensorData.startPacketNum = packetNum;
		FirstIdPacketInfosCache.push_back(sensorData);
		if (FirstIdPacketInfosCache.size() > 10)
		{
			FirstIdPacketInfosCache.erase(FirstIdPacketInfosCache.begin());
		}
	}

	mSensorConnectManagerStructMap[sensorId].SRISensorDataManeger->OnSensorDataReceive(fx, fy, fz, mx, my, mz, packetNum);


	return true;
}

//M8128 data
//M8128 传感器数据清零
bool CSRICommManager::SetSensorDataZero(BYTE sensorId)
{
	if (mSensorConnectManagerStructMap.find(sensorId) == mSensorConnectManagerStructMap.end())
	{
		return false;
	}
	if (mSensorConnectManagerStructMap[sensorId].Online == false)
	{
		return false;
	}
	mSensorConnectManagerStructMap[sensorId].SRISensorDataManeger->SetSensorDataZero();
	return true;
}



bool CSRICommManager::GetData(BYTE sensorId,std::vector<ForceSensorData>& forceSensorDataVector)
{
	forceSensorDataVector.clear();
	if (mSensorConnectManagerStructMap.find(sensorId) == mSensorConnectManagerStructMap.end())
	{
		return false;
	}
	if (mSensorConnectManagerStructMap[sensorId].Online == false)
	{
		return false;
	}
	return mSensorConnectManagerStructMap[sensorId].SRISensorDataManeger->GetData(forceSensorDataVector);
}

bool CSRICommManager::GetAllSensorData( std::vector < std::vector<ForceSensorData>>& forceSensorDataVector)
{
	forceSensorDataVector.clear();
	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
	{
		if (it->second.Online = true)
		{
			std::vector<ForceSensorData> data;
			if (it->second.SRISensorDataManeger->GetData(data) == true)
			{
				forceSensorDataVector.push_back(data);
			}		
		}

	}
	return true;
}

bool CSRICommManager::GetAllSensorData(std::unordered_map<BYTE, std::vector<ForceSensorData>>& forceSensorDataMap)
{
	forceSensorDataMap.clear();
	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
	{
		if (it->second.Online = true)
		{		
			std::vector<ForceSensorData> data;
			if (it->second.SRISensorDataManeger->GetData(data) == true)
			{
				forceSensorDataMap[it->first] = data;
			}		
		}

	}
	return true;
}

bool CSRICommManager::GetRealtimeData(BYTE sensorId, ForceSensorData& forceSensorDataVector)
{
	int index;
	if (mSensorConnectManagerStructMap.find(sensorId) == mSensorConnectManagerStructMap.end())
	{
		return false;
	}
	if (mSensorConnectManagerStructMap[sensorId].Online == false)
	{
		return false;
	}
	return mSensorConnectManagerStructMap[sensorId].SRISensorDataManeger->GetRealtimeData(forceSensorDataVector,index);
}



bool CSRICommManager::GetAllSensorRealtimeData(std::vector<ForceSensorData>& forceSensorDataVector)
{
	forceSensorDataVector.clear();
	std::vector<int> packetNumVector;
	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
	{
		if (it->second.Online == true)
		{
			ForceSensorData data;
			int index;
			if (it->second.SRISensorDataManeger->GetRealtimeData(data,index) == true)
			{
				forceSensorDataVector.push_back(data);		
			}			
		}
	}
	return true;
}




bool CSRICommManager::GetAllSensorRealtimeData(std::unordered_map<BYTE, ForceSensorData>& forceSensorDataMap)
{
	forceSensorDataMap.clear();
	int nextPacketNum = (mLastPacketNum + 1)% 65536;



	//先正常获取每个数据
	std::vector<BYTE> sensorID;
	std::vector<int> indexList;
	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
	{
		if (it->second.Online == true)
		{
			ForceSensorData data;
			int index;
			if (it->second.SRISensorDataManeger->GetRealtimeData(data, index) == true)
			{
				forceSensorDataMap[it->first] = data;
				sensorID.push_back(it->first);	
				indexList.push_back(index);
			}		
		}
	}




	if (sensorID.size() == 0)
		return false;
	 
	//第一包数据
	if (mLastPacketNum == -1)
	{
		//20251119解决第一包数据读取不到问题
		//mLastPacketNum = forceSensorDataMap[sensorID[0]].packetNum;
		mLastPacketNum = forceSensorDataMap[sensorID[0]].packetNum-1;
		if (mLastPacketNum < 0)
			mLastPacketNum += 65536;

		for (int i = 1; i < sensorID.size(); i++)
		{
			int packNum= forceSensorDataMap[sensorID[i]].packetNum;
			int difNum = mLastPacketNum - packNum;
			if (difNum == 0)
				continue;
			//取包编号比较小的作为起始
			if (abs(difNum) > 65300)
			{
				if (difNum < 0)
				{
					mLastPacketNum = packNum;
				}

			}
			else if (difNum > 0)
			{
				mLastPacketNum = packNum;
			}

		}
		nextPacketNum = (mLastPacketNum + 1) % 65536;
	}


	//检查获取到的数据是否是新(nextPacketNum)的数据编号,如果不是尝试重新获取
	bool ret = true;
	bool isHasNewData = true;
	int diffNum = 0;
	for (int i = 0; i < sensorID.size(); i++)
	{
		if (nextPacketNum == forceSensorDataMap[sensorID[i]].packetNum)//数据对了
		{
			continue;
		}
		if (mLastPacketNum == forceSensorDataMap[sensorID[i]].packetNum)//数据没有刷新
			break;
	    //有数据刷新，查找获取新的数据包
		int tailIndex = indexList[i];
		ForceSensorData data;
		if(GetSpecifiedPackageNumData(sensorID[i],  nextPacketNum, data)==false)
		{
			ret = false;
			diffNum = data.packetNum - nextPacketNum;
			if (diffNum < -65200)
			{
				diffNum += 65536;
			}
			break;			
		}
		forceSensorDataMap[sensorID[i]] = data;	
	}


	//找不到指定编号，且跳过的编号超过10个，说明可能丢包了,往后面找
	int diffNumTh = 10;
	if ((ret == false) && diffNum > diffNumTh)
	{
		while (true)
		{
			nextPacketNum = (nextPacketNum + 1) % 65536;
			for (int i = 0; i < sensorID.size(); i++)
			{
				ForceSensorData data;
				if (GetSpecifiedPackageNumData(sensorID[i], nextPacketNum, data) == false)
				{

					break;			
				}

				forceSensorDataMap[sensorID[i]] = data;
			}
			diffNum--;
			if (diffNum < diffNumTh)
			{
				break;
			}
		}
	}



	ret = true;
	//检查是否每个传感器都已经刷新，如果没有刷新则返回上一包数据
	for (int i = 0; i < sensorID.size(); i++)
	{
		if(forceSensorDataMap[sensorID[i]].packetNum!= nextPacketNum)
		{
			isHasNewData = false;
		}
	}
	if (isHasNewData == false)//有id的数据没有刷新，用回上一个编号数据
	{
		for (int i = 0; i < sensorID.size(); i++)
		{
			ForceSensorData data;
			if (GetSpecifiedPackageNumData(sensorID[i],  nextPacketNum-1, data) == false)
			{
				ret = false;
				break;
			}	

			forceSensorDataMap[sensorID[i]] = data;
		}

	
	}

	if (mLastPacketNum == forceSensorDataMap[sensorID[0]].packetNum)
	{
		forceSensorDataMap.clear();
		return false;//
	}


	mLastPacketNum = forceSensorDataMap[sensorID[0]].packetNum;
	
	//Test
	//if (sensorID.size() >= 2)
	//{
	//	if (forceSensorDataMap[sensorID[0]].packetNum != forceSensorDataMap[sensorID[1]].packetNum)
	//	{
	//		printf("AAAAAAAAAA  packetNum1 =%d    packetNum2 =%d  \n", forceSensorDataMap[sensorID[0]].packetNum, forceSensorDataMap[sensorID[1]].packetNum);
	//	}	
	//}


	
	return ret;
}






//bool CSRICommManager::GetAllSensorRealtimeData(std::unordered_map<BYTE, ForceSensorData>& forceSensorDataMap)
//{
//	forceSensorDataMap.clear();
//	int nextPacketNum = (mLastPacketNum + 1)% 65536;
//
//
//	//test
//	if ((nextPacketNum == 65535) || (nextPacketNum == 0))
//	{
//		nextPacketNum = (mLastPacketNum + 1) % 65536;
//	}
//
//
//	//先正常获取每个数据
//	std::vector<BYTE> sensorID;
//	std::vector<int> indexList;
//	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
//	{
//		if (it->second.Online == true)
//		{
//			ForceSensorData data;
//			int index;
//			if (it->second.SRISensorDataManeger->GetRealtimeData(data, index) == true)
//			{
//				forceSensorDataMap[it->first] = data;
//				sensorID.push_back(it->first);	
//				indexList.push_back(index);
//			}		
//		}
//	}
//
//
//
//
//	if (sensorID.size() == 0)
//		return false;
//	 
//	//每个传感器尝试获取新的数据包
//	bool ret = true;
//	bool isHasNewData = true;
//	for (int i = 0; i < sensorID.size(); i++)
//	{
//		if (nextPacketNum == forceSensorDataMap[sensorID[i]].packetNum)//数据对了
//		{
//			//isHasNewDataVector[i] = true;
//			continue;
//		}
//		if (mLastPacketNum == forceSensorDataMap[sensorID[i]].packetNum)//数据没有刷新
//			continue;
//	    //有数据刷新，查找获取新的数据包
//		int tailIndex = indexList[i];
//		ForceSensorData data;
//		if(GetSpecifiedPackageNumData(sensorID[i],  nextPacketNum, data)==false)
//		{
//			ret = false;
//			break;			
//		}
//		forceSensorDataMap[sensorID[i]] = data;	
//	}
//
//
//
//
//
//
//	//检查是否每个传感器都已经刷新，如果没有刷新则返回上一包数据
//	for (int i = 0; i < sensorID.size(); i++)
//	{
//		//if (isHasNewDataVector[i] == false)
//		if(forceSensorDataMap[sensorID[i]].packetNum!= nextPacketNum)
//		{
//			isHasNewData = false;
//		}
//	}
//	if (isHasNewData == false)//有id的数据没有刷新，用回上一个编号数据
//	{
//		for (int i = 0; i < sensorID.size(); i++)
//		{
//			ForceSensorData data;
//			if (GetSpecifiedPackageNumData(sensorID[i],  nextPacketNum-1, data) == false)
//			{
//				break;
//				ret = false;
//			}	
//
//
//
//			forceSensorDataMap[sensorID[i]] = data;
//		}
//
//	
//	}
//
//	mLastPacketNum = forceSensorDataMap[sensorID[0]].packetNum;
//	
//
//
//	if (forceSensorDataMap[sensorID[0]].packetNum != forceSensorDataMap[sensorID[1]].packetNum)
//	{
//		printf("AAAAAAAAAA  packetNum1 =%d    packetNum2 =%d  \n", forceSensorDataMap[sensorID[0]].packetNum, forceSensorDataMap[sensorID[1]].packetNum);
//	}
//
//	
//	return true;
//}






bool CSRICommManager::GetSpecifiedPackageNumData(BYTE id,INT16 targetNum, ForceSensorData& data)
{
	return mSensorConnectManagerStructMap[id].SRISensorDataManeger->GetSpecifiedPackageNumData(targetNum, data); 
}





bool CSRICommManager::SetAllSensorDataZero()
{
	for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
	{
		//ForceSensorData data;
		if (it->second.Online == true)
		{
			it->second.SRISensorDataManeger->SetSensorDataZero();		
		}

	}
	return true;
}


bool CSRICommManager::GetOnlineSensorsId(std::vector<BYTE>& sensorIds)
{
	sensorIds.clear();
	sensorIds.reserve(mSensorConnectManagerStructMap.size());
	for (const auto& pair : mSensorConnectManagerStructMap)
	{
		if (pair.second.Online == true)
		{
			sensorIds.push_back(pair.first);	
		}
		
	}
	return true;
}



bool CSRICommManager::OnStartCheckSensorThread()
{
	if (mCheckSensorThread.joinable() == false)
	{
		mCheckSensorThread = std::thread(&CSRICommManager::CheckSensorThreadFuction, this, 0);
	}

	return true;
}

void CSRICommManager::CheckSensorThreadFuction(int code)
{
	mIsStopThread = false;
	mIsTreadStoped = false;
	float TimeOutThMS = 5000;//5秒没有接收到数据视为掉线//数据停止，可能有2-3S时间才有心跳包

	while (true)
	{
		for (auto it = mSensorConnectManagerStructMap.begin(); it != mSensorConnectManagerStructMap.end(); ++it)
		{
			auto nawTime = std::chrono::high_resolution_clock::now();
			auto lastTime = it->second.LastPacketTime;
			auto duration = nawTime - lastTime;
			auto spanMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
			int spanMS = spanMilliseconds.count();
			if (spanMS > TimeOutThMS)
			{
				it->second.Online = false;
			}
			//else
			//{
			//	it->second.Online = true;
			//}
		}
		Sleep(1000);
	}
	mIsTreadStoped = true;
}