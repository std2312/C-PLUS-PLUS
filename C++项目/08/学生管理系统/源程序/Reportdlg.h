#if !defined(AFX_REPORTDLG_H__F259AEF7_C622_422F_A02E_0B228791D043__INCLUDED_)
#define AFX_REPORTDLG_H__F259AEF7_C622_422F_A02E_0B228791D043__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Reportdlg.h : header file
//
#include "excel9.h"
#include "Examinfo_submarkset.h"

/////////////////////////////////////////////////////////////////////////////
// CReportdlg dialog

	class CReportdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CReportdlg(CWnd* pParent = NULL);   // standard constructor

	CExaminfo_submarkset* myexamsubmarkset_report;
	CExaminfo_submarkset* myexamsubmarkset_report_sort;
// Dialog Data
	//{{AFX_DATA(CReportdlg)
	enum { IDD = IDD_DIgstudentreport };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReportdlg)
	afx_msg void OnBtnreport();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORTDLG_H__F259AEF7_C622_422F_A02E_0B228791D043__INCLUDED_)
