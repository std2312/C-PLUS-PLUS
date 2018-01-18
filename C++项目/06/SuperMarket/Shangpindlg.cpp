// Shangpindlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Shangpindlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShangpindlg dialog


CShangpindlg::CShangpindlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShangpindlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShangpindlg)
	m_Spbh = _T("");
	m_Spmc = _T("");
	m_Spjm = _T("");
	m_Splb = _T("");
	m_Spdw = _T("");
	m_Txm = _T("");
	m_Jhjg = 0.0;
	m_Xsjg = 0.0;
	m_Text = _T("");
	//}}AFX_DATA_INIT
}


void CShangpindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShangpindlg)
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Spbh);
	DDX_Text(pDX, IDC_EDIT2, m_Spmc);
	DDX_Text(pDX, IDC_EDIT3, m_Spjm);
	DDX_Text(pDX, IDC_EDIT4, m_Splb);
	DDX_Text(pDX, IDC_EDIT5, m_Spdw);
	DDX_Text(pDX, IDC_EDIT6, m_Txm);
	DDX_Text(pDX, IDC_EDIT8, m_Jhjg);
	DDX_Text(pDX, IDC_EDIT9, m_Xsjg);
	DDX_Text(pDX, IDC_EDIT10, m_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShangpindlg, CDialog)
	//{{AFX_MSG_MAP(CShangpindlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTQUERY, OnButquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShangpindlg message handlers

void CShangpindlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_SHANGPIN");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		while(!m_AdoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH");
			m_AdoConn.m_pRecordset->MoveNext();
		}
		m_Spbh.Format("SP%04d",atoi(ph.Right(4))+1);
	}
	else
		m_Spbh.Format("SP0001");
	m_AdoConn.ExitConnect();
	m_Spmc = "";
	m_Spjm = "";
	m_Splb = "";
	m_Spdw = "";
	m_Txm  = "";
	m_Jhjg = 0;
	m_Xsjg = 0;
	UpdateData(FALSE);
}

void CShangpindlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Spmc.IsEmpty() || m_Spjm.IsEmpty() || m_Splb.IsEmpty()
		|| m_Spdw.IsEmpty() || m_Txm.IsEmpty())
	{
		MessageBox("商品信息不能为空！");
		return;
	}
	CString sql;
	sql.Format("update CTXSYS.TB_SHANGPIN set SPMC='%s',SPJM='%s',SPLB='%s',\
		SPDW='%s',TXM='%s',JHJG=%f,XSJG=%f where SPBH='%s'",m_Spmc,m_Spjm,
		m_Splb,m_Spdw,m_Txm,m_Jhjg,m_Xsjg,m_Spbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CShangpindlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Spmc.IsEmpty() || m_Spjm.IsEmpty() || m_Splb.IsEmpty()
		|| m_Spdw.IsEmpty() || m_Txm.IsEmpty())
	{
		MessageBox("商品信息不能为空！");
		return;
	}
	CString sql;
	sql.Format("insert into CTXSYS.TB_SHANGPIN(SPBH,SPMC,SPJM,SPLB,SPDW,TXM,\
		JHJG,XSJG)values('%s','%s','%s','%s','%s','%s',%f,%f)",m_Spbh,m_Spmc,
		m_Spjm,m_Splb,m_Spdw,m_Txm,m_Jhjg,m_Xsjg);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

BOOL CShangpindlg::OnInitDialog() 
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
	m_Grid.InsertColumn(2,"商品简码",LVCFMT_LEFT,70,2); 
	m_Grid.InsertColumn(3,"商品类别",LVCFMT_LEFT,70,3); 
	m_Grid.InsertColumn(4,"商品单位",LVCFMT_LEFT,70,4); 
	m_Grid.InsertColumn(5,"条形码",LVCFMT_LEFT,70,5); 
	m_Grid.InsertColumn(6,"进货价格",LVCFMT_LEFT,70,6); 
	m_Grid.InsertColumn(7,"销售价格",LVCFMT_LEFT,70,7); 
	AddToGrid();
	m_Combo1.SetCurSel(0);
	m_Combo2.SetCurSel(5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShangpindlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sql;
	sql.Format("delete from CTXSYS.TB_SHANGPIN where SPBH='%s'",m_Spbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	sql.Format("select * from CTXSYS.TB_DEPOT where SPBH='%s'",m_Spbh);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		MessageBox("请先删除库存表中的信息");
	}
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CShangpindlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Spbh  = m_Grid.GetItemText(pos,0);
	m_Spmc  = m_Grid.GetItemText(pos,1);
	m_Spjm  = m_Grid.GetItemText(pos,2);
	m_Splb  = m_Grid.GetItemText(pos,3);
	m_Spdw  = m_Grid.GetItemText(pos,4);
	m_Txm   = m_Grid.GetItemText(pos,5);
	m_Jhjg  = atof(m_Grid.GetItemText(pos,6));
	m_Xsjg  = atof(m_Grid.GetItemText(pos,7));
	UpdateData(FALSE);
	*pResult = 0;
}

void CShangpindlg::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from CTXSYS.TB_SHANGPIN");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJM"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPLB"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDW"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("TXM"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("JHJG"));
		m_Grid.SetItemText(i,7,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSJG"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CShangpindlg::OnButquery() 
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
		field = "SPJM";
		break;
	case 3:
		field = "SPLB";
		break;
	}
	if(condition=="LIKE")
		sql.Format("select * from CTXSYS.TB_SHANGPIN where %s %s '%s%s%s'",
			field,condition,"%",m_Text,"%");
	else
		sql.Format("select * from CTXSYS.TB_SHANGPIN where %s %s '%s'",
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
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJM"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPLB"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDW"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("TXM"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("JHJG"));
		m_Grid.SetItemText(i,7,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSJG"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}
