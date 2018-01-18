// DlgBookKinds1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgBookKinds1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;
/////////////////////////////////////////////////////////////////////////////
// CDlgBookKinds1 dialog


CDlgBookKinds1::CDlgBookKinds1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBookKinds1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBookKinds1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgBookKinds1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBookKinds1)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BOOK_KINDS1, m_bookkind);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBookKinds1, CDialog)
	//{{AFX_MSG_MAP(CDlgBookKinds1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CDlgBookKinds1 message handlers

BOOL CDlgBookKinds1::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam = 9;
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDlgBookKinds1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//设置列表风格
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FLATSB);


	//添加列
	m_list.InsertColumn(1,"图书种类",LVCFMT_LEFT,180);
	//加载图书种类信息
	LoadBookKinds();
	return TRUE;  
}

void CDlgBookKinds1::LoadBookKinds()
{
	m_pRs->raw_Close();
	CString sql,str;
	m_list.DeleteAllItems();
	sql.Format("select * from tb_bookkinds");
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

void CDlgBookKinds1::AddBookKind()
{
	CString kind;
	m_bookkind.GetWindowText(kind);
	if (! kind.IsEmpty())
	{
		try
		{
			CString sql;
			sql.Format("insert into tb_bookkinds values ('%s')",kind);

			m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
			m_pCom->CommandText = (_bstr_t)sql;
			m_pCom->Execute(NULL,NULL,adCmdText);
			LoadBookKinds();
			MessageBox("操作成功");
		}
		catch(...)
		{
			MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
		}

	}
	else
		MessageBox("请输入图书种类.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgBookKinds1::UpdateBookKind()
{
	CString kind,oldkind;
	m_bookkind.GetWindowText(kind);
	int row= m_list.GetSelectionMark();
	if (row != -1)
	{
		if (! kind.IsEmpty())
		{
			try
			{
				oldkind = m_list.GetItemText(row,0);
				CString sql;
				sql.Format("update tb_bookkinds set bookkind = ? where bookkind = ?");
				_ParameterPtr p1,p2;
				p1 = m_pCom->CreateParameter("aa",adVarChar,adParamInput,20);
				p1->Value = (_bstr_t)kind;
				p2 = m_pCom->CreateParameter("bb",adVarChar,adParamInput,20);
				p2->Value = (_bstr_t)oldkind;
				m_pCom->Parameters->Append(p1);
				m_pCom->Parameters->Append(p2);

				m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
				m_pCom->CommandText = (_bstr_t)sql;
				m_pCom->Execute(NULL,NULL,adCmdText);
				
				m_pCom->Parameters->Delete("aa");
				m_pCom->Parameters->Delete("bb");
	
				LoadBookKinds();
				MessageBox("操作成功");

			}
			catch(...)
			{
				MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
			}
		}
		else
			MessageBox("请输入图书种类.","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
		MessageBox("请在表格中选择图书种类.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgBookKinds1::DeleteBookKind()
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
				sql.Format("delete from tb_bookkinds where bookkind = '%s'",kind);
				m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
				LoadBookKinds();
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

void CDlgBookKinds1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		m_bookkind.SetWindowText(m_list.GetItemText(row,0));
	}
	//*pResult = 0;
}

void CDlgBookKinds1::OnPaint() 
{
	CPaintDC dc(this); 
	m_list.SetTextColor(RGB(0,0,255));	

}

void CDlgBookKinds1::OnAdd() 
{
	AddBookKind();
	
}

void CDlgBookKinds1::OnChange() 
{
	UpdateBookKind();	
}

void CDlgBookKinds1::OnDel() 
{
	DeleteBookKind();
	
}

void CDlgBookKinds1::OnCancel() 
{
	CDialog::OnCancel();	
}
