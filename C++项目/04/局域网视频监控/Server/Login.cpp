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
	//��ȡ�û���������
	m_UserName.GetWindowText(user);
	m_Password.GetWindowText(password);
	//�ж��û����������Ƿ�Ϊ��
	if (user.IsEmpty() || password.IsEmpty())
	{
		MessageBox("�û��������벻��Ϊ��","��ʾ");
		m_UserName.SetFocus();
	}
	else //�û��������벻Ϊ��
	{
	
		_ParameterPtr puser,ppassword;
		CServerApp* pApp = (CServerApp*)AfxGetApp();
		//��������
		puser =  pApp->m_DataManage.m_pCommand->CreateParameter("user",adVarWChar,adParamInput,100,(_bstr_t)user);
		ppassword =  pApp->m_DataManage.m_pCommand->CreateParameter("password",adVarWChar,adParamInput,100,(_bstr_t)password);
		//��Ӳ���
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

			try //�ж��Ƿ��ܹ���ȡ����
			{
				CString str =(char*) (_bstr_t)pRecord->GetFields()->GetItem("UserName")->Value;
				pRecord ->Close();
			}
			catch(...)
			{
				MessageBox("�û��������벻��ȷ");
				m_UserName.SetFocus();
				pRecord ->Close();
				return;
			}
			EndDialog(IDOK);
		}
		else
		{
			pRecord ->Close();
			MessageBox("�û��������벻��ȷ");
			m_UserName.SetFocus();
		}
	}	
}

BOOL CLogin::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN )
	{
		CString str;
		//��ȡ����
		GetClassName(pMsg->hwnd,str.GetBuffer(0),MAX_PATH);
		if (str=="Edit")
			pMsg->wParam = VK_TAB ;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
