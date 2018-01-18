// ReqChkList.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ReqChkList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReqChkList dialog


CReqChkList::CReqChkList(CWnd* pParent /*=NULL*/)
	: CDialog(CReqChkList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReqChkList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReqChkList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReqChkList)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReqChkList, CDialog)
	//{{AFX_MSG_MAP(CReqChkList)
	ON_BN_CLICKED(ID_EXPORT, OnExport)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_MESSAGE(UM_LISTEDIT_KILLFOCUS, OnListEditKillFocus)
	ON_MESSAGE(UM_LISTEDIT_DBCLICK, OnListEditDBClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReqChkList message handlers

BOOL CReqChkList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_List.InsertColumn(0, "考核日期", LVCFMT_LEFT, 75);
	m_List.InsertColumn(1, "编号", LVCFMT_LEFT, 60);
	m_List.InsertColumn(2, "姓名", LVCFMT_LEFT, 60);
	m_List.InsertColumn(3, "科目", LVCFMT_LEFT, 80);
	m_List.InsertColumn(4, "负责人", LVCFMT_LEFT, 60);
	m_List.InsertColumn(5, "类型", LVCFMT_LEFT, 80);
	m_List.InsertColumn(6, "考核意见", LVCFMT_LEFT, 80);

	ShowList((CString)"");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReqChkList::OnExport() 
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
BOOL CReqChkList::ExportToWord(CString &file)
{
	BOOL ret = TRUE;
	CADOOperation ado;
	ado.OpenRecordset("select tb_req_chk.chk_dte as 日期, tb_req_chk.chk_num as 编号, tb_applicant.applicant_name as 姓名, tb_req_chk.chk_sjt as 科目, \
				  tb_employee.employee_name as 负责人, tb_req_chk.chk_stl as 类型, tb_req_chk.chk_ade as 意见\
				  from tb_req_chk, tb_applicant, tb_employee\
				  where tb_req_chk.chk_num = tb_applicant.applicant_id and tb_req_chk.chk_pal = tb_employee.employee_id");
	ado.ExportToWord(file);
	ado.CloseRecorset();
	return ret;
}

BOOL CReqChkList::ShowList(CString &seaExp)
{
	BOOL ret = TRUE;
	CString sql;
	CADOOperation ado;
	CString field[] = {"chk_dte", "chk_num", "applicant_name", "chk_sjt", "employee_name", "chk_stl", "chk_ade"};
	if(seaExp.IsEmpty())
	sql.Format("\
				  select tb_req_chk.chk_dte, tb_req_chk.chk_num, tb_applicant.applicant_name, tb_req_chk.chk_sjt, \
				  tb_employee.employee_name, tb_req_chk.chk_stl, tb_req_chk.chk_ade \
				  from tb_req_chk, tb_applicant, tb_employee\
				  where tb_req_chk.chk_num = tb_applicant.applicant_id and tb_req_chk.chk_pal = tb_employee.employee_id");
	else
	sql.Format("\
				  select tb_req_chk.chk_dte, tb_req_chk.chk_num, tb_applicant.applicant_name, tb_req_chk.chk_sjt, \
				  tb_employee.employee_name, tb_req_chk.chk_stl, tb_req_chk.chk_ade \
				  from tb_req_chk, tb_applicant, tb_employee\
				  where tb_req_chk.chk_num = tb_applicant.applicant_id and tb_req_chk.chk_pal = tb_employee.employee_id \
				  and %s", seaExp);
	ado.OpenRecordset(sql);
	ado.ShowADOView(field, 7, this);
	ado.CloseRecorset();
	return ret;
}

BOOL CReqChkList::DeleteAllRows()
{
	m_List.DeleteAllItems();
	return TRUE;
}

BOOL CReqChkList::SetRow(int row, CString *strArray, int count)
{
	BOOL ret = TRUE;
	m_List.InsertItem(row, strArray[0]);
	for(int i=1; i<count; i++)
		m_List.SetItemText(row, i, strArray[i]);
	return ret;
}

BOOL CReqChkList::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CReqChkList::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	CReqSeachDlg dlg;
	CString str;
	dlg.DoModal();
	str = dlg.GetSearchExpression();
	ShowList(str);
}

LRESULT CReqChkList::OnListEditKillFocus(WPARAM wParam, LPARAM lParam)
{
	CADOOperation ado;
	CString str;
	if(2 == lParam)
	{
		CString sql;
		sql.Format("update tb_applicant set applicant_name = '%s' where applicant_id = '%s'",
			m_List.GetItemText(wParam, lParam), 
			m_List.GetItemText(wParam, 1));
		ado.OpenRecordset(sql);
	}
	else
	{
		CString sql;
		sql.Format("update tb_req_chk set chk_sjt = '%s', chk_stl = '%s', chk_ade = '%s' \
			where chk_num = '%s' and  chk_dte = '%s' ", m_List.GetItemText(wParam, 3), m_List.GetItemText(wParam, 5),
			m_List.GetItemText(wParam, 6),  m_List.GetItemText(wParam, 1), m_List.GetItemText(wParam, 0));
		PRINTRESULT(sql);
		ado.OpenRecordset(sql);
	}
	ado.CloseRecorset();
	return 0;
}

LRESULT CReqChkList::OnListEditDBClick(WPARAM wParam, LPARAM lParam)
{
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)wParam;
	if(!::G_IsLanded)
	{
		m_List.ShowEditBox(FALSE, lpnmlv->iItem, lpnmlv->iSubItem);
		return 0;
	}
	if(lpnmlv->iItem < 0 || lpnmlv->iSubItem < 2 || lpnmlv->iSubItem == 4)
	{
		m_List.ShowEditBox(FALSE, lpnmlv->iItem, lpnmlv->iSubItem);
		return 0;
	}
	return 0;
}
