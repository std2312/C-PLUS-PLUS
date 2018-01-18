#if !defined(AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_)
#define AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomButton window
//���尴ť״̬
enum ButtonState  {bsNormal,bsHot,bsDown};

class CCustomButton : public CButton
{
// Construction
public:
	CCustomButton();
	int         m_State;           //��ť��ǰ״̬
	static int  m_Style;           //��ť���
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_)
