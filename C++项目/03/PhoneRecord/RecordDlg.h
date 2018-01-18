#if !defined(AFX_RECORDDLG_H__5812EA2A_F8F2_4C98_9435_8F5EB92F354E__INCLUDED_)
#define AFX_RECORDDLG_H__5812EA2A_F8F2_4C98_9435_8F5EB92F354E__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordDlg dialog

class CRecordDlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRecordDlg)
	enum { IDD = IDD_RECORD_DIALOG };
	CBaseButton	m_ButPlay;
	CBaseButton	m_ButModPath;
	CBaseButton	m_ButDel;
	CListCtrl	m_Grid;
	CString	m_Name;
	CString	m_Path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButmodpath();
	afx_msg void OnButdel();
	afx_msg void OnButplay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDDLG_H__5812EA2A_F8F2_4C98_9435_8F5EB92F354E__INCLUDED_)
