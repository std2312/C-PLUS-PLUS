// LaborageRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LaborageRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLaborageRecordDlg dialog


CLaborageRecordDlg::CLaborageRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborageRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLaborageRecordDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CLaborageRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLaborageRecordDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLaborageRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CLaborageRecordDlg)
	ON_MESSAGE(UM_LISTEDIT_DBCLICK, OnListEditDBClick)
	ON_MESSAGE(UM_LISTEDIT_KILLFOCUS, OnListEditKillFocus)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_COMMAND(IDM_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_EXPORT_TO_WORD, OnExportToWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLaborageRecordDlg message handlers

BOOL CLaborageRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_ListCtrl.SetExtendedStyle(LVS_EX_FLATSB 
		| LVS_EX_GRIDLINES 
		|LVS_EX_TRACKSELECT 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_ONECLICKACTIVATE);

	m_ListCtrl.InsertColumn(0, "员工编号", LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(1, "姓名", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(2, "部门", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(3, "职务", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(4, "基本工资", LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(5, "职务工资", LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(6, "工龄工资", LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(7, "养老保险", LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(8, "缺勤扣款（元/小时）", LVCFMT_LEFT, 100);
	ShowLaborageRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLaborageRecordDlg::ShowLaborageRecord()
{
	CADOOperation ado;
	CString fields[] = {"employee_id", "employee_name", "dept_name", 
	"duty_name", "base_laborage", "duty_laborage", "leser_laborage", "insurance", "recoup"};

	ado.OpenRecordset("\
		select tb_laborage.employee_id, tb_employee.employee_name, \
		tb_dept.dept_name, tb_dept_duty.duty_name, tb_laborage.base_laborage,\
		tb_laborage.duty_laborage, 	tb_laborage.leser_laborage, tb_laborage.insurance, \
		tb_laborage.recoup	from tb_laborage, tb_employee, tb_dept, tb_dept_duty\
		where tb_laborage.employee_id = tb_employee.employee_id and\
		tb_employee.employee_dept = tb_dept.dept_id and\
		tb_employee.employee_duty = tb_dept_duty.duty_id ");
	ado.ShowADOView(fields, 9, this);
	ado.CloseRecorset();
	return TRUE;
}

BOOL CLaborageRecordDlg::SetRow(int row, CString *strArray, int count)
{
	m_ListCtrl.InsertItem(row, strArray[0]);
	for(int i=1; i < count; i++)
		m_ListCtrl.SetItemText(row, i, strArray[i]);
	return TRUE;
}

BOOL CLaborageRecordDlg::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

LRESULT CLaborageRecordDlg::OnListEditDBClick(WPARAM wParam, LPARAM lParam)
{
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)wParam;
	if(!::G_IsLanded)
	{
		m_ListCtrl.ShowEditBox(FALSE, lpnmlv->iItem, lpnmlv->iSubItem);
	}
	if(lpnmlv->iSubItem ==0)
	{
		m_ListCtrl.ShowEditBox(FALSE, lpnmlv->iItem, lpnmlv->iSubItem);
		return TRUE;
	}
	return TRUE;
}

LRESULT CLaborageRecordDlg::OnListEditKillFocus(WPARAM wParam, LPARAM lParam)
{
	if(0 == lParam)
		return TRUE;
	SaveModify(wParam, lParam);
	return TRUE;
}

BOOL CLaborageRecordDlg::SaveModify(int iItem, int iSubItem)
{
	CString sql;
	CADOOperation ado;
	switch(iSubItem)
	{
	case 0:
		return TRUE;
	case 1:		//姓名
		{
			CString name, id;
			name = m_ListCtrl.GetItemText(iItem, iSubItem);
			id = m_ListCtrl.GetItemText(iItem, 0);
			sql.Format("update tb_employee set employee_name = '%s' where employee_id = '%s'", name, id);
		}
		break;
	case 2:		//部门
		{
			CString id, dept;
			DWORD deptSerial = -1;
			id = m_ListCtrl.GetItemText(iItem, 0);
			dept = m_ListCtrl.GetItemText(iItem, iSubItem);
			deptSerial = CFileRecord::GetDeptNumber(dept);
			if(deptSerial <=0 )
			{
				MessageBox("请确认该部门的存在！");
				return FALSE;
			}
			sql.Format("update tb_employee set employee_dept = %d where employee_id = '%s'", deptSerial, id);
		}
		break;
	case 3://职务
		{
			CString id, duty;
			DWORD dutySerial = -1;
			id = m_ListCtrl.GetItemText(iItem, 0);
			duty = m_ListCtrl.GetItemText(iItem, iSubItem);
			dutySerial = CFileRecord::GetDutyNumber(duty);
			if(dutySerial <= 0)
			{
				MessageBox("请确认该职位的存在！");
				return FALSE;
			}
			sql.Format("update tb_employee set employee_duty = %d where employee_id = '%s'", dutySerial, id);
		}
		break;
	case 4:case 5:case 6:case 7:case 8:
		{
			float b_lab, d_lab, l_lab, insur, recou;
			CString id;
			b_lab = (float)atof(m_ListCtrl.GetItemText(iItem, 4));
			d_lab = (float)atof(m_ListCtrl.GetItemText(iItem, 5));
			l_lab = (float)atof(m_ListCtrl.GetItemText(iItem, 6));
			insur = (float)atof(m_ListCtrl.GetItemText(iItem, 7));
			recou = (float)atof(m_ListCtrl.GetItemText(iItem, 8));
			id = m_ListCtrl.GetItemText(iItem, 0);
			sql.Format("\
						  update tb_laborage set base_laborage = %f, \
						  duty_laborage = %f, leser_laborage = %f, insurance = %f,\
						  recoup = %f where employee_id = '%s'", b_lab, d_lab, l_lab, insur, recou, id);
		}
		break;
	default:
		return FALSE;
	}
	ado.OpenRecordset(sql);
	ado.CloseRecorset();
	return TRUE;
}

BOOL CLaborageRecordDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CLaborageRecordDlg::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CLabRecSearchDlg dlg;
	CString seaExpr;
	if(IDOK == dlg.DoModal())
	{
		seaExpr = dlg.GetSearchExpression();
		ShowLaborageRecord(seaExpr);
	}
}

BOOL CLaborageRecordDlg::ShowLaborageRecord(CString &seaExpr)
{
	CADOOperation ado;
	CString sql;
	CString fields[] = {"employee_id", "employee_name", "dept_name", 
	"duty_name", "base_laborage", "duty_laborage", "leser_laborage", "insurance", "recoup"};
	sql.Format("\
		select tb_laborage.employee_id, tb_employee.employee_name, \
		tb_dept.dept_name, tb_dept_duty.duty_name, tb_laborage.base_laborage,\
		tb_laborage.duty_laborage, 	tb_laborage.leser_laborage, tb_laborage.insurance, \
		tb_laborage.recoup	from tb_laborage, tb_employee, tb_dept, tb_dept_duty\
		where tb_laborage.employee_id = tb_employee.employee_id and\
		tb_employee.employee_dept = tb_dept.dept_id and\
		tb_employee.employee_duty = tb_dept_duty.duty_id and %s", seaExpr);
	ado.OpenRecordset(sql);
	ado.ShowADOView(fields, 9, this);
	ado.CloseRecorset();
	return TRUE;
}

void CLaborageRecordDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(!::G_IsLanded)
	{
		return;
	}
	m_lpNMListView = (LPNMLISTVIEW)pNMHDR;
	if(m_lpNMListView->iItem < 0)
	{
		*pResult = 0;
		return ;
	}
	m_CurSel = m_lpNMListView->iItem;
	POINT pt;
	::GetCursorPos(&pt);
	ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
	*pResult = 0;
}

void CLaborageRecordDlg::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}

void CLaborageRecordDlg::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CLaborageRecordDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CLaborageRecordDlg::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	CADOOperation ado;
	ado.OpenTable("tb_laborage");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	m_CurSel = -1;
	ShowLaborageRecord();
}

void CLaborageRecordDlg::OnEdit() 
{
	// TODO: Add your command handler code here
	if(NULL == m_lpNMListView 
		|| m_lpNMListView->iItem < 0 
		|| m_lpNMListView->iSubItem < 0)
	{
		MessageBox("请选择一个要编辑的项！", "提示", MB_OK);
		return ;
	}
	m_ListCtrl.ShowEditBox(TRUE, 
		m_lpNMListView->iItem, 
		m_lpNMListView->iSubItem);
}

void CLaborageRecordDlg::OnExportToWord() 
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

void CLaborageRecordDlg::ExportToWord(CString &file)
{
	CADOOperation ado;
	ado.OpenRecordset("select tb_laborage.employee_id as 员工编号, tb_employee.employee_name as 员工姓名, \
		tb_dept.dept_name as 部门, tb_dept_duty.duty_name as 职位, tb_laborage.base_laborage as 基本工资,\
		tb_laborage.duty_laborage as 职务工资, 	tb_laborage.leser_laborage as 工龄工资, tb_laborage.insurance as 养老保险, \
		tb_laborage.recoup	as 缺勤扣款 from tb_laborage, tb_employee, tb_dept, tb_dept_duty\
		where tb_laborage.employee_id = tb_employee.employee_id and\
		tb_employee.employee_dept = tb_dept.dept_id and\
		tb_employee.employee_duty = tb_dept_duty.duty_id");
	ado.ExportToWord(file);
	ado.CloseRecorset();
}
