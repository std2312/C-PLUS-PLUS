// PayClipDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "PayClipDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPayClipDlg dialog


CPayClipDlg::CPayClipDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPayClipDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPayClipDlg)
	//}}AFX_DATA_INIT
	m_Editable = TRUE;
}


void CPayClipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPayClipDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPayClipDlg, CDialog)
	//{{AFX_MSG_MAP(CPayClipDlg)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_EN_SETFOCUS(IDC_EDIT2, OnSetfocusEdit2)
	ON_CBN_KILLFOCUS(IDC_COMBO3, OnKillfocusCombo3)
	ON_CBN_KILLFOCUS(IDC_COMBO4, OnKillfocusCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPayClipDlg message handlers

void CPayClipDlg::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateContent();

	*pResult = 0;
}

void CPayClipDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(!m_Editable)
	{
		if(SaveModify())
			MessageBox("修改成功！");
		CDialog::OnOK();
		return ;
	}
	if(SavePaySlip())
	{
		CDialog::OnOK();
		MessageBox("保存成功！", "提示", MB_OK);
	}
}

BOOL CPayClipDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox *pCom = (CComboBox*)GetDlgItem(IDC_COMBO2);
	CTimeCardDlg::InitEmployeeList(pCom);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO4))->SetCurSel(0);
	if(!m_Editable)
	{
		SetDlgContent();
		InitModifyDlg();
	}



	UpdateContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

DWORD CPayClipDlg::GetRecentLateCount(const CString &name, int year, int month)
{
	ASSERT(!name.IsEmpty());

	DWORD count = 0;
	CADOOperation late;
	CString sql;

	sql.Format("select (\
						  select count(*)\
						  from tb_employee, tb_timecard\
						  where tb_employee.employee_name = '%s'\
						  and tb_timecard.timecart_late_leave_early & 2 > 0\
						  and year(tb_timecard.timecart_date) = %d\
						  and month(tb_timecard.timecart_date) = %d\
						  and tb_employee.employee_id = tb_timecard.employee_id) + \
						  (select count(*)\
						  from tb_employee, tb_timecard\
						  where tb_employee.employee_name = '%s'\
						  and tb_timecard.timecart_late_leave_early & 1 > 0\
						  and year(tb_timecard.timecart_date) = %d\
						  and month(tb_timecard.timecart_date) = %d\
						  and tb_employee.employee_id = tb_timecard.employee_id)",
						  name, year, month , name, year, month);
	late.OpenRecordset(sql);
	late.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	late.CloseRecorset();

	return count;
}

DWORD CPayClipDlg::GetSickLeaveCount(const CString &name, int year, int month)
{
	DWORD count = 0;
	CADOOperation sick;
	CString sql;

	sql.Format("select count(*)\
								 from tb_employee, tb_timecard\
								 where tb_employee.employee_name = '%s'\
								 and year(tb_timecard.timecart_date) = %d\
								 and month(tb_timecard.timecart_date) = %d\
								 and tb_timecard.timecart_reason = 3\
								 and tb_employee.employee_id = tb_timecard.employee_id", name, year, month);
	sick.OpenRecordset(sql);
	sick.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	sick.CloseRecorset();

	return count;
}

BOOL CPayClipDlg::UpdateContent()
{
	DWORD count = 0;
	CComboBox *pComName = (CComboBox*)GetDlgItem(IDC_COMBO2), 
		*pComYear = (CComboBox*)GetDlgItem(IDC_COMBO3), 
		*pComMonth = (CComboBox*)GetDlgItem(IDC_COMBO4);
	CString name, str;
	float leave;
	int year, month;

	pComName->GetLBText(pComName->GetCurSel(), name);
	pComYear->GetLBText(pComYear->GetCurSel(), str);
	year = atoi(str);
	pComMonth->GetLBText(pComMonth->GetCurSel(), str);
	month = atoi(str);
	count = GetHolidays(name, year, month);
	SetDlgItemInt(IDC_EDIT7, count);
	count = 0;
	count = GetSickLeaveCount(name, year, month);
	SetDlgItemInt(IDC_EDIT5, count);
	count = 0;
	count = GetAffairLeave(name, year, month);
	SetDlgItemInt(IDC_EDIT3, count);
	count = 0;
	count = GetRecentLateCount(name, year, month);
	SetDlgItemInt(IDC_EDIT9, count);
	leave = GetLaveHours(name, year, month);
	str.Format("%.2f", leave);
	SetDlgItemText(IDC_EDIT8, str);

	leave *= GetRecoupSum(name);
	str.Format("%.2f", leave);
	SetDlgItemText(IDC_EDIT10, str);
	SetWageDlg(name);
	return TRUE;
}


void CPayClipDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	UpdateContent();
}

DWORD CPayClipDlg::GetHolidays(const CString &name, int year, int month)
{
	DWORD count = 0;
	CADOOperation holiday;
	CString sql;
	
	sql.Format("select count(*)\
								 from tb_employee, tb_timecard\
								 where tb_employee.employee_name = '%s'\
								 and year(tb_timecard.timecart_date) = %d\
								 and month(tb_timecard.timecart_date) = %d\
								 and tb_timecard.timecart_reason = 2\
								 and tb_employee.employee_id = tb_timecard.employee_id", name, year, month);
	holiday.OpenRecordset(sql);
	holiday.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	holiday.CloseRecorset();

	return count;
}

DWORD CPayClipDlg::GetAffairLeave(const CString &name, int year, int month)
{

	DWORD count = 0;
	CADOOperation affairLeave;
	CString sql;

	sql.Format("select count(*)\
								 from tb_employee, tb_timecard\
								 where tb_employee.employee_name = '%s'\
								 and year(tb_timecard.timecart_date) = %d\
								 and month(tb_timecard.timecart_date) = %d\
								 and tb_timecard.timecart_reason = 3\
								 and tb_employee.employee_id = tb_timecard.employee_id",
								  name, year, month);
	affairLeave.OpenRecordset(sql);
	affairLeave.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	affairLeave.CloseRecorset();

	return count;
}


float CPayClipDlg::GetLaveHours(const CString &name, int year, int month)
{
	ASSERT(month>0 && month<13);
	float hours = 0;
	LONG minutes = 0, days;
	CString sql;
	CADOOperation leave;
	
	sql.Format("select \
						 sum(timecart_worklong)\
						 from tb_employee, tb_timecard\
						 where tb_employee.employee_name = '%s'\
						 and year(tb_timecard.timecart_date) = %d\
						 and month(tb_timecard.timecart_date) = %d\
						 and tb_timecard.employee_id = tb_employee.employee_id",
						 name, year, month);
	leave.OpenRecordset(sql);
	leave.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &minutes);
	leave.CloseRecorset();
	hours = (float)minutes/(float)60;
	switch(month)
	{
	case 1:	case 3:case 5:case 7:
	case 8:case 10:case 12:
		days = 31;
		break;
	case 2:
		days = 29;
		break;
	case 4: case 6:case 9:case 11:
		days = 30;
		break;
	}
	hours = days*8 - hours;

	return hours;
}

float CPayClipDlg::DeductFunds(float hours, float per)
{
	return hours*per;
}

BOOL CPayClipDlg::GetLastDate(SYSTEMTIME *sysTime)
{
	CADOOperation pay;
	BOOL ret = TRUE;

	pay.OpenRecordset("select max(pay_endtime) from tb_paylist");
	ret = pay.GetItemContent(0, CADOOperation::ADO_TYPE_DATE, &sysTime);
	pay.CloseRecorset();

	return ret;
}

void CPayClipDlg::OnSetfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	char buf[40] = {0};
	double total = 0.0f;
	GetDlgItemText(IDC_EDIT12, buf, 40);
	total += atof(buf);
	memset(buf, 0, 40);
	GetDlgItemText(IDC_EDIT11, buf, 40);
	total += atof(buf);
	GetDlgItemText(IDC_EDIT10, buf, 40);
	total -= atof(buf);
	GetDlgItemText(IDC_EDIT13, buf, 40);
	total += atof(buf);

	GetDlgItemText(IDC_EDIT14, buf, 40);
	total += atof(buf);
	GetDlgItemText(IDC_EDIT15, buf, 40);
	total += atof(buf);
	sprintf(buf, "%.2f", total);

	SetDlgItemText(IDC_EDIT2, buf);

}

BOOL CPayClipDlg::SavePaySlip()
{

	float f;
	CString name, id;
	CADOOperation pay;
	BOOL ret = TRUE;
	int year, month;

	pay.OpenTable("tb_paylist");
	pay.AddNew();

	GetDlgItemText(IDC_COMBO2, name);
	id = CTimeCardDlg::GetEmployIDByName(name);
	ret = pay.SetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &id);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT12);
	ret = pay.SetItemContent("pay_laborage", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT10);
	ret = pay.SetItemContent("pay_deduct", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT11);
	ret = pay.SetItemContent("pay_bonus", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}

	CComboBox* pComYear = (CComboBox*)GetDlgItem(IDC_COMBO3),
		*pComMonth = (CComboBox*)GetDlgItem(IDC_COMBO4);
	CString str;
	pComMonth->GetLBText(pComMonth->GetCurSel(), str);
	month = atoi(str);
	pComYear->GetLBText(pComYear->GetCurSel(), str);
	year = atoi(str);
	ret = pay.SetItemContent("pay_datemonth",CADOOperation::ADO_TYPE_INT, &month);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	ret = pay.SetItemContent("pay_dateyear", CADOOperation::ADO_TYPE_INT, &year);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT13);
	ret = pay.SetItemContent("duty_laborage", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}

	f = (float)GetDlgItemFloat(IDC_EDIT14);
	ret = pay.SetItemContent("leser_laborage", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	f = (float)GetDlgItemFloat(IDC_EDIT15);
	ret = pay.SetItemContent("insurance", CADOOperation::ADO_TYPE_FLOAT, &f);
	if(!ret)
	{
		pay.CloseTable();
		return FALSE;
	}
	pay.UpdateData();
	pay.CloseTable();

	return TRUE;
}

double CPayClipDlg::GetDlgItemFloat(UINT id)
{
	CString str;
	GetDlgItemText(id,str);
	
	return atoi(str.GetBuffer(0));
}


//年
void CPayClipDlg::OnKillfocusCombo3() 
{
	// TODO: Add your control notification handler code here
	UpdateContent();
}

//月
void CPayClipDlg::OnKillfocusCombo4() 
{
	// TODO: Add your control notification handler code here
	UpdateContent();
}


//年
void CPayClipDlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	UpdateContent();
}

//月
void CPayClipDlg::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	UpdateContent();
}

void CPayClipDlg::SetDlgInfo(CString &name, int year, int month, 
							 float laborage, float bonus)
{
	m_Name = name;
	m_year = year;
	m_Month = month;
	m_Laborage = laborage;
	m_Bonus = bonus;
}

BOOL CPayClipDlg::SetDlgContent()
{
	CString str;
	SetDlgItemText(IDC_COMBO2, m_Name.GetBuffer(0));
	SetDlgItemInt(IDC_COMBO3, m_year);
	((CComboBox*)GetDlgItem(IDC_COMBO4))->SetCurSel(m_Month -1);
	str.Format("%.2f", m_Laborage);
	SetDlgItemText(IDC_EDIT12, str);
	str.Format("%.2f", m_Bonus);
	SetDlgItemText(IDC_EDIT11, str);
	UpdateContent();

	OnSetfocusEdit2();
	return TRUE;
}

BOOL CPayClipDlg::SaveModify()
{
	
	CString sql, str;
	CADOOperation ado;
	float bonus, laborage, duty_laborage, leser_laborage, insurance;
	BOOL ret;
	GetDlgItemText(IDC_EDIT12, str);
	laborage = (float)atof(str);
	GetDlgItemText(IDC_EDIT11, str);
	bonus = (float)atof(str);
	GetDlgItemText(IDC_EDIT13, str);
	duty_laborage = (float)atof(str);
	GetDlgItemText(IDC_EDIT14, str);
	leser_laborage = (float)atof(str);
	GetDlgItemText(IDC_EDIT15, str);
	insurance = (float)atof(str);

	sql.Format("\
				  update tb_paylist \
				  set pay_bonus = %f, pay_laborage = %f, duty_laborage = %f, leser_laborage = %f, insurance = %f\
				  where tb_paylist.employee_id in \
				  (select employee_id from tb_employee where employee_name = '%s')\
				  and pay_datemonth = %d\
				  and pay_dateyear = %d", bonus, laborage,
				  duty_laborage, leser_laborage, insurance, m_Name, m_Month, m_year);
	ret = ado.OpenRecordset(sql);
	ado.CloseRecorset();
	return ret;
}

void CPayClipDlg::InitModifyDlg()
{

	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO4)->EnableWindow(FALSE);
	SetWindowText("修改工资单");
	GetDlgItem(IDOK)->SetWindowText("修改");
}

void CPayClipDlg::SetEditable(BOOL is)
{
	m_Editable = is;
}

BOOL CPayClipDlg::SetWageDlg(CString &name)
{
	BOOL ret = FALSE;
	CString sql;
	CADOOperation ado;
	CString str;
	sql.Format("select tb_laborage.base_laborage, tb_laborage.duty_laborage, \
tb_laborage.leser_laborage, tb_laborage.insurance, tb_laborage.recoup from tb_laborage,tb_employee \
where tb_laborage.employee_id = tb_employee.employee_id and tb_employee.employee_name ='%s' ", name);
	ado.OpenRecordset(sql);
	ret = ado.GetItemContent("base_laborage", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
		goto end;
	SetDlgItemText(IDC_EDIT12, str);
	ret = ado.GetItemContent("duty_laborage", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
		goto end;
	SetDlgItemText(IDC_EDIT13, str);
	ret = ado.GetItemContent("leser_laborage", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
		goto end;
	SetDlgItemText(IDC_EDIT14, str);

	ret = ado.GetItemContent("insurance", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
		goto end;
	SetDlgItemText(IDC_EDIT15, str);

end:
	ado.CloseRecorset();
	return ret;
}

void CPayClipDlg::SetDlgItemFloat(UINT id, float f)
{
	CString s;
	s.Format("%.2f", f);
	SetDlgItemText(id, s);
}

float CPayClipDlg::GetRecoupSum(CString &name)
{
	float f = 0;
	BOOL ret = FALSE;
	CString sql;
	CADOOperation ado;
	CString str;
	sql.Format("select tb_laborage.base_laborage, tb_laborage.duty_laborage, \
tb_laborage.leser_laborage, tb_laborage.insurance, tb_laborage.recoup from tb_laborage,tb_employee \
where tb_laborage.employee_id = tb_employee.employee_id and tb_employee.employee_name ='%s' ", name);
	ado.OpenRecordset(sql);
	ret = ado.GetItemContent("recoup", CADOOperation::ADO_TYPE_STRING, &str);
	ado.CloseRecorset();
	return (float)atof(str);
}
