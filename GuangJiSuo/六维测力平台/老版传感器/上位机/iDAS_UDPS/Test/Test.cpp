// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "sriSensorManager.h"

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread> 
#include <string>
//
//bool t1()
//{
//    std::cout << "Hello World!\n";
//    CSRISensorManager sensorManager;
//    if (sensorManager.sriRunSensorManager("192.168.0.22", 4008) == false)
//    {
//        std::cout << "sriRunSensorManager fail!\n";
//    }
//
//    std::vector<int> sensorIds;
//    sensorManager.GetOnlineSensorsId(sensorIds);
//    int skip = 0;
//    int count = 0;
//    return true;
//}
//
//
//
//int main()
//{
//    t1();
//    std::cout << "Hello World!\n";
//    t1();
//    std::cout << "Hello World!\n";
//
//}


int main()
{

    std::cout << "Hello World!\n";

    CSRISensorManager sensorManager;


    if (sensorManager.sriRunSensorManager( "192.168.0.22", 4009) == false)
    {
        std::cout << "sriRunSensorManager fail!\n";
    }
    Sleep(10);


    if (sensorManager.sriRunSensorManager("192.168.0.22", 4008) == false)
    {
        std::cout << "sriRunSensorManager fail!\n";
    }
    Sleep(10);


    std::vector<BYTE> sensorIds;
    sensorManager.GetOnlineSensorsId(sensorIds);
    //for (int i = 0; i < sensorIds.size(); i++)
    //{
    //    sensorManager.SetSensorDataZero(sensorIds[i]);
    //}


    int skip = 0;
    int count = 0;
    //Sleep(3000);
    //sensorManager.SetAllSensorDataZero();
    int packetNum = 0;


    int ti = 1;

    bool isFirst = true;
    while (true)
    {
        count++;
        //if (count == 500)
        //{
        //    sensorManager.SetAllSensorDataZero();
        //    count=0;
        //}

        sensorManager.GetOnlineSensorsId(sensorIds);
        std::string  str="";
        for (int i = 0; i < sensorIds.size(); i++)
        {
            str += std::to_string(sensorIds[i]) + ";";
        }

        if ((sensorIds.size() > 0)&&(isFirst==true))
        {
            sensorManager.SetAllSensorDataZero();
            isFirst = false;
        }
        //if (str != "")
        //{
        //    std::cout << "sensorIds::" << str<<"\r\n";
        //}
        if (str == "")
        {
            std::cout << "No Sensor Online::!!!!!!!!!!!!!!!!" << "\r\n";
        }


        //获取所有数据
        //std::unordered_map<BYTE, std::vector<ForceSensorData>> forceSensorDataMap;
        //sensorManager.GetAllSensorData(forceSensorDataMap);
        //for (auto it = forceSensorDataMap.begin(); it != forceSensorDataMap.end(); ++it)
        //{
        //    std::vector<ForceSensorData> data = it->second;
        //    if ((data.size() > 0)&& (data.size() <20))
        //    {         
        //        for (int i = 0; i < data.size(); i++)
        //        {
        //            std::cout << data[i].packetNum << ",";
        //        }
        //        std::cout << std::endl;
        //    }
        //}



        std::unordered_map<BYTE, ForceSensorData> realtimeForceSensorDataMap;
        bool ret=sensorManager.GetAllSensorRealtimeData(realtimeForceSensorDataMap);
        if (ret == false)
        {
            Sleep(0.1);
            continue;
        }
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<UINT16> packetNumVector;
        int testCount = 0;
        for (auto it = realtimeForceSensorDataMap.begin(); it != realtimeForceSensorDataMap.end(); ++it)
        {
            testCount++;
            ForceSensorData forceData= it->second;         
            //if (packetNum == forceData.packetNum)
            //    break;


            //if (ti % 100 == 0)
            {
                //sensorManager.SetAllSensorDataZero();
                printf("[%d]SensorId[%d] =%d  %f, %f, %f,  %f, %f, %f   momentArm： %f, %f\n",
                    ti, it->first, forceData.packetNum, forceData.channels[0], forceData.channels[1], forceData.channels[2],
                    forceData.channels[3], forceData.channels[4], forceData.channels[5], forceData.momentArm_X, forceData.momentArm_Y);
                //printf("[%d]SensorId[%d] =%d \n",ti,it->first, forceData.packetNum);
                ti = 0;
            }



            //if (it->first == 0)
            //{
            //    printf("[%d]SensorId[%d] =%d  \n",ti,it->first, forceData.packetNum);

            //}

             
            //printf("[%d]SensorId[%d] =%d  %f, %f, %f,  %f, %f, %f   momentArm： %f, %f\n",
            //    ti,it->first, forceData.packetNum, forceData.channels[0], forceData.channels[1], forceData.channels[2],
            //    forceData.channels[3], forceData.channels[4], forceData.channels[5], forceData.momentArm_X, forceData.momentArm_Y);


            //packetNumVector.push_back(forceData.packetNum);
            //if (packetNumVector.size() > 1)
            //{
            //    if (packetNumVector[0]!= packetNumVector[1])
            //    {
            //        printf("packetNum1 =%d    packetNum2 =%d  \n", packetNumVector[0], packetNumVector[1]);               
            //    }           
            //}


            //printf("[%d]SensorId[%d] =%d  %f, %f, %f,  %f, %f, %f   momentArm： %f, %f\n",
            //    ti,it->first, forceData.packetNum, forceData.channels[0], forceData.channels[1], forceData.channels[2],
            //    forceData.channels[3], forceData.channels[4], forceData.channels[5], forceData.momentArm_X, forceData.momentArm_Y);



            int changeNum = forceData.packetNum - packetNum;
            if ((std::abs(changeNum) > 1) && (changeNum != -65534))
            {
                printf("packetNum =%d    NewPacketNum =%d  \n", packetNum,forceData.packetNum);
            }

            packetNum = forceData.packetNum;
            ti++;

            
        }

        //auto end = std::chrono::high_resolution_clock::now();

        //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //if(count%5==0)
        //    std::cout << "操作耗时: " << duration.count() << "微秒" << std::endl;
        Sleep(0.1);



        //if ((realtimeForceSensorDataMap.size() > 0) && (isFirst == true))
        //{
        //    sensorManager.SetAllSensorDataZero();
        //    isFirst = false;
        //}



        //std::unordered_map<BYTE, std::vector<ForceSensorData>> forceSensorDataMap;
        //sensorManager.GetAllSensorData(forceSensorDataMap);
        //for (auto it = forceSensorDataMap.begin(); it != forceSensorDataMap.end(); ++it)
        //{
        //    std::vector<ForceSensorData> dataVector;
        //    dataVector = it->second;
        //    int count = dataVector.size();
        //    printf("New Packet!!!!!!!!!!!!!!!!!!!!:::::::::::%d\r\n", count);
        //    for (int i = 0; i < count; i++)
        //    {
        //        if (i % 10 == 0)
        //        {
        //            printf("[%d]packetNum = ", it->first);
        //        }
        //        printf("  %d ", dataVector[i].packetNum);
        //        if (i % 10 == 9)
        //        {
        //            printf("\r\n");
        //        }
        //    }
        //    printf("\r\n");
        //
        //}


        //Sleep(1000);


    }

}


