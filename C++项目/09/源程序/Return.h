#if !defined(AFX_RETURN_H__42BF0475_70DA_4DE4_A820_E797FB6AECB5__INCLUDED_)
#define AFX_RETURN_H__42BF0475_70DA_4DE4_A820_E797FB6AECB5__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Return.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturn dialog

class CReturn : public CDialog
{
// Construction
public:
	CReturn(CWnd* pParent = NULL);   // standard constructor
	char buf[256];
// Dialog Data
	//{{AFX_DATA(CReturn)
	enum { IDD = IDD_SQLRETURN };
	CEdit	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturn)
	afx_msg void OnBUTTONliulan();
	afx_msg void OnBUTTONreturn();
	afx_msg void OnButtonCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURN_H__42BF0475_70DA_4DE4_A820_E797FB6AECB5__INCLUDED_)
