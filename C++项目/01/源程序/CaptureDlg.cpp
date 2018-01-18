// CaptureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Capture.h"
#include "CaptureDlg.h"
#include "ControlForm.h"
#include "Autodlg.h"
#include "Playdlg.h"
#include "Login.h"
#include "Managedlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CCaptureDlg dialog


CCaptureDlg::CCaptureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCaptureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCaptureDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon        = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_CapitonColor = RGB(0,0,255);
	m_Caption      = "社区视频监控系统";
	m_IsMax        = TRUE;
	m_Time         = FALSE;
	m_Kinescope    = FALSE;
	m_Cancel       = FALSE;
}

void CCaptureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCaptureDlg)
	DDX_Control(pDX, IDC_REBRUSH, m_ReBrush);
	DDX_Control(pDX, IDC_INBRUSH, m_InBrush);
	DDX_Control(pDX, IDC_INAPERTURE, m_InAperture);
	DDX_Control(pDX, IDC_REAPERTURE, m_ReAperture);
	DDX_Control(pDX, IDC_RELEN, m_ReLen);
	DDX_Control(pDX, IDC_INLEN, m_InLen);
	DDX_Control(pDX, IDC_REFOCI, m_ReFoci);
	DDX_Control(pDX, IDC_INFOCI, m_InFoci);
	DDX_Control(pDX, IDC_BUTTONRIGHT, m_ButtonRight);
	DDX_Control(pDX, IDC_BUTTONLEFT, m_ButtonLeft);
	DDX_Control(pDX, IDC_BUTTONUP, m_ButtonUp);
	DDX_Control(pDX, IDC_BUTTONDOWN, m_ButtonDown);
	DDX_Control(pDX, IDC_MSCOMM1, m_Com);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCaptureDlg, CDialog)
	//{{AFX_MSG_MAP(CCaptureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_SNAPSHOT, OnSnapshot)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_BMP, OnBmp)
	ON_BN_CLICKED(IDC_JPG, OnJpg)
	ON_BN_CLICKED(IDC_VGA, OnVga)
	ON_BN_CLICKED(IDC_PCI, OnPci)
	ON_BN_CLICKED(IDC_SETTING, OnSetting)
	ON_WM_CTLCOLOR()
	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCACTIVATE()
	ON_BN_CLICKED(IDC_CONTROL, OnControl)
	ON_BN_CLICKED(IDC_AUTOMATISM, OnAutomatism)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_KINESCOPE, OnKinescope)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_MANAGE, OnManage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureDlg message handlers



BOOL CCaptureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CButton* pBmpButton = (CButton*) GetDlgItem(IDC_BMP);
	pBmpButton->SetCheck(1);

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
	CLogin dlg;
	if(dlg.DoModal() != IDOK)
	{
		m_Cancel = TRUE;
		CDialog::OnCancel();
	}
	char buf[256];
	::GetCurrentDirectory(256,buf);
	m_PathText.Format("%s",buf);
	m_UserName = dlg.m_Name;
	m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t登录\r\n",m_UserName,m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	strcat(buf,"\\log.txt");
	m_LogPath.Format("%s",buf);
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
	
	//加载背景位图
	m_BKGround.LoadBitmap(IDB_BKGROUND);
	m_BorderHeight  = GetSystemMetrics(SM_CYBORDER);
	m_BorderWidth   = GetSystemMetrics(SM_CXBORDER);
	m_CaptionHeight = GetSystemMetrics(SM_CYCAPTION);	
	SetWindowText(m_Caption);
	m_CaptionFont.CreateFont(14,10,0,3,600,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_ROMAN,"宋体");
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MINBT);
	BITMAPINFO bInfo;
	bitmap.GetObject(sizeof(bInfo),&bInfo);
	m_ButtonWidth = bInfo.bmiHeader.biWidth;
	m_ButtonHeight = bInfo.bmiHeader.biHeight;
	bitmap.DeleteObject();

	CString strTemp;
	m_Frame.Create(IDD_PANEL_DIALOG,NULL);
	CRect rc;
	GetWindowRect(rc);
	m_Frame.SetWindowPos(&wndTop,0,0,rc.Width()-180,rc.Height()-10,SWP_SHOWWINDOW);
	m_Frame.ShowWindow(SW_SHOW);
	CButton* pVGAButton = (CButton*) GetDlgItem(IDC_VGA);
	CButton* pPCIButton = (CButton*) GetDlgItem(IDC_PCI);
	CString str= "temp";
	GetPrivateProfileString("显卡设置","类型","VGA" ,str.GetBuffer(0), 10, "./syssetting.ini");	
	BOOL ret;
	if(str=="VGA")
	{
		pVGAButton->SetCheck(1);
		pPCIButton->SetCheck(0);
		//初始化SDK
		ret = VCAInitSdk(m_Frame.m_hWnd,PCI_VIEDOMEMORY);
	}
	else
	{
		ret = VCAInitSdk(m_Frame.m_hWnd,PCI_MEMORY_VIDEOMEMORY);
		pVGAButton->SetCheck(0);
		pPCIButton->SetCheck(1);
	}	
	if(ret)
	{
		//获得几路视频
		m_DevNum = VCAGetDevNum();
		m_Frame.CreatePreWnd((int)sqrt(m_DevNum));
		for (int i = 0; i<m_DevNum; i++)
		{
			VCAOpenDevice(i,m_Frame.m_pList[i].m_hWnd);
			BOOL ret = VCAStartVideoPreview(i);	
			m_Frame.UpdateAllPreView();
		}
		m_BStop = FALSE;
	}
	SetTimer(1,1000,NULL);

	m_ButtonUp.m_Type    = ctUp;
	m_ButtonDown.m_Type  = ctDown;
	m_ButtonLeft.m_Type  = ctLeft;
	m_ButtonRight.m_Type = ctRight;
	m_InFoci.m_Type      = ctInFoci;
	m_ReFoci.m_Type      = ctReFoci;
	m_InLen.m_Type       = ctInLen;
	m_ReLen.m_Type       = ctReLen;
	m_InAperture.m_Type  = ctInAperture;
	m_ReAperture.m_Type  = ctReAperture;
	m_InBrush.m_Type     = ctInBrush;
	m_ReBrush.m_Type     = ctReBrush;
	m_Len = GetPrivateProfileInt("使用字节数","字节数",8,"./stage.ini");
	m_ActoinCount = GetPrivateProfileInt("控制项","控制数",13,"./stage.ini");
	m_pData = new  unsigned char[m_ActoinCount][MAXNUM];
	m_Port = GetPrivateProfileInt("端口设置","端口号",1,"./stage.ini");
	GetPrivateProfileString("端口设置","环境设置","9600,n,8,1",
		m_Setting.GetBuffer(0),MAX_PATH,"./stage.ini");
	int data;
	char buff[20] = {0};
	char var[20]  = {0};
	for (int i = 0 ; i<m_ActoinCount ; i++)
	{
		for (int j = 0 ; j <m_Len; j++)
		{
			char section[20] = "字节";
			itoa(i+1,var,10);
			itoa(j+1,buff,10);
			strcat(section,buff);
			data = GetPrivateProfileInt(var,section,0,"./stage.ini");
			m_pData[i][j] = data;
		}
	}
	//设置端口信息,并打开端口
	m_Com.SetSettings(m_Setting);
	m_Com.SetOutBufferSize(512);
	m_Com.SetCommPort(m_Port);
	m_Com.SetSThreshold(0);
	m_Com.SetPortOpen(TRUE);
	return TRUE; 
}

void CCaptureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCaptureDlg::OnPaint() 
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
	DrawDialog(FALL);
	m_IsDrawForm = TRUE;
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCaptureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCaptureDlg::OnCancel()
{
	for(int i=0;i<m_DevNum;i++)
		VCACloseDevice(i);
	VCAUnInitSdk();
	CDialog::OnCancel();
}

void CCaptureDlg::OnTimer(UINT nIDEvent) 
{
	//判断某一路是否有信号
	eFieldFrequency frequency;
	for (int i=0;i<m_DevNum;i++)
	{
		VCAGetVidFieldFrq(i,frequency);
		if(frequency == FIELD_FREQ_0HZ)  //无信号
		{
			if (m_Frame.m_pList[i].m_ShowImage == TRUE)
			{
				m_Frame.m_pList[i].m_ShowImage = FALSE;
				m_Frame.m_pList[i].Invalidate();
			}
		}
		else
		{
			if(m_Frame.m_pList[i].m_ShowImage == FALSE)
			{
				m_Frame.m_pList[i].m_ShowImage = TRUE;
				m_Frame.m_pList[i].Invalidate();
				if(m_Frame.m_pList[i].m_Stop == psPreview)
				{
					VCAUpdateOverlayWnd(m_Frame.m_hWnd);
					VCAUpdateVideoPreview(i,m_Frame.m_pList[i].m_hWnd);	
				}
			}
		}
	}
	if(m_Time)
	{
		CTime time= CTime::GetCurrentTime();
		if(time == m_StopTime)
		{
			OnStop();
			m_Time = FALSE;
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CCaptureDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);	
	CPoint pos(30,1);
	m_MinRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight 
		+2*m_BorderHeight -m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	pos.x = 55;
	m_MaxRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight
		+2*m_BorderHeight -m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	pos.x = 80;
	m_CloseRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight
		+2*m_BorderHeight -m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	Invalidate();

	CRect rc,frc;
	GetClientRect(rc);
	CRect rcconctrl;
	GetDlgItem(IDC_STATIC1)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_STATIC1)->MoveWindow(rc.Width()-170,rc.top+55,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_STATIC2)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_STATIC2)->MoveWindow(rc.Width()-170,rc.top+255,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_REFOCI)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_REFOCI)->MoveWindow(rc.Width()-150,rc.top+80,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_RELEN)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_RELEN)->MoveWindow(rc.Width()-150,rc.top+120,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_REAPERTURE)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_REAPERTURE)->MoveWindow(rc.Width()-150,rc.top+160,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_REBRUSH)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_REBRUSH)->MoveWindow(rc.Width()-150,rc.top+200,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_INFOCI)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_INFOCI)->MoveWindow(rc.Width()-80,rc.top+80,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_INLEN)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_INLEN)->MoveWindow(rc.Width()-80,rc.top+120,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_INAPERTURE)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_INAPERTURE)->MoveWindow(rc.Width()-80,rc.top+160,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_INBRUSH)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_INBRUSH)->MoveWindow(rc.Width()-80,rc.top+200,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_BUTTONUP)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_BUTTONUP)->MoveWindow(rc.Width()-110,rc.top+270,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_MSCOMM1)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_MSCOMM1)->MoveWindow(rc.Width()-110,rc.top+320,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_BUTTONDOWN)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_BUTTONDOWN)->MoveWindow(rc.Width()-110,rc.top+370,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_BUTTONLEFT)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_BUTTONLEFT)->MoveWindow(rc.Width()-160,rc.top+320,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_BUTTONRIGHT)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_BUTTONRIGHT)->MoveWindow(rc.Width()-60,rc.top+320,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_CONTROL)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_CONTROL)->MoveWindow(rc.Width()-170,rc.top+435,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_KINESCOPE)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_KINESCOPE)->MoveWindow(rc.Width()-170,rc.top+470,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_SNAPSHOT)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_SNAPSHOT)->MoveWindow(rc.Width()-170,rc.top+505,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_AUTOMATISM)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_AUTOMATISM)->MoveWindow(rc.Width()-170,rc.top+575,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_MANAGE)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_MANAGE)->MoveWindow(rc.Width()-85,rc.top+435,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_PLAY)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_PLAY)->MoveWindow(rc.Width()-85,rc.top+470,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_SETTING)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_SETTING)->MoveWindow(rc.Width()-85,rc.top+505,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_STOP)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_STOP)->MoveWindow(rc.Width()-85,rc.top+575,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_BMP)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_BMP)->MoveWindow(rc.Width()-172,rc.top+540,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_JPG)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_JPG)->MoveWindow(rc.Width()-133,rc.top+540,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_VGA)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_VGA)->MoveWindow(rc.Width()-87,rc.top+540,
		rcconctrl.Width(),rcconctrl.Height());
	GetDlgItem(IDC_PCI)->GetClientRect(rcconctrl);
	GetDlgItem(IDC_PCI)->MoveWindow(rc.Width()-48,rc.top+540,
		rcconctrl.Width(),rcconctrl.Height());

	m_Frame.SetWindowPos(&wndTop,0,0,rc.Width()-180,rc.Height()-10,SWP_SHOWWINDOW);
	m_Frame.GetClientRect(frc);
	m_Frame.SetWindowPos(NULL,0,7,frc.Width(),rc.Height()-8,0);
	m_Frame.ShowWindow(SW_SHOW);
}

void CCaptureDlg::OnOK() 
{

}

void CCaptureDlg::OnSnapshot() 
{
	if(CPreView::m_CurIndex != -1)
	{
		if(m_Frame.m_pList[CPreView::m_CurIndex].m_ShowImage)
		{
			CButton* pBmpButton = (CButton*)GetDlgItem(IDC_BMP);
			if(pBmpButton->GetCheck() != 0)
			{
				CFileDialog fDlg(FALSE,"bmp","bmp_001",OFN_HIDEREADONLY 
					| OFN_OVERWRITEPROMPT,"bmp|*.bmp",this);
				if(fDlg.DoModal() == IDOK)
				{
					CString fName = fDlg.GetPathName();
					VCASaveAsBmpFile(CPreView::m_CurIndex,fName);		
				}
			}
			else
			{
				CFileDialog fDlg(FALSE,"jpg","jpg_001",OFN_HIDEREADONLY 
					| OFN_OVERWRITEPROMPT,"JPG|*.JPG",this);
				if(fDlg.DoModal() == IDOK)
				{
					CString fName = fDlg.GetPathName();
					VCASaveAsJpegFile(CPreView::m_CurIndex,fName);		
				}		
			}
			m_LogTime = CTime::GetCurrentTime();
			CString strText;
			strText.Format("%s\t%s\t快照\r\n",m_UserName,
				m_LogTime.Format("%y-%m-%d %H:%M:%S"));
			CFile file;
			file.Open(m_LogPath,CFile::modeWrite);
			file.SeekToEnd();
			file.Write(strText,strText.GetLength());
			file.Close();
		}
		else
		{
			MessageBox("当前选择的图像不能预览!","提示");
		}
	}
}

void CCaptureDlg::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanged(lpwndpos);
	if(!m_Cancel)
	{
		for (UINT i = 0 ; i< m_DevNum; i++)
		{
			if (m_Frame.m_pList[i].m_ShowImage)
			{	
				if (m_Frame.m_pList[i].m_Stop==psStop)
				{
					VCAStopVideoPreview(i);
					VCAUpdateOverlayWnd(m_Frame.GetSafeHwnd());
				}
				else if (m_Frame.m_pList[i].m_Stop==psPreview)
				{		
					m_Frame.m_pList[i].Invalidate();
					VCAUpdateOverlayWnd(m_Frame.m_hWnd);
					VCAUpdateVideoPreview(i,m_Frame.m_pList[i].m_hWnd);
				}
			}
		}
	}
}

void CCaptureDlg::OnBmp() 
{
	CButton* pBmpButton = (CButton*)GetDlgItem(IDC_BMP);
	pBmpButton->SetCheck(1);	
	CButton* pJpgButton = (CButton*)GetDlgItem(IDC_JPG);
	pJpgButton->SetCheck(0);	
}

void CCaptureDlg::OnJpg() 
{
	CButton* pJpgButton = (CButton*)GetDlgItem(IDC_JPG);
	pJpgButton->SetCheck(1);
	CButton* pBmpButton = (CButton*)GetDlgItem(IDC_BMP);
	pBmpButton->SetCheck(0);	
}

void CCaptureDlg::OnVga() 
{
	CButton* pVGAButton = (CButton*)GetDlgItem(IDC_VGA);
	pVGAButton->SetCheck(1);	
	CButton* pPCIButton = (CButton*)GetDlgItem(IDC_PCI);
	pPCIButton->SetCheck(0);	
}

void CCaptureDlg::OnPci() 
{
	CButton* pVGAButton = (CButton*)GetDlgItem(IDC_VGA);
	pVGAButton->SetCheck(0);	
	CButton* pPCIButton = (CButton*)GetDlgItem(IDC_PCI);
	pPCIButton->SetCheck(1);	
}

void CCaptureDlg::OnSetting() 
{
	CButton* pVGAButton = (CButton*)GetDlgItem(IDC_VGA);
	int sel = pVGAButton->GetCheck();	
	if(sel)
	{
		WritePrivateProfileString("显卡设置","类型","VGA","./syssetting.ini");
	}
	else
	{
		WritePrivateProfileString("显卡设置","类型","PCI","./syssetting.ini");
	}	
	m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t设置显卡类型\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
	MessageBox("要使显卡设置生效,需要重新启动应用程序!","提示");
}

HBRUSH CCaptureDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr;
	
	if(nCtlColor == CTLCOLOR_DLG)
	{
		//定义一个位图画刷
		CBrush m_Brush(&m_BKGround);
		CRect rect;
		GetClientRect(rect);
		//选中画刷
		pDC->SelectObject(&m_Brush);
		//填充客户区域
		pDC->FillRect(rect,&m_Brush);
		return m_Brush;
	}
	else 
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	return hbr;
}

void CCaptureDlg::DrawDialog(UINT Flags)
{
	m_FrameHeight   = GetSystemMetrics(SM_CYFIXEDFRAME);
	m_BorderHeight  = GetSystemMetrics(SM_CYBORDER);
	m_FrameWidth    = GetSystemMetrics(SM_CXFIXEDFRAME);
	m_BorderWidth   = GetSystemMetrics(SM_CXBORDER);
	m_CaptionHeight = GetSystemMetrics(SM_CYCAPTION);

	CRect Clientrect;
	GetClientRect(Clientrect);
	CRect WinRC,FactRC;
	GetWindowRect(WinRC);
	FactRC.CopyRect(CRect(0,0,WinRC.Width(),WinRC.Height()));
	//获取窗口设备上下文
	CWindowDC WindowDC(this);
	CBitmap LeftLine,*OldObj;
	BITMAPINFO bitinfo;	
	CDC memDC;
	memDC.CreateCompatibleDC(&WindowDC);
	int leftwidth     = 0; //左标题的宽度
	int rightwidth    = 0; //右标题的宽度
	int leftlinewidth = 0; //窗体边框和3D宽度
	int rLineWidth;
	int bLineHeight;
	DeleteObject(LeftLine);
	LeftLine.LoadBitmap(IDB_RIGHTTITLE); //加载右标题
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	rightwidth = bitinfo.bmiHeader.biWidth;
	LeftLine.Detach();
	int x,y;
	//绘制左边线
	//获取位图大小
	if(Flags & FLEFTBAR)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_LEFTBAR);
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;				
		OldObj = memDC.SelectObject(&LeftLine);
		//判断位图的宽度与窗体边缘的宽度
		leftlinewidth = (x> m_FrameWidth+m_BorderWidth)? x:m_FrameWidth+m_BorderWidth;
		WindowDC.StretchBlt(0,m_CaptionHeight,leftlinewidth,
			FactRC.Height()-m_CaptionHeight,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}	
	//绘制左标题
	if(Flags & FLEFTTITLE)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_LEFTTITLE);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		leftwidth = x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		m_TitleDrawHeight = (m_CaptionHeight+4 > y) ? m_CaptionHeight+4 : y;
		m_LTitleRc.CopyRect(CRect(0,0,x,m_TitleDrawHeight));
		WindowDC.StretchBlt(m_LTitleRc.left,m_LTitleRc.top,m_LTitleRc.Width(),
			m_LTitleRc.Height(),&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}
	//绘制右标题
	if(Flags & FRIGHTTITLE)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_RIGHTTITLE);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		m_TitleDrawHeight = (m_CaptionHeight+4 > y) ? m_CaptionHeight+4 : y;	
		m_RTitleRc.CopyRect(CRect(FactRC.right-x,0,FactRC.right,m_TitleDrawHeight));
		WindowDC.StretchBlt(m_RTitleRc.left,m_RTitleRc.top,m_RTitleRc.Width(),
			m_RTitleRc.Height(),&memDC,0,0,x,y,SRCCOPY);
		DeleteObject( memDC.SelectObject(OldObj));
		LeftLine.Detach();
	}
	//绘制中间标题
	if(Flags & FMIDTITLE)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_MIDTITLE);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		m_TitleDrawHeight = (m_CaptionHeight+4 > y) ? m_CaptionHeight+4 : y;
		m_MTitleRc.CopyRect(CRect(m_LTitleRc.right,0,m_RTitleRc.left,m_TitleDrawHeight));
		WindowDC.StretchBlt(m_MTitleRc.left,m_MTitleRc.top,m_MTitleRc.Width(),
			m_MTitleRc.Height(),&memDC,0,0,x,y,SRCCOPY);
		LeftLine.Detach();
		memDC.SelectObject(OldObj);
	}

	//绘制右边框
	if(Flags & FRIGHTBAR)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_RIGHTBAR);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		rLineWidth = m_FrameWidth + m_BorderWidth;
		rLineWidth = rLineWidth>x? rLineWidth:x;
		WindowDC.StretchBlt(m_RTitleRc.right-rLineWidth,m_TitleDrawHeight,rLineWidth,
			FactRC.Height()-m_TitleDrawHeight,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}

	//绘制底边框
	if(Flags & FBOTTOMBAR)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_BOTTOMBAR);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		bLineHeight = m_BorderHeight + m_FrameHeight;
		bLineHeight = bLineHeight>y? bLineHeight:y;
		WindowDC.StretchBlt(leftlinewidth,FactRC.Height()-bLineHeight,m_RTitleRc.right
			-rLineWidth-leftlinewidth, bLineHeight,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}
	//绘制底边框
	CPoint pos(30,1);
	m_MinRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight+2*m_BorderHeight
		-m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	pos.x = 55; 	
	m_MaxRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight+2*m_BorderHeight 
		-m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	pos.x = 80;
	m_CloseRect.CopyRect(CRect(m_RTitleRc.left+pos.x,(m_TitleDrawHeight+2*m_BorderHeight
		-m_ButtonHeight)/2+pos.y,m_ButtonWidth,m_ButtonHeight));
	//绘制最小化按钮
	if(Flags & FMINBUTTON)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_MINBT);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		WindowDC.StretchBlt(m_MinRect.left,m_MinRect.top,m_MinRect.right,
			m_MinRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}
	//绘制最大化按钮
	if ( Flags & FMAXBUTTON)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_MAXBT);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj =  memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		WindowDC.StretchBlt(m_MaxRect.left,m_MaxRect.top,m_MaxRect.right,
			m_MaxRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}
	//绘制关闭按钮
	if(Flags & FCLOSEBUTTON)
	{
		DeleteObject(LeftLine);
		LeftLine.LoadBitmap(IDB_CLOSEBT);
		//获取位图大小
		LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
		OldObj = memDC.SelectObject(&LeftLine);
		x = bitinfo.bmiHeader.biWidth;
		y = bitinfo.bmiHeader.biHeight;
		WindowDC.StretchBlt(m_CloseRect.left,m_CloseRect.top,m_CloseRect.right,
			m_CloseRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		memDC.SelectObject(OldObj);
		LeftLine.Detach();
	}
	LeftLine.DeleteObject();
	memDC.DeleteDC();
	DrawCaption();
}

void CCaptureDlg::DrawCaption()
{
	if(!m_Caption.IsEmpty())
	{
		CDC* pDC = GetWindowDC();
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_CapitonColor);
		pDC->SetTextAlign(TA_CENTER);
		CRect rect;
		GetClientRect(rect);
		pDC->SelectObject(&m_CaptionFont);
		pDC->TextOut(rect.Width()/2, m_CaptionHeight/3 ,m_Caption);	
		ReleaseDC(pDC);
	}
}

void CCaptureDlg::OnNcMouseMove(UINT nHitTest, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect tempMin,tempMax,tempClose,ClientRect;
	CWindowDC WindowDC (this);
	CDC memDC;
	memDC.CreateCompatibleDC(&WindowDC);
	BITMAPINFO bInfo;
	CBitmap LeftLine;
	int x,y;
	GetWindowRect(ClientRect);
	tempMin.CopyRect(CRect(m_MinRect.left+ ClientRect.left,ClientRect.top
		+m_MinRect.top,m_MinRect.right+m_MinRect.left+ ClientRect.left,
		m_MinRect.bottom+m_MinRect.top+ClientRect.top));
	tempMax.CopyRect(CRect(m_MaxRect.left+ ClientRect.left,ClientRect.top
		+m_MaxRect.top,m_MaxRect.right+m_MaxRect.left+ ClientRect.left,
		m_MaxRect.bottom+m_MaxRect.top+ClientRect.top));
	tempClose.CopyRect(CRect(m_CloseRect.left+ ClientRect.left,ClientRect.top
		+m_CloseRect.top,m_CloseRect.right+m_CloseRect.left+ ClientRect.left,
		m_CloseRect.bottom+m_CloseRect.top+ClientRect.top));
	if(tempMin.PtInRect(point)) //鼠标在最小化按钮上移动时,更改按钮显示的位图
	{
		if(m_ButtonState != bsMin)
		{
			LeftLine.LoadBitmap(IDB_MINHOTBT);
			LeftLine.GetObject(sizeof(bInfo),&bInfo);		
			x = bInfo.bmiHeader.biWidth;
			y = bInfo.bmiHeader.biHeight;
			memDC.SelectObject(&LeftLine);
			WindowDC.StretchBlt(m_MinRect.left,m_MinRect.top,m_MinRect.right,
				m_MinRect.bottom,&memDC,0,0,x,y,SRCCOPY);
			m_IsDrawForm = FALSE;
			m_ButtonState = bsMin;	
			LeftLine.Detach();
		}
	}
	else if(tempMax.PtInRect(point))
	{
		if(m_ButtonState!=bsMax && m_ButtonState!=bsRes)
		{
			LeftLine.LoadBitmap(IDB_MAXHOTBT);
			LeftLine.GetObject(sizeof(bInfo),&bInfo);
			x = bInfo.bmiHeader.biWidth;
			y = bInfo.bmiHeader.biHeight;
			memDC.SelectObject(&LeftLine);
			WindowDC.StretchBlt(m_MaxRect.left,m_MaxRect.top,m_MaxRect.right,
				m_MaxRect.bottom,&memDC,0,0,x,y,SRCCOPY);
			m_IsDrawForm = FALSE;
			if (m_IsMax)
			{
				m_ButtonState = bsMax;
			}
			else
			{
				m_ButtonState = bsRes;
			}
			LeftLine.Detach();	
		}
	}
	else if(tempClose.PtInRect(point))
	{
		if(m_ButtonState != bsClose)
		{
			LeftLine.LoadBitmap(IDB_CLOSEHOTBT);
			LeftLine.GetObject(sizeof(bInfo),&bInfo);
			x = bInfo.bmiHeader.biWidth;
			y = bInfo.bmiHeader.biHeight;
			memDC.SelectObject(&LeftLine);
			WindowDC.StretchBlt(m_CloseRect.left,m_CloseRect.top,m_CloseRect.right,
				m_CloseRect.bottom,&memDC,0,0,x,y,SRCCOPY);
			m_IsDrawForm = FALSE;
			m_ButtonState = bsClose;
			LeftLine.Detach();	
		}
	}
	else
	{		
		if(m_IsDrawForm == FALSE)
		{
			if(m_ButtonState == bsMin)
				DrawDialog( FMINBUTTON);
			else if(m_ButtonState == bsClose)
				DrawDialog( FCLOSEBUTTON);
			else if(m_ButtonState == bsMax || m_ButtonState==bsRes)
				DrawDialog( FMAXBUTTON);
		}
		m_ButtonState = bsNone;
	}
	LeftLine.DeleteObject();
	ReleaseDC(&memDC);
	CDialog::OnNcMouseMove(nHitTest, point);
}

void CCaptureDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_ButtonState != bsNone)
	{
		if(m_ButtonState == bsMin)
			DrawDialog(FMINBUTTON);
		else if(m_ButtonState == bsClose)
			DrawDialog(FCLOSEBUTTON);
		else if(m_ButtonState==bsMax || m_ButtonState==bsRes)
			DrawDialog(FMAXBUTTON);
		m_ButtonState = bsNone;
	}	
	CDialog::OnMouseMove(nFlags, point);
}

void CCaptureDlg::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_ButtonState)
	{
	case bsClose: //关闭窗口
		{
			OnCancel();
		}
		break;
	case bsMin: 
		{
			ShowWindow(SW_SHOWMINIMIZED);
		}
		break;
	case bsMax:
		{
			m_ButtonState = bsMax;
			ShowWindow(SW_SHOWMAXIMIZED);
			m_IsMax = FALSE;
		}
		break;
	case bsRes:
		{			
			ShowWindow(SW_RESTORE);
			m_IsMax = TRUE;
		}
		break;
	}
	CDialog::OnNcLButtonDown(nHitTest, point);
}

BOOL CCaptureDlg::OnNcActivate(BOOL bActive) 
{
	// TODO: Add your message handler code here and/or call default
	OnPaint() ;
	return CDialog::OnNcActivate(bActive);
}

void CCaptureDlg::MoveCapture(UINT num)
{
	VARIANT vt;
	SAFEARRAY* pSafe;
	SAFEARRAYBOUND band;
	band.cElements = m_Len;
	band.lLbound   = 0;
	pSafe = SafeArrayCreate(VT_UI1,1,&band);
	for(long i=0;i<m_Len;i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[num][i]);
	}
	vt.vt     = VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);
}

//向上移动
void CCaptureDlg::OnUp()
{
	MoveCapture(0);
}
//停止移动
void CCaptureDlg::OnReset()
{
	MoveCapture(12);
}
//向下移动
void CCaptureDlg::OnDown()
{
	MoveCapture(1);
}
//向左移动
void CCaptureDlg::OnLeft()
{
	MoveCapture(2);
}
//向右移动
void CCaptureDlg::OnRight()
{
	MoveCapture(3);
}
//增加聚焦
void CCaptureDlg::OnInFoci()
{	
	MoveCapture(5);
}
//减小聚焦
void CCaptureDlg::OnReFoci()
{
	MoveCapture(4);
}
//对焦增
void CCaptureDlg::OnInLen()
{
	MoveCapture(7);
}
//对焦减
void CCaptureDlg::OnReLen()
{
	MoveCapture(6);
}
//光圈减
void CCaptureDlg::OnReAperture()
{
	MoveCapture(8);
}
//光圈增
void CCaptureDlg::OnInAperture()
{
	MoveCapture(9);
}
//雨刷减
void CCaptureDlg::OnReBrush()
{
	MoveCapture(10);
}
//雨刷增
void CCaptureDlg::OnInBrush()
{
	MoveCapture(11);
}

void CCaptureDlg::OnControl() 
{
	// TODO: Add your control notification handler code here
	CControlForm dlg;
	dlg.m_UserName = m_UserName;
	dlg.m_LogPath  = m_LogPath;
	dlg.DoModal();
	Invalidate();
}
DWORD WINAPI ThreadProc(LPVOID lpParameter )
{
	CCaptureDlg* pDlg = (CCaptureDlg*)lpParameter;
	while (true) 
	{
		switch(pDlg->m_Num)
		{
		case 0:
			//向上
			pDlg->MoveCapture(0);
			Sleep(2000);
			//向左
			pDlg->MoveCapture(2);
			Sleep(22000);
			//向下
			pDlg->MoveCapture(1);
			Sleep(2000);
			//向右	
			pDlg->MoveCapture(3);
			Sleep(22000);
			//向下
			pDlg->MoveCapture(1);
			Sleep(2000);
			//向左
			pDlg->MoveCapture(2);
			Sleep(22000);
			//向上
			pDlg->MoveCapture(0);
			Sleep(2000);
			//向右	
			pDlg->MoveCapture(3);
			Sleep(22000);
			break;
		case 1:
			//向左
			pDlg->MoveCapture(2);
			Sleep(22000);
			//向右	
			pDlg->MoveCapture(3);
			Sleep(22000);
			break;
		case 2:
			//向上
			pDlg->MoveCapture(0);
			Sleep(2000);
			//向下
			pDlg->MoveCapture(1);
			Sleep(2000);
			break;
		}
	}
	return 0;
}

void CCaptureDlg::OnAutomatism() 
{
	// TODO: Add your control notification handler code here
	CAutodlg dlg;
	dlg.m_UserName = m_UserName;
	dlg.m_LogPath  = m_LogPath;
	if(dlg.DoModal()==IDOK)
	{
		DWORD threadID;
		m_hThread = ::CreateThread(NULL,0,ThreadProc,(LPVOID)this,0,&threadID);
		m_Num = dlg.m_Num;
		m_Time = dlg.m_Time;
		if(m_Time)
		{
			m_StopTime = dlg.stoptime;
		}	
	}
	Invalidate();
}

void CCaptureDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	//停止运动
	MoveCapture(12);
	::TerminateThread(m_hThread,0);
	//停止监控
	VCAStopVideoCapture(0);
}

void CCaptureDlg::OnKinescope() 
{
	// TODO: Add your control notification handler code here
	if(!m_Kinescope)
	{
		if(CPreView::m_CurIndex != -1)
		{
			CFileDialog fDlg(FALSE,"avi","avi_001",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"AVI|*.avi",this);
			if (fDlg.DoModal()==IDOK)
			{
		
				m_Kinescope = TRUE;
				CString file = fDlg.GetPathName();
				VCASetKeyFrmInterval(CPreView::m_CurIndex,250);
				VCASetBitRate(CPreView::m_CurIndex,256);
				VCASetVidCapFrameRate(CPreView::m_CurIndex,25);
				VCASetVidCapSize(CPreView::m_CurIndex,320,240);
				VCASetXVIDQuality(CPreView::m_CurIndex,10,3);
				VCASetXVIDCompressMode(CPreView::m_CurIndex,XVID_VBR_MODE);
				BOOL ret = VCAStartVideoCapture(CPreView::m_CurIndex,CAP_ORIGIN_MPEG4_STREAM,
					MPEG4_AVIFILE_CALLBACK ,file);
				GetDlgItem(IDC_KINESCOPE)->SetWindowText("停止录像");
			}
		}
		m_LogTime = CTime::GetCurrentTime();
		CString strText;
		strText.Format("%s\t%s\t录像\r\n",m_UserName,
			m_LogTime.Format("%y-%m-%d %H:%M:%S"));
		CFile file;
		file.Open(m_LogPath,CFile::modeWrite);
		file.SeekToEnd();
		file.Write(strText,strText.GetLength());
		file.Close();
	}
	else
	{
		m_Kinescope = FALSE;
		GetDlgItem(IDC_KINESCOPE)->SetWindowText("录像");
		VCAStopVideoCapture(CPreView::m_CurIndex);
	}
}

void CCaptureDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	CPlaydlg dlg;
	dlg.m_UserName = m_UserName;
	dlg.m_LogPath  = m_LogPath;
	dlg.DoModal();
	Invalidate();
}

void CCaptureDlg::OnManage() 
{
	// TODO: Add your control notification handler code here
	CManagedlg dlg;
	dlg.m_UserName = m_UserName;
	dlg.m_LogPath  = m_LogPath;
	dlg.m_PathText = m_PathText;
	dlg.DoModal();
	Invalidate();
}
