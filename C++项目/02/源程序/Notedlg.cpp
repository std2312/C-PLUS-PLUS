// Notedlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "Notedlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotedlg dialog


CNotedlg::CNotedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotedlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNotedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotedlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNotedlg, CDialog)
	//{{AFX_MSG_MAP(CNotedlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotedlg message handlers

BOOL CNotedlg::OnInitDialog() 
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
	m_Grid.InsertColumn(1,"常用短语",LVCFMT_LEFT,1000,1); 
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
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNotedlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Note  =  m_Grid.GetItemText(pos,1);
	CDialog::OnCancel();
	*pResult = 0;
}
