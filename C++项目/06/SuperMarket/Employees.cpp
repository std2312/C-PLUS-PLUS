// Employees.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Employees.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployees dialog


CEmployees::CEmployees(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployees::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployees)
	m_Ygbh = _T("");
	m_Ygxm = _T("");
	m_Ygxz = 0.0;
	m_Text = _T("");
	//}}AFX_DATA_INIT
}


void CEmployees::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployees)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_COMBO1, m_Ygxb);
	DDX_Control(pDX, IDC_COMBO2, m_Ygzw);
	DDX_Control(pDX, IDC_COMBO4, m_Combo4);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Text(pDX, IDC_EDIT1, m_Ygbh);
	DDX_Text(pDX, IDC_EDIT2, m_Ygxm);
	DDX_Text(pDX, IDC_EDIT3, m_Ygxz);
	DDX_Text(pDX, IDC_EDIT4, m_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployees, CDialog)
	//{{AFX_MSG_MAP(CEmployees)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_BN_CLICKED(IDC_BUTQUERY, OnButquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployees message handlers

BOOL CEmployees::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	//设置表头
	m_Grid.InsertColumn(0,"员工编号",LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"员工姓名",LVCFMT_LEFT,100,1); 
	m_Grid.InsertColumn(2,"员工性别",LVCFMT_LEFT,100,2); 
	m_Grid.InsertColumn(3,"员工职务",LVCFMT_LEFT,100,3); 
	m_Grid.InsertColumn(4,"员工薪资",LVCFMT_LEFT,100,4); 
	AddToGrid();
	m_Ygxb.SetCurSel(0);
	m_Ygzw.SetCurSel(0);
	m_Combo3.SetCurSel(0);
	m_Combo4.SetCurSel(5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEmployees::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from CTXSYS.TB_EMPLOYEES");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXM"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXB"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGZW"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXZ"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CEmployees::OnButadd() 
{
	// TODO: Add your control notification handler code here
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_EMPLOYEES");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		while(!m_AdoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGBH");
			m_AdoConn.m_pRecordset->MoveNext();
		}
		m_Ygbh.Format("YG%04d",atoi(ph.Right(4))+1);
	}
	else
		m_Ygbh.Format("YG0001");
	m_AdoConn.ExitConnect();
	m_Ygxm = "";
	m_Ygxb.SetCurSel(0);
	m_Ygzw.SetCurSel(0);
	m_Ygxz = 0;
	UpdateData(FALSE);
}

void CEmployees::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Ygxm.IsEmpty())
	{
		MessageBox("员工信息不能为空！");
		return;
	}
	CString ygxb,ygzw;
	m_Ygxb.GetWindowText(ygxb);
	m_Ygzw.GetWindowText(ygzw);
	CString sql;
	sql.Format("insert into CTXSYS.TB_EMPLOYEES(YGBH,YGXM,YGXB,YGZW,YGXZ)\
		values('%s','%s','%s','%s','%f')",m_Ygbh,m_Ygxm,ygxb,ygzw,m_Ygxz);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CEmployees::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Ygbh  = m_Grid.GetItemText(pos,0);
	m_Ygxm  = m_Grid.GetItemText(pos,1);
	m_Ygxb.SetWindowText(m_Grid.GetItemText(pos,2));
	m_Ygzw.SetWindowText(m_Grid.GetItemText(pos,3));
	m_Ygxz  = atof(m_Grid.GetItemText(pos,4));
	UpdateData(FALSE);
	*pResult = 0;
}

void CEmployees::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Ygxm.IsEmpty())
	{
		MessageBox("员工信息不能为空！");
		return;
	}
	CString ygxb,ygzw;
	m_Ygxb.GetWindowText(ygxb);
	m_Ygzw.GetWindowText(ygzw);
	CString sql;
	sql.Format("update CTXSYS.TB_EMPLOYEES set YGXM='%s',YGXB='%s',YGZW='%s',\
		YGXZ='%f' where YGBH='%s'",m_Ygxm,ygxb,ygzw,m_Ygxz,m_Ygbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CEmployees::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sql;
	sql.Format("delete from CTXSYS.TB_EMPLOYEES where YGBH='%s'",m_Ygbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CEmployees::OnButquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString field,condition,sql;
	m_Combo4.GetWindowText(condition);
	switch(m_Combo3.GetCurSel())
	{
	case 0:
		field = "YGBH";
		break;
	case 1:
		field = "YGXM";
		break;
	case 2:
		field = "YGXB";
		break;
	case 3:
		field = "YGZW";
		break;
	}
	if(condition=="LIKE")
		sql.Format("select * from CTXSYS.TB_EMPLOYEES where %s %s '%s%s%s'",
			field,condition,"%",m_Text,"%");
	else
		sql.Format("select * from CTXSYS.TB_EMPLOYEES where %s %s '%s'",
			field,condition,m_Text);
	m_Grid.DeleteAllItems();
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXM"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXB"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGZW"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("YGXZ"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}
