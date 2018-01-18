#if !defined(AFX_REGBREAK_FINDDLG_H__310B0BCD_14D6_433B_B97B_A5A8F76C5DE3__INCLUDED_)
#define AFX_REGBREAK_FINDDLG_H__310B0BCD_14D6_433B_B97B_A5A8F76C5DE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Regbreak_finddlg.h : header file
//
#include "Regbrreakinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// CRegbreak_finddlg dialog

class CRegbreak_finddlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CRegbreak_finddlg(CWnd* pParent = NULL);   // standard constructor

	CRegbrreakinfoset* myregbreakset_find;
	bool DisplayRecord();

// Dialog Data
	//{{AFX_DATA(CRegbreak_finddlg)
	enum { IDD = IDD_Dlgregbreak_find };
	CListCtrl	m_list2;
	CString	m_studentid;
	CString	m_regresult;
	CString	m_regmemo;
	CString	m_regcontent;
	CTime	m_regdate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegbreak_finddlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegbreak_finddlg)
	afx_msg void OnBtnfindregbreakinfo();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGBREAK_FINDDLG_H__310B0BCD_14D6_433B_B97B_A5A8F76C5DE3__INCLUDED_)
