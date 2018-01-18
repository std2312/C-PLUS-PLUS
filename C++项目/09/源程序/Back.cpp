// Back.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "Back.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBack dialog


CBack::CBack(CWnd* pParent /*=NULL*/)
	: CDialog(CBack::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBack)
	sqlmanagedlg=new CSQLManage;
	resultselectdlg=new CResultSelect;
	testmanagedlg=new CTextManage;
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBack)
	DDX_Control(pDX, IDC_BackTab, m_BackTab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBack, CDialog)
	//{{AFX_MSG_MAP(CBack)
	ON_NOTIFY(TCN_SELCHANGE, IDC_BackTab, OnSelchangeBackTab)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBack message handlers

BOOL CBack::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	m_BackTab.InsertItem(0,"试题管理"); 
	m_BackTab.InsertItem(1,"学生成绩查询");
	m_BackTab.InsertItem(2,"数据库管理");
	m_BackTab.SetCurSel(0);
	CRect rect;
	m_BackTab.GetClientRect(rect);
	rect.DeflateRect(1,30,2,2);
	testmanagedlg->Create(IDD_TEXTMANAGE,&m_BackTab);
	resultselectdlg->Create(IDD_RESULTSELECT,&m_BackTab);
	sqlmanagedlg->Create(IDD_SQLMANAGE,&m_BackTab);
	testmanagedlg->MoveWindow(rect);
	testmanagedlg->ShowWindow(SW_SHOW);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBack::OnSelchangeBackTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CRect rect;
	m_BackTab.GetClientRect(rect);
	rect.DeflateRect(1,30,2,2);
	int i=m_BackTab.GetCurSel();
	testmanagedlg->ShowWindow(SW_HIDE);
	resultselectdlg->ShowWindow(SW_HIDE);
	sqlmanagedlg->ShowWindow(SW_HIDE);
	switch(i)
	{
	case 0:
		{			
			testmanagedlg->MoveWindow(rect);
			testmanagedlg->ShowWindow(SW_SHOW);
			resultselectdlg->ShowWindow(SW_HIDE);
			sqlmanagedlg->ShowWindow(SW_HIDE);
			break;
		}
	case 1:
		{	
			resultselectdlg->MoveWindow(rect);
			resultselectdlg->ShowWindow(SW_SHOW);
			testmanagedlg->ShowWindow(SW_HIDE);
			sqlmanagedlg->ShowWindow(SW_HIDE);
			break;
		}
	case 2:
		{				
			sqlmanagedlg->MoveWindow(rect);
			sqlmanagedlg->ShowWindow(SW_SHOW);
			testmanagedlg->ShowWindow(SW_HIDE);	
			resultselectdlg->ShowWindow(SW_HIDE);
		}

	}
	
	*pResult = 0;
}
