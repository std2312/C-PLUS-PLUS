#if !defined(AFX_USERDLG_H__1DB50856_EF44_48CA_BCD4_219FE99520B6__INCLUDED_)
#define AFX_USERDLG_H__1DB50856_EF44_48CA_BCD4_219FE99520B6__INCLUDED_
#include "LoginSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Userdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserdlg dialog

class CUserdlg : public CDialog
{
// Construction
public:
	void DisplayRecord();
	CUserdlg(CWnd* pParent = NULL);   // standard constructor
	CImageList m_ImageList;
	CLoginSet* m_LoginSet;
// Dialog Data
	//{{AFX_DATA(CUserdlg)
	enum { IDD = IDD_Dlguser };
	CListCtrl	m_List;
	CString	m_Name;
	CString	m_PassWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnButtadd();
	afx_msg void OnButmod();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__1DB50856_EF44_48CA_BCD4_219FE99520B6__INCLUDED_)
