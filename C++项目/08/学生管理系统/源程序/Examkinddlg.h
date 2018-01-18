#if !defined(AFX_EXAMKINDDLG_H__8E57388F_F36A_47C6_9916_074ADCF38D68__INCLUDED_)
#define AFX_EXAMKINDDLG_H__8E57388F_F36A_47C6_9916_074ADCF38D68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Examkinddlg.h : header file
//
#include "Examkindset.h"
#include "Examinfo_submarkset.h"
/////////////////////////////////////////////////////////////////////////////
// CExamkinddlg dialog

class CExamkinddlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CExamkinddlg(CWnd* pParent = NULL);   // standard constructor

	bool DisplayRecord();
	CExamkindset* myexamset;
	CExamkindset* myexamset_find;
    CExaminfo_submarkset* myexamset_findkind;
	bool m_bAdd;

	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CExamkinddlg)
	enum { IDD = IDD_DIgexamkind };
	CString	m_examkind;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamkinddlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamkinddlg)
	virtual BOOL OnInitDialog();
	afx_msg void Ontoolbarexamkindadd();
	afx_msg void Ontoolbarexamkinddel();
	afx_msg void Ontoolbarexamkindfirst();
	afx_msg void Ontoolbarexamkindlast();
	afx_msg void Ontoolbarexamkindnext();
	afx_msg void Ontoolbarexamkindpre();
	afx_msg void Ontoolbarexamkindsave();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMKINDDLG_H__8E57388F_F36A_47C6_9916_074ADCF38D68__INCLUDED_)
