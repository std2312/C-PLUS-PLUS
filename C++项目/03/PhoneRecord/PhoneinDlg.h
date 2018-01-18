#if !defined(AFX_PHONEINDLG_H__BCEB9B59_ABF8_46BE_8F71_2E4FDEE37E81__INCLUDED_)
#define AFX_PHONEINDLG_H__BCEB9B59_ABF8_46BE_8F71_2E4FDEE37E81__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhoneinDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhoneinDlg dialog

class CPhoneinDlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	void AddToGrid();
	CPhoneinDlg(CWnd* pParent = NULL);   // standard constructor
	CString m_Number;
// Dialog Data
	//{{AFX_DATA(CPhoneinDlg)
	enum { IDD = IDD_PHONEIN_DIALOG };
	CBaseButton	m_ButQuery;
	CComboBox	m_Content;
	CComboBox	m_Field;
	CBaseButton	m_ButDialup;
	CBaseButton	m_ButDel;
	CListCtrl	m_Grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPhoneinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButdialup();
	afx_msg void OnButdel();
	afx_msg void OnButquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONEINDLG_H__BCEB9B59_ABF8_46BE_8F71_2E4FDEE37E81__INCLUDED_)
