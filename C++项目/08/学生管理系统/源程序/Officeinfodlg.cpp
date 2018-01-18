// Officeinfodlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Officeinfodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COfficeinfodlg dialog


COfficeinfodlg::COfficeinfodlg(CWnd* pParent /*=NULL*/)
	: CDialog(COfficeinfodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COfficeinfodlg)
	m_officename = _T("");
	//}}AFX_DATA_INIT
}


void COfficeinfodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COfficeinfodlg)
	DDX_Text(pDX, IDC_EDIT_officename, m_officename);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COfficeinfodlg, CDialog)
	//{{AFX_MSG_MAP(COfficeinfodlg)
	ON_BN_CLICKED(IDC_BUTTON_first, OnBUTTONfirst)
	ON_BN_CLICKED(IDC_BUTTON_last, OnBUTTONlast)
	ON_BN_CLICKED(IDC_BUTTON_next, OnBUTTONnext)
	ON_BN_CLICKED(IDC_BUTTON_pre, OnBUTTONpre)
	ON_BN_CLICKED(IDC_BUTTON_add, OnBUTTONadd)
	ON_BN_CLICKED(IDC_BUTTON_save, OnBUTTONsave)
	ON_BN_CLICKED(IDC_BUTTON_del, OnBUTTONdel)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COfficeinfodlg message handlers

void COfficeinfodlg::OnBUTTONfirst() 
{
	// TODO: Add your control notification handler code here
	if(!myofficeset->IsBOF())
	{
		myofficeset->MoveFirst(); //向前移动一条记录
		DisplayRecord();          //更新窗口显示
	}
}

BOOL COfficeinfodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString sqlStr;
	sqlStr="SELECT * FROM tb_office";
	myofficeset = new officeset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myofficeset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //打开数据表
	{
		AfxMessageBox("tb_office表打开失败!");
	}
	return TRUE; 
}

bool COfficeinfodlg::DisplayRecord()
{
	if(myofficeset->IsEOF()&&myofficeset->IsBOF())
	{
		m_officename="";
	}
	else
	{
		if(myofficeset->IsBOF()) //移动到了开头,就向后移动
		{
			myofficeset->MoveNext();
		}
		else //否则前移
		{
			if(myofficeset->IsEOF())
			{
				myofficeset->MovePrev();
			}
		}
	}
	m_officename = myofficeset->m_Office; //对应变量赋值	
	UpdateData(FALSE);                 
	return TRUE;
}

void COfficeinfodlg::OnBUTTONlast() 
{
	// TODO: Add your control notification handler code here
	if(!myofficeset->IsEOF())
	{
		myofficeset->MoveLast();
		DisplayRecord(); 
	}
}

void COfficeinfodlg::OnBUTTONnext() 
{
	// TODO: Add your control notification handler code here
	if(!myofficeset->IsEOF())
	{
		myofficeset->MoveNext();
		DisplayRecord(); 
	}
}

void COfficeinfodlg::OnBUTTONpre() 
{
	// TODO: Add your control notification handler code here
	if(!myofficeset->IsBOF())
	{
		myofficeset->MovePrev();
		DisplayRecord(); 
	}
}

void COfficeinfodlg::OnBUTTONadd() 
{
	// TODO: Add your control notification handler code here
	m_officename = "";
	UpdateData(FALSE);
}

void COfficeinfodlg::OnBUTTONsave() 
{
	UpdateData(TRUE);
	if(m_officename.IsEmpty())
	{
		AfxMessageBox("请输入相应的数据!");
		return;
	}
	CString  sql;
	sql.Format("SELECT * FROM tb_office WHERE office = '%s'",m_officename);
	myofficeset_find = new officeset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	
	if(!myofficeset_find->Open(AFX_DB_USE_DEFAULT_TYPE,sql))
	{
		AfxMessageBox("tb_office 表打开失败!");
	}
	if(myofficeset_find->GetRecordCount()!=0)
	{
		AfxMessageBox("科室名称不能重复,请修改后再输入!");

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
	myofficeset->AddNew();                //调用添加记录的函数处理
	myofficeset->m_Office = m_officename; //对应变量更新
	myofficeset->Update();
	myofficeset->Requery();
	DisplayRecord();
}

void COfficeinfodlg::OnBUTTONdel() 
{
	myofficeset->Delete(); //删除记录
	myofficeset->Requery();
	DisplayRecord();
}

void COfficeinfodlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myofficeset->IsOpen())
	{
		myofficeset->Close(); //记录集关闭
		delete myofficeset;
	}
	CDialog::OnClose();
}

void COfficeinfodlg::OnOK()
{

}
