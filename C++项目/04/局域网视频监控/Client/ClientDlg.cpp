// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
//自定义一个消息
#define CM_RECEIVED  WM_USER+2
//定义每个数据报中包含位图数据的大小
#define GraphSize    1024

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_MESSAGE(CM_RECEIVED,OnReceived)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);
		
	//获取本机IP
	hostent* phost =  gethostbyname("");
	char* localIP =	inet_ntoa (*(struct in_addr *)*phost->h_addr_list);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr  = inet_addr(localIP);
	addr.sin_port  = htons(5001);
	//创建套接字
	m_Socket = socket(AF_INET,SOCK_DGRAM,0);
	if (m_Socket == INVALID_SOCKET)
	{
		MessageBox("套接字创建失败!");
	}

	char* len = "512";
	if (setsockopt(m_Socket,SOL_SOCKET,SO_SNDBUF,len,4)!= 0)
	{
		MessageBox("设置失败!");
	}
	//绑定套接字
	if (bind(m_Socket,(sockaddr*)&addr,sizeof(addr))==SOCKET_ERROR)
	{
		MessageBox("套接字绑定失败!");
	}

	m_ServerIP= "127.0.0.1";
	GetPrivateProfileString("ServerInfo","IP","127.0.0.1",m_ServerIP.GetBuffer(0),MAX_PATH,"./Server.ini");

	WSAAsyncSelect(m_Socket,m_hWnd,CM_RECEIVED,FD_READ);
	m_X = m_Y = 0;
	m_RecvX = m_RecvY = 0;
	m_Confirm = TRUE;
	pSendBuf = new char[1024*1024*2];
	pHeader = pSendBuf;
	OnOK();
	m_Received = FALSE;
	m_Counter = 0;
	SetTimer(1,1000,NULL);
	return TRUE; 
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint() 
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
	ShowWindow(SW_HIDE);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnOK() 
{
	CDC* pDeskDC =  GetDesktopWindow()->GetDC();		//获取桌面画布对象
	CRect rc;
	GetDesktopWindow()->GetClientRect(rc);				//获取屏幕的客户区域

	int width  = 300;									//获取屏幕的宽度
	int height = 300;									//获取屏幕的高度

	CDC  memDC;											//定义一个内存画布
	memDC.CreateCompatibleDC(pDeskDC);					//创建一个兼容的画布
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDeskDC,width,height);	//创建兼容位图
	memDC.SelectObject(&bmp);							//选中位图对象
	
	BITMAP bitmap;
	bmp.GetBitmap(&bitmap);
	
	int panelsize  = 0;									//记录调色板大小
	if (bitmap.bmBitsPixel<16)							//判断是否为真彩色位图
		panelsize = pow(2,bitmap.bmBitsPixel*sizeof(RGBQUAD));

	BITMAPINFO *pBInfo = (BITMAPINFO*)LocalAlloc(LPTR,sizeof(BITMAPINFO)+panelsize);
	pBInfo->bmiHeader.biBitCount = bitmap.bmBitsPixel;
	pBInfo->bmiHeader.biClrImportant  = 0;
	pBInfo->bmiHeader.biCompression   = 0;
	pBInfo->bmiHeader.biHeight        = height;
	pBInfo->bmiHeader.biPlanes        = bitmap.bmPlanes;
	pBInfo->bmiHeader.biSize          = sizeof(BITMAPINFO);
	pBInfo->bmiHeader.biSizeImage     = bitmap.bmWidthBytes*bitmap.bmHeight;
	pBInfo->bmiHeader.biWidth         = width;
	pBInfo->bmiHeader.biXPelsPerMeter = 0;
	pBInfo->bmiHeader.biYPelsPerMeter = 0;
	m_X = m_RecvX;
	m_Y = m_RecvY;
	memDC.BitBlt(0,0,width,height,pDeskDC,m_X,m_Y,SRCCOPY);
	char* pData = new char[bitmap.bmWidthBytes* bitmap.bmHeight];
	::GetDIBits(memDC.m_hDC,bmp,0,bitmap.bmHeight,pData,pBInfo,DIB_RGB_COLORS);

	int BufSize = panelsize+ sizeof(BITMAPINFO)+bitmap.bmWidthBytes* bitmap.bmHeight;

	memcpy(pSendBuf,pBInfo,sizeof(BITMAPINFO));
	char* pHead = pSendBuf;
	pSendBuf += sizeof(BITMAPINFO);
	memcpy(pSendBuf,pData,bitmap.bmWidthBytes* bitmap.bmHeight);

	pSendBuf = pHead;

	addr1.sin_family = AF_INET;
	addr1.sin_port   = htons(5002);
	addr1.sin_addr.S_un.S_addr = inet_addr(m_ServerIP);
	//定义数据报的格式
	/*序号2位||结束标记2位||位图数据||位图数据大小4位||屏幕X坐标2位||屏幕Y坐标2位||数据报大小4位*/

	//定义每次发送位图数据的大小
	bmpsize = GraphSize;
	//计算每个位图发送的次数
	count = BufSize / GraphSize;
	mod   = BufSize % GraphSize;
	if ( mod != 0)
		count+=1;

	m_FrameIndex = 0;
	int ret = SendData(m_FrameIndex,mod,bmpsize,count,pSendBuf,addr1);

	pSendBuf = pHead;
	delete []pData;
	LocalFree(pBInfo);

	pDeskDC->DeleteDC();
	bmp.DeleteObject();
	memDC.DeleteDC();
}

void CClientDlg::OnTimer(UINT nIDEvent) 
{
	if (!m_Received)
	{
		m_Counter++;
		if (m_Counter>5)
		{
			
			m_Counter= 0;
			OnOK();  //超过5秒没有收到服务器的应答信息,重发数据
		}
	}
	else
	{
		m_Received = FALSE;
		m_Counter =0;
	}
	CDialog::OnTimer(nIDEvent);
}



void CClientDlg::OnReceived()
{
	char* pData = new char[1024];
	memset(pData,0,1024);
	sockaddr_in addr;
	int factsize =sizeof(sockaddr);
	int ret = recvfrom(m_Socket,pData,1024,0,(sockaddr*)&addr,&factsize);
	if (ret != -1)
	{
		//读取控制指令
		if (ret == 4)  //方向
		{
			m_RecvX = *(WORD*)&pData[0];
			m_RecvY = *(WORD*)&pData[2];
		}
		else if (ret==8)
		{
			m_Received = TRUE;
			m_FrameIndex +=1;
			if (m_FrameIndex<count)
				SendData(m_FrameIndex,mod,bmpsize,count,pSendBuf,addr1);
			else
				OnOK() ;
		}
	}
	delete []pData;
}


int CClientDlg::SendData(UINT index, int mod , int bmpsize , int frames,char *pSendBuf, sockaddr_in &addr)
{
	char* pPackage;
	int packsize = 0; 
	if ( mod ==0 || index != frames-1)
		packsize = 2+2+bmpsize+4+2+2+4;
	else 
		packsize = 2+2+mod+4+2+2+4;

	pPackage = new char[packsize];
	memset(pPackage,0,packsize);
	//填充数据报
	*(WORD*)&pPackage[0] = index;		//填充序号
	if (index != frames-1)				//填充结束标记
		*(WORD*)&pPackage[2] = 0;		
	else
		*(WORD*)&pPackage[2] = 1;
	//填充位图数据
	pSendBuf+=bmpsize*index;
	memcpy(&pPackage[4],pSendBuf,packsize-16);

	//填充位图大小
	*(int*)&pPackage[packsize-12]= bmpsize;
	//填充屏幕X坐标
	*(WORD*)&pPackage[packsize-8]= m_X;
	//填充屏幕Y坐标
	*(WORD*)&pPackage[packsize-6]= m_Y;
	//填充数据报大小
	*(int*)&pPackage[packsize-4] = packsize;

	m_Confirm = FALSE;
	int ret   = sendto(m_Socket,pPackage,packsize,0,(sockaddr*)&addr,sizeof(addr));
	delete[] pPackage;

	return ret;
}

void CClientDlg::OnCancel()
{
	delete[]pHeader;
	CDialog::OnCancel();
}
