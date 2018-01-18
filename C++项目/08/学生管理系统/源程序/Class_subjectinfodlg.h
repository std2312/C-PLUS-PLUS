#if !defined(AFX_CLASS_SUBJECTINFODLG_H__58563BFC_9E20_45AD_8FC1_84B5744AC30C__INCLUDED_)
#define AFX_CLASS_SUBJECTINFODLG_H__58563BFC_9E20_45AD_8FC1_84B5744AC30C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Class_subjectinfodlg.h : header file
//
#include "Class_subjectset.h"
/////////////////////////////////////////////////////////////////////////////
// CClass_subjectinfodlg dialog

class CClass_subjectinfodlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CClass_subjectinfodlg(CWnd* pParent = NULL);   // standard constructor

	bool DisplayRecord();
	CClass_subjectset* myclass_subjectinfoset;
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CClass_subjectinfodlg)
	enum { IDD = IDD_DIgclass_subject };
	CString	m_classid;
	CString	m_classname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClass_subjectinfodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClass_subjectinfodlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onclasssubjectinfotoolbaradd();
	afx_msg void Onclasssubjectinfotoolbardel();
	afx_msg void Onclasssubjectinfotoolbarfirst();
	afx_msg void Onclasssubjectinfotoolbarlast();
	afx_msg void Onclasssubjectinfotoolbarnext();
	afx_msg void Onclasssubjectinfotoolbarpre();
	afx_msg void Onclasssubjectinfotoolbarsave();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASS_SUBJECTINFODLG_H__58563BFC_9E20_45AD_8FC1_84B5744AC30C__INCLUDED_)
