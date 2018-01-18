#if !defined(AFX_LABRECSEARCHDLG_H__AABF8B4D_E9E9_48AA_98DE_CCCBA1C42AB7__INCLUDED_)
#define AFX_LABRECSEARCHDLG_H__AABF8B4D_E9E9_48AA_98DE_CCCBA1C42AB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LabRecSearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLabRecSearchDlg dialog

class CLabRecSearchDlg : public CDialog
{
// Construction
public:
	CString GetSearchExpression();
	CLabRecSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLabRecSearchDlg)
	enum { IDD = IDD_LABORAGE_RECORD_SEARCH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabRecSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLabRecSearchDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SearchExpression;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABRECSEARCHDLG_H__AABF8B4D_E9E9_48AA_98DE_CCCBA1C42AB7__INCLUDED_)
