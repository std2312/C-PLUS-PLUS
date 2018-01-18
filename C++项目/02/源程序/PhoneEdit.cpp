// PhoneEdit.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "PhoneEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneEdit

CPhoneEdit::CPhoneEdit()
{
}

CPhoneEdit::~CPhoneEdit()
{
}


BEGIN_MESSAGE_MAP(CPhoneEdit, CEdit)
	//{{AFX_MSG_MAP(CPhoneEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneEdit message handlers

void CPhoneEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==8) //退格键
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	if((nChar<48 || nChar>57)) //只允许输入数字
		nChar = 0;
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);

}
