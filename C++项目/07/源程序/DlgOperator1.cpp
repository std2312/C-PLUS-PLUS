// DlgOperator1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgOperator1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
/////////////////////////////////////////////////////////////////////////////
// CDlgOperator1 dialog


CDlgOperator1::CDlgOperator1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOperator1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOperator1)
	//}}AFX_DATA_INIT
}


void CDlgOperator1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOperator1)
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_OPERATOR, m_operator);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMB_JB, m_level);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOperator1, CDialog)
	//{{AFX_MSG_MAP(CDlgOperator1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOperator1 message handlers

BOOL CDlgOperator1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_list.ModifyStyle(LVS_EDITLABELS,0);
	m_list.ModifyStyle(0,LVS_REPORT);
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE|LVS_EX_FLATSB);
	
	m_list.InsertColumn(0,"操作员名称");
	m_list.InsertColumn(1,"操作员密码");
	m_list.InsertColumn(2,"操作员级别");
	
	m_list.SetColumnWidth(0,200);
	m_list.SetColumnWidth(1,130);
	m_list.SetColumnWidth(2,100);

	LoadOperatorInfo();//加载操作员信息
	return TRUE;  
}

BOOL CDlgOperator1::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam =9;
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgOperator1::LoadOperatorInfo()
{
	m_list.DeleteAllItems();
	m_pRs->raw_Close();
	CString sql;
	sql.Format("select * from tb_operator");
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int row = 0;
	CString itemtext;
	while (! m_pRs->adoEOF)
	{
		m_list.InsertItem(100,"");
		for (int index = 0;index <m_pRs->Fields->Count;index++)
		{
			itemtext =(TCHAR*)(_bstr_t) m_pRs->GetFields()->GetItem((long)index)->Value;
			m_list.SetItemText(row,index,itemtext);
		}
		row += 1;
		m_pRs->MoveNext();
	}
}

void CDlgOperator1::AddOperator()
{
	//判断基础信息是否为空
	if (!InfoIsNull())
	{
		CString c_operator,c_password,c_level;
		m_operator.GetWindowText(c_operator);
		m_password.GetWindowText(c_password);
		m_level.GetWindowText(c_level);	
		int level= atoi(c_level);
		CString sql;
		sql.Format("insert into tb_operator values ('%s','%s',%d)",c_operator,c_password,level);
		if (m_pRs->State ==adStateOpen)
			m_pRs->raw_Close();
		try
		{
			m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			LoadOperatorInfo();
			ClearInterface();
			MessageBox("操作成功.","提示",MB_OK);
		}
		catch(_com_error *e)
		{
			
			MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
		}
	}
	else
		MessageBox("基础信息不能为空.","提示",MB_OK+MB_ICONINFORMATION);
}

bool CDlgOperator1::InfoIsNull()
{
	CString c_operator,c_password,c_level;
	m_operator.GetWindowText(c_operator);
	m_password.GetWindowText(c_password);
	m_level.GetWindowText(c_level);
	if (c_operator.IsEmpty()||c_password.IsEmpty()||c_level.IsEmpty())
		return true;
	return false;
}

void CDlgOperator1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		m_operator.SetWindowText(m_list.GetItemText(row,0));
		m_password.SetWindowText(m_list.GetItemText(row,1));
		m_level.SetCurSel(m_level.FindString(0,m_list.GetItemText(row,2)));
	}	
	*pResult = 0;
}

void CDlgOperator1::ClearInterface()
{
	m_operator.SetWindowText("");
	m_password.SetWindowText("");
	m_level.SetCurSel(-1);
}

void CDlgOperator1::UpdateOperator()
{
	if (!InfoIsNull())
	{
		if (m_list.GetSelectionMark()!=-1)
		{
			if (MessageBox("确实要修改数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
			{
				CString c_operator,c_password,c_level;
				m_operator.GetWindowText(c_operator);
				m_password.GetWindowText(c_password);
				m_level.GetWindowText(c_level);	
				int level= atoi(c_level);
				int i = m_list.GetSelectionMark();
				CString c_name = m_list.GetItemText(i,0);
				CString sql;
				sql.Format("update tb_operator set name = '%s',password = '%s',[level] = %d where name = '%s'",c_operator,c_password,level,c_name);
				m_pRs->raw_Close();
				try
				{
					m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					ClearInterface();
					LoadOperatorInfo();
					MessageBox("操作成功.","提示",64);
				}
				catch(...)
				{
					MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
				}
			}
		}
		else
			MessageBox("请选择欲修改的信息.","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
		MessageBox("基础信息不完整.","提示",MB_OK|MB_ICONINFORMATION);
}

bool CDlgOperator1::InfoIsExist(LPTSTR name)
{
	CString sql;
	sql.Format("select * from tb_operator where name = '%s'",name);
	m_pRs->raw_Close();
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	if (m_pRs->RecordCount>1)
		return true;
	return false;
}

void CDlgOperator1::DeleteOperator()
{
	if (m_list.GetSelectionMark()!=-1)
	{
		if (MessageBox("确实要删除数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{
			int i = m_list.GetSelectionMark();
			CString c_name = m_list.GetItemText(i,0);
			CString sql;
			sql.Format("delete tb_operator where name= '%s'",c_name);
			m_pRs->raw_Close();
			try
			{
				m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
				ClearInterface();
				LoadOperatorInfo();
				MessageBox("操作成功.","提示",64);
			}
			catch(...)
			{
				MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
			}
		}
	}
	else
		MessageBox("请选择欲删除的信息.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgOperator1::OnAdd() 
{
	AddOperator() ;	
}

void CDlgOperator1::OnChange() 
{
	UpdateOperator();
	
}

void CDlgOperator1::OnDel() 
{
	DeleteOperator();	
}

void CDlgOperator1::OnCancel() 
{
	CDialog::OnCancel();
	
}
