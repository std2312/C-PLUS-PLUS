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
	//�����б���ͼ����չ���
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB  //��ƽ�����ʾ������
		|LVS_EX_FULLROWSELECT              //��������ѡ��
		|LVS_EX_HEADERDRAGDROP             //���������϶�
		|LVS_EX_ONECLICKACTIVATE           //����ѡ����
		|LVS_EX_GRIDLINES);                //����������
	//���ñ�ͷ
	m_Grid.InsertColumn(0,"�ͻ����",LVCFMT_LEFT,70,0); 
	m_Grid.InsertColumn(1,"�ͻ�����",LVCFMT_LEFT,70,1); 
	m_Grid.InsertColumn(2,"��ϵ��",LVCFMT_LEFT,70,2);
	m_Grid.InsertColumn(3,"��ϵ�绰",LVCFMT_LEFT,70,3);
	m_Grid.InsertColumn(4,"Email",LVCFMT_LEFT,70,4);
	m_Grid.InsertColumn(5,"��ϵ��ַ",LVCFMT_LEFT,70,5);
	m_Grid.InsertColumn(6,"��ע��Ϣ",LVCFMT_LEFT,70,6);

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
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�ͻ����"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�ͻ�����"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ��"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ�绰"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("Email"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ��ַ"));
		m_Grid.SetItemText(i,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ע��Ϣ"));
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
		MessageBox("�ͻ���Ϣ����Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_client(�ͻ����,�ͻ�����,��ϵ��,��ϵ�绰,Email,\
		��ϵ��ַ,��ע��Ϣ) values('%s','%s','%s','%s','%s','%s','%s')",m_Id,
		m_Name,m_Linkman,m_Phone,m_Email,m_Address,m_Remark);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("����ɹ�");
	else
		MessageBox("����ʧ��");
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
		MessageBox("�ͻ���Ϣ����Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_client set �ͻ�����='%s',��ϵ��='%s',��ϵ�绰='%s',\
		Email='%s',��ϵ��ַ='%s',��ע��Ϣ='%s' where �ͻ����='%s'",m_Name,
		m_Linkman,m_Phone,m_Email,m_Address,m_Remark,m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("�޸ĳɹ�");
	else
		MessageBox("�޸�ʧ��");
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
		MessageBox("�ͻ���Ų���Ϊ�գ�");
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_client where �ͻ����='%s'",m_Id);
	BOOL res = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	if(res)
		MessageBox("ɾ���ɹ�");
	else
		MessageBox("ɾ��ʧ��");
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	Clear();
	UpdateData(FALSE);
}

void CClientDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos   = m_Grid.GetSelectionMark(); //��ȡѡ��������
	m_Id      = m_Grid.GetItemText(pos,0); //���ÿͻ���ű༭���е���ʾ�ı�
	m_Name    = m_Grid.GetItemText(pos,1); //���ÿͻ����Ʊ༭���е���ʾ�ı�
	m_Linkman = m_Grid.GetItemText(pos,2); //������ϵ�˱༭���е���ʾ�ı�
	m_Phone   = m_Grid.GetItemText(pos,3); //������ϵ�绰�༭���е���ʾ�ı�
	m_Email   = m_Grid.GetItemText(pos,4); //����Email�༭���е���ʾ�ı�
	m_Address = m_Grid.GetItemText(pos,5); //������ϵ��ַ�༭���е���ʾ�ı�
	m_Remark  = m_Grid.GetItemText(pos,6); //���ñ�ע��Ϣ�༭���е���ʾ�ı�
	UpdateData(FALSE);
	*pResult = 0;
}
