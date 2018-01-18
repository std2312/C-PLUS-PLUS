// HRMS.cpp : Defines the class behaviors for the application.
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
// CHRMSApp

BEGIN_MESSAGE_MAP(CHRMSApp, CWinApp)
	//{{AFX_MSG_MAP(CHRMSApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHRMSApp construction

CHRMSApp::CHRMSApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHRMSApp object

CHRMSApp theApp;
BOOL G_IsLanded = TRUE;

/////////////////////////////////////////////////////////////////////////////
// CHRMSApp initialization

BOOL CHRMSApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CHRMSDlg dlg;
	m_pMainWnd = &dlg;

	::CoInitialize(NULL);		//初始化COM
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CHRMSApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	CoUninitialize();
	return CWinApp::ExitInstance();
}

void PrintResult(CString &result)
{
	FILE * pFile;
	pFile = fopen("result.txt", "w");
	if(NULL == pFile)
	{
		::MessageBox(NULL, "文件打开出错！", "提示", MB_OK);
		return ;
	}
#ifdef _UNICODE
	fwrite(result.GetBuffer(0), 2, result.GetLength(), pFile);
#else
	fwrite(result.GetBuffer(0), 1, result.GetLength(), pFile);
#endif

	fclose(pFile);
}