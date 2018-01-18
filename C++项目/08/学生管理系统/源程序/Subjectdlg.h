#if !defined(AFX_SUBJECTDLG_H__5328D27F_D27A_41F5_87B0_3AC80F438A2B__INCLUDED_)
#define AFX_SUBJECTDLG_H__5328D27F_D27A_41F5_87B0_3AC80F438A2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Subjectdlg.h : header file
//
#include "Subjectinfo.h"
#include "Class_subjectset.h"
/////////////////////////////////////////////////////////////////////////////
// CSubjectdlg dialog

class CSubjectdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CSubjectdlg(CWnd* pParent = NULL);   // standard constructor

	bool DisplayRecord();
	CSubjectinfo* mysubjectset;
    CSubjectinfo* mysubjectset_find;
	CClass_subjectset* myclass_subject_findref;
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CSubjectdlg)
	enum { IDD = IDD_DIg_subjectinfo };
	CString	m_subjectname;
	CString	m_subjectid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubjectdlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onsubjectinfotoolbaradd();
	afx_msg void Onsubjectinfotoolbardel();
	afx_msg void Onsubjectinfotoolbarfirst();
	afx_msg void Onsubjectinfotoolbarlast();
	afx_msg void Onsubjectinfotoolbarnext();
	afx_msg void Onsubjectinfotoolbarpre();
	afx_msg void Onsubjectinfotoolbarsave();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTDLG_H__5328D27F_D27A_41F5_87B0_3AC80F438A2B__INCLUDED_)
