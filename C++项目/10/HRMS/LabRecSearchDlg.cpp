// LabRecSearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LabRecSearchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabRecSearchDlg dialog


CLabRecSearchDlg::CLabRecSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabRecSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLabRecSearchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLabRecSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLabRecSearchDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLabRecSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CLabRecSearchDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabRecSearchDlg message handlers

BOOL CLabRecSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLabRecSearchDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString fiel, optr, expr;
	int curSel;
	curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	GetDlgItemText(IDC_COMBO2, optr);
	GetDlgItemText(IDC_EDIT1, expr);
	if(expr.IsEmpty())
	{
		MessageBox("请输入一个合法的表达式！", "提示");
		return ;
	}
	switch(curSel)
	{
	case 0:		fiel = "tb_laborage.employee_id";		break;
	case 1:		fiel = "tb_employee.employee_name";		break;
	case 2:		fiel = "tb_dept.dept_name";				break;
	case 3:		fiel = "tb_dept_duty.duty_name";		break;

	case 4:		fiel = "tb_laborage.base_laborage";		break;
	case 5:		fiel = "tb_laborage.duty_laborage";		break;
	case 6:		fiel = "tb_laborage.leser_laborage";	break;
	case 7:		fiel = "tb_laborage.insurance";			break;
	case 8:		fiel = "tb_laborage.recoup";			break;
	default:
		return ;
	}
	if(curSel < 4)
		m_SearchExpression.Format("%s %s '%s'", fiel, optr, expr);
	else if(curSel > 3)
		m_SearchExpression.Format("%s %s %s", fiel, optr, expr);
	CDialog::OnOK();
}

CString CLabRecSearchDlg::GetSearchExpression()
{
	return m_SearchExpression;
}