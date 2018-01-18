// LoadInTempDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LoadInTempDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoadInTempDlg dialog


CLoadInTempDlg::CLoadInTempDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadInTempDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoadInTempDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoadInTempDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoadInTempDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoadInTempDlg, CDialog)
	//{{AFX_MSG_MAP(CLoadInTempDlg)
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoadInTempDlg message handlers

BOOL CLoadInTempDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox* pCom = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCom->SetWindowText(m_TmpType);

	CADOOperation barType;
	CString str;
	barType.OpenRecordset("select distinct template_type from tb_bargain_template");
	if(barType.IsLastRow())
	{
		barType.CloseRecorset();
		return TRUE;
	}
	barType.MoveFirst();
	do
	{
		barType.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
		pCom->AddString(str);
		barType.MoveNext();
	}
	while(!barType.IsLastRow());
	barType.CloseRecorset();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoadInTempDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CLoadInTempDlg::SetTemplateType(CString type)
{

	m_TmpType = type;
}

CString CLoadInTempDlg::GetTemplateType()
{
	return m_TmpType;
}

CString CLoadInTempDlg::GetTemplateName()
{
	return m_TmpName;
}

void CLoadInTempDlg::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItemText(IDC_COMBO1, m_TmpType);
	GetDlgItemText(IDC_EDIT1, m_TmpName);
	CDialog::OnOK();
}
