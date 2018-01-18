#if !defined(AFX_LOGIN_H__74E931E5_0077_47E8_97DA_16C48B838E3F__INCLUDED_)
#define AFX_LOGIN_H__74E931E5_0077_47E8_97DA_16C48B838E3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LOGIN.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CLOGIN dialog

class CLOGIN : public CDialog
{
// Construction
public:
	void OnOK();
	CLOGIN(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLOGIN)
	enum { IDD = IDD_LOGIN };
	CComboBox	m_TypeList;
	CString	m_UserName;
	CString	m_UserPasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLOGIN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLOGIN)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonReg();
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__74E931E5_0077_47E8_97DA_16C48B838E3F__INCLUDED_)
