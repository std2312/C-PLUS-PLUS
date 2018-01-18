// DlgDeskInfo1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgDeskInfo1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;
/////////////////////////////////////////////////////////////////////////////
// CDlgDeskInfo1 dialog


CDlgDeskInfo1::CDlgDeskInfo1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDeskInfo1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDeskInfo1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgDeskInfo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDeskInfo1)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_counter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDeskInfo1, CDialog)
	//{{AFX_MSG_MAP(CDlgDeskInfo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDeskInfo1 message handlers

BOOL CDlgDeskInfo1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_list.InsertColumn(1,"柜台名称",LVCFMT_LEFT,180);
	
	//加载柜台信息

	LoadCounterInfo();
	return TRUE;  
}

void CDlgDeskInfo1::LoadCounterInfo()
{
	m_pRs->raw_Close();
	CString sql,str;
	m_list.DeleteAllItems();
	sql.Format("select * from tb_counterinfo");
	m_pRs = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int row = 0;
	while(! m_pRs->adoEOF)
	{
		m_list.InsertItem(100,"");
		str = (TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)0)->Value;
		m_list.SetItemText(row,0,str);
		row +=1;
		m_pRs->MoveNext();
	}
}

void CDlgDeskInfo1::AddCounterInfo()
{
	CString kind;
	m_counter.GetWindowText(kind);
	if (! kind.IsEmpty())
	{
		try
		{
			CString sql;
			sql.Format("insert into tb_counterinfo values ('%s')",kind);

			m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
			m_pCom->CommandText = (_bstr_t)sql;
			m_pCom->Execute(NULL,NULL,adCmdText);
			LoadCounterInfo();
			MessageBox("操作成功");

		}
		catch(...)
		{
			MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
		}
	}
	else
		MessageBox("请输入柜台信息.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgDeskInfo1::DeleteCounterInfo()
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		if (MessageBox("确实要删除数据吗?","提示",MB_YESNO)==IDYES)
		{
			try
			{
				CString kind = m_list.GetItemText(row,0);
				CString sql;
				sql.Format("delete from tb_counterinfo where counter = '%s'",kind);
				m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
				LoadCounterInfo();
				MessageBox("操作成功.","提示",64);
			}
			catch(...)
			{
				MessageBox("操作失败.");
			}
		}
	}
	else
	{
		MessageBox("请在列表中选择欲删除的信息");
	}
}

BOOL CDlgDeskInfo1::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam = 9;	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgDeskInfo1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		m_counter.SetWindowText(m_list.GetItemText(row,0));
	}	
	//*pResult = 0;
}

void CDlgDeskInfo1::UpdateCounterInfo()
{
	CString counter,oldcounter;
	m_counter.GetWindowText(counter);
	int row= m_list.GetSelectionMark();
	if (row != -1)
	{
		if (! counter.IsEmpty())
		{
			try
			{
				oldcounter = m_list.GetItemText(row,0);
				CString sql;
				sql.Format("update tb_counterinfo set counter = ? where counter = ?");
				_ParameterPtr p1,p2;
				p1 = m_pCom->CreateParameter("aa",adVarChar,adParamInput,20);
				p1->Value = (_bstr_t)counter;
				p2 = m_pCom->CreateParameter("bb",adVarChar,adParamInput,20);
				p2->Value = (_bstr_t)oldcounter;
				m_pCom->Parameters->Append(p1);
				m_pCom->Parameters->Append(p2);

				m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
				m_pCom->CommandText = (_bstr_t)sql;
				m_pCom->Execute(NULL,NULL,adCmdText);
				
				m_pCom->Parameters->Delete("aa");
				m_pCom->Parameters->Delete("bb");
	
				LoadCounterInfo();
				MessageBox("操作成功");

			}
			catch(...)
			{
				MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
			}
		}
		else
			MessageBox("请输入柜台信息.","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
		MessageBox("请在表格中选择柜台信息.","提示",MB_OK|MB_ICONINFORMATION);
}


void CDlgDeskInfo1::OnCancel() 
{
	CDialog::OnCancel();	
}

void CDlgDeskInfo1::OnAdd() 
{
	AddCounterInfo();	
}

void CDlgDeskInfo1::OnChange() 
{
	UpdateCounterInfo();
}

void CDlgDeskInfo1::OnDel() 
{
	DeleteCounterInfo();
	
}
