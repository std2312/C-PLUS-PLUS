// TestChange.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "TestChange.h"
#include "TextManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestChange dialog


CTestChange::CTestChange(CWnd* pParent /*=NULL*/)
	: CDialog(CTestChange::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestChange)
	m_Question = _T("");
	m_Answer = _T("");
	//}}AFX_DATA_INIT
}


void CTestChange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestChange)
	DDX_Text(pDX, IDC_QUESTION, m_Question);
	DDX_Text(pDX, IDC_ANSWER, m_Answer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestChange, CDialog)
	//{{AFX_MSG_MAP(CTestChange)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestChange message handlers



void CTestChange::OnOk() 
{
	UpdateData();
	if(m_Answer=="a"||m_Answer=="b"||m_Answer=="c"||m_Answer=="d")
	{
		AfxMessageBox("´ð°¸ÇëÓÃ´óÐ´×ÖÄ¸");
		return;
	}
	if(m_Answer.IsEmpty()||(m_Answer!='A'&&m_Answer!='B'&&m_Answer!='C'&&m_Answer!='D'))
	{
		AfxMessageBox("ÇëÊäÈëÕýÈ·´ð°¸");
		return;
	}
	CString sql;
	sql.Format("update test set question='%s',rightanswer='%s' where testid=%d",m_Question,m_Answer,testid);
	try
	{
		m_AdoConn.OnInitADOConn();
		m_AdoConn.ExecuteSQL((_bstr_t)sql);				
	}
	catch(...)
	{
		AfxMessageBox("²Ù×÷Ê§°Ü");
		return;
	}
	CDialog::OnOK();
}

BOOL CTestChange::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString sql="select * from test where question='"+m_Question+"'";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		testid=atoi((char*)(_bstr_t)m_pRs->GetCollect("testid"));
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("²Ù×÷Ê§°Ü");
		return false;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestChange::OnOK()
{
	OnOk();
}
