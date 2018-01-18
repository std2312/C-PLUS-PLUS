// SearchRequestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "SearchRequestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchRequestDlg dialog


CSearchRequestDlg::CSearchRequestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchRequestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchRequestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSearchRequestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchRequestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchRequestDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchRequestDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchRequestDlg message handlers

CString CSearchRequestDlg::GetSearchExpression()
{
	return m_SearchExpression;
}

BOOL CSearchRequestDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSearchRequestDlg::OnOK() 
{
	// TODO: Add extra validation here
	int curSel = -1;
	CString field, optor, condition;

	curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	switch(curSel)
	{
	case 0:		field = "tb_torequest.torequest_dept";			break;
	case 1:		field = "tb_torequest.torequest_duty";			break;
	case 2:		field = "tb_torequest.torequest_edulev";		break;
	case 3:		field = "tb_torequest.torequest_perofval";		break;
	case 4:		field = "tb_torequest.torequest_sex";			break;
	case 5:		field = "tb_torequest.torequest_state";		break;
	case 6:		field = "tb_torequest.torequest_date";			break;
	case 7:		field = "tb_torequest.torequest_principal";	break;
	default:	return ;
	}
	GetDlgItemText(IDC_COMBO2, optor);
	GetDlgItemText(IDC_EDIT1, condition);
	switch(curSel)
	{
	case 0:
		{
			DWORD deptSerial = -1;
			deptSerial = CFileRecord::GetDeptNumber(condition);
			if(deptSerial <= 0)
			{
				MessageBox("没有该部门", "提示");
				return ;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, deptSerial);
		}break;
	case 1:
		{
			DWORD dutySerial = -1;
			dutySerial = CFileRecord::GetDutyNumber(condition);
			if(dutySerial <= 0)
			{
				MessageBox("没有该职务！", "提示");
				return ;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, dutySerial);
		}break;
	case 2:case 3:case 4:case 5:case 6:case 7:
		m_SearchExpression.Format("%s %s '%s'", field, optor, condition);
		break;
	}
	CDialog::OnOK();
}

void CSearchRequestDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int curSel = -1;
	curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	switch(curSel)
	{
	case 3:
	case 6:
		{
			CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
			edit->SetFocus();
			edit->SetWindowText("日期格式：yy-mm-dd");
			edit->SetSel(0, -1);
		}
		break;
	case 0:case 1:case 2: case 5:
		SetDlgItemText(IDC_EDIT1, "");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		break;
	case 7:
		{
			CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
			edit->SetFocus();
			edit->SetWindowText("负责人的员工编号");
			edit->SetSel(0, -1);
		}
		break;
	default:	return ;
	}
}

void CSearchRequestDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->SetFocus();
}
