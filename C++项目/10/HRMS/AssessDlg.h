#if !defined(AFX_ASSESSDLG_H__69C5A1C3_FF90_4485_A029_4FBD61F24D43__INCLUDED_)
#define AFX_ASSESSDLG_H__69C5A1C3_FF90_4485_A029_4FBD61F24D43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssessDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssessDlg dialog

class CAssessDlg : public CDialog
{
// Construction
public:
	double GetDlgItemFloat(UINT id);
	BOOL SaveAssess();
	CAssessDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAssessDlg)
	enum { IDD = IDD_OPERATION_ASSESS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSESSDLG_H__69C5A1C3_FF90_4485_A029_4FBD61F24D43__INCLUDED_)
