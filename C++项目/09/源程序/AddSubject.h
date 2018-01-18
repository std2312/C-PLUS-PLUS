#if !defined(AFX_ADDSUBJECT_H__8190F4F7_EC72_4AA7_BE5F_B6E7444646CE__INCLUDED_)
#define AFX_ADDSUBJECT_H__8190F4F7_EC72_4AA7_BE5F_B6E7444646CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSubject.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSubject dialog

class CAddSubject : public CDialog
{
// Construction
public:
	void OnOK();
	CAddSubject(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSubject)
	enum { IDD = IDD_ADDSUBJECT };
	CString	m_SubjectName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSubject)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSubject)
	afx_msg void OnOkButton();
	afx_msg void OnCancelButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSUBJECT_H__8190F4F7_EC72_4AA7_BE5F_B6E7444646CE__INCLUDED_)
