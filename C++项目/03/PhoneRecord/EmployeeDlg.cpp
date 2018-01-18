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
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //�����б���ͼ����
	//��ͼ���б������ͼ��
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
	sql.Format("select Ա�����,Ա������ from tb_employees ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		CString strId,strName,str;
		strId   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Ա�����");
		strName = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Ա������");
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
		MessageBox("Ա����Ϣ����Ϊ�գ�");
	}
	CString sex;
	m_Sex.GetWindowText(sex);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_employees(�û���,����,Ա�����,Ա������,Ա���Ա�,Ա��ѧ��,\
		���֤��,��ϵ�绰,��ע��Ϣ) values('%s','%s','%s','%s','%s','%s','%s','%s','%s')",
		m_UserName,m_Password,m_Id,m_Name,sex,m_Culture,m_IdCard,m_Phone,m_Remark);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("����ɹ�");
	else
		MessageBox("����ʧ��");
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
		MessageBox("Ա����Ϣ����Ϊ�գ�");
	}
	CString sex;
	m_Sex.GetWindowText(sex);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_employees set �û���='%s',����='%s',Ա������='%s',Ա���Ա�='%s',\
		Ա��ѧ��='%s',���֤��='%s',��ϵ�绰='%s',��ע��Ϣ='%s' where Ա�����='%s'",
		m_UserName,m_Password,m_Name,sex,m_Culture,m_IdCard,m_Phone,m_Remark,m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("�޸ĳɹ�");
	else
		MessageBox("�޸�ʧ��");
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
		MessageBox("Ա����Ų���Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_employees where Ա�����='%s'",m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("ɾ���ɹ�");
	else
		MessageBox("ɾ��ʧ��");
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
	sql.Format("select * from tb_employees where Ա�����='%s'",m_Id);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Name     = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Ա������");
		m_UserName = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�û���");
		m_Password = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("����");
		m_Culture  = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Ա��ѧ��");
		m_IdCard   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("���֤��");
		m_Phone    = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ�绰");
		m_Remark   = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ע��Ϣ");
		m_Sex.SetWindowText((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Ա���Ա�"));
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
