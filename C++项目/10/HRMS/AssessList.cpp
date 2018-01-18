// AssessList.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "AssessList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssessList dialog


CAssessList::CAssessList(CWnd* pParent /*=NULL*/)
	: CDialog(CAssessList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssessList)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
	m_pNMListView = NULL;
}


void CAssessList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssessList)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssessList, CDialog)
	//{{AFX_MSG_MAP(CAssessList)
	ON_BN_CLICKED(IDC_EXPORTTOWORD, OnExporttoword)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_MESSAGE(UM_LISTEDIT_KILLFOCUS, OnListEditKillFocus)
	ON_MESSAGE(UM_LISTEDIT_DBCLICK, OnListEditDBClick)
	ON_COMMAND(IDM_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssessList message handlers

BOOL CAssessList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );
	
	m_ListCtrl.InsertColumn(0, "日期(年)", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, "日期(月)", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(2, "编号", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(3, "姓名", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "工作态度", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(7, "业绩评估", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(8, "能力评介", LVCFMT_LEFT, 80);
	ShowAssessList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CAssessList::SetRow(int row, CString *strArray, int count)
{

	m_ListCtrl.InsertItem(row, strArray[0], 0);
	for(int i=1; i<count; i++)
		m_ListCtrl.SetItemText(row, i, strArray[i]);

	return TRUE;
}

BOOL CAssessList::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

BOOL CAssessList::ShowAssessList()
{
	CADOOperation list;
	CString fields[] = {"dateyear", "datemonth", "id", "name", "dept", "duty",
		"mannerofwork", "ability", "efficiency"};

	list.OpenRecordset("\
						  select tb_assess.assess_dateyear as dateyear, tb_assess.assess_datemonth as datemonth, \
						  tb_assess.employee_id as id, tb_employee.employee_name as name, tb_dept.dept_name as dept, \
						  tb_dept_duty.duty_name as duty, tb_assess.assess_mannerofwork as mannerofwork,\
						  tb_assess.assess_ability as ability, tb_assess.assess_efficiency as efficiency\
						  from tb_assess, tb_employee, tb_dept, tb_dept_duty\
						  where tb_employee.employee_id = tb_assess.employee_id\
						  and tb_employee.employee_dept = tb_dept.dept_id\
						  and tb_employee.employee_duty = tb_dept_duty.duty_id");
	list.ShowADOView(fields, 9, this);
	list.CloseRecorset();

	return TRUE;
}

void CAssessList::OnExporttoword() 
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

BOOL CAssessList::ExportToWord(CString &file)
{

	CADOOperation ado;

	ado.OpenRecordset("\
						 select tb_assess.assess_dateyear as 年份, tb_assess.assess_datemonth as 月份, \
						 tb_assess.employee_id as 员工编号, tb_employee.employee_name as 姓名, \
						 tb_dept.dept_name as 部门, \
						 tb_dept_duty.duty_name as 职务, tb_assess.assess_mannerofwork as 工作态度,\
						 tb_assess.assess_ability as 工作能力, tb_assess.assess_efficiency as 工作业绩\
						 from tb_assess, tb_employee, tb_dept, tb_dept_duty\
						 where tb_employee.employee_id = tb_assess.employee_id\
						 and tb_employee.employee_dept = tb_dept.dept_id\
						 and tb_employee.employee_duty = tb_dept_duty.duty_id");

	ado.ExportToWord(file);
	ado.CloseRecorset();

	return TRUE;
}

void CAssessList::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	if(m_CurSel < 0)
		goto end;
	m_pNMListView = (LPNMLISTVIEW)pNMHDR;
	POINT pt;
	::GetCursorPos(&pt);
	ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
end:
	*pResult = 0;
}

void CAssessList::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	CADOOperation ado;
	ado.OpenTable("tb_assess");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	ShowAssessList();

	m_CurSel = -1;
}

void CAssessList::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CAssessList::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CAssessList::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}

BOOL CAssessList::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CAssessList::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CAssessSearchDlg dlg;
	CString seaExpr;
	if(IDOK == dlg.DoModal())
	{
		seaExpr = dlg.GetSearchExpression();
		ShowAssessList(seaExpr);
	}
}

BOOL CAssessList::ShowAssessList(CString &seaExpr)
{

	CADOOperation list;
	CString sql;
	CString fields[] = {"dateyear", "datemonth", "id", "name", "dept", "duty",
		"mannerofwork", "ability", "efficiency"};
	sql.Format("\
				  select tb_assess.assess_dateyear as dateyear, tb_assess.assess_datemonth as datemonth, \
				  tb_assess.employee_id as id, tb_employee.employee_name as name, tb_dept.dept_name as dept, \
				  tb_dept_duty.duty_name as duty, tb_assess.assess_mannerofwork as mannerofwork,\
				  tb_assess.assess_ability as ability, tb_assess.assess_efficiency as efficiency\
				  from tb_assess, tb_employee, tb_dept, tb_dept_duty\
				  where tb_employee.employee_id = tb_assess.employee_id\
				  and tb_employee.employee_dept = tb_dept.dept_id\
				  and tb_employee.employee_duty = tb_dept_duty.duty_id and %s", seaExpr);
	PRINTRESULT(sql);
	list.OpenRecordset(sql);
	list.ShowADOView(fields, 9, this);
	list.CloseRecorset();

	return TRUE;
}

LRESULT CAssessList::OnListEditKillFocus(WPARAM wParam, LPARAM lParam)
{
	SaveModify(wParam, lParam);
	return 0;
}

LRESULT CAssessList::OnListEditDBClick(WPARAM wParam, LPARAM lParam)
{
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)wParam;
	m_pNMListView = lpnmlv;
	if(!::G_IsLanded)
	{
		m_ListCtrl.ShowEditBox(FALSE, lpnmlv->iItem, lpnmlv->iSubItem);
		return 0;
	}
	if(lpnmlv->iSubItem == 0 || lpnmlv->iSubItem == 1 || lpnmlv->iSubItem == 2)
		m_ListCtrl.ShowEditBox(FALSE, NULL);

	return 0;
}

BOOL CAssessList::SaveModify(int iItem, int subItem)
{
	CString sql;
	CADOOperation ado;
	if(subItem < 3)
		return TRUE;

	switch(subItem)
	{
	case 3:		//姓名
		{
			CString name, id;
			name = m_ListCtrl.GetItemText(iItem, subItem);
			id = m_ListCtrl.GetItemText(iItem, 2);
			sql.Format("update tb_employee set employee_name = '%s' where employee_id = '%s'", name, id);
		}
		break;
	case 4:		//部门
		{
			CString id, dept;
			DWORD deptSerial = -1;
			id = m_ListCtrl.GetItemText(iItem, 2);
			dept = m_ListCtrl.GetItemText(iItem, subItem);
			deptSerial = CFileRecord::GetDeptNumber(dept);
			if(deptSerial <=0 )
			{
				MessageBox("请确认该部门的存在！");
				return FALSE;
			}
			sql.Format("update tb_employee set employee_dept = %d where employee_id = '%s'", deptSerial, id);
		}
		break;
	case 5://职务
		{
			CString id, duty;
			DWORD dutySerial = -1;
			id = m_ListCtrl.GetItemText(iItem, 2);
			duty = m_ListCtrl.GetItemText(iItem, subItem);
			dutySerial = CFileRecord::GetDutyNumber(duty);
			if(dutySerial <= 0)
			{
				MessageBox("请确认该职位的存在！");
				return FALSE;
			}
			sql.Format("update tb_employee set employee_duty = %d where employee_id = '%s'", dutySerial, id);
		}
		break;
	case 6:case 7: case 8:		//工作态度
		{
			CString id;
			int y, m;
			float attWork, evaWork, scoWork;
			attWork = (float)atof(m_ListCtrl.GetItemText(iItem, 6));
			evaWork = (float)atof(m_ListCtrl.GetItemText(iItem, 7));
			scoWork = (float)atof(m_ListCtrl.GetItemText(iItem, 8));
			id = m_ListCtrl.GetItemText(iItem, 2);
			y = atoi(m_ListCtrl.GetItemText(iItem, 0));
			m = atoi(m_ListCtrl.GetItemText(iItem, 1));
			sql.Format("update tb_assess set assess_mannerofwork = %f,\
				assess_efficiency = %f,assess_ability = %f \
				where employee_id = '%s' and assess_dateyear = %d and \
				assess_datemonth = %d", attWork, evaWork, scoWork, id, y, m);
			PRINTRESULT(sql);
		}
		break;
	default:
		return FALSE;
	}
	ado.OpenRecordset(sql);
	ado.CloseRecorset();
	return TRUE;
}

void CAssessList::OnEdit() 
{
	// TODO: Add your command handler code her
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	if(NULL != m_pNMListView)
	{
		if(m_pNMListView->iSubItem >= 3)
		{
			m_ListCtrl.ShowEditBox(TRUE, m_pNMListView->iItem, m_pNMListView->iSubItem);
			m_pNMListView = NULL;
		}
	}
}
