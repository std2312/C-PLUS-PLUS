// NewNotedlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "NewNotedlg.h"
#include "Restoredlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define AW_BLEND                    0x00080000 //淡入淡出
#define AW_HIDE                     0x00010000 //隐藏
/////////////////////////////////////////////////////////////////////////////
// CNewNotedlg dialog


CNewNotedlg::CNewNotedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewNotedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewNotedlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewNotedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewNotedlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewNotedlg, CDialog)
	//{{AFX_MSG_MAP(CNewNotedlg)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewNotedlg message handlers

BOOL CNewNotedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CenterWindow();
	DWORD dwStyle = AW_BLEND;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));
	MYFUNC* AnimateWindow;
	AnimateWindow = (MYFUNC *)::GetProcAddress(hInst,"AnimateWindow");
	AnimateWindow(this->m_hWnd,1000,dwStyle);
	FreeLibrary(hInst);	
	AddToTable();
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewNotedlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	DWORD dwStyle = AW_BLEND;
	HINSTANCE hInst=LoadLibrary("User32.DLL"); 
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));
	MYFUNC* AnimateWindow;
	AnimateWindow=(MYFUNC *)::GetProcAddress(hInst,"AnimateWindow");
	AnimateWindow(this->GetSafeHwnd(),1000,AW_HIDE | dwStyle);
	FreeLibrary(hInst);
	CDialog::OnCancel();
	CDialog::OnTimer(nIDEvent);
}

void CNewNotedlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);	
	CRestoredlg dlg;
	dlg.m_Name  = m_Name;
	dlg.m_Phone = m_Phone;
	dlg.m_Note  = m_Note;
	dlg.DoModal();
	CDialog::OnCancel();
	CDialog::OnLButtonDown(nFlags, point);
}

void CNewNotedlg::AddToTable()
{
	CString sql;
	sql.Format("select * from tb_phonebook where 电话号码='%s'",m_Phone);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Name = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("姓名");
	}
	else
		m_Name = "新号码";
	
	CTime time = CTime::GetCurrentTime();
	sql.Format("insert into tb_recvnote(发送人姓名,发送人电话,信息内容,接收时间)values\
		('%s','%s','%s','%s')",m_Name,m_Phone,m_Note,time.Format("%y-%m-%d %H:%M:%S"));
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}
