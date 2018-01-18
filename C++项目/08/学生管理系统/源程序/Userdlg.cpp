// Userdlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Userdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserdlg dialog


CUserdlg::CUserdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserdlg)
	m_Name = _T("");
	m_PassWord = _T("");
	//}}AFX_DATA_INIT
}


void CUserdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserdlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserdlg, CDialog)
	//{{AFX_MSG_MAP(CUserdlg)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTADD, OnButtadd)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserdlg message handlers

BOOL CUserdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //创建列表视图窗口
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_List.SetImageList(&m_ImageList,LVSIL_NORMAL);
	CString sql;
	sql.Format("select * from tb_user ",m_Name,m_PassWord);
	m_LoginSet = new CLoginSet(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!m_LoginSet->Open(AFX_DB_USE_DEFAULT_TYPE,sql))
	{
		AfxMessageBox("tb_studentinfo 表打开失败!");
	}
	DisplayRecord();
	return TRUE; 
}

void CUserdlg::DisplayRecord()
{
	int i = 0;
	while(!m_LoginSet->IsEOF())
	{
		//向列表视图中添加数据
		m_List.InsertItem(i,m_LoginSet->m_username,0);
		m_LoginSet->MoveNext();
		i++;
	}
}

void CUserdlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_LoginSet->IsOpen())
	{
		m_LoginSet->Close();
		delete m_LoginSet;
	} 
	CDialog::OnClose();
}

void CUserdlg::OnButtadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	m_LoginSet->AddNew();
	m_LoginSet->m_username = m_Name;
	m_LoginSet->m_password = m_PassWord;
	m_LoginSet->Update();
	m_LoginSet->Requery();
	m_List.DeleteAllItems();
	DisplayRecord(); 
}

void CUserdlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	m_LoginSet->MoveFirst();
	while(!m_LoginSet->IsEOF())
	{
		if(m_Name != m_LoginSet->m_username)
		{
			m_LoginSet->MoveNext();
		}
		else
		{
			m_LoginSet->Edit();
			m_LoginSet->m_username = m_Name;
			m_LoginSet->m_password = m_PassWord;
			m_LoginSet->Update();
			m_LoginSet->Requery();
			m_List.DeleteAllItems();
			DisplayRecord(); 
			return;
		}
	}
}

void CUserdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_List.GetSelectionMark();
	m_Name  = m_List.GetItemText(pos,0);
	UpdateData(FALSE);
	*pResult = 0;
}

void CUserdlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty())
	{
		MessageBox("用户名不能为空");
		return;
	}
	m_LoginSet->MoveFirst();
	while(!m_LoginSet->IsEOF())
	{
		if(m_Name != m_LoginSet->m_username)
		{
			m_LoginSet->MoveNext();
		}
		else
		{
			m_LoginSet->Delete();
			m_LoginSet->Requery();
			m_List.DeleteAllItems();
			DisplayRecord(); 
			return;
		}
	}
}
