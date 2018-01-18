// RequestInfListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "RequestInfListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRequestInfListDlg dialog


CRequestInfListDlg::CRequestInfListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRequestInfListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRequestInfListDlg)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CRequestInfListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRequestInfListDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRequestInfListDlg, CDialog)
	//{{AFX_MSG_MAP(CRequestInfListDlg)
	ON_BN_CLICKED(IDC_EXPORTTOWORD, OnExporttoword)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_COMMAND(IDM_EDIT, OnEdit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRequestInfListDlg message handlers

BOOL CRequestInfListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	UpdateTable();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_ListCtrl.InsertColumn(0, "编号", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, "申请部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(2, "申请职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(3, "性别要求", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "年龄要求", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "要求学历", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "负责人编号", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(7, "申请状态", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(8, "申请日期", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(9, "有效日期", LVCFMT_LEFT, 80);
	ShowRequestList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CRequestInfListDlg::SetRow(int row, CString *strArray, int count)
{
	m_ListCtrl.InsertItem(row, strArray[0], 0);
	m_ListCtrl.SetItemText(row, 1, strArray[1]);
	m_ListCtrl.SetItemText(row, 2, strArray[2]);
	m_ListCtrl.SetItemText(row, 3, strArray[3]);
	m_ListCtrl.SetItemText(row, 4, strArray[4] + " -- "+  strArray[5]);
	m_ListCtrl.SetItemText(row, 5, strArray[6]);
	m_ListCtrl.SetItemText(row, 6, strArray[7]);
	m_ListCtrl.SetItemText(row, 7, strArray[8]);
	m_ListCtrl.SetItemText(row, 8, strArray[9]);
	m_ListCtrl.SetItemText(row, 9, strArray[10]);

	return TRUE;
}

BOOL CRequestInfListDlg::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

BOOL CRequestInfListDlg::ShowRequestList()
{

	CADOOperation list;
	CString fields[] = {"torequest_number", "dept_name", "duty_name", "torequest_sex",
		"torequest_minage", "torequest_maxage", "torequest_edulev", "torequest_principal","torequest_state",
		"torequest_date", "torequest_perofval"};
	
		list.OpenRecordset(	"\
							   select torequest_number, tb_dept.dept_name, tb_dept_duty.duty_name, tb_torequest.torequest_sex,\
							   tb_torequest.torequest_minage, tb_torequest.torequest_maxage, tb_torequest.torequest_edulev,\
							   tb_torequest.torequest_principal,tb_torequest.torequest_state,\
							   tb_torequest.torequest_date,tb_torequest.torequest_perofval\
							   from tb_torequest, tb_dept, tb_dept_duty \
							   where tb_torequest.torequest_dept = tb_dept.dept_id \
							   and tb_torequest.torequest_duty = tb_dept_duty.duty_id");

	
	list.ShowADOView(fields, 11, this);
	list.CloseRecorset();
	return TRUE;
}

BOOL CRequestInfListDlg::ExportToWord(CString &file)
{
	CADOOperation ado;
	ado.OpenRecordset("\
						 select tb_dept.dept_name as 部门, tb_dept_duty.duty_name as 职位, \
						 tb_torequest.torequest_sex as 性别要求, \
						 tb_torequest.torequest_minage as 年龄下限, \
						 tb_torequest.torequest_maxage as 年龄上限, \
						 tb_torequest.torequest_edulev as 学历要求, \
						 tb_torequest.torequest_principal as 负责人编号, \
						 tb_torequest.torequest_date as 请求日期, \
						 tb_torequest.torequest_perofval as 有效日期\
						 from tb_torequest, tb_dept, tb_dept_duty\
						 where tb_torequest.torequest_dept = tb_dept.dept_id\
						 and tb_torequest.torequest_duty = tb_dept_duty.duty_id");

	ado.ExportToWord(file);
	ado.CloseRecorset();
	return TRUE;
}

void CRequestInfListDlg::OnExporttoword() 
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

void CRequestInfListDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	if(m_CurSel < 0)
		goto end;

	POINT pt;
	::GetCursorPos(&pt);
	this->ShowItemMenu(G_IsLanded, pt.x, pt.y, this);
end:
	*pResult = 0;
}

void CRequestInfListDlg::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要删除的项！");
		return;
	}
	CADOOperation ado;
	ado.OpenTable("tb_torequest");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	m_CurSel = -1;
	ShowRequestList();
}

void CRequestInfListDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CRequestInfListDlg::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

BOOL CRequestInfListDlg::UpdateTable()
{
	CADOOperation ado;
	ado.OpenRecordset("\
						 update tb_torequest\
						 set torequest_state = '过期' \
						 where torequest_perofval < getdate() \
						 and torequest_state = '有效'");
	ado.CloseRecorset();
	return TRUE;
}

BOOL CRequestInfListDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

void CRequestInfListDlg::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CSearchRequestDlg dlg;
	CString seaExp;
	if(IDOK !=dlg.DoModal())
		return;
	seaExp = dlg.GetSearchExpression();
	ShowRequestList(seaExp);
}

BOOL CRequestInfListDlg::ShowRequestList(CString &seaExpr)
{
	CADOOperation ado;
	CString sql;
	CString fields[] = {"torequest_number", "dept_name", "duty_name", "torequest_sex",
		"torequest_minage", "torequest_maxage", "torequest_edulev", "torequest_principal","torequest_state",
		"torequest_date", "torequest_perofval"};
		sql.Format("\
					  select tb_torequest.torequest_number, \
					  tb_dept.dept_name, tb_dept_duty.duty_name, tb_torequest.torequest_sex, \
					  tb_torequest.torequest_minage, tb_torequest.torequest_maxage, \
					  tb_torequest.torequest_edulev, tb_torequest.torequest_principal, \
					  tb_torequest.torequest_state, tb_torequest.torequest_date, \
					  tb_torequest.torequest_perofval \
					  from tb_torequest, tb_dept, tb_dept_duty \
					  where tb_torequest.torequest_dept = tb_dept.dept_id \
					  and tb_torequest.torequest_duty = tb_dept_duty.duty_id and %s", seaExpr);
	ado.OpenRecordset(sql);
	ado.ShowADOView(fields, 11, this);
	ado.CloseRecorset();

	return TRUE;
}

void CRequestInfListDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	CApplyEmployeeDlg dlg;
	CString serial;
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	m_CurSel = lpnmlv->iItem;
	if(m_CurSel>=0)
	{
		serial = m_ListCtrl.GetItemText(lpnmlv->iItem, 0);
		dlg.SetApplicationSerial(serial);
		dlg.DoModal();
		ShowRequestList();
	}

	*pResult = 0;
}

void CRequestInfListDlg::OnEdit() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
	{
		MessageBox("请登陆！");
		return;
	}
	CApplyEmployeeDlg dlg;
	CString app;
	app = m_ListCtrl.GetItemText(m_CurSel, 0);
	dlg.SetApplicationSerial(app);
	dlg.DoModal();
}

void CRequestInfListDlg::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	OnFindEmployee();
}
