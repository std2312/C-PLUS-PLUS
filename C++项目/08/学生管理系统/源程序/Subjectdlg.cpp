// Subjectdlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Subjectdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectdlg dialog


CSubjectdlg::CSubjectdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubjectdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubjectdlg)
	m_subjectname = _T("");
	m_subjectid = _T("");
	//}}AFX_DATA_INIT
}


void CSubjectdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubjectdlg)
	DDX_Text(pDX, IDC_subjectname, m_subjectname);
	DDX_Text(pDX, IDC_subjectid, m_subjectid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubjectdlg, CDialog)
	//{{AFX_MSG_MAP(CSubjectdlg)
	ON_COMMAND(ID_subjectinfo_toolbar_add, Onsubjectinfotoolbaradd)
	ON_COMMAND(ID_subjectinfo_toolbar_del, Onsubjectinfotoolbardel)
	ON_COMMAND(ID_subjectinfo_toolbar_first, Onsubjectinfotoolbarfirst)
	ON_COMMAND(ID_subjectinfo_toolbar_last, Onsubjectinfotoolbarlast)
	ON_COMMAND(ID_subjectinfo_toolbar_next, Onsubjectinfotoolbarnext)
	ON_COMMAND(ID_subjectinfo_toolbar_pre, Onsubjectinfotoolbarpre)
	ON_COMMAND(ID_subjectinfo_toolbar_save, Onsubjectinfotoolbarsave)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubjectdlg message handlers

BOOL CSubjectdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD|WS_VISIBLE|CBRS_TOP
		|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_SIZE_DYNAMIC)
		||!m_ToolBar.LoadToolBar(IDR_TOOLBAR_subjectinfo))
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
	// TODO: Add extra initialization here
	//RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);	
	CString sqlStr;
	sqlStr="SELECT * FROM tb_subject";
	mysubjectset = new CSubjectinfo(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!mysubjectset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_subject表打开失败!");
	}
	return TRUE;
}
bool CSubjectdlg::DisplayRecord()
{
	if(mysubjectset->IsEOF()&&mysubjectset->IsBOF()) //判断是否移动到了开头和结尾
	{
		m_subjectname = "";
		m_subjectid   = "";
	}
	else
	{
		if(mysubjectset->IsBOF()) //移动到了开头,就向后移动
		{
			mysubjectset->MoveNext();
		}
		else //否则前移
		{
			if(mysubjectset->IsEOF())
			{
				mysubjectset->MovePrev();
			}
		}
	}
	m_subjectname = mysubjectset->m_subject; //对应变量赋值
	m_subjectid   = mysubjectset->m_code;
	UpdateData(FALSE);
	return TRUE;

}

void CSubjectdlg::Onsubjectinfotoolbaradd() 
{
	// TODO: Add your command handler code here
	m_subjectname = "";
	m_subjectid   = "";
	UpdateData(FALSE);
}

void CSubjectdlg::Onsubjectinfotoolbardel() 
{
	// TODO: Add your command handler code here
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_class_subject WHERE tb_class_subject.code='"+m_subjectid+"' ";
	myclass_subject_findref = new CClass_subjectset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myclass_subject_findref->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_class_subject 表打开失败!");
	}
	if(myclass_subject_findref->GetRecordCount() != 0)
	{
		AfxMessageBox("科室名称在<班级科目表>里有引用,不能删除!");
		if(myclass_subject_findref->IsOpen())
		{
			myclass_subject_findref->Close();
			delete myclass_subject_findref;
		}
		return;
	}
	if(myclass_subject_findref->IsOpen())
	{
		myclass_subject_findref->Close();
		delete myclass_subject_findref;
	}  
	mysubjectset->Delete(); //删除记录
	mysubjectset->Requery();
	DisplayRecord(); 
}

void CSubjectdlg::Onsubjectinfotoolbarfirst() 
{
	// TODO: Add your command handler code here
	if(!mysubjectset->IsBOF())
	{
		mysubjectset->MoveFirst(); //向前移动一条记录
		DisplayRecord();           //更新窗口显示
	}
}

void CSubjectdlg::Onsubjectinfotoolbarlast() 
{
	// TODO: Add your command handler code here
	if(!mysubjectset->IsEOF())
	{
		mysubjectset->MoveLast();
		DisplayRecord();
	}
}

void CSubjectdlg::Onsubjectinfotoolbarnext() 
{
	// TODO: Add your command handler code here
	if(!mysubjectset->IsEOF())
	{
		mysubjectset->MoveNext();
		DisplayRecord();
	}
}

void CSubjectdlg::Onsubjectinfotoolbarpre() 
{
	// TODO: Add your command handler code here
	if(!mysubjectset->IsBOF())
	{
		mysubjectset->MovePrev();
		DisplayRecord();
	}
}

void CSubjectdlg::Onsubjectinfotoolbarsave() 
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);
	if(m_subjectname.IsEmpty()||m_subjectid.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return ;
	}
	CString sqlStr_findid;
	sqlStr_findid = "SELECT * FROM tb_subject WHERE tb_subject.code='"+m_subjectid+"' ";
	mysubjectset_find = new CSubjectinfo(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!mysubjectset_find->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_subject 表打开失败!");
	}
	if(mysubjectset_find->GetRecordCount()!=0)
	{
		AfxMessageBox("科目代码不能重复,请修改后再输入!");
		if(mysubjectset_find->IsOpen())
		{
			mysubjectset_find->Close();
			delete mysubjectset_find;
		}
		return;
	}
	if(mysubjectset_find->IsOpen())
	{
		mysubjectset_find->Close();
		delete mysubjectset_find;
	}  
	mysubjectset->AddNew();                //调用添加记录的函数处理
	mysubjectset->m_subject = m_subjectname; //对应变量更新
	mysubjectset->m_code    = m_subjectid;
	try
	{
		mysubjectset->Update();
		mysubjectset->Requery();
		AfxMessageBox("成功保存数据!");
	}
	catch( CDBException* e )
    {
        AfxMessageBox( e->m_strError,MB_ICONEXCLAMATION );
        e->Delete();
    }
	DisplayRecord(); //更新显示
}

void CSubjectdlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(mysubjectset->IsOpen())
	{
		mysubjectset->Close();
		delete mysubjectset;
	}
	CDialog::OnClose();
}

void CSubjectdlg::OnOK()
{

}
