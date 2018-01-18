// Return.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "Return.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturn dialog


CReturn::CReturn(CWnd* pParent /*=NULL*/)
	: CDialog(CReturn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReturn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturn)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturn, CDialog)
	//{{AFX_MSG_MAP(CReturn)
	ON_BN_CLICKED(IDC_BUTTON_liulan, OnBUTTONliulan)
	ON_BN_CLICKED(IDC_BUTTON_return, OnBUTTONreturn)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturn message handlers



void CReturn::OnBUTTONliulan() 
{
	CFileDialog dlg(TRUE,"mdb",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "(*.mdb)|*.mdb",NULL);
	if(dlg.DoModal()==IDOK)
	{
		CString str;
		str = dlg.GetPathName();
		m_Edit.SetWindowText(str);
	}	
}

void CReturn::OnBUTTONreturn() 
{
	UpdateData();
	CString str;
	m_Edit.GetWindowText(str);	
	CopyFile(str,buf,false);//复制文件
	MessageBox("还原完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	CDialog::OnOK();	
}

void CReturn::OnButtonCancel() 
{
	CDialog::OnCancel();	
}

BOOL CReturn::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\ExamOnline.mdb");	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
