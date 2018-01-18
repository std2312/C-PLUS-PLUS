// OnTheStageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OnTheStage.h"
#include "OnTheStageDlg.h"
#include "Insertdlg.h"
#include "ADOConn.h"
#include "Login.h"
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
// COnTheStageDlg dialog

COnTheStageDlg::COnTheStageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnTheStageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COnTheStageDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COnTheStageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnTheStageDlg)
	DDX_Control(pDX, IDC_STATICZ, m_Zstatic);
	DDX_Control(pDX, IDC_EDIT3, m_Zl);
	DDX_Control(pDX, IDC_EDIT2, m_Sje);
	DDX_Control(pDX, IDC_EDIT1, m_Yje);
	DDX_Control(pDX, IDC_DATE, m_Date);
	DDX_Control(pDX, IDC_TIME, m_Time);
	DDX_Control(pDX, IDC_STATICT, m_Tstatic);
	DDX_Control(pDX, IDC_STATICD, m_Dstatic);
	DDX_Control(pDX, IDC_TITLE, m_Title);
	DDX_Control(pDX, IDC_STATICS, m_Sstatic);
	DDX_Control(pDX, IDC_STATICY, m_Ystatic);
	DDX_Control(pDX, IDC_BUTTONOK, m_Ok);
	DDX_Control(pDX, IDC_BUTTONADD, m_Add);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COnTheStageDlg, CDialog)
	//{{AFX_MSG_MAP(COnTheStageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONADD, OnButtonadd)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTONOK, OnButtonok)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnTheStageDlg message handlers

BOOL COnTheStageDlg::OnInitDialog()
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
/*	CLogin dlg;
	if(dlg.DoModal() != IDOK)
	{
		CDialog::OnCancel();
	}*/
	int x,y;
	x = GetSystemMetrics(SM_CXSCREEN);
	y = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(NULL,0,0,x,y,SWP_NOMOVE);
	CRect rect;
	GetClientRect(&rect);
	m_Grid.MoveWindow(10,70,rect.Width()-150,rect.Height()-90);
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	//设置表头
	m_Grid.InsertColumn(0,"商品编号",LVCFMT_LEFT,150,0); 
	m_Grid.InsertColumn(1,"商品名称",LVCFMT_LEFT,230,1); 
	m_Grid.InsertColumn(2,"商品简称",LVCFMT_LEFT,150,2); 
	m_Grid.InsertColumn(3,"商品类别",LVCFMT_LEFT,150,3); 
	m_Grid.InsertColumn(4,"条 形 码",LVCFMT_LEFT,150,4); 
	m_Grid.InsertColumn(5,"销售数量",LVCFMT_LEFT,150,5); 
	m_Grid.InsertColumn(6,"商品单价",LVCFMT_LEFT,150,6); 
	
	font.CreatePointFont(250,"宋体");
	m_Title.SetFont(&font,true);
	CTime time = CTime::GetCurrentTime();
	m_Date.SetWindowText(time.Format("%Y-%m-%d"));
	m_Time.SetWindowText(time.Format("%H:%M:%S"));
	m_Title.MoveWindow(10,20,rect.Width()-20,30);
	m_Add.MoveWindow(rect.Width()-120,70,100,30);
	m_Ystatic.MoveWindow(rect.Width()-120,120,100,30);
	m_Yje.MoveWindow(rect.Width()-120,170,100,30);
	m_Sstatic.MoveWindow(rect.Width()-120,220,100,30);
	m_Sje.MoveWindow(rect.Width()-120,270,100,30);
	m_Zstatic.MoveWindow(rect.Width()-120,320,100,30);
	m_Zl.MoveWindow(rect.Width()-120,370,100,30);
	m_Ok.MoveWindow(rect.Width()-120,420,100,30);
	m_Dstatic.MoveWindow(rect.Width()-120,470,100,30);
	m_Date.MoveWindow(rect.Width()-120,520,100,30);
	m_Tstatic.MoveWindow(rect.Width()-120,570,100,30);
	m_Time.MoveWindow(rect.Width()-120,620,100,30);
	SetTimer(1,1000,NULL);
	i = 0;
	m_Sum = "";
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COnTheStageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COnTheStageDlg::OnPaint() 
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
HCURSOR COnTheStageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COnTheStageDlg::OnButtonadd() 
{
	// TODO: Add your control notification handler code here
	CInsertdlg dlg;
	dlg.DoModal();
	CString Text,sql,field;
	int Num,Condition;
	Text      = dlg.m_Text;
	Condition = dlg.m_Condition;
	Num       = dlg.m_Num;
	switch(Condition)
	{
	case 0:
		field = "SPBH";
		break;
	case 1:
		field = "SPMC";
		break;
	case 2:
		field = "SPJM";
		break;
	case 3:
		field = "TXM";
		break;
	}
	sql.Format("select * from CTXSYS.TB_SHANGPIN where %s='%s'",field,Text);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		CString str,sNum,sum;
		str = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSJG");
		sNum.Format("%d",Num);
		sum.Format("%f",Num*atof(str)+atof(m_Sum));
		m_Grid.InsertItem(i,"");
		m_Grid.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Grid.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Grid.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJM"));
		m_Grid.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPLB"));
		m_Grid.SetItemText(i,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("TXM"));
		m_Grid.SetItemText(i,5,sNum);
		m_Grid.SetItemText(i,6,str);
		m_Sum = sum;
		m_Yje.SetWindowText(m_Sum);
		i++;
	}
	else
		MessageBox("该商品不存在");
	m_AdoConn.ExitConnect();
}

void COnTheStageDlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString ysje,ssje,zl;
	m_Yje.GetWindowText(ysje);
	m_Sje.GetWindowText(ssje);
	zl.Format("%f",atof(ssje)-atof(ysje));
	m_Zl.SetWindowText(zl);
}

void COnTheStageDlg::OnButtonok() 
{
	// TODO: Add your control notification handler code here
	CString ysje,ssje,zl;
	m_Yje.GetWindowText(ysje);
	m_Sje.GetWindowText(ssje);
	if(ysje.IsEmpty() || ssje.IsEmpty())
	{
		MessageBox("应收金额和实收金额不能为空");
		return;
	}
	CString sql;
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	for(int i=0;i<m_Grid.GetItemCount();i++)
	{
		sql.Format("update CTXSYS.TB_DEPOT set SPSL=SPSL-%d where SPBH='%s'",
			atoi(m_Grid.GetItemText(i,5)),m_Grid.GetItemText(i,0));
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	m_AdoConn.ExitConnect();
	Print();
	m_Grid.DeleteAllItems();
}

void COnTheStageDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime time = CTime::GetCurrentTime();
	m_Time.SetWindowText(time.Format("%H:%M:%S"));
	CDialog::OnTimer(nIDEvent);
}

void COnTheStageDlg::Print()
{
	CTime time = CTime::GetCurrentTime();
	CString sql,ph,m_Xsph;
	sql.Format("select * from CTXSYS.TB_SELL where TO_DATE(XSSJ)=\
		TO_DATE('%s','MMDDYYYY')",time.Format("%m%d%Y"));
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		while(!m_AdoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSPH");
			m_AdoConn.m_pRecordset->MoveNext();
		}
		m_Xsph.Format("XS%s%04d",time.Format("%y%m%d"),atoi(ph.Right(4))+1);
	}
	else
		m_Xsph.Format("XS%s0001",time.Format("%y%m%d"));
	
	int i=0,n=0;
	CString spbh,spmc,spjm,splb,txm,xssl,xsdj,xssj;
	for(i=0;i<m_Grid.GetItemCount();i++)
	{
		spbh = m_Grid.GetItemText(i,0);
		spmc = m_Grid.GetItemText(i,1);
		spjm = m_Grid.GetItemText(i,2);
		splb = m_Grid.GetItemText(i,3);
		txm  = m_Grid.GetItemText(i,4);
		xssl = m_Grid.GetItemText(i,5);
		xsdj = m_Grid.GetItemText(i,6);
		sql.Format("insert into CTXSYS.TB_SELL(XSPH,SPBH,SPMC,SPJM,SPLB,TXM,\
			XSSL,SPDJ,XSSJ)values('%s','%s','%s','%s','%s','%s',%d,%f,\
			TO_DATE('%s','MMDDYYYY HH24:MI'))",m_Xsph,spbh,spmc,spjm,
			splb,txm,atoi(xssl),atof(xsdj),time.Format("%m%d%Y %H:%M"));
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	m_AdoConn.ExitConnect();
	m_Sum = "";
	m_Yje.SetWindowText("");
	m_Sje.SetWindowText("");
	i = 0;
	CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	CPrintDialog m_printdlg(FALSE);
	if (m_printdlg.DoModal()==IDOK)
	{
		CDC dc;	
		
		dc.Attach(m_printdlg.GetPrinterDC());

		printx = dc.GetDeviceCaps(LOGPIXELSX);
		printy = dc.GetDeviceCaps(LOGPIXELSY);
		ratex = (double)(printx)/screenx;
		ratey = (double)(printy)/screeny;
		
		i=0;
		str[i][0] = "商品编号";
		str[i][1] = "商品名称";
		str[i][2] = "销售数量";
		str[i][3] = "销售单价";
		str[i][4] = "销售金额";
		double sum  = 0;
		CString strsum = "";
		for(i=1;i<=m_Grid.GetItemCount();i++)
		{
			str[i][0] = m_Grid.GetItemText(i-1,0);
			str[i][1] = m_Grid.GetItemText(i-1,1);
			str[i][2] = m_Grid.GetItemText(i-1,5);
			str[i][3] = m_Grid.GetItemText(i-1,6);
			str[i][4].Format("%0.2f",atoi(str[i][2])*atof(str[i][3]));
			strsum.Format("%0.2f",sum + atof(str[i][4]));
			sum = atof(str[i][4]);
		}
		dc.StartDoc("printstart");
		pfont.CreatePointFont(110,"宋体",&dc);
		dc.TextOut((int)ratex*5,(int)ratey*10,"XX超市");
		dc.TextOut((int)ratex*5,(int)ratey*30,"销售票号：XS0711300001");
		dc.TextOut((int)ratex*5,(int)ratey*50,"销售时间：");
		dc.TextOut((int)ratex*90,(int)ratey*50,time.Format("%Y-%m-%d %H:%M:%S"));
		dc.MoveTo((int)ratex*5,(int)ratey*72);
		dc.LineTo((int)ratex*220,(int)ratey*72);
		dc.MoveTo((int)ratex*5,(int)ratey*74);
		dc.LineTo((int)ratex*220,(int)ratey*74);
		for(int k=0;k<i;k++)
		{
			if(n >= 40)
			{
				n = 1;
				dc.EndPage();
				dc.StartPage();
			}
			for(int j=0;j<5;j++)
			{
				if(j<2)
					dc.TextOut((int)ratex*(5+j*80),(int)ratey*(80+n*20),str[k][j]);	
				else
					dc.TextOut((int)ratex*(5+(j-2)*80),(int)ratey*(80+(n+1)*20),str[k][j]);
			}
			n = n + 2;
		}
		
		dc.MoveTo((int)ratex*5,(int)ratey*(80+n*20));
		dc.LineTo((int)ratex*220,(int)ratey*(80+n*20));
		dc.MoveTo((int)ratex*5,(int)ratey*(82+n*20));
		dc.LineTo((int)ratex*220,(int)ratey*(82+n*20));
		dc.TextOut((int)ratex*5,(int)ratey*(90+n*20),"销售总额："+strsum);
		dc.EndDoc();
		pfont.DeleteObject();
	}
}

void COnTheStageDlg::OnOK()
{
	OnButtonok();
}
