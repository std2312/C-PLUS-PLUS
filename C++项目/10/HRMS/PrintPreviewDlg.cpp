// PrintPreviewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "PrintPreviewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintPreviewDlg dialog


CPrintPreviewDlg::CPrintPreviewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintPreviewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintPreviewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPrintPreviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintPreviewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintPreviewDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintPreviewDlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintPreviewDlg message handlers

void CPrintPreviewDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	ShowListView(&dc);
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CPrintPreviewDlg::ShowListView(CDC *dc)
{
	CADOOperation ado;
	CPrintView view(dc);
	
	view.InsertColumn("年份", 40);
	view.InsertColumn("月份", 30);
	view.InsertColumn("员工姓名", 75);
	view.InsertColumn("部门", 55);
	view.InsertColumn("职务", 55);
	view.InsertColumn("基本工资", 70);
	view.InsertColumn("职务工资", 65);
	view.InsertColumn("工龄工资", 65);
	view.InsertColumn("奖金", 45);
	view.InsertColumn("养老保险", 65);
	view.InsertColumn("缺勤扣除", 65);
	view.InsertColumn("共计", -1);

	view.SetTableHeader((CString)"员工月工资工资表");
	view.SetRowHigth(20);
	RECT rc = {0};
	GetClientRect(&rc);
	view.SetBountsRect(&rc);
	view.ShowColumn();

	CADOOperation paylist;
	CString fields[] = {"year", "month", "name", "dept", "duty", "laborage", 
		"duty_laborage", "leser_laborage", "bonus", "insurance","deduct"};
	CString sql;
	sql.Format("\
							 select tb_paylist.pay_dateyear as year, tb_paylist.pay_datemonth as month,\
							 tb_employee.employee_name as name, tb_dept.dept_name as dept, \
							 tb_dept_duty.duty_name as duty, \
							 tb_paylist.pay_laborage as laborage, tb_paylist.duty_laborage, \
							 tb_paylist.leser_laborage, tb_paylist.insurance, \
							 tb_paylist.pay_bonus as bonus, tb_paylist.pay_deduct as deduct\
							 from tb_paylist, tb_employee, tb_dept_duty,tb_dept\
							 where tb_paylist.employee_id = tb_employee.employee_id\
							 and tb_employee.employee_dept = tb_dept.dept_id\
							 and tb_employee.employee_duty = tb_dept_duty.duty_id");
	paylist.OpenRecordset(sql);
	PRINTRESULT(sql);

	paylist.ShowADOView(fields, 11, &view);
	paylist.CloseRecorset();
	return TRUE;
}

HBRUSH CPrintPreviewDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	RECT rc;
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	GetClientRect(&rc);
	pDC->FillRect(&rc, &brush);
	// TODO: Return a different brush if the default is not desired
	return brush;
}
