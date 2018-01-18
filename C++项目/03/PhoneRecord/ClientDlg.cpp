// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "ClientDlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog


CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_Id = _T("");
	m_Name = _T("");
	m_Linkman = _T("");
	m_Phone = _T("");
	m_Email = _T("");
	m_Address = _T("");
	m_Remark = _T("");
	//}}AFX_DATA_INIT
}


void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_BUTSAVE, m_ButSave);
	DDX_Control(pDX, IDC_BUTMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Id);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_Linkman);
	DDX_Text(pDX, IDC_EDIT4, m_Phone);
	DDX_Text(pDX, IDC_EDIT5, m_Email);
	DDX_Text(pDX, IDC_EDIT6, m_Address);
	DDX_Text(pDX, IDC_EDIT7, m_Remark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB  //扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT              //允许整行选中
		|LVS_EX_HEADERDRAGDROP             //允许整列拖动
		|LVS_EX_ONECLICKACTIVATE           //单击选中项
		|LVS_EX_GRIDLINES);                //画出网格线
	//设置表头
	m_Grid.InsertColumn(0,"客户编号",LVCFMT_LEFT,70,0); 
	m_Grid.InsertColumn(1,"客户名称",LVCFMT_LEFT,70,1); 
	m_Grid.InsertColumn(2,"联系人",LVCFMT_LEFT,70,2);
	m_Grid.InsertColumn(3,"联系电话",LVCFMT_LEFT,70,3);
	m_Grid.InsertColumn(4,"Email",LVCFMT_LEFT,70,4);
	m_Grid.InsertColumn(5,"联系地址",LVCFMT_LEFT,70,5);
	m_Grid.InsertColumn(6,"备注信息",LVCFMT_LEFT,70,6);

	AddToGrid();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClientDlg::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_client ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("客户编号"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("客户名称"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("联系人"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("联系电话"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Email"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("联系地址"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("备注信息"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CClientDlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	Clear();
	UpdateData(FALSE);
}

void CClientDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() || m_Name.IsEmpty() || m_Linkman.IsEmpty() || m_Phone.IsEmpty()
		|| m_Email.IsEmpty() || m_Address.IsEmpty() || m_Remark.IsEmpty())
	{
		MessageBox("客户信息不能为空！");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_client(客户编号,客户名称,联系人,联系电话,Email,\
		联系地址,备注信息) values('%s','%s','%s','%s','%s','%s','%s')",m_Id,
		m_Name,m_Linkman,m_Phone,m_Email,m_Address,m_Remark);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("保存成功");
	else
		MessageBox("保存失败");
	m_ADOConn.ExitConnect();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	m_Grid.DeleteAllItems();
	AddToGrid();
	Clear();
	UpdateData(FALSE);
}

void CClientDlg::Clear()
{
	m_Id      = "";
	m_Name    = "";
	m_Linkman = "";
	m_Phone   = "";
	m_Email   = "";
	m_Address = "";
	m_Remark  = "";
}

void CClientDlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() || m_Name.IsEmpty() || m_Linkman.IsEmpty() || m_Phone.IsEmpty()
		|| m_Email.IsEmpty() || m_Address.IsEmpty() || m_Remark.IsEmpty())
	{
		MessageBox("客户信息不能为空！");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_client set 客户名称='%s',联系人='%s',联系电话='%s',\
		Email='%s',联系地址='%s',备注信息='%s' where 客户编号='%s'",m_Name,
		m_Linkman,m_Phone,m_Email,m_Address,m_Remark,m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("修改成功");
	else
		MessageBox("修改失败");
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	Clear();
	UpdateData(FALSE);
}

void CClientDlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() )
	{
		MessageBox("客户编号不能为空！");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_client where 客户编号='%s'",m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("删除成功");
	else
		MessageBox("删除失败");
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	Clear();
	UpdateData(FALSE);
}

void CClientDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos   = m_Grid.GetSelectionMark(); //获取选中项索引
	m_Id      = m_Grid.GetItemText(pos,0); //设置客户编号编辑框中的显示文本
	m_Name    = m_Grid.GetItemText(pos,1); //设置客户名称编辑框中的显示文本
	m_Linkman = m_Grid.GetItemText(pos,2); //设置联系人编辑框中的显示文本
	m_Phone   = m_Grid.GetItemText(pos,3); //设置联系电话编辑框中的显示文本
	m_Email   = m_Grid.GetItemText(pos,4); //设置Email编辑框中的显示文本
	m_Address = m_Grid.GetItemText(pos,5); //设置联系地址编辑框中的显示文本
	m_Remark  = m_Grid.GetItemText(pos,6); //设置备注信息编辑框中的显示文本
	UpdateData(FALSE);
	*pResult = 0;
}
