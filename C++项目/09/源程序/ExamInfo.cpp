// ExamInfo.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ExamInfo.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CExamOnlineApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CExamInfo dialog


CExamInfo::CExamInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CExamInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExamInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExamInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamInfo)
	DDX_Control(pDX, IDC_SUBJECTCOMBO, m_SubjectCombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamInfo, CDialog)
	//{{AFX_MSG_MAP(CExamInfo)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamInfo message handlers

BOOL CExamInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_AdoConn.OnInitADOConn();
	CString sql="select* from subject";
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_pRs->adoEOF==0)
	{
		CString subject=(char*)(_bstr_t)m_pRs->GetCollect("subjectname");
		m_SubjectCombo.AddString(subject);
		m_pRs->MoveNext();
	}
	m_AdoConn.ExitConn();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExamInfo::OnButtonOk() 
{
	UpdateData();
	if(m_SubjectCombo.GetCurSel()==-1)
	{
		AfxMessageBox("请选择科目");
		return;
	}
	int studentid=theApp.studentid;
	m_SubjectCombo.GetLBText(m_SubjectCombo.GetCurSel(),Subject);
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from result where studentid=%d and Subject='%s' ",studentid,Subject);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)
	{
		sql="select * from subject where subjectname='"+Subject+"'";
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		Sid=atoi((char*)(_bstr_t)m_pRs->GetCollect("subjectid"));
		sql.Format("select *from test where subjectid=%d order by testid",Sid);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		Question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		CDialog::OnOK();
	}
	else
		MessageBox("该考生以进行过本科目的考试");
	m_AdoConn.ExitConn();
		
}

void CExamInfo::OnButtonCancel() 
{
	CDialog::OnCancel();	
}

void CExamInfo::OnOK()
{
	OnButtonOk();
}
