
// M812x-DemoDlg.h : header file
//

#pragma once
#include "afxwin.h"

#include "cnComm.h"
#include "afxcmn.h"

#define RX_BUFFER_SIZE	16384

#define PROCESS_BUFFER_SIZE	16384

#define M812X_CHN_NUMBER	6
#define RECORD_BUFFER_SIZE	5000000

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



// CM812xDemoDlg dialog
class CM812xDemoDlg : public CDialog
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
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	
	CComboBox m_CtrlPortName;
	CComboBox m_CtrComboBaudRate;
	CStatic m_ctrlPicIconOpenoff;
	CButton m_ctrButtonlOpenOrClosePort;

	INT_PTR GetSerialPort(CStringArray& arrCom);
	void ReadREGInitComBoxList(void);

	HICON m_hIconOn;   
	HICON m_hIconOff; 

	CString m_strPortName;
	CString m_strPortSetting;
	int	m_nCom;
	int m_nBaudRate;

	cnComm m_ComPort;

	bool m_bIsComPortOpenFlag;

	afx_msg void OnCbnSelchangeComboPortname();
	afx_msg void OnCbnSelchangeComboBaudrate();
	afx_msg void OnBnClickedButtonOpenclosePort();


	afx_msg LRESULT OnComRecvData(WPARAM wParam, LPARAM lParam);
	void DispOnReceiverData(BYTE* pDispBuffer,DWORD len);

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CRichEditCtrl m_ctrlReceiveData;
	CString m_strEditRxData;

	BYTE* m_pReadRxBuffer;
	BYTE* MyRxBuffer;
	DWORD RxCounter;

	BYTE* m_pi8OrdinalBuffer;


	CEdit m_ctrlEditValueCh1;
	CEdit m_ctrlEditValueCh2;
	CEdit m_ctrlEditValueCh3;
	CEdit m_ctrlEditValueCh4;
	CEdit m_ctrlEditValueCh5;
	CEdit m_ctrlEditValueCh6;


	double m_dResultChValue[M812X_CHN_NUMBER];
	double m_dEngValue[M812X_CHN_NUMBER];

	union DealDataFloat2Byte_TypeDef DealDataBufferUnion[M812X_CHN_NUMBER];

	void ShowAlgorithmData(void);

	afx_msg void OnBnClickedButtonGetdata();
	afx_msg void OnBnClickedButtonCfg();

	afx_msg void OnClose();

	bool ConfigSystem(void);
	void WriteInstr(char *pInstr);
	bool GetChParameter(char *pInstr,double *pdBuffer);

	bool GetEng(void);

	afx_msg void OnBnClickedButtonRealtime();

	//----------------------------------------
	bool m_bIsRealTimeFlag;

	BYTE* m_pDealDataBuffer; 

	//记录实时数据，记录 M812X_CHN_NUMBER个通道， RECORD_BUFFER_SIZE为缓存大小，根据实际需要可以修改
	WORD* m_pRecordDataBuffer[M812X_CHN_NUMBER];	
	DWORD m_dwRecordCounter;//记录实时采用点 个数

	DWORD m_dwPackageCouter;
	DWORD m_dwDealDataIndex;
	DWORD Data_Ptr_Out;
	int RealTimeDataProcessForRS232();

};
