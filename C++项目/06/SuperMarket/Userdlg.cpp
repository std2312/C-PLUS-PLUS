// Userdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
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
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserdlg, CDialog)
	//{{AFX_MSG_MAP(CUserdlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
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
	AddToList();
	m_Combo.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserdlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("用户名或密码不能为空");
		return;
	}
	CString str;
	m_Combo.GetWindowText(str);
	if(str == "后台管理")
		str = "1";
	else
		str = "0";
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into CTXSYS.TB_USER (NAME,PWD,POPEDOM) values ('%s','%s','%s')",
		m_Name,m_PassWord,str);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
}

void CUserdlg::AddToList()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select NAME from CTXSYS.TB_USER ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_List.InsertItem(i,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("NAME"),0);
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
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
	CString str;
	m_Combo.GetWindowText(str);
	if(str == "后台管理")
		str = "1";
	else
		str = "0";
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("update CTXSYS.TB_USER set NAME='%s',PWD='%s',POPEDOM='%s'\
		where NAME='%s' ",m_Name,m_PassWord,str,m_oName);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
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
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from CTXSYS.TB_USER where NAME='%s' ",m_oName);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
}

void CUserdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_List.GetSelectionMark();
	m_oName = m_Name  = m_List.GetItemText(pos,0);
	UpdateData(FALSE);
	*pResult = 0;
}
