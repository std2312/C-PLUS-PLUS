#if !defined(AFX_KEYEDIT_H__ACF62101_A3F0_431C_8912_E3FA44359D4A__INCLUDED_)
#define AFX_KEYEDIT_H__ACF62101_A3F0_431C_8912_E3FA44359D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KeyEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKeyEdit window

class CKeyEdit : public CEdit
{
// Construction
public:
	CKeyEdit();
	CFont m_font;
	bool IsNumber; 
	COLORREF color;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetEditTextColor(COLORREF Color);
	virtual ~CKeyEdit();
	DECLARE_DYNAMIC (CKeyEdit)
	// Generated message map functions
protected:
	//{{AFX_MSG(CKeyEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnKillfocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYEDIT_H__ACF62101_A3F0_431C_8912_E3FA44359D4A__INCLUDED_)
