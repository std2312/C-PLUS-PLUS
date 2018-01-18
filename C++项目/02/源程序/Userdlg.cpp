// Userdlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "Userdlg.h"
#include "ADOConn.h"
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
	DDX_Control(pDX, IDC_CANCEL, m_Cancel);
	DDX_Control(pDX, IDC_BUTTONMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTTONDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTTONADD, m_ButAdd);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserdlg, CDialog)
	//{{AFX_MSG_MAP(CUserdlg)
	ON_BN_CLICKED(IDC_BUTTONADD, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTONMOD, OnButtonmod)
	ON_BN_CLICKED(IDC_BUTTONDEL, OnButtondel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserdlg message handlers

void CUserdlg::OnButtonadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_user (用户名,密码) values ('%s','%s')",
		m_Name,m_PassWord);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
}

void CUserdlg::OnButtonmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_user set 用户名='%s',密码='%s' where 用户名='%s' ",
		m_Name,m_PassWord,m_oName);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
}

void CUserdlg::OnButtondel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty())
	{
		MessageBox("用户名不能为空");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete * from tb_user where 用户名='%s' ",m_Name);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
}

BOOL CUserdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //创建列表视图窗口
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_List.SetImageList(&m_ImageList,LVSIL_NORMAL);
	AddToList();
	m_ButAdd.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTADD1))); //设置位图
	m_ButAdd.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD1)));
	m_ButMod.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTMOD1))); //设置位图
	m_ButMod.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD1)));
	m_ButDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTDEL1))); //设置位图
	m_ButDel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL1)));
	m_Cancel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_CANCEL1))); //设置位图
	m_Cancel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_CANCEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_CANCEL1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserdlg::AddToList()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select 用户名 from tb_user ",m_Name,m_PassWord);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_List.InsertItem(i,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("用户名"),0);
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CUserdlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CUserdlg::OnOK()
{
}

void CUserdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_List.GetSelectionMark();
	m_Name = m_oName = m_List.GetItemText(pos,0);
	UpdateData(FALSE);
	*pResult = 0;
}
