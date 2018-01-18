// SuperMarketDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "SuperMarketDlg.h"
#include "Login.h"
#include "Userdlg.h"
#include "Backdlg.h"
#include "Shangpindlg.h"
#include "Providedlg.h"
#include "Employees.h"
#include "Depotdlg.h"
#include "DepotCountdlg.h"
#include "Depotbqdlg.h"
#include "DepotBackdlg.h"
#include "Sellquerydlg.h"
#include "Backquerydlg.h"
#include "Daydlg.h"
#include "Monthdlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuperMarketDlg dialog

CSuperMarketDlg::CSuperMarketDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSuperMarketDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSuperMarketDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSuperMarketDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSuperMarketDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSuperMarketDlg, CDialog)
	//{{AFX_MSG_MAP(CSuperMarketDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(1001,OnShangp)
	ON_COMMAND(1002,OnSellq)
	ON_COMMAND(1004,OnDepot)
	ON_COMMAND(1005,OnNdepot)
	ON_COMMAND(1007,OnDay)
	ON_COMMAND(1008,OnUser)
	ON_COMMAND(ID_MENU_SHANGP, OnMenuShangp)
	ON_COMMAND(ID_MENU_EMP, OnMenuEmp)
	ON_COMMAND(ID_MENU_PROVIDE, OnMenuProvide)
	ON_COMMAND(ID_MENU_BACK, OnMenuBack)
	ON_COMMAND(ID_MENU_SELLQ, OnMenuSellq)
	ON_COMMAND(ID_MENU_BACKQ, OnMenuBackq)
	ON_COMMAND(ID_MENU_DEPOT, OnMenuDepot)
	ON_COMMAND(ID_MENU_NDEPOT, OnMenuNdepot)
	ON_COMMAND(ID_MENU_DAY, OnMenuDay)
	ON_COMMAND(ID_MENU_MONTH, OnMenuMonth)
	ON_COMMAND(ID_MENU_USER, OnMenuUser)
	ON_COMMAND(ID_MENU_ABOUT, OnMenuAbout)
	ON_COMMAND(ID_MENU_BDEPOT, OnMenuBdepot)
	ON_COMMAND(ID_MENU_BDEPOTQ, OnMenuBdepotq)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuperMarketDlg message handlers

BOOL CSuperMarketDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CLogin dlg;
	if(dlg.DoModal() != IDOK)
	{
		CDialog::OnCancel();
	}
	//创建图像列表
	m_ImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSHANGP));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSELLQ));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONDEPOT));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONNDEPOT));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONDAY));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONUSER));
	
	UINT array[8];
	for(int i=0;i<8;i++)
	{
		if(i==2 || i==5)
			array[i] = ID_SEPARATOR; //第3、6个按钮为分隔条
		else
			array[i] = i+1001;
	}
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,8);
	//关联图像列表
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);
	m_ToolBar.SetSizes(CSize(50,60),CSize(32,32)); //设置按钮和图标的大小
	//设置工具栏按钮的显示文本
	m_ToolBar.SetButtonText(0,"商品信息");
	m_ToolBar.SetButtonText(1,"销售查询");
	m_ToolBar.SetButtonText(3,"入库登记");
	m_ToolBar.SetButtonText(4,"库存信息");
	m_ToolBar.SetButtonText(6,"日结查询");
	m_ToolBar.SetButtonText(7,"用户管理");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSuperMarketDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSuperMarketDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSuperMarketDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSuperMarketDlg::OnShangp()
{
	OnMenuShangp();
}

void CSuperMarketDlg::OnSellq()
{
	OnMenuSellq();
}

void CSuperMarketDlg::OnDepot()
{
	OnMenuDepot(); 
}

void CSuperMarketDlg::OnNdepot()
{
	OnMenuNdepot(); 
}

void CSuperMarketDlg::OnDay()
{
	OnMenuDay();
}

void CSuperMarketDlg::OnUser()
{
	OnMenuUser();
}

void CSuperMarketDlg::OnMenuShangp() 
{
	// TODO: Add your command handler code here
	CShangpindlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuEmp() 
{
	// TODO: Add your command handler code here
	CEmployees dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuProvide() 
{
	// TODO: Add your command handler code here
	CProvidedlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuBack() 
{
	// TODO: Add your command handler code here
	CBackdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuSellq() 
{
	// TODO: Add your command handler code here
	CSellquerydlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuBackq() 
{
	// TODO: Add your command handler code here
	CBackquerydlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuDepot() 
{
	// TODO: Add your command handler code here
	CDepotdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuNdepot() 
{
	// TODO: Add your command handler code here
	CDepotCountdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuDay() 
{
	// TODO: Add your command handler code here
	CDaydlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuMonth() 
{
	// TODO: Add your command handler code here
	CMonthdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuUser() 
{
	// TODO: Add your command handler code here
	CUserdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal(); 
}

void CSuperMarketDlg::OnMenuBdepot() 
{
	// TODO: Add your command handler code here
	CDepotBackdlg dlg;
	dlg.DoModal();
}

void CSuperMarketDlg::OnMenuBdepotq() 
{
	// TODO: Add your command handler code here
	CDepotbqdlg dlg;
	dlg.DoModal();
}
