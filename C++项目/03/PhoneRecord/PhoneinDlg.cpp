// PhoneinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "PhoneinDlg.h"
#include "ADOConn.h"
#include "atlbase.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneinDlg dialog


CPhoneinDlg::CPhoneinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhoneinDlg)
	//}}AFX_DATA_INIT
}


void CPhoneinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhoneinDlg)
	DDX_Control(pDX, IDC_BUTQUERY, m_ButQuery);
	DDX_Control(pDX, IDC_COMBO2, m_Content);
	DDX_Control(pDX, IDC_COMBO1, m_Field);
	DDX_Control(pDX, IDC_BUTDIALUP, m_ButDialup);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPhoneinDlg, CDialog)
	//{{AFX_MSG_MAP(CPhoneinDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTDIALUP, OnButdialup)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_BN_CLICKED(IDC_BUTQUERY, OnButquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneinDlg message handlers

BOOL CPhoneinDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle( LVS_EX_FLATSB  //扁平风格显示滚动条
		| LVS_EX_FULLROWSELECT              //允许整行选中
		| LVS_EX_HEADERDRAGDROP             //允许整列拖动
		| LVS_EX_ONECLICKACTIVATE           //单击选中项
		| LVS_EX_GRIDLINES );               //画出网格线
	//设置表头
	m_Grid.InsertColumn(0,"客户名称",LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"来电号码",LVCFMT_LEFT,100,1); 
	m_Grid.InsertColumn(2,"来电时间",LVCFMT_LEFT,150,2);
	m_Grid.InsertColumn(3,"洽谈内容",LVCFMT_LEFT,150,3);
	AddToGrid();
	m_Field.AddString("客户名称");
	m_Field.AddString("来电号码");
	m_Field.AddString("来电时间");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPhoneinDlg::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_phonein ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("客户名称"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("来电号码"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("来电时间"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("洽谈内容"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CPhoneinDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	m_Content.ResetContent();
	CString str;
	m_Field.GetLBText(m_Field.GetCurSel(),str);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select %s from tb_phonein ",str);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	CComVariant a(0);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Content.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect(a));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
	m_Content.SetCurSel(0);
}

void CPhoneinDlg::OnButdialup() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Number = m_Grid.GetItemText(pos,1);
	if(m_Number.IsEmpty())
	{
		MessageBox("请选择来电记录");
		return;
	}
	CDialog::OnOK();
}

void CPhoneinDlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	if(pos < 0)
	{
		MessageBox("请选择来电记录");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_phonein where 客户名称 = '%s'",m_Grid.GetItemText(pos,0));
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CPhoneinDlg::OnButquery() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
	CString field,content;
	m_Field.GetLBText(m_Field.GetCurSel(),field);
	m_Content.GetWindowText(content);//.GetLBText(m_Content.GetCurSel(),content);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_phonein where %s like '%s%s%s'",field,"%",content,"%");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("客户名称"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("来电号码"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("来电时间"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("洽谈内容"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CPhoneinDlg::OnOK()
{
}