#ifndef SRI_COMM_M8218_PARSER_H
#define SRI_COMM_M8218_PARSER_H

#include "sriCommParser.h"
#include "sriCommCircularBuffer.h"

class CSRICommM8218Parser: public CSRICommParser
{
public:
	CSRICommM8218Parser();
	~CSRICommM8218Parser();

	bool SetM8218CallbackFunction(SRICommM8218CallbackFunction m8218CallbackFunction);

	bool OnReceivedData(sockaddr_in remotrSockaddr,BYTE* data, int dataLen);
	bool OnNetworkFailure(std::string infor);
private:
	CSRICommCircularBuffer mCircularBuffer;
	SRICommM8218CallbackFunction mM8218CallbackFunction;

	bool ParseDataFromBuffer(int& delLen, float& fx, float& fy, float& fz, float& mx, float& my, float& mz,INT16& packetNum,BYTE& sensorId,int packetLenght, BYTE& protocolNo);
	int ParseGetHeadIndex(BYTE* data, int dataLen,int packetLenght);
	UINT32 GetCRC32(BYTE bytes[], UINT32 beginIndex, UINT32 len);
	int swapEndian(int value);

	bool OnParseDataFromBuffer(sockaddr_in remotrSockaddr, int packetLenght);
};
#endif

