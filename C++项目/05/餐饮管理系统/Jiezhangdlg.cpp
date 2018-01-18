// Jiezhangdlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������.h"
#include "Jiezhangdlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiezhangdlg dialog

extern CMyApp theApp;
CJiezhangdlg::CJiezhangdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJiezhangdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJiezhangdlg)
	//}}AFX_DATA_INIT
}


void CJiezhangdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJiezhangdlg)
	DDX_Control(pDX, IDC_mingxi, m_MingXi);
	DDX_Control(pDX, IDC_zhaoling, m_ZhaoLing);
	DDX_Control(pDX, IDC_yingshou, m_YingShou);
	DDX_Control(pDX, IDC_shishou, m_ShiShou);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJiezhangdlg, CDialog)
	//{{AFX_MSG_MAP(CJiezhangdlg)
	ON_BN_CLICKED(IDC_BUTTON_OK2, OnButtonOk2)
	ON_BN_CLICKED(IDC_BUTTON_BYE, OnButtonBye)
	ON_EN_CHANGE(IDC_EDIT_shishou, OnChangeEDITshishou)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiezhangdlg message handlers

BOOL CJiezhangdlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_pay)),TRUE);
	CString TheValue;
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from TableUSE where TableUSEID=1"),NULL,adCmdText);
	if(m_pRs->GetRecordCount()==0)
		return true;
	if(m_pRs->GetRecordCount()==1)
	{
		TheValue=(char*)(_bstr_t)m_pRs->GetCollect("����");	
		m_Combo.AddString(TheValue);
		return true;
	}
	
	while(!m_pRs->adoEOF)
	{
		TheValue=(char*)(_bstr_t)m_pRs->GetCollect("����");		
		m_Combo.AddString(TheValue);
		m_pRs->MoveNext();
	}
	m_pRs=NULL;
	m_MingXi.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_MingXi.InsertColumn(0,"����",LVCFMT_LEFT,100,0);
	m_MingXi.InsertColumn(1,"����",LVCFMT_LEFT,100,1);
	m_MingXi.InsertColumn(2,"����(Ԫ)",LVCFMT_LEFT,120,1);
	res = FALSE;
	return true;


}


void CJiezhangdlg::OnButtonOk2() 
{
	UpdateData();
	CString str,str1,str2,str3;
	CString TheValue;
	CString ShiShou,YingShou;
	m_Combo.GetWindowText(str1);
	if(str1.GetLength()<4||str1.GetLength()>4)
	{
		AfxMessageBox("�������");
		return;
	}
	CString bjsql="select * from TableUSE where ����="+str1+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)bjsql,NULL,adCmdText);
	if(m_pRs->adoEOF)
	{
		AfxMessageBox("û����������");
		return;
	}
	CString bjstr=(char*)(_bstr_t)m_pRs->GetCollect("TableUSEID");
	if(bjstr=="0")
	{
		AfxMessageBox("��������Ҫ����");
		return;
	}
	m_ShiShou.GetWindowText(str3);
	if(str3.IsEmpty())
	{
		AfxMessageBox("������˿͸���");
		return;
	}
	if(res == TRUE)
		m_Combo.GetWindowText(str);
	else
		m_Combo.GetLBText(m_Combo.GetCurSel(),str);
	m_ZhaoLing.SetWindowText("");
	double zhaoling,rishouru=0;
	m_ShiShou.GetWindowText(ShiShou);
	m_YingShou.GetWindowText(YingShou);
	rishouru=atof(YingShou);
	if(atof(ShiShou)<atof(YingShou))
	{
		AfxMessageBox("��԰����ͣ�");
		return;
	}
	else
	{	
		CTime time;
		time = CTime::GetCurrentTime();
		CString str1 = time.Format("%Y-%m-%d");
		zhaoling=atof(ShiShou)-atof(YingShou);		
		TheValue=(char*)(_bstr_t)zhaoling;		
		m_ZhaoLing.SetWindowText(TheValue);
		UpdateData(false);
		CString sql;
		str2="update TableUSE set TableUSEID=0 where ����="+str+" ";
		theApp.m_pCon->Execute((_bstr_t)str2,NULL,adCmdText);
    	TheValue.Format("%0.2f",rishouru);
		sql="update shouru set ������=������+'"+TheValue+"' where ʱ��='"+str1+"'";
		theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
		m_YingShou.SetWindowText("");
		m_ShiShou.SetWindowText("");
		m_ZhaoLing.SetWindowText("");
		m_Combo.SetWindowText("");
		m_Combo.DeleteString(m_Combo.GetCurSel());
		m_MingXi.DeleteAllItems();
		sql="delete from paybill where ����="+str+"";
		theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
		AfxMessageBox("��ӭ����");					
	}

}

void CJiezhangdlg::OnButtonBye() 
{
	CDialog::OnCancel();
	
}



void CJiezhangdlg::OnChangeEDITshishou() 
{
	double zhaoling;
	CString ShiShou,YingShou;
	m_ShiShou.GetWindowText(ShiShou);
	m_YingShou.GetWindowText(YingShou);
	zhaoling = atof(ShiShou) - atof(YingShou);
	CString str;
	str.Format("%0.2f",zhaoling);
	m_ZhaoLing.SetWindowText(str);

}

void CJiezhangdlg::OnSelchangeCombo1() 
{
	UpdateData();
	CString str,sql,caiming,shuliang,xiaofei,xiaofeitotle,TheValue;
	double totle=0;
	m_Combo.GetLBText(m_Combo.GetCurSel(),str);
	sql="select * from paybill where ����="+str+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_MingXi.DeleteAllItems();
	while(m_pRs->adoEOF==0)
	{
		TheValue=(char*)(_bstr_t)m_pRs->GetCollect("����");
		totle+=atof(TheValue);
		caiming=(char*)(_bstr_t)m_pRs->GetCollect("����");
		shuliang=(char*)(_bstr_t)m_pRs->GetCollect("����");	
		xiaofei=(char*)(_bstr_t)m_pRs->GetCollect("����");
		m_MingXi.InsertItem(0,"");
		m_MingXi.SetItemText(0,0,caiming);
		m_MingXi.SetItemText(0,1,shuliang);
		m_MingXi.SetItemText(0,2,xiaofei);
		m_pRs->MoveNext();
	}
	xiaofeitotle=(char*)(_bstr_t)totle;
	m_YingShou.SetWindowText(xiaofeitotle);
	UpdateData(false);
}
void CJiezhangdlg::OnOK()
{
	OnButtonOk2();
}


void CJiezhangdlg::OnEditchangeCombo1() 
{
	m_MingXi.DeleteAllItems();
	m_YingShou.SetWindowText("");
	CString str;
	m_Combo.GetWindowText(str);
	if(str.GetLength()==4)
	{
		UpdateData();
		CString sql,caiming,shuliang,xiaofei,xiaofeitotle,TheValue;
		double totle=0;
		sql="select * from paybill where ����="+str+"";
		m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
		while(m_pRs->adoEOF==0)
		{
			TheValue=(char*)(_bstr_t)m_pRs->GetCollect("����");
			totle+=atof(TheValue);
			caiming=(char*)(_bstr_t)m_pRs->GetCollect("����");
			shuliang=(char*)(_bstr_t)m_pRs->GetCollect("����");	
			xiaofei=(char*)(_bstr_t)m_pRs->GetCollect("����");
			m_MingXi.InsertItem(0,"");
			m_MingXi.SetItemText(0,0,caiming);
			m_MingXi.SetItemText(0,1,shuliang);
			m_MingXi.SetItemText(0,2,xiaofei);
			m_pRs->MoveNext();
		}
		xiaofeitotle=(char*)(_bstr_t)totle;
		m_YingShou.SetWindowText(xiaofeitotle);
		res = TRUE;
		UpdateData(false);
	}
}

