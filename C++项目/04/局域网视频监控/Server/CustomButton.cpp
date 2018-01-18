// CustomButton.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "CustomButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomButton

int CCustomButton::m_Style = 2;

CCustomButton::CCustomButton()
{
	m_State   = bsNormal;
}

CCustomButton::~CCustomButton()
{
	m_State   = bsNormal;
}


BEGIN_MESSAGE_MAP(CCustomButton, CButton)
	//{{AFX_MSG_MAP(CCustomButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomButton message handlers


void CCustomButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_State = bsDown;
	InvalidateRect(NULL,TRUE);	
}

void CCustomButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	HRGN hRgn = CreateRectRgn( 0, 0, 0, 0 );
	GetWindowRgn(hRgn );
	BOOL ret = PtInRegion( hRgn, point.x, point.y );
	if( ret ) 
	{
		
		if( m_State == bsDown) 
			return ;
		if( m_State != bsHot ) 
		{
			m_State = bsHot;
			InvalidateRect(NULL,TRUE);
			//UpdateWindow();
			SetCapture();
		}
	} 
	else 
	{
		m_State = bsNormal;
		InvalidateRect(NULL,TRUE);	
		ReleaseCapture();
	}	
	DeleteObject( hRgn );	

	CButton::OnMouseMove(nFlags, point);
}

void CCustomButton::OnPaint() 
{
	CPaintDC dc(this); 
	
	CWnd* pWnd = this;
	
	CString		Text;
	CRect		RC;
	CFont		Font;
	CFont		*pOldFont;
	CBrush		Brush;
	CBrush		*pOldBrush;
	CPoint		PT(2,2);
	
	dc.SetBkMode( TRANSPARENT );
	Font.CreateFont( 12, 0, 0, 0, FW_HEAVY, 0, 0, 0, ANSI_CHARSET, \
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, \
		VARIABLE_PITCH | FF_SWISS, "MS Sans Serif" );

	pOldFont = dc.SelectObject( &Font );
	
	if( m_State == bsNormal)
	{
		
		if (m_Style==2)
		{
			CBitmap bmp;
			bmp.LoadBitmap(IDB_BKBUTTON);
			Brush.CreatePatternBrush(&bmp); 
		}
		else
			Brush.CreateSolidBrush( RGB( 200, 200, 200 ) );
		dc.SetTextColor( RGB( 80, 80, 80) );
	}
	else if( m_State == bsDown )
	{
		Brush.CreateSolidBrush( RGB( 160, 160, 160 ) );
		dc.SetTextColor( RGB( 50, 50, 250 ) );
	}
	else if( m_State == bsHot )
	{
		Brush.CreateSolidBrush( RGB( 100, 100, 180 ) );
		dc.SetTextColor( RGB( 250, 250, 0 ) );
	}
	
	pOldBrush = dc.SelectObject( &Brush );
	pWnd->GetClientRect( &RC );
	dc.RoundRect( &RC, PT );
	
	HRGN hRgn = CreateRectRgn( RC.left, RC.top, RC.right, RC.bottom );
	pWnd->SetWindowRgn( hRgn, TRUE );
	DeleteObject( hRgn );
	
	pWnd->GetWindowText(Text );
	dc.DrawText( Text, &RC, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	
	Font.DeleteObject();
	Brush.DeleteObject();

	dc.SelectObject( pOldFont );
	dc.SelectObject( pOldBrush );
}

void CCustomButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( m_State != bsNormal )
	{
		m_State = bsNormal;
		ReleaseCapture();
		InvalidateRect(NULL,TRUE);
	}	
	::SendMessage(GetParent()->m_hWnd,WM_COMMAND, GetDlgCtrlID(), (LPARAM) m_hWnd);
}

void CCustomButton::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	m_State = bsNormal;
	InvalidateRect(NULL,TRUE);	
}

void CCustomButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	OnPaint() ;		
}
