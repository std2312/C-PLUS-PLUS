#if !defined(AFX_BOOKDLG_H__307D052F_1152_4771_91A4_F05E119BE045__INCLUDED_)
#define AFX_BOOKDLG_H__307D052F_1152_4771_91A4_F05E119BE045__INCLUDED_
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bookdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookdlg dialog

class CBookdlg : public CDialog
{
// Construction
public:
	int m_Num;
	CBookdlg(CWnd* pParent = NULL);   // standard constructor
	CString m_ID[100];
	CString m_Name[100];
	CString m_Phone[100];
// Dialog Data
	//{{AFX_DATA(CBookdlg)
	enum { IDD = IDD_BOOK_DIALOG };
	CBmpButton	m_ButDuty;
	CBmpButton	m_ButDep;
	CBmpButton	m_ButAll;
	CComboBox	m_Duty;
	CComboBox	m_Dep;
	CListCtrl	m_Grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtondep();
	afx_msg void OnButtonduty();
	afx_msg void OnButtonall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKDLG_H__307D052F_1152_4771_91A4_F05E119BE045__INCLUDED_)
