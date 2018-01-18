#if !defined(AFX_PHONEBOOKDLG_H__48C2F233_3A68_4203_8D77_A43EC4BE09B7__INCLUDED_)
#define AFX_PHONEBOOKDLG_H__48C2F233_3A68_4203_8D77_A43EC4BE09B7__INCLUDED_
#include "PhoneEdit.h"
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhoneBookdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookdlg dialog

class CPhoneBookdlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	virtual void OnOK();
	CPhoneBookdlg(CWnd* pParent = NULL);   // standard constructor
	int m_ID;
// Dialog Data
	//{{AFX_DATA(CPhoneBookdlg)
	enum { IDD = IDD_PHONEBOOK_DIALOG };
	CBmpButton	m_ButMod;
	CBmpButton	m_ButDel;
	CBmpButton	m_ButAdd;
	CPhoneEdit	m_Phone;
	CEdit	m_Name;
	CListCtrl	m_Grid;
	CComboBox	m_Dep;
	CComboBox	m_Duty;
	CComboBox	m_Sex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneBookdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPhoneBookdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONEBOOKDLG_H__48C2F233_3A68_4203_8D77_A43EC4BE09B7__INCLUDED_)
