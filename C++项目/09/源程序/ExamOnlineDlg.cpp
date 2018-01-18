// ExamOnlineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ExamOnlineDlg.h"
#include "ExamInfo.h"
#include "TestResult.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CExamOnlineApp theApp;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg dialog

CExamOnlineDlg::CExamOnlineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExamOnlineDlg::IDD, pParent)
{
	testnum=1;
	num = 0;
	//{{AFX_DATA_INIT(CExamOnlineDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamOnlineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamOnlineDlg)
	DDX_Control(pDX, IDC_STATIC1, m_Time);
	DDX_Control(pDX, IDC_TESTID, m_TestID);
	DDX_Control(pDX, IDC_TEST, m_Test);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExamOnlineDlg, CDialog)
	//{{AFX_MSG_MAP(CExamOnlineDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_RADIO_A, OnRadioA)
	ON_BN_CLICKED(IDC_RADIO_B, OnRadioB)
	ON_BN_CLICKED(IDC_RADIO_C, OnRadioC)
	ON_BN_CLICKED(IDC_RADIO_D, OnRadioD)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg message handlers

BOOL CExamOnlineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CExamInfo infodlg;
	CTime time;
	time=CTime::GetCurrentTime();
	if(infodlg.DoModal()==IDOK)
	{
		CString Subject=infodlg.Subject;	
		CString studentid;
		studentid.Format("%d",theApp.studentid);
		CTime time;
		time=CTime::GetCurrentTime();
		TimeStr=time.Format("%m月%d日%H:%M");		
		CString sql="insert into result(starttime,subject,studentid)values('"+TimeStr+"','"+Subject+"','"+studentid+"')";
		m_AdoConn.OnInitADOConn();
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		CString question=infodlg.Question;
		m_Test.SetWindowText(question);
		CString Id;
		Id.Format("题号:%d",testnum);
		m_TestID.SetWindowText(Id);
		Sid=infodlg.Sid;
		m_AdoConn.ExitConn();
		PutAnswer();
	}
	else
		CDialog::OnCancel();
	m_Time.SetWindowText(time.Format("%m月%d日%H:%M"));
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExamOnlineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExamOnlineDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExamOnlineDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExamOnlineDlg::PutAnswer()
{
	UpdateData();
	CString question;
	m_Test.GetWindowText(question);
	CString sql="select * from test where question='"+question+"'";
	m_AdoConn.OnInitADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");
	sql="select*from testanswer where testid="+testid+"";
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString A,B,C,D;
	A=(char*)(_bstr_t)m_pRs->GetCollect("AnswerA");
	B=(char*)(_bstr_t)m_pRs->GetCollect("AnswerB");
	C=(char*)(_bstr_t)m_pRs->GetCollect("AnswerC");
	D=(char*)(_bstr_t)m_pRs->GetCollect("AnswerD");
	GetDlgItem(IDC_RADIO_A)->SetWindowText("A  "+A);
	GetDlgItem(IDC_RADIO_B)->SetWindowText("B  "+B);
	GetDlgItem(IDC_RADIO_C)->SetWindowText("C  "+C);
	GetDlgItem(IDC_RADIO_D)->SetWindowText("D  "+D);
	m_AdoConn.ExitConn();

}

void CExamOnlineDlg::OnNext() 
{	
	UpdateData(); 
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	CString sql;
	CString question,answer;
	m_Test.GetWindowText(question);
	CString Id;
	Id.Format("题号:%d",testnum+1);
	m_AdoConn.OnInitADOConn();	
	sql.Format("select*from test where question='%s'",question);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");
	sql.Format("select * from examminginfo where testnum=%d",testnum+1);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)
	{
		sql.Format("select*from examminginfo where question='%s'",question);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)
		{
			if(Answer!='A'&&Answer!='B'&&Answer!='C'&&Answer!='D')
			{
				AfxMessageBox("请选择一个答案");
				return;		
			}
			SaveQuestion();
		}
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
		if(answer!=Answer)
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);	
		Answer='e';
		int tid=atoi(testid);
		sql.Format("select * from test where subjectid=%d and testid>%d order by testid",Sid,tid);	
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);	
		if(m_pRs->adoEOF)
		{
			CheckAnswer();
			m_AdoConn.ExitConn();
			if(MessageBox("考试结束,是否交卷?","提示",MB_YESNO)==IDYES)
			{
				CDialog::OnCancel();
				CTestResult dlg;
				dlg.TimeStr=TimeStr;
				dlg.DoModal();
			}
			else return;
		}
		else
		{
			question=(char*)(_bstr_t)m_pRs->GetCollect("question");		
			m_TestID.SetWindowText(Id);
			m_Test.SetWindowText(question);
			testnum++;
			PutAnswer();
		}
	}
	else
	{
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
		if(answer!=Answer)
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		testnum++;
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
		m_TestID.SetWindowText(Id);
		m_Test.SetWindowText(question);
		PutAnswer();		
		if(answer=='A')
		{
			m_checkA->SetCheck(true);		
			m_checkB->SetCheck(false);
			m_checkC->SetCheck(false);
			m_checkD->SetCheck(false);
		}
		if(answer=='B')
		{
			m_checkB->SetCheck(true);
			m_checkA->SetCheck(false);
			m_checkC->SetCheck(false);
			m_checkD->SetCheck(false);
		}
		if(answer=='C')
		{
			m_checkC->SetCheck(true);
			m_checkA->SetCheck(false);
			m_checkB->SetCheck(false);
			m_checkD->SetCheck(false);
		}
		if(answer=='D')
		{
			m_checkD->SetCheck(true);
			m_checkA->SetCheck(false);
			m_checkB->SetCheck(false);
			m_checkC->SetCheck(false);
		}
	}
}

void CExamOnlineDlg::OnBack() 
{
	UpdateData();
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	if(testnum==1)
	{
		AfxMessageBox("这已经是第一题了");
		return;
	}
	CString question;
	CString Id;
	CString answer;
	CString sql;
	m_Test.GetWindowText(question);
	m_AdoConn.OnInitADOConn();
	testnum--;	
	sql.Format("select * from ExammingInfo where testnum=%d",testnum);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);	
	question=(char*)(_bstr_t)m_pRs->GetCollect("question");
	answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
	Id.Format("题号:%d",testnum);
	m_TestID.SetWindowText(Id);
	m_Test.SetWindowText(question);
	PutAnswer();
	if(answer=='A')
	{
		m_checkA->SetCheck(true);		
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
	}
	if(answer=='B')
	{
		m_checkB->SetCheck(true);
		m_checkA->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
	}
	if(answer=='C')
	{
		m_checkC->SetCheck(true);
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkD->SetCheck(false);
	}
	if(answer=='D')
	{
		m_checkD->SetCheck(true);
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
	}

}

void CExamOnlineDlg::SaveQuestion()
{
	UpdateData();
	CString question;
	m_Test.GetWindowText(question);
	CString sql;
	sql.Format("insert into examminginfo(testnum,question,answer,studentid)values(%d,'%s','%s',%d)",testnum,question,Answer,theApp.studentid);
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
}

void CExamOnlineDlg::OnRadioA() 
{
	Answer='A';
	
}

void CExamOnlineDlg::OnRadioB() 
{
	Answer='B';
	
}

void CExamOnlineDlg::OnRadioC() 
{
	Answer='C';
	
}

void CExamOnlineDlg::OnRadioD() 
{
	Answer='D';
	
}
void CExamOnlineDlg::OnReset() 
{
	CString sql;
	sql.Format("delete from examminginfo");
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);	
	CDialog::OnCancel();
	CExamOnlineDlg dlg;
	dlg.DoModal();	
}

void CExamOnlineDlg::CheckAnswer()
{
	CString sql;
	sql.Format("select * from examminginfo");
	m_AdoConn.OnInitADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_pRs->adoEOF==0)
	{
		_RecordsetPtr m_prs;
		CString question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		CString answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
		sql.Format("select * from test where question='%s'",question);
		m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString rightanswer=(char*)(_bstr_t)m_prs->GetCollect("rightanswer");
		int totle=atoi((char*)(_bstr_t)m_prs->GetCollect("totle"));
		if(answer==rightanswer)
		{
			sql.Format("update examminginfo set totle=%d where question='%s'",totle,question);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		}
		m_pRs->MoveNext();
	}
}

void CExamOnlineDlg::OnCancel()
{
	CString sql;
	sql.Format("delete from examminginfo");
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.m_pCon->Close();
	CDialog::OnCancel();
}

void CExamOnlineDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	num++;
	if(num==3600)
		OnCancel();
	CDialog::OnTimer(nIDEvent);
}
