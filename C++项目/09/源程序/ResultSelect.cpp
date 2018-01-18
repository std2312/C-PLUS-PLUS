// ResultSelect.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ResultSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultSelect dialog


CResultSelect::CResultSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CResultSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResultSelect)
	m_Mark = _T("");
	//}}AFX_DATA_INIT
}


void CResultSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultSelect)
	DDX_Control(pDX, IDC_RESULTLIST, m_ResultList);
	DDX_Control(pDX, IDC_TYPECOMBO, m_Type);
	DDX_Text(pDX, IDC_Mark, m_Mark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultSelect, CDialog)
	//{{AFX_MSG_MAP(CResultSelect)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_NOTIFY(NM_DBLCLK, IDC_RESULTLIST, OnDblclkResultlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultSelect message handlers

BOOL CResultSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_ResultList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	m_ResultList.InsertColumn(0,"考生姓名",LVCFMT_CENTER,100,0);
	m_ResultList.InsertColumn(1,"科目",LVCFMT_CENTER,150,1);
	m_ResultList.InsertColumn(2,"分数",LVCFMT_CENTER,242,2);
	m_ResultList.InsertColumn(3,"考生编号",LVCFMT_CENTER,100,0);
	CString sql="select * from result";
	m_AdoConn.OnInitADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString subject,totle;
	int i=0;
	while(m_pRs->adoEOF==0)
	{
		int	studentid=atoi((char*)(_bstr_t)m_pRs->GetCollect("studentid"));
		sql.Format("select*from register where studentid=%d",studentid);
		_RecordsetPtr m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString name=(char*)(_bstr_t)m_prs->GetCollect("name");
		subject=(char*)(_bstr_t)m_pRs->GetCollect("subject");
		totle=(char*)(_bstr_t)m_pRs->GetCollect("totle");
		m_ResultList.InsertItem(i,"");
		m_ResultList.SetItemText(i,0,name);
		m_ResultList.SetItemText(i,1,subject);
		m_ResultList.SetItemText(i,2,totle);
		CString ss;
		ss.Format("%d",studentid);
		m_ResultList.SetItemText(i,3,ss);
		i++;
		m_pRs->MoveNext();
	}
	m_Type.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CResultSelect::OnSelect() 
{
	m_ResultList.DeleteAllItems();
	UpdateData();
	int i=m_Type.GetCurSel();
	CString sql;
	int mark=atoi(m_Mark);
	if(i==0)
	{
		sql.Format("select * from result where totle<=%d",mark);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString subject,totle;
		int i=0;
		while(m_pRs->adoEOF==0)
		{
			int	studentid=atoi((char*)(_bstr_t)m_pRs->GetCollect("studentid"));
			sql.Format("select*from register where studentid=%d",studentid);
			_RecordsetPtr m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			CString name=(char*)(_bstr_t)m_prs->GetCollect("name");
			subject=(char*)(_bstr_t)m_pRs->GetCollect("subject");
			totle=(char*)(_bstr_t)m_pRs->GetCollect("totle");
			m_ResultList.InsertItem(i,"");
			m_ResultList.SetItemText(i,0,name);
			m_ResultList.SetItemText(i,1,subject);
			m_ResultList.SetItemText(i,2,totle);
			CString ss;
			ss.Format("%d",studentid);
			m_ResultList.SetItemText(i,3,ss);
			i++;
			m_pRs->MoveNext();
		}
	}
	if(i==1)
	{
		sql.Format("select * from result where totle>=%d",mark);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString subject,totle;
		int i=0;
		while(m_pRs->adoEOF==0)
		{
			int	studentid=atoi((char*)(_bstr_t)m_pRs->GetCollect("studentid"));
			sql.Format("select*from register where studentid=%d",studentid);
			_RecordsetPtr m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			CString name=(char*)(_bstr_t)m_prs->GetCollect("name");
			subject=(char*)(_bstr_t)m_pRs->GetCollect("subject");
			totle=(char*)(_bstr_t)m_pRs->GetCollect("totle");
			m_ResultList.InsertItem(i,"");
			m_ResultList.SetItemText(i,0,name);
			m_ResultList.SetItemText(i,1,subject);
			m_ResultList.SetItemText(i,2,totle);
			CString ss;
			ss.Format("%d",studentid);
			m_ResultList.SetItemText(i,3,ss);
			i++;
			m_pRs->MoveNext();
		}
	}
}

void CResultSelect::OnDblclkResultlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString sql,studentid,subject;
	int pos = m_ResultList.GetSelectionMark();
	studentid = m_ResultList.GetItemText(pos,3);
	subject = m_ResultList.GetItemText(pos,1);
	m_AdoConn.OnInitADOConn();
	sql.Format("delete from result where studentid = %d and subject = '%s'",atoi(studentid),subject);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_ResultList.DeleteAllItems();
	sql="select * from result";
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString totle;
	int i=0;
	while(m_pRs->adoEOF==0)
	{
		int	studentid=atoi((char*)(_bstr_t)m_pRs->GetCollect("studentid"));
		sql.Format("select*from register where studentid=%d",studentid);
		_RecordsetPtr m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString name=(char*)(_bstr_t)m_prs->GetCollect("name");
		subject=(char*)(_bstr_t)m_pRs->GetCollect("subject");
		totle=(char*)(_bstr_t)m_pRs->GetCollect("totle");
		m_ResultList.InsertItem(i,"");
		m_ResultList.SetItemText(i,0,name);
		m_ResultList.SetItemText(i,1,subject);
		m_ResultList.SetItemText(i,2,totle);
		CString ss;
		ss.Format("%d",studentid);
		m_ResultList.SetItemText(i,3,ss);
		i++;
		m_pRs->MoveNext();
	}
	*pResult = 0;
}
