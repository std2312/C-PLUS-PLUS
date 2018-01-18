// AssessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "AssessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssessDlg dialog


CAssessDlg::CAssessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAssessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAssessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssessDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssessDlg, CDialog)
	//{{AFX_MSG_MAP(CAssessDlg)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssessDlg message handlers

BOOL CAssessDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox* pDept = (CComboBox* )GetDlgItem(IDC_COMBO2), 
		*pEmployee = (CComboBox*)GetDlgItem(IDC_COMBO4);
	CTimeCardDlg::InitEmployeeList(pEmployee);
	CFileRecord::InitDeptComboBox(pDept);
	OnSelchangeCombo2();
	((CComboBox*)GetDlgItem(IDC_COMBO5))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO6))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAssessDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pDept = (CComboBox*)GetDlgItem(IDC_COMBO2), 
		*pDuty = (CComboBox*)GetDlgItem(IDC_COMBO3);
	CString str;
	pDept->GetLBText(pDept->GetCurSel(), str);
	CFileRecord::ShowDutyComboBox(str, pDuty);
}

void CAssessDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString name, dept, duty;
	GetDlgItemText(IDC_COMBO4, name);
	GetDlgItemText(IDC_COMBO2, dept);
	GetDlgItemText(IDC_COMBO3, duty);
	if(!CUserRegDlg::CheckUser(name, dept, duty))
	{
		MessageBox("请输入正确的信息！");
		return ;
	}
	if(SaveAssess())
	{
		if(IDYES != MessageBox("保存成功！是否继续操作？", "提示", MB_YESNO))
			CDialog::OnOK();
	}
	CComboBox* pCom = (CComboBox*)GetDlgItem(IDC_COMBO4);
	pCom->SetFocus();
	pCom->SetEditSel(0, -1);
}

BOOL CAssessDlg::SaveAssess()
{
	CString name, id;
	float f;
	CADOOperation assess;
	BOOL ret = TRUE;
	int year, month;

	GetDlgItemText(IDC_COMBO4, name);
	id = CTimeCardDlg::GetEmployIDByName(name);
	assess.OpenTable("tb_assess");
	assess.AddNew();
	year = GetDlgItemInt(IDC_COMBO5);
	month = GetDlgItemInt(IDC_COMBO6);
	ret = assess.SetItemContent("assess_dateyear", CADOOperation::ADO_TYPE_INT, &year);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	ret = assess.SetItemContent("assess_datemonth", CADOOperation::ADO_TYPE_INT, &month);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	ret = assess.SetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &id);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT1);
	ret = assess.SetItemContent("assess_mannerofwork", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT2);
	assess.SetItemContent("assess_efficiency", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT10);
	ret = assess.SetItemContent("assess_ability", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		assess.CloseTable();
		return FALSE;
	}
	assess.UpdateData();
	assess.CloseTable();

	return TRUE;
}

double CAssessDlg::GetDlgItemFloat(UINT id)
{
	CString str;
	GetDlgItemText(id, str);

	return atof(str);
}
