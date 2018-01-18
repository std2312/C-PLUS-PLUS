#if !defined(AFX_TEMLOADDLG_H__3E55C55C_574A_4DBA_B998_5B1506B3FDC8__INCLUDED_)
#define AFX_TEMLOADDLG_H__3E55C55C_574A_4DBA_B998_5B1506B3FDC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TemLoadDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTemLoadDlg dialog

class CTemLoadDlg : public CDialog
{
// Construction
public:
	CString GetTemplateType();
	CString GetTemplateName();
	CTemLoadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTemLoadDlg)
	enum { IDD = IDD_LOAD_TEMPLATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTemLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTemLoadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnSelchangeCombo1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_TemType;
	CString m_TemName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEMLOADDLG_H__3E55C55C_574A_4DBA_B998_5B1506B3FDC8__INCLUDED_)
