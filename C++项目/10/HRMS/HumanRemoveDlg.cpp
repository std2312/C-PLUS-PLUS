// HumanRemoveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "HumanRemoveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHumanRemoveDlg dialog


CHumanRemoveDlg::CHumanRemoveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHumanRemoveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHumanRemoveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CHumanRemoveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHumanRemoveDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHumanRemoveDlg, CDialog)
	//{{AFX_MSG_MAP(CHumanRemoveDlg)
	ON_COMMAND(ID_DELITEM, OnDelitem)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_COMMAND(IDM_FIND, OnFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHumanRemoveDlg message handlers

BOOL CHumanRemoveDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_DELITEM));
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_ListCtrl.InsertColumn(0, "调动日期", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, "编号", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(2, "姓名", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(3, "原部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "原职位", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "现部门", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "现职位", LVCFMT_LEFT, 80);
	ShowList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CHumanRemoveDlg::ShowList()
{
	CADOOperation ado;
	CString fields[] = {"ch_date", "ch_employee", "employee_name", "ch_source", "ch_duty_source", "ch_destination",
		"ch_duty_Destination"};
	ado.OpenRecordset("\
						 select ch_date,tb_dept_change.ch_employee, tb_employee.employee_name,\
						 ch_source, ch_duty_source, ch_destination,  ch_duty_Destination\
						 from tb_dept_change,tb_employee\
						 where  tb_employee.employee_id = tb_dept_change.ch_employee");
	ado.ShowADOView(fields, 7, this);
	ado.CloseRecorset();
	return TRUE;
}

BOOL CHumanRemoveDlg::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

BOOL CHumanRemoveDlg::SetRow(int row, CString *strArray, int count)
{
	m_ListCtrl.InsertItem(row, strArray[0]);
	m_ListCtrl.SetItemText(row, 1, strArray[1]);
	m_ListCtrl.SetItemText(row, 2, strArray[2]);
	m_ListCtrl.SetItemText(row, 3,CFileRecord::GetDeptName(atoi(strArray[3])));
	m_ListCtrl.SetItemText(row, 4,CFileRecord::GetDutyName(atoi(strArray[4])));
	m_ListCtrl.SetItemText(row, 5,CFileRecord::GetDeptName(atoi(strArray[5])));
	m_ListCtrl.SetItemText(row, 6,CFileRecord::GetDutyName(atoi(strArray[6])));

	return TRUE;
}

BOOL CHumanRemoveDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CHumanRemoveDlg::OnDelitem() 
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
	ado.OpenTable("tb_dept_change");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	m_CurSel = -1;
	ShowList();
}

void CHumanRemoveDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
	*pResult = 0;
}

void CHumanRemoveDlg::OnFind() 
{
	// TODO: Add your command handler code here
	CFindDlg dlg;
	dlg.DoModal();
	CString str;
	str = dlg.GetSearchExpression();
	ShowList(str);
}

BOOL CHumanRemoveDlg::ShowList(CString &seaExp)
{
	CADOOperation ado;
	CString fields[] = {"ch_date", "ch_employee", "employee_name", "ch_source", "ch_duty_source", "ch_destination",
		"ch_duty_Destination"};
	CString sql;
	sql.Format("\
				  select ch_date,tb_dept_change.ch_employee, tb_employee.employee_name,\
						 ch_source, ch_duty_source, ch_destination,  ch_duty_Destination\
						 from tb_dept_change,tb_employee\
						 where  tb_employee.employee_id = tb_dept_change.ch_employee and %s", seaExp);
	ado.OpenRecordset(sql);
	ado.ShowADOView(fields, 7, this);
	ado.CloseRecorset();
	return TRUE;
}
