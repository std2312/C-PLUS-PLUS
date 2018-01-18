// Monthdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Monthdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonthdlg dialog


CMonthdlg::CMonthdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMonthdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonthdlg)
	m_Money = _T("");
	//}}AFX_DATA_INIT
}


void CMonthdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonthdlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Month);
	DDX_Text(pDX, IDC_EDIT1, m_Money);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonthdlg, CDialog)
	//{{AFX_MSG_MAP(CMonthdlg)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonthdlg message handlers

BOOL CMonthdlg::OnInitDialog() 
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
	m_Grid.InsertColumn(0,"商品编号",LVCFMT_LEFT,80,0); 
	m_Grid.InsertColumn(1,"商品名称",LVCFMT_LEFT,80,1); 
	m_Grid.InsertColumn(2,"商品单价",LVCFMT_LEFT,80,2); 
	m_Grid.InsertColumn(3,"销售数量",LVCFMT_LEFT,80,3); 
	CTime time = CTime::GetCurrentTime();
	m_Month.SetTime(&time);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMonthdlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
	CTime time;
	m_Month.GetTime(time);
	CString sql,m_Xsph;
	double sum=0,spdj[1000];
	int num=0;
	sql.Format("select * from CTXSYS.TB_MONTH where MONTH='%s'",time.Format("%m月%Y年"));
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(num,"");
		m_Grid.SetItemText(num,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(num,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		spdj[num] = atof((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDJ"));
		m_Grid.SetItemText(num,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDJ"));
		int xssl = atoi((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSSL"));
		m_Grid.SetItemText(num,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSSL"));
		m_AdoConn.m_pRecordset->MoveNext();
		sum = sum + spdj[num]*xssl;
		num++;
	}
	m_Money.Format("%0.2f",sum);
	m_AdoConn.ExitConnect();
	UpdateData(FALSE);
}
