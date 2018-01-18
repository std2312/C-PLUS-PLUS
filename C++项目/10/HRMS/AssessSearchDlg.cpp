// AssessSearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "AssessSearchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssessSearchDlg dialog

CAssessSearchDlg::CAssessSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAssessSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssessSearchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CAssessSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssessSearchDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAssessSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CAssessSearchDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssessSearchDlg message handlers

void CAssessSearchDlg::OnOK() 
{
	// TODO: Add extra validation here
	CComboBox* fieldCom = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int curSel = -1;
	CString field, optor, con;

	curSel = fieldCom->GetCurSel();
	GetDlgItemText(IDC_COMBO2, optor);
	GetDlgItemText(IDC_EDIT2, con);
	optor.Replace(" ", "");
	switch(curSel)
	{
	case 0:
		field = "tb_assess.employee_id";
		break;
	case 1:
		{
			WORD y = 0, m = 0;
			DWORD date;
			date = AnalyzeDate(con);
			if(date)
			{
				y = LOWORD(date);
				m = HIWORD(date);
				m_SearchExpression.Format("\
					tb_assess.assess_dateyear = %d and tb_assess.assess_datemonth = %d", y, m);
			}
		}
		break;
	case 2:		field = "tb_employee.employee_name"; break;
	case 3:		field = "tb_employee.employee_dept";	break;
	case 4:		field = "tb_employee.employee_duty";	break;
	default:	MessageBox("选择出错！", "提示");	return;
	}
	switch(curSel)
	{
	case 0:	case 2:
		m_SearchExpression.Format("%s %s '%s'", field, optor, con);
		break;
	case 1:
		break;
	case 3:
		{
			DWORD deptSerial = CFileRecord::GetDeptNumber(con);
			if(deptSerial <= 0)
			{
				MessageBox("请确认该部门的存在！", "提示");
				return ;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, deptSerial);
		}
		break;
	case 4:
		{
			DWORD dutySerial = CFileRecord::GetDutyNumber(con);
			if(dutySerial <= 0)
			{
				MessageBox("请先确认该职务的存在！");
				return;
			}
			m_SearchExpression.Format("%s %s %d", field, optor, dutySerial);
		}
		break;
	default:
		return ;
	}
	CDialog::OnOK();
}

BOOL CAssessSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAssessSearchDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int curSel = -1;
	CEdit *con = NULL;
	curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	con = (CEdit*)GetDlgItem(IDC_EDIT2);
	if(curSel == 1)
	{
		con->SetWindowText("日期格式：yy-mm");
		con->SetFocus();
		con->SetSel(0, -1);
		return ;
	}
	con->SetWindowText("");
	con->SetFocus();
	con->SetSel(0, -1);
}

DWORD CAssessSearchDlg::AnalyzeDate(CString &date)
{
	WORD y = 0, m = 0;
	int pos = -1;

	date.Replace(" ", "");
	pos = date.Find("-");
	y = atoi(date.Left(pos));
	m = atoi(date.Right(date.GetLength()-pos -1));
	if(m > 12 || m < 1)
	{
		::MessageBox(NULL, "非法的日期！", "错误", MB_OK);
		return 0;
	}

	return MAKELONG(y, m);
}

CString CAssessSearchDlg::GetSearchExpression()
{
	return m_SearchExpression;
}

void CAssessSearchDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetFocus();
}
