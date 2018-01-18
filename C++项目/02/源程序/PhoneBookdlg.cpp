// PhoneBookdlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "PhoneBookdlg.h"
#include "ADOCOnn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookdlg dialog


CPhoneBookdlg::CPhoneBookdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneBookdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhoneBookdlg)
	//}}AFX_DATA_INIT
}


void CPhoneBookdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhoneBookdlg)
	DDX_Control(pDX, IDC_BUTMOD, m_ButMod);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_EDIT2, m_Phone);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_COMBO3, m_Dep);
	DDX_Control(pDX, IDC_COMBO2, m_Duty);
	DDX_Control(pDX, IDC_COMBO1, m_Sex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPhoneBookdlg, CDialog)
	//{{AFX_MSG_MAP(CPhoneBookdlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTMOD, OnButmod)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookdlg message handlers

BOOL CPhoneBookdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//�����б���ͼ����չ���
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	//���ñ�ͷ
	m_Grid.InsertColumn(0,"���",LVCFMT_LEFT,70,0); 
	m_Grid.InsertColumn(1,"����",LVCFMT_LEFT,70,1); 
	m_Grid.InsertColumn(2,"�Ա�",LVCFMT_LEFT,70,2);
	m_Grid.InsertColumn(3,"ְ��",LVCFMT_LEFT,70,3);
	m_Grid.InsertColumn(4,"����",LVCFMT_LEFT,70,4);
	m_Grid.InsertColumn(5,"�绰",LVCFMT_LEFT,130,5);
	AddToGrid(); 
	m_Sex.SetCurSel(0);
	m_Duty.SetCurSel(0);
	m_Dep.SetCurSel(0);
	m_ID = -1;

	m_ButAdd.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTADD1))); //����λͼ
	m_ButAdd.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTADD1)));
	m_ButMod.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTMOD1))); //����λͼ
	m_ButMod.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTMOD1)));
	m_ButDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTDEL1))); //����λͼ
	m_ButDel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPhoneBookdlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	CString name,phone,sex,duty,dep;
	m_Name.GetWindowText(name);
	m_Phone.GetWindowText(phone);
	if(name.IsEmpty() || phone.IsEmpty())
	{
		MessageBox("�����͵绰���벻��Ϊ�գ�");
		return;
	}
	m_Sex.GetLBText(m_Sex.GetCurSel(),sex);
	m_Duty.GetLBText(m_Duty.GetCurSel(),duty);
	m_Dep.GetLBText(m_Dep.GetCurSel(),dep);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_phonebook(����,�Ա�,�绰����,���ڲ���,ְ��)\
		values ('%s','%s','%s','%s','%s')",name,sex,phone,dep,duty);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
}

void CPhoneBookdlg::OnButmod() 
{
	// TODO: Add your control notification handler code here
	CString name,phone,sex,duty,dep;
	m_Name.GetWindowText(name);
	m_Phone.GetWindowText(phone);
	if(m_ID < 0)
	{
		MessageBox("�����б���ѡ��Ա����");
		return;
	}
	m_Sex.GetWindowText(sex);
	m_Duty.GetWindowText(duty);
	m_Dep.GetWindowText(dep);
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("update tb_phonebook set ����='%s',�Ա�='%s',�绰����='%s', \
		���ڲ���='%s',ְ��='%s' where ���=%d",name,sex,phone,dep,duty,m_ID);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	m_ID = -1;
}

void CPhoneBookdlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	if(m_ID < 0)
	{
		MessageBox("�����б���ѡ��Ա����");
		return;
	}
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tb_phonebook where ���=%d",m_ID);
	m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
	m_Grid.DeleteAllItems();
	AddToGrid();
	m_ID = -1;
}

void CPhoneBookdlg::AddToGrid()
{
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("select * from tb_phonebook");
	m_ADOConn.m_pRecordset = m_ADOConn.GetRecordSet((_bstr_t)sql);
	while(!m_ADOConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("���"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("����"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("�Ա�"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("ְ��"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("���ڲ���"));
		m_Grid.SetItemText(i,5,(char*)(_bstr_t)m_ADOConn.m_pRecordset->GetCollect("�绰����"));
		m_ADOConn.m_pRecordset->MoveNext();
		i++;
	}
	m_ADOConn.ExitConnect();
}

void CPhoneBookdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_ID = atoi(m_Grid.GetItemText(pos,0));
	m_Name.SetWindowText(m_Grid.GetItemText(pos,1));
	m_Sex.SetWindowText(m_Grid.GetItemText(pos,2));
	m_Duty.SetWindowText(m_Grid.GetItemText(pos,3));
	m_Dep.SetWindowText(m_Grid.GetItemText(pos,4));
	m_Phone.SetWindowText(m_Grid.GetItemText(pos,5));

	*pResult = 0;
}

void CPhoneBookdlg::OnOK()
{
}
