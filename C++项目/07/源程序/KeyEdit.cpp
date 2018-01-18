// KeyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "CustomGrid.h"
#include "KeyEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyEdit
IMPLEMENT_DYNAMIC(CKeyEdit,CEdit);

CKeyEdit::CKeyEdit()
{
	IsNumber =false;
	color = RGB(0,0,0);
}

CKeyEdit::~CKeyEdit()
{
}


BEGIN_MESSAGE_MAP(CKeyEdit, CEdit)
	//{{AFX_MSG_MAP(CKeyEdit)
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR_REFLECT()
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyEdit message handlers

void CKeyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (IsNumber)
		if (((nChar <45)||(nChar>46)&&(nChar<48)||(nChar > 57))&& (nChar != 8))
		{
			nChar = 0;
			Beep(100,100);
		}
		else
			CEdit::OnChar(nChar, nRepCnt, nFlags);
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}

int CKeyEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;
	LOGFONT font;
	font.lfHeight = -12;
	font.lfWidth = 0;
	font.lfItalic = 0;
	font.lfStrikeOut = 0;
	font.lfEscapement = 0;
	font.lfUnderline = 0;
	font.lfWeight = 400;
	font.lfCharSet = 134;
	strcpy(font.lfFaceName,"ËÎÌו");
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&font);
	SetFont(&m_font);
	return 0;
}

void CKeyEdit::SetEditTextColor(COLORREF Color)
{
	color = Color;
	Invalidate();
}

HBRUSH CKeyEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetTextColor(color);
	CBrush brush(color);
	return brush;
}

void CKeyEdit::OnKillfocus() 
{
	CWnd* temp = NULL;
	temp = GetParent();
	if (temp != NULL)		 
	{		
		if (temp->IsKindOf(RUNTIME_CLASS(CCustomGrid))==true)
		{
			CString str;
			GetWindowText(str);
			((CCustomGrid*)(temp))->SetItemText(((CCustomGrid*)(temp))->row,((CCustomGrid*)(temp))->col,str);
			ShowWindow(SW_HIDE);
		}
	}	
}
