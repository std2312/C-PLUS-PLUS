// DeptDutyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "DeptDutyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptDutyDlg dialog


CDeptDutyDlg::CDeptDutyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeptDutyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeptDutyDlg)
	//}}AFX_DATA_INIT
}


void CDeptDutyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeptDutyDlg)
	DDX_Control(pDX, IDC_LIST2, m_DutyList);
	DDX_Control(pDX, IDC_COMBO1, m_Dept);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeptDutyDlg, CDialog)
	//{{AFX_MSG_MAP(CDeptDutyDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_EDITDEPTINFO, OnEditdeptinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeptDutyDlg message handlers

BOOL CDeptDutyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CADOOperation dept;
	CString str;

	dept.OpenTable("tb_dept");
	if(dept.IsLastRow())
		return TRUE;
	dept.MoveFirst();
	do
	{
		dept.GetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &str);
		m_Dept.AddString(str);
		dept.MoveNext();
	}while(!dept.IsLastRow());

	m_Dept.SetCurSel(0);
	OnSelchangeCombo1() ;
	dept.CloseTable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CDeptDutyDlg::SetRow(int row, CString *strArray, int count)
{
	UpdateData();
	m_DutyList.AddString(*strArray);
	return TRUE;
}

BOOL CDeptDutyDlg::DeleteAllRows()
{
	m_DutyList.ResetContent();
	return TRUE;
}

void CDeptDutyDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CADOOperation duty;
	CString sql, table;
	CString fields[1] = {"duty_name"};

	m_Dept.GetWindowText(table);

	sql.Format("select duty_name from tb_dept_duty, \
		tb_dept where tb_dept.dept_name = '%s' and tb_dept.dept_id = tb_dept_duty.dept_id", table);
	duty.OpenRecordset(sql);
	duty.ShowADOView(fields, 1, this);
	duty.CloseRecorset();
}

void CDeptDutyDlg::OnEditdeptinfo() 
{
	// TODO: Add your control notification handler code here
	if(!G_IsLanded)
	{
		MessageBox("请登陆！");
		return ;
	}
	CDeptInfoDlg dlg;
	CString name;

	GetDlgItemText(IDC_COMBO1, name);
	if(name.IsEmpty())
	{
		MessageBox("没有可用的部门信息！");
		return ;
	}
	dlg.SetEditable(TRUE);
	dlg.SetDeptName(name);
	dlg.DoModal();
}
