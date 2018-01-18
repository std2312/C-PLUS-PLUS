// Input_regbreakdlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Input_regbreakdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInput_regbreakdlg dialog


CInput_regbreakdlg::CInput_regbreakdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInput_regbreakdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInput_regbreakdlg)
	m_regstudentid = _T("");
	m_regresult = _T("");
	m_regmemo = _T("");
	m_regdate = 0;
	m_regcontent = _T("");
	//}}AFX_DATA_INIT
}


void CInput_regbreakdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInput_regbreakdlg)
	DDX_Text(pDX, IDC_regbreakstudentid, m_regstudentid);
	DDX_Text(pDX, IDC_regbreak_result, m_regresult);
	DDX_Text(pDX, IDC_regbreak_memo, m_regmemo);
	DDX_DateTimeCtrl(pDX, IDC_regbreak_date, m_regdate);
	DDX_Text(pDX, IDC_regbreak_content, m_regcontent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInput_regbreakdlg, CDialog)
	//{{AFX_MSG_MAP(CInput_regbreakdlg)
	ON_BN_CLICKED(IDC_Btn_inputregbreak, OnBtninputregbreak)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInput_regbreakdlg message handlers

BOOL CInput_regbreakdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString sqlStr;
	sqlStr="SELECT * FROM tb_regbreakinfo";
	myregbreakset = new CRegbrreakinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!myregbreakset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_regbreakinfo表打开失败!");
	}
	m_regdate = CTime::GetCurrentTime();
	UpdateData(FALSE);
	return TRUE;  
}
bool CInput_regbreakdlg::DisplayRecord()
{
	if(myregbreakset->IsEOF()&&myregbreakset->IsBOF())
	{
		m_regstudentid = "";
    	m_regresult    = "";
	    m_regmemo      = "";
    	m_regcontent   = "";	   		
	}
	else
	{
		if(myregbreakset->IsBOF()) //移动到了开头,就向后移动
		{
			myregbreakset->MoveNext();
		}
		else //否则前移
		{
			if(myregbreakset->IsEOF())
			{
				myregbreakset->MovePrev();
			}
		}
	}
	m_regstudentid = "";
	m_regresult    = "";
	m_regmemo      = "";
	m_regcontent   = "";
	UpdateData(FALSE);
	return TRUE;

}

void CInput_regbreakdlg::OnBtninputregbreak() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_regstudentid.IsEmpty()||m_regresult.IsEmpty()||m_regcontent.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_studentinfo WHERE tb_studentinfo.studentid\
		='"+m_regstudentid+"'";
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
		}
		return;
	}
	if(myfindset_id->IsOpen())
	{
		myfindset_id->Close();
		delete myfindset_id;
	}  
	//调用添加记录的函数处理
	myregbreakset->AddNew();                   
	myregbreakset->m_studentid    = m_regstudentid; //对应变量更新
	myregbreakset->m_breakcontent = m_regcontent;
    myregbreakset->m_memo         = m_regmemo;
    myregbreakset->m_handleresult = m_regresult;
    myregbreakset->m_breaktime    = m_regdate;
	myregbreakset->Update();
	myregbreakset->Requery();
	DisplayRecord(); //更新显示
}

void CInput_regbreakdlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myregbreakset->IsOpen())
	{
		myregbreakset->Close();
		delete myregbreakset;
	}
	CDialog::OnClose();
}

void CInput_regbreakdlg::OnOK()
{

}
