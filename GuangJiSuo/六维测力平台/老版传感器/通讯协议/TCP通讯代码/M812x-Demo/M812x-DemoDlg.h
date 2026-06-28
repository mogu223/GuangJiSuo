
// M812x-DemoDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CommTCPClient.h"



union DealDataFloat2Byte_TypeDef
{
	float	m_FloatResultData;
	BYTE	m_ByteResultDataBuffer[4];
};


union DealDataDouble2Byte_TypeDef
{
	double	m_DoubleResultData;
	BYTE	m_ByteResultDataBuffer[8];
};


#define RX_BUFFER_SIZE	16384
#define PROCESS_BUFFER_SIZE	16384

#define M812X_CHN_NUMBER	6
#define RECORD_BUFFER_SIZE	5000000


// CM812xDemoDlg dialog
class CM812xDemoDlg : public CDialog, CCommReceiveResponser
{
	// Construction
public:
	CM812xDemoDlg(CWnd* pParent = NULL);	// standard constructor
	// Dialog Data
	enum { IDD = IDD_M812XDEMO_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	//-------------------------------------------------------------------------
	//op ctr

	CStatic m_ctrlPicIconOpenoff;
	CButton m_ctrButtonlOpenOrClosePort;
	HICON m_hIconOn;   
	HICON m_hIconOff; 

	CString m_strIP;
	int m_intIPPort;
	//-------------------------------------------------------------------------
	//data ctr
	CRichEditCtrl m_ctrlReceiveData;
	CString m_strEditRxData;

	CEdit m_ctrlEditValueCh1;
	CEdit m_ctrlEditValueCh2;
	CEdit m_ctrlEditValueCh3;
	CEdit m_ctrlEditValueCh4;
	CEdit m_ctrlEditValueCh5;
	CEdit m_ctrlEditValueCh6;
	//-------------------------------------------------------------------------
	//data
	CCommTCPClient* m_CommTCPClient;

	BYTE* MyRxBuffer;
	DWORD mRxCounter;

	BYTE* m_pi8OrdinalBuffer;

	double m_dResultChValue[M812X_CHN_NUMBER];
	double m_dEngValue[M812X_CHN_NUMBER];

	union DealDataFloat2Byte_TypeDef DealDataBufferUnion[M812X_CHN_NUMBER];


	BYTE* m_pDealDataBuffer; 
	WORD* m_pRecordDataBuffer[M812X_CHN_NUMBER];	
	DWORD m_dwRecordCounter;

	DWORD m_dwPackageCouter;
	DWORD m_dwDealDataIndex;
	DWORD Data_Ptr_Out;
	//-------------------------------------------------------------------------
	//op func
	afx_msg void OnBnClickedButtonOpenclosePort();
	afx_msg void OnBnClickedButtonGetdata();
	afx_msg void OnBnClickedButtonCfg();
	afx_msg void OnBnClickedButtonRealtime();
	afx_msg void OnClose();	
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//op var
	bool m_bIsComPortOpenFlag;
	bool m_bIsRealTimeFlag;

		
	//----------------------------------------
	//op
	bool InitSystem(void);
	bool CloseSystem(void);

	bool OpenComm(void);
	bool CloseComm(void);

	bool OnReceiverData(BYTE* data, DWORD dataLen);
	bool OnNetworkFailure();

	void ShowReceiverData(BYTE* pDispBuffer,DWORD len);
	void ShowAlgorithmData(void);
	
	bool ConfigSystem(void);
	bool GetChParameter(char *pInstr,double *pdBuffer);
	bool GetEng(void);
	
	int RealTimeDataProcess();

	bool WriteCommand(CString command);
};
