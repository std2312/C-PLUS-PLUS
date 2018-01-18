// Restoredlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "Restoredlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRestoredlg dialog


CRestoredlg::CRestoredlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRestoredlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRestoredlg)
	m_Name = _T("");
	m_Phone = _T("");
	m_Note = _T("");
	m_RNote = _T("");
	//}}AFX_DATA_INIT
}


void CRestoredlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRestoredlg)
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_BUTSEND, m_Restore);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Phone);
	DDX_Text(pDX, IDC_EDIT3, m_Note);
	DDX_Text(pDX, IDC_EDIT4, m_RNote);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRestoredlg, CDialog)
	//{{AFX_MSG_MAP(CRestoredlg)
	ON_BN_CLICKED(IDC_BUTSEND, OnButsend)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestoredlg message handlers

BOOL CRestoredlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Restore.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_RESTORE1))); //设置位图
	m_Restore.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_RESTORE2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_RESTORE1)));
	m_ButDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BUTDEL1))); //设置位图
	m_ButDel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRestoredlg::OnButsend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_RNote.IsEmpty())
	{
		MessageBox("回复信息不能为空！");
		return;
	}
	CString port,baud,merid,accredit;
	char buf[129];
	GetPrivateProfileString("短信猫设置","端口号","default",buf,128,"./stage.ini");
	port.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","波特率","default",buf,128,"./stage.ini");
	baud.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","机器号码","default",buf,128,"./stage.ini");
	merid.Format("%s",buf);
	GetPrivateProfileString("短信猫设置","授权号码","default",buf,128,"./stage.ini");
	accredit.Format("%s",buf);

	if(GSMModemInitNew((char*)(LPCTSTR)port,(char*)(LPCTSTR)baud,
		NULL,NULL,FALSE,(char*)(LPCTSTR)accredit)==FALSE)
	{
		MessageBox((char*)GSMModemGetErrorMsg());
		return; 
	}
	if(GSMModemSMSsend(NULL,8,(char*)(LPCTSTR)m_RNote,m_RNote.GetLength(),
		(char*)(LPCTSTR)m_Phone,FALSE))
	{
		MessageBox("发送成功");
	}
	else
	{
		MessageBox("发送失败");
	}
}

void CRestoredlg::OnOK()
{
}

void CRestoredlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	ADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	CString sql;
	int i = 0;
	sql.Format("delete from tb_recvnote where 编号 = %d",atoi(m_Num));
	BOOL ret = m_ADOConn.ExecuteSQL((_bstr_t)sql);
	m_ADOConn.ExitConnect();
}
