// Login.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_LOGIN, m_BTLogin);
	DDX_Control(pDX, IDC_BTCANCLE, m_BTCancel);
	DDX_Control(pDX, IDC_PASSWORD, m_Password);
	DDX_Control(pDX, IDC_USERNAME, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_BTCANCLE, OnBtCancle)
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

void CLogin::OnOK() 
{

}

void CLogin::OnBtCancle() 
{
	EndDialog(IDCANCEL);
}

void CLogin::OnLogin() 
{
	CString user,password;
	//获取用户名和密码
	m_UserName.GetWindowText(user);
	m_Password.GetWindowText(password);
	//判断用户名和密码是否为空
	if (user.IsEmpty() || password.IsEmpty())
	{
		MessageBox("用户名和密码不能为空","提示");
		m_UserName.SetFocus();
	}
	else //用户名和密码不为空
	{
	
		_ParameterPtr puser,ppassword;
		CServerApp* pApp = (CServerApp*)AfxGetApp();
		//创建参数
		puser =  pApp->m_DataManage.m_pCommand->CreateParameter("user",adVarWChar,adParamInput,100,(_bstr_t)user);
		ppassword =  pApp->m_DataManage.m_pCommand->CreateParameter("password",adVarWChar,adParamInput,100,(_bstr_t)password);
		//添加参数
		pApp->m_DataManage.m_pConnect->CursorLocation = adUseServer;

		pApp->m_DataManage.m_pCommand->ActiveConnection = pApp->m_DataManage.m_pConnect;
		pApp->m_DataManage.m_pCommand->Parameters->Append(puser);
		pApp->m_DataManage.m_pCommand->Parameters->Append(ppassword);
		pApp->m_DataManage.m_pCommand->CommandText = "select * from tb_userInfo where username = @user and password  = @password";
		_RecordsetPtr pRecord= NULL;

		pRecord = pApp->m_DataManage.m_pCommand->Execute (0,NULL,adCmdText);
		pApp->m_DataManage.m_pCommand->Parameters->Delete("user");
		pApp->m_DataManage.m_pCommand->Parameters->Delete("password");	
		
			
		if (pRecord !=NULL )
		{	

			try //判断是否能够读取数据
			{
				CString str =(char*) (_bstr_t)pRecord->GetFields()->GetItem("UserName")->Value;
				pRecord ->Close();
			}
			catch(...)
			{
				MessageBox("用户名或密码不正确");
				m_UserName.SetFocus();
				pRecord ->Close();
				return;
			}
			EndDialog(IDOK);
		}
		else
		{
			pRecord ->Close();
			MessageBox("用户名或密码不正确");
			m_UserName.SetFocus();
		}
	}	
}

BOOL CLogin::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN )
	{
		CString str;
		//获取类名
		GetClassName(pMsg->hwnd,str.GetBuffer(0),MAX_PATH);
		if (str=="Edit")
			pMsg->wParam = VK_TAB ;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
