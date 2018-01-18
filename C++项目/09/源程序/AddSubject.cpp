// AddSubject.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "AddSubject.h"
#include "TextManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSubject dialog


CAddSubject::CAddSubject(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSubject::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSubject)
	m_SubjectName = _T("");
	//}}AFX_DATA_INIT
}


void CAddSubject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSubject)
	DDX_Text(pDX, IDC_SubjectName, m_SubjectName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSubject, CDialog)
	//{{AFX_MSG_MAP(CAddSubject)
	ON_BN_CLICKED(IDC_OK_BUTTON, OnOkButton)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancelButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSubject message handlers

void CAddSubject::OnOkButton() 
{
	CDialog::OnOK();	
}

void CAddSubject::OnOK()
{
	OnOkButton();
}

void CAddSubject::OnCancelButton() 
{
	CDialog::OnCancel();
	
}
