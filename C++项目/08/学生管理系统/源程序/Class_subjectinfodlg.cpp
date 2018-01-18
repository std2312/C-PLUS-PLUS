// Class_subjectinfodlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Class_subjectinfodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClass_subjectinfodlg dialog


CClass_subjectinfodlg::CClass_subjectinfodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClass_subjectinfodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClass_subjectinfodlg)
	m_classid = _T("");
	m_classname = _T("");
	//}}AFX_DATA_INIT
}


void CClass_subjectinfodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClass_subjectinfodlg)
	DDX_Text(pDX, IDC_EDITclassid, m_classid);
	DDX_Text(pDX, IDC_EDITclassname, m_classname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClass_subjectinfodlg, CDialog)
	//{{AFX_MSG_MAP(CClass_subjectinfodlg)
	ON_COMMAND(ID_classsubjectinfo_toolbar_add, Onclasssubjectinfotoolbaradd)
	ON_COMMAND(ID_classsubjectinfo_toolbar_del, Onclasssubjectinfotoolbardel)
	ON_COMMAND(ID_classsubjectinfo_toolbar_first, Onclasssubjectinfotoolbarfirst)
	ON_COMMAND(ID_classsubjectinfo_toolbar_last, Onclasssubjectinfotoolbarlast)
	ON_COMMAND(ID_classsubjectinfo_toolbar_next, Onclasssubjectinfotoolbarnext)
	ON_COMMAND(ID_classsubjectinfo_toolbar_pre, Onclasssubjectinfotoolbarpre)
	ON_COMMAND(ID_classsubjectinfo_toolbar_save, Onclasssubjectinfotoolbarsave)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClass_subjectinfodlg message handlers

BOOL CClass_subjectinfodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE
		| CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC)
		|| !m_ToolBar.LoadToolBar(IDR_TOOLBAR_classsubjectinfo))
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
	CString sqlStr;
	sqlStr="SELECT * FROM tb_class_subject";
	myclass_subjectinfoset = new CClass_subjectset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myclass_subjectinfoset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_class_subject表打开失败!");
	}
	return TRUE;
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbaradd() 
{
	// TODO: Add your command handler code here
	m_classname = "";
	m_classid   = "";
	UpdateData(FALSE);
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbardel() 
{
	// TODO: Add your command handler code here
	myclass_subjectinfoset->Delete(); //删除记录
	myclass_subjectinfoset->Requery();
	DisplayRecord(); //更新显示
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbarfirst() 
{
	// TODO: Add your command handler code here
	if(!myclass_subjectinfoset->IsBOF())
	{
		myclass_subjectinfoset->MoveFirst(); //向前移动一条记录
		DisplayRecord();                     //更新窗口显示
	}
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbarlast() 
{
	// TODO: Add your command handler code here
	if(!myclass_subjectinfoset->IsEOF())
	{
		myclass_subjectinfoset->MoveLast();
		DisplayRecord();
	}
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbarnext() 
{
	// TODO: Add your command handler code here
	if(!myclass_subjectinfoset->IsEOF())
	{
		myclass_subjectinfoset->MoveNext();
		DisplayRecord();
	}
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbarpre() 
{
	// TODO: Add your command handler code here
	if(!myclass_subjectinfoset->IsBOF())
	{
		myclass_subjectinfoset->MovePrev();
		DisplayRecord();
	}
}

void CClass_subjectinfodlg::Onclasssubjectinfotoolbarsave() 
{
	// TODO: Add your command handler code here
	UpdateData(TRUE); 
	if(m_classname.IsEmpty()||m_classid.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}
	//调用添加记录的函数处理
	myclass_subjectinfoset->AddNew();
	myclass_subjectinfoset->m_code      = m_classid; //对应变量更新
	myclass_subjectinfoset->m_classname = m_classname;
	myclass_subjectinfoset->Update();
	myclass_subjectinfoset->Requery();
	DisplayRecord(); 
}
bool CClass_subjectinfodlg::DisplayRecord()
{
	if(myclass_subjectinfoset->IsEOF()&&myclass_subjectinfoset->IsBOF())
	{
		m_classname = "";
	    m_classid   = "";	
	}
	else
	{
		if(myclass_subjectinfoset->IsBOF()) //移动到了开头,就向后移动
		{
			myclass_subjectinfoset->MoveNext();
		}
		else //否则前移
		{
			if(myclass_subjectinfoset->IsEOF())
			{
				myclass_subjectinfoset->MovePrev();
			}
		}
	}
	m_classname = myclass_subjectinfoset->m_classname; //对应变量赋值
	m_classid   = myclass_subjectinfoset->m_code;
	UpdateData(FALSE); 
	return true;

}

void CClass_subjectinfodlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myclass_subjectinfoset->IsOpen())
	{
		myclass_subjectinfoset->Close();
		delete myclass_subjectinfoset;
	}
	CDialog::OnClose();
}

void CClass_subjectinfodlg::OnOK()
{

}
