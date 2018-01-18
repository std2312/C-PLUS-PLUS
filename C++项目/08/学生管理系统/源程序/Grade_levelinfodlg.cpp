// Grade_levelinfodlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Grade_levelinfodlg.h"
#include <stdlib.h>
#include <stdio.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrade_levelinfodlg dialog


CGrade_levelinfodlg::CGrade_levelinfodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGrade_levelinfodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrade_levelinfodlg)
	m_gradekind = _T("");
	m_lowgrade = 0.0f;
	m_upgrade = 0.0f;
	//}}AFX_DATA_INIT
}


void CGrade_levelinfodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrade_levelinfodlg)
	DDX_Control(pDX, IDC_LIST3, m_List3);
	DDX_Control(pDX, IDC_COMBO1, m_gradekindC);
	DDX_CBString(pDX, IDC_COMBO1, m_gradekind);
	DDX_Text(pDX, IDC_EDIT_lowgrade, m_lowgrade);
	DDX_Text(pDX, IDC_EDIT_upgrade, m_upgrade);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGrade_levelinfodlg, CDialog)
	//{{AFX_MSG_MAP(CGrade_levelinfodlg)
	ON_BN_CLICKED(IDC_Btn_setgradelevel, OnBtnsetgradelevel)
	ON_BN_CLICKED(IDC_Btn_findbest, OnBtnfindbest)
	ON_BN_CLICKED(IDC_Btnfindbetter, OnBtnfindbetter)
	ON_BN_CLICKED(IDC_Btnfindnormal, OnBtnfindnormal)
	ON_BN_CLICKED(IDC_Btnfindworse, OnBtnfindworse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrade_levelinfodlg message handlers

BOOL CGrade_levelinfodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_List3.InsertColumn(0,"学生编号");
	m_List3.InsertColumn(1,"考试科目");
	m_List3.InsertColumn(2,"成绩");
	m_List3.InsertColumn(3,"考试类别");
	m_List3.InsertColumn(4,"时间");
	RECT rect;
	m_List3.GetWindowRect(&rect);
	int wid = rect.right-rect.left;
	m_List3.SetColumnWidth(0,wid/5);
	m_List3.SetColumnWidth(1,wid/5);
    m_List3.SetColumnWidth(2,wid/5);
	m_List3.SetColumnWidth(3,wid/5);
	m_List3.SetColumnWidth(4,wid/5);
	m_List3.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	UpdateData(FALSE);
	return TRUE;
}

void CGrade_levelinfodlg::OnBtnsetgradelevel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_gradekindC.GetWindowText(m_gradekind);
	if(m_gradekind.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
	}
	CString sqlStr;
	sqlStr = "SELECT * FROM tb_gradelevel WHERE tb_gradelevel.grade_level='"+m_gradekind+"'";	
	gradelevel_findset = new CGrade_levelset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!gradelevel_findset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_gradelevel表打开失败!");
	}
	gradelevel_findset->Edit();
	gradelevel_findset->m_up_grade  = m_upgrade; //对应变量更新
	gradelevel_findset->m_low_grade = m_lowgrade;
	gradelevel_findset->Update();
	gradelevel_findset->Requery();
	AfxMessageBox("设置成功!");
	DisplayRecord(); //更新显示
	if(gradelevel_findset->IsOpen())
	{
		gradelevel_findset->Close();
		delete gradelevel_findset;
	}
}
bool CGrade_levelinfodlg::DisplayRecord()
{
	m_upgrade  = gradelevel_findset->m_up_grade; //对应变量更新
	m_lowgrade = gradelevel_findset->m_low_grade;
	UpdateData(FALSE);
	return TRUE;
}

void CGrade_levelinfodlg::OnBtnfindbest() 
{
	// TODO: Add your control notification handler code hereBETWEEN
	CString sqlStr_finduplow;
	sqlStr_finduplow = "SELECT * FROM tb_gradelevel WHERE tb_gradelevel.grade_level='优秀'";
	findbest_uplowset = new CGrade_levelset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!findbest_uplowset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_finduplow)) //打开数据表
	{
		AfxMessageBox("tb_gradelevel表打开失败!");
	}
    float upgrade  = findbest_uplowset->m_up_grade;
    float lowgrade = findbest_uplowset->m_low_grade;
	if(findbest_uplowset->IsOpen())
	{
		findbest_uplowset->Close();
		delete findbest_uplowset;
	}
	CString sqlStr_findmarks;
	sqlStr_findmarks.Format("SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.grade\
		<='%f' AND tb_examinfo_sub.grade >='%f'",upgrade,lowgrade);
	exammark_findbestset = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!exammark_findbestset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findmarks)) //打开数据表
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	CString stuid,subject,kind;
	float marks;
	CString date;
    CTime tDate;
	int i=0;
	m_List3.DeleteAllItems();
	while(!exammark_findbestset->IsEOF())
	{
		stuid   = exammark_findbestset->m_studentid;
		subject = exammark_findbestset->m_code;
		kind    = exammark_findbestset->m_kind;
		marks   = exammark_findbestset->m_grade;
		char buffer[50];
		_gcvt(marks, 4, buffer );
		tDate = exammark_findbestset->m_examdate;
		date  = tDate.Format("%m/%d/%y"); 
		m_List3.InsertItem(i,stuid.GetBuffer(50));
		m_List3.SetItemText(i,1,subject.GetBuffer(50));
		m_List3.SetItemText(i,2,buffer);
		m_List3.SetItemText(i,3,kind.GetBuffer(50));
		m_List3.SetItemText(i,4,date.GetBuffer(50));
		exammark_findbestset->MoveNext();
		i++;
	}
	UpdateData(FALSE);
	if(exammark_findbestset->IsOpen())
	{
		exammark_findbestset->Close();
		delete exammark_findbestset;
	}
	return;
}

void CGrade_levelinfodlg::OnBtnfindbetter() 
{
	// TODO: Add your control notification handler code here
	CString sqlStr_finduplow;
	sqlStr_finduplow="SELECT * FROM tb_gradelevel WHERE tb_gradelevel.grade_level='良好'";
	findbetter_uplowset = new CGrade_levelset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!findbetter_uplowset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_finduplow)) //打开数据表
	{
		AfxMessageBox("tb_gradelevel表打开失败!");
	}
    float upgrade  = findbetter_uplowset->m_up_grade;
    float lowgrade = findbetter_uplowset->m_low_grade;
	if(findbetter_uplowset->IsOpen())
	{
		findbetter_uplowset->Close();
		delete findbetter_uplowset;
	}
	CString sqlStr_findmarks;
	sqlStr_findmarks.Format("SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.grade\
		<='%f' AND tb_examinfo_sub.grade >='%f'",upgrade,lowgrade);
	exammark_findbetterset = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!exammark_findbetterset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findmarks)) //打开数据表
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	CString stuid,subject,kind;
	float marks;
	CString date;
    CTime tDate;
	int i=0;
	m_List3.DeleteAllItems();
	while(!exammark_findbetterset->IsEOF())
	{
		stuid   = exammark_findbetterset->m_studentid;
		subject = exammark_findbetterset->m_code;
		kind    = exammark_findbetterset->m_kind;
		marks   = exammark_findbetterset->m_grade;
		char buffer[50];
		_gcvt(marks, 4, buffer );
		tDate = exammark_findbetterset->m_examdate;
		date  = tDate.Format("%m/%d/%y"); 
		m_List3.InsertItem(i,stuid.GetBuffer(50));
		m_List3.SetItemText(i,1,subject.GetBuffer(50));
		m_List3.SetItemText(i,2,buffer);
		m_List3.SetItemText(i,3,kind.GetBuffer(50));
		m_List3.SetItemText(i,4,date.GetBuffer(50));
		exammark_findbetterset->MoveNext();
		i++;
	}
	UpdateData(FALSE);

	if(exammark_findbetterset->IsOpen())
	{
		exammark_findbetterset->Close();
		delete exammark_findbetterset;
	}

	return;
}

void CGrade_levelinfodlg::OnBtnfindnormal() 
{
	// TODO: Add your control notification handler code here	
	CString sqlStr_finduplow;
	sqlStr_finduplow="SELECT * FROM tb_gradelevel WHERE tb_gradelevel.grade_level='及格'";	
	findnormal_uplowset = new CGrade_levelset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!findnormal_uplowset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_finduplow)) //打开数据表
	{
		AfxMessageBox("tb_gradelevel表打开失败!");
	}
    float upgrade  = findnormal_uplowset->m_up_grade;
    float lowgrade = findnormal_uplowset->m_low_grade;
	if(findnormal_uplowset->IsOpen())
	{
		findnormal_uplowset->Close();
		delete findnormal_uplowset;
	}
	CString sqlStr_findmarks;
	sqlStr_findmarks.Format("SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.grade\
		<='%f' AND tb_examinfo_sub.grade >='%f'",upgrade,lowgrade);
	exammark_findnormalset = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!exammark_findnormalset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findmarks)) //打开数据表
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	CString stuid,subject,kind;
	float marks;
	CString date;
    CTime tDate;
	int i=0;
	m_List3.DeleteAllItems();
	while(!exammark_findnormalset->IsEOF())
	{
		stuid   = exammark_findnormalset->m_studentid;
		subject = exammark_findnormalset->m_code;
		kind    = exammark_findnormalset->m_kind;
		marks   = exammark_findnormalset->m_grade;
		char buffer[50];
		_gcvt(marks, 4, buffer );
		tDate=exammark_findnormalset->m_examdate;
		date = tDate.Format("%m/%d/%y"); 	
		m_List3.InsertItem(i,stuid.GetBuffer(50));
		m_List3.SetItemText(i,1,subject.GetBuffer(50));
		m_List3.SetItemText(i,2,buffer);
		m_List3.SetItemText(i,3,kind.GetBuffer(50));
		m_List3.SetItemText(i,4,date.GetBuffer(50));
		exammark_findnormalset->MoveNext();
		i++;
	}
	UpdateData(FALSE);
	if(exammark_findnormalset->IsOpen())
	{
		exammark_findnormalset->Close();
		delete exammark_findnormalset;
	}
	return;
}

void CGrade_levelinfodlg::OnBtnfindworse() 
{
	// TODO: Add your control notification handler code here	
	CString sqlStr_finduplow;
	sqlStr_finduplow="SELECT * FROM tb_gradelevel WHERE tb_gradelevel.grade_level='不及格'";
	findworse_uplowset = new CGrade_levelset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!findworse_uplowset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_finduplow)) //打开数据表
	{
		AfxMessageBox("tb_gradelevel表打开失败!");
	}
    float upgrade  = findworse_uplowset->m_up_grade;
    float lowgrade = findworse_uplowset->m_low_grade;
	if(findworse_uplowset->IsOpen())
	{
		findworse_uplowset->Close();
		delete findworse_uplowset;
	}
	CString sqlStr_findmarks;
	sqlStr_findmarks.Format("SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.grade\
		<='%f' AND tb_examinfo_sub.grade >='%f'",upgrade,lowgrade);
	exammark_findworseset = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!exammark_findworseset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findmarks)) //打开数据表
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	CString stuid,subject,kind;
	float marks;
	CString date;
    CTime tDate;
	int i=0;
	m_List3.DeleteAllItems();
	while(!exammark_findworseset->IsEOF())
	{
		stuid   = exammark_findworseset->m_studentid;
		subject = exammark_findworseset->m_code;
		kind    = exammark_findworseset->m_kind;
		marks   = exammark_findworseset->m_grade;
		char buffer[50];
		_gcvt(marks, 4, buffer );
		tDate = exammark_findworseset->m_examdate;    
		date  = tDate.Format("%m/%d/%y");  
		m_List3.InsertItem(i,stuid.GetBuffer(50));
		m_List3.SetItemText(i,1,subject.GetBuffer(50));
		m_List3.SetItemText(i,2,buffer);
		m_List3.SetItemText(i,3,kind.GetBuffer(50));
		m_List3.SetItemText(i,4,date.GetBuffer(50));
		exammark_findworseset->MoveNext();
		i++;
	}
	UpdateData(FALSE);
	if(exammark_findworseset->IsOpen())
	{
		exammark_findworseset->Close();
		delete exammark_findworseset;
	}
	return;
}
