// FindEmployeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "FindEmployeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindEmployeeDlg dialog


CFindEmployeeDlg::CFindEmployeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindEmployeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindEmployeeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFindEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindEmployeeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFindEmployeeDlg, CDialog)
	//{{AFX_MSG_MAP(CFindEmployeeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindEmployeeDlg message handlers

BOOL CFindEmployeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CFindEmployeeDlg::OnOK() 
{
	// TODO: Add extra validation here
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	CString sql, buf;
	GetDlgItemText(IDC_EDIT1, buf);
	CADOOperation employee;

	switch(index)
	{
	case 0:
	sql.Format("\
				  select tb_employee.employee_id as id, tb_employee.employee_name as name,\
				  tb_employee.employee_sex as sex,\
				  tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
				  tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept ,\
				  tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
				  tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
				  from tb_employee, tb_dept, tb_dept_duty\
				  where tb_employee.employee_dept = tb_dept.dept_id \
				  and tb_employee.employee_duty = tb_dept_duty.duty_id and employee_id = '%s' ", buf);
		break;
	case 1:
	sql.Format("\
				  select tb_employee.employee_id as id, tb_employee.employee_name as name,\
				  tb_employee.employee_sex as sex,\
				  tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
				  tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept ,\
				  tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
				  tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
				  from tb_employee, tb_dept, tb_dept_duty\
				  where tb_employee.employee_dept = tb_dept.dept_id \
				  and tb_employee.employee_duty = tb_dept_duty.duty_id and employee_name = '%s'", buf);
		break;
	case 2:
	sql.Format("\
				  select tb_employee.employee_id as id, tb_employee.employee_name as name,\
				  tb_employee.employee_sex as sex,\
				  tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
				  tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept ,\
				  tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
				  tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
				  from tb_employee, tb_dept, tb_dept_duty\
				  where tb_employee.employee_dept = tb_dept.dept_id \
				  and tb_employee.employee_duty = tb_dept_duty.duty_id and employee_sex = '%s'", buf);
		break;
	case 3:
		{
			DWORD num = 0;
			num = CFileRecord::GetDeptNumber(buf);
			sql.Format("\
						  select tb_employee.employee_id as id, tb_employee.employee_name as name,\
						  tb_employee.employee_sex as sex,\
						  tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
						  tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept ,\
						  tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
						  tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
						  from tb_employee, tb_dept, tb_dept_duty\
						  where tb_employee.employee_dept = tb_dept.dept_id \
						  and tb_employee.employee_duty = tb_dept_duty.duty_id and employee_dept = '%d'", num);
		}
		break;
	case 4:
		sql.Format("\
					  select tb_employee.employee_id as id, tb_employee.employee_name as name,\
					  tb_employee.employee_sex as sex,\
					  tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
					  tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept ,\
					  tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
					  tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
					  from tb_employee, tb_dept, tb_dept_duty\
					  where tb_employee.employee_dept = tb_dept.dept_id \
					  and tb_employee.employee_duty = tb_dept_duty.duty_id and employee_edulev = '%s'", buf);
		break;
	default:
		return ;
	}
	CString fields[] = {"id", "name", "sex", "birthday", 
		"edulev", "lenofser", "dept", "duty", "timeofser", "phone", "address"};
	employee.OpenRecordset(sql);
	employee.ShowADOView(fields, 11, (CADOView*)((CFileInfo*)GetParent()));
	employee.CloseRecorset();

	CDialog::OnOK();
}
