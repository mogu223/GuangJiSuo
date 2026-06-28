#ifndef SRI_SRISENSORDATA_H
#define SRI_SRISENSORDATA_H
#include "sriCommDefine.h"
#include "sriSensorForceDataCircular.h"
#include <unordered_map>

class CSRISensorData
{
public:

	CSRISensorData(BYTE sensorId);
	~CSRISensorData();
	bool OnSensorDataReceive(float fx, float fy, float fz, float mx, float my, float mz, INT16 packetNum);
	//心跳包上传的数据
	bool OnSensorDataReceive_HB(float fx, float fy, float fz, float mx, float my, float mz, INT16 packetNum);
	bool SetSensorDataZero();
	bool GetData(std::vector<ForceSensorData>& forceSensorDataVector);
	bool GetRealtimeData(ForceSensorData& forceSensorDataVector, int& index);
	bool GetSpecifiedPackageNumData(UINT16 targetNum, ForceSensorData& forceSensorDataVector);
private:
	int mSensorId;
	CSRISensorForceDataCircular mCSRISensorForceDataCircular;
	ForceSensorData mForceSensorDataZero;//传感器零点

	float mCalMomentArmMinForce;
	//bool mSetSensorDataZeroFlag = false;//清零标志
};//
#endif