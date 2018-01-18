#if !defined(AFX_BACK_H__ACA372B2_BB6E_47E4_B0E9_54A086CC06C1__INCLUDED_)
#define AFX_BACK_H__ACA372B2_BB6E_47E4_B0E9_54A086CC06C1__INCLUDED_
#include "TextManage.h"
#include "ResultSelect.h"
#include "SQLManage.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Back.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBack dialog

class CBack : public CDialog
{
// Construction
public:
	CSQLManage* sqlmanagedlg;
	CResultSelect* resultselectdlg;
	CTextManage* testmanagedlg;
	CBack(CWnd* pParent = NULL);  // standard constructor
// Dialog Data
	//{{AFX_DATA(CBack)
	enum { IDD = IDD_BACKMANAGE };
	CTabCtrl	m_BackTab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBack)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBack)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeBackTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACK_H__ACA372B2_BB6E_47E4_B0E9_54A086CC06C1__INCLUDED_)
