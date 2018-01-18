// TextManage.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "TextManage.h"
#include "AddSubject.h"
#include "AddTest.h"
#include "TestChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextManage dialog


CTextManage::CTextManage(CWnd* pParent /*=NULL*/)
	: CDialog(CTextManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTextManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextManage)
	DDX_Control(pDX, IDC_TextList, m_TextList);
	DDX_Control(pDX, IDC_TextTree, m_TextTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextManage, CDialog)
	//{{AFX_MSG_MAP(CTextManage)
	ON_BN_CLICKED(IDC_ADDSUBJECT, OnAddsubject)
	ON_BN_CLICKED(IDC_ADDTEST, OnAddtest)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TextTree, OnSelchangedTextTree)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DELSUBJECT, OnDelsubject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextManage message handlers

BOOL CTextManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	AddToTree();
	m_TextList.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_TextList.InsertColumn(0,"题目",LVCFMT_LEFT,250,0);
	m_TextList.InsertColumn(1,"答案",LVCFMT_LEFT,100,0);	
	return TRUE;  
}



void CTextManage::OnAddsubject() 
{
	CAddSubject dlg;
	if(dlg.DoModal()==IDOK)
	{
		CString Name;
		Name=dlg.m_SubjectName;
		try
		{
			int subjectid;
			CString sql="select * from subject";
			m_AdoConn.OnInitADOConn();
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(m_pRs->adoEOF)
			{
				subjectid=1;
				sql.Format("insert into subject(subjectid,subjectname)values(%d,'%s')",subjectid,Name);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
			}
			else
			{
				m_pRs->MoveLast();
				subjectid=atoi((char*)(_bstr_t)m_pRs->GetCollect("subjectid"))+1;
				sql.Format("insert into subject(subjectid,subjectname)values(%d,'%s')",subjectid,Name);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
			}
			m_AdoConn.ExitConn();
			m_TextTree.DeleteAllItems();
			AddToTree();
		}
		catch(...)
		{
			AfxMessageBox("操作失败");
			return;
		}
	}
}

void CTextManage::AddToTree()
{
	HTREEITEM h_root;
	h_root=m_TextTree.InsertItem("试题科目",0,1);	
	CString sql="select * from subject";
	_RecordsetPtr m_prs;
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		while(m_pRs->adoEOF==0)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("subjectname");
			m_TextTree.InsertItem(str,0,1,h_root);	
			m_pRs->MoveNext();
		}
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("读取数据失败");
		return ;
	}

}

void CTextManage::OnAddtest() 
{
	CAddTest dlg;
	if(dlg.DoModal()==IDOK)
	{
		CString Question;
		CString Answer;
		CString Subject;
		CString totle;
		CString AnswerA,AnswerB,AnswerC,AnswerD;
		Subject=dlg.ComboText;
		Question=dlg.m_Question;
		Answer=dlg.m_Answer;
		totle=dlg.m_Totle;
		AnswerA=dlg.m_AnswerA; 
		AnswerB=dlg.m_AnswerB;
		AnswerC=dlg.m_AnswerC;
		AnswerD=dlg.m_AnswerD;
		int testid;
		CString sql="select*from test where question='"+Question+"'";
		try
		{
			m_AdoConn.OnInitADOConn();
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(!m_pRs->adoEOF)
			{
				AfxMessageBox("试题已经存在");
				return;
			}
			else 
			{
				sql="select * from subject where subjectname='"+Subject+"'";
				m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
				int Sid=atoi((char*)(_bstr_t)m_pRs->GetCollect("subjectid"));
				sql="select * from test";
				m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
				if(m_pRs->adoEOF)
				{
					testid=1000;
				}
				else
				{
					m_pRs->MoveLast();
					testid=atoi((char*)(_bstr_t)m_pRs->GetCollect("testid"))+1;
				}
				sql.Format("insert into test(testid,question,rightanswer,subjectid,totle)values(%d,\
					'%s','%s',%d,'%s')",testid,Question,Answer,Sid,totle);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
				sql.Format("insert into testanswer(testid,AnswerA,AnswerB,AnswerC,AnswerD)values(%d,\
					'%s','%s','%s','%s')",testid,AnswerA,AnswerB,AnswerC,AnswerD);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
				m_AdoConn.ExitConn();
				m_TextList.DeleteAllItems();
				AddToList(Sid);
			}
		}
		catch(...)
		{
			AfxMessageBox("操作失败");
			return;
		}
	}
}



void CTextManage::OnSelchangedTextTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;	
	HTREEITEM select=m_TextTree.GetSelectedItem();
	if(select!=m_TextTree.GetRootItem())
	{
		CString TreeText=m_TextTree.GetItemText(select);
		m_TextList.DeleteAllItems();
		try
		{
			CString sql="select*from subject where subjectname='"+TreeText+"'"; 
			m_AdoConn.OnInitADOConn();
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			int Sid=atoi((char*)(_bstr_t)m_pRs->GetCollect("subjectid"));
			AddToList(Sid);
			m_AdoConn.ExitConn();
		}
		catch(...)
		{
			AfxMessageBox("操作失败");
			return;
		}
	}
	

	*pResult = 0;
}

void CTextManage::AddToList(int Sid)
{
	CString sql;
	sql.Format("select * from test where subjectid=%d",Sid);
	m_AdoConn.OnInitADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_pRs->adoEOF==0)
	{
		CString Question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		CString Answer=(char*)(_bstr_t)m_pRs->GetCollect("rightanswer");
		m_TextList.InsertItem(0,"");
		m_TextList.SetItemText(0,0,Question);
		m_TextList.SetItemText(0,1,Answer);
		m_pRs->MoveNext();
	}
}

void CTextManage::OnDel() 
{
	int i=m_TextList.GetSelectionMark();
	CString str=m_TextList.GetItemText(i,0);
	int testidold,testidnew;
	if(i==-1)
	{
		AfxMessageBox("请选择一个试题");
		return;
	}
	try
	{
		CString sql="select* from test where question='"+str+"'";
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		testidold=atoi((char*)(_bstr_t)m_pRs->GetCollect("testid"));
		CString strid;
		strid.Format("%d",testidold+1);
		sql="delete from test where question='"+str+"'";
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql="select* from test where testid>="+strid+"";
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		while(m_pRs->adoEOF==0)
		{
			testidold=atoi((char*)(_bstr_t)m_pRs->GetCollect("testid"));
			testidnew=testidold-1;
			sql.Format("update test set testid=%d where testid=%d",testidnew,testidold);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_pRs->MoveNext();
		}
		m_AdoConn.ExitConn();
		m_TextList.DeleteItem(i);
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return;
	}

}

void CTextManage::OnChange() 
{
	int i=m_TextList.GetSelectionMark();
	Question=m_TextList.GetItemText(i,0);
	Answer=m_TextList.GetItemText(i,1);	
	if(i==-1)
	{
		AfxMessageBox("请选择一个试题");
		return;
	}
	else
	{
		CTestChange dlg;
		dlg.m_Question=Question;
		dlg.m_Answer=Answer;
		if(dlg.DoModal()==IDOK)
		{
			m_TextList.DeleteAllItems();
			CString sql;
			m_AdoConn.OnInitADOConn();
			sql.Format("select*from test where question='%s'",Question);
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			int Sid=atoi((char*)(_bstr_t)m_pRs->GetCollect("subjectid"));
			AddToList(Sid);
		}
	}
}

void CTextManage::OnDelsubject() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM m_Tree = m_TextTree.GetSelectedItem();
	CString sql,Name;
	Name = m_TextTree.GetItemText(m_Tree);
	if(MessageBox("确定要删除该科目吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
		m_AdoConn.OnInitADOConn();
		sql.Format("delete from subject where subjectname = '%s'",Name);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.m_pCon->Close();
		m_TextTree.DeleteAllItems();
		AddToTree();
	}
}
