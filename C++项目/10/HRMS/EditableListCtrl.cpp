// EditableListCtrl.cpp: implementation of the CEditableListCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hrms.h"
#include "EditableListCtrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEditableListCtrl::CEditableListCtrl()
{
	m_CurSelSubItem = -1;
	m_CurSelItem = -1;
}

CEditableListCtrl::~CEditableListCtrl()
{

}

BEGIN_MESSAGE_MAP(CEditableListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CEditableListCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_EN_KILLFOCUS(IDC_LISTEDIT, OnEditKillFocus)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditableListCtrl message handlers

void CEditableListCtrl::ShowEditBox(BOOL isShow, CRect *rc)
{
	ASSERT((isShow && (rc != NULL)) || !isShow);
	if(rc != NULL)
		m_Edit.MoveWindow(rc->left, rc->top, rc->right, rc->bottom, TRUE);
	if(isShow)
	{
		m_Edit.SetFocus();
		m_Edit.ShowWindow(SW_SHOW);
	}
	else if(!isShow)
		m_Edit.ShowWindow(SW_HIDE);
}

void CEditableListCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	if(lpnmlv->iItem >= 0)
	{
		CRect rc;
		CWnd* wnd = GetParent();
		
		m_CurSelItem = lpnmlv->iItem;
		m_CurSelSubItem = lpnmlv->iSubItem;
		CString str = GetItemText(m_CurSelItem, m_CurSelSubItem);
		m_Edit.SetWindowText(str);
		m_Edit.SetSel(0, -1);
		GetSubItemRect(lpnmlv->iItem, lpnmlv->iSubItem, LVIR_LABEL, rc);
		rc.bottom = rc.bottom - rc.top;
		rc.right = rc.right - rc.left;
		ShowEditBox(TRUE, &rc);
		wnd->SendMessage(UM_LISTEDIT_DBCLICK, (WPARAM)lpnmlv, 0);
	}
	*pResult = -1;
}

void CEditableListCtrl::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	RECT rc = {0};
	m_Edit.Create(WS_CHILD| WS_TABSTOP  | WS_VISIBLE |ES_LEFT, rc, this, IDC_LISTEDIT);
	CListCtrl::PreSubclassWindow();
}

void CEditableListCtrl::OnEditKillFocus()
{
	CString str;
	CWnd* wnd;

	wnd = GetParent();
	ShowEditBox(FALSE, NULL);
	m_Edit.GetWindowText(str);
	SetItemText(m_CurSelItem, m_CurSelSubItem, str.GetBuffer(0));
	::SendMessage(wnd->m_hWnd, UM_LISTEDIT_KILLFOCUS, 
		m_CurSelItem, m_CurSelSubItem);
	m_CurSelItem = -1;
	m_CurSelSubItem = -1;
	m_Edit.SetWindowText("");
}

void CEditableListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	SetFocus();
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CEditableListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	SetFocus();
	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CEditableListCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	SetFocus();
	return CListCtrl::OnMouseWheel(nFlags, zDelta, pt);
}

void CEditableListCtrl::ShowEditBox(BOOL isShow, int iItem, int iSubItem)
{

	CString con;
	CRect rc;
	if(!isShow)
	{
		m_Edit.ShowWindow(SW_HIDE);
		return ;
	}
	con = GetItemText(iItem, iSubItem);
	GetSubItemRect(iItem, iSubItem, LVIR_LABEL, rc);
	m_Edit.SetWindowText(con);
	m_Edit.SetFocus();
	m_Edit.SetSel(0, -1);
	m_Edit.MoveWindow(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);
	m_Edit.ShowWindow(SW_SHOW);
}
