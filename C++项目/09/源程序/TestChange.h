#if !defined(AFX_TESTCHANGE_H__6D322C27_9332_4EE2_A277_2E3EBD8D9D68__INCLUDED_)
#define AFX_TESTCHANGE_H__6D322C27_9332_4EE2_A277_2E3EBD8D9D68__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestChange.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestChange dialog

class CTestChange : public CDialog
{
// Construction
public:
	void OnOK();
	int testid;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CTestChange(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestChange)
	enum { IDD = IDD_TESTCHANGE };
	CString	m_Question;
	CString	m_Answer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestChange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestChange)
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHANGE_H__6D322C27_9332_4EE2_A277_2E3EBD8D9D68__INCLUDED_)
