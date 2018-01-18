// Examkinddlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Examkinddlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamkinddlg dialog


CExamkinddlg::CExamkinddlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExamkinddlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExamkinddlg)
	m_examkind = _T("");
	//}}AFX_DATA_INIT
}


void CExamkinddlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamkinddlg)
	DDX_Text(pDX, IDC_EDIT_examkind, m_examkind);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamkinddlg, CDialog)
	//{{AFX_MSG_MAP(CExamkinddlg)
	ON_COMMAND(ID_toolbar_examkind_add, Ontoolbarexamkindadd)
	ON_COMMAND(ID_toolbar_examkind_del, Ontoolbarexamkinddel)
	ON_COMMAND(ID_toolbar_examkind_first, Ontoolbarexamkindfirst)
	ON_COMMAND(ID_toolbar_examkind_last, Ontoolbarexamkindlast)
	ON_COMMAND(ID_toolbar_examkind_next, Ontoolbarexamkindnext)
	ON_COMMAND(ID_toolbar_examkind_pre, Ontoolbarexamkindpre)
	ON_COMMAND(ID_toolbar_examkind_save, Ontoolbarexamkindsave)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamkinddlg message handlers

BOOL CExamkinddlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE
		| CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC)
		||!m_ToolBar.LoadToolBar(IDR_TOOLBAR_examkinds))
	{
		TRACE0(_T("����������ʧ��\n"));
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
	sqlStr    = "SELECT * FROM tb_examkinds";
	myexamset = new CExamkindset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myexamset->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr)) //�����ݱ�
	{
		AfxMessageBox("tb_examkinds���ʧ��!");
	}
	return TRUE; 
}

void CExamkinddlg::Ontoolbarexamkindadd() 
{
	// TODO: Add your command handler code here	
	m_examkind = "";	
	UpdateData(FALSE);
}

void CExamkinddlg::Ontoolbarexamkinddel() 
{
	// TODO: Add your command handler code here
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_examinfo_sub WHERE tb_examinfo_sub.kind='"+m_examkind+"'";
	myexamset_findkind = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	   	
	if(!myexamset_findkind->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_examinfo_sub ���ʧ��!");
	}
	if(myexamset_findkind->GetRecordCount()!=0)
	{
		AfxMessageBox("�˿��������<������Ϣ��>��������,����ɾ��!");
		if(myexamset_findkind->IsOpen())
		{
			myexamset_findkind->Close();
			delete myexamset_findkind;
		}
		return;
	}
	if(myexamset_findkind->IsOpen())
	{
	   myexamset_findkind->Close();
	   delete myexamset_findkind;
	} 
	myexamset->Delete(); //ɾ����¼
	myexamset->Requery();
	DisplayRecord(); //������ʾ
}

void CExamkinddlg::Ontoolbarexamkindfirst() 
{
	// TODO: Add your command handler code here
	if(!myexamset->IsBOF())
	{
		myexamset->MoveFirst(); //��ǰ�ƶ�һ����¼
		DisplayRecord();        //���´�����ʾ
	}
}

void CExamkinddlg::Ontoolbarexamkindlast() 
{
	// TODO: Add your command handler code here
	if(!myexamset->IsEOF())
	{
		myexamset->MoveLast();
		DisplayRecord();
	}
}

void CExamkinddlg::Ontoolbarexamkindnext() 
{
	// TODO: Add your command handler code here
	if(!myexamset->IsEOF())
	{
		myexamset->MoveNext();
		DisplayRecord();
	}
}

void CExamkinddlg::Ontoolbarexamkindpre() 
{
	// TODO: Add your command handler code here
	if(!myexamset->IsBOF())
	{
		myexamset->MovePrev();
		DisplayRecord();
	}
}

void CExamkinddlg::Ontoolbarexamkindsave() 
{
	// TODO: Add your command handler code here
	
	UpdateData(TRUE);
	if(m_examkind.IsEmpty())
	{
		AfxMessageBox("��������Ӧ������!");
		return;
	}
	CString sqlStr_findid;
	sqlStr_findid="SELECT * FROM tb_examkinds WHERE tb_examkinds.kind='"+m_examkind+"'";
	myexamset_find = new CExamkindset(&((CMystudentsysApp*)AfxGetApp())->m_DB);	 
	if(!myexamset_find->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_findid))
	{
		AfxMessageBox("tb_examkinds ���ʧ��!");
	}
	if(myexamset_find->GetRecordCount()!=0)
	{
		AfxMessageBox("�˿�������Ѿ�����,���������������ظ�,���޸ĺ�������!");
		if(myexamset_find->IsOpen())
		{
		   myexamset_find->Close();
		}
		return;
	}
	if(myexamset_find->IsOpen())
	{
	   myexamset_find->Close();
	   delete myexamset_find;
	}  
	//������Ӽ�¼�ĺ�������
	myexamset->AddNew();
	myexamset->m_kind = m_examkind; //��Ӧ��������
	myexamset->Update();
	myexamset->Requery();
	DisplayRecord(); //������ʾ
}
bool CExamkinddlg::DisplayRecord()
{
	if(myexamset->IsEOF()&&myexamset->IsBOF())
	{
		m_examkind = "";
	}
	else
	{
		if(myexamset->IsBOF()) //�ƶ����˿�ͷ,������ƶ�
		{
			myexamset->MoveNext();
		}
		else //����ǰ��
		{
			if(myexamset->IsEOF())
			{
				myexamset->MovePrev();
			}
		}
	}
	m_examkind = myexamset->m_kind; //��Ӧ������ֵ
	UpdateData(FALSE); //��ʾ����
	return TRUE;

}

void CExamkinddlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myexamset->IsOpen())
	{
		myexamset->Close();
		delete myexamset;
	}
	CDialog::OnClose();
}

void CExamkinddlg::OnOK()
{

}
