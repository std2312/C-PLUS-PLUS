#if !defined(AFX_PHONEOUTDLG_H__A6478E53_A27A_4773_80D0_63A02EB57D46__INCLUDED_)
#define AFX_PHONEOUTDLG_H__A6478E53_A27A_4773_80D0_63A02EB57D46__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhoneoutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhoneoutDlg dialog

class CPhoneoutDlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CPhoneoutDlg(CWnd* pParent = NULL);   // standard constructor
	CString m_Number;
// Dialog Data
	//{{AFX_DATA(CPhoneoutDlg)
	enum { IDD = IDD_PHONEOUT_DIALOG };
	CBaseButton	m_ButQuery;
	CComboBox	m_Content;
	CComboBox	m_Field;
	CBaseButton	m_ButDialup;
	CBaseButton	m_ButDel;
	CListCtrl	m_Grid;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneoutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPhoneoutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButquery();
	afx_msg void OnButdel();
	afx_msg void OnButdialup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONEOUTDLG_H__A6478E53_A27A_4773_80D0_63A02EB57D46__INCLUDED_)
