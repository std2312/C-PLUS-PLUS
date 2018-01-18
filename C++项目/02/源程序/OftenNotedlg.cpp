// OftenNotedlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "OftenNotedlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COftenNotedlg dialog


COftenNotedlg::COftenNotedlg(CWnd* pParent /*=NULL*/)
	: CDialog(COftenNotedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COftenNotedlg)
	m_Note = _T("");
	//}}AFX_DATA_INIT
}


void COftenNotedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COftenNotedlg)
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Note);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COftenNotedlg, CDialog)
	//{{AFX_MSG_MAP(COftenNotedlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COftenNotedlg message handlers

void COftenNotedlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Note.IsEmpty())
	{
		MessageBox("常用短语不能为空！");
		return;
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_note (常用短语) values ('%s')",m_Note);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	m_Note = "";
	UpdateData(FALSE);
}

void COftenNotedlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_ID<0)
	{
		MessageBox("请在列表中选择常用短语！");
		return;
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_note set 常用短语='%s' where 编号=%d",m_Note,m_ID);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	m_ID = -1;
}

void COftenNotedlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	if(m_ID < 0)
	{
		MessageBox("请在列表中选择常用短语！");
		return;
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_note where 编号=%d",m_ID);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	m_ID = -1;
}

BOOL COftenNotedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"编号",LVCFMT_LEFT,70,0); //设置表头
	m_Grid.InsertColumn(1,"常用短语",LVCFMT_LEFT,330,1); 
	AddToGrid();
	m_ID = -1;
	
	m_ButAdd.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTADD1))); //设置位图
	m_ButAdd.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD1)));
	m_ButMod.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTMOD1))); //设置位图
	m_ButMod.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD1)));
	m_ButDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTDEL1))); //设置位图
	m_ButDel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COftenNotedlg::AddToGrid()
{
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from tb_note");
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("常用短语"));
		m_ADOConn.m_pRecordset->MoveNext();
		i++;
	}
	m_ADOConn.ExitConnect();
}

void COftenNotedlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_ID    = atoi(m_Grid.GetItemText(pos,0));
	m_Note  = m_Grid.GetItemText(pos,1);
	UpdateData(FALSE);
	*pResult = 0;
}

void COftenNotedlg::OnOK()
{
}


