#if !defined(AFX_BMPBUTTON_H__16D450A9_C371_4A54_9E0B_D7DB4D5A2167__INCLUDED_)
#define AFX_BMPBUTTON_H__16D450A9_C371_4A54_9E0B_D7DB4D5A2167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BmpButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBmpButton window

class CBmpButton : public CButton
{
// Construction
public:
	CBmpButton();
	HBITMAP m_Hbitmap1;
	HBITMAP m_Hbitmap2;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetHBitmap(HBITMAP m_hbmp1, HBITMAP m_hbmp2);
	virtual ~CBmpButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBmpButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBUTTON_H__16D450A9_C371_4A54_9E0B_D7DB4D5A2167__INCLUDED_)
