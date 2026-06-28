#include "sriSensorManager.h"
#include "sriCommManager.h"

//清零，启动上传GSD(上传频率)，对外接口添加提示信息输出


CSRISensorManager::CSRISensorManager()
{
	mSensorManager = new CSRICommManager();
}


CSRISensorManager::~CSRISensorManager()
{
	delete mSensorManager;
}


//###################本地端口也要设(目前只能固定本地端口连接，换端口连接需要重启传感器)//###########
bool CSRISensorManager::sriRunSensorManager(std::string LocalServerIP, int LocalServerPort)
{
	if (mSensorManager->Init(LocalServerIP, LocalServerPort) == false)
	{
		return false;
	}
	return true;

}

bool CSRISensorManager::sriStartSample(BYTE sensorId, int sampRate)
{

	if (mSensorManager->sriStartSample(sampRate) == false)
	{
		return false;
	}

	return true;
}

bool CSRISensorManager::sriStopSample(BYTE sensorId)
{
	if (mSensorManager->sriStopSample() == false)
	{
		return false;
	}
	return true;
}


bool CSRISensorManager::GetSensorData(BYTE sensorId,std::vector<ForceSensorData>& forceSensorDataVector)
{
	return mSensorManager->GetData(sensorId, forceSensorDataVector);
}

bool CSRISensorManager::GetAllSensorData(std::vector < std::vector<ForceSensorData>>& forceSensorDataVector)
{
	return mSensorManager->GetAllSensorData(forceSensorDataVector);
}

bool CSRISensorManager::GetAllSensorData(std::unordered_map<BYTE, std::vector<ForceSensorData>>& forceSensorDataMap)
{
	return mSensorManager->GetAllSensorData(forceSensorDataMap);
}

bool CSRISensorManager::GetRealtimeData(BYTE sensorId,ForceSensorData& forceSensorDataVector)
{
	return mSensorManager->GetRealtimeData(sensorId, forceSensorDataVector);
}
bool CSRISensorManager::GetAllSensorRealtimeData(std::vector<ForceSensorData>& forceSensorDataVector)
{
	return mSensorManager->GetAllSensorRealtimeData(forceSensorDataVector);
}

bool CSRISensorManager::GetAllSensorRealtimeData(std::unordered_map<BYTE, ForceSensorData>& forceSensorDataMap)
{
	return mSensorManager->GetAllSensorRealtimeData(forceSensorDataMap);
}

bool CSRISensorManager::SetSensorDataZero(BYTE sensorId)
{
	return mSensorManager->SetSensorDataZero(sensorId);
}

bool CSRISensorManager::SetAllSensorDataZero()
{
	return mSensorManager->SetAllSensorDataZero();
}

bool CSRISensorManager::GetOnlineSensorsId(std::vector<BYTE>& sensorIds)
{
	return mSensorManager->GetOnlineSensorsId(sensorIds);
}




//


