// DlgStoreInfo1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgStoreInfo1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;
/////////////////////////////////////////////////////////////////////////////
// CDlgStoreInfo1 dialog


CDlgStoreInfo1::CDlgStoreInfo1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgStoreInfo1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgStoreInfo1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDlgStoreInfo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgStoreInfo1)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_storage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgStoreInfo1, CDialog)
	//{{AFX_MSG_MAP(CDlgStoreInfo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgStoreInfo1 message handlers

void CDlgStoreInfo1::OnOK()
{
//prevent pressing enter key to close form
}

BOOL CDlgStoreInfo1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//修改列表框风格
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//添加列,设置列宽度

	m_list.InsertColumn(1,"仓库名称",LVCFMT_CENTER,180);
	m_list.SetTextColor(RGB(0,0,255));
	//加载仓库信息
	LoadStorageInfo();
	return TRUE;  
}

void CDlgStoreInfo1::LoadStorageInfo()
{
	m_pRs->raw_Close();
	CString sql,str;
	m_list.DeleteAllItems();
	sql.Format("select * from tb_storageinfo");
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

void CDlgStoreInfo1::AddStorageInfo()
{
	CString storage;
	m_storage.GetWindowText(storage);
	if (! storage.IsEmpty())
	{
		try
		{
			CString sql;
			sql.Format("insert into tb_storageinfo values ('%s')",storage);

			m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
			m_pCom->CommandText = (_bstr_t)sql;
			m_pCom->Execute(NULL,NULL,adCmdText);
			LoadStorageInfo();
			MessageBox("操作成功");
		}
		catch(...)
		{
			MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
		}

	}
	else
		MessageBox("请输入仓库信息.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgStoreInfo1::DeleteStorageInfo()
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		if (MessageBox("确实要删除数据吗?","提示",MB_YESNO)==IDYES)
		{
			try
			{
				CString storage = m_list.GetItemText(row,0);
				CString sql;
				sql.Format("delete from tb_storageinfo where storagename = '%s'",storage);
				m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
				LoadStorageInfo();
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

void CDlgStoreInfo1::UpdateStorageInfo()
{
	CString storage,oldstorage;
	m_storage.GetWindowText(storage);
	int row= m_list.GetSelectionMark();
	if (row != -1)
	{
		if (! storage.IsEmpty())
		{
			try
			{
				oldstorage = m_list.GetItemText(row,0);
				CString sql;
				sql.Format("update tb_storageinfo set storagename = ? where storagename = ?");
				_ParameterPtr p1,p2;
				p1 = m_pCom->CreateParameter("aa",adVarChar,adParamInput,20);
				p1->Value = (_bstr_t)storage;
				p2 = m_pCom->CreateParameter("bb",adVarChar,adParamInput,20);
				p2->Value = (_bstr_t)oldstorage;
				m_pCom->Parameters->Append(p1);
				m_pCom->Parameters->Append(p2);

				m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
				m_pCom->CommandText = (_bstr_t)sql;
				m_pCom->Execute(NULL,NULL,adCmdText);
				
				m_pCom->Parameters->Delete("aa");
				m_pCom->Parameters->Delete("bb");
	
				LoadStorageInfo();
				MessageBox("操作成功");

			}
			catch(...)
			{
				MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
			}
		}
		else
			MessageBox("请输入仓库信息.","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
		MessageBox("请在表格中选择仓库信息.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgStoreInfo1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		m_storage.SetWindowText(m_list.GetItemText(row,0));	
	}
}

BOOL CDlgStoreInfo1::PreTranslateMessage(MSG* pMsg) 
{
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgStoreInfo1::OnCancel() 
{
	CDialog::OnCancel();	
}

void CDlgStoreInfo1::OnAdd() 
{
	AddStorageInfo();	
}

void CDlgStoreInfo1::OnChange() 
{
	UpdateStorageInfo();
	
}

void CDlgStoreInfo1::OnDel() 
{
	DeleteStorageInfo();
	
}
