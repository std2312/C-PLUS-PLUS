#if !defined(AFX_RESTOREDLG_H__FA0BA792_849E_477E_97D2_13851E38FB2B__INCLUDED_)
#define AFX_RESTOREDLG_H__FA0BA792_849E_477E_97D2_13851E38FB2B__INCLUDED_
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Restoredlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRestoredlg dialog

class CRestoredlg : public CDialog
{
// Construction
public:
	CRestoredlg(CWnd* pParent = NULL);   // standard constructor
	virtual void OnOK();
	CString m_Num;
// Dialog Data
	//{{AFX_DATA(CRestoredlg)
	enum { IDD = IDD_RESTORE_DIALOG };
	CBmpButton	m_ButDel;
	CBmpButton	m_Restore;
	CString	m_Name;
	CString	m_Phone;
	CString	m_Note;
	CString	m_RNote;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestoredlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRestoredlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButsend();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREDLG_H__FA0BA792_849E_477E_97D2_13851E38FB2B__INCLUDED_)
