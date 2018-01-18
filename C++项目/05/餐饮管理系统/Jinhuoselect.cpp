// Jinhuoselect.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Jinhuoselect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJinhuoselect dialog

extern CMyApp theApp;
CJinhuoselect::CJinhuoselect(CWnd* pParent /*=NULL*/)
	: CDialog(CJinhuoselect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJinhuoselect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJinhuoselect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJinhuoselect)
	DDX_Control(pDX, IDC_LIST1, m_Jinhuoinfo);
	DDX_Control(pDX, IDC_COMBO_year, m_Yearcombo);
	DDX_Control(pDX, IDC_COMBO_month, m_Monthcombo);
	DDX_Control(pDX, IDC_COMBO_day, m_Daycombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJinhuoselect, CDialog)
	//{{AFX_MSG_MAP(CJinhuoselect)
	ON_BN_CLICKED(IDC_CHAXUN_BUTTON, OnChaxunButton)
	ON_BN_CLICKED(IDC_TUICHU_BUTTON, OnTuichuButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJinhuoselect message handlers

BOOL CJinhuoselect::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	CString sql;
	CString str;
	sql="select distinct Year(����ʱ��) as ��� from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("���");
		m_Yearcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Month(����ʱ��) as �·� from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("�·�");
		m_Monthcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Day(����ʱ��) as ���� from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("����");
		m_Daycombo.AddString(str);	
		m_pRs->MoveNext();
	}
	m_Jinhuoinfo.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_Jinhuoinfo.InsertColumn(0,"��Ʒ��",LVCFMT_LEFT,60,0);
	m_Jinhuoinfo.InsertColumn(1,"����(��)",LVCFMT_LEFT,80,1);
	m_Jinhuoinfo.InsertColumn(2,"�۸�(Ԫ)",LVCFMT_LEFT,80,2);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CJinhuoselect::OnChaxunButton() 
{	
	m_Jinhuoinfo.DeleteAllItems();
	UpdateData();
	CString year,month,day,totle;
	if(m_Yearcombo.GetCurSel()==-1||m_Monthcombo.GetCurSel()==-1||m_Daycombo.GetCurSel()==-1)
	{
		AfxMessageBox("��ѡ��һ��ʱ��");
		return;
	}
	m_Yearcombo.GetLBText(m_Yearcombo.GetCurSel(),year);
	m_Monthcombo.GetLBText(m_Monthcombo.GetCurSel(),month);
	m_Daycombo.GetLBText(m_Daycombo.GetCurSel(),day);
	CString sql="select * from jinhuoinfo where Year(����ʱ��)="+year+" and Month(����ʱ��)="+month+" and Day(����ʱ��)="+day+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		CString name,sum,price;
		name=(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ��");
		sum=(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ����");
		price=(char*)(_bstr_t)m_pRs->GetCollect("��Ʒ�۸�");
		m_Jinhuoinfo.InsertItem(0,"");
		m_Jinhuoinfo.SetItemText(0,0,name);
		m_Jinhuoinfo.SetItemText(0,1,sum);
		m_Jinhuoinfo.SetItemText(0,2,price);
		m_pRs->MoveNext();
	}
}

void CJinhuoselect::OnTuichuButton() 
{
	CDialog::OnCancel();	
}

void CJinhuoselect::OnOK()
{
	OnChaxunButton();
}
