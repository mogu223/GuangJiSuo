#include"sriSensorData.h"

CSRISensorData::CSRISensorData(BYTE sensorId)
{
	ForceSensorData zeroData;
	zeroData.packetNum = 0;
	zeroData.channels[0] = 0;
	zeroData.channels[1] = 0;
	zeroData.channels[2] = 0;
	zeroData.channels[3] = 0;
	zeroData.channels[4] = 0;
	zeroData.channels[5] = 0;
	mForceSensorDataZero = zeroData;
	mCalMomentArmMinForce = 2;
	mSensorId = sensorId;
}
CSRISensorData::~CSRISensorData()
{

}

bool CSRISensorData::SetSensorDataZero()
{
	ForceSensorData realtimeData;
	int index;
	if (mCSRISensorForceDataCircular.GetRealtimeData(realtimeData, index)==true)
	{
		//realtimeData是已经减去0点的数据了
		for (int i = 0; i < 6; i++)
		{
			mForceSensorDataZero.channels[i] = mForceSensorDataZero.channels[i] + realtimeData.channels[i];		
		}
	}
	else//没有实时数据则获取心跳包数据
	{

		mCSRISensorForceDataCircular.GetRealtimeData_HB(realtimeData);
		//realtimeData是已经减去0点的数据了
		for (int i = 0; i < 6; i++)
		{
			mForceSensorDataZero.channels[i] = mForceSensorDataZero.channels[i] + realtimeData.channels[i];
		}
	}

	return true;
}


bool CSRISensorData::OnSensorDataReceive(float fx, float fy, float fz, float mx, float my, float mz, INT16 packetNum)
{
	ForceSensorData data;
	data.packetNum = packetNum;
	data.channels[0] = fx - mForceSensorDataZero.channels[0];
	data.channels[1] = fy - mForceSensorDataZero.channels[1];
	data.channels[2] = fz - mForceSensorDataZero.channels[2];
	data.channels[3] = mx - mForceSensorDataZero.channels[3];
	data.channels[4] = my - mForceSensorDataZero.channels[4];
	data.channels[5] = mz - mForceSensorDataZero.channels[5];
	data.sensorId = mSensorId;
	if (std::fabs(data.channels[2]) > mCalMomentArmMinForce)
	{	
		data.momentArm_X = data.channels[4] / data.channels[2];
		data.momentArm_Y = -data.channels[3] / data.channels[2];	
	}
	else
	{
		data.momentArm_X =0;
		data.momentArm_Y =0;
	}
	mCSRISensorForceDataCircular.AddData(data);
	return true;
}

bool CSRISensorData::OnSensorDataReceive_HB(float fx, float fy, float fz, float mx, float my, float mz, INT16 packetNum)
{
	ForceSensorData data;
	data.packetNum = packetNum;
	if (mForceSensorDataZero.packetNum != 0)
	{
		data.channels[0] = fx - mForceSensorDataZero.channels[0];
		data.channels[1] = fy - mForceSensorDataZero.channels[1];
		data.channels[2] = fz - mForceSensorDataZero.channels[2];
		data.channels[3] = mx - mForceSensorDataZero.channels[3];
		data.channels[4] = my - mForceSensorDataZero.channels[4];
		data.channels[5] = mz - mForceSensorDataZero.channels[5];	
	}
	else
	{
		data.channels[0] = fx;
		data.channels[1] = fy;
		data.channels[2] = fz;
		data.channels[3] = mx;
		data.channels[4] = my;
		data.channels[5] = mz;
	}
	data.sensorId = mSensorId;
	if (std::fabs(data.channels[2]) > mCalMomentArmMinForce)
	{	
		data.momentArm_X = data.channels[4] / data.channels[2];
		data.momentArm_Y = -data.channels[3] / data.channels[2];	
	}
	else
	{
		data.momentArm_X =0;
		data.momentArm_Y =0;
	}
	mCSRISensorForceDataCircular.AddData_HB(data);
	return true;
}


bool CSRISensorData::GetData(std::vector<ForceSensorData>& forceSensorDataVector)
{
	return mCSRISensorForceDataCircular.GetData(forceSensorDataVector);
}

bool CSRISensorData::GetRealtimeData(ForceSensorData& forceSensorDataVector,int& index)
{
	return mCSRISensorForceDataCircular.GetRealtimeData(forceSensorDataVector, index);
}

bool CSRISensorData::GetSpecifiedPackageNumData( UINT16 targetNum, ForceSensorData& forceSensorDataVector)
{
	return mCSRISensorForceDataCircular.GetSpecifiedPackageNumData( targetNum, forceSensorDataVector);
}