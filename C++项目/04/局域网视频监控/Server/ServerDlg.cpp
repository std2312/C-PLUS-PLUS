// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#define MAX_BUFF 99999

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
	virtual void OnOK();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{

	//{{AFX_DATA_INIT(CServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAIN);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_SYSSETTING, m_SysSetting);
	DDX_Control(pDX, IDC_QUIT, m_Quit);
	DDX_Control(pDX, IDC_OPERATORMGE, m_OperatorMge);
	DDX_Control(pDX, IDC_BTUP, m_BtUp);
	DDX_Control(pDX, IDC_BTRIGHT, m_BtRight);
	DDX_Control(pDX, IDC_BTRESTORE, m_BtRestore);
	DDX_Control(pDX, IDC_BTLEFT, m_BtLeft);
	DDX_Control(pDX, IDC_BTDOWN, m_BtDown);
	DDX_Control(pDX, IDC_BACKGROUND, m_BK);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SYSSETTING, OnSyssetting)
	ON_BN_CLICKED(IDC_OPERATORMGE, OnOperatormge)
	ON_MESSAGE(CM_RECEIVED,OnReceived)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_BTUP,IDC_BTRESTORE,OnButtonDown)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	//获取本机IP

	hostent* phost =  gethostbyname("");
	char* localIP =	inet_ntoa (*(struct in_addr *)*phost->h_addr_list);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr  = inet_addr(localIP);
	addr.sin_port  = htons(5002);

	//创建套接字
	m_Socket = socket(AF_INET,SOCK_DGRAM,0);
	if (m_Socket == INVALID_SOCKET)
	{
		MessageBox("套接字创建失败!");
	}

	//绑定套接字
	if (bind(m_Socket,(sockaddr*)&addr,sizeof(addr))==SOCKET_ERROR)
	{
		MessageBox("套接字绑定失败!");
	}
	m_BmpData = new char[1024*1024*2];
	memset(m_BmpData,0,1024*1024*2);
	m_TempData = new char[1024*1024*2];
	memset(m_TempData,0,1024*1024*2);
	m_Header = m_BmpData;

	WSAAsyncSelect(m_Socket,m_hWnd,CM_RECEIVED,FD_READ);

	m_ShowBmp = FALSE;
	m_BmpSize = 0;
	m_RecSize = 0;
	m_ClientPort = 0;

	CServerApp* pApp = (CServerApp*)AfxGetApp();
	CString sql = "select * from tb_ClientInfo";
	pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
	pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);

	m_ClientIP= "";
	if (pApp->m_DataManage.m_pRecord->RecordCount>0)
	{
		m_ClientIP = (char*)(_bstr_t)pApp->m_DataManage.m_pRecord->GetFields()->GetItem(0L)->Value;	
	}
	pApp->m_DataManage.m_pRecord->Close();

	m_LeftTopX= 0;
	m_LeftTopY= 0;
	m_BK.SetWindowPos(NULL,0,0,305,305,SWP_NOMOVE);
	return TRUE; 
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnReceived()
{
	//接收数据
	char* buffer = new char[MAX_BUFF];
	sockaddr_in addr;
	int factsize =sizeof(sockaddr);
	int ret = recvfrom(m_Socket,buffer,MAX_BUFF,0,(sockaddr*)&addr,&factsize);
	
	if (ret != -1)
	{
		CString revIP = inet_ntoa(addr.sin_addr);
		if (revIP != m_ClientIP)
		{
			delete [] buffer;
			return;
		}
		
		m_ClientPort = ntohs(addr.sin_port);
		//记录接收的数据报大小
		m_RecSize += ret;
		//读取序号
		WORD orderID =  *(WORD*)&buffer[0];
		WORD endID = *(WORD*)&buffer[2];
		//读取位图大小
		int bmpsize = *(int*)&buffer[ret-12];
		//获取屏幕的X轴坐标
		m_LeftTopX = *(WORD*)&buffer[ret-8];
		//获取屏幕的Y轴坐标
		m_LeftTopY = *(WORD*)&buffer[ret-6];
		//读取结束标记

		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(m_ClientPort);
		addr.sin_addr.S_un.S_addr = inet_addr(m_ClientIP.GetBuffer(0));
		int size = sizeof(addr);

		//发送确认信息
		char* pData = "Confirm";
		sendto(m_Socket,pData,8,0,(sockaddr*)&addr,size);
	
		if (orderID==0)
		{

			m_BmpSize = bmpsize;
			m_BmpData = m_Header;
		}
		else
			m_BmpSize +=bmpsize;
		memcpy(m_BmpData,&buffer[4],bmpsize);
		m_BmpData += bmpsize;
		m_ShowBmp = FALSE;
		if (endID==1)
		{
			m_ShowBmp = TRUE;
			m_BmpData = m_Header;
			memcpy(m_TempData,m_Header,1024*1024);
			ShowImage() ;
			m_RecSize = 0;
		}
	}
	delete [] buffer;

}

void CServerDlg::OnCancel()
{	
	m_BmpData = m_Header;
	delete [] m_BmpData;
	delete	[]m_TempData;
	CDialog::OnCancel();
}

void CServerDlg::ShowImage() 
{
	if (m_ShowBmp)
	{	
		BITMAPINFO bInfo;		
		memcpy(&bInfo,m_TempData,sizeof(bInfo));
		int x  = bInfo.bmiHeader.biWidth;
		int y  = bInfo.bmiHeader.biHeight;
		StretchDIBits(m_BK.GetDC()->m_hDC,0,0,x,y,0,0,x,y,&m_TempData[sizeof(BITMAPINFO)],&bInfo,DIB_RGB_COLORS,SRCCOPY);	
	}
}


void CServerDlg::OnButtonDown(UINT nID)
{
	if (!m_ClientIP.IsEmpty())
	{
		WORD x =  m_LeftTopX;
		WORD y =  m_LeftTopY; 
		
		char buffer[4];

		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(m_ClientPort);
		addr.sin_addr.S_un.S_addr = inet_addr(m_ClientIP.GetBuffer(0));
		int size = sizeof(addr);

		switch(nID)
		{

		case IDC_BTDOWN:
			{
				y =  m_LeftTopY+100; 
				*(WORD*)&buffer[0] = x;
				*(WORD*)&buffer[2] = y;
				int ret = sendto(m_Socket,&buffer[0],4,0,(sockaddr*)&addr,size);
				break;
			}
		case IDC_BTUP:
			{	
				y =  m_LeftTopY-100; 
				*(WORD*)&buffer[0] = x;
				*(WORD*)&buffer[2] = y;
				int ret = sendto(m_Socket,&buffer[0],4,0,(sockaddr*)&addr,size);
				break;			
			}
		case IDC_BTLEFT:
			{	
				x =  m_LeftTopX-100; 
				*(WORD*)&buffer[0] = x;
				*(WORD*)&buffer[2] = y;
				int ret = sendto(m_Socket,&buffer[0],4,0,(sockaddr*)&addr,size);
				break;			
			}
		case IDC_BTRIGHT:
			{	
				x =  m_LeftTopX+100; 
				*(WORD*)&buffer[0] = x;
				*(WORD*)&buffer[2] = y;
				int ret = sendto(m_Socket,&buffer[0],4,0,(sockaddr*)&addr,size);
				break;			
			}
		case IDC_BTRESTORE:
			{
				*(WORD*)&buffer[0] = 0;
				*(WORD*)&buffer[2] = 0;
				int ret = sendto(m_Socket,&buffer[0],4,0,(sockaddr*)&addr,size);
				break;				
			}
		}
	}

}

void CAboutDlg::OnOK() 
{
//	CDialog::OnOK();
}


void CServerDlg::OnSyssetting() 
{
	
	CSysSetting  sysSet;
	sysSet.DoModal();
}


void CServerDlg::OnOperatormge() 
{
	COprManage OprMge;
	OprMge.DoModal();
	

}

void CServerDlg::OnQuit() 
{
	OnCancel();	
}
