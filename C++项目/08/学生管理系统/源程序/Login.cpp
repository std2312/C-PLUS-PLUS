// Login.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_Name = _T("");
	m_PassWord = _T("");
	//}}AFX_DATA_INIT
	m_Num = 0;
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

void CLogin::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	m_Num++;
	CString sql;
	sql.Format("select * from tb_user where username = '%s' and pwd = '%s'",
		m_Name,m_PassWord);
	m_LoginSet = new CLoginSet(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!m_LoginSet->Open(AFX_DB_USE_DEFAULT_TYPE,sql))
	{
		AfxMessageBox("tb_studentinfo 表打开失败!");
	}
	if(m_LoginSet->GetRecordCount()!=0)
	{
		CDialog::OnOK();
	}
	else
	{
		if(m_Num == 3)
		{
			MessageBox("密码3次不正确");
			CDialog::OnCancel();
		}
		else
		{
			MessageBox("用户名或密码不正确");
			m_Name = "";
			m_PassWord = "";
			UpdateData(FALSE);
		}
	}
	if(m_LoginSet->IsOpen())
	{
		m_LoginSet->Close();
		delete m_LoginSet;
	} 
}
