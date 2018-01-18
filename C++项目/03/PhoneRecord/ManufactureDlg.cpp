// ManufactureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "ManufactureDlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManufactureDlg dialog


CManufactureDlg::CManufactureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManufactureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManufactureDlg)
	m_Name = _T("");
	m_Intro = _T("");
	//}}AFX_DATA_INIT
}


void CManufactureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManufactureDlg)
	DDX_Control(pDX, IDC_BUTSAVE, m_ButSave);
	DDX_Control(pDX, IDC_BUTMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Intro);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManufactureDlg, CDialog)
	//{{AFX_MSG_MAP(CManufactureDlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManufactureDlg message handlers

BOOL CManufactureDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //�����б���ͼ����
	//��ͼ���б������ͼ��
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_MANUFACTURE));
	m_List.SetImageList(&m_ImageList,LVSIL_NORMAL);
	AddToList();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CManufactureDlg::AddToList()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select ��Ʒ���� from tb_manufacture ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_List.InsertItem(i,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��Ʒ����"),0);
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CManufactureDlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	m_Name  = "";
	m_Intro = "";
	UpdateData(FALSE);
}

void CManufactureDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Intro.IsEmpty())
	{
		MessageBox("��Ʒ��Ϣ����Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_manufacture(��Ʒ����,��Ʒ����) values('%s','%s')",m_Name,m_Intro);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("����ɹ�");
	else
		MessageBox("����ʧ��");
	m_ADOConn.ExitConnect();
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	m_List.DeleteAllItems();
	AddToList();
	m_Name  = "";
	m_Intro = "";
	UpdateData(FALSE);
}

void CManufactureDlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Intro.IsEmpty())
	{
		MessageBox("��Ʒ��Ϣ����Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_manufacture set ��Ʒ����='%s' where ��Ʒ����='%s'",m_Intro,m_Name);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("�޸ĳɹ�");
	else
		MessageBox("�޸�ʧ��");
	m_ADOConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
	m_Name  = "";
	m_Intro = "";
	UpdateData(FALSE);
}

void CManufactureDlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() )
	{
		MessageBox("��Ʒ���Ʋ���Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_manufacture where ��Ʒ����='%s'",m_Name);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("ɾ���ɹ�");
	else
		MessageBox("ɾ��ʧ��");
	m_ADOConn.ExitConnect();
	m_List.DeleteAllItems();
	AddToList();
	m_Name  = "";
	m_Intro = "";
	UpdateData(FALSE);
}

void CManufactureDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_List.GetSelectionMark();
	m_Name  = m_List.GetItemText(pos,0);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_manufacture where ��Ʒ����='%s'",m_Name);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Intro = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��Ʒ����");
	}
	m_AdoConn.ExitConnect();
	UpdateData(FALSE);
	*pResult = 0;
}
