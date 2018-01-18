// ApplerSearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ApplerSearchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApplerSearchDlg dialog


CApplerSearchDlg::CApplerSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CApplerSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CApplerSearchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CApplerSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CApplerSearchDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CApplerSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CApplerSearchDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApplerSearchDlg message handlers

BOOL CApplerSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CApplerSearchDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString field, optor, condition;
	int fieldSerial = -1;

	fieldSerial = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	switch(fieldSerial)
	{
	case 0:		field = "tb_applicant.applicant_id";			break;
	case 1:		field = "tb_applicant.applicant_name";			break;
	case 2:		field = "tb_applicant.applicant_sex";			break;
	case 3:		field = "tb_applicant.applicant_nativeplace";	break;
	case 4:		field = "tb_applicant.applicant_address";		break;
	case 5:		field = "tb_applicant.applicant_eduoflev";		break;
	case 6:		field = "tb_applicant.applicant_specialty";	break;
	case 7:		field = "tb_applicant.applicant_birthday";		break;
	case 8:		field = "tb_applicant.applicant_duty";			break;
	case 9:		field = "tb_applicant.applicant_duty";			break;
	default:	CDialog::OnOK();					return;
	}
	GetDlgItemText(IDC_COMBO2, optor);
	GetDlgItemText(IDC_EDIT1, condition);
	switch(fieldSerial)
	{
	case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:
		m_SearchExpression.Format("%s %s '%s'", field, optor, condition);
		break;
	case 8:
		{
			DWORD deptSerail;
			deptSerail = CFileRecord::GetDeptNumber(condition);
			if(deptSerail < 1)
			{
				MessageBox("公司没目前有该部门！", "提示", MB_OK | MB_ICONWARNING);
				return ;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, deptSerail);
		}
		break;
	case 9:
		{
			DWORD dutySerail;
			dutySerail = CFileRecord::GetDutyNumber(condition);
			if(dutySerail < 1)
			{
				MessageBox("公司目前没有该职务！", "提示", MB_OK | MB_ICONWARNING);
				return ;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, dutySerail);
		}
		break;
	}
	CDialog::OnOK();
}

CString CApplerSearchDlg::GetSearchCondition()
{
	return m_SearchExpression;
}

void CApplerSearchDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CEdit *condition = (CEdit*)GetDlgItem(IDC_EDIT1);
	CComboBox * field = (CComboBox*)GetDlgItem(IDC_COMBO1);
	if(7 == field->GetCurSel())
	{
		condition->SetWindowText("日期格式：yy-mm-dd");
		condition->SetFocus();
		condition->SetSel(0, -1);
	}
}
