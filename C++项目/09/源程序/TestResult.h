#if !defined(AFX_TESTRESULT_H__DA2ACF34_3A08_4CC5_AD09_636E597BB65C__INCLUDED_)
#define AFX_TESTRESULT_H__DA2ACF34_3A08_4CC5_AD09_636E597BB65C__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestResult.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestResult dialog

class CTestResult : public CDialog
{
// Construction
public:
	CString TimeStr;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CTestResult(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestResult)
	enum { IDD = IDD_TESTRESULT };
	CListCtrl	m_ResultList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestResult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestResult)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTRESULT_H__DA2ACF34_3A08_4CC5_AD09_636E597BB65C__INCLUDED_)
