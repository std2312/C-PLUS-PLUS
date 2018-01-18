// Bookdlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "Bookdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookdlg dialog


CBookdlg::CBookdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBookdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookdlg)
	DDX_Control(pDX, IDC_BUTTONDUTY, m_ButDuty);
	DDX_Control(pDX, IDC_BUTTONDEP, m_ButDep);
	DDX_Control(pDX, IDC_BUTTONALL, m_ButAll);
	DDX_Control(pDX, IDC_COMBO2, m_Duty);
	DDX_Control(pDX, IDC_COMBO1, m_Dep);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookdlg, CDialog)
	//{{AFX_MSG_MAP(CBookdlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTONDEP, OnButtondep)
	ON_BN_CLICKED(IDC_BUTTONDUTY, OnButtonduty)
	ON_BN_CLICKED(IDC_BUTTONALL, OnButtonall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookdlg message handlers

BOOL CBookdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"编号",LVCFMT_LEFT,40,0); //设置表头
	m_Grid.InsertColumn(1,"姓名",LVCFMT_LEFT,50,1); 
	m_Grid.InsertColumn(2,"性别",LVCFMT_LEFT,40,2);
	m_Grid.InsertColumn(3,"职务",LVCFMT_LEFT,40,3);
	m_Grid.InsertColumn(4,"部门",LVCFMT_LEFT,50,4);
	m_Grid.InsertColumn(5,"电话",LVCFMT_LEFT,100,5);
	m_Num = 0;
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from tb_phonebook");
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("姓名"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("性别"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("职务"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("所在部门"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("电话号码"));
		m_ADOConn.m_pRecordset->MoveNext();
		i++;
	}
	m_ADOConn.ExitConnect();

	m_ButDep.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTDEP1))); //设置位图
	m_ButDep.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEP2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEP1)));
	m_ButDuty.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTDUTY1))); //设置位图
	m_ButDuty.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDUTY2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDUTY1)));
	m_ButAll.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTALL1))); //设置位图
	m_ButAll.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTALL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTALL1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBookdlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_Num = 1;
	int pos = m_Grid.GetSelectionMark();
	m_ID[0]    = m_Grid.GetItemText(pos,0);
	m_Name[0]  = m_Grid.GetItemText(pos,1);
	m_Phone[0] = m_Grid.GetItemText(pos,5);
	CDialog::OnCancel();
	*pResult = 0;
}

void CBookdlg::OnButtondep() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_Dep.GetLBText(m_Dep.GetCurSel(),str);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_phonebook where 所在部门 = '%s'",str);
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_ID[m_Num]    = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号");
		m_Name[m_Num]  = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("姓名");
		m_Phone[m_Num] = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("电话号码");
		m_ADOConn.m_pRecordset->MoveNext();
		m_Num++;
	}
	m_ADOConn.ExitConnect();
	CDialog::OnCancel();
}

void CBookdlg::OnButtonduty() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_Duty.GetLBText(m_Duty.GetCurSel(),str);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_phonebook where 职务 = '%s'",str);
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_ID[m_Num]    = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号");
		m_Name[m_Num]  = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("姓名");
		m_Phone[m_Num] = (char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("电话号码");
		m_ADOConn.m_pRecordset->MoveNext();
		m_Num++;
	}
	m_ADOConn.ExitConnect();
	CDialog::OnCancel();
}

void CBookdlg::OnButtonall() 
{
	// TODO: Add your control notification handler code here
	m_Num = m_Grid.GetItemCount();
	for(int i=0;i<m_Num;i++)
	{
		m_ID[i]    = m_Grid.GetItemText(i,0);
		m_Name[i]  = m_Grid.GetItemText(i,1);
		m_Phone[i] = m_Grid.GetItemText(i,5);
	}
	CDialog::OnCancel();
}
