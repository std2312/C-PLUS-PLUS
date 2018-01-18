// Providedlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Providedlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg dialog


CProvidedlg::CProvidedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProvidedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProvidedlg)
	m_Gysbh = _T("");
	m_Gysmc = _T("");
	m_Gysjc = _T("");
	m_Gysdz = _T("");
	m_Lxr = _T("");
	m_Gysdh = _T("");
	m_Gyscz = _T("");
	m_Text = _T("");
	//}}AFX_DATA_INIT
}


void CProvidedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProvidedlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Text(pDX, IDC_EDIT1, m_Gysbh);
	DDX_Text(pDX, IDC_EDIT2, m_Gysmc);
	DDX_Text(pDX, IDC_EDIT3, m_Gysjc);
	DDX_Text(pDX, IDC_EDIT4, m_Gysdz);
	DDX_Text(pDX, IDC_EDIT5, m_Lxr);
	DDX_Text(pDX, IDC_EDIT6, m_Gysdh);
	DDX_Text(pDX, IDC_EDIT7, m_Gyscz);
	DDX_Text(pDX, IDC_EDIT8, m_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProvidedlg, CDialog)
	//{{AFX_MSG_MAP(CProvidedlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTQUERY, OnButquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg message handlers

BOOL CProvidedlg::OnInitDialog() 
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
	m_Grid.InsertColumn(0,"供应商编号",LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"供应商名称",LVCFMT_LEFT,100,1); 
	m_Grid.InsertColumn(2,"供应商简称",LVCFMT_LEFT,100,2); 
	m_Grid.InsertColumn(3,"供应商地址",LVCFMT_LEFT,100,3); 
	m_Grid.InsertColumn(4,"联系人",LVCFMT_LEFT,100,4); 
	m_Grid.InsertColumn(5,"供应商电话",LVCFMT_LEFT,100,5); 
	m_Grid.InsertColumn(6,"供应商传真",LVCFMT_LEFT,100,6); 
	AddToGrid();
	m_Combo1.SetCurSel(0);
	m_Combo2.SetCurSel(5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProvidedlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_PROVIDE");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		while(!m_AdoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH");
			m_AdoConn.m_pRecordset->MoveNext();
		}
		m_Gysbh.Format("GYS%04d",atoi(ph.Right(4))+1);
	}
	else
		m_Gysbh.Format("GYS0001");
	m_AdoConn.ExitConnect();
	m_Gysmc = "";
	m_Gysjc = "";
	m_Gysdz = "";
	m_Lxr   = "";
	m_Gysdh = "";
	m_Gyscz = "";
	UpdateData(FALSE);
}

void CProvidedlg::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from CTXSYS.TB_PROVIDE");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSJC"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSDZ"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("LXR"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSDH"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSCZ"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CProvidedlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Gysmc.IsEmpty() || m_Gysjc.IsEmpty() || m_Gysdz.IsEmpty()
		|| m_Lxr.IsEmpty() || m_Gysdh.IsEmpty() || m_Gyscz.IsEmpty())
	{
		MessageBox("供应商信息不能为空！");
		return;
	}
	CString sql;
	sql.Format("insert into CTXSYS.TB_PROVIDE(GYSBH,GYSMC,GYSJC,GYSDZ,LXR,\
		GYSDH,GYSCZ)values('%s','%s','%s','%s','%s','%s',%s)",m_Gysbh,
		m_Gysmc,m_Gysjc,m_Gysdz,m_Lxr,m_Gysdh,m_Gyscz);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CProvidedlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Gysmc.IsEmpty() || m_Gysjc.IsEmpty() || m_Gysdz.IsEmpty()
		|| m_Lxr.IsEmpty() || m_Gysdh.IsEmpty() || m_Gyscz.IsEmpty())
	{
		MessageBox("供应商信息不能为空！");
		return;
	}
	CString sql;
	sql.Format("update CTXSYS.TB_PROVIDE set GYSMC='%s',GYSJC='%s',GYSDZ='%s',\
		LXR='%s',GYSDH='%s',GYSCZ=%s where GYSBH='%s'",m_Gysmc,m_Gysjc,m_Gysdz,
		m_Lxr,m_Gysdh,m_Gyscz,m_Gysbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CProvidedlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sql;
	sql.Format("delete from CTXSYS.TB_PROVIDE where GYSBH='%s'",m_Gysbh);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CProvidedlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Gysbh = m_Grid.GetItemText(pos,0);
	m_Gysmc = m_Grid.GetItemText(pos,1);
	m_Gysjc = m_Grid.GetItemText(pos,2);
	m_Gysdz = m_Grid.GetItemText(pos,3);
	m_Lxr   = m_Grid.GetItemText(pos,4);
	m_Gysdh = m_Grid.GetItemText(pos,5);
	m_Gyscz = m_Grid.GetItemText(pos,6);
	UpdateData(FALSE);
	*pResult = 0;
}

void CProvidedlg::OnButquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString field,condition,sql;
	m_Combo2.GetWindowText(condition);
	switch(m_Combo1.GetCurSel())
	{
	case 0:
		field = "GYSBH";
		break;
	case 1:
		field = "GYSMC";
		break;
	case 2:
		field = "GYSJC";
		break;
	}
	if(condition=="LIKE")
		sql.Format("select * from CTXSYS.TB_PROVIDE where %s %s '%s%s%s'",
			field,condition,"%",m_Text,"%");
	else
		sql.Format("select * from CTXSYS.TB_PROVIDE where %s %s '%s'",
			field,condition,m_Text);
	m_Grid.DeleteAllItems();
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSJC"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSDZ"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("LXR"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSDH"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSCZ"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}
