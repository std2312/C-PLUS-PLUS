#if !defined(AFX_TEACHERINFODLG_H__1384B1AE_862C_4A9B_A3B1_880EBC2FE2FA__INCLUDED_)
#define AFX_TEACHERINFODLG_H__1384B1AE_862C_4A9B_A3B1_880EBC2FE2FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Teacherinfodlg.h : header file
//
#include "Teacherinfoset.h"
#include "officeset.h"
/////////////////////////////////////////////////////////////////////////////
// CTeacherinfodlg dialog

class CTeacherinfodlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CTeacherinfodlg(CWnd* pParent = NULL);   // standard constructor

	CTeacherinfoset* myteacherset;
	officeset* myofficeset_find;
	bool DisplayRecord();
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CTeacherinfodlg)
	enum { IDD = IDD_DIgteacherinfo };
	CComboBox	m_teachersexc;
	CString	m_teachername;
	CString	m_teacheroffice;
	CString	m_teacherlevel;
	CString	m_teacherknowledge;
	CString	m_teacherid;
	CString	m_teachersex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherinfodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTeacherinfodlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onteacherinfotoolbaradd();
	afx_msg void Onteacherinfotoolbardel();
	afx_msg void Onteacherinfotoolbarfirst();
	afx_msg void Onteacherinfotoolbarlast();
	afx_msg void Onteacherinfotoolbarnext();
	afx_msg void Onteacherinfotoolbarpre();
	afx_msg void Onteacherinfotoolbarsave();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEACHERINFODLG_H__1384B1AE_862C_4A9B_A3B1_880EBC2FE2FA__INCLUDED_)
