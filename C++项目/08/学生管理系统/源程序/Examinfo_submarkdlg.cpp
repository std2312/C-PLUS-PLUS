// Examinfo_submarkdlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Examinfo_submarkdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkdlg dialog


CExaminfo_submarkdlg::CExaminfo_submarkdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExaminfo_submarkdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExaminfo_submarkdlg)
	m_studentid = _T("");
	m_submark = 0.0f;
	m_examsubject = _T("");
	m_examkind = _T("");
	m_examdate = 0;
	//}}AFX_DATA_INIT
}


void CExaminfo_submarkdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExaminfo_submarkdlg)
	DDX_Text(pDX, IDC_sutentid, m_studentid);
	DDX_Text(pDX, IDC_submarks, m_submark);
	DDX_Text(pDX, IDC_examsubject, m_examsubject);
	DDX_Text(pDX, IDC_examkind, m_examkind);
	DDX_DateTimeCtrl(pDX, IDC_examdate_picker, m_examdate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExaminfo_submarkdlg, CDialog)
	//{{AFX_MSG_MAP(CExaminfo_submarkdlg)
	ON_BN_CLICKED(IDC_inputsave_marks, Oninputsavemarks)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkdlg message handlers

void CExaminfo_submarkdlg::Oninputsavemarks() 
{

	UpdateData(TRUE); //读入输入的资料
	if(m_studentid.IsEmpty()||m_examsubject.IsEmpty()||m_examkind.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}

	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_studentinfo WHERE tb_studentinfo.studentid='"+m_studentid+"' ";
	myfindset_id = new CStudentinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myfindset_id->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_studentinfo表打开失败!");
	}
	if(myfindset_id->GetRecordCount()==0)
	{
		AfxMessageBox("没有此学生,请确认学号后再输入!");
    	
		if(myfindset_id->IsOpen())
		{
			myfindset_id->Close();
			delete myfindset_id;
		}
		return;
	}
	if(myfindset_id->IsOpen())
	{
		myfindset_id->Close();
		delete myfindset_id;
	}  
	CString sql;
	CString year,month,day;

	year = m_examdate.Format("%Y");
	month = m_examdate.Format("%m");
	day = m_examdate.Format("%d");
	sql.Format("SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.studentid\
		= '%s' and code = '%s' and kind = '%s' and  year(examdate) = '%s' and\
		month(examdate) = '%s' and day(examdate) = '%s'",m_studentid,
		m_examsubject,m_examkind,year,month,day);
	myexamsubmarkset_findsame = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myexamsubmarkset_findsame->Open(AFX_DB_USE_DEFAULT_TYPE,sql))
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	if(myexamsubmarkset_findsame->GetRecordCount()!=0)
	{
		AfxMessageBox("已经有此记录,不能重复输入!");
		if(myexamsubmarkset_findsame->IsOpen())
		{
	    	myexamsubmarkset_findsame->Close();
		}
		return;
	}
	if(myexamsubmarkset_findsame->IsOpen())
	{
	    myexamsubmarkset_findsame->Close();
		delete myexamsubmarkset_findsame;
	}
	myexamsubmarkset->AddNew();                  //调用添加记录的函数处理
	myexamsubmarkset->m_studentid = m_studentid; //对应变量更新
	myexamsubmarkset->m_code      = m_examsubject;
    myexamsubmarkset->m_grade     = m_submark;
    myexamsubmarkset->m_kind      = m_examkind;
	myexamsubmarkset->m_examdate  = m_examdate;
	myexamsubmarkset->Update();
	myexamsubmarkset->Requery();
	DisplayRecord(); //更新显示
}
bool CExaminfo_submarkdlg::DisplayRecord()
{
	if(myexamsubmarkset->IsEOF()&&myexamsubmarkset->IsBOF())
	{
		m_studentid   = "";
	    m_submark     = 0.0f;
	    m_examsubject = "";
	    m_examkind    = "";
	   		
	}
	else
	{
		if(myexamsubmarkset->IsBOF()) //移动到了开头,就向后移动
		{
			myexamsubmarkset->MoveNext();
		}
		else //否则前移
		{
			if(myexamsubmarkset->IsEOF())
			{
				myexamsubmarkset->MovePrev();
			}
		}
	}
    GetCurrentTime(m_examdate);
	m_studentid   = "";
	m_submark     = 0.0f;
	m_examsubject = "";
	m_examkind    = "";
	UpdateData(FALSE);//显示更新
	return TRUE;

}

BOOL CExaminfo_submarkdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString sqlStr;
	sqlStr = "SELECT * FROM tb_examinfo_sub"; 
	myexamsubmarkset = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myexamsubmarkset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	m_examdate = CTime::GetCurrentTime();
	UpdateData(FALSE);
	return TRUE; 
}

void CExaminfo_submarkdlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myexamsubmarkset->IsOpen())
	{
		myexamsubmarkset->Close();
		delete myexamsubmarkset;
	}
	CDialog::OnClose();
}

void CExaminfo_submarkdlg::OnOK()
{

}
