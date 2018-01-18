// Classinfodlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Classinfodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassinfodlg dialog


CClassinfodlg::CClassinfodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClassinfodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClassinfodlg)
	m_classname = _T("");
	m_classteacher = _T("");
	//}}AFX_DATA_INIT
}


void CClassinfodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassinfodlg)
	DDX_Text(pDX, IDC_EDIT_classname, m_classname);
	DDX_Text(pDX, IDC_EDIT_classteacher, m_classteacher);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassinfodlg, CDialog)
	//{{AFX_MSG_MAP(CClassinfodlg)
	ON_COMMAND(ID_classinfo_toolbar_add, Onclassinfotoolbaradd)
	ON_COMMAND(ID_classinfo_toolbar_del, Onclassinfotoolbardel)
	ON_COMMAND(ID_classinfo_toolbar_first, Onclassinfotoolbarfirst)
	ON_COMMAND(ID_classinfo_toolbar_last, Onclassinfotoolbarlast)
	ON_COMMAND(ID_classinfo_toolbar_next, Onclassinfotoolbarnext)
	ON_COMMAND(ID_classinfo_toolbar_pre, Onclassinfotoolbarpre)
	ON_COMMAND(ID_classinfo_toolbar_save, Onclassinfotoolbarsave)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassinfodlg message handlers

BOOL CClassinfodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE
		| CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC)
		|| !m_ToolBar.LoadToolBar(IDR_TOOLBAR_classinfo))
	{
		TRACE0(_T("创建工具条失败\n"));
		return FALSE;
	}
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	m_ToolBar.SetButtonStyle(0,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(1,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(2,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(3,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(4,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(5,TBBS_CHECKBOX);
	m_ToolBar.SetButtonStyle(6,TBBS_CHECKBOX);
	myclassinfoset = new CClassinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	CString sqlStr;
	sqlStr="SELECT * FROM tb_classinfo";
	if(!myclassinfoset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_classinfo表打开失败!");
	}
	return TRUE;
}

void CClassinfodlg::Onclassinfotoolbaradd() 
{
	// TODO: Add your command handler code here	
	m_classname    = "";
	m_classteacher = "";
	UpdateData(FALSE);
}

void CClassinfodlg::Onclassinfotoolbardel() 
{
	// TODO: Add your command handler code here
	myclassinfoset_findref = new CStudentinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_studentinfo WHERE tb_studentinfo.class='"+m_classname+"'";
	   	
	if(!myclassinfoset_findref->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_studentinfo 表打开失败!");
	}
	if(myclassinfoset_findref->GetRecordCount()!=0)
	{
		AfxMessageBox("此考试类别在<学生信息表>里有引用,不能删除!");
		if(myclassinfoset_findref->IsOpen())
		{
			myclassinfoset_findref->Close();
			delete myclassinfoset_findref;
		}
		return;
	}
	if(myclassinfoset_findref->IsOpen())
	{
		myclassinfoset_findref->Close();
		delete myclassinfoset_findref;
	} 
	myclassinfoset->Delete(); //删除记录
	myclassinfoset->Requery();
	DisplayRecord(); //更新显示
}

void CClassinfodlg::Onclassinfotoolbarfirst() 
{
	// TODO: Add your command handler code here
	if(!myclassinfoset->IsBOF())
	{
		myclassinfoset->MoveFirst(); //向前移动一条记录
		DisplayRecord();             //更新窗口显示
	}
}

void CClassinfodlg::Onclassinfotoolbarlast() 
{
	// TODO: Add your command handler code here
	if(!myclassinfoset->IsEOF())
	{
		myclassinfoset->MoveLast();
		DisplayRecord(); 
	}
}

void CClassinfodlg::Onclassinfotoolbarnext() 
{
	// TODO: Add your command handler code here
	if(!myclassinfoset->IsEOF()) 
	{
		myclassinfoset->MoveNext();
		DisplayRecord(); 
	}
}

void CClassinfodlg::Onclassinfotoolbarpre() 
{
	// TODO: Add your command handler code here
	if(!myclassinfoset->IsBOF())
	{
		myclassinfoset->MovePrev();
		DisplayRecord();
	}
}

void CClassinfodlg::Onclassinfotoolbarsave() 
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);
	if(m_classname.IsEmpty()||m_classteacher.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}
	//调用添加记录的函数处理
	myclassinfoset->AddNew();
	myclassinfoset->m_teacher   = m_classteacher; //对应变量更新
	myclassinfoset->m_classname = m_classname;
	myclassinfoset->Update();
	myclassinfoset->Requery();
	DisplayRecord(); 
}
bool CClassinfodlg::DisplayRecord()
{
	if(myclassinfoset->IsEOF()&&myclassinfoset->IsBOF())
	{
		m_classname    = "";
	    m_classteacher = "";	
	}
	else
	{
		if(myclassinfoset->IsBOF()) //移动到了开头,就向后移动
		{
			myclassinfoset->MoveNext();
		}
		else //否则前移
		{
			if(myclassinfoset->IsEOF())
			{
				myclassinfoset->MovePrev();
			}
		}
	}
	m_classname    = myclassinfoset->m_classname; //对应变量赋值
	m_classteacher = myclassinfoset->m_teacher;

	UpdateData(FALSE); //显示更新
	return true;

}

void CClassinfodlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myclassinfoset->IsOpen())
	{
		myclassinfoset->Close();
		delete myclassinfoset;
	}
	CDialog::OnClose();
}

void CClassinfodlg::OnOK()
{

}
