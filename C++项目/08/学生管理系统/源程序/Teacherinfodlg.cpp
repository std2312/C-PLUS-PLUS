// Teacherinfodlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Teacherinfodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherinfodlg dialog


CTeacherinfodlg::CTeacherinfodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTeacherinfodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTeacherinfodlg)
	m_teachername = _T("");
	m_teacheroffice = _T("");
	m_teacherlevel = _T("");
	m_teacherknowledge = _T("");
	m_teacherid = _T("");
	m_teachersex = _T("");
	//}}AFX_DATA_INIT
}


void CTeacherinfodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeacherinfodlg)
	DDX_Control(pDX, IDC_COMBO_teachersex, m_teachersexc);
	DDX_Text(pDX, IDC_teachername, m_teachername);
	DDX_Text(pDX, IDC_teacheroffice, m_teacheroffice);
	DDX_Text(pDX, IDC_teacherlevel, m_teacherlevel);
	DDX_Text(pDX, IDC_teacherkonwledge, m_teacherknowledge);
	DDX_Text(pDX, IDC_teacherid, m_teacherid);
	DDX_CBString(pDX, IDC_COMBO_teachersex, m_teachersex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeacherinfodlg, CDialog)
	//{{AFX_MSG_MAP(CTeacherinfodlg)
	ON_COMMAND(ID_teacherinfo_toolbar_add, Onteacherinfotoolbaradd)
	ON_COMMAND(ID_teacherinfo_toolbar_del, Onteacherinfotoolbardel)
	ON_COMMAND(ID_teacherinfo_toolbar_first, Onteacherinfotoolbarfirst)
	ON_COMMAND(ID_teacherinfo_toolbar_last, Onteacherinfotoolbarlast)
	ON_COMMAND(ID_teacherinfo_toolbar_next, Onteacherinfotoolbarnext)
	ON_COMMAND(ID_teacherinfo_toolbar_pre, Onteacherinfotoolbarpre)
	ON_COMMAND(ID_teacherinfo_toolbar_save, Onteacherinfotoolbarsave)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeacherinfodlg message handlers

BOOL CTeacherinfodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE
		| CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC)
		||!m_ToolBar.LoadToolBar(IDR_TOOLBAR_teacherinfo))
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
	CString sqlStr;
	sqlStr="SELECT * FROM tb_teacher";
	myteacherset = new CTeacherinfoset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myteacherset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_teacher表打开失败!");
	}
	return TRUE;
}

void CTeacherinfodlg::Onteacherinfotoolbaradd() 
{
	// TODO: Add your command handler code here
	m_teachername      = "";
	m_teacheroffice    = "";
	m_teacherlevel     = "";
	m_teacherknowledge = "";
	m_teacherid        = "";
	m_teachersex       = "";
	UpdateData(FALSE);
}

void CTeacherinfodlg::Onteacherinfotoolbardel() 
{
	// TODO: Add your command handler code here
	myteacherset->Delete();
	myteacherset->Requery();
	DisplayRecord();
}

void CTeacherinfodlg::Onteacherinfotoolbarfirst() 
{
	// TODO: Add your command handler code here
	if(!myteacherset->IsBOF())
	{
		myteacherset->MoveFirst();
		DisplayRecord();
	}
}

void CTeacherinfodlg::Onteacherinfotoolbarlast() 
{
	// TODO: Add your command handler code here
	if(!myteacherset->IsEOF())
	{
		myteacherset->MoveLast();
		DisplayRecord();
	}
}

void CTeacherinfodlg::Onteacherinfotoolbarnext() 
{
	// TODO: Add your command handler code here
	if(!myteacherset->IsBOF())
	{
		myteacherset->MoveNext();
		DisplayRecord();
	}
}

void CTeacherinfodlg::Onteacherinfotoolbarpre() 
{
	// TODO: Add your command handler code here
	if(!myteacherset->IsEOF())
	{
		myteacherset->MovePrev();
		DisplayRecord();
	}
}

void CTeacherinfodlg::Onteacherinfotoolbarsave() 
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);
	if(m_teacherid.IsEmpty()||m_teachername.IsEmpty()||m_teacheroffice.IsEmpty()
		||m_teacherknowledge.IsEmpty()||m_teachersex.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_office WHERE tb_office.Office='"+m_teacheroffice+"'";
	myofficeset_find = new officeset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myofficeset_find->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_studentinfo表打开失败!");
	}
	if(myofficeset_find->GetRecordCount() == 0)
	{
		AfxMessageBox("没有此科室,请确认后再输入!");
		if(myofficeset_find->IsOpen())
		{
			myofficeset_find->Close();
			delete myofficeset_find;
		}
		return;
	}
	if(myofficeset_find->IsOpen())
	{
		myofficeset_find->Close();
		delete myofficeset_find;
	} 
	myteacherset->AddNew();                    //调用添加记录的函数处理
	myteacherset->m_teacherid   = m_teacherid; //对应变量更新
	myteacherset->m_teachername = m_teachername;
    myteacherset->m_sex         = m_teachersex;
	myteacherset->m_office      = m_teacheroffice;
	myteacherset->m_knowledge   = m_teacherknowledge;
    myteacherset->m_Level       = m_teacherlevel;
	try
	{
		myteacherset->Update();
		myteacherset->Requery();
		AfxMessageBox("成功保存数据!");
	}
	catch( CDBException* e )
    {
        AfxMessageBox( e->m_strError, MB_ICONEXCLAMATION );
        e->Delete();
    }
	DisplayRecord();//更新显示
}
bool CTeacherinfodlg::DisplayRecord()
{
	if(myteacherset->IsBOF() && myteacherset->IsEOF())
	{
		m_teachername      = "";
	    m_teacheroffice    = "";
	    m_teacherlevel     = "";
	    m_teacherknowledge = "";
	    m_teacherid        = "";
	    m_teachersex       = "";
		
	}
	else
	{
		if(myteacherset->IsBOF())
		{
			myteacherset->MoveNext();
		}
		else
		{
			if(myteacherset->IsEOF())
			{
				myteacherset->MovePrev();
			}
		}
	}
	m_teachername      = myteacherset->m_teachername;
	m_teacheroffice    = myteacherset->m_office;
	m_teacherlevel     = myteacherset->m_Level;
	m_teacherknowledge = myteacherset->m_knowledge;
	m_teacherid        = myteacherset->m_teacherid;
	m_teachersex       = myteacherset->m_sex;
	UpdateData(FALSE);
	return TRUE;

}

void CTeacherinfodlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myteacherset->IsOpen())
	{
		myteacherset->Close();
		delete myteacherset;
	}
	CDialog::OnClose();
}

void CTeacherinfodlg::OnOK()
{

}
