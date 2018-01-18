#if !defined(AFX_SEARCHREQUESTDLG_H__9FB6835D_969B_4B43_B9E6_A7F3BB4B9C8A__INCLUDED_)
#define AFX_SEARCHREQUESTDLG_H__9FB6835D_969B_4B43_B9E6_A7F3BB4B9C8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchRequestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchRequestDlg dialog

class CSearchRequestDlg : public CDialog
{
// Construction
public:
	CString GetSearchExpression();
	CSearchRequestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchRequestDlg)
	enum { IDD = IDD_SEARCH_REQUEST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchRequestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchRequestDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SearchExpression;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHREQUESTDLG_H__9FB6835D_969B_4B43_B9E6_A7F3BB4B9C8A__INCLUDED_)
