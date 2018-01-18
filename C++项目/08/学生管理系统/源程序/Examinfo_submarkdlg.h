#if !defined(AFX_EXAMINFO_SUBMARKDLG_H__214923BB_3D93_4993_88AB_D5FAD4C8BFD3__INCLUDED_)
#define AFX_EXAMINFO_SUBMARKDLG_H__214923BB_3D93_4993_88AB_D5FAD4C8BFD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Examinfo_submarkdlg.h : header file
//
#include "Examinfo_submarkset.h"
#include "Studentinfoset.h"
/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkdlg dialog

class CExaminfo_submarkdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CExaminfo_submarkdlg(CWnd* pParent = NULL);   // standard constructor
	CExaminfo_submarkset* myexamsubmarkset; 
	CExaminfo_submarkset* myexamsubmarkset_findsame;
	CStudentinfoset* myfindset_id; 
	bool DisplayRecord();
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CExaminfo_submarkdlg)
	enum { IDD = IDD_DIgexaminfo_submark };
	CString	m_studentid;
	float	m_submark;
	CString	m_examsubject;
	CString	m_examkind;
	CTime	m_examdate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExaminfo_submarkdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExaminfo_submarkdlg)
	afx_msg void Oninputsavemarks();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMINFO_SUBMARKDLG_H__214923BB_3D93_4993_88AB_D5FAD4C8BFD3__INCLUDED_)
