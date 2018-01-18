// NoteManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "NoteManageDlg.h"
#include "PhoneBookdlg.h"
#include "OftenNotedlg.h"
#include "SendNotedlg.h"
#include "RecvNotedlg.h"
#include "Userdlg.h"
#include "Login.h"
#include "NoteSet.h"
#include "NewNotedlg.h"
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
// CNoteManageDlg dialog

CNoteManageDlg::CNoteManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoteManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoteManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNoteManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoteManageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNoteManageDlg, CDialog)
	//{{AFX_MSG_MAP(CNoteManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(1001,OnPhoneBook)
	ON_COMMAND(1002,OnOftenNote)
	ON_COMMAND(1004,OnSendNote)
	ON_COMMAND(1005,OnRecvNote)
	ON_COMMAND(1007,OnNoteSet)
	ON_COMMAND(1008,OnUser)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoteManageDlg message handlers

BOOL CNoteManageDlg::OnInitDialog()
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
	CLogin dlg;
	if(dlg.DoModal() != IDOK)
	{
		CDialog::OnCancel();
	}
	//创建图像列表
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONBOOK));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONNOTE));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSEND));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONRECV));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSET));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONUSER));
	
	UINT array[8];
	for(int i=0;i<8;i++)
	{
		if(i==2 || i==5)
			array[i] = ID_SEPARATOR; //第3、6个按钮为分隔条
		else
			array[i] = i+1001; //为工具栏按钮设置索引
	}
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,8);
	//关联图像列表
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);
	m_ToolBar.SetSizes(CSize(50,60),CSize(32,32)); //设置按钮和图标的大小
	m_ToolBar.SetButtonText(0,"电话簿管理");
	m_ToolBar.SetButtonText(1,"常用语管理");
	m_ToolBar.SetButtonText(3,"短信息发送");
	m_ToolBar.SetButtonText(4,"短信息接收");
	m_ToolBar.SetButtonText(6,"短信猫设置");
	m_ToolBar.SetButtonText(7,"操作员管理");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	CString port,baud,merid,accredit,isnum;
	char buf[129];
	GetPrivateProfileString("短信猫设置","端口号","default",buf,128,"./stage.ini");
	port.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","波特率","default",buf,128,"./stage.ini");
	baud.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","机器号码","default",buf,128,"./stage.ini");
	merid.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","授权号码","default",buf,128,"./stage.ini");
	accredit.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","是否设置","default",buf,128,"./stage.ini");
	isnum.Format("%s",buf);

	if(isnum == "1")
	{
		if(GSMModemInitNew((char*)(LPCTSTR)port,(char*)(LPCTSTR)baud,
			NULL,NULL,FALSE,(char*)(LPCTSTR)accredit)==FALSE)
		{
			MessageBox((char*)GSMModemGetErrorMsg());
			return TRUE; 
		}
	}
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNoteManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNoteManageDlg::OnPaint() 
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
HCURSOR CNoteManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNoteManageDlg::OnPhoneBook()
{
	CPhoneBookdlg dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnOftenNote()
{
	COftenNotedlg dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnSendNote()
{
	CSendNotedlg dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnRecvNote()
{
	CRecvNotedlg dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnNoteSet()
{
	CNoteSet dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnUser()
{
	CUserdlg dlg;
	dlg.DoModal();
}

void CNoteManageDlg::OnOK()
{
}
void CNoteManageDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	char* reData;
	char number[30],msgContent[512]; //电话号码,短信内容
	//获取接收的所有数据
	reData = (char*)GSMModemSMSReadAll(0);
	if (reData != NULL)
	{
		//获取所有短信内容的总长度
		int allDataLen = strlen(reData);
		int num = 0,content = 0;
		int once = 0 ; //接收完一个电话号码和一条短信

		for(int i=0;i<allDataLen;i++)
		{
			if(reData[i] == '|')
			{
				once+=1;
			}
			if(once == 0)
			{
				number[num] = reData[i];
				num++;
			}
			else if(once==1 && reData[i]!='|')
			{
				msgContent[content] = reData[i];
				content++;
			}
			if(once==3 && reData[i-1]=='|')
			{
				CNewNotedlg dlg;
				number[num]         = '\0';
				msgContent[content] = '\0';
				
				MessageBox(msgContent);
				CString strPhone,strNote;
				strPhone.Format("%s",number);
				strNote.Format("%s",msgContent);
				dlg.m_Phone = strPhone.Right(11);
				dlg.m_Note  = strNote;
				dlg.DoModal();
				break;
			}
		}
		
	}
	CDialog::OnTimer(nIDEvent);
}
