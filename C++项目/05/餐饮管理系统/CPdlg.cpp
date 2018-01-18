// CPdlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "CPdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCPdlg dialog

extern CMyApp theApp;
CCPdlg::CCPdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPdlg)
	m_Name = _T("");
	m_Price = _T("");
	//}}AFX_DATA_INIT
}


void CCPdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPdlg)
	DDX_Control(pDX, IDC_LIST1, m_CpList);
	DDX_Text(pDX, IDC_EDIT_name, m_Name);
	DDX_Text(pDX, IDC_EDIT_price, m_Price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCPdlg, CDialog)
	//{{AFX_MSG_MAP(CCPdlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON_change, OnBUTTONchange)
	ON_BN_CLICKED(IDC_BUTTON_del, OnBUTTONdel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPdlg message handlers

BOOL CCPdlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_CpList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_CpList.InsertColumn(0,"����",LVCFMT_LEFT,100,0);
	m_CpList.InsertColumn(1,"�˼�(Ԫ)",LVCFMT_LEFT,100,1);
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from caishiinfo"),NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		m_CpList.InsertItem(0,"");
		m_CpList.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("����"));
		m_CpList.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("�˼�"));
		m_pRs->MoveNext();
	}
	return true;
}

void CCPdlg::OnButtonadd() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("�˼۲���Ϊ��");
		return;
	}

	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from caishiinfo where ����='"+m_Name+"'"),NULL,adCmdText);
	if(!m_pRs->adoEOF)
	{
		AfxMessageBox("�Ѿ����������");
		return;
	}
	else
	{
		CString sql="insert into caishiinfo (����,�˼�) values ('"+m_Name+"',"+m_Price+")";
		theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
		m_CpList.DeleteAllItems();
		m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from caishiinfo"),NULL,adCmdText);
		while(!m_pRs->adoEOF)
		{		
			m_CpList.InsertItem(0,"");
			m_CpList.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("����"));
			m_CpList.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("�˼�"));
			m_pRs->MoveNext();			
		}
		m_Name="";
		m_Price="";
		UpdateData(false);			
	}
}

void CCPdlg::OnButton2() 
{
	CDialog::OnCancel();	
}

void CCPdlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i=m_CpList.GetSelectionMark();
	CString str=m_CpList.GetItemText(i,0);
	CString str1=m_CpList.GetItemText(i,1);
	m_Name=str;
	m_Price=str1;
	UpdateData(false);
	*pResult = 0;
}

void CCPdlg::OnBUTTONchange() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("�˼۲���Ϊ��");
		return;
	}
	CString sql="update caishiinfo set �˼�="+m_Price+" where ����='"+m_Name+"'";
	theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_CpList.DeleteAllItems();
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from caishiinfo"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{		
		m_CpList.InsertItem(0,"");
		m_CpList.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("����"));
		m_CpList.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("�˼�"));
		m_pRs->MoveNext();	
	}
	m_Name="";
	m_Price="";
	UpdateData(false);	
}

void CCPdlg::OnBUTTONdel() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("�˼۲���Ϊ��");
		return;
	}
	CString sql="delete from caishiinfo where �˼�="+m_Price+" and ����='"+m_Name+"'";
	theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_CpList.DeleteAllItems();
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from caishiinfo"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{		
		m_CpList.InsertItem(0,"");
		m_CpList.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("����"));
		m_CpList.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("�˼�"));
		m_pRs->MoveNext();			
		m_Name="";
		m_Price="";
		UpdateData(false);
	}
	
}
