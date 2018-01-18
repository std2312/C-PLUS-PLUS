// SpInfo.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "SpInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpInfo dialog

extern CMyApp theApp;
CSpInfo::CSpInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CSpInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpInfo)
	m_Name = _T("");
	m_Price = _T("");
	//}}AFX_DATA_INIT
}


void CSpInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpInfo)

	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT_name, m_Name);
	DDX_Text(pDX, IDC_EDIT_price, m_Price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpInfo, CDialog)
	//{{AFX_MSG_MAP(CSpInfo)
	ON_BN_CLICKED(IDC_BUTTON_add, OnBUTTONadd)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON_change, OnBUTTONchange)
	ON_BN_CLICKED(IDC_BUTTON_del, OnBUTTONdel)
	ON_BN_CLICKED(IDC_BUTTON_return, OnBUTTONreturn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpInfo message handlers

BOOL CSpInfo::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"��Ʒ��",LVCFMT_LEFT,100,0);
	m_Grid.InsertColumn(1,"��Ʒ����",LVCFMT_LEFT,100,1);
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shangpininfo"),NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ��"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ����"));
		m_pRs->MoveNext();
	}
	return true;



}

void CSpInfo::OnBUTTONadd() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��Ʒ������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("���۲���Ϊ��");
		return;
	}
	CString str="select * from shangpininfo where ��Ʒ��='"+m_Name+"'";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)str,NULL,adCmdText);
	if(!m_pRs->adoEOF)
	{
		AfxMessageBox("�Ѿ������ֻ�����");
		return;
	}
	CString sql="insert into shangpininfo(��Ʒ��,��Ʒ����)values('"+m_Name+"',"+m_Price+")";
	theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_Grid.DeleteAllItems();
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shangpininfo"),NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ��"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ����"));
		m_pRs->MoveNext();
	}	
	m_Name="";
	m_Price="";
	UpdateData(false);	
}

void CSpInfo::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i=m_Grid.GetSelectionMark();
	CString str=m_Grid.GetItemText(i,0);
	CString str1=m_Grid.GetItemText(i,1);
	m_Name=str;
	m_Price=str1;
	UpdateData(false);
	
	*pResult = 0;
}

void CSpInfo::OnBUTTONchange() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��Ʒ������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("���۲���Ϊ��");
		return;
	}
	CString str="update shangpininfo set ��Ʒ����="+m_Price+" where ��Ʒ��='"+m_Name+"'";
	theApp.m_pCon->Execute((_bstr_t)str,NULL,adCmdText);
	m_Grid.DeleteAllItems();
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shangpininfo"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{		
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ��"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ����"));
		m_pRs->MoveNext();
	}			
		m_Name="";
		m_Price="";
		UpdateData(false);	
}

void CSpInfo::OnBUTTONdel() 
{
	UpdateData();
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("��Ʒ������Ϊ��");
		return;
	}
	if(m_Price.IsEmpty())
	{
		AfxMessageBox("���۲���Ϊ��");
		return;
	}
	CString sql="delete from shangpininfo where ��Ʒ����="+m_Price+" and ��Ʒ��='"+m_Name+"'";
	theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_Grid.DeleteAllItems();
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shangpininfo"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{		
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ��"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ����"));
		m_pRs->MoveNext();			
		m_Name="";
		m_Price="";
		UpdateData(false);
	}
	
}

void CSpInfo::OnBUTTONreturn() 
{
	CDialog::OnCancel();	
	
}
