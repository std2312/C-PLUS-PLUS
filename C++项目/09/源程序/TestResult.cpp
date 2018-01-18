// TestResult.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "TestResult.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestResult dialog

extern CExamOnlineApp theApp;
CTestResult::CTestResult(CWnd* pParent /*=NULL*/)
	: CDialog(CTestResult::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestResult)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTestResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestResult)
	DDX_Control(pDX, IDC_RESULTLIST, m_ResultList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestResult, CDialog)
	//{{AFX_MSG_MAP(CTestResult)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestResult message handlers

BOOL CTestResult::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_ResultList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	m_ResultList.InsertColumn(0,"题号",LVCFMT_CENTER,200,0);
	m_ResultList.InsertColumn(1,"结果",LVCFMT_CENTER,200,1);
	m_AdoConn.OnInitADOConn();
	CString sql="select*from examminginfo";
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	int sum=0;
	while(m_pRs->adoEOF==0)
	{
		CString num=(char*)(_bstr_t)m_pRs->GetCollect("testnum");
		CString result=(char*)(_bstr_t)m_pRs->GetCollect("totle");
		m_ResultList.InsertItem(i,"");
		m_ResultList.SetItemText(i,0,num);
		if(result=='0')
			m_ResultList.SetItemText(i,1,"错误");
		else
			m_ResultList.SetItemText(i,1,"正确");
		i++;
		sum+=atoi(result);
		m_pRs->MoveNext();
	}
	CString str;
	str.Format("%d",sum);
	m_ResultList.InsertItem(i,"");
	m_ResultList.SetItemText(i,0,"总分:");
	m_ResultList.SetItemText(i,1,str+"分");
	CTime time;
	time=CTime::GetCurrentTime();
	CString Tstr=time.Format("%m月%d日%H:%M");
	sql="update result set closetime='"+Tstr+"',totle='"+str+"' where starttime='"+TimeStr+"'";
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConn();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestResult::OnCancel() 
{
	CString sql;
	sql.Format("delete from examminginfo");
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.m_pCon->Close();
	CDialog::OnCancel();
}
