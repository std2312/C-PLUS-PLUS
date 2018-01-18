// Ycxdlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Ycxdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYcxdlg dialog

extern CMyApp theApp;
CYcxdlg::CYcxdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYcxdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYcxdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CYcxdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYcxdlg)
	DDX_Control(pDX, IDC_COMBO_month, m_MonthCombo);
	DDX_Control(pDX, IDC_COMBO_year, m_YearCombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYcxdlg, CDialog)
	//{{AFX_MSG_MAP(CYcxdlg)
	ON_BN_CLICKED(IDC_BUTTON_CHAXUN, OnButtonChaxun)
	ON_BN_CLICKED(IDC_BUTTON_tuichu, OnBUTTONtuichu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYcxdlg message handlers

BOOL CYcxdlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString sql;
	CString str;
	sql="select distinct Year(ʱ��) as ��� from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("���");
		m_YearCombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Month(ʱ��) as �·� from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("�·�");
		m_MonthCombo.AddString(str);	
		m_pRs->MoveNext();
	}

	return true;
}

void CYcxdlg::OnButtonChaxun() 
{
	UpdateData();
	CString year,month,day,totle;
	double Mytotle=0;
	if(m_YearCombo.GetCurSel()==-1||m_MonthCombo.GetCurSel()==-1)
	{
		AfxMessageBox("��ѡ��һ��ʱ��");
		return;
	}
	m_YearCombo.GetLBText(m_YearCombo.GetCurSel(),year);
	m_MonthCombo.GetLBText(m_MonthCombo.GetCurSel(),month);
	CString sql="select * from shouru where Year(ʱ��)="+year+" and Month(ʱ��)="+month+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		totle=(char*)(_bstr_t)m_pRs->GetCollect("������");
		Mytotle+=atof(totle);
		m_pRs->MoveNext();
	}
	totle.Format("%.2lf",Mytotle);
	MessageBox(year+"��"+month+"�µ�����Ϊ��"+totle+"Ԫ","�������ѯ");	
}

void CYcxdlg::OnBUTTONtuichu() 
{
	CDialog::OnCancel();		
}

void CYcxdlg::OnOK()
{
	OnButtonChaxun();

}
