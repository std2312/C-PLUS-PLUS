// Daydlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Daydlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDaydlg dialog


CDaydlg::CDaydlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDaydlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDaydlg)
	m_Money = _T("");
	//}}AFX_DATA_INIT
}


void CDaydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDaydlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Day);
	DDX_Text(pDX, IDC_EDIT1, m_Money);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDaydlg, CDialog)
	//{{AFX_MSG_MAP(CDaydlg)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDaydlg message handlers

BOOL CDaydlg::OnInitDialog() 
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
	m_Day.SetTime(&time);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDaydlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
	CTime time;
	m_Day.GetTime(time);
	CString sql,m_Xsph;
	CString spbh[1000],spmc[1000];
	double sum=0;
	int num=0;
	double spdj[1000];
	sql.Format("select distinct SPBH,SPMC,SPDJ from CTXSYS.TB_SELL where TO_DATE(XSSJ)=\
		TO_DATE('%s','MMDDYYYY')",time.Format("%m%d%Y"));
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		spbh[num] = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH");
		m_Grid.InsertItem(num,"");
		m_Grid.SetItemText(num,0,spbh[num]);
		spmc[num] = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC");
		m_Grid.SetItemText(num,1,spmc[num]);
		spdj[num] = atoi((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDJ"));
		m_Grid.SetItemText(num,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDJ"));
		m_AdoConn.m_pRecordset->MoveNext();
		num++;
	}
	for(int j=0;j<num;j++)
	{
		sql.Format("select SUM(XSSL)AS ZSL from CTXSYS.TB_SELL\
			where TO_DATE(XSSJ)=TO_DATE('%s','MMDDYYYY') and SPBH='%s'",
			time.Format("%m%d%Y"),spbh[j]);	
		m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(!m_AdoConn.m_pRecordset->adoEOF)
		{
			int zsl = atoi((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ZSL"));
			m_Grid.SetItemText(j,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ZSL"));
			sum = sum + spdj[j]*zsl;
			sql.Format("select * from CTXSYS.TB_MONTH where MONTH='%s' and \
				SPBH='%s'",time.Format("%m月%Y年"),spbh[j]);	
			m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(!m_AdoConn.m_pRecordset->adoEOF)
			{
				sql.Format("update CTXSYS.TB_MONTH set XSSL=XSSL+%d where SPBH='%s' and \
					MONTH='%s'",zsl,spbh[j],time.Format("%m月%Y年"));
			}
			else
			{
				sql.Format("insert into CTXSYS.TB_MONTH(SPBH,SPMC,SPDJ,XSSL,MONTH)values('%s',\
					'%s',%0.2f,%d,'%s')",spbh[j],spmc[j],spdj[j],zsl,time.Format("%m月%Y年"));
			}
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		}
	}
	m_Money.Format("%0.2f",sum);
	m_AdoConn.ExitConnect();
	UpdateData(FALSE);
}
