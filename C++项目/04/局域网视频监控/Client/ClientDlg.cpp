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
//�Զ���һ����Ϣ
#define CM_RECEIVED  WM_USER+2
//����ÿ�����ݱ��а���λͼ���ݵĴ�С
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
		
	//��ȡ����IP
	hostent* phost =  gethostbyname("");
	char* localIP =	inet_ntoa (*(struct in_addr *)*phost->h_addr_list);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr  = inet_addr(localIP);
	addr.sin_port  = htons(5001);
	//�����׽���
	m_Socket = socket(AF_INET,SOCK_DGRAM,0);
	if (m_Socket == INVALID_SOCKET)
	{
		MessageBox("�׽��ִ���ʧ��!");
	}

	char* len = "512";
	if (setsockopt(m_Socket,SOL_SOCKET,SO_SNDBUF,len,4)!= 0)
	{
		MessageBox("����ʧ��!");
	}
	//���׽���
	if (bind(m_Socket,(sockaddr*)&addr,sizeof(addr))==SOCKET_ERROR)
	{
		MessageBox("�׽��ְ�ʧ��!");
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
	CDC* pDeskDC =  GetDesktopWindow()->GetDC();		//��ȡ���滭������
	CRect rc;
	GetDesktopWindow()->GetClientRect(rc);				//��ȡ��Ļ�Ŀͻ�����

	int width  = 300;									//��ȡ��Ļ�Ŀ��
	int height = 300;									//��ȡ��Ļ�ĸ߶�

	CDC  memDC;											//����һ���ڴ滭��
	memDC.CreateCompatibleDC(pDeskDC);					//����һ�����ݵĻ���
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDeskDC,width,height);	//��������λͼ
	memDC.SelectObject(&bmp);							//ѡ��λͼ����
	
	BITMAP bitmap;
	bmp.GetBitmap(&bitmap);
	
	int panelsize  = 0;									//��¼��ɫ���С
	if (bitmap.bmBitsPixel<16)							//�ж��Ƿ�Ϊ���ɫλͼ
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
	//�������ݱ��ĸ�ʽ
	/*���2λ||�������2λ||λͼ����||λͼ���ݴ�С4λ||��ĻX����2λ||��ĻY����2λ||���ݱ���С4λ*/

	//����ÿ�η���λͼ���ݵĴ�С
	bmpsize = GraphSize;
	//����ÿ��λͼ���͵Ĵ���
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
			OnOK();  //����5��û���յ���������Ӧ����Ϣ,�ط�����
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
		//��ȡ����ָ��
		if (ret == 4)  //����
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
	//������ݱ�
	*(WORD*)&pPackage[0] = index;		//������
	if (index != frames-1)				//���������
		*(WORD*)&pPackage[2] = 0;		
	else
		*(WORD*)&pPackage[2] = 1;
	//���λͼ����
	pSendBuf+=bmpsize*index;
	memcpy(&pPackage[4],pSendBuf,packsize-16);

	//���λͼ��С
	*(int*)&pPackage[packsize-12]= bmpsize;
	//�����ĻX����
	*(WORD*)&pPackage[packsize-8]= m_X;
	//�����ĻY����
	*(WORD*)&pPackage[packsize-6]= m_Y;
	//������ݱ���С
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
