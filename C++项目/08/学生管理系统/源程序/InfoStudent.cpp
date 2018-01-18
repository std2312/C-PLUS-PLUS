// InfoStudent.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "InfoStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoStudent dialog


CInfoStudent::CInfoStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoStudent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfoStudent)
	m_studentaddr = _T("");
	m_studentage = 0.0f;
	m_studentclass = _T("");
	m_studentname = _T("");
	m_studentphone = _T("");
	m_studentsex = _T("");
	m_studentid = _T("");
	//}}AFX_DATA_INIT
}


void CInfoStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoStudent)
	DDX_Text(pDX, IDC_studentaddr, m_studentaddr);
	DDX_Text(pDX, IDC_studentage, m_studentage);
	DDX_Text(pDX, IDC_studentclass, m_studentclass);
	DDX_Text(pDX, IDC_studentname, m_studentname);
	DDX_Text(pDX, IDC_studentphone, m_studentphone);
	DDX_Text(pDX, IDC_studentsex, m_studentsex);
	DDX_Text(pDX, IDC_findstudent_id, m_studentid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoStudent, CDialog)
	//{{AFX_MSG_MAP(CInfoStudent)
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
// CInfoStudent message handlers

BOOL CInfoStudent::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
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
	sqlStr="SELECT * FROM tb_studentinfo";
	mystudentset = new CStudentinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!mystudentset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_studentinfo表打开失败!");
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool CInfoStudent::DisplayRecord()
{
	if(mystudentset->IsBOF()&&mystudentset->IsEOF())
	{
		m_studentaddr  = "";
	    m_studentage   = 0.0f;
	    m_studentclass = "";
	    m_studentname  = "";
	    m_studentphone = "";
    	m_studentsex   = "";
    	m_studentid    = "";
	}
	else
	{
		if(mystudentset->IsBOF()) //移动到了开头,就向后移动
		{
			mystudentset->MoveNext();
		}
		else //否则前移
		{
			if(mystudentset->IsEOF())
			{
				mystudentset->MovePrev();
			}
		}
	}
	m_studentaddr  = mystudentset->m_addr;
	m_studentage   = mystudentset->m_age;
	m_studentclass = mystudentset->m_class;
	m_studentname  = mystudentset->m_studentname;
	m_studentphone = mystudentset->m_phone;
	m_studentsex   = mystudentset->m_sex;	
	m_studentid    = mystudentset->m_studentid;
	UpdateData(FALSE);
	return TRUE;

}

void CInfoStudent::Onsubjectinfotoolbaradd() 
{
	// TODO: Add your command handler code here
	m_studentaddr  = "";
    m_studentage   = 0.0f;
    m_studentclass = "";
    m_studentname  = "";
    m_studentphone = "";
 	m_studentsex   = "";
 	m_studentid    = "";
	UpdateData(FALSE);
}

void CInfoStudent::Onsubjectinfotoolbardel() 
{
	// TODO: Add your command handler code here
	mystudentset->Delete(); //删除记录
	mystudentset->Requery();
	DisplayRecord(); 
}

void CInfoStudent::Onsubjectinfotoolbarfirst() 
{
	// TODO: Add your command handler code here
	if(!mystudentset->IsBOF())
	{
		mystudentset->MoveFirst(); //向前移动一条记录
		DisplayRecord();           //更新窗口显示
	}
}

void CInfoStudent::Onsubjectinfotoolbarlast() 
{
	// TODO: Add your command handler code here
	if(!mystudentset->IsEOF())
	{
		mystudentset->MoveLast();
		DisplayRecord();
	}
}

void CInfoStudent::Onsubjectinfotoolbarnext() 
{
	// TODO: Add your command handler code here
	if(!mystudentset->IsEOF())
	{
		mystudentset->MoveNext();
		DisplayRecord();
	}
}

void CInfoStudent::Onsubjectinfotoolbarpre() 
{
	// TODO: Add your command handler code here
	if(!mystudentset->IsBOF())
	{
		mystudentset->MovePrev();
		DisplayRecord();
	}
}

void CInfoStudent::Onsubjectinfotoolbarsave() 
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);
	if(m_studentaddr.IsEmpty()||m_studentclass.IsEmpty()
		||m_studentname.IsEmpty()||m_studentphone.IsEmpty()
		||m_studentsex.IsEmpty()||m_studentid.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return ;
	}
	mystudentset->AddNew(); //调用添加记录的函数处理
	mystudentset->m_studentid   = m_studentid;
	mystudentset->m_addr        = m_studentaddr;
	mystudentset->m_age         = m_studentage;
	mystudentset->m_class       = m_studentclass;
	mystudentset->m_studentname = m_studentname;
	mystudentset->m_phone       = m_studentphone; 
	mystudentset->m_sex         = m_studentsex;		
	mystudentset->Update();
	mystudentset->Requery();
	AfxMessageBox("成功保存数据!");
	DisplayRecord(); //更新显示
}

void CInfoStudent::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(mystudentset->IsOpen())
	{
		mystudentset->Close();
		delete mystudentset;
	}
	CDialog::OnClose();
}
