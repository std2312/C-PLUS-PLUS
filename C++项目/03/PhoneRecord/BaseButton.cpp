// BaseButton.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "BaseButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseButton
//,UINT EnablePic
CBaseButton::CBaseButton(UINT NomalPic,UINT MovePic,UINT DownPic)
{
	 m_DownPic=DownPic;
	 m_NomalPic=NomalPic;
//	 m_EnablePic=EnablePic;
	 m_MovePic=MovePic;
	 m_IsInRect=false;
}

CBaseButton::~CBaseButton()
{

}


BEGIN_MESSAGE_MAP(CBaseButton, CButton)
	//{{AFX_MSG_MAP(CBaseButton)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseButton message handlers

bool CBaseButton::Drawit(CDC *pDC, UINT ResID)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	BITMAP bitStruct;
	bitmap.LoadBitmap(ResID);
	bitmap.GetBitmap(&bitStruct);
	memDC.SelectObject(&bitmap);
	pDC->BitBlt(0,0,bitStruct.bmWidth,bitStruct.bmHeight,&memDC,0,0,SRCCOPY);
	memDC.DeleteDC();
	bitmap.DeleteObject();
	return true;
}


void CBaseButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC* pDC;
	pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	UINT state=lpDrawItemStruct->itemState;
	CRect focRect,rect=lpDrawItemStruct->rcItem;

	focRect.left   = rect.left + 3;
	focRect.right  = rect.right - 3;
	focRect.top    = rect.top + 3;
	focRect.bottom = rect.bottom - 3;
	//Ð´°´Å¥ÎÄ±¾
	pDC->SetBkMode(TRANSPARENT);
	CString sCaption;
	this->GetWindowText(sCaption);
	if(state&ODS_SELECTED)
	{
		Drawit(pDC,m_DownPic);
		pDC->SetTextColor(RGB(159,191,223));
	}
	else
	{
		if(m_IsInRect==true)
		{
			Drawit(pDC,m_MovePic);
			pDC->SetTextColor(RGB(255,100,100));
		}
		else
		{
			Drawit(pDC,m_NomalPic);
			pDC->SetTextColor(RGB(255,255,155));
		}
	}
	if(state&ODS_FOCUS)
	{
		pDC->DrawFocusRect(&focRect);
		lpDrawItemStruct->itemAction=ODA_FOCUS ;
	}
/*	if(state&ODS_DISABLED)
	{
		Drawit(pDC,m_EnablePic);
		pDC->SetTextColor(RGB(96,96,96));
	}*/
	
	pDC->DrawText(sCaption,rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}



BOOL CBaseButton::PreTranslateMessage(MSG* pMsg) 
{

	if(pMsg->hwnd==this->GetSafeHwnd()&&pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
	{
		pMsg->lParam  = 589857;
		pMsg->message = WM_LBUTTONDOWN;
	}
	if(pMsg->hwnd==this->GetSafeHwnd()&&pMsg->message==WM_KEYUP && pMsg->wParam==13)
	{
		pMsg->lParam  = 589857;
		pMsg->message = WM_LBUTTONUP;
	}
	return CButton::PreTranslateMessage(pMsg);
}

void CBaseButton::OnTimer(UINT nIDEvent) 
{
	CPoint point;
	GetCursorPos(&point);
	CRect rcWnd;
	this->GetWindowRect(&rcWnd);
	if(rcWnd.PtInRect(point))
	{
		if(m_IsInRect==true)
			goto END;
		else
		{
			m_IsInRect=true;
			this->Invalidate();
		}
	}
	else
	{
		if(m_IsInRect==false)
			goto END;
		else
		{
			this->Invalidate();
			m_IsInRect=false;
		}
	}
END:	CButton::OnTimer(nIDEvent);
}

void CBaseButton::PreSubclassWindow() 
{
	this->SetTimer(1,10,NULL);
	CButton::PreSubclassWindow();
}


