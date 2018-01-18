#if !defined(AFX_STUDENTINFO_FINDDLG_H__CA354C6C_2B3A_485A_B638_2FF882174B3C__INCLUDED_)
#define AFX_STUDENTINFO_FINDDLG_H__CA354C6C_2B3A_485A_B638_2FF882174B3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Studentinfo_finddlg.h : header file
//
#include "Studentinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// CStudentinfo_finddlg dialog

class CStudentinfo_finddlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CStudentinfo_finddlg(CWnd* pParent = NULL);   // standard constructor

	CStudentinfoset* mystudentset;
	
	bool DisplayRecord();
// Dialog Data
	//{{AFX_DATA(CStudentinfo_finddlg)
	enum { IDD = IDD_DIgstudentinfo };
	CListCtrl	m_List;
	CString	m_studentid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentinfo_finddlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentinfo_finddlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onfindstudentinfo();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTINFO_FINDDLG_H__CA354C6C_2B3A_485A_B638_2FF882174B3C__INCLUDED_)
