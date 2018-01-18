#if !defined(AFX_USERDLG_H__6CBEB45E_AF98_4C45_89E4_40B15057B929__INCLUDED_)
#define AFX_USERDLG_H__6CBEB45E_AF98_4C45_89E4_40B15057B929__INCLUDED_
#include "BmpButton.h"
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
	void AddToList();
	virtual void OnOK();
	CUserdlg(CWnd* pParent = NULL);   // standard constructor
	CImageList     m_ImageList;
	CString        m_oName;
// Dialog Data
	//{{AFX_DATA(CUserdlg)
	enum { IDD = IDD_USER_DIALOG };
	CBmpButton	m_Cancel;
	CBmpButton	m_ButMod;
	CBmpButton	m_ButDel;
	CBmpButton	m_ButAdd;
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
	afx_msg void OnButtonadd();
	afx_msg void OnButtonmod();
	afx_msg void OnButtondel();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__6CBEB45E_AF98_4C45_89E4_40B15057B929__INCLUDED_)
