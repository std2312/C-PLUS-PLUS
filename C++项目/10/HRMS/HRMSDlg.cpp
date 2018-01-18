// HRMSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HRMS.h"
#include "HRMSDlg.h"

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
// CHRMSDlg dialog

CHRMSDlg::CHRMSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHRMSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHRMSDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON6);
}

void CHRMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHRMSDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHRMSDlg, CDialog)
	//{{AFX_MSG_MAP(CHRMSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDM_FILE_RECORD, OnFileRecord)
	ON_COMMAND(IDM_FILE_SEARCH, OnFileSearch)
	ON_COMMAND(IDM_INSERTDEPT, OnInsertdept)
	ON_COMMAND(IDM_DEPT_DUTY, OnDeptDuty)
	ON_COMMAND(IDM_HELP, OnHelp)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_ATTENDANCE_RECORD, OnAttendanceRecord)
	ON_COMMAND(IDM_TIMECARD_LIST, OnTimecardList)
	ON_COMMAND(IDM_PAY, OnPay)
	ON_COMMAND(IDM_PAYLIP, OnPaylip)
	ON_COMMAND(IDM_APPLERFILE, OnApplerfile)
	ON_COMMAND(IDM_REQUEST_EMPLOYEE, OnRequestEmployee)
	ON_COMMAND(ID_USER_REGISTER, OnUserRegister)
	ON_COMMAND(IDM_MODI_CODE, OnModiCode)
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_COMMAND(IDM_PORTFOLIO, OnPortfolio)
	ON_COMMAND(IDM_PORTFOLIO_LIST, OnPortfolioList)
	ON_COMMAND(IDM_EXPORT, OnExport)
	ON_COMMAND(IDM_APPLERLIST, OnApplerlist)
	ON_COMMAND(IDM_RESETLAND, OnResetland)
	ON_COMMAND(IDM_QUITLAND, OnQuitland)
	ON_COMMAND(IDM_REAUESTLIST, OnReauestlist)
	ON_COMMAND(IDM_AGREEMENTLIST, OnAgreementlist)
	ON_COMMAND(IDM_LABORAGE, OnLaborage)
	ON_COMMAND(IDM_HUMAN_REDEPLOY, OnHumanRedeploy)
	ON_COMMAND(IDM_EXAMINE_APPLICANT, OnExamineApplicant)
	ON_COMMAND(IDM_EXAMINE_LIST, OnExamineList)
	ON_COMMAND(ID_LABORAGE_RECORD, OnLaborageRecord)
	ON_COMMAND(IDM_LEAVEITEM, OnLeaveitem)
	ON_COMMAND(IDM_LEAVELIST, OnLeavelist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHRMSDlg message handlers

BOOL CHRMSDlg::OnInitDialog()
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

	TBBUTTON tbButton[ICONSUM] = {0};
	m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK, 0, 0);
	m_ImageList.Add(::AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(::AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(::AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(::AfxGetApp()->LoadIcon(IDI_ICON5));
	m_ImageList.Add(::AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ToolBar.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 0);
	m_ToolBar.SetImageList(&m_ImageList);
	for(int i=0; i< ICONSUM; i++)
	{
		tbButton[i].dwData		= NULL;
		tbButton[i].fsState		= TBSTATE_ENABLED;
		tbButton[i].fsStyle		= (BYTE)TBSTYLE_FLAT;
		tbButton[i].iBitmap		= i;
		
	}
	tbButton[0].idCommand = ID_ATTENDANCE_RECORD;
	tbButton[1].idCommand = IDM_REQUEST_EMPLOYEE;
	tbButton[2].idCommand = IDM_PAYLIP;
	tbButton[3].idCommand = IDM_PORTFOLIO;
	tbButton[4].idCommand = ID_ABOUT;
	m_ToolBar.AddButtons(ICONSUM, tbButton);
	m_ToolBar.AutoSize();
	m_ToolBar.SetStyle(TBSTYLE_FLAT | CCS_TOP);

	m_Menu.LoadMenu(IDR_MAINFRAME_MENU);
	SetMenu(&m_Menu);

	/*登陆功能*/
	CString statusCon;
#ifndef TESTING
		CLandingDlg dlg;
		if(IDOK != dlg.DoModal())
		{
			::G_IsLanded = FALSE;
			NonLoading();
			statusCon = "当前用户没有登录！";
			goto setstatus;
		}
		m_CurUserName = dlg.GetUserName();
#else
		m_CurUserName = "tsoft";
#endif
		statusCon.Format("当前用户是：%s", m_CurUserName);
setstatus:
	UINT indicators[] = {100, 101};
	m_StatusBar.Create(this);
	m_StatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	m_StatusBar.SetPaneInfo(0, 100, 0, 200);
	m_StatusBar.SetPaneInfo(1, 101, 0, 600);
	m_StatusBar.SetPaneText(0, statusCon);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHRMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHRMSDlg::OnPaint() 
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
HCURSOR CHRMSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHRMSDlg::OnFileRecord() 
{
	// TODO: Add your command handler code here
	CFileRecord fileRecord;
	fileRecord.DoModal();

}

void CHRMSDlg::OnFileSearch() 
{
	// TODO: Add your command handler code here
	CFileInfo fileDlg;
	fileDlg.DoModal();
}

void CHRMSDlg::OnInsertdept() 
{
	// TODO: Add your command handler code here
	CDeptInfoDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnDeptDuty() 
{
	// TODO: Add your command handler code here
	CDeptDutyDlg dlg;
	dlg.DoModal();
}



void CHRMSDlg::OnHelp() 
{
	// TODO: Add your command handler code here

	char buf[MAX_PATH];
	::GetCurrentDirectory(MAX_PATH,buf); //获取程序根目录路径
	strcat(buf,"\\scaleprint.chm");
	::ShellExecute(NULL, "open", "HRMS-Help.chm", "", "", SW_SHOW);
}

void CHRMSDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CHRMSDlg::OnAttendanceRecord() 
{
	// TODO: Add your command handler code here
	if(G_IsLanded)
	{
		CTimeCardDlg dlg;
		dlg.DoModal();
	}
	else
		MessageBox("请登陆！", "提示", MB_OK | MB_ICONWARNING);
}

void CHRMSDlg::OnTimecardList() 
{
	// TODO: Add your command handler code here
	CTimeCardList dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnPay() 
{
	// TODO: Add your command handler code here
	CPayListDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnPaylip() 
{
	// TODO: Add your command handler code here

	if(G_IsLanded)
	{
		CPayClipDlg dlg;
		dlg.DoModal();
	}
	else
		MessageBox("请登陆！", "提示", MB_OK | MB_ICONWARNING);
}

void CHRMSDlg::OnApplerfile() 
{
	// TODO: Add your command handler code here
	CApplerInfo dlg;
	dlg.DoModal();

}

void CHRMSDlg::OnRequestEmployee() 
{
	// TODO: Add your command handler code here
	if(G_IsLanded)
	{
		CApplyEmployeeDlg dlg;
		dlg.DoModal();
	}
	else
		MessageBox("请登陆！", "提示", MB_OK | MB_ICONWARNING);
}

void CHRMSDlg::OnUserRegister() 
{
	// TODO: Add your command handler code here
	CUserRegDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnModiCode() 
{
	// TODO: Add your command handler code here
	CUserRegDlg dlg;

	dlg.SetModiCodeDlg();
	dlg.SetUserName(m_CurUserName);
	dlg.DoModal();
}

void CHRMSDlg::OnExit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CHRMSDlg::OnPortfolio() 
{
	// TODO: Add your command handler code here
	if(G_IsLanded)
	{
		CAssessDlg dlg;
		dlg.DoModal();
	}
	else
		MessageBox("请登陆！", "提示", MB_OK | MB_ICONWARNING);
}

void CHRMSDlg::OnPortfolioList() 
{
	// TODO: Add your command handler code here
	CAssessList list;
	list.DoModal();

}

void CHRMSDlg::OnExport() 
{
	// TODO: Add your command handler code here
	MessageBox("把对应的数据导入Word!");
}

void CHRMSDlg::NonLoading(BOOL isLanding)
{
	if(!isLanding)
	{
		m_Menu.EnableMenuItem(IDM_MODI_CODE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_FILE_RECORD, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_APPLERFILE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_INSERTDEPT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_REQUEST_EMPLOYEE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_PORTFOLIO, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(ID_ATTENDANCE_RECORD, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_PAYLIP, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(ID_USER_REGISTER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_AGREEMENTEDIT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

		m_Menu.EnableMenuItem(IDM_EXAMINE_APPLICANT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(ID_LABORAGE_RECORD, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		m_Menu.EnableMenuItem(IDM_LEAVEITEM, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}
	else
	{
		m_Menu.EnableMenuItem(IDM_MODI_CODE, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_FILE_RECORD, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_APPLERFILE, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_INSERTDEPT, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_REQUEST_EMPLOYEE, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_PORTFOLIO, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(ID_ATTENDANCE_RECORD, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_PAYLIP, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(ID_USER_REGISTER, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_AGREEMENTEDIT, MF_BYCOMMAND | MF_ENABLED);

		m_Menu.EnableMenuItem(IDM_EXAMINE_APPLICANT, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(ID_LABORAGE_RECORD, MF_BYCOMMAND | MF_ENABLED);
		m_Menu.EnableMenuItem(IDM_LEAVEITEM, MF_BYCOMMAND | MF_ENABLED);
	}
}

void CHRMSDlg::OnApplerlist() 
{
	// TODO: Add your command handler code here
	CApplerList list;
 	list.DoModal();
}

void CHRMSDlg::OnResetland() 
{
	// TODO: Add your command handler code here
	CString str;
	CLandingDlg dlg;
	if(IDOK != dlg.DoModal())
		return ;
	
	m_CurUserName = dlg.GetUserName();
	str.Format("当前用户是：%s", m_CurUserName);
	m_StatusBar.SetPaneText(0, str);
	NonLoading(TRUE);
	G_IsLanded = TRUE;

}

void CHRMSDlg::OnQuitland() 
{
	// TODO: Add your command handler code here
	G_IsLanded = FALSE;
	m_CurUserName.Empty();
	m_StatusBar.SetPaneText(0, "当前系统没有登录.");
	NonLoading(FALSE);
}

void CHRMSDlg::OnReauestlist() 
{
	// TODO: Add your command handler code here
	CRequestInfListDlg info;
	info.DoModal();
}

void CHRMSDlg::OnAgreementlist() 
{
	// TODO: Add your command handler code here
	CAgreementListDlg dlg;
	dlg.DoModal();

}

void CHRMSDlg::OnLaborage() 
{
	// TODO: Add your command handler code here
	CLaborageRecordDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnHumanRedeploy() 
{
	// TODO: Add your command handler code here
	CHumanRemoveDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnExamineApplicant() 
{
	// TODO: Add your command handler code here
	CReqCheckDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnExamineList() 
{
	// TODO: Add your command handler code here
	CReqChkList list;
	list.DoModal();
}

void CHRMSDlg::OnLaborageRecord() 
{
	// TODO: Add your command handler code here
	CLaborRecorDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnLeaveitem() 
{
	// TODO: Add your command handler code here
	CLeaveItemDlg dlg;
	dlg.DoModal();
}

void CHRMSDlg::OnLeavelist() 
{
	// TODO: Add your command handler code here
	CLeaveList dlg;
	dlg.DoModal();
}
