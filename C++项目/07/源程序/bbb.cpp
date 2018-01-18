// bbb.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "bbb.h"
#include "bbbDlg.h"
#include "DlgLogin.h"
#include "PrintDoc.h"
#include "PrintFram.h"
#include "PrintView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBbbApp

BEGIN_MESSAGE_MAP(CBbbApp, CWinApp)
	//{{AFX_MSG_MAP(CBbbApp)



	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBbbApp construction

CBbbApp::CBbbApp()
{

}
/////////////////////////////////////////////////////////////////////////////
// The one and only CBbbApp object

CBbbApp theApp;

_ConnectionPtr m_pCon;  //ADO连接对象
_RecordsetPtr m_pRs; 
_RecordsetPtr m_pRs1;
_CommandPtr m_pCom;

BOOL Flag = FALSE; //登录标识
CString user,password;//记录当前用户
CString strserver;
CString strdbName;
CString strUser;
CString strPassword;

CReport report;
/////////////////////////////////////////////////////////////////////////////
// CBbbApp initialization

BOOL CBbbApp::InitInstance()
{
	AfxOleInit(); 
	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	m_mainfram = NULL;
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPrintDoc),
		RUNTIME_CLASS(CPrintFram),       // main SDI frame window
		RUNTIME_CLASS(CPrintView));
	AddDocTemplate(pDocTemplate);
	IniAdo();
	CDlgLogin login ;
	login.DoModal();
	if (Flag ==true)
	{
		CBbbDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();		
	}
	return FALSE;
}

CString CBbbApp::ExtractFilePath(LPTSTR filename)
{
	CString appname;
	appname = AfxGetAppName();
	appname = appname+".exe";
	CString temp;
	int pos;
	temp = filename;
	pos = temp.Find(appname,0);
	temp = temp.Left(pos);
	return temp;
}

void CBbbApp::IniAdo()
{
	try
	{		
	CString temp;
	char filepath[MAX_PATH];
	GetModuleFileName(NULL,filepath,MAX_PATH);
	
	temp = theApp.ExtractFilePath(filepath);//获取可执行文件的路径

		//m_pCon.CreateInstance("ADODB.Connection");
		CString strAdoConn;
		char temp1[100];
		
		GetPrivateProfileString("DatabaseConfig","Server","",temp1,100,temp+"login.ini");
		strserver = (TCHAR *)temp1;
		GetPrivateProfileString("DatabaseConfig","Database","",temp1,100,temp+"login.ini");
		strdbName = temp1;
		GetPrivateProfileString("DatabaseConfig","User","",temp1,100,temp+"login.ini");
		strUser = temp1;
		GetPrivateProfileString("DatabaseConfig","PWD","",temp1,100,temp+"login.ini");
		strPassword = temp1;
		strAdoConn.Format("driver={SQL Server};SERVER=%s;UID=%s;PWD=%s;DATABASE=%s", 
		                                  strserver, strUser, strPassword, strdbName);
		m_pCon.CreateInstance(_uuidof(Connection));
		m_pCon->ConnectionString = (_bstr_t)strAdoConn;
		m_pCon->Open("","","",NULL);
		m_pCom.CreateInstance("ADODB.Command");
		m_pRs.CreateInstance(_uuidof(Recordset));	

		m_pRs1.CreateInstance(_uuidof(Recordset));
	//	ADOFLAG = TRUE;

	}
	catch(_com_error)
	{		
		//ADOFLAG = FALSE;
		Flag = FALSE;
		MessageBox(0,"请检查系统配置信息", "数据库连接失败",MB_OK);		
		return;
	}
	catch(...)
	{	
		AfxMessageBox("SYS Error");
		return ;
	}
}

