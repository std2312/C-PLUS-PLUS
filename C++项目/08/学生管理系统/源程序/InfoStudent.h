#if !defined(AFX_INFOSTUDENT_H__FF64ECB3_33F5_4893_8C27_7E11B0C37BF2__INCLUDED_)
#define AFX_INFOSTUDENT_H__FF64ECB3_33F5_4893_8C27_7E11B0C37BF2__INCLUDED_
#include "Studentinfoset.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoStudent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoStudent dialog

class CInfoStudent : public CDialog
{
// Construction
public:
	CInfoStudent(CWnd* pParent = NULL);   // standard constructor
	CToolBar m_ToolBar;
	CStudentinfoset* mystudentset;
	bool DisplayRecord();
// Dialog Data
	//{{AFX_DATA(CInfoStudent)
	enum { IDD = IDD_DIginfostudent };
	CString	m_studentaddr;
	float	m_studentage;
	CString	m_studentclass;
	CString	m_studentname;
	CString	m_studentphone;
	CString	m_studentsex;
	CString	m_studentid;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfoStudent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfoStudent)
	afx_msg void Onsubjectinfotoolbaradd();
	afx_msg void Onsubjectinfotoolbardel();
	afx_msg void Onsubjectinfotoolbarfirst();
	afx_msg void Onsubjectinfotoolbarlast();
	afx_msg void Onsubjectinfotoolbarnext();
	afx_msg void Onsubjectinfotoolbarpre();
	afx_msg void Onsubjectinfotoolbarsave();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFOSTUDENT_H__FF64ECB3_33F5_4893_8C27_7E11B0C37BF2__INCLUDED_)
