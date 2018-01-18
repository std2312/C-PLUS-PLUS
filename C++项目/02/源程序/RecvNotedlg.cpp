// RecvNotedlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "RecvNotedlg.h"
#include "ADOConn.h"
#include "Restoredlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecvNotedlg dialog


CRecvNotedlg::CRecvNotedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecvNotedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecvNotedlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRecvNotedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecvNotedlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecvNotedlg, CDialog)
	//{{AFX_MSG_MAP(CRecvNotedlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecvNotedlg message handlers

BOOL CRecvNotedlg::OnInitDialog() 
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
	m_Grid.InsertColumn(1,"发送人姓名",LVCFMT_LEFT,70,1); 
	m_Grid.InsertColumn(2,"发送人电话",LVCFMT_LEFT,100,2);
	m_Grid.InsertColumn(3,"信息内容",LVCFMT_LEFT,100,3);
	m_Grid.InsertColumn(4,"接收时间",LVCFMT_LEFT,100,4);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from tb_recvnote order by 接收时间 desc");
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("发送人姓名"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("发送人电话"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("信息内容"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("接收时间"));
		m_ADOConn.m_pRecordset->MoveNext();
		i++;
	}
	m_ADOConn.ExitConnect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRecvNotedlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRestoredlg dlg;
	int pos     = m_Grid.GetSelectionMark();
	dlg.m_Name  =  m_Grid.GetItemText(pos,1);
	dlg.m_Phone =  m_Grid.GetItemText(pos,2);
	dlg.m_Note  =  m_Grid.GetItemText(pos,3);
	dlg.m_Num   =  m_Grid.GetItemText(pos,0);
	dlg.DoModal();
	m_Grid.DeleteAllItems();
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from tb_recvnote order by 接收时间 desc");
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("编号"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("发送人姓名"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("发送人电话"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("信息内容"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("接收时间"));
		m_ADOConn.m_pRecordset->MoveNext();
		i++;
	}
	m_ADOConn.ExitConnect();
	*pResult = 0;
}

void CRecvNotedlg::OnOK()
{
}