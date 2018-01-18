// SQLManage.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "SQLManage.h"
#include "Copy.h"
#include "Return.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSQLManage dialog


CSQLManage::CSQLManage(CWnd* pParent /*=NULL*/)
	: CDialog(CSQLManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSQLManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSQLManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSQLManage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSQLManage, CDialog)
	//{{AFX_MSG_MAP(CSQLManage)
	ON_BN_CLICKED(IDC_SQLNEW, OnSqlnew)
	ON_BN_CLICKED(IDC_SQLCOPY, OnSqlcopy)
	ON_BN_CLICKED(IDC_SQLRETURN, OnSqlreturn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSQLManage message handlers

void CSQLManage::OnSqlnew() 
{
	if(MessageBox("确定要初始化数据库吗?","提示",MB_YESNO)==IDYES)
	{
		CString Sql1="delete from result";
		CString Sql2="delete from register where studentid>1000";
		CString Sql3="delete from subject";
		CString Sql4="delete from test";
		CString Sql5="delete from testanswer";
		m_AdoConn.OnInitADOConn();
		m_AdoConn.ExecuteSQL((_bstr_t)Sql1);
		m_AdoConn.ExecuteSQL((_bstr_t)Sql2);
		m_AdoConn.ExecuteSQL((_bstr_t)Sql3);
		m_AdoConn.ExecuteSQL((_bstr_t)Sql4);
		m_AdoConn.ExecuteSQL((_bstr_t)Sql5);
		m_AdoConn.ExitConn();		
		AfxMessageBox("初始化成功");
		return;
	}
	else
		return;	
}

void CSQLManage::OnSqlcopy() 
{
	CCopy dlg;
	dlg.DoModal();
	
}

void CSQLManage::OnSqlreturn() 
{
	CReturn dlg;
	dlg.DoModal();	
}
