#if !defined(AFX_APPLERSEARCHDLG_H__AA644F1B_80C2_4A7C_8FD9_DE3F165A3B10__INCLUDED_)
#define AFX_APPLERSEARCHDLG_H__AA644F1B_80C2_4A7C_8FD9_DE3F165A3B10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ApplerSearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CApplerSearchDlg dialog

class CApplerSearchDlg : public CDialog
{
// Construction
public:
	CString GetSearchCondition();
	CApplerSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CApplerSearchDlg)
	enum { IDD = IDD_APPLER_SEARCH_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApplerSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CApplerSearchDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SearchExpression;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPLERSEARCHDLG_H__AA644F1B_80C2_4A7C_8FD9_DE3F165A3B10__INCLUDED_)
