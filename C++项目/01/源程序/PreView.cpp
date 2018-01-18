// PreView.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
#include "PreView.h"
#include "Panel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreView
#include "CaptureDlg.h"
int CPreView::m_CurIndex = 0;

CPreView::CPreView()
	:m_Selected (FALSE),m_Index(0),m_Dbled(FALSE),m_ShowImage(FALSE)
	, m_Stop(psPreview)
{
	m_Bitmap.LoadBitmap(IDB_NOSIGNAL);
}

CPreView::~CPreView()
{
	m_Bitmap.Detach();
}


BEGIN_MESSAGE_MAP(CPreView, CStatic)
	//{{AFX_MSG_MAP(CPreView)
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreView message handlers

void CPreView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	GetClientRect(rc);
	if(m_Index == m_CurIndex)
		m_Selected = TRUE;
	else
		m_Selected = FALSE;
	if(m_Selected)
	{
		CPen pen(PS_SOLID,2,RGB(0,255,0));
		dc.SelectObject(&pen);
		dc.Rectangle(rc);
	}
	else
	{
		CPen pen(PS_SOLID,2,RGB(55,55,55));
		dc.SelectObject(&pen);
		dc.Rectangle(rc);
	}
	if(m_ShowImage) //有视频信号
	{
		CBrush brush (RGB(255,0,255));
		dc.SelectObject(&brush);
		rc.DeflateRect(2,2,2,2);
		dc.FillRect(rc,&brush);
	}
	else //无视频信号
	{
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		memDC.SelectObject(&m_Bitmap);
		BITMAP bInfo;
		m_Bitmap.GetBitmap(&bInfo);
		int x = bInfo.bmWidth;
		int y = bInfo.bmHeight;
		dc.StretchBlt(1,1,rc.Width()-2,rc.Height()-2,&memDC,1,1,x,y,SRCCOPY);
		memDC.DeleteDC();
	}
	// Do not call CStatic::OnPaint() for painting messages
}

void CPreView::OnSetFocus(CWnd* pOldWnd) 
{
	CStatic::OnSetFocus(pOldWnd);
}

void CPreView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int preIndex = m_CurIndex ;
	if(m_CurIndex==-1)
		preIndex = m_Index;
	m_CurIndex = m_Index;
	((CPanel*)GetParent())->RefreshWnd(preIndex,m_Index);		
	CStatic::OnLButtonDown(nFlags, point);
}

void CPreView::OnSize(UINT nType, int cx, int cy) 
{
	if(m_ShowImage)
	{		
		if(m_Stop==psPreview)
		{
			VCAUpdateOverlayWnd(GetParent()->m_hWnd);
			VCAUpdateVideoPreview(m_Index,m_hWnd);
		}
	}
	CStatic::OnSize(nType, cx, cy);
}

void CPreView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	m_CurIndex = m_Index;
	if(m_Stop!=psPreview)  //在停止预览时禁止双击
		return;
	m_Dbled = ! m_Dbled;
	//记录原始区域大小
	CRect rc,prc;
	GetClientRect(rc);
	this->MapWindowPoints(GetParent(),rc);

	GetParent()->GetClientRect(prc);
	int div = ((CPanel*)GetParent())->m_Div;
	prc.DeflateRect(div,div,div,div);
	((CPanel*)GetParent())->OnSize(0,0,0);
	if(m_Dbled)
	{
		((CPanel*)GetParent())->ShowOnly(m_Index);
		SetWindowPos(&wndTop,prc.left,prc.top,prc.Width(),prc.Height(),SWP_SHOWWINDOW);
		if (m_ShowImage )
		{
			VCAUpdateOverlayWnd(GetParent()->m_hWnd);
			VCAUpdateVideoPreview(m_Index,m_hWnd);	
			Invalidate();
		}
	}
	else
	{
		((CPanel*)GetParent())->ShowAll();
		if(m_ShowImage)
		{
			VCAUpdateOverlayWnd(GetParent()->m_hWnd);
			((CPanel*)GetParent())->UpdateAllPreView();
			 VCAUpdateVideoPreview(m_Index,m_hWnd);
			Invalidate();
		}	
	}
	CStatic::OnLButtonDblClk(nFlags, point);
}


