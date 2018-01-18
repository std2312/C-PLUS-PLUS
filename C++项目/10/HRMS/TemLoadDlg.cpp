// TemLoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "TemLoadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemLoadDlg dialog


CTemLoadDlg::CTemLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTemLoadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTemLoadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTemLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTemLoadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTemLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CTemLoadDlg)
	ON_WM_CANCELMODE()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemLoadDlg message handlers

BOOL CTemLoadDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CADOOperation barType;
	CComboBox* pCom = (CComboBox*)GetDlgItem(IDC_COMBO1);
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

	pCom->SetCurSel(0);
	OnSelchangeCombo1();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTemLoadDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CTemLoadDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pName = (CComboBox*)GetDlgItem(IDC_COMBO2);
	CString type, sql, str;
	CADOOperation tem;
	pName->ResetContent();
	GetDlgItemText(IDC_COMBO1, type);
	sql.Format("select template_name from tb_bargain_template where template_type = '%s'", type);
	tem.OpenRecordset(sql);
	if(tem.IsLastRow())
	{
		tem.CloseRecorset();
		return ;
	}
	tem.MoveFirst();
	do
	{
		tem.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
		pName->AddString(str);
		tem.MoveNext();
	}while(!tem.IsLastRow());
	tem.CloseRecorset();
	pName->SetCurSel(0);
}

CString CTemLoadDlg::GetTemplateName()
{
	return m_TemName;
}

CString CTemLoadDlg::GetTemplateType()
{
	return m_TemType;
}

void CTemLoadDlg::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItemText(IDC_COMBO1, m_TemType);
	GetDlgItemText(IDC_COMBO2, m_TemName);
	CDialog::OnOK();
}
