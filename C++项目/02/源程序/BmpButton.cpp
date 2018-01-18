// BmpButton.cpp : implementation file
//

#include "stdafx.h"
#include "NoteManage.h"
#include "BmpButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpButton

CBmpButton::CBmpButton()
{
}

CBmpButton::~CBmpButton()
{
}


BEGIN_MESSAGE_MAP(CBmpButton, CButton)
	//{{AFX_MSG_MAP(CBmpButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpButton message handlers

void CBmpButton::SetHBitmap(HBITMAP m_hbmp1, HBITMAP m_hbmp2)
{
	m_Hbitmap1 = m_hbmp1;
	m_Hbitmap2 = m_hbmp2;
}

void CBmpButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CButton::OnMouseMove(nFlags, point);
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point))
	{
		SetCapture();
		SetBitmap(m_Hbitmap1);
	}
	else
	{
		ReleaseCapture();
		SetBitmap(m_Hbitmap2);
	}
}
