// LandingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LandingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLandingDlg dialog


CLandingDlg::CLandingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLandingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLandingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLandingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLandingDlg)
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, IDOK, m_OK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLandingDlg, CDialog)
	//{{AFX_MSG_MAP(CLandingDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLandingDlg message handlers

void CLandingDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString name, code;

	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, code);
	if(!CheckLoading(name, code))
	{
		MessageBox("错误的用户名或密码！", "提示", MB_OK | MB_ICONWARNING);
		((CEdit*)GetDlgItem(IDC_EDIT1))->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(0, -1);
		Invalidate();
		return ;
	}

	m_UserName = name;
	CDialog::OnOK();
}

BOOL CLandingDlg::CheckLoading(CString &name, CString &code)
{

	CADOOperation load;
	CString sql;
	DWORD count = 0;

	sql.Format("select count(*) from tb_user_loader \
		where user_name = '%s' and user_code = '%s' ", name, code);
	load.OpenRecordset(sql);
	if(load.IsLastRow())
	{
		load.CloseRecorset();
		return FALSE;
	}
	load.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	load.CloseRecorset();
	if(count <= 0)
		return FALSE;

	return TRUE;
}

CString CLandingDlg::GetUserName()
{

	return m_UserName;
}

BOOL CLandingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Title.LoadBitmap(IDB_BITMAP10);
	m_Cross.LoadBitmap(IDB_BITMAP9);
	m_BitmapOK = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7));
	m_BitmapCancel = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8));
	m_OK.SetBitmap(m_BitmapOK);
	m_Cancel.SetBitmap(m_BitmapCancel);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLandingDlg::OnPaint() 
{
	
	// TODO: Add your message handler code here
	CWindowDC *dc = (CWindowDC *)GetWindowDC();

	DrawTitleBar(*dc);
	DrawSystemButton(*dc, m_Cross);
	CDialog::OnPaint();

	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CLandingDlg::DrawTitleBar(CWindowDC &dc)
{
	CDC memDC;
  	BITMAP bm;
  
  	memDC.CreateCompatibleDC((CDC*)&dc);
  	memDC.SelectObject(&m_Title);
  	m_Title.GetObject(sizeof(bm), &bm);
  	dc.StretchBlt(3, 1, bm.bmWidth, bm.bmHeight, 
  		&memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	memDC.DeleteDC();

	return TRUE;
}

BOOL CLandingDlg::DrawSystemButton(CWindowDC &dc, CBitmap &bitmap)
{
	CDC memDC;
  	BITMAP bm;
  
  	memDC.CreateCompatibleDC((CDC*)&dc);
	memDC.SelectObject(&m_Cross);
	m_Cross.GetObject(sizeof(bm),&bm);
	dc.StretchBlt(285, 4, bm.bmWidth, bm.bmHeight, 
  		&memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
  	memDC.DeleteDC();

	return TRUE;
}
