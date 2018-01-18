// mystudentsysDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "mystudentsysDlg.h"

#include "Officeinfodlg.h"
#include "Subjectdlg.h"
#include "Teacherinfodlg.h"
#include "Classinfodlg.h"
#include "Class_subjectinfodlg.h"
#include "Examkinddlg.h"
#include "Examinfo_submarkdlg.h"
#include "Studentinfo_finddlg.h"
#include "Input_regbreakdlg.h"
#include "Reportdlg.h"
#include "Regbreak_finddlg.h"
#include "Grade_levelinfodlg.h"
#include "Login.h"
#include "Userdlg.h"
#include "InfoStudent.h"
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
// CMystudentsysDlg dialog

CMystudentsysDlg::CMystudentsysDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMystudentsysDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMystudentsysDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMystudentsysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMystudentsysDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMystudentsysDlg, CDialog)
	//{{AFX_MSG_MAP(CMystudentsysDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_inputmarks, OnMENUinputmarks)
	ON_COMMAND(ID_MENU_studentinfo, OnMENUstudentinfo)
	ON_COMMAND(ID_MENU_regbreakinfo, OnMENUregbreakinfo)
	ON_COMMAND(ID_MENU_markreport, OnMENUmarkreport)
	ON_COMMAND(ID_MENU_findbreakinfo, OnMENUfindbreakinfo)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_MENU_gradeleveldlg, OnMENUgradeleveldlg)
	ON_COMMAND(ID_MENU_help, OnMENUhelp)
	ON_COMMAND(ID_MENU_user, OnMENUuser)
	ON_COMMAND(ID_MENU_exit, OnMENUexit)
	ON_COMMAND(ID_MENU_infostudent, OnMENUinfostudent)
	ON_COMMAND(ID_MENU_classinfo, OnMENUclassinfo)
	ON_COMMAND(ID_MENU_classsubject, OnMENUclasssubject)
	ON_COMMAND(ID_MENU_examkind, OnMENUexamkind)
	ON_COMMAND(ID_MENU_officeinfo, OnMENUofficeinfo)
	ON_COMMAND(ID_MENU_subjectinfo, OnMENUsubjectinfo)
	ON_COMMAND(ID_MENU_teacherinfo, OnMENUteacherinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMystudentsysDlg message handlers

BOOL CMystudentsysDlg::OnInitDialog()
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
		OnOK();
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMystudentsysDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMystudentsysDlg::OnPaint() 
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
HCURSOR CMystudentsysDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMystudentsysDlg::OnMENUinputmarks() 
{
	// TODO: Add your command handler code here
	CExaminfo_submarkdlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUstudentinfo() 
{
	// TODO: Add your command handler code here
	CStudentinfo_finddlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUregbreakinfo() 
{
	// TODO: Add your command handler code here
	CInput_regbreakdlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUmarkreport() 
{
	// TODO: Add your command handler code here
	CReportdlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUfindbreakinfo() 
{
	// TODO: Add your command handler code here
	CRegbreak_finddlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUgradeleveldlg() 
{
	// TODO: Add your command handler code here
	CGrade_levelinfodlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUhelp() 
{
	// TODO: Add your command handler code here
	//得到可CHM文件的路径
	char exeFullPath[MAX_PATH];
	CString strPath;
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = CString(exeFullPath);
	strPath = strPath.Left(strPath.ReverseFind('\\'));
	strPath += "\\studentinfosyshelp.chm";
	//设置显示的初始页面
	strPath += "::main.htm";
	char cCommandLine[MAX_PATH];
	strcpy(cCommandLine, strPath);
	//显示CHM帮助文件
	HtmlHelp(GetSafeHwnd(), cCommandLine, HH_DISPLAY_TOPIC, 0);
}

void CMystudentsysDlg::OnCancel()
{
	if(MessageBox("确定要退出学生管理系统吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)
		return;
	CDialog::OnCancel();
}

void CMystudentsysDlg::OnMENUuser() 
{
	// TODO: Add your command handler code here
	CUserdlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUexit() 
{
	// TODO: Add your command handler code here
	OnCancel();
}

void CMystudentsysDlg::OnMENUinfostudent() 
{
	// TODO: Add your command handler code here
	CInfoStudent dlg;
	dlg.DoModal();
}


void CMystudentsysDlg::OnMENUclassinfo() 
{
	// TODO: Add your command handler code here
	CClassinfodlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUclasssubject() 
{
	// TODO: Add your command handler code here
	CClass_subjectinfodlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUexamkind() 
{
	// TODO: Add your command handler code here
	CExamkinddlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUofficeinfo() 
{
	// TODO: Add your command handler code here
	COfficeinfodlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUsubjectinfo() 
{
	// TODO: Add your command handler code here
	CSubjectdlg dlg;
	dlg.DoModal();
}

void CMystudentsysDlg::OnMENUteacherinfo() 
{
	// TODO: Add your command handler code here
	CTeacherinfodlg dlg;
	dlg.DoModal();
}
