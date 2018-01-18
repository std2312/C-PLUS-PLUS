// PayListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "PayListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPayListDlg dialog


CPayListDlg::CPayListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPayListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPayListDlg)
	//}}AFX_DATA_INIT
	m_CurrentSel = -1;
}


void CPayListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPayListDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPayListDlg, CDialog)
	//{{AFX_MSG_MAP(CPayListDlg)
	ON_BN_CLICKED(IDC_EXPORTTOWORD, OnExporttoword)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_BN_CLICKED(IDC_PRINTMENUNU, OnPrintmenunu)
	ON_COMMAND(IDM_PRINTER, OnPrinter)
	ON_COMMAND(IDM_PREVIEW, OnPreview)
	ON_COMMAND(IDM_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPayListDlg message handlers

BOOL CPayListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );
	m_ListCtrl.InsertColumn(0, "日期/年", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(1, "日期/月", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(2, "姓名", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(3, "部门", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(4, "职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "基本工资", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(6, "职务工资", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(7, "工龄工资", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(8, "养老保险", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(9, "奖金", LVCFMT_LEFT, 50);
	m_ListCtrl.InsertColumn(10, "缺勤扣款", LVCFMT_LEFT, 70);
	m_ListCtrl.InsertColumn(11, "共计", LVCFMT_LEFT, 70);
	ShowList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPayListDlg::SetRow(int row, CString *strArray, int count)
{
	CString str;
	m_ListCtrl.InsertItem(row, strArray[0], 0);
	for(int i=1; i<count; i++)
		m_ListCtrl.SetItemText(row, i, strArray[i]);
	str.Format("%.2f", CPayListDlg::GetTotalSum(strArray[2], atoi(strArray[0]), atoi(strArray[1])));
	m_ListCtrl.SetItemText(row, i, str);
	return TRUE;
}

BOOL CPayListDlg::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

BOOL CPayListDlg::ShowList()
{

	CADOOperation paylist;
	CString fields[] = {"year", "month", "name", "dept", "duty", "laborage", 
		"duty_laborage", "leser_laborage", "insurance",  "bonus", "deduct"};
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

	paylist.ShowADOView(fields, 11, this);
	paylist.CloseRecorset();

	return TRUE;
}

void CPayListDlg::OnExporttoword() 
{
	// TODO: Add your control notification handler code here
	SYSTEMTIME sysTime;
	::GetSystemTime(&sysTime);
	CString str;
	str.Format("%d-%d-%d", sysTime.wYear, sysTime.wMonth, sysTime.wDay);
	CFileDialog file(FALSE, ".doc", str,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Word 文件(*.doc) | .doc||", NULL);
	if(IDOK != file.DoModal())
		return ;

	str = file.GetPathName();
	ExportToWord(str);
}

BOOL CPayListDlg::ExportToWord(CString &file)
{
	CADOOperation ado;
	ado.OpenRecordset("select tb_paylist.pay_dateyear as 年份, tb_paylist.pay_datemonth as 月份,\
							 tb_employee.employee_name as 姓名, tb_dept.dept_name as 部门, tb_dept_duty.duty_name as 职位, \
							 tb_paylist.pay_laborage as 基本工资, tb_paylist.duty_laborage as 职务工资, \
							 tb_paylist.leser_laborage as 工龄工资, tb_paylist.insurance as 养老保险, \
							 tb_paylist.pay_bonus as 奖金, tb_paylist.pay_deduct as 缺勤扣资\
							 from tb_paylist, tb_employee, tb_dept_duty,tb_dept\
							 where tb_paylist.employee_id = tb_employee.employee_id\
							 and tb_employee.employee_dept = tb_dept.dept_id\
							 and tb_employee.employee_duty = tb_dept_duty.duty_id");

	ado.ExportToWord(file);
	ado.CloseRecorset();
	return TRUE;
}

void CPayListDlg::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	if(m_CurrentSel < 0)
	{
		MessageBox("请选择一个要删除的项目！");
		return ;
	}
	CADOOperation ado;
	ado.OpenTable("tb_paylist");
	ado.DeleteItem(m_CurrentSel);
	ado.CloseTable();
	m_CurrentSel = -1;
	ShowList();
}


void CPayListDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)pNMHDR;
 	m_CurrentSel = pnmlv->iItem;
	if(m_CurrentSel >= 0)
	{
		CPoint pt;
		::GetCursorPos(&pt);
		this->ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
	}
	*pResult = 0;
}

BOOL CPayListDlg::SaveModification(CString &sql, long item, long subItem)
{
	CADOOperation ado;
	CString str;
	ado.OpenRecordset(sql);
	str = m_ListCtrl.GetItemText(item, subItem);
	ado.MoveTo(item);
//	ado.SetItemContent("", CADOOperation::ADO_TYPE_STRING, );
	return TRUE;
}

void CPayListDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CPayListDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	if(lpnmlv->iItem>=0)
	{
		CString name, str;
		int year, month;
		float bonus, laborage;
		name = m_ListCtrl.GetItemText(lpnmlv->iItem, 2);
		str = m_ListCtrl.GetItemText(lpnmlv->iItem, 0);
		year = atoi(str);
		str = m_ListCtrl.GetItemText(lpnmlv->iItem, 1);
		month = atoi(str);
		str = m_ListCtrl.GetItemText(lpnmlv->iItem, 5);
		laborage = (float)atof(str);
		str = m_ListCtrl.GetItemText(lpnmlv->iItem, 6);
		bonus = (float)atof(str);
		
		CPayClipDlg dlg;
		dlg.SetEditable();
		dlg.SetDlgInfo(name, year, month, laborage, bonus);
		dlg.DoModal();
		ShowList();
	}
	*pResult = 0;
}

void CPayListDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CPayListDlg::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CPayListDlg::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}

BOOL CPayListDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CPayListDlg::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CPayListSeachDlg dlg;
	CString seaExp;
	if(IDOK == dlg.DoModal())
	{
		seaExp = dlg.GetSeachExpression();
		ShowList(seaExp);
	}
}

BOOL CPayListDlg::ShowList(CString &seaExp)
{
	CADOOperation paylist;
	CString fields[] = {"year", "month", "name", "dept", "duty", "laborage", 
		"duty_laborage", "leser_laborage", "insurance",  "bonus", "deduct"};
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
				  and tb_employee.employee_duty = tb_dept_duty.duty_id and %s", seaExp);
	paylist.OpenRecordset(sql);
	PRINTRESULT(sql);
	
	paylist.ShowADOView(fields, 11, this);
	paylist.CloseRecorset();
	
	return TRUE;
}

void CPayListDlg::OnPrintmenunu() 
{
	// TODO: Add your control notification handler code here
	CRect rc;
	((CButton*)GetDlgItem(IDC_PRINTMENUNU))->GetWindowRect(rc);
	CMenu menu, *subMenu;
	menu.LoadMenu(IDR_PRINTMENU);
	subMenu = menu.GetSubMenu(0);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON , 
		rc.left, rc.bottom, this);
}

void CPayListDlg::OnPrinter() 
{
	// TODO: Add your command handler code here
 	CPrintDialog printDlg(FALSE);
 	if(IDOK == printDlg.DoModal())
 	{
 		CDC printDC;
 		printDC.Attach(printDlg.GetPrinterDC());
 		PrintList(&printDC);
 	}
}

void CPayListDlg::OnPreview() 
{
	// TODO: Add your command handler code here
	CPrintPreviewDlg dlg;
	dlg.DoModal();
}

BOOL CPayListDlg::PrintList(CDC *pDC)
{
	BOOL ret = FALSE;
	CADOOperation ado;
	CPrintView view(pDC);
	
	view.InsertColumn("年份", 40);
	view.InsertColumn("月份", 40);
	view.InsertColumn("员工姓名", 80);

	view.InsertColumn("部门", 60);
	view.InsertColumn("职务", 60);
	view.InsertColumn("基本工资", 70);

	view.InsertColumn("职务工资", 70);
	view.InsertColumn("工龄工资", 70);
	view.InsertColumn("奖金", 50);
	view.InsertColumn("养老保险", 70);
	view.InsertColumn("缺勤扣除", 50);
	view.InsertColumn("共计", -1);
	view.SetTableHeader((CString)"员工月工资工资表");
	view.SetRowHigth(20);

	CDC *wndDC;
	wndDC = GetDC();

	view.SetPrinterRate(float((float)pDC->GetDeviceCaps(LOGPIXELSX)/(float)wndDC->GetDeviceCaps(LOGPIXELSX)), 
		float((float)pDC->GetDeviceCaps(LOGPIXELSX)/(float)wndDC->GetDeviceCaps(LOGPIXELSY)));
	view.BeginPrint();
	pDC->StartPage();
	view.ShowColumn();
	
	CADOOperation paylist;
	CString fields[] = {"year", "month", "name", "dept", "duty", "laborage", 
		"duty_laborage", "leser_laborage", "bonus","insurance",   "deduct"};
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
	pDC->EndPage();
	view.EndPrint();
	return ret;
}

double CPayListDlg::GetTotalSum(CString &name, int year, int month)
{
	double total = 0;
	CADOOperation ado;
	CString sql;
	CString str;
	sql.Format("\
				  select pay_bonus - pay_deduct + pay_laborage + duty_laborage + leser_laborage - insurance\
				  from tb_paylist, tb_employee \
				  where tb_paylist.employee_id = tb_employee.employee_id \
				  and tb_employee.employee_name = '%s'\
				  and pay_dateyear = %d\
				  and pay_datemonth = %d ", name, year, month);
	ado.OpenRecordset(sql);
	ado.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
	ado.CloseRecorset();
	return atof(str);

}

void CPayListDlg::OnEdit() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
}
