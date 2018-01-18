// bbbDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "bbbDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern BOOL Flag ; 

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CBbbApp theApp;
extern _ConnectionPtr m_pCon; 
extern _RecordsetPtr m_pRs; 
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
// CBbbDlg dialog

CBbbDlg::CBbbDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBbbDlg::IDD, pParent)
{
//	pdlgBaseInfoM = NULL;
//	pdlgStoreInfoM = NULL;
//	pdlgQueryM = NULL;


	bFlag = FALSE;
	//{{AFX_DATA_INIT(CBbbDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//IDR_MAINFRAME);
}

void CBbbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBbbDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBbbDlg, CDialog)
	//{{AFX_MSG_MAP(CBbbDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_EXIT, OnNew)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_COMMAND(ID_OPERATOR_M, OnOperatorM)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_WM_TIMER()
	ON_COMMAND(IDD_ABOUTBOX, OnAboutbox)
	ON_COMMAND(ID_BOOK_INFO, OnBookInfo)
	ON_COMMAND(ID_PROVIDER_INFO, OnProviderInfo)
	ON_COMMAND(ID_BOOK_TYPE, OnBookType)
	ON_COMMAND(ID_CK_INFO, OnCkInfo)
	ON_COMMAND(ID_DESK_INFO, OnDeskInfo)
	ON_COMMAND(ID_BOOK_INPUT, OnBookInput)
	ON_COMMAND(ID_BOOK_PRICE, OnBookPrice)
	ON_COMMAND(ID_BOOK_PRICE_ADJUST, OnBookPriceAdjust)
	ON_COMMAND(ID_INPUT_BACK, OnInputBack)
	ON_COMMAND(ID_BOOK_ADJUST, OnBookAdjust)
	ON_COMMAND(ID_SALE_M, OnSaleM)
	ON_COMMAND(ID_SALE_BACK, OnSaleBack)
	ON_COMMAND(ID_INPUT_QUERY, OnInputQuery)
	ON_COMMAND(ID_INPUT_BACK_QUERY, OnInputBackQuery)
	ON_COMMAND(ID_SALE_QUERY, OnSaleQuery)
	ON_COMMAND(ID_SALE_BACK_QUERY, OnSaleBackQuery)
	ON_COMMAND(IDB_bookinfo, OnBookInfo)
	ON_COMMAND(IDB_set, OnButton4)
	ON_COMMAND(IDB_cancel, OnCancel)
	ON_COMMAND(IDB_booksell, OnBookInput)
	ON_COMMAND(IDB_sellinfo, OnSaleQuery)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBbbDlg message handlers

BOOL CBbbDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	AdoInit();
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
	
	m_imagelist.Create(24,24,ILC_COLOR24|ILC_MASK,1,1);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON11));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON13));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON19));	
	UINT array[5];
	for(int i=0;i<5;i++)
	{
		array[i]=5000+i;
	}
	m_toolbar.Create(this);
	m_toolbar.SetButtons(array,5);
	m_toolbar.SetButtonText(0,"图书信息");
	m_toolbar.SetButtonText(1,"图书入库");
	m_toolbar.SetButtonText(2,"销售查询");
	m_toolbar.SetButtonText(3,"系统配置");
	m_toolbar.SetButtonText(4,"系统退出");
	m_toolbar.GetToolBarCtrl().SetButtonWidth(60,120);
	m_toolbar.GetToolBarCtrl().SetImageList(&m_imagelist);
	m_toolbar.SetSizes(CSize(70,60),CSize(28,40));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBbbDlg::OnSysCommand(UINT nID, LPARAM lParam)
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



// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBbbDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CBbbDlg::OnNew() 
{
	exit(0);
		
}

void CBbbDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	m_mnu.DrawItem(lpDrawItemStruct);
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CBbbDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	m_mnu.MeasureItem(lpMeasureItemStruct);
	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}






void CBbbDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CDlgLogin dlg;
	dlg.DoModal();	
}

void CBbbDlg::OnOperatorM() 
{
	// TODO: Add your command handler code here
	pdlgoperator1 = new CDlgOperator1;
	pdlgoperator1->DoModal();
	delete pdlgoperator1;	
}

void CBbbDlg::OnButton4() 
{
	CDlgConfigM dlg;
	if (dlg.DoModal() == IDOK)
	{
		return;
	}
	
}

void CBbbDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}

void CBbbDlg::OnAboutbox() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
	
}

void CBbbDlg::OnBookInfo() 
{
	// TODO: Add your command handler code here
	pdlgbookinfo1 = new CDlgBookInfo1;
	pdlgbookinfo1->DoModal();
	delete pdlgbookinfo1;
	
}

void CBbbDlg::OnProviderInfo() 
{
	// TODO: Add your command handler code here
	pdlgproviderinfo1 = new CDlgProviderInfo1;
	pdlgproviderinfo1->DoModal();
	delete pdlgproviderinfo1;
	
}

void CBbbDlg::OnBookType() 
{
	// TODO: Add your command handler code here
	pdlgbookkinds1 = new CDlgBookKinds1;
	pdlgbookkinds1->DoModal();
	delete pdlgbookkinds1;
	
}

void CBbbDlg::OnCkInfo() 
{
	// TODO: Add your command handler code here
	pdlgstoreinfo1 = new CDlgStoreInfo1;
	pdlgstoreinfo1->DoModal();
	delete pdlgstoreinfo1;
	
}

void CBbbDlg::OnDeskInfo() 
{
	// TODO: Add your command handler code here
	pdlgdeskinfo1 = new CDlgDeskInfo1;
	pdlgdeskinfo1->DoModal();
	delete pdlgdeskinfo1;
	
}

void CBbbDlg::OnBookInput() 
{
	// TODO: Add your command handler code here
	pbookinput2 = new CDlgBookInput2;
	pbookinput2->DoModal();
	delete pbookinput2;
	
}

void CBbbDlg::OnBookPrice() 
{
	        	// TODO: Add your command handler code here
	pbookprice2 = new CDlgBookPrice2;
	pbookprice2->DoModal();
	delete pbookprice2;
	
}

void CBbbDlg::OnBookPriceAdjust() 
{
  	// TODO: Add your command handler code here
	pbookadjustprice2 = new CDlgBookAdjustPrice2;
	pbookadjustprice2->DoModal();
	delete pbookadjustprice2;
	
}

void CBbbDlg::OnInputBack() 
{
	// TODO: Add your command handler code here
    pinputback2 = new CDlgInputBack2;
	pinputback2->DoModal();
	delete pinputback2;
	
}

void CBbbDlg::OnBookAdjust() 
{
	// TODO: Add your command handler code here	    
	pbookadjust2 = new CDlgBookAdjust2;
	pbookadjust2->DoModal();
	delete pbookadjust2;
	
}

void CBbbDlg::OnSaleM() 
{
     	// TODO: Add your command handler code here
	pbooksale2 = new CDlgBookSale2;
	pbooksale2->DoModal();
	delete pbooksale2;
	
}

void CBbbDlg::OnSaleBack() 
{
	// TODO: Add your command handler code here
	psaleback2 = new CDlgSaleBack2;
	psaleback2->DoModal();
	delete psaleback2;
	
}

void CBbbDlg::OnInputQuery() 
{
	// TODO: Add your command handler code here
	pinputquery3 = new CDlgInputQuery3;
	pinputquery3->DoModal();
	delete pinputquery3;
	
}

void CBbbDlg::OnInputBackQuery() 
{
// TODO: Add your command handler code here
	pinputbackquery3 = new CDlgInputBackQuery3;
	pinputbackquery3->DoModal();
	delete pinputbackquery3;
	
}

void CBbbDlg::OnSaleQuery() 
{
     // TODO: Add your command handler code here
	psalequery = new CDlgSaleQuery3;
	psalequery->DoModal();
	delete psalequery;
	
}

void CBbbDlg::OnSaleBackQuery() 
{
	// TODO: Add your command handler code here
	psalebackquery = new CDlgSaleBackQuery3;
	psalebackquery->DoModal();
	delete psalebackquery;
	
}

void CBbbDlg::AdoInit()
{

}
void CBbbDlg::OnOK()
{

}

void CBbbDlg::OnCancel()
{
	CDialog::OnCancel();
}
