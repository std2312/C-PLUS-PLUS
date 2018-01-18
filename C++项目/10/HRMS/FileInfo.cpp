// FileInfo.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "FileInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileInfo dialog


CFileInfo::CFileInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CFileInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileInfo)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CFileInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileInfo)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileInfo, CDialog)
	//{{AFX_MSG_MAP(CFileInfo)
	ON_WM_CANCELMODE()
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_WM_CAPTURECHANGED()
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_BN_CLICKED(IDC_EXPORTTOWORD, OnExporttoword)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_BN_CLICKED(IDC_ADDNEW, OnAddnew)
	ON_COMMAND(IDM_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileInfo message handlers



BOOL CFileInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_ListCtrl.InsertColumn(0, "编号", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(1, "姓名", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(2, "性别", LVCFMT_LEFT, 40);
	m_ListCtrl.InsertColumn(3, "出生年月", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "学历", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "工龄(年)", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(7, "职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(8, "入职时间", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(9, "电话", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(10, "住址", LVCFMT_LEFT, 120);

	ShowAllRecords();

	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFileInfo::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

BOOL CFileInfo::ShowAllRecords()
{
	CADOOperation emp;
	CString str[] = {"id", "name", "sex", "birthday", 
		"edulev", "lenofser", "dept", "duty", "timeofser", "phone", "address"};
	emp.OpenRecordset("\
						 select tb_employee.employee_id as id, tb_employee.employee_name as name, \
						 tb_employee.employee_sex as sex,\
						 tb_employee.employee_birthday as birthday,tb_employee.employee_lenofser as lenofser,\
						 tb_employee.employee_edulev as edulev, tb_dept.dept_name as dept , \
						 tb_dept_duty.duty_name as duty, tb_employee.employee_timeofser as timeofser, \
						 tb_employee.employee_phone as phone, tb_employee.employee_dwel as address\
						 from tb_employee, tb_dept, tb_dept_duty\
						 where tb_employee.employee_dept = tb_dept.dept_id and tb_employee.employee_duty = tb_dept_duty.duty_id");
	emp.ShowADOView(str, 11, this);
	emp.CloseRecorset();

	return TRUE;
}

void CFileInfo::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POINT pt;
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	if(m_CurSel < 0)
		goto end;

	::GetCursorPos(&pt);
	this->ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
end:
	*pResult = 0;
}

BOOL CFileInfo::SetRow(int row, CString *strArray, int len)
{
	m_ListCtrl.InsertItem(row, strArray[0], 0);
	for(int i=1; i < len; i++)
		m_ListCtrl.SetItemText(row, i, strArray[i]);

	return TRUE;
}

BOOL CFileInfo::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

void CFileInfo::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CDialog::OnCaptureChanged(pWnd);
}

BOOL CFileInfo::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}

void CFileInfo::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CFindEmployeeDlg dlg(this);
	dlg.DoModal();
}

BOOL CFileInfo::ExportToWord(CString &file)
{
	CADOOperation ado;
	ado.OpenRecordset("\
						 select tb_employee.employee_id as 员工编号, tb_employee.employee_name as 姓名, \
						 tb_employee.employee_sex as 性别,\
						 tb_employee.employee_birthday as 生日, tb_employee.employee_lenofser as 工龄,\
						 tb_employee.employee_edulev as 学历, tb_dept.dept_name as 部门, \
						 tb_dept_duty.duty_name as 职务, tb_employee.employee_timeofser as 入职时间, \
						 tb_employee.employee_phone as 电话, tb_employee.employee_dwel as 住址\
						 from tb_employee, tb_dept, tb_dept_duty\
						 where tb_employee.employee_dept = tb_dept.dept_id and tb_employee.employee_duty = tb_dept_duty.duty_id");
	
	ado.ExportToWord(file);
	ado.CloseRecorset();
	return TRUE;
}

void CFileInfo::OnExporttoword() 
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

void CFileInfo::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(!G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	CADOOperation ado;
	ado.OpenTable("tb_employee");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	this->ShowAllRecords();
	m_CurSel = -1;

}

void CFileInfo::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
 	if(G_IsLanded)
 	{
 		LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
 		
 		if(lpnmlv->iItem < 0)
			return ;
		m_CurSel = lpnmlv->iItem;
 		CFileRecord fileRecord;
 		fileRecord.SetModifyDlg();
 		fileRecord.SetShowItem(lpnmlv->iItem);
 		fileRecord.DoModal();
		ShowAllRecords();
 	}
	else
		MessageBox("请登陆！");
  	*pResult = 0;
}

void CFileInfo::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CFileInfo::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CFileInfo::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}

void CFileInfo::OnAddnew() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void CFileInfo::OnEdit() 
{
	// TODO: Add your command handler code here
	if(G_IsLanded)
 	{
		if(m_CurSel < 0)
		{
			MessageBox("请选择一个所要编辑的项！");
			return ;
		}
 		CFileRecord fileRecord;
 		fileRecord.SetModifyDlg();
 		fileRecord.SetShowItem(m_CurSel);
 		fileRecord.DoModal();
		ShowAllRecords();
 	}
	MessageBox("请登陆！");
}
