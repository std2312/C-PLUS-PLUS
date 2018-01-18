// LeaveList.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LeaveList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeaveList dialog


CLeaveList::CLeaveList(CWnd* pParent /*=NULL*/)
	: CDialog(CLeaveList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeaveList)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CLeaveList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeaveList)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeaveList, CDialog)
	//{{AFX_MSG_MAP(CLeaveList)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO5, OnSetfocusCombo5)
	ON_CBN_KILLFOCUS(IDC_COMBO1, OnKillfocusCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO6, OnSetfocusCombo6)
	ON_CBN_SELCHANGE(IDC_COMBO5, OnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnSelchangeCombo6)
	ON_CBN_KILLFOCUS(IDC_COMBO5, OnKillfocusCombo5)
	ON_COMMAND(ID_DELITEM, OnDelitem)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(ID_EXPORT, OnExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeaveList message handlers

BOOL CLeaveList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hDelAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_DELITEM));
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_List.InsertColumn(0, "编号", LVCFMT_LEFT, 60);
	m_List.InsertColumn(1, "姓名", LVCFMT_LEFT, 60);
	m_List.InsertColumn(2, "类型", LVCFMT_LEFT, 60);
	m_List.InsertColumn(3, "天数", LVCFMT_LEFT, 60);
	m_List.InsertColumn(4, "原因", LVCFMT_LEFT, 80);
	m_List.InsertColumn(5, "时间从", LVCFMT_LEFT, 80);
	m_List.InsertColumn(6, "时间到", LVCFMT_LEFT, 80);
	m_List.InsertColumn(7, "申请日期", LVCFMT_LEFT, 80);
	OnKillfocusEdit1();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLeaveList::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	CString name;
	CComboBox *com = (CComboBox*)GetDlgItem(IDC_COMBO1);
	GetDlgItemText(IDC_EDIT1, name);
	CLeaveItemDlg::InitNumberComboBox(name, com);
}

BOOL CLeaveList::UpdateDialog()
{
	BOOL ret = TRUE;
	CString constr;
	int year, month;
	GetDlgItemText(IDC_COMBO1, constr);
	year = GetDlgItemInt(IDC_COMBO5);
	month = GetDlgItemInt(IDC_COMBO6);
	ShowList(constr, year, month);

	return ret;
}

void CLeaveList::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CComboBox *num = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CString constr;
	num->GetLBText(num->GetCurSel(), constr);
	InitYearComboBox(constr);
}

BOOL CLeaveList::InitYearComboBox(CString &num)
{
	BOOL ret = TRUE;
	CString sql, constr;
	CComboBox * com = (CComboBox*)GetDlgItem(IDC_COMBO5);
	com->ResetContent();
	CADOOperation ado;
	sql.Format("select year(req_date) from tb_req_leave where req_emp = '%s'", num);
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return TRUE;
	}
	do
	{
		ret = ado.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &constr);
		if(!ret)
		{
			ado.CloseRecorset();
			return ret;
		}
		com->AddString(constr);
		ado.MoveNext();
	}while(!ado.IsLastRow());
	ado.CloseRecorset();
	com->SetCurSel(0);

	return ret;
}

void CLeaveList::OnSetfocusCombo5() 
{
	// TODO: Add your control notification handler code here
	OnSelchangeCombo1();
}

void CLeaveList::OnKillfocusCombo1() 
{
	// TODO: Add your control notification handler code here
	OnSelchangeCombo1();
}



BOOL CLeaveList::InitMonthComboBox(CString &num, int year)
{
	BOOL ret = TRUE;
	CString sql, constr;
	CComboBox *com = (CComboBox*)GetDlgItem(IDC_COMBO6);
	CADOOperation ado;
	sql.Format("\
		select distinct month(req_date) from tb_req_leave \
		where req_emp = '%s' and year(req_date) = %d", num, year);
	com->ResetContent();
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return TRUE;
	}
	do
	{
		ado.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &constr);
		com->AddString(constr);
		ado.MoveNext();
	}while(!ado.IsLastRow());
	ado.CloseRecorset();
	com->SetCurSel(0);
	UpdateDialog();
	return ret;
}

void CLeaveList::OnSetfocusCombo6() 
{
	// TODO: Add your control notification handler code here
	
}

void CLeaveList::OnSelchangeCombo5() 
{
	// TODO: Add your control notification handler code here
	CComboBox *year = (CComboBox*)GetDlgItem(IDC_COMBO5);
	CString constr, num;
	int cur;
	cur = year->GetCurSel();
	if(cur < 0)
		return;
	year->GetLBText(cur, constr);
	GetDlgItemText(IDC_COMBO1, num);
	InitMonthComboBox(num, atoi(constr));
}

BOOL CLeaveList::SetRow(int row, CString *strArray, int count)
{
	m_List.InsertItem(row, strArray[0]);
	for(int i=1; i<count; i++)
		m_List.SetItemText(row, i, strArray[i]);

	return TRUE;
}

BOOL CLeaveList::DeleteAllRows()
{
	m_List.DeleteAllItems();
	return TRUE;
}

BOOL CLeaveList::ShowList(CString &num, int year, int month)
{
	BOOL ret = TRUE;
	CString field[] = { "num", "name", "req_stl", "req_lng", "req_res","req_frm", "req_to",  "req_date"};
	CString sql;
	CADOOperation ado;
	sql.Format("\
		select tb_employee.employee_name as name, tb_req_leave.req_emp as num, tb_req_leave.req_date, \
		tb_req_leave.req_res, tb_req_leave.req_frm, req_to, req_stl, req_lng from tb_req_leave, tb_employee \
		where tb_employee.employee_id = tb_req_leave.req_emp and tb_req_leave.req_emp = '%s'\
		and year(tb_req_leave.req_date) = %d and month(tb_req_leave.req_date) = %d", num, year, month);
	ado.OpenRecordset(sql);
	ado.ShowADOView(field, 8, this);
	ado.CloseRecorset();
	return ret;
}

void CLeaveList::OnSelchangeCombo6() 
{
	// TODO: Add your control notification handler code here
	UpdateDialog();
}

void CLeaveList::OnKillfocusCombo5() 
{
	// TODO: Add your control notification handler code here
	OnSelchangeCombo5();
}

void CLeaveList::OnDelitem() 
{
	// TODO: Add your command handler code here
	if(!::G_IsLanded)
		return;

	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要删除的项！");
		return ;
	}
	if(!G_IsLanded)
	{
		MessageBox("您现在没有权限要删除该项！");
		return ;
	}
	DeleteItem();
	UpdateDialog();
}

BOOL CLeaveList::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hDelAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hDelAccel, pMsg))
			return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CLeaveList::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	*pResult = 0;
}

BOOL CLeaveList::DeleteItem()
{
	BOOL ret = TRUE;
	CString num, sql;
	int year, month;
	GetDlgItemText(IDC_COMBO1, num);
	year = GetDlgItemInt(IDC_COMBO5);
	month = GetDlgItemInt(IDC_COMBO6);
	sql.Format("\
		select month(req_date) from tb_req_leave \
		where req_emp = '%s' and year(req_date) = %d", num, year);
	CADOOperation ado;
	ado.OpenRecordset(sql);
	ado.DeleteItem(m_CurSel);
	ado.CloseRecorset();
	m_CurSel = -1;
	return ret;
}

void CLeaveList::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	*pResult = 0;
}

void CLeaveList::OnExport() 
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

void CLeaveList::ExportToWord(CString &file)
{
	CADOOperation ado;
	CString sql;
	CString num;
	int year, month;
	GetDlgItemText(IDC_COMBO1, num);
	year = GetDlgItemInt(IDC_COMBO5);
	month = GetDlgItemInt(IDC_COMBO6);
	sql.Format("\
		select tb_employee.employee_name as 姓名, tb_req_leave.req_emp as 编号, tb_req_leave.req_date as 申请日期, \
		tb_req_leave.req_res as 原因, tb_req_leave.req_frm as 日期从, req_to as 到, req_stl as 类型, \
		req_lng as 天数 from tb_req_leave, tb_employee \
		where tb_employee.employee_id = tb_req_leave.req_emp and tb_req_leave.req_emp = '%s'\
		and year(tb_req_leave.req_date) = %d and month(tb_req_leave.req_date) = %d", num, year, month);
	PRINTRESULT(sql);

	ado.OpenRecordset(sql);
	ado.ExportToWord(file);
	ado.CloseRecorset();
}
