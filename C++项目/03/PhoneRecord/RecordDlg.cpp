// RecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "RecordDlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")
/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog


CRecordDlg::CRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecordDlg)
	m_Name = _T("");
	m_Path = _T("");
	//}}AFX_DATA_INIT
}


void CRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordDlg)
	DDX_Control(pDX, IDC_BUTPLAY, m_ButPlay);
	DDX_Control(pDX, IDC_BUTMODPATH, m_ButModPath);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTMODPATH, OnButmodpath)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_BN_CLICKED(IDC_BUTPLAY, OnButplay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg message handlers

BOOL CRecordDlg::OnInitDialog() 
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
	m_Grid.InsertColumn(0,"�ļ�����",LVCFMT_LEFT,100,0); 
	m_Grid.InsertColumn(1,"�ļ�·��",LVCFMT_LEFT,200,1); 
	m_Grid.InsertColumn(2,"¼��ʱ��",LVCFMT_LEFT,100,2);
	AddToGrid();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRecordDlg::AddToGrid()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tb_record ");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i = 0;
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�ļ�����"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("�ļ�·��"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("¼��ʱ��"));
		m_AdoConn.m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();
}

void CRecordDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark(); //��ȡѡ��������
	m_Name  = m_Grid.GetItemText(pos,0); //�����ļ����Ʊ༭���е���ʾ�ı�
	m_Path  = m_Grid.GetItemText(pos,1); //�����ļ�·���༭���е���ʾ�ı�
	UpdateData(FALSE);
	*pResult = 0;
}

void CRecordDlg::OnButmodpath() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty())
	{
		MessageBox("�ļ�������Ϊ�գ�");
		return;
	}
	CString strText;
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];
	BROWSEINFO bi;
	bi.hwndOwner             = NULL;
	bi.pidlRoot              = NULL;
	bi.lpszTitle             = _T("��ѡ�񱸷��ļ���");
	bi.pszDisplayName        = szPath;
	bi.ulFlags               = BIF_RETURNONLYFSDIRS;
	bi.lpfn                  = NULL;
	bi.lParam                = NULL;
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath))
			ReturnPach = szPath;	
	}
	else
	{
		ReturnPach = "";
	}
	strText = ReturnPach;
	if(strText.Right(1) != "\\")
	{
		strText += "\\";
	}
	BOOL ret = MoveFile(m_Path+m_Name,strText+m_Name);
	if(ret)
	{
		ADOConn m_ADOConn;
		m_ADOConn.OnInitADOConn();
		CString sql;
		sql.Format("update tb_record set �ļ�·��='%s' where �ļ�����='%s'",strText,m_Name);
		m_ADOConn.ExecuteSQL((_bstr_t)sql);
		m_ADOConn.ExitConnect();
		m_Grid.DeleteAllItems();
		AddToGrid();
		m_Path = strText;
		UpdateData(FALSE);
	}
	else
		MessageBox("�ļ�·���޸�ʧ��");
}

void CRecordDlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Path.IsEmpty())
	{
		MessageBox("�ļ�������ļ�·������Ϊ�գ�");
		return;
	}
	BOOL ret = DeleteFile(m_Path+m_Name);
	if(ret)
	{
		ADOConn m_ADOConn;
		m_ADOConn.OnInitADOConn();
		CString sql;
		sql.Format("delete from tb_record where �ļ�����='%s'",m_Name);
		m_ADOConn.ExecuteSQL((_bstr_t)sql);
		m_ADOConn.ExitConnect();
		m_Grid.DeleteAllItems();
		AddToGrid();
	}
	else
		MessageBox("ɾ��ʧ��");
}

void CRecordDlg::OnButplay() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Path.IsEmpty())
	{
		MessageBox("�ļ�������ļ�·������Ϊ�գ�");
		return;
	}
	MCIDEVICEID m_nDeviceID;
	MCIDEVICEID m_nElementID;
	MCI_OPEN_PARMS mciOpenParms;

	mciOpenParms.lpstrDeviceType=(LPSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
	mciSendCommand(NULL,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID
		| MCI_WAIT,(DWORD)(LPVOID)&mciOpenParms);
	m_nDeviceID=mciOpenParms.wDeviceID;

	MCI_OPEN_PARMS mciOpen;
	memset(&mciOpen,0,sizeof(MCI_OPEN_PARMS));
	mciOpen.lpstrElementName = m_Path + m_Name;
	mciSendCommand(m_nDeviceID,MCI_OPEN,MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpen);
	m_nElementID=mciOpen.wDeviceID;

	MCI_PLAY_PARMS mciPlay;
	mciPlay.dwCallback=(DWORD)this->GetSafeHwnd();
	mciSendCommand(m_nElementID,MCI_PLAY,MCI_NOTIFY,(DWORD)(LPVOID)&mciPlay);
}
