// DlgLogin.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString user;
extern CString password;
extern CBbbApp theApp;

extern BOOL Flag;
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs;
extern _CommandPtr m_pCom; 
/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog


CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogin)
	DDX_Control(pDX, IDC_BUTTON2, m_cancel);
	DDX_Control(pDX, IDC_BUTTON1, m_confirm);
	DDX_Control(pDX, IDC_EDIT2, m_password);
	DDX_Control(pDX, IDC_EDIT1, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	//{{AFX_MSG_MAP(CDlgLogin)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin message handlers

void CDlgLogin::OnOK() 
{	
	//CDialog::OnOK();
}

void CDlgLogin::OnButton1() 
{
	CString c_user,c_password;
	m_user.GetWindowText(c_user);
	m_password.GetWindowText(c_password);
	if (c_user.IsEmpty() || c_password.IsEmpty())
	{
		MessageBox("用户名称或密码不能为空", "用户登录信息");
		return;
	}
	CString sql;
	sql.Format("select * from tb_operator where name = '%s' and password = '%s'",c_user,c_password);

	m_pRs->raw_Close();
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	


	if (m_pRs->RecordCount>0)
	{
		Flag = true;
		user = m_pRs->GetCollect("name").bstrVal;
		password = m_pRs->GetCollect("password").bstrVal;
		//PostMessage(WM_CLOSE,0,0);
		EndDialog(0);
	}
	else
	{
		user = "";
		password = "";
		MessageBox("用户名或密码不正确.","提示",64);
		return;
	}
}

void CDlgLogin::OnButton2() 
{
	EndDialog(0);
}

BOOL CDlgLogin::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message ==WM_KEYDOWN)&&(pMsg->hwnd!= m_confirm.m_hWnd)&&(pMsg->hwnd!= m_cancel.m_hWnd))
		if (pMsg->wParam ==13)
			pMsg->wParam = 9;
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDlgLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
