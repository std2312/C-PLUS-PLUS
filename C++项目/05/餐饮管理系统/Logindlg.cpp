// Logindlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Logindlg.h"
#include "��������Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMyApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog


CLogindlg::CLogindlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogindlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogindlg)
	m_Uname = _T("");
	m_Upasswd = _T("");
	//}}AFX_DATA_INIT
	i = 0;
}


void CLogindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogindlg)
	DDX_Text(pDX, IDC_EDIT1, m_Uname);
	DDX_Text(pDX, IDC_EDIT2, m_Upasswd);
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
	UpdateData();
	if(!m_Uname.IsEmpty()||!m_Upasswd.IsEmpty())
	{
		CString sql="SELECT * FROM Login WHERE Uname='"+m_Uname+"' and Upasswd='"+m_Upasswd+"'";
		try
		{			
			m_pRs.CreateInstance("ADODB.Recordset");
			m_pRs->Open((_variant_t)sql,theApp.m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			if(m_pRs->adoEOF)
			{
				AfxMessageBox("�û������������!");	
				m_Uname="";
				m_Upasswd="";
				i++;
				UpdateData(false);
				if(i==3)
				{
					OnCancel();		
				}
				
			}
			else
			{
				theApp.name=m_Uname;
				theApp.pwd=m_Upasswd;
				CDialog::OnOK();
				return;
			}
		}
		catch(_com_error e)
		{
			CString temp;
			temp.Format("�������ݿ������Ϣ:%s",e.ErrorMessage());
			AfxMessageBox(temp);
			return;				
		}
	}
	else
	{
		AfxMessageBox("�û������벻��Ϊ��");
	}
}


					



	


BOOL CLogindlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_login)),TRUE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogindlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
