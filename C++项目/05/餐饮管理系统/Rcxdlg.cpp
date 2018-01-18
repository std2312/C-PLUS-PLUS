// Rcxdlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Rcxdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CRcxdlg dialog

extern CMyApp theApp;
CRcxdlg::CRcxdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRcxdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRcxdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRcxdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRcxdlg)
	DDX_Control(pDX, IDC_COMBO_day, m_Daycombo);
	DDX_Control(pDX, IDC_COMBO_month, m_Monthcombo);
	DDX_Control(pDX, IDC_COMBO_year, m_Yearcombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRcxdlg, CDialog)
	//{{AFX_MSG_MAP(CRcxdlg)
	ON_BN_CLICKED(IDC_BUTTON_CHAXUN, OnButtonChaxun)
	ON_BN_CLICKED(IDC_BUTTON_tuichu, OnBUTTONtuichu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRcxdlg message handlers

BOOL CRcxdlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString sql;
	CString str;
	sql="select distinct Year(ʱ��) as ��� from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("���");
		m_Yearcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Month(ʱ��) as �·� from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("�·�");
		m_Monthcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Day(ʱ��) as ���� from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("����");
		m_Daycombo.AddString(str);	
		m_pRs->MoveNext();
	}
	return true;
}

void CRcxdlg::OnButtonChaxun() 
{
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
	CString sql="select * from shouru where Year(ʱ��)="+year+" and Month(ʱ��)="+month+" and Day(ʱ��)="+day+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	totle=(char*)(_bstr_t)m_pRs->GetCollect("������");
	MessageBox(year+"��"+month+"��"+day+"�յ�����Ϊ��"+totle+"Ԫ","�������ѯ");	
}

void CRcxdlg::OnBUTTONtuichu() 
{
	CDialog::OnCancel();	
}

void CRcxdlg::OnOK()
{
	OnButtonChaxun(); 

}
