// LOGIN.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "LOGIN.h"
#include "Register.h"
#include "Find.h"
#include "Back.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLOGIN dialog


CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialog(CLOGIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLOGIN)
	m_UserName = _T("");
	m_UserPasswd = _T("");
	//}}AFX_DATA_INIT
}


void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLOGIN)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_TypeList);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_EDIT_USERPASSWD, m_UserPasswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialog)
	//{{AFX_MSG_MAP(CLOGIN)
	ON_BN_CLICKED(IDC_BUTTON_REG, OnButtonReg)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLOGIN message handlers
#define AW_CENTER                   0x00000010 //动画
#define AW_HIDE                     0x00010000 //隐藏
BOOL CLOGIN::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_TypeList.SetCurSel(1);

	CenterWindow();
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));
	MYFUNC* AnimateWindow;
	AnimateWindow=(MYFUNC *)::GetProcAddress(hInst,"AnimateWindow");
	AnimateWindow(this->m_hWnd,1000,dwStyle);
	FreeLibrary(hInst);
	return TRUE; 
}

void CLOGIN::OnButtonReg() 
{
	OnButtonCancel();
	CRegister dlg;
	dlg.DoModal();	
}

void CLOGIN::OnButtonCancel() 
{
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));
	MYFUNC* AnimateWindow;
	AnimateWindow=(MYFUNC *)::GetProcAddress(hInst,"AnimateWindow");
	AnimateWindow(this->GetSafeHwnd(),700,AW_HIDE|dwStyle);
	FreeLibrary(hInst);
	CDialog::OnCancel();
	
}

void CLOGIN::OnButtonOk() 
{
	UpdateData();
	CString str;
	m_TypeList.GetLBText(m_TypeList.GetCurSel(),str);
	if(m_UserName.IsEmpty())
	{
		AfxMessageBox("用户名不能为空");
		return;
	}
	if(m_UserPasswd.IsEmpty())
	{
		AfxMessageBox("密码不能为空");
		return;
	}
	CString sql="select*from register where username='"+m_UserName+"' and [password]='"+m_UserPasswd+"' and power='"+str+"'";
	try
	{
		_RecordsetPtr m_pRs;
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)
		{
			sql="select*from register where username='"+m_UserName+"'";
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(!m_pRs->adoEOF)
			{
				if(m_UserPasswd!=(char*)(_bstr_t)m_pRs->GetCollect("password"))
				{
					if(MessageBox("密码错误,是否找回密码?","提示",MB_YESNO)==IDYES)
					{	
						CFind dlg;
						dlg.Name=m_UserName;
						CDialog::OnCancel();						
						dlg.DoModal();
					}					
				}
				else
				{
					if(str!=(char*)(_bstr_t)m_pRs->GetCollect("power"))
					{
						AfxMessageBox("权限错误");
						return;
					}
				}
			}
			else
			{
				if(MessageBox("用户名不存在，是否注册？","提示",MB_YESNO)==IDYES)
				{
					CDialog::OnCancel();					
					CRegister dlg;
					dlg.m_UserName=m_UserName;
					dlg.DoModal();
				}
				else
					CDialog::OnCancel();
			}
		}
		else
		{
			if(str=="教职工")
			{
				CDialog::OnCancel();
				CBack dlg;
				dlg.DoModal();
			}
			else
				CDialog::OnOK();
		}
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return;
	}

}

void CLOGIN::OnOK()
{
	OnButtonOk();
}
