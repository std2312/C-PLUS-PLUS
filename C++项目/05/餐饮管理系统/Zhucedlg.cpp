// Zhucedlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Zhucedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhucedlg dialog

extern CMyApp theApp;
CZhucedlg::CZhucedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZhucedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZhucedlg)
	m_Name = _T("");
	m_Pwd = _T("");
	m_Pwd1 = _T("");
	//}}AFX_DATA_INIT
}


void CZhucedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZhucedlg)
	DDX_Text(pDX, IDC_EDIT_name, m_Name);
	DDX_Text(pDX, IDC_EDIT_pwd, m_Pwd);
	DDX_Text(pDX, IDC_EDIT_pwd1, m_Pwd1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZhucedlg, CDialog)
	//{{AFX_MSG_MAP(CZhucedlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_reset, OnBUTTONreset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhucedlg message handlers

void CZhucedlg::OnButtonOk() 
{
	UpdateData();
	if(m_Name.IsEmpty()||m_Pwd.IsEmpty()||m_Pwd1.IsEmpty())
	{
		AfxMessageBox("�û������벻��Ϊ��");
		return;
	}
	if(m_Pwd!=m_Pwd1)
	{
		AfxMessageBox("���벻һ��");
		return;
	}
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from Login where Uname='"+m_Name+"'"),NULL,adCmdText);
	if(m_pRs->adoEOF)
	{
		theApp.m_pCon->Execute((_bstr_t)("insert into Login(Uname,Upasswd,power)values('"+m_Name+"',\
		'"+m_Pwd+"',2)"),NULL,adCmdText);
		AfxMessageBox("ע��ɹ�");
		CDialog::OnOK();
	}
	else
	{
		AfxMessageBox("�û����Ѵ���");
		return;
	}

}

void CZhucedlg::OnBUTTONreset() 
{
	m_Name="";
	m_Pwd="";
	m_Pwd1="";
	UpdateData(false);
	
}

BOOL CZhucedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_reg)),TRUE);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
