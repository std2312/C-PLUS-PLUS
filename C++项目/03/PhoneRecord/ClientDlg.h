#if !defined(AFX_CLIENTDLG_H__5E8A90E7_5B48_40AC_BA45_5830EB03AF0B__INCLUDED_)
#define AFX_CLIENTDLG_H__5E8A90E7_5B48_40AC_BA45_5830EB03AF0B__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	void Clear();
	void AddToGrid();
	CClientDlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CBaseButton	m_ButSave;
	CBaseButton	m_ButMod;
	CBaseButton	m_ButDel;
	CBaseButton	m_ButAdd;
	CListCtrl	m_Grid;
	CString	m_Id;
	CString	m_Name;
	CString	m_Linkman;
	CString	m_Phone;
	CString	m_Email;
	CString	m_Address;
	CString	m_Remark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButsave();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__5E8A90E7_5B48_40AC_BA45_5830EB03AF0B__INCLUDED_)
