// AddTest.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "AddTest.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddTest dialog


CAddTest::CAddTest(CWnd* pParent /*=NULL*/)
	: CDialog(CAddTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddTest)
	m_Question = _T("");
	m_Answer = _T("");
	m_AnswerA = _T("");
	m_AnswerB = _T("");
	m_AnswerC = _T("");
	m_AnswerD = _T("");
	m_Totle = _T("");
	//}}AFX_DATA_INIT
}


void CAddTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddTest)
	DDX_Control(pDX, IDC_SUBJECTCOMBO, m_SubjectCombo);
	DDX_Text(pDX, IDC_QUESTION, m_Question);
	DDX_Text(pDX, IDC_ANSWER, m_Answer);
	DDX_Text(pDX, IDC_EDITA, m_AnswerA);
	DDX_Text(pDX, IDC_EDITB, m_AnswerB);
	DDX_Text(pDX, IDC_EDITC, m_AnswerC);
	DDX_Text(pDX, IDC_EDITD, m_AnswerD);
	DDX_Text(pDX, IDC_TOTLE, m_Totle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddTest, CDialog)
	//{{AFX_MSG_MAP(CAddTest)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddTest message handlers

void CAddTest::OnButtonOk() 
{
	UpdateData();
	m_SubjectCombo.GetLBText(m_SubjectCombo.GetCurSel(),ComboText);
	if(m_AnswerA.IsEmpty()||m_AnswerB.IsEmpty()||m_AnswerC.IsEmpty()||m_AnswerD.IsEmpty())
	{
		AfxMessageBox("请输入答案选项");
		return;
	}
	if(m_Totle.IsEmpty())
	{
		AfxMessageBox("请输入分值");
		return;
	}
	if(m_Answer=="a"||m_Answer=="b"||m_Answer=="c"||m_Answer=="d")
	{
		AfxMessageBox("答案请用大写字母");
		return;
	}
	if(m_Answer.IsEmpty()||(m_Answer!='A'&&m_Answer!='B'&&m_Answer!='C'&&m_Answer!='D'))
	{
		AfxMessageBox("请输入正确答案");
		return;
	}

	CDialog::OnOK();
	
}

void CAddTest::OnOK()
{
	OnButtonOk();
}

BOOL CAddTest::OnInitDialog() 
{
	CDialog::OnInitDialog();
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CString sql="select * from subject";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		while(m_pRs->adoEOF==0)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("subjectname");
			m_SubjectCombo.AddString(str);
			m_pRs->MoveNext();
		}
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return false;
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddTest::OnButtonCancel() 
{
	CDialog::OnCancel();	
}
