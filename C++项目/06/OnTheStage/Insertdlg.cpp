// Insertdlg.cpp : implementation file
//

#include "stdafx.h"
#include "OnTheStage.h"
#include "Insertdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInsertdlg dialog


CInsertdlg::CInsertdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInsertdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInsertdlg)
	m_Text = _T("");
	m_Num = 0;
	//}}AFX_DATA_INIT
}


void CInsertdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInsertdlg)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDX_Text(pDX, IDC_EDIT2, m_Num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInsertdlg, CDialog)
	//{{AFX_MSG_MAP(CInsertdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsertdlg message handlers

BOOL CInsertdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Combo.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CInsertdlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	m_Condition = m_Combo.GetCurSel();
	CDialog::OnOK();
}
