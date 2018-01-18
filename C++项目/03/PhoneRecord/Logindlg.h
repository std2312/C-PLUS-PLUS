#if !defined(AFX_LOGINDLG_H__F09D4565_FDB2_4E89_A833_8EEFE78F90C5__INCLUDED_)
#define AFX_LOGINDLG_H__F09D4565_FDB2_4E89_A833_8EEFE78F90C5__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Logindlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog

class CLogindlg : public CDialog
{
// Construction
public:
	CLogindlg(CWnd* pParent = NULL);   // standard constructor
	int m_Time;
// Dialog Data
	//{{AFX_DATA(CLogindlg)
	enum { IDD = IDD_LOGIN_DIALOG };
	CBaseButton	m_Ok;
	CBaseButton	m_Canel;
	CString	m_Name;
	CString	m_Pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogindlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogindlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__F09D4565_FDB2_4E89_A833_8EEFE78F90C5__INCLUDED_)
