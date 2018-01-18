#if !defined(AFX_NOTESET_H__2900297E_E55E_4CBD_95A6_697CC0B9569A__INCLUDED_)
#define AFX_NOTESET_H__2900297E_E55E_4CBD_95A6_697CC0B9569A__INCLUDED_
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NoteSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNoteSet dialog

class CNoteSet : public CDialog
{
// Construction
public:
	CNoteSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNoteSet)
	enum { IDD = IDD_NOTESET_DIALOG };
	CBmpButton	m_ButSave;
	CBmpButton	m_ButGet;
	CString	m_Baud;
	CString	m_MerID;
	CString	m_AccrEdit;
	CString	m_Port;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoteSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNoteSet)
	afx_msg void OnButget();
	afx_msg void OnButsave();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTESET_H__2900297E_E55E_4CBD_95A6_697CC0B9569A__INCLUDED_)
