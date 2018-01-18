#if !defined(AFX_CLASSINFODLG_H__1F6F8D3E_B7E1_4FA7_A188_8D11C02FC9DB__INCLUDED_)
#define AFX_CLASSINFODLG_H__1F6F8D3E_B7E1_4FA7_A188_8D11C02FC9DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Classinfodlg.h : header file
//
#include "Classinfoset.h"
#include "Studentinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// CClassinfodlg dialog

class CClassinfodlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CClassinfodlg(CWnd* pParent = NULL);   // standard constructor

	
	bool DisplayRecord();
	CClassinfoset* myclassinfoset;
	CStudentinfoset* myclassinfoset_findref;
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CClassinfodlg)
	enum { IDD = IDD_DIgclassinfo };
	CString	m_classname;
	CString	m_classteacher;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassinfodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClassinfodlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onclassinfotoolbaradd();
	afx_msg void Onclassinfotoolbardel();
	afx_msg void Onclassinfotoolbarfirst();
	afx_msg void Onclassinfotoolbarlast();
	afx_msg void Onclassinfotoolbarnext();
	afx_msg void Onclassinfotoolbarpre();
	afx_msg void Onclassinfotoolbarsave();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSINFODLG_H__1F6F8D3E_B7E1_4FA7_A188_8D11C02FC9DB__INCLUDED_)
