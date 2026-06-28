
// M812x-DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "M812x-Demo.h"
#include "M812x-DemoDlg.h"

#include "MyCRC.h"
#include "cnComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)

END_MESSAGE_MAP()


// CM812xDemoDlg dialog
CM812xDemoDlg::CM812xDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CM812xDemoDlg::IDD, pParent)
	, m_strEditRxData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CM812xDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PORTNAME, m_CtrlPortName);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_CtrComboBaudRate);
	DDX_Control(pDX, IDC_STATIC_PICTURECTRL_ONOFF, m_ctrlPicIconOpenoff);
	DDX_Control(pDX, IDC_BUTTON_OPENCLOSE_PORT, m_ctrButtonlOpenOrClosePort);
	DDX_Control(pDX, IDC_RICHEDIT21, m_ctrlReceiveData);
	DDX_Text(pDX, IDC_RICHEDIT21, m_strEditRxData);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEditValueCh1);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlEditValueCh2);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlEditValueCh3);
	DDX_Control(pDX, IDC_EDIT4, m_ctrlEditValueCh4);
	DDX_Control(pDX, IDC_EDIT5, m_ctrlEditValueCh5);
	DDX_Control(pDX, IDC_EDIT6, m_ctrlEditValueCh6);
}

BEGIN_MESSAGE_MAP(CM812xDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_MESSAGE(ON_COM_RECEIVE, OnComRecvData)

	ON_WM_TIMER()

	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO_PORTNAME, &CM812xDemoDlg::OnCbnSelchangeComboPortname)
	ON_CBN_SELCHANGE(IDC_COMBO_BAUDRATE, &CM812xDemoDlg::OnCbnSelchangeComboBaudrate)
	ON_BN_CLICKED(IDC_BUTTON_OPENCLOSE_PORT, &CM812xDemoDlg::OnBnClickedButtonOpenclosePort)
	ON_BN_CLICKED(IDC_BUTTON_GETDATA, &CM812xDemoDlg::OnBnClickedButtonGetdata)
	ON_BN_CLICKED(IDC_BUTTON_CFG, &CM812xDemoDlg::OnBnClickedButtonCfg)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_REALTIME, &CM812xDemoDlg::OnBnClickedButtonRealtime)
END_MESSAGE_MAP()


// CM812xDemoDlg message handlers

BOOL CM812xDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_hIconOn  = AfxGetApp()->LoadIcon(IDI_ICON_ON);
	m_hIconOff = AfxGetApp()->LoadIcon(IDI_ICON_OFF);


	//--------------------------------------------------------------------------------
	CString strTemp;
	ReadREGInitComBoxList();
	m_CtrlPortName.SetCurSel (0);
	m_CtrlPortName.GetWindowText (strTemp);

	m_nCom = 1;
	m_nCom = _wtoi(strTemp.Mid (3,2));

	m_CtrComboBaudRate.SetCurSel(6);
	m_nBaudRate = 115200;
	m_strPortSetting.Format(_T("%d,%c,%d,%d"), m_nBaudRate,'N',8,1);

	m_bIsComPortOpenFlag = false;
	m_ctrlPicIconOpenoff.SetIcon (m_hIconOff);
	m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Open Port"));

	m_pReadRxBuffer = new BYTE[RX_BUFFER_SIZE];
	if(m_pReadRxBuffer == NULL)	{return FALSE;}

	MyRxBuffer = new BYTE[RX_BUFFER_SIZE];
	if(MyRxBuffer == NULL)	{return FALSE;}
	
	m_pDealDataBuffer = new BYTE[PROCESS_BUFFER_SIZE];
	if(m_pDealDataBuffer == NULL)	{return FALSE;}

	m_pi8OrdinalBuffer = new BYTE[PROCESS_BUFFER_SIZE];
	if(m_pi8OrdinalBuffer == NULL)	{return FALSE;}
	
	for(int i = 0x00;i < M812X_CHN_NUMBER;i++)
	{
		m_pRecordDataBuffer[i] = new WORD[RECORD_BUFFER_SIZE];
		if(m_pRecordDataBuffer[i] == NULL)	{return FALSE;}
	}

	RxCounter  = 0x00;

	m_bIsRealTimeFlag = false;
	m_dwRecordCounter = 0x00;
	m_dwPackageCouter = 0x00;
	m_dwDealDataIndex = 0x00;
	Data_Ptr_Out = 0xFFFFFFFF;

	SetTimer(3,50, NULL);

	UpdateData(FALSE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CM812xDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CM812xDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CM812xDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CM812xDemoDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if(MyRxBuffer != NULL){delete []MyRxBuffer;}
	if(m_pReadRxBuffer != NULL) {delete []m_pReadRxBuffer;}

	if(m_pDealDataBuffer != NULL) {delete []m_pDealDataBuffer;}
	for(int i = 0x00;i < M812X_CHN_NUMBER;i++)
	{
		if(m_pRecordDataBuffer[i] != NULL) {delete []m_pRecordDataBuffer[i];}
	}	

	if(m_bIsComPortOpenFlag)
	{
		CString	CmdStr;
		LPTSTR  pszTest;
		char *pChar;
		int len;
		CmdStr = _T("AT+GSD=STOP\r\n");
		pszTest=CmdStr.GetBuffer(CmdStr.GetLength());
		USES_CONVERSION;
		pChar = W2A(pszTest);
		len = strlen(pChar);
		m_ComPort.Write(pChar,len);
		CmdStr.ReleaseBuffer();
	}

	CDialog::OnClose();
}

LRESULT  CM812xDemoDlg::OnComRecvData(WPARAM wParam, LPARAM lParam)
{
	DWORD len;
	DWORD i = 0x00;
	len = m_ComPort.Read(m_pReadRxBuffer, RX_BUFFER_SIZE);
	//-----------------------------------------------------------------------
	for(i = 0x00;i < len;i++)
	{	
		if(RxCounter >= RX_BUFFER_SIZE) {RxCounter = 0x00;}
		MyRxBuffer[RxCounter++] = m_pReadRxBuffer[i];		
	}		
	//-----------------------------------------------------------------------
	if(m_bIsRealTimeFlag == false){DispOnReceiverData(m_pReadRxBuffer,len);}

	if(m_bIsRealTimeFlag == true){RealTimeDataProcessForRS232();}

	return 0;
}


//--------------------------------------------------------------
void CM812xDemoDlg::DispOnReceiverData(BYTE* pDispBuffer,DWORD len)
{

	//------------------------------------------------------
	CString strRxTemp;
	CString strRxTempResult;

	pDispBuffer[len] = 0x00;
	strRxTempResult = (CString)(CStringA)(pDispBuffer);

	//-----------------------------------------------------------------------------------------
	int	nStart = m_ctrlReceiveData.GetTextLength ();		
	int nEnd = strRxTempResult.GetLength() + nStart;
	m_ctrlReceiveData.SetSel (nStart,nEnd);
	m_ctrlReceiveData.ReplaceSel(strRxTempResult);
	m_ctrlReceiveData.LineScroll(1);
	m_strEditRxData += strRxTempResult;	
}


//==================================================================================
INT_PTR  CM812xDemoDlg::GetSerialPort(CStringArray& arrCom)
{
	arrCom.RemoveAll();
	HKEY hkey; 

	LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DEVICEMAP\\SERIALCOMM"), NULL, KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS | KEY_READ, &hkey); 

	if (lRes == ERROR_SUCCESS) 
	{

		TCHAR tchKey[MAX_PATH]; 

		TCHAR tchValue[20];

		DWORD dwIndex = 0;

		DWORD dwType = REG_SZ;

		while(lRes == ERROR_SUCCESS)
		{
			DWORD dwCount = MAX_PATH;
			DWORD dwVCount = 20;
			lRes = RegEnumValue(hkey, dwIndex++, tchKey, &dwCount, NULL, &dwType, (LPBYTE)tchValue, &dwVCount);

			if(lRes == ERROR_SUCCESS)
			{
				if((dwVCount > 0) && (dwCount > 0))
				{
					arrCom.Add(tchValue);
				}
			}
		}
	}

	RegCloseKey(hkey);
	return  arrCom.GetSize();
}

void  CM812xDemoDlg::ReadREGInitComBoxList(void)
{
	CStringArray  CA_Com;
	GetSerialPort( CA_Com);
	INT_PTR len =  CA_Com.GetSize ();
	
	CString strComTemp;

	for(int i = 0;i <  len ; i++)
	{
		strComTemp += CA_Com[i];
		m_CtrlPortName.AddString (strComTemp);
		strComTemp.Empty ();
	}
}



void CM812xDemoDlg::OnCbnSelchangeComboPortname()
{
	// TODO: Add your control notification handler code here
	CString strTemp;
	int ComNum = 1;
	m_CtrlPortName.GetWindowText (strTemp);
	m_strPortName = strTemp;


	m_ComPort.Close (); 

	ComNum = _wtoi(strTemp.Mid (3,2));
	m_nCom = ComNum;
	m_strPortSetting.Format(L"%d,%c,%d,%d", m_nBaudRate,'N',8,1);

	if(m_bIsComPortOpenFlag == true)
	{
		m_bIsComPortOpenFlag = false;
		m_ctrlPicIconOpenoff.SetIcon (m_hIconOff);
		m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Open Port"));
		OnBnClickedButtonOpenclosePort();
	}
}

void CM812xDemoDlg::OnCbnSelchangeComboBaudrate()
{
	// TODO: Add your control notification handler code here
	CString temp;
	long i = m_CtrComboBaudRate.GetCurSel();

	switch(i)
	{
		case 0:
			i=9600;
			break;
		case 1:
			i=14400;
			break;
		case 2:
			i=19200;
			break;
		case 3:
			i=38400;
			break;
		case 4:
			i=56000;
			break;
		case 5:
			i=57600;
			break;
		case 6:
			i=115200;
			break;
		default:
			i=115200;
			break;

	}
	m_nBaudRate = i;
	m_strPortSetting.Format(L"%d,%c,%d,%d", m_nBaudRate,'N',8,1);

	if(m_bIsComPortOpenFlag == true)
	{
		m_bIsComPortOpenFlag = false;
		m_ctrlPicIconOpenoff.SetIcon (m_hIconOff);
		m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Open Port"));
		OnBnClickedButtonOpenclosePort();
	}
}

void CM812xDemoDlg::OnBnClickedButtonOpenclosePort()
{
	// TODO: Add your control notification handler code here
	//------------------------------------------------------------------------------------------

	if(m_bIsComPortOpenFlag == false)
	{
		if(!m_ComPort.Open(m_nCom,m_strPortSetting))	
		{	
			m_bIsComPortOpenFlag = false;
			m_ctrlPicIconOpenoff.SetIcon (m_hIconOff);
			m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Open Port"));
			AfxMessageBox(_T("Connot open the com port,the port may\r\n be used by another application."));
			return;
		}
		else
		{
			m_ComPort.SetWnd(m_hWnd);
			m_ComPort.SetBufferSize(65535,8192);
			m_ComPort.SetNotifyNum(2);
			m_ComPort.m_bTxBufEmpty_Flag = true;
			m_bIsComPortOpenFlag = true;
		}
	}
	else
	{
		m_ComPort.Close (); //close
		m_bIsComPortOpenFlag = false;
	}

	if(m_bIsComPortOpenFlag == false)
	{
		m_ctrlPicIconOpenoff.SetIcon (m_hIconOff);
		m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Open Port"));
	}
	else
	{
		m_ctrlPicIconOpenoff.SetIcon (m_hIconOn);
		m_ctrButtonlOpenOrClosePort.SetWindowText(_T("Close Port"));
	}

}


void CM812xDemoDlg::ShowAlgorithmData(void)
{

	CString strTemp;
	strTemp.Format (_T("%.6lf"),m_dEngValue[0]);
	m_ctrlEditValueCh1.SetWindowText (strTemp);
	strTemp.Format (_T("%.6lf"),m_dEngValue[1]);
	m_ctrlEditValueCh2.SetWindowText (strTemp);
	strTemp.Format (_T("%.6lf"),m_dEngValue[2]);
	m_ctrlEditValueCh3.SetWindowText (strTemp);
	strTemp.Format (_T("%.6lf"),m_dEngValue[3]);
	m_ctrlEditValueCh4.SetWindowText (strTemp);
	strTemp.Format (_T("%.6lf"),m_dEngValue[4]);
	m_ctrlEditValueCh5.SetWindowText (strTemp);
	strTemp.Format (_T("%.6lf"),m_dEngValue[5]);
	m_ctrlEditValueCh6.SetWindowText (strTemp);

}



void CM812xDemoDlg::OnBnClickedButtonGetdata()
{
	// TODO: Add your control notification handler code here
	CString	CmdStr;
	LPTSTR  pszTest;
	char *pChar;
	int len;

	if(!m_bIsComPortOpenFlag)
	{
		AfxMessageBox(_T("Please open the com port."));
		return;
	}

	RxCounter = 0x00; //reset index
	memset(MyRxBuffer,0x00,RX_BUFFER_SIZE);

	CmdStr = _T("AT+GOD\r\n");
	pszTest=CmdStr.GetBuffer(CmdStr.GetLength());
	USES_CONVERSION;
	pChar = W2A(pszTest);
	len = strlen(pChar);
	m_ComPort.Write(pChar,len);

	CmdStr.ReleaseBuffer();

	::Sleep (500);

	SetTimer(2,200, NULL);

}

void CM812xDemoDlg::OnBnClickedButtonCfg()
{
	// TODO: Add your control notification handler code here

	if(!m_bIsComPortOpenFlag)
	{
		AfxMessageBox(_T("Please open the com port."));
		return;
	}

	RxCounter = 0x00; //reset index
	memset(MyRxBuffer,0x00,RX_BUFFER_SIZE);

	::Sleep (300);

	//Time-delay between two commands GOD(or GSD)
	SetTimer(1,300, NULL);
	
}

void CM812xDemoDlg::WriteInstr(char *pInstr)
{
	CString	CmdStr;
	LPTSTR  pszTest;
	char *pChar;
	int len;

	CmdStr = pInstr;
	USES_CONVERSION;
	pszTest=CmdStr.GetBuffer(CmdStr.GetLength());
	pChar = W2A(pszTest);
	len = strlen(pChar);
	m_ComPort.Write(pChar,len);

	CmdStr.ReleaseBuffer();
}

bool CM812xDemoDlg::ConfigSystem(void)
{

	KillTimer(1);	
	AfxMessageBox(_T("Config system finish."));
	return true;
}

void CM812xDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	int static Counter = 0x00;
	//-------------------------------------------------------------------------
	switch(nIDEvent)
	{	
		case 1:
			if(ConfigSystem() == false) KillTimer(1);		
			break;
		case 2:
			Counter++;
			if(Counter > 1)
			{
				Counter = 0x00;
				KillTimer(2);
				if(GetEng() != true)
				{
					AfxMessageBox(_T("Get Eng fail."));
					return;
				}
				ShowAlgorithmData();
			}
			break;
		case 3:
			ShowAlgorithmData();
			break;

		default:
			break;
	}

	//------------------------------------------------------------------------
	CDialog::OnTimer(nIDEvent);
}



bool CM812xDemoDlg::GetChParameter(char *pInstr,double *pdBuffer)
{
	char *pIndexBuffer = NULL;
	char CharTemp[16] = {0x00};
	double pdTemp[M812X_CHN_NUMBER] = {0x00};

	pIndexBuffer = strstr((char*)MyRxBuffer,pInstr);
	if(pIndexBuffer == NULL) return false;

	int k = 0x00;
	double dTemp = 0x00;
	int len = strlen(pInstr)+1;
	pIndexBuffer = pIndexBuffer+len;
	for(int i = 0x00; i < M812X_CHN_NUMBER; i++)
	{
		memset(CharTemp,0x00,16);		
		k = 0x00;
		while(*pIndexBuffer != ';' && *pIndexBuffer != '\r')
		{
			CharTemp[k++] = *pIndexBuffer++;
			if(k >= 16) return false;
		}
		if(sscanf_s(CharTemp,"%lf",&dTemp) != 1) return false;	
		pdTemp[i] = dTemp;
		pIndexBuffer++;
	}

	for(int i = 0x00; i < M812X_CHN_NUMBER; i++)
		pdBuffer[i] = pdTemp[i];

	//CString strTemp;
	//strTemp.Format(L"%lf %lf %lf %lf %lf %lf",pdBuffer[0],pdBuffer[1],pdBuffer[2],pdBuffer[3],pdBuffer[4],pdBuffer[5]);
	//AfxMessageBox(strTemp);	
	return true;
}


// To get sampling data from M8128
bool CM812xDemoDlg::GetEng(void)
{
//  structure
//	FrameHeader	PackageLength	DataNo	     Data	     ChkSum/CRC32
//  0xAA,0x55	   HB,LB          2B	(ChNum*N)B/6*4   1B/4B

	BYTE *pRxBuffer = (BYTE*)MyRxBuffer;
	
	int i = 0x00;
	while(1)
	{
		if(pRxBuffer[i] == 0xAA && pRxBuffer[i+1] == 0x55)
		{
			break;
		}
		i++;
		if(i >= RX_BUFFER_SIZE)	return false;	
	}
	
	int Length = pRxBuffer[i+2]*256 + pRxBuffer[i+3];


	int Index = i + 6;
	BYTE CheckSum = 0x00;
	for(int j = 0x00; j < M812X_CHN_NUMBER*4; j++)
	{
		CheckSum += pRxBuffer[Index++];
	}
	//if(CheckSum !=  pRxBuffer[Index])	return false;

	Index = i + 6;
	DWORD dwCheckCrc32 = 0x00,dwRxCheckCrc32 = 0x00;
	CMyCRC m_MyCRC;
	dwCheckCrc32 = m_MyCRC.GetCRC32(&pRxBuffer[Index], M812X_CHN_NUMBER*4);
	DWORD CrcIndex = Index + M812X_CHN_NUMBER*4;
	dwRxCheckCrc32 =  pRxBuffer[CrcIndex] << 24 | pRxBuffer[CrcIndex+1] << 16 | pRxBuffer[CrcIndex+2] << 8 | pRxBuffer[CrcIndex+3];
	//考虑 可能的两种 校验方法
	if(dwCheckCrc32 != dwRxCheckCrc32 && CheckSum !=  pRxBuffer[CrcIndex]) return false;

	Index = i + 6;
	for(int k = 0x00; k < M812X_CHN_NUMBER; k++)
	{				
		for(int m = 0x00; m < 4; m++)
		{
			DealDataBufferUnion[k].m_ByteResultDataBuffer[m] = pRxBuffer[Index++];
		}
		m_dEngValue[k] = DealDataBufferUnion[k].m_FloatResultData;
	}

	return true;
}


void CM812xDemoDlg::OnBnClickedButtonRealtime()
{
	// TODO: Add your control notification handler code here
	CString	CmdStr;
	LPTSTR  pszTest;
	char *pChar;
	int len;

	if(!m_bIsComPortOpenFlag)
	{
		AfxMessageBox(_T("Please open the com port."));
		return;
	}
	
	CWnd* wnd = GetDlgItem(IDC_BUTTON_REALTIME);
	if(m_bIsRealTimeFlag == false)
	{		
		RxCounter = 0x00; //reset index
		memset(MyRxBuffer,0x00,RX_BUFFER_SIZE);
		CmdStr = _T("AT+GSD\r\n");
		pszTest=CmdStr.GetBuffer(CmdStr.GetLength());
		USES_CONVERSION;
		pChar = W2A(pszTest);
		len = strlen(pChar);
		m_ComPort.Write(pChar,len);
		CmdStr.ReleaseBuffer();

		Data_Ptr_Out = RxCounter;
		m_dwPackageCouter= 0x00;
		m_dwDealDataIndex = 0x00;

		m_bIsRealTimeFlag = true;
		wnd->SetWindowText(_T("StopRealTime"));
	}
	else
	{
		CmdStr = _T("AT+GSD=STOP\r\n");
		pszTest=CmdStr.GetBuffer(CmdStr.GetLength());
		USES_CONVERSION;
		pChar = W2A(pszTest);
		len = strlen(pChar);
		m_ComPort.Write(pChar,len);
		CmdStr.ReleaseBuffer();
		m_bIsRealTimeFlag = false;
		wnd->SetWindowText(_T("StartRealTime"));	
	}
}


//Scan buffer memory, save sampling data as long as new data is fushed in.
//Head fram	PackageLength	DataNo CHN	Length	  Data	  ChkSum NextCHN Length	  Data 	     ChkSum
//0xAA,0x55	  HB,LB	       2B	    2B	HB,LB	 (DNpCH*N)B	 1B	      2B	  HB,LB	(DNpCH*N)B 	 1
int CM812xDemoDlg::RealTimeDataProcessForRS232(void)
{
	if(MyRxBuffer == NULL){return 0;}
	if(Data_Ptr_Out == 0xFFFFFFFF){return 0;}

	BOOL  DataHeaderFlag = FALSE;
	DWORD i = 0x00,j = 0x00,k = 0x00;

	DWORD PackageLength= 0xFFFFFFFF; 
	DWORD HeaderIndex= 0x00;
	DWORD HighIndex,LowIndex;
	DWORD PointCounter = 0x00;
	DWORD RxLengthTemp = 0x00;

	DWORD RxCounterCurrent= RxCounter;

	//--------------------------------------------------------------------------------	
	//Data length
	HeaderIndex = Data_Ptr_Out;		
	if(RxCounterCurrent >= HeaderIndex)
	{
		RxLengthTemp = RxCounterCurrent - HeaderIndex;
	}else
	{
		RxLengthTemp = RX_BUFFER_SIZE - HeaderIndex + RxCounterCurrent;
	}
	if(RxLengthTemp <= 33)
	{
		return -1;
	}
	//--------------------------------------------------------------------------------
	//Data head fram
	for(i = 0x00;i < RxLengthTemp; i++)
	{	
		if(HeaderIndex == RX_BUFFER_SIZE )
		{
			HeaderIndex = 0x00;
		}
		if(HeaderIndex == RX_BUFFER_SIZE-1)
		{
			if((MyRxBuffer[HeaderIndex] == 0xAA) && (MyRxBuffer[0] == 0x55))
			{
				DataHeaderFlag = TRUE;
				break;
			}
		}else if((MyRxBuffer[HeaderIndex] == 0xAA) && (MyRxBuffer[HeaderIndex+1] == 0x55))
		{
			DataHeaderFlag = TRUE;
			break;
		}
		HeaderIndex++;	
	}
	if(DataHeaderFlag != TRUE)
	{
		return -1;
	}
	DataHeaderFlag = FALSE;
	//-------------------------------------------------------------------------------
	HighIndex = HeaderIndex+2;
	LowIndex = HeaderIndex+3;
	if(HighIndex >= RX_BUFFER_SIZE)
	{
		HighIndex = HighIndex - RX_BUFFER_SIZE;
	}
	if(LowIndex >= RX_BUFFER_SIZE)
	{
		LowIndex = LowIndex - RX_BUFFER_SIZE;
	}
	PackageLength = MyRxBuffer[HighIndex]*256 + MyRxBuffer[LowIndex];

	if(RxCounterCurrent >= HeaderIndex)//LYY
	{
		RxLengthTemp = RxCounterCurrent - HeaderIndex;
	}else
	{
		RxLengthTemp = RX_BUFFER_SIZE - HeaderIndex + RxCounterCurrent;
	}	
	if(RxLengthTemp < PackageLength + 4)
	{
		return -1;
	}

	//Now, HeaderIndex point to‘0xAA’
	//Head fram	  PackageLength	 DataNo	       Data	         ChkSum/CRC32
	//0xAA,0x55	     HB,LB         2B   (ChNum*N*DNpCH) B/6*4	 1B/4
	//--------------------------------------------------------------------------------
	//Save data	in order
	DWORD MoveIndex = HeaderIndex+6;
	if(MoveIndex >= RX_BUFFER_SIZE)
	{
		MoveIndex = MoveIndex - RX_BUFFER_SIZE;
	}
	for(i = 0x00; i < (PackageLength - 2); i++)
	{		
		m_pi8OrdinalBuffer[i] = MyRxBuffer[MoveIndex];	
		MoveIndex++;
		if(MoveIndex >= RX_BUFFER_SIZE){MoveIndex = 0x00;}		
	}
	Data_Ptr_Out = MoveIndex;

	BYTE CheckSum = 0x00;
	for(i = 0x00; i < (PackageLength-3); i++)
	{	
		CheckSum += m_pi8OrdinalBuffer[i];		
	}

	DWORD dwCheckCrc32 = 0x00,dwRxCheckCrc32 = 0x00;
	CMyCRC m_MyCRC;
	dwCheckCrc32 = m_MyCRC.GetCRC32(m_pi8OrdinalBuffer, (PackageLength-6));
	DWORD CrcIndex = PackageLength - 6;
	dwRxCheckCrc32 = m_pi8OrdinalBuffer[CrcIndex] << 24 | m_pi8OrdinalBuffer[CrcIndex+1] << 16 | m_pi8OrdinalBuffer[CrcIndex+2] << 8 | m_pi8OrdinalBuffer[CrcIndex+3];
	//考虑 可能的两种 校验方法
	if((dwCheckCrc32 != dwRxCheckCrc32) && (CheckSum != m_pi8OrdinalBuffer[PackageLength-3])) {return -1;}

	DWORD dwActualDataLen = 0x00;
	if(dwCheckCrc32 == dwRxCheckCrc32) dwActualDataLen = PackageLength - 6;
	else dwActualDataLen = PackageLength - 3;
	//---------------------------------------------------------------------------------
	if(m_dwDealDataIndex >= PROCESS_BUFFER_SIZE - dwActualDataLen) 
	{ 
		m_dwDealDataIndex = 0x00;
		m_dwPackageCouter = 0x00;
		return -1;
	}
	for(i = 0x00; i < dwActualDataLen; i++)
	{			
		m_pDealDataBuffer[m_dwDealDataIndex++] = m_pi8OrdinalBuffer[i];				
	}	
	m_dwPackageCouter++;
	if(m_dwDealDataIndex == 0x00)
	{
		return -1;
	}

	//-------------------------------------------------------------------------------
	//			
	int Index = 0x00;			
	PointCounter = m_dwDealDataIndex/4/M812X_CHN_NUMBER;
	if( (PointCounter >= PROCESS_BUFFER_SIZE) || (PointCounter <= 0) )
	{ 
		m_dwDealDataIndex = 0x00;
		m_dwPackageCouter = 0x00;
		return -1;
	}

	DWORD DispChSum[M812X_CHN_NUMBER] = {0x00};
	for(int k = 0x00; k < M812X_CHN_NUMBER; k++)
	{
		m_dEngValue[k] = 0.00;
	}
	for(j = 0x00; j < PointCounter; j++)
	{					
		for(int k = 0x00; k < M812X_CHN_NUMBER; k++)
		{				
			for(int m = 0x00; m < 4; m++)
			{
				DealDataBufferUnion[k].m_ByteResultDataBuffer[m] = m_pDealDataBuffer[Index++];
			}
			m_dEngValue[k] += DealDataBufferUnion[k].m_FloatResultData;
		}
	}

	//---------------------------------------------------
	for(int k = 0x00; k < M812X_CHN_NUMBER;k++)
	{	
		m_dEngValue[k]  = m_dEngValue[k]/PointCounter;
	}
	//show decoupled data
	//ShowAlgorithmData();

	//--------------------------------
	m_dwDealDataIndex = 0x00;
	m_dwPackageCouter = 0x00;

	//------------------------------------
	return 1;
}


