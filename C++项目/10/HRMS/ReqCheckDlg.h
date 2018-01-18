#if !defined(AFX_REQCHECKDLG_H__A5C6466E_66AA_4272_94B3_63C32D9FD3BE__INCLUDED_)
#define AFX_REQCHECKDLG_H__A5C6466E_66AA_4272_94B3_63C32D9FD3BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReqCheckDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReqCheckDlg dialog

class CReqCheckDlg : public CDialog
{
// Construction
public:
	BOOL InitReqNumberComboBox(CString &name);
	BOOL SaveReqChk();
	CReqCheckDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReqCheckDlg)
	enum { IDD = IDD_REQ_CHECK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReqCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReqCheckDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdit2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQCHECKDLG_H__A5C6466E_66AA_4272_94B3_63C32D9FD3BE__INCLUDED_)
