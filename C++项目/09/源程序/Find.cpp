// Find.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "Find.h"
#include "LOGIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFind dialog


CFind::CFind(CWnd* pParent /*=NULL*/)
	: CDialog(CFind::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFind)
	m_Answer = _T("");
	//}}AFX_DATA_INIT
}


void CFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFind)
	DDX_Control(pDX, IDC_STATIC_username, m_UserName);
	DDX_Control(pDX, IDC_STATIC_QUESTION, m_Question);
	DDX_Control(pDX, IDC_STATIC_PASSWD, m_PasswdStatic);
	DDX_Text(pDX, IDC_ANSWER, m_Answer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFind, CDialog)
	//{{AFX_MSG_MAP(CFind)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_EN_CHANGE(IDC_ANSWER, OnChangeAnswer)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFind message handlers

BOOL CFind::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_UserName.SetWindowText(Name);
	CString sql="select * from register where username='"+Name+"'";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		m_Question.SetWindowText(question);	
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return false;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFind::OnButtonSend() 
{
	UpdateData();
	CString name,question;
	m_UserName.GetWindowText(name);
	CString sql;
	sql.Format("select * from register where username='%s' and answer='%s'",name,m_Answer);
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(!m_pRs->adoEOF)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("password");
			m_PasswdStatic.SetWindowText("回答正确,您的密码是:"+str);			
		}
		else
		{
			m_PasswdStatic.SetWindowText("回答错误");			
		}		
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return;
	}
	m_AdoConn.ExitConn();	
}

void CFind::OnChangeAnswer() 
{
	m_PasswdStatic.SetWindowText("");	
}

void CFind::OnButtonExit() 
{
	CLOGIN dlg;
	CDialog::OnCancel();
	dlg.DoModal();	
}
