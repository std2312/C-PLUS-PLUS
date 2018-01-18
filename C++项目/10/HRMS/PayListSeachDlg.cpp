// PayListSeachDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "PayListSeachDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPayListSeachDlg dialog


CPayListSeachDlg::CPayListSeachDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPayListSeachDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPayListSeachDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPayListSeachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPayListSeachDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPayListSeachDlg, CDialog)
	//{{AFX_MSG_MAP(CPayListSeachDlg)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPayListSeachDlg message handlers

BOOL CPayListSeachDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPayListSeachDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CComboBox *com = (CComboBox*)GetDlgItem(IDC_COMBO2);
	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	int curSel = com->GetCurSel();
	if(curSel == 1)
	{
		edit->SetWindowText("日期格式：yy-mm");
		edit->SetFocus();
		edit->SetSel(0, -1);
	}
}

CString CPayListSeachDlg::GetSeachExpression()
{
	return m_SearchExpression;
}

void CPayListSeachDlg::OnOK() 
{
	// TODO: Add extra validation here
	CComboBox* fieldCom = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int curSel = -1;
	CString field, optor, con;

	curSel = fieldCom->GetCurSel();
	GetDlgItemText(IDC_COMBO1, optor);
	GetDlgItemText(IDC_EDIT1, con);
	optor.Replace(" ", "");
	switch(curSel)
	{
	case 1:
		{
			WORD y = 0, m = 0;
			DWORD date;
			date = CAssessSearchDlg::AnalyzeDate(con);
			if(date)
			{
				y = LOWORD(date);
				m = HIWORD(date);
				m_SearchExpression.Format("\
					tb_paylist.pay_dateyear = %d and tb_paylist.pay_datemonth = %d", y, m);
			}
		}
		break;
	case 0:		field = "tb_employee.employee_name"; break;
	case 2:		field = "tb_employee.employee_dept";	break;
	case 3:		field = "tb_employee.employee_duty";	break;
	default:	MessageBox("选择出错！", "提示");	return;
	}
	switch(curSel)
	{
	case 0:
		m_SearchExpression.Format("%s %s '%s'", field, optor, con);
		break;
	case 1:
		break;
	case 2:
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
	case 3:
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
