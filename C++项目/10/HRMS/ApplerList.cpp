// ApplerList.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ApplerList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApplerList dialog


CApplerList::CApplerList(CWnd* pParent /*=NULL*/)
	: CDialog(CApplerList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CApplerList)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CApplerList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CApplerList)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CApplerList, CDialog)
	//{{AFX_MSG_MAP(CApplerList)
	ON_BN_CLICKED(IDC_EXPORTTOWORD, OnExporttoword)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_COMMAND(IDM_EDIT, OnEdit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_BN_CLICKED(IDC_ADDNEW, OnAddnew)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApplerList message handlers

BOOL CApplerList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_SearchAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDR_ACCELERATOR1));

	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );
	m_ListCtrl.InsertColumn(0, "编号", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, "姓名", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(2, "性别", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(3, "出生日期", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "学历", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "专业", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "应聘部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(7, "应聘职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(8, "籍贯", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(9, "电话", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(10, "住址", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(11, "ICQ", LVCFMT_LEFT, 80);
	ShowApplerList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CApplerList::ShowApplerList()
{
	CADOOperation list;
	CString fields[] = {"id", "name", "sex", "birthday", "edulev", "specialty", 
		 "dept", "duty", "nativeplace", "phone", "address", "ICQ"};
	list.OpenRecordset("\
						  select tb_applicant.applicant_id as id, tb_applicant.applicant_name as name,\
						  tb_applicant.applicant_sex as sex, tb_applicant.applicant_nativeplace as nativeplace,\
						  tb_applicant.applicant_birthday as birthday, tb_applicant.applicant_specialty as specialty, \
						  tb_applicant.applicant_eduoflev as edulev, tb_dept.dept_name as dept,\
						  tb_dept_duty.duty_name as duty,\
						  tb_applicant.applicant_phone as phone, tb_applicant.applicant_address as address, \
						  tb_applicant.applicant_ICO as ICQ\
						  from tb_applicant, tb_dept, tb_dept_duty\
						  where tb_applicant.applicant_dept = tb_dept.dept_id \
						  and tb_applicant.applicant_duty = tb_dept_duty.duty_id");

	list.ShowADOView(fields, 12, this);
	list.CloseRecorset();

	return TRUE;
}

BOOL CApplerList::SetRow(int row, CString *strArray, int count)
{

	m_ListCtrl.InsertItem(row, strArray[0]);
	for(int i=1; i<count; i++)
		m_ListCtrl.SetItemText(row, i ,strArray[i]);

	return TRUE;
}

BOOL CApplerList::DeleteAllRows()
{

	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

void CApplerList::OnExporttoword() 
{
	// TODO: Add your control notification handler code here
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

BOOL CApplerList::ExportToWord(CString &file)
{
	CADOOperation ado;
	ado.OpenRecordset("select tb_applicant.applicant_id as 应聘者编号, tb_applicant.applicant_name as 姓名,\
						  tb_applicant.applicant_sex as 姓性, tb_applicant.applicant_nativeplace as 籍贯,\
						  tb_applicant.applicant_birthday as 生日, tb_applicant.applicant_specialty as 专业, \
						  tb_applicant.applicant_eduoflev as 学历, tb_dept.dept_name as 申请部门,\
						  tb_dept_duty.duty_name as 申请职位,\
						  tb_applicant.applicant_phone as phone, tb_applicant.applicant_address as address, \
						  tb_applicant.applicant_ICO as ICQ\
						  from tb_applicant, tb_dept, tb_dept_duty\
						  where tb_applicant.applicant_dept = tb_dept.dept_id \
						  and tb_applicant.applicant_duty = tb_dept_duty.duty_id");

	ado.ExportToWord(file);
	ado.CloseRecorset();

	return TRUE;
}

void CApplerList::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	if(m_CurSel < 0)
		goto end;

	POINT pt;
	::GetCursorPos(&pt);
	ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
end:
	*pResult = 0;
}

void CApplerList::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要删除的项！");
		return ;
	}
	CADOOperation ado;
	ado.OpenTable("tb_applicant");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	ShowApplerList();
	m_CurSel = -1;
}

BOOL CApplerList::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_SearchAccel != NULL)
		if(::TranslateAccelerator(m_hWnd, m_SearchAccel, pMsg))
			return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}

void CApplerList::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CApplerSearchDlg search;
	CString condition;
	if(IDOK != search.DoModal())
		return ;
	condition = search.GetSearchCondition();
	m_SeachExpression = condition;
	ShowApplerList(condition);

}

BOOL CApplerList::ShowApplerList(CString &condition)
{
	BOOL ret = FALSE;
	CADOOperation list;
	CString fields[] = {"id", "name", "sex", "birthday", "edulev", "specialty", 
		 "dept", "duty", "nativeplace", "phone", "address", "ICQ"};
	list.OpenRecordset("\
						  select tb_applicant.applicant_id as id, tb_applicant.applicant_name as name,\
						  tb_applicant.applicant_sex as sex, tb_applicant.applicant_nativeplace as nativeplace,\
						  tb_applicant.applicant_birthday as birthday, tb_applicant.applicant_specialty as specialty, \
						  tb_applicant.applicant_eduoflev as edulev, tb_dept.dept_name as dept,\
						  tb_dept_duty.duty_name as duty,\
						  tb_applicant.applicant_phone as phone, tb_applicant.applicant_address as address, \
						  tb_applicant.applicant_ICO as ICQ\
						  from tb_applicant, tb_dept, tb_dept_duty\
						  where tb_applicant.applicant_dept = tb_dept.dept_id \
						  and tb_applicant.applicant_duty = tb_dept_duty.duty_id and " + condition);

	list.ShowADOView(fields, 12, this);
	list.CloseRecorset();
	return ret;
}

void CApplerList::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CApplerList::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CApplerList::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	CApplerInfo dlg;
	CString num;
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	if(lpnmlv->iItem >= 0)
	{
		m_CurSel = lpnmlv->iItem;
		num = m_ListCtrl.GetItemText(lpnmlv->iItem, 0);
		dlg.SetCurrentApplerNumber(num);
		dlg.DoModal();
		ShowApplerList();
	}
	*pResult = 0;
}



void CApplerList::OnEdit() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	CApplerInfo dlg;
	CString num;
	num = m_ListCtrl.GetItemText(m_CurSel, 0);
	dlg.SetCurrentApplerNumber(num);
	dlg.DoModal();
	ShowApplerList();
}

void CApplerList::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}

void CApplerList::OnAddnew() 
{
	// TODO: Add your control notification handler code here
	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要加入的项！");
		return ;
	}
	CString id;
	id = m_ListCtrl.GetItemText(m_CurSel, 0);
	EndDialog(0);

	CFileRecord rec;
	rec.SetAppler(TRUE);
	rec.SetApplerId(id);
	rec.DoModal();
}

void CApplerList::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	*pResult = 0;
}
