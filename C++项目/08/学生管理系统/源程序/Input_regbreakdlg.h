#if !defined(AFX_INPUT_REGBREAKDLG_H__A85269C0_4233_4688_A2AA_8B842F4967F4__INCLUDED_)
#define AFX_INPUT_REGBREAKDLG_H__A85269C0_4233_4688_A2AA_8B842F4967F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Input_regbreakdlg.h : header file
//
#include "Regbrreakinfoset.h"
#include "Studentinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// CInput_regbreakdlg dialog

class CInput_regbreakdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CInput_regbreakdlg(CWnd* pParent = NULL);   // standard constructor

	CRegbrreakinfoset* myregbreakset;
	CStudentinfoset* myfindset_id;

	bool DisplayRecord();

// Dialog Data
	//{{AFX_DATA(CInput_regbreakdlg)
	enum { IDD = IDD_DIgregbreak_input };
	CString	m_regstudentid;
	CString	m_regresult;
	CString	m_regmemo;
	CTime	m_regdate;
	CString	m_regcontent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInput_regbreakdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInput_regbreakdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtninputregbreak();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUT_REGBREAKDLG_H__A85269C0_4233_4688_A2AA_8B842F4967F4__INCLUDED_)
