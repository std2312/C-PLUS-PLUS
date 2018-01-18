// NoteSet.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "NoteSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoteSet dialog


CNoteSet::CNoteSet(CWnd* pParent /*=NULL*/)
	: CDialog(CNoteSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoteSet)
	m_Baud = _T("");
	m_MerID = _T("");
	m_AccrEdit = _T("");
	m_Port = _T("");
	//}}AFX_DATA_INIT
}


void CNoteSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoteSet)
	DDX_Control(pDX, IDC_BUTSAVE, m_ButSave);
	DDX_Control(pDX, IDC_BUTGET, m_ButGet);
	DDX_Text(pDX, IDC_EDIT1, m_Baud);
	DDX_Text(pDX, IDC_EDIT2, m_MerID);
	DDX_Text(pDX, IDC_EDIT3, m_AccrEdit);
	DDX_Text(pDX, IDC_EDIT4, m_Port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNoteSet, CDialog)
	//{{AFX_MSG_MAP(CNoteSet)
	ON_BN_CLICKED(IDC_BUTGET, OnButget)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoteSet message handlers

void CNoteSet::OnButget() 
{
	// TODO: Add your control notification handler code here
	m_MerID.Format("%s",GSMModemGetSnInfoNew(NULL,NULL));
	m_Baud.Format("%s",GSMModemGetBaudrate());
	m_Port.Format("%s",GSMModemGetDevice());	
	UpdateData(FALSE);
}

void CNoteSet::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	WritePrivateProfileString("短信猫设置","端口号",m_Port,"./stage.ini");
	WritePrivateProfileString("短信猫设置","波特率",m_Baud,"./stage.ini");
	WritePrivateProfileString("短信猫设置","机器号码",m_MerID,"./stage.ini");
	WritePrivateProfileString("短信猫设置","授权号码",m_AccrEdit,"./stage.ini");
	WritePrivateProfileString("短信猫设置","是否设置","1","./stage.ini");
	MessageBox("保存成功,请重新启动系统！");
}

BOOL CNoteSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ButGet.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTGET1))); //设置位图
	m_ButGet.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTGET2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTGET1)));
	m_ButSave.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTSAVE1))); //设置位图
	m_ButSave.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTSAVE2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTSAVE1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
