#if !defined(AFX_PRINTFRAM_H__9128B1F4_58D9_4459_8F39_E7DB3B72184D__INCLUDED_)
#define AFX_PRINTFRAM_H__9128B1F4_58D9_4459_8F39_E7DB3B72184D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintFram.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintFram frame

class CPrintFram : public CFrameWnd
{
	DECLARE_DYNCREATE(CPrintFram)
public:
	CPrintFram();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintFram)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintFram();
protected:  // control bar embedded members
	CToolBar    m_ToolBar;
	// Generated message map functions
	//{{AFX_MSG(CPrintFram)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTFRAM_H__9128B1F4_58D9_4459_8F39_E7DB3B72184D__INCLUDED_)
