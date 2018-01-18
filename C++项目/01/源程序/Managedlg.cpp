// Managedlg.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
#include "Managedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManagedlg dialog


CManagedlg::CManagedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManagedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManagedlg)
	m_Name = _T("");
	m_PassWord = _T("");
	m_Log = _T("");
	//}}AFX_DATA_INIT
}


void CManagedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManagedlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_PassWord);
	DDX_Text(pDX, IDC_EDIT3, m_Log);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManagedlg, CDialog)
	//{{AFX_MSG_MAP(CManagedlg)
	ON_BN_CLICKED(IDC_BUTTONADD, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTONMOD, OnButtonmod)
	ON_BN_CLICKED(IDC_BUTTONDEL, OnButtondel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagedlg message handlers

BOOL CManagedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bExpand = FALSE;
	CRect rcDlg, rcMarker;
	GetWindowRect(rcDlg);
	m_nExpandedHeight = rcDlg.Height();
	GetDlgItem(IDC_STATIC1)->GetWindowRect(rcMarker);
	m_nNormalHeight = (rcMarker.top - rcDlg.top);
	Display();
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,0); //�����б���ͼ����
	//��ͼ���б������ͼ��
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_List.SetImageList(&m_ImageList,LVSIL_NORMAL);
	AddToList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CManagedlg::OnInitADOConn()
{
	try
	{
		//�������Ӷ���ʵ��
		m_pConnection.CreateInstance("ADODB.Connection");
		//���������ַ���
		CString strConnect;
		strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s\\shujuku.mdb;Persist Security Info=False",m_PathText);
		//ʹ��Open�����������ݿ�
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CManagedlg::ExitConnect()
{
	//�رռ�¼��������
    if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}

void CManagedlg::AddToList()
{
	OnInitADOConn();
	CString sql;
	sql.Format("select �û��� from tb_user ",m_Name,m_PassWord);
	m_pRecordset = m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_List.InsertItem(i,(char*)(_bstr_t)m_pRecordset->GetCollect("�û���"),0);
		m_pRecordset->MoveNext();
		i++;
	}
	ExitConnect();
}

void CManagedlg::OnButtonadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("�û��������벻��Ϊ��");
		return;
	}
	for(int i=0;i<m_List.GetItemCount();i++)
	{
		if(m_Name == m_List.GetItemText(i,0))
		{
			MessageBox("�û����Ѵ���");
			return;
		}
	}
	OnInitADOConn();
	CString sql;
	sql.Format("insert into tb_user (�û���,����) values ('%s','%s')",
		m_Name,m_PassWord);
	m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	m_pConnection->Close();
	m_List.DeleteAllItems();
	AddToList();
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t����û�\r\n",m_UserName,m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CManagedlg::OnButtonmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_PassWord.IsEmpty())
	{
		MessageBox("�û��������벻��Ϊ��");
		return;
	}
	OnInitADOConn();
	CString sql;
	sql.Format("update tb_user set �û���='%s',����='%s' where �û���='%s' ",
		m_Name,m_PassWord,m_Name);
	m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	m_pConnection->Close();
	m_List.DeleteAllItems();
	AddToList();
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t�޸��û�\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CManagedlg::OnButtondel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty())
	{
		MessageBox("�û�������Ϊ��");
		return;
	}
	if(m_Name == "tsoft")
	{
		MessageBox("�û�tsoft����ɾ��");
		return;
	}
	OnInitADOConn();
	CString sql;
	sql.Format("delete * from tb_user where �û���='%s' ",m_Name);
	m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	m_pConnection->Close();
	m_List.DeleteAllItems();
	AddToList();
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\tɾ���û�\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CManagedlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_List.GetSelectionMark();
	m_Name  = m_List.GetItemText(pos,0);
	UpdateData(FALSE);
	*pResult = 0;
}

void CManagedlg::Display()
{
	CRect rcDlg;
	GetWindowRect(rcDlg);
	if(m_bExpand)
	{
		rcDlg.SetRect( rcDlg.left, rcDlg.top, 
		rcDlg.left + rcDlg.Width(),
		rcDlg.top + m_nExpandedHeight);
		CFile file;
		file.Open(m_LogPath,CFile::modeRead);
		DWORD size = file.GetLength();
		char read[51200];
		file.Read(read,size);
		CString str="";
		for(int i=0;i<size;i++)
		{
			str += read[i];
		}
		m_Log = str;
		UpdateData(FALSE);
	}
	else
	{
		rcDlg.SetRect(rcDlg.left, rcDlg.top, 
		rcDlg.left + rcDlg.Width(),
		rcDlg.top + m_nNormalHeight);
	}
	MoveWindow(rcDlg);
}

void CManagedlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	m_bExpand = !m_bExpand;
	Display();
}
