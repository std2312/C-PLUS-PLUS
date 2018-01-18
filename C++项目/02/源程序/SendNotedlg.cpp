// SendNotedlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "SendNotedlg.h"
#include "Bookdlg.h"
#include "Notedlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendNotedlg dialog


CSendNotedlg::CSendNotedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendNotedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendNotedlg)
	m_Note = _T("");
	//}}AFX_DATA_INIT
}


void CSendNotedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendNotedlg)
	DDX_Control(pDX, IDC_BUTSEND, m_ButSend);
	DDX_Control(pDX, IDC_BUTNOTE, m_ButNote);
	DDX_Control(pDX, IDC_BUTCLEAR, m_ButClear);
	DDX_Control(pDX, IDC_BUTBOOK, m_ButBook);
	DDX_Control(pDX, IDC_BUTDEL, m_ButDel);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Note);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendNotedlg, CDialog)
	//{{AFX_MSG_MAP(CSendNotedlg)
	ON_BN_CLICKED(IDC_BUTBOOK, OnButbook)
	ON_BN_CLICKED(IDC_BUTDEL, OnButdel)
	ON_BN_CLICKED(IDC_BUTCLEAR, OnButclear)
	ON_BN_CLICKED(IDC_BUTNOTE, OnButnote)
	ON_BN_CLICKED(IDC_BUTSEND, OnButsend)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendNotedlg message handlers

BOOL CSendNotedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"编号",LVCFMT_LEFT,80,0); //设置表头
	m_Grid.InsertColumn(1,"姓名",LVCFMT_LEFT,80,1); 
	m_Grid.InsertColumn(2,"电话",LVCFMT_LEFT,150,2);
	
	m_ButBook.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTBOOK1))); //设置位图
	m_ButBook.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTBOOK2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTBOOK1)));
	m_ButDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTDEL1))); //设置位图
	m_ButDel.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTDEL1)));
	m_ButClear.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTCLEAR1))); //设置位图
	m_ButClear.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTCLEAR2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTCLEAR1)));
	m_ButNote.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTNOTE1))); //设置位图
	m_ButNote.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTNOTE2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTNOTE1)));
	m_ButSend.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BUTSEND1))); //设置位图
	m_ButSend.SetHBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTSEND2)),
		LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BUTSEND1)));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendNotedlg::OnButbook() 
{
	// TODO: Add your control notification handler code here
	CBookdlg dlg;
	dlg.DoModal();
	int num = dlg.m_Num;
	for(int i=0;i<num;i++)
	{
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,dlg.m_ID[i]);
		m_Grid.SetItemText(i,1,dlg.m_Name[i]);
		m_Grid.SetItemText(i,2,dlg.m_Phone[i]);
	}
}

void CSendNotedlg::OnButdel() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Grid.GetSelectionMark();
	m_Grid.DeleteItem(pos);
}

void CSendNotedlg::OnButclear() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
}

void CSendNotedlg::OnButnote() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CNotedlg dlg;
	dlg.DoModal();
	m_Note += dlg.m_Note;
	UpdateData(FALSE);
}

void CSendNotedlg::OnButsend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString port,baud,merid,accredit;
	char buf[128];
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
	CString str="其中：";
	int num = 0;
	for(int i=0;i<m_Grid.GetItemCount();i++)
	{
		CString phone = m_Grid.GetItemText(i,2);
		if(GSMModemSMSsend(NULL,8,(char*)(LPCTSTR)m_Note,m_Note.GetLength(),
			(char*)(LPCTSTR)phone,FALSE))
		{
			num++;
		}
		else
		{
			str += m_Grid.GetItemText(i,1);
			str += ",";
		}
	}
	if(num == i)
	{
		MessageBox("发送成功");
	}
	else if(num>0 && num<i)
	{
		str += "发送失败";
		MessageBox(str);
	}
	else
	{
		MessageBox("发送失败");
	}
}

void CSendNotedlg::OnOK()
{
}

void CSendNotedlg::OnDestroy() 
{
	GSMModemRelease();
	CDialog::OnDestroy();
}
