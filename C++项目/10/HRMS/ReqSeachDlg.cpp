// ReqSeachDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ReqSeachDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReqSeachDlg dialog


CReqSeachDlg::CReqSeachDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReqSeachDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReqSeachDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReqSeachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReqSeachDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReqSeachDlg, CDialog)
	//{{AFX_MSG_MAP(CReqSeachDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReqSeachDlg message handlers

BOOL CReqSeachDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CString CReqSeachDlg::GetSearchExpression()
{
	return m_SearchExpression;
}

void CReqSeachDlg::OnOK() 
{
	// TODO: Add extra validation here
	int curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	CString field, optor, expr;

	GetDlgItemText(IDC_COMBO2, optor);
	GetDlgItemText(IDC_EDIT1, expr);
	switch(curSel)
	{
	case 0:
		field = "tb_applicant.applicant_name";
		break;
	case 1:
		field = "tb_req_chk.chk_num";
		break;
	case 2:
		field = "tb_req_chk.chk_sjt";
		break;
	case 3:
		field = "tb_req_chk.chk_stl";
		break;
	default:
		return ;
	}
	m_SearchExpression.Format("%s %s '%s'", field, optor, expr);
	CDialog::OnOK();
}
