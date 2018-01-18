#if !defined(AFX_EDITABLELISTCTRL_H__D931FC67_33E0_4A71_8C4B_2E62FBCA6081__INCLUDED_)
#define AFX_EDITABLELISTCTRL_H__D931FC67_33E0_4A71_8C4B_2E62FBCA6081__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditableListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditableListCtrl window

class CEditableListCtrl : public CListCtrl
{
// Construction
public:
	CEditableListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditableListCtrl)
	public:
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowEditBox(BOOL isShow, CRect *rc);
	virtual ~CEditableListCtrl();

	// Generated message map functions
public:
	void ShowEditBox(BOOL isShow, int iItem, int iSubItem);
	//{{AFX_MSG(CEditableListCtrl)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditKillFocus();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	int m_CurSelSubItem;
	int m_CurSelItem;
	CEdit m_Edit;
};

#define	UM_LISTEDIT_KILLFOCUS	WM_USER + 1
#define UM_LISTEDIT_DBCLICK		WM_USER + 2

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITABLELISTCTRL_H__D931FC67_33E0_4A71_8C4B_2E62FBCA6081__INCLUDED_)
