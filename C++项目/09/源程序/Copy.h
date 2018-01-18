#if !defined(AFX_COPY_H__F906DA5A_A576_463B_9AFB_9F8142D01284__INCLUDED_)
#define AFX_COPY_H__F906DA5A_A576_463B_9AFB_9F8142D01284__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Copy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCopy dialog

class CCopy : public CDialog
{
// Construction
public:
	CCopy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCopy)
	enum { IDD = IDD_COPY };
	CEdit	m_Edit;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCopy)
	afx_msg void OnBUTTONcheckml();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPY_H__F906DA5A_A576_463B_9AFB_9F8142D01284__INCLUDED_)
