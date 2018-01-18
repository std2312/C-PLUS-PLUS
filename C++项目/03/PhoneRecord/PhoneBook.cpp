// PhoneBook.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "PhoneBook.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneBook dialog


CPhoneBook::CPhoneBook(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhoneBook)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPhoneBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhoneBook)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPhoneBook, CDialog)
	//{{AFX_MSG_MAP(CPhoneBook)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneBook message handlers

BOOL CPhoneBook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//�����б���ͼ����չ���
	m_Grid.SetExtendedStyle( LVS_EX_FLATSB  //��ƽ�����ʾ������
		| LVS_EX_FULLROWSELECT              //��������ѡ��
		| LVS_EX_HEADERDRAGDROP             //���������϶�
		| LVS_EX_ONECLICKACTIVATE           //����ѡ����
		| LVS_EX_GRIDLINES );               //����������
	//���ñ�ͷ
	m_Grid.InsertColumn(0,"�ͻ�����",LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"�ͻ��绰",LVCFMT_LEFT,100,1); 
	m_Grid.InsertColumn(2,"�ͻ���ַ",LVCFMT_LEFT,100,2);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_client ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�ͻ�����"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ�绰"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("��ϵ��ַ"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPhoneBook::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Num = m_Grid.GetItemText(pos,1);
	CDialog::OnCancel();
	*pResult = 0;
}
