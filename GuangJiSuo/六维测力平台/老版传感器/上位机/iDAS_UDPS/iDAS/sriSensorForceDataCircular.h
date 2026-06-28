#ifndef SRI_SRISENSORFORCCEDADACIRCULAR_H
#define SRI_SRISENSORFORCCEDADACIRCULAR_H

#include "sriCommDefine.h"

#include <array>

class CSRISensorForceDataCircular
{
public:
	CSRISensorForceDataCircular();
	~CSRISensorForceDataCircular();
    bool AddData(ForceSensorData data);
    bool AddData_HB(ForceSensorData data);
    bool GetData(std::vector<ForceSensorData>& forceSensorDataVector);
    bool GetRealtimeData(ForceSensorData& forceSensorDataVector, int& index);
    bool GetRealtimeData_HB(ForceSensorData& forceSensorDataVector);
    size_t GetSize();
    bool GetSpecifiedPackageNumData( UINT16 targetNum,ForceSensorData& forceSensorDataVector);
    bool OnGetSpecifiedPackageNumData(UINT16 targetNum, ForceSensorData& forceSensorDataVector);


private:
    static constexpr size_t MAX_CAPACITY = 5000;
    std::array<ForceSensorData, MAX_CAPACITY> mSensorDataCache;
    size_t mHead;
    size_t mTail;
    size_t mSize;
    std::mutex mMutex;  // 互斥锁

    ForceSensorData mForceSensorDataVector_HB;//心跳包上传的数据
};//
#endif