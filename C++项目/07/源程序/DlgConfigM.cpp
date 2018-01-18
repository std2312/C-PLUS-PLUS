// DlgConfigM.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgConfigM.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgConfigM dialog
extern CBbbApp theApp;

CDlgConfigM::CDlgConfigM(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConfigM::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgConfigM)
	//}}AFX_DATA_INIT
}


void CDlgConfigM::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgConfigM)
	DDX_Control(pDX, IDC_EDIT3, password);
	DDX_Control(pDX, IDC_EDIT2, users);
	DDX_Control(pDX, IDC_EDIT1, database);
	DDX_Control(pDX, IDC_COMBO1, server);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgConfigM, CDialog)
	//{{AFX_MSG_MAP(CDlgConfigM)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgConfigM message handlers

BOOL CDlgConfigM::OnInitDialog() 
{
	CDialog::OnInitDialog();
	database.SetWindowText("StudentManage");
	users.SetWindowText("sa");

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgConfigM::OnOK() 
{
	
	
	//CDialog::OnOK();
}

void CDlgConfigM::OnButton1() 
{
	CString temp;
	char filepath[MAX_PATH];
	GetModuleFileName(NULL,filepath,MAX_PATH);
	
	temp = theApp.ExtractFilePath(filepath);//获取可执行文件的路径
	
	CString str;
	server.GetWindowText(str);
	WritePrivateProfileString("DatabaseConfig","Server",str,temp+"Login.ini");

	database.GetWindowText(str);
	WritePrivateProfileString("DatabaseConfig","Database",str,temp+"Login.ini");

	users.GetWindowText(str);
	WritePrivateProfileString("DatabaseConfig","User",str,temp+"Login.ini");

	password.GetWindowText(str);
	WritePrivateProfileString("DatabaseConfig","PWD",str,temp+"Login.ini");

	MessageBox("配置成功.","提示",64);
	EndDialog(0);
	
}

void CDlgConfigM::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CDlgConfigM::OnButton2() 
{
	EndDialog(0);	
}

BOOL CDlgConfigM::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==	WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam = 9;
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgConfigM::EnumServers()
{
	int i,m;
	VARIANT sqldmo,sqlserver;

	//LPOLESTR * classid ;
	//CLSIDFromProgID();
	//CLSIDFromString(classid,"sss");
	//ProgIDFromCLSID(,classid);
	//CComPtr temp;
	//temp.CoCreateInstance("sss");
	//CoCreateInstance();
		//sqldmo = CreateOleAdviseHolder();
	//CoCreateInstance();
}
