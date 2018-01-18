// PhoneRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "PhoneRecordDlg.h"
#include "ClientDlg.h"
#include "EmployeeDlg.h"
#include "ManufactureDlg.h"
#include "RecordDlg.h"
#include "PhoneinDlg.h"
#include "PhoneoutDlg.h"
#include "Tc08a32.h"
#include "NewSig.h"
#include "PhoneBook.h"
#include "ADOConn.h"
#include "Logindlg.h"
#include "djcvt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib,"djcvt")
#pragma comment (lib,"Tc08a32")
#pragma comment (lib,"NewSig")
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordDlg dialog

CPhoneRecordDlg::CPhoneRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhoneRecordDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon       = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ChanelCount = 0;
	m_IsReceiving = FALSE;
	m_CurNumber   = "";
	m_CurTime     = "";
	m_CurChanel   = -1;
	m_IsOffHook   = TRUE;
	m_RecordNum   = -1;
	m_IsBusy      = FALSE;
}

void CPhoneRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhoneRecordDlg)
	DDX_Control(pDX, IDC_PHONEBOOK, m_PhoneBook);
	DDX_Control(pDX, IDC_EDIT1, m_PhoneNum);
	DDX_Control(pDX, IDC_COMBO1, m_Chanel);
	DDX_Control(pDX, IDC_DIALUP, m_Dialup);
	DDX_Control(pDX, IDC_HANGUP, m_Hangup);
	DDX_Control(pDX, IDC_RECORD, m_Record);
	DDX_Control(pDX, IDC_PHONEOUT, m_PhoneOut);
	DDX_Control(pDX, IDC_PHONEIN, m_PhoneIn);
	DDX_Control(pDX, IDC_MANUFACTURE, m_Manufacture);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_EMPLOYEE, m_Employee);
	DDX_Control(pDX, IDC_CLIENT, m_Client);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPhoneRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CPhoneRecordDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_WM_CLOSE()
	ON_COMMAND(ID_MENUSHOW, OnMenushow)
	ON_COMMAND(ID_MENUHIDE, OnMenuhide)
	ON_COMMAND(ID_MENUCLOSE, OnMenuclose)
	ON_COMMAND(ID_MENUPHONEOUT, OnMenuphoneout)
	ON_COMMAND(ID_MENUPHONEIN, OnMenuphonein)
	ON_COMMAND(ID_MENURECORD, OnMenurecord)
	ON_COMMAND(ID_MENUCLIENT, OnMenuclient)
	ON_COMMAND(ID_MENUEMPLOYEES, OnMenuemployees)
	ON_COMMAND(ID_MENUMANUFACTURE, OnMenumanufacture)
	ON_COMMAND(ID_MENUABOUT, OnMenuabout)
	ON_COMMAND(ID_MENUEXIT, OnMenuexit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_DIALUP, OnDialup)
	ON_BN_CLICKED(IDC_HANGUP, OnHangup)
	ON_BN_CLICKED(IDC_PHONEBOOK, OnPhonebook)
	ON_BN_CLICKED(IDC_PHONEIN, OnPhonein)
	ON_BN_CLICKED(IDC_PHONEOUT, OnPhoneout)
	ON_BN_CLICKED(IDC_RECORD, OnRecord)
	ON_BN_CLICKED(IDC_CLIENT, OnClient)
	ON_BN_CLICKED(IDC_EMPLOYEE, OnEmployee)
	ON_BN_CLICKED(IDC_MANUFACTURE, OnManufacture)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordDlg message handlers

BOOL CPhoneRecordDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CLogindlg dlg;
	if(dlg.DoModal() != IDOK)
	{
		CDialog::OnCancel();
	}
	m_Menu.LoadMenu(IDR_MENU2);
	//添加系统托盘
	char lpszTip[]="企业电话语音录音管理系统";
	NOTIFYICONDATA data;
	data.cbSize = sizeof(NOTIFYICONDATA);
	data.hWnd   = m_hWnd;
	lstrcpyn(data.szTip,lpszTip,sizeof(lpszTip));
	data.uCallbackMessage = WM_ONTRAY;
	data.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	data.hIcon            = m_hIcon;
	data.uID              = IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_ADD,&data);

	//加载驱动程序
/*	if(LoadDRV()!=0)
		MessageBox("加载驱动程序错误");
	//检查可用的通道数量
	m_ChanelCount = CheckValidCh();
	SetBusyPara(350);
	EnableCard(m_ChanelCount,1024*32);*/

	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle( LVS_EX_FLATSB  //扁平风格显示滚动条
		| LVS_EX_FULLROWSELECT              //允许整行选中
		| LVS_EX_HEADERDRAGDROP             //允许整列拖动
		| LVS_EX_ONECLICKACTIVATE           //单击选中项
		| LVS_EX_GRIDLINES );               //画出网格线
	//设置表头
	m_Grid.InsertColumn(0,"通道号"  ,LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"通道类型",LVCFMT_LEFT,100,1); 
	m_Grid.InsertColumn(2,"电话号码",LVCFMT_LEFT,150,2); 
	m_Grid.InsertColumn(3,"来电时间",LVCFMT_LEFT,150,3); 
	m_Grid.InsertColumn(4,"流程状态",LVCFMT_LEFT,100,4); 

	m_pLines = new LINESTRUCT[m_ChanelCount];
	CString convert;
	for(int i = 0; i<m_ChanelCount; i++)
	{
		WORD type = CheckChType(i);
		convert.Format("%i",i);
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,convert);
		m_pLines[i].State       = CH_FREE;
		m_pLines[i].IsReceiving = FALSE;
		m_pLines[i].nType       = type ;
//		m_pLines[i].Inited      = FALSE;

		switch(type)
		{
		case 0: //内线
			{
				convert = "内线";
				break;
			}
		case 1: //外线
			{
				m_Chanel.AddString(convert);
				convert = "外线";	
				break;
			}
		case 2: //悬空
			{
				convert = "悬空";
				break;
			}
		}
		m_Grid.SetItemText(i,1,convert);
	}
	//初始化信号音函数
/*	Sig_Init(0);
	SetPackRate(PACK_32KBPS);
	SetDialPara(1000,2000,350,10);
	SetTimer(1,1,NULL);*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPhoneRecordDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPhoneRecordDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPhoneRecordDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPhoneRecordDlg::OnTray(WPARAM wParam, LPARAM lParam)
{
	UINT uMouseMsg = (UINT) lParam;
	if(uMouseMsg == WM_RBUTTONDOWN)
	{
		CMenu* pPopup = m_Menu.GetSubMenu(0);
		CPoint point;
		GetCursorPos(&point);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON | TPM_VERTICAL,
			point.x,point.y,AfxGetApp()->m_pMainWnd,TPM_LEFTALIGN); 		
	}
	if(uMouseMsg==WM_LBUTTONDBLCLK)     //双击鼠标
	{
		ShowWindow(SW_SHOWNOACTIVATE);     //恢复窗口的显示
	}
}

void CPhoneRecordDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CloseWindow();
	ShowWindow(SW_HIDE);
//	CDialog::OnClose();
}

void CPhoneRecordDlg::OnMenushow() 
{
	// TODO: Add your command handler code here
	ShowWindow(SW_SHOWNOACTIVATE);
}

void CPhoneRecordDlg::OnMenuhide() 
{
	// TODO: Add your command handler code here
	CloseWindow();
	ShowWindow(SW_HIDE);
}

void CPhoneRecordDlg::OnMenuclose() 
{
	// TODO: Add your command handler code here
	if(MessageBox("确定要退出企业电话语音录音管理系统吗？","系统提示",
		MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)
		return;
	//删除系统托盘
	NOTIFYICONDATA data;
	data.cbSize = sizeof(NOTIFYICONDATA);
	data.hWnd   = m_hWnd;
	data.uID    = IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	delete []m_pLines;
	FreeDRV();
	CDialog::OnCancel();
}

void CPhoneRecordDlg::OnMenuphoneout() 
{
	// TODO: Add your command handler code here
	CPhoneoutDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_PhoneNum.SetWindowText(dlg.m_Number);
		OnDialup();
	}
}

void CPhoneRecordDlg::OnMenuphonein() 
{
	// TODO: Add your command handler code here
	CPhoneinDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_PhoneNum.SetWindowText(dlg.m_Number);
		OnDialup();
	}
}

void CPhoneRecordDlg::OnMenurecord() 
{
	// TODO: Add your command handler code here
	CRecordDlg* dlg = new CRecordDlg;
	dlg->Create(IDD_RECORD_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnMenuclient() 
{
	// TODO: Add your command handler code here
	CClientDlg* dlg = new CClientDlg;
	dlg->Create(IDD_CLIENT_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnMenuemployees() 
{
	// TODO: Add your command handler code here
	CEmployeeDlg* dlg = new CEmployeeDlg;
	dlg->Create(IDD_EMPLOYEES_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnMenumanufacture() 
{
	// TODO: Add your command handler code here
	CManufactureDlg* dlg = new CManufactureDlg;
	dlg->Create(IDD_MANUFACTURE_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);

}

void CPhoneRecordDlg::OnMenuabout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CPhoneRecordDlg::OnMenuexit() 
{
	// TODO: Add your command handler code here
	if(MessageBox("确定要退出企业电话语音录音管理系统吗？","系统提示",
		MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)
		return;
	//删除系统托盘
	NOTIFYICONDATA data;
	data.cbSize = sizeof(NOTIFYICONDATA);
	data.hWnd   = m_hWnd;
	data.uID    = IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	delete []m_pLines;
	FreeDRV();
	CDialog::OnCancel();
}

void CPhoneRecordDlg::OnOK()
{
}

void CPhoneRecordDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	PUSH_PLAY();
	FeedSigFunc();	
	CString str;
	BOOL bOffHook = FALSE;
	for(int i=0;i<m_ChanelCount;i++)
	{
		if(m_pLines[i].IsReceiving)
		{
			StartSigCheck(i);
			ReadNumber(i);
		}
		if(RingDetect(i))
		{
			if(m_pLines[i].IsReceiving == FALSE)
			{
				StartSigCheck(i);
				ResetCallerIDBuffer(i);
				StartTimer(i,4);
				ReadNumber(i);
				m_pLines[i].IsReceiving = TRUE;
			}
		}
		
		if(m_pLines[i].State == CH_INCEPT)
		{
			m_Grid.SetItemText(i,4,"检测信号音");
			m_Grid.SetItemText(i,2,"来电是：" + m_CurNumber);
			//摘机,开始录音
			OffHook(i);
			StartSigCheck(i);
			m_RecordNum = 2;
			m_IsBusy    = TRUE;
			Record(i);
		}
		if(m_pLines[i].State == CH_FREE)
		{
			m_Grid.SetItemText(i,4,"空闲");
			m_Grid.SetItemText(i,2,"");
		}	
		switch(m_pLines[i].State)
		{
		case CH_DIAL:
			{
				m_Grid.SetItemText(i,4,"检测信号音");
				m_Grid.SetItemText(i,2,"呼叫号：" + m_Number);
				//检测某路DTMF发送是否结束,为1,以发送完毕,可以开始信号音检测
				if(CheckSendEnd(i) == 1)
				{
					StartSigCheck(i);
					m_pLines[i].State = CH_CHECKSIG;
				}
				break;
			}
		case CH_CHECKSIG:
			{
				int sig = Sig_CheckDial(i);
				if(sig == S_BUSY)
				{
					m_pLines[i].State = CH_BUSY;
				}
				else if(sig == S_CONNECT)
				{
					m_pLines[i].State = CH_CONNECT;
				}
				else if(sig == S_NOSIGNAL)
				{
					m_pLines[i].State = CH_NOSIGNAL;
				}
				else if(sig == S_NOBODY)
				{
					m_pLines[i].State = CH_NOBODY;
				}
				else if(sig == S_NODIALTONE)
				{
					m_pLines[i].State = CH_NODIALTONE;
				}
				break;
			}
		case CH_CONNECT:
			{
				m_RecordNum = 1;
				m_IsBusy    = TRUE;
				Record(i);
				break;
			}
		case CH_NODIALTONE: //没有信号音
		case CH_NOSIGNAL:   //没有信号
		case CH_BUSY:       //对方占线(检测到忙音)
			{
				OnHangup();
				break;
			}
		}
		if(m_IsBusy == TRUE)
		{
			if(Sig_CheckBusy(i) == 1) 
			{
				CString sql;
				CTime time = CTime::GetCurrentTime();
				StopRecordFile(i);
				m_IsOffHook = TRUE;
				Sig_ResetCheck(i);
				CString namefile;
				namefile = m_RecordFile.Left(m_RecordFile.GetLength()-4)+".vol";
				CString str1,str2;
				str1 = "f:\\"+m_RecordFile;
				str2 = "f:\\"+namefile;
				PcmtoWave(str2.GetBuffer(0),str1.GetBuffer(0));
				ADOConn m_AdoConn;
				m_AdoConn.OnInitADOConn();
				sql.Format("insert into tb_record(文件名称,文件路径,录制时间)values\
					('%s','%s','%s')",m_RecordFile,"f:\\",time.Format("%Y-%m-%d %H:%M:%S"));
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
				m_AdoConn.ExitConnect();
				AddToDataBase(m_RecordFile,time);
				m_IsBusy = FALSE;
				Sig_ResetCheck(i);
				StartSigCheck(i);
				m_pLines[i].IsReceiving = FALSE;
				m_pLines[i].CallerID    = "";
				m_CurTime               = "";
				m_Grid.SetItemText(i,2,"");
				m_Grid.SetItemText(i,3,"");
				m_Grid.SetItemText(i,4,"");
				m_pLines[i].State = CH_FREE;
			}
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CPhoneRecordDlg::ReadNumber(WORD nID)
{
	char number[100];
	int  result;
	PUSH_PLAY();
	FeedSigFunc();	
	memset(number,0,100);	
	result = GetCallerIDStr(nID,number);
	GetDtmfCode(nID);
	if((result==3) || (result==4))
	{
		m_CurNumber = number;
		m_CurNumber = m_CurNumber.Mid(8);
		m_pLines[nID].CallerID = m_CurNumber;
		m_pLines[nID].State = CH_INCEPT;
		if(m_CurTime.IsEmpty())
			m_CurTime = CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S");
		m_Grid.SetItemText(nID,3,m_CurTime);
		InitDtmfBuf(nID);
	}
}

void CPhoneRecordDlg::OnDialup() 
{
	// TODO: Add your control notification handler code here
	CString str,number;
	m_Chanel.GetWindowText(str);
	m_PhoneNum.GetWindowText(number);
	m_Number = number;
	if(str.IsEmpty()||number.IsEmpty())
		return;
	m_CurChanel = atoi(str);
	OffHook(m_CurChanel);
	int ret = Sig_StartDial(m_CurChanel,m_Number.GetBuffer(0),"",0);
	if(!ret)
	{
		MessageBox("拨出失败");
		return;
	}
	m_pLines[m_CurChanel].State = CH_DIAL;
}

void CPhoneRecordDlg::OnHangup() 
{
	// TODO: Add your control notification handler code here
	if(m_RecordNum == 1)
	{
		CString sql;
		CTime time = CTime::GetCurrentTime();
		StopRecordFile(m_CurChanel);
		m_IsOffHook = TRUE;
		Sig_ResetCheck(m_CurChanel);
		CString namefile;
		namefile = m_RecordFile.Left(m_RecordFile.GetLength()-4)+".vol";
		CString str1,str2;
		str1 = "f:\\"+m_RecordFile;
		str2 = "f:\\"+namefile;
		PcmtoWave(str2.GetBuffer(0),str1.GetBuffer(0));
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		sql.Format("insert into tb_record(文件名称,文件路径,录制时间)values\
			('%s','%s','%s')",m_RecordFile,"f:\\",time.Format("%Y-%m-%d %H:%M:%S"));
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.ExitConnect();
		AddToDataBase(m_RecordFile,time);
	}
	HangUp(m_CurChanel);
	Sig_ResetCheck(m_CurChanel);
	StartSigCheck(m_CurChanel);
	m_pLines[m_CurChanel].State = CH_FREE;
	m_RecordNum = -1;
}

void CPhoneRecordDlg::OnPhonebook() 
{
	// TODO: Add your control notification handler code here
	CPhoneBook dlg;
	dlg.DoModal();
	m_PhoneNum.SetWindowText(dlg.m_Num);
}

void CPhoneRecordDlg::Record(WORD num)
{
	CString file,sql,name,snum;
	CTime time = CTime::GetCurrentTime();
	//对方没有挂机
	if(ReadCheckResult(num,RECORD_CHECK) != R_BUSY)
	{
		if(m_IsOffHook == TRUE)
		{	
			CTime time = CTime::GetCurrentTime();
			sql.Format("select * from tb_record where YEAR(录制时间) = %d and MONTH(录制时间)\
				= %d and DAY(录制时间) = %d",atoi(time.Format("%Y")),atoi(time.Format("%m")),
				atoi(time.Format("%d")));
			ADOConn m_AdoConn;
			m_AdoConn.OnInitADOConn();
			m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(!m_AdoConn.m_pRecordset->adoEOF)
			{
				while(!m_AdoConn.m_pRecordset->adoEOF)
				{
					snum = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("文件名称");
					m_AdoConn.m_pRecordset->MoveNext();
				}
				CString ss;
				ss = snum.Left(snum.GetLength()-4);
				name.Format("%s%04d",time.Format("%y%m%d"),atoi(ss.Right(4))+1);
			}
			else
				name.Format("%s0001",time.Format("%y%m%d"));
			m_AdoConn.ExitConnect();
			name += ".vol";
			m_RecordFile = name.Left(name.GetLength()-4)+".wav";
			file.Format("f:\\%s",name);
			m_IsOffHook = FALSE;
			StartRecordFile(num,file.GetBuffer(0),60 * 8000);
		}
	}
	if(CheckRecordEnd(num))
	{
		StopRecordFile(num);
		m_IsOffHook = TRUE;
		Sig_ResetCheck(num);
		CString namefile;
		namefile = m_RecordFile.Left(m_RecordFile.GetLength()-4)+".vol";
		CString str1,str2;
		str1 = "f:\\"+m_RecordFile;
		str2 = "f:\\"+namefile;
		PcmtoWave(str2.GetBuffer(0),str1.GetBuffer(0));
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		sql.Format("insert into tb_record(文件名称,文件路径,录制时间)values\
			('%s','%s','%s')",m_RecordFile,"f:\\",time.Format("%Y-%m-%d %H:%M:%S"));
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.ExitConnect();
		AddToDataBase(m_RecordFile,time);
	}
}

void CPhoneRecordDlg::AddToDataBase(CString name,CTime time)
{
	CString sql,number,strname;
	m_PhoneNum.GetWindowText(number);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	sql.Format("select * from tb_client where 联系电话 = '%s'",number);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		strname = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("客户名称");
	}
	else
		strname = "新客户";
	if(m_RecordNum == 1)
	{
		sql.Format("insert into tb_phoneout(客户名称,去电号码,去电时间,洽谈内容)values\
			('%s','%s','%s','%s')",strname,number,time.Format("%Y-%m-%d %H:%M:%S"),name);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	else if(m_RecordNum == 2)
	{
		sql.Format("insert into tb_phonein(客户名称,来电号码,来电时间,洽谈内容)values\
			('%s','%s','%s','%s')",strname,number,time.Format("%Y-%m-%d %H:%M:%S"),name);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	m_AdoConn.ExitConnect();
}

void CPhoneRecordDlg::OnPhonein() 
{
	// TODO: Add your control notification handler code here
	CPhoneinDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_PhoneNum.SetWindowText(dlg.m_Number);
		OnDialup();
	}
}

void CPhoneRecordDlg::OnPhoneout() 
{
	// TODO: Add your control notification handler code here
	CPhoneoutDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_PhoneNum.SetWindowText(dlg.m_Number);
		OnDialup();
	}
}

void CPhoneRecordDlg::OnRecord() 
{
	// TODO: Add your control notification handler code here
	CRecordDlg* dlg = new CRecordDlg;
	dlg->Create(IDD_RECORD_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnClient() 
{
	// TODO: Add your control notification handler code here
	CClientDlg* dlg = new CClientDlg;
	dlg->Create(IDD_CLIENT_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnEmployee() 
{
	// TODO: Add your control notification handler code here
	CEmployeeDlg* dlg = new CEmployeeDlg;
	dlg->Create(IDD_EMPLOYEES_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}

void CPhoneRecordDlg::OnManufacture() 
{
	// TODO: Add your control notification handler code here
	CManufactureDlg* dlg = new CManufactureDlg;
	dlg->Create(IDD_MANUFACTURE_DIALOG,this);
	dlg->ShowWindow(SW_SHOW);
}
