// Studentinfo_finddlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Studentinfo_finddlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentinfo_finddlg dialog


CStudentinfo_finddlg::CStudentinfo_finddlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentinfo_finddlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentinfo_finddlg)
	m_studentid = _T("");
	//}}AFX_DATA_INIT
}


void CStudentinfo_finddlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentinfo_finddlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_findstudent_id, m_studentid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentinfo_finddlg, CDialog)
	//{{AFX_MSG_MAP(CStudentinfo_finddlg)
	ON_BN_CLICKED(IDC_findstudentinfo, Onfindstudentinfo)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentinfo_finddlg message handlers

BOOL CStudentinfo_finddlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_List.InsertColumn(0,"学生姓名");
	m_List.InsertColumn(1,"性别");
	m_List.InsertColumn(2,"年龄");
	m_List.InsertColumn(3,"住址");
	m_List.InsertColumn(4,"电话");
	m_List.InsertColumn(5,"班级");
	RECT rect;
	m_List.GetWindowRect(&rect);
	int wid=rect.right-rect.left;
	m_List.SetColumnWidth(0,wid/6);
	m_List.SetColumnWidth(1,wid/6);
    m_List.SetColumnWidth(2,wid/6);
	m_List.SetColumnWidth(3,wid/6);
	m_List.SetColumnWidth(4,wid/6);
	m_List.SetColumnWidth(5,wid/6);
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void CStudentinfo_finddlg::Onfindstudentinfo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sqlStr;
	sqlStr="SELECT * FROM tb_studentinfo WHERE studentid='";
	sqlStr+=m_studentid;
	sqlStr+="'";
	mystudentset = new CStudentinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!mystudentset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr))
	{
		AfxMessageBox("tb_studentinfo表打开失败!");
	}
	DisplayRecord();
	if(mystudentset->IsOpen())
	{
		mystudentset->Close();
		delete mystudentset;
	}
}
bool CStudentinfo_finddlg::DisplayRecord()
{
/*	if(mystudentset->IsBOF())
	{
		mystudentset->MoveNext();
	}
	else
	{
		if(mystudentset->IsEOF())
		{
			mystudentset->MovePrev();
		}
	}*/
	m_List.DeleteAllItems();
	CString addr,sage,sclass;
	CString name,phone,sex;
	CString date;
	int age;
    
	name   = mystudentset->m_studentname;
	addr   = mystudentset->m_addr;
	age    = mystudentset->m_age;
	sclass = mystudentset->m_class;
	phone  = mystudentset->m_phone;
    sex    = mystudentset->m_sex;
	sage.Format("%d",age);

	m_List.InsertItem(0,name.GetBuffer(50));
    m_List.SetItemText(0,1,sex.GetBuffer(50));
	m_List.SetItemText(0,2,sage.GetBuffer(50));
	m_List.SetItemText(0,3,addr.GetBuffer(50));
    m_List.SetItemText(0,4,phone.GetBuffer(50));
	m_List.SetItemText(0,5,sclass.GetBuffer(50));
	UpdateData(FALSE);
	return TRUE;
}

void CStudentinfo_finddlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

void CStudentinfo_finddlg::OnOK()
{

}
