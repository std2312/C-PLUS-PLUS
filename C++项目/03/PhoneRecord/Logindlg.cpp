// Logindlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "Logindlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog


CLogindlg::CLogindlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogindlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogindlg)
	m_Name = _T("");
	m_Pwd = _T("");
	//}}AFX_DATA_INIT
	m_Time = 0;
}


void CLogindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogindlg)
	DDX_Control(pDX, IDOK, m_Ok);
	DDX_Control(pDX, IDCANCEL, m_Canel);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogindlg, CDialog)
	//{{AFX_MSG_MAP(CLogindlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogindlg message handlers


void CLogindlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Pwd.IsEmpty()) //判断数据是否为空
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_Time++; //计算登录次数
	CString sql;
	sql.Format("select * from tb_employees where 用户名 = '%s' and 密码 = '%s'",
		m_Name,m_Pwd); //设置SQL语句
	m_AdoConn.m_pRecordset = m_AdoConn.m_pConnection->Execute((_bstr_t)sql,
		NULL,adCmdText); //执行SQL语句
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		CDialog::OnOK(); //进入主窗体并关闭登录框
	}
	else
	{
		if(m_Time == 3) //判断错误是否超过3次
		{
			MessageBox("密码3次不正确");
			CDialog::OnCancel(); //关闭对话框
		}
		else
		{
			MessageBox("用户名或密码不正确");
			m_Name = "";
			m_Pwd = "";
			UpdateData(FALSE); //更新控件显示
		}
	}
	m_AdoConn.ExitConnect();
}
