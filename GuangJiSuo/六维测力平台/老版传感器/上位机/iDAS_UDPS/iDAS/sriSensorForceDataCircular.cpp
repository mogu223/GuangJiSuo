#include"sriSensorForceDataCircular.h"
#include <cstdlib> 

CSRISensorForceDataCircular::CSRISensorForceDataCircular()
{
	mHead = 0;
	mTail = 0;
	mSize = 0;
    mForceSensorDataVector_HB.packetNum = 0;
}

CSRISensorForceDataCircular::~CSRISensorForceDataCircular()
{
    
}



bool CSRISensorForceDataCircular::AddData(ForceSensorData data)
{
    std::lock_guard<std::mutex> lock(mMutex);//加锁
    if (mSize == MAX_CAPACITY)
    {
        // 缓存已满，覆盖最早的数据
        mHead = (mHead + 1) % MAX_CAPACITY;
    }
    else 
    {
        mSize++;
    }
    mSensorDataCache[mTail] = data;
    mTail = (mTail + 1) % MAX_CAPACITY;
    return true;
}
//心跳包上传的数据
bool CSRISensorForceDataCircular::AddData_HB(ForceSensorData data)
{
    mForceSensorDataVector_HB=data;
    return true;
}

 bool CSRISensorForceDataCircular::GetData(std::vector<ForceSensorData>& forceSensorDataVector)
 {
    std::lock_guard<std::mutex> lock(mMutex);//加锁
    //if (index >= mSize)
    //{
    //    throw std::out_of_range("Index out of range");//抛出异常
    //    return false;
    //}    
    if (mTail > mHead)
    {
        for (int i = mHead; i < mTail; i++)
        {
            forceSensorDataVector.push_back(mSensorDataCache[i]);       
        }
    }
    else if(mTail < mHead)
    {
        for (int i = mHead; i < MAX_CAPACITY; i++)
        {
            forceSensorDataVector.push_back(mSensorDataCache[i]);
        }
        for (int i = 0; i < mTail; i++)
        {
            forceSensorDataVector.push_back(mSensorDataCache[i]);
        }
    }
    mSize = 0;
    mHead = 0;
    mTail = 0;
    return true;
}

 bool CSRISensorForceDataCircular::GetRealtimeData_HB(ForceSensorData& forceSensorDataVector)
 {
     if (mForceSensorDataVector_HB.packetNum == 0)
     {
         for (int i = 0; i < 30; i++)
         {
             Sleep(100);
             if (mForceSensorDataVector_HB.packetNum != 0)
             {
                 break;
             }
         }
     }
     if (mForceSensorDataVector_HB.packetNum == 0)
     {
         return false;
     }
     forceSensorDataVector = mForceSensorDataVector_HB;


     return true;
 }


 //获取最新接收道到的数据
 //int mLastPackNum = 0;
 bool CSRISensorForceDataCircular::GetRealtimeData( ForceSensorData& forceSensorDataVector, int& index)
 {
     std::lock_guard<std::mutex> lock(mMutex);//加锁
     if (mSize == 0)
     {
         //throw std::out_of_range("No Sensor Data!!");//抛出异常
         return false;
     }
     if (mTail > 0)
     {
        forceSensorDataVector = mSensorDataCache[mTail - 1];
        index = mTail - 1;
     }
     else
     {
        forceSensorDataVector = mSensorDataCache[MAX_CAPACITY - 1];
        index = MAX_CAPACITY - 1;
     }
     

     //int changeNum = forceSensorDataVector.packetNum - mLastPackNum;
     //if ((changeNum > 1) && (changeNum != -65534))
     //{
 	   // printf("packetNum =%d    NewPacketNum =%d  \n", mLastPackNum, forceSensorDataVector.packetNum);
     //}
     //mLastPackNum = forceSensorDataVector.packetNum;



     //mSize = 0;//不删除，接收到新的数据之前还是返回当前值
     //mHead = 0;
     //mTail = 0;
     return true;
 }




 //根据编号获取缓存数据
 bool CSRISensorForceDataCircular::GetSpecifiedPackageNumData( UINT16 targetNum, ForceSensorData& forceSensorDataVector)
 {
    

     if (OnGetSpecifiedPackageNumData(targetNum,  forceSensorDataVector) == false)
     {
         return false;
     }
     if (targetNum != forceSensorDataVector.packetNum)
     {
         return false;
     }
     return true;
 }

 //根据编号获取缓存数据
 bool CSRISensorForceDataCircular::OnGetSpecifiedPackageNumData(UINT16 targetNum, ForceSensorData& forceSensorDataVector)
 {
     int tailIndex;
     ForceSensorData data;
     int difNum;
     if (GetRealtimeData(data, tailIndex) == false)
     {
         return false;
     }
     forceSensorDataVector = data;
     difNum = forceSensorDataVector.packetNum - targetNum;
     if (difNum == 0)
     {
         return true;
     }

     difNum += 3;////有些接收数据顺序错了，往前多找3个


     difNum = abs(difNum) % 65535;

     if (difNum > 65200)//用普通交换机延迟比较大，两边的包编号差测试发现可能有几十包的差别
     {
         difNum = 65536 - difNum;
     }




     if (difNum > 100)//差太多，不往后取//也可能是接收到的第一包//(经过普通交换机会有延迟)
     {
         return true;//返回最新的
     }

     std::lock_guard<std::mutex> lock(mMutex);//加锁
     if (mSize == 0)
     {
         return false;
     }

     for (int i = tailIndex - difNum; i <= tailIndex; i++)
     {
         int index = i;
         if (index < 0)
         {
             index = index + MAX_CAPACITY;
         }
         ForceSensorData calData = mSensorDataCache[index];
         if (calData.packetNum == targetNum)
         {
             forceSensorDataVector = calData;
             return true;
         }
     }

     return false;
 }



// 获取缓存的当前大小
size_t CSRISensorForceDataCircular::GetSize()
{
    std::lock_guard<std::mutex> lock(mMutex);//加锁
    return mSize;
}