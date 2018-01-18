#if !defined(AFX_FIND_H__69471F71_A48A_48EF_AB04_D20EBAE9DC00__INCLUDED_)
#define AFX_FIND_H__69471F71_A48A_48EF_AB04_D20EBAE9DC00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Find.h : header file
//
#include "ADOConn.h"
/////////////////////////////////////////////////////////////////////////////
// CFind dialog

class CFind : public CDialog
{
// Construction
public:
	CString Name;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CFind(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFind)
	enum { IDD = IDD_FINDPASSWD };
	CStatic	m_UserName;
	CStatic	m_Question;
	CStatic	m_PasswdStatic;
	CString	m_Answer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFind)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSend();
	afx_msg void OnChangeAnswer();
	afx_msg void OnButtonExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIND_H__69471F71_A48A_48EF_AB04_D20EBAE9DC00__INCLUDED_)
