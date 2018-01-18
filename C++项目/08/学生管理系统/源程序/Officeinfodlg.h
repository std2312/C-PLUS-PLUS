#if !defined(AFX_OFFICEINFODLG_H__E711E4F0_2583_4E84_8F7E_3583BAD13A37__INCLUDED_)
#define AFX_OFFICEINFODLG_H__E711E4F0_2583_4E84_8F7E_3583BAD13A37__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Officeinfodlg.h : header file
//

#include "officeset.h"
#include "Teacherinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// COfficeinfodlg dialog

class COfficeinfodlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	COfficeinfodlg(CWnd* pParent = NULL);   // standard constructor

	bool DisplayRecord();
	officeset* myofficeset;
    officeset* myofficeset_find;
//	CTeacherinfoset myteacherset_findref;
	bool m_bAdd;

	CToolBar m_ToolBar;
//	bool m_bEdit;
// Dialog Data
	//{{AFX_DATA(COfficeinfodlg)
	enum { IDD = IDD_DIgofficeinfo };
	CString	m_officename;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COfficeinfodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COfficeinfodlg)
	afx_msg void OnBUTTONfirst();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONlast();
	afx_msg void OnBUTTONnext();
	afx_msg void OnBUTTONpre();
	afx_msg void OnBUTTONadd();
	afx_msg void OnBUTTONsave();
	afx_msg void OnBUTTONdel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OFFICEINFODLG_H__E711E4F0_2583_4E84_8F7E_3583BAD13A37__INCLUDED_)
