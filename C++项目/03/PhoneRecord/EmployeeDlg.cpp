// EmployeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "EmployeeDlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg dialog


CEmployeeDlg::CEmployeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployeeDlg)
	m_Id = _T("");
	m_Name = _T("");
	m_UserName = _T("");
	m_Password = _T("");
	m_Culture = _T("");
	m_IdCard = _T("");
	m_Phone = _T("");
	m_Remark = _T("");
	//}}AFX_DATA_INIT
}


void CEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployeeDlg)
	DDX_Control(pDX, IDC_BUTSAVE, m_ButSave);
	DDX_Control(pDX, IDC_BUTMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_COMBO1, m_Sex);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Id);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_UserName);
	DDX_Text(pDX, IDC_EDIT4, m_Password);
	DDX_Text(pDX, IDC_EDIT5, m_Culture);
	DDX_Text(pDX, IDC_EDIT6, m_IdCard);
	DDX_Text(pDX, IDC_EDIT7, m_Phone);
	DDX_Text(pDX, IDC_EDIT8, m_Remark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployeeDlg, CDialog)
	//{{AFX_MSG_MAP(CEmployeeDlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg message handlers


BOOL CEmployeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //创建列表视图窗口
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_EMPLOYEE));
	m_List.SetImageList(&m_ImageList,LVSIL_NORMAL);
	AddToList();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	m_Sex.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEmployeeDlg::AddToList()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select 员工编号,员工姓名 from tb_employees ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		CString strId,strName,str;
		strId   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("员工编号");
		strName = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("员工姓名");
		str = strId + " " + strName;
		m_List.InsertItem(i,str,0);
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CEmployeeDlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	Clear();
	UpdateData(FALSE);
}

void CEmployeeDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() || m_Name.IsEmpty() || m_UserName.IsEmpty() || m_Password.IsEmpty()
		|| m_Culture.IsEmpty() || m_IdCard.IsEmpty() || m_Phone.IsEmpty() || m_Remark.IsEmpty())
	{
		MessageBox("员工信息不能为空！");
	}
	CString sex;
	m_Sex.GetWindowText(sex);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_employees(用户名,密码,员工编号,员工姓名,员工性别,员工学历,\
		身份证号,联系电话,备注信息) values('%s','%s','%s','%s','%s','%s','%s','%s','%s')",
		m_UserName,m_Password,m_Id,m_Name,sex,m_Culture,m_IdCard,m_Phone,m_Remark);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("保存成功");
	else
		MessageBox("保存失败");
	m_ADOConn.ExitConnect();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	m_List.DeleteAllItems();
	AddToList();
	Clear();
	UpdateData(FALSE);
}

void CEmployeeDlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() || m_Name.IsEmpty() || m_UserName.IsEmpty() || m_Password.IsEmpty()
		|| m_Culture.IsEmpty() || m_IdCard.IsEmpty() || m_Phone.IsEmpty() || m_Remark.IsEmpty())
	{
		MessageBox("员工信息不能为空！");
	}
	CString sex;
	m_Sex.GetWindowText(sex);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_employees set 用户名='%s',密码='%s',员工姓名='%s',员工性别='%s',\
		员工学历='%s',身份证号='%s',联系电话='%s',备注信息='%s' where 员工编号='%s'",
		m_UserName,m_Password,m_Name,sex,m_Culture,m_IdCard,m_Phone,m_Remark,m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("修改成功");
	else
		MessageBox("修改失败");
	m_ADOConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
	Clear();
	UpdateData(FALSE);
}

void CEmployeeDlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Id.IsEmpty() )
	{
		MessageBox("员工编号不能为空！");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_employees where 员工编号='%s'",m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("删除成功");
	else
		MessageBox("删除失败");
	m_ADOConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
	Clear();
	UpdateData(FALSE);
}

void CEmployeeDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int     pos   = m_List.GetSelectionMark();
	CString strid = m_List.GetItemText(pos,0);
	num = strid.Find(" ",0);
	m_Id = strid.Left(num);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_employees where 员工编号='%s'",m_Id);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Name     = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("员工姓名");
		m_UserName = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("用户名");
		m_Password = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("密码");
		m_Culture  = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("员工学历");
		m_IdCard   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("身份证号");
		m_Phone    = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("联系电话");
		m_Remark   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("备注信息");
		m_Sex.SetWindowText((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("员工性别"));
	}
	m_AdoConn.ExitConnect();
	UpdateData(FALSE);
	*pResult = 0;
}

void CEmployeeDlg::Clear()
{
	m_Id       = "";
	m_Name     = "";
	m_UserName = "";
	m_Password = "";
	m_Culture  = "";
	m_IdCard   = "";
	m_Phone    = "";
	m_Remark   = "";
	m_Sex.SetCurSel(0);
}
