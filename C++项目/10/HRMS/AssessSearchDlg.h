#if !defined(AFX_ASSESSSEARCHDLG_H__68522F4D_EC52_4F6E_8760_BF58DA5597C0__INCLUDED_)
#define AFX_ASSESSSEARCHDLG_H__68522F4D_EC52_4F6E_8760_BF58DA5597C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssessSearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssessSearchDlg dialog

class CAssessSearchDlg : public CDialog
{
// Construction
public:
	CString GetSearchExpression();
	static DWORD AnalyzeDate(CString &date);
	CAssessSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAssessSearchDlg)
	enum { IDD = IDD_ASSESS_SEARCH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssessSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssessSearchDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SearchExpression;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSESSSEARCHDLG_H__68522F4D_EC52_4F6E_8760_BF58DA5597C0__INCLUDED_)
