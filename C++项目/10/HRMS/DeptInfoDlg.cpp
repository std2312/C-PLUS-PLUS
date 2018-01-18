// DeptInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "DeptInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptInfoDlg dialog


CDeptInfoDlg::CDeptInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeptInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeptInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_Enlarge = FALSE;
	m_CurSelItem  = -1;
	m_IsModify = FALSE;
}


void CDeptInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeptInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeptInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CDeptInfoDlg)
	ON_BN_CLICKED(IDC_DUTYLIST, OnDutylist)
	ON_BN_CLICKED(ID_APPEND, OnAppend)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeptInfoDlg message handlers

void CDeptInfoDlg::OnDutylist() 
{
	// TODO: Add your control notification handler code here
	if(m_Enlarge)
	{
		SetEnlarge(FALSE);
		m_Enlarge = FALSE;
		SetDlgItemText(IDC_DUTYLIST, ">>");
	}
	else
	{
		SetEnlarge(TRUE);
		m_Enlarge = TRUE;
		SetDlgItemText(IDC_DUTYLIST, "<<");
	}
}

BOOL CDeptInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_IsModify && !m_DeptName.IsEmpty())
	{
		ShowDeptInfo(m_DeptName);
		ShowDutyList();
		return TRUE;
	}
	RECT rcDlg, rcEdge;
	GetWindowRect(&rcDlg);
	GetDlgItem(IDC_EDGE)->GetWindowRect(&rcEdge);
	m_EnlargeWidth = rcDlg.right - rcEdge.left;
	SetEnlarge(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeptInfoDlg::SetEnlarge(BOOL isEnlarge)
{
	RECT rcDlg = {0};
	if(isEnlarge)
	{
		GetWindowRect(&rcDlg);
		rcDlg.right = rcDlg.right + m_EnlargeWidth;
		MoveWindow(&rcDlg);
	}
	else if(!isEnlarge)
	{
		GetWindowRect(&rcDlg);
		rcDlg.right = rcDlg.right - m_EnlargeWidth;
		MoveWindow(&rcDlg);
	}
}

void CDeptInfoDlg::OnAppend() 
{
	// TODO: Add your control notification handler code here
	if(m_IsModify)
	{
		if(SaveModify(m_DeptName))
			MessageBox("保存成功！");
		return ;
	}
	CADOOperation dbo;
	CString name, show, str;
	BOOL ret;

	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT3, show);
	if(name.IsEmpty())
	{
		MessageBox("请绐该部门取一个合适的名字！");
		return ;
	}
	if(show.IsEmpty())
	{
		MessageBox("请简要介绍一下您的部门！");
		return ;
	}
	dbo.OpenTable("tb_dept");
	dbo.AddNew();
	ret = dbo.SetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &name);
	if(!ret)
	{
		dbo.CloseTable();
		return ;
	}
	ret = dbo.SetItemContent("dept_show", CADOOperation::ADO_TYPE_STRING, &show);
	if(!ret)
	{
		dbo.CloseTable();
		return ;
	}
	ret = dbo.UpdateData();
	if(!ret)
	{
		dbo.CloseTable();
		return ;
	}

	dbo.CloseTable();
	ret = MessageBox("保存成功！\n是否为该部门添加职务？", "注意", MB_ICONQUESTION | MB_YESNO);
	if(IDYES == ret)
	{
		OnDutylist();
		return;
	}
	else if(ret = IDNO)
	{
		EndDialog(0);
		return ;
	}
}

DWORD CDeptInfoDlg::GetCurNum()
{
	DWORD num = 0;
	CADOOperation dbo;
	dbo.OpenRecordset("select max(dept_id) from tb_dept");
	num = (long)dbo.GetSubItem(0);
	dbo.CloseTable();

	return num;
}

void CDeptInfoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CADOOperation dbo;
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	if(str.IsEmpty())
	{
		MessageBox("部门名称不能为空！", "提示");
		return ;
	}
	DWORD curNum = GetCurNum();

	dbo.OpenTable("tb_dept_duty");
	dbo.AddNew();
	GetDlgItemText(IDC_EDIT4, str);
	if(str.IsEmpty())
	{
		MessageBox("职务不能为空！", "提示");
		return ;
	}
	dbo.SetItemContent("dept_id", CADOOperation::ADO_TYPE_INT, &curNum);
	dbo.SetItemContent("duty_name", CADOOperation::ADO_TYPE_STRING, &str);

	dbo.UpdateData();
	dbo.CloseTable();
	ShowDutyList();

	GetDlgItem(IDC_EDIT4)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT4))->SetSel(0, -1);
	
}

void CDeptInfoDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	CString str, sql;
	if(m_CurSelItem < 0)
	{
		MessageBox("请选择一个要删除的项！");
		m_CurSelItem = -1;
		return ;
	}
	((CListBox*)GetDlgItem(IDC_LIST2))->GetText(m_CurSelItem, str);
	CADOOperation duty;
	sql.Format("delete from tb_dept_duty where duty_name = '%s' ",str);
	try{
		duty.OpenRecordset(sql);
	}catch(_com_error e)
	{
		MessageBox(e.Description());
	}
	duty.CloseRecorset();

	ShowDutyList();
}

BOOL CDeptInfoDlg::SetRow(int row, CString *strArray, int count)
{
	CListBox * list;
	list = (CListBox *)GetDlgItem(IDC_LIST2);
	list->AddString(strArray->GetBuffer(0));
	return TRUE;
}

BOOL CDeptInfoDlg::DeleteAllRows()
{
	CListBox * list;
	list = (CListBox *)GetDlgItem(IDC_LIST2);
	list->ResetContent();
	return TRUE;
}

BOOL CDeptInfoDlg::ShowDutyList()
{
	CString sql, fields[1];
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	sql.Format("select duty_name from tb_dept_duty where dept_id = %d", CFileRecord::GetDeptNumber(str));

	CADOOperation duty;
	duty.OpenRecordset(sql);
	fields[0] = "duty_name";
 	duty.ShowADOView(fields, 1, this);
	duty.CloseRecorset();
	return TRUE;
}

void CDeptInfoDlg::OnSelchangeList2() 
{
	// TODO: Add your control notification handler code here
	m_CurSelItem  = ((CListBox *)GetDlgItem(IDC_LIST2))->GetCurSel();
}

void CDeptInfoDlg::SetEditable(BOOL isModify)
{
	m_IsModify = isModify;
}

void CDeptInfoDlg::SetDeptName(CString name)
{
	m_DeptName = name;
}

BOOL CDeptInfoDlg::ShowDeptInfo(CString name)
{
	CADOOperation dept;
	CString sql, buf;
	sql.Format("select dept_show from tb_dept where dept_name = '%s'", name);
	dept.OpenRecordset(sql);;
	SetDlgItemText(IDC_EDIT1, name);
	dept.GetItemContent("dept_show", CADOOperation::ADO_TYPE_STRING, &buf);
	SetDlgItemText(IDC_EDIT3, buf);
	dept.CloseRecorset();
	SetDlgItemText(ID_APPEND, "保存");

	return TRUE;
}

BOOL CDeptInfoDlg::SaveModify(CString name)
{
	CADOOperation dept;
	CString sql, str;
	sql.Format("select * from tb_dept where dept_name = '%s'", name);
	dept.OpenRecordset(sql);
	GetDlgItemText(IDC_EDIT1, str);
	dept.SetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &str);
	GetDlgItemText(IDC_EDIT3, str);
	dept.SetItemContent("dept_show", CADOOperation::ADO_TYPE_STRING, &str);
	dept.CloseRecorset();

	return TRUE;
}
