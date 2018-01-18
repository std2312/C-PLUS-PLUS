// Depotbqdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Depotbqdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepotbqdlg dialog


CDepotbqdlg::CDepotbqdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepotbqdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepotbqdlg)
	m_Text = _T("");
	//}}AFX_DATA_INIT
}


void CDepotbqdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepotbqdlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepotbqdlg, CDialog)
	//{{AFX_MSG_MAP(CDepotbqdlg)
	ON_BN_CLICKED(IDC_BUTQUERY, OnButquery)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepotbqdlg message handlers

BOOL CDepotbqdlg::OnInitDialog() 
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
	m_Grid.InsertColumn(0,"商品编号",LVCFMT_LEFT,70,0); 
	m_Grid.InsertColumn(1,"商品名称",LVCFMT_LEFT,70,1); 
	m_Grid.InsertColumn(2,"商品进价",LVCFMT_LEFT,70,2); 
	m_Grid.InsertColumn(3,"退货数量",LVCFMT_LEFT,70,3); 
	m_Grid.InsertColumn(4,"退货时间",LVCFMT_LEFT,70,4); 
	m_Grid.InsertColumn(5,"供应商编号",LVCFMT_LEFT,70,5); 
	m_Grid.InsertColumn(6,"供应商名称",LVCFMT_LEFT,70,6); 
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from CTXSYS.TB_BDEPOTQ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJJ"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSL"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSJ"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
	m_Combo1.SetCurSel(0);
	m_Combo2.SetCurSel(5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDepotbqdlg::OnButquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString field,condition,sql;
	m_Combo2.GetWindowText(condition);
	switch(m_Combo1.GetCurSel())
	{
	case 0:
		field = "SPBH";
		break;
	case 1:
		field = "SPMC";
		break;
	case 2:
		field = "GYSBH";
		break;
	case 3:
		field = "GYSMC";
		break;
	}
	if(condition == "LIKE")
		sql.Format("select * from CTXSYS.TB_BDEPOTQ where %s %s '%s%s%s'",
			field,condition,"%",m_Text,"%");
	else
		sql.Format("select * from CTXSYS.TB_BDEPOTQ where %s %s '%s'",
			field,condition,m_Text);
	m_Grid.DeleteAllItems();
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJJ"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSL"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSJ"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}


void CDepotbqdlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	CString xsph = m_Grid.GetItemText(pos,0);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from CTXSYS.TB_BDEPOTQ where SPBH='%s'",xsph);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_Grid.DeleteAllItems();
	int i = 0;
	sql.Format("select * from CTXSYS.TB_BDEPOTQ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJJ"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSL"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THSJ"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}
