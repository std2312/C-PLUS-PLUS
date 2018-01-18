// ApplyEmployeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ApplyEmployeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApplyEmployeeDlg dialog


CApplyEmployeeDlg::CApplyEmployeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CApplyEmployeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CApplyEmployeeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CApplyEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CApplyEmployeeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CApplyEmployeeDlg, CDialog)
	//{{AFX_MSG_MAP(CApplyEmployeeDlg)
	ON_CBN_SELCHANGE(IDC_COMBO5, OnSelchangeCombo5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApplyEmployeeDlg message handlers

BOOL CApplyEmployeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	CComboBox* pDept = (CComboBox*)GetDlgItem(IDC_COMBO5);
	CFileRecord::InitDeptComboBox(pDept);
	if(!m_ApplicationSerial.IsEmpty())
	{
		SetDlgContent(m_ApplicationSerial);
		SetModifyMode();
		return TRUE;
	}
	OnSelchangeCombo5();
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO6))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CApplyEmployeeDlg::OnSelchangeCombo5() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pDept = (CComboBox*)GetDlgItem(IDC_COMBO5), 
		*pDuty = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CString str;
	pDept->GetLBText(pDept->GetCurSel(), str);
	CFileRecord::ShowDutyComboBox(str, pDuty);
}

BOOL CApplyEmployeeDlg::CheckPrincipal(const CString &id)
{
	int count = 0;
	CADOOperation emp;
	BOOL ret;
	CString sql;
	if(id.IsEmpty())
		return FALSE;
	sql.Format("select count(*) from tb_employee where employee_id = '%s'", id);
	emp.OpenRecordset(sql);
	ret = emp.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	if(!ret || count <= 0)
	{
		emp.CloseRecorset();
		return FALSE;
	}
	emp.CloseRecorset();

	return TRUE;
}

void CApplyEmployeeDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString name;
	GetDlgItemText(IDC_EDIT3, name);
	if(!CheckPrincipal(name))
	{
		MessageBox("请输入一个有效的负责人！", "错误", MB_OK | MB_ICONWARNING);
		return ;
	}
	if(!m_ApplicationSerial.IsEmpty())
	{
		if(SaveModify())
		{
			MessageBox("修改成功！", "提示");
			CDialog::OnOK();
		}
		return ;
	}
	if(RequestEmployee())
	{
		if(IDYES != MessageBox("保存成功！是否继续操作？", "提示", MB_YESNO))
			CDialog::OnOK();

	}
}

BOOL CApplyEmployeeDlg::RequestEmployee()
{
	CADOOperation req;
	BOOL ret = TRUE;
	CString str;
	int number;
	SYSTEMTIME sysTime = {0};

	req.OpenTable("tb_torequest");
	req.AddNew();

	GetDlgItemText(IDC_EDIT4, str);
	req.SetItemContent("torequest_number", CADOOperation::ADO_TYPE_STRING, &str);
	GetDlgItemText(IDC_COMBO5, str);
	number = CFileRecord::GetDeptNumber(str);										//保存申请部门
	ret = req.SetItemContent("torequest_dept", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, str);
	number = CFileRecord::GetDutyNumber(str);										//保存职位需求
	ret = req.SetItemContent("torequest_duty", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO2, str);												//保存性别需求
	ret = req.SetItemContent("torequest_sex", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	number = GetDlgItemInt(IDC_EDIT13);												//年龄要求上限
	ret = req.SetItemContent("torequest_minage", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	number = GetDlgItemInt(IDC_EDIT2);												//年龄要求下限
	ret = req.SetItemContent("torequest_maxage", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO6, str);												//学历要求
	ret = req.SetItemContent("torequest_edulev", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT1, str);													//职位说明
	ret = req.SetItemContent("torequest_explain", CADOOperation::ADO_TYPE_TEXT, &str);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, str);													//负责人
	ret = req.SetItemContent("torequest_principal" ,CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);			///保存请求日期
	ret = req.SetItemContent("torequest_date", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2))->GetTime(&sysTime);			//保存有效日期
	ret = req.SetItemContent("torequest_perofval", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO3, str);												//保存状态
	ret = req.SetItemContent("torequest_state", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		req.CloseTable();
		return FALSE;
	}
	req.UpdateData();
	req.CloseTable();
	return TRUE;
}

void CApplyEmployeeDlg::SetApplicationSerial(CString &applicationSerial)
{
	m_ApplicationSerial = applicationSerial;
}

BOOL CApplyEmployeeDlg::SetDlgContent(CString &applicationSerial)
{
	CString sql, constr;
	CADOOperation ado;
	DWORD dw = -1;
	SYSTEMTIME sysTime = {0};
	CComboBox *dept = (CComboBox*)GetDlgItem(IDC_COMBO5),
		*duty = (CComboBox*)GetDlgItem(IDC_COMBO1);
	sql.Format("\
				  select tb_torequest.torequest_number, tb_dept.dept_name, tb_dept_duty.duty_name, tb_torequest.torequest_sex,\
				  tb_torequest.torequest_minage, tb_torequest.torequest_maxage, tb_torequest.torequest_edulev,\
				  tb_torequest.torequest_principal,tb_torequest.torequest_state,\
				  tb_torequest.torequest_date,tb_torequest.torequest_perofval , tb_torequest.torequest_explain\
				  from tb_torequest, tb_dept, tb_dept_duty \
				  where tb_torequest.torequest_dept = tb_dept.dept_id \
				  and tb_torequest.torequest_duty = tb_dept_duty.duty_id \
				  and tb_torequest.torequest_number = '%s'", applicationSerial);
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return FALSE;
	}
	ado.GetItemContent("torequest_principal", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT3, constr);
	ado.GetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &constr);
	dept->SetCurSel(dept->FindString(0, constr.GetBuffer(0)));
	OnSelchangeCombo5();
	ado.GetItemContent("duty_name", CADOOperation::ADO_TYPE_STRING, &constr);
	duty->SetCurSel(duty->FindString(0, constr.GetBuffer(0)));
	ado.GetItemContent("torequest_sex", CADOOperation::ADO_TYPE_STRING, &constr);
	if(0 == constr.Compare("男"))
		((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	else
		((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(1);
	ado.GetItemContent("torequest_minage", CADOOperation::ADO_TYPE_INT, &dw);
	SetDlgItemInt(IDC_EDIT13, dw);
	ado.GetItemContent("torequest_maxage", CADOOperation::ADO_TYPE_INT, &dw);
	SetDlgItemInt(IDC_EDIT2, dw);
	ado.GetItemContent("torequest_edulev", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_COMBO6, constr);
	ado.GetItemContent("torequest_state", CADOOperation::ADO_TYPE_STRING, &constr);
	constr.Replace(" ", "");
	CComboBox * state = (CComboBox*)GetDlgItem(IDC_COMBO3);
	int i = state->FindString(0, constr.GetBuffer(0));
	state->SetCurSel(i);
	ado.GetItemContent("torequest_date", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);
	ado.GetItemContent("torequest_perofval", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2))->SetTime(&sysTime);
	ado.GetItemContent("torequest_explain", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT1, constr);
	


	ado.CloseRecorset();
	return TRUE;
}

BOOL CApplyEmployeeDlg::SetModifyMode()
{

	SetWindowText("申请用人信息修改");
	SetDlgItemText(IDC_EDIT4, m_ApplicationSerial);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	SetDlgItemText(IDOK, "修改");
	return TRUE;
}

BOOL CApplyEmployeeDlg::SaveModify()
{
	CString sql, constr;
	CADOOperation ado;
	DWORD deptSerial, dutySerial;
	int age;
	SYSTEMTIME sysTime = {0};
	sql.Format("select * from tb_torequest where tb_torequest.torequest_number = '%s'", m_ApplicationSerial);
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, constr);
	ado.SetItemContent("torequest_principal", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_COMBO5, constr);
	deptSerial = CFileRecord::GetDeptNumber(constr);
	GetDlgItemText(IDC_COMBO1, constr);
	dutySerial = CFileRecord::GetDutyNumber(constr);
	ado.SetItemContent("torequest_dept", CADOOperation::ADO_TYPE_INT, &deptSerial);
	ado.SetItemContent("torequest_duty", CADOOperation::ADO_TYPE_INT, &dutySerial);
	GetDlgItemText(IDC_COMBO2, constr);
	ado.SetItemContent("torequest_sex", CADOOperation::ADO_TYPE_STRING, &constr);
	age = GetDlgItemInt(IDC_EDIT13);
	ado.SetItemContent("torequest_minage", CADOOperation::ADO_TYPE_INT, &age);
	age = GetDlgItemInt(IDC_EDIT2);
	ado.SetItemContent("torequest_maxage", CADOOperation::ADO_TYPE_INT, &age);
	GetDlgItemText(IDC_COMBO6, constr);
	ado.SetItemContent("torequest_edulev", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_COMBO3, constr);
	ado.SetItemContent("torequest_state", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT1, constr);
	ado.SetItemContent("torequest_explain", CADOOperation::ADO_TYPE_TEXT, &constr);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ado.SetItemContent("torequest_date", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2))->SetTime(&sysTime);
	ado.SetItemContent("torequest_perofval", CADOOperation::ADO_TYPE_DATE, &sysTime);
	ado.UpdateData();
	ado.CloseRecorset();
	return TRUE;
}
