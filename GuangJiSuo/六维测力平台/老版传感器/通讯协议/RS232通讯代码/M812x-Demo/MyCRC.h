#pragma once

#include "MyCRC.h"
class CMyCRC
{
public:
	CMyCRC(void);
	~CMyCRC(void);
	BYTE GetCRC8(BYTE *pDat,BYTE bytes);
	WORD GetCRC16(BYTE *puchMsg, WORD usDataLen);
	DWORD GetCRC32(BYTE *pData,DWORD Length);

private:

};
