// Login.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
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
	m_Time = 0;
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_OK, m_OK);
	DDX_Control(pDX, IDC_CANCEL, m_Cancel);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

BOOL CLogin::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
	{
		pMsg->wParam = 9;
	}
	if(pMsg->message == WM_LBUTTONDOWN)
	{
		CRect rect,rc;
		m_OK.GetWindowRect(&rect);
		m_Cancel.GetWindowRect(&rc);
		CPoint point;
		GetCursorPos(&point);
		if(rect.PtInRect(point))
		{
			UpdateData(TRUE);
			if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
			{
				MessageBox("用户名或密码不能为空");
				return FALSE;
			}
			m_Time++;
			try
			{
				//创建连接对象实例
				
				m_pConnection.CreateInstance("ADODB.Connection");
				//设置连接字符串
				CString strConnect="DRIVER={Microsoft Access Driver (*.mdb)};\
					uid=;pwd=;DBQ=shujuku.mdb;";
				//使用Open方法连接数据库
				m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
			}
			catch(_com_error e)
			{
				AfxMessageBox(e.Description());
			}
			CString sql;
			sql.Format("select * from tb_user where 用户名 = '%s' and 密码 = '%s'",
				m_Name,m_PassWord);
			m_pRecordset = m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!m_pRecordset->adoEOF)
			{
				CDialog::OnOK();
			}
			else
			{
				if(m_Time == 3)
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
			m_pRecordset->Close();
			m_pConnection->Close();	
		}
		if(rc.PtInRect(point))
		{
			CDialog::OnCancel();
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
