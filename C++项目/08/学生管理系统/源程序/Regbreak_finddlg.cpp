// Regbreak_finddlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Regbreak_finddlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegbreak_finddlg dialog


CRegbreak_finddlg::CRegbreak_finddlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegbreak_finddlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegbreak_finddlg)
	m_studentid = _T("");
	m_regresult = _T("");
	m_regmemo = _T("");
	m_regcontent = _T("");
	m_regdate = 0;
	//}}AFX_DATA_INIT
}


void CRegbreak_finddlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegbreak_finddlg)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Text(pDX, IDC_EDIT_studentid, m_studentid);
	DDX_Text(pDX, IDC_EDIT_reghandleresult, m_regresult);
	DDX_Text(pDX, IDC_EDIT_regmemo, m_regmemo);
	DDX_Text(pDX, IDC_EDIT_regcontent, m_regcontent);
	DDX_DateTimeCtrl(pDX, IDC_regfind_date, m_regdate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegbreak_finddlg, CDialog)
	//{{AFX_MSG_MAP(CRegbreak_finddlg)
	ON_BN_CLICKED(IDC_Btnfind_regbreakinfo, OnBtnfindregbreakinfo)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegbreak_finddlg message handlers

void CRegbreak_finddlg::OnBtnfindregbreakinfo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sqlStr;
	sqlStr="SELECT * FROM tb_regbreakinfo WHERE studentid='"+m_studentid+"'";
	myregbreakset_find = new CRegbrreakinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myregbreakset_find->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr))
	{
		AfxMessageBox("tb_regbreakinfo表打开失败!");
	}
	if(myregbreakset_find->GetRecordCount() == 0)
	{
		AfxMessageBox("此学生没有违规记录!");
		return;
	}
	DisplayRecord();
	if(myregbreakset_find->IsOpen())
	{
		myregbreakset_find->Close();
		delete myregbreakset_find;
	}
}
bool CRegbreak_finddlg::DisplayRecord()
{
   	if(myregbreakset_find->IsEOF() && myregbreakset_find->IsBOF())
	{
		m_studentid = "";
    	m_regresult = "";
	    m_regmemo   = "";
		GetCurrentTime(m_regdate);
    	m_regcontent = "";	
	}
	else
	{
		if(myregbreakset_find->IsBOF()) //移动到了开头,就向后移动
		{
			myregbreakset_find->MoveNext();
		}
		else //否则前移
		{
			if(myregbreakset_find->IsEOF())
			{
				myregbreakset_find->MovePrev();
			}
		}
	}
	
	CString regcontent;
	CString regresult;
	CString regmemo,regdate;
	CTime tDate;
	int i=0;
	while(!myregbreakset_find->IsEOF())
	{
		regcontent = myregbreakset_find->m_breakcontent;
        regresult  = myregbreakset_find->m_handleresult;
        regmemo    = myregbreakset_find->m_memo;
        tDate      = myregbreakset_find->m_breaktime;    
		regdate    = tDate.Format("%m/%d/%y"); 
		m_list2.InsertItem(i,regcontent.GetBuffer(50));
		m_list2.SetItemText(i,1,regresult.GetBuffer(50));
	    m_list2.SetItemText(i,2,regmemo.GetBuffer(50));	    
		regdate.Format("%d-%d-%d",myregbreakset_find->m_breaktime.GetYear(),
			myregbreakset_find->m_breaktime.GetMonth(),
			myregbreakset_find->m_breaktime.GetDay());
		m_list2.SetItemText(i,3,regdate.GetBuffer(50));
		myregbreakset_find->MoveNext();
		i++;
	}
	myregbreakset_find->MoveFirst();
	m_studentid  = myregbreakset_find->m_studentid;
    m_regresult  = myregbreakset_find->m_handleresult;
	m_regmemo    = myregbreakset_find->m_memo;
	m_regdate    = myregbreakset_find->m_breaktime;
    m_regcontent = myregbreakset_find->m_breakcontent;
	UpdateData(FALSE);//显示更新
	return TRUE;
}

void CRegbreak_finddlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnClose();
}

BOOL CRegbreak_finddlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_list2.InsertColumn(0,"违规内容");
	m_list2.InsertColumn(1,"处理结果");
	m_list2.InsertColumn(2,"备注");
	m_list2.InsertColumn(3,"时间");
	RECT rect;
	m_list2.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	m_list2.SetColumnWidth(0,wid/4);
	m_list2.SetColumnWidth(1,wid/4);
    m_list2.SetColumnWidth(2,wid/4);
	m_list2.SetColumnWidth(3,wid/4);	
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void CRegbreak_finddlg::OnOK()
{

}
