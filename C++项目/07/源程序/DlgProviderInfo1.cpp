// DlgProviderInfo1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgProviderInfo1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;
/////////////////////////////////////////////////////////////////////////////
// CDlgProviderInfo1 dialog


CDlgProviderInfo1::CDlgProviderInfo1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgProviderInfo1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgProviderInfo1)
	//}}AFX_DATA_INIT
}


void CDlgProviderInfo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgProviderInfo1)
	DDX_Control(pDX, IDC_PROVIDER1, m_provider);
	DDX_Control(pDX, IDC_PROVIDER_PHONE1, m_phone);
	DDX_Control(pDX, IDC_PROVIDER_EMAIL1, m_email);
	DDX_Control(pDX, IDC_PROVIDER_CEO1, m_corporation);
	DDX_Control(pDX, IDC_PROVIDER_ADDRESS1, m_addr);
	DDX_Control(pDX, IDC_NET_ADDRESS1, m_netaddr);
	DDX_Control(pDX, IDC_MANAGER1, m_principal);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgProviderInfo1, CDialog)
	//{{AFX_MSG_MAP(CDlgProviderInfo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgProviderInfo1 message handlers

BOOL CDlgProviderInfo1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FLATSB);
	
	m_list.InsertColumn(0,"供应商名称",LVCFMT_LEFT,100);
	m_list.InsertColumn(1,"法人",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"负责人",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"联系电话",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"详细地址",LVCFMT_LEFT,100);
	m_list.InsertColumn(5,"网址",LVCFMT_LEFT,100);
	m_list.InsertColumn(6,"邮箱",LVCFMT_LEFT,100);

	LoadProviderInfo();//加载供应商信息	
	return TRUE;  
}

void CDlgProviderInfo1::LoadProviderInfo()
{
	m_list.DeleteAllItems();
	m_pRs->raw_Close();
	CString sql,temp;
	sql.Format("select * from tb_providerinfo");
	m_pRs = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int row = 0;
	while (!m_pRs->adoEOF)
	{
		m_list.InsertItem(100,"");
		for (int i = 0; i<m_pRs->GetFields()->Count;i++)
		{
			temp = (TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
			m_list.SetItemText(row,i,temp);
		}		
		row +=1;
		m_pRs->MoveNext();
	}	
}

BOOL CDlgProviderInfo1::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message ==	WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam = 9;
	return CDialog::PreTranslateMessage(pMsg);
}

bool CDlgProviderInfo1::InfoIsNull()
{
	CWnd * temp;
	temp = this;
	CString text;
	for (int index = 0; index <7;index++)
	{
		temp = this->GetNextDlgTabItem(temp);
		temp->GetWindowText(text);
		if (text.IsEmpty())
			return true;
	}
	return false;
}

void CDlgProviderInfo1::AddProvider()
{
	if (InfoIsNull())
	{
		MessageBox("供应商信息不能为空.","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}

	CString c_provider,c_principal,c_phone,c_corporation,c_addr,c_netaddr,c_email;
	m_addr.GetWindowText(c_addr);
	m_corporation.GetWindowText(c_corporation);
	m_email.GetWindowText(c_email);
	m_netaddr.GetWindowText(c_netaddr);
	m_phone.GetWindowText(c_phone);
	m_principal.GetWindowText(c_principal);
	m_provider.GetWindowText(c_provider);

	CString sql;
	sql.Format("Insert into tb_providerinfo values ( '%s','%s','%s','%s','%s','%s','%s')",c_provider,c_corporation,c_principal,c_phone,c_addr,c_netaddr,c_email);
	try
	{
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		MessageBox("操作成功.","提示",MB_OK|MB_ICONINFORMATION);
		ClearInterface();
		LoadProviderInfo();
	}
	catch(...)
	{
		MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
	}
}

void CDlgProviderInfo1::ClearInterface()
{
	CWnd * temp;
	temp = this;
	CString text;
	for (int index = 0; index <8;index++)
	{
		temp = this->GetNextDlgTabItem(temp);
		temp->SetWindowText("");
	}
}

void CDlgProviderInfo1::DeleteProvider()
{
	if (m_list.GetSelectionMark()!=-1)
	{
		if (MessageBox("确实要删除数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{
			int i = m_list.GetSelectionMark();
			CString c_provider = m_list.GetItemText(i,0);
			CString sql;
			sql.Format("delete tb_providerinfo where provider= '%s'",c_provider);
			m_pRs->raw_Close();
			try
			{
				m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
				ClearInterface();
				LoadProviderInfo();
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

void CDlgProviderInfo1::UpdateProvider()
{
	if (!InfoIsNull())
	{
		if (m_list.GetSelectionMark()!=-1)
		{
			if (MessageBox("确实要修改数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
			{
				CString c_provider;
				c_provider = m_list.GetItemText(m_list.GetSelectionMark(),0);

				CString c_provider1,c_principal,c_phone,c_corporation,c_addr,c_netaddr,c_email;
				m_addr.GetWindowText(c_addr);
				m_corporation.GetWindowText(c_corporation);
				m_email.GetWindowText(c_email);
				m_netaddr.GetWindowText(c_netaddr);
				m_phone.GetWindowText(c_phone);
				m_principal.GetWindowText(c_principal);
				m_provider.GetWindowText(c_provider1);

				CString sql;
				sql.Format("update tb_providerinfo set provider ='%s',corporation = '%s',principal = '%s',phone = '%s',addr = '%s',web = '%s',e_mail = '%s' where provider = '%s' "
					,c_provider1,c_corporation,c_principal,c_phone,c_addr,c_netaddr,c_email,c_provider);
				m_pRs->raw_Close();
				try
				{
					m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					ClearInterface();
					LoadProviderInfo();
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

void CDlgProviderInfo1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)
	{
		CWnd * temp;
		temp = this;
		CString text;
		
		for (int index = 0; index <7;index++)
		{
			temp = this->GetNextDlgTabItem(temp);
			text = m_list.GetItemText(row,index);
			temp->SetWindowText(text);
		}
	}
	
//	*pResult = 0;
}



void CDlgProviderInfo1::OnCancel() 
{
	CDialog::OnCancel();	
}

void CDlgProviderInfo1::OnAdd() 
{
	AddProvider();
	
}

void CDlgProviderInfo1::OnChange() 
{
	UpdateProvider();
	
}

void CDlgProviderInfo1::OnDel() 
{
	DeleteProvider();
	
}
