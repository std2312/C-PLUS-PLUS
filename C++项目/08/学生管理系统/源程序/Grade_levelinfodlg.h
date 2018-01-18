#if !defined(AFX_GRADE_LEVELINFODLG_H__E07BE569_1121_440F_ACA7_2C6A13949FDC__INCLUDED_)
#define AFX_GRADE_LEVELINFODLG_H__E07BE569_1121_440F_ACA7_2C6A13949FDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Grade_levelinfodlg.h : header file
//
#include "Grade_levelset.h"
#include "Examinfo_submarkset.h"
/////////////////////////////////////////////////////////////////////////////
// CGrade_levelinfodlg dialog

class CGrade_levelinfodlg : public CDialog
{
// Construction
public:
	CGrade_levelinfodlg(CWnd* pParent = NULL);   // standard constructor
   
	bool DisplayRecord();
	CExaminfo_submarkset* exammark_findbestset;
	CExaminfo_submarkset* exammark_findbetterset;
	CExaminfo_submarkset* exammark_findnormalset;
	CExaminfo_submarkset* exammark_findworseset;

	CGrade_levelset* gradelevel_findset;
    CGrade_levelset* findbest_uplowset;
	CGrade_levelset* findbetter_uplowset;
	CGrade_levelset* findnormal_uplowset;
	CGrade_levelset* findworse_uplowset;
	float best_upgrade,best_lowgrade;
// Dialog Data
	//{{AFX_DATA(CGrade_levelinfodlg)
	enum { IDD = IDD_DIggrade_leveldlg };
	CListCtrl	m_List3;
	CComboBox	m_gradekindC;
	CString	m_gradekind;
	float	m_lowgrade;
	float	m_upgrade;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrade_levelinfodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGrade_levelinfodlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnsetgradelevel();
	afx_msg void OnBtnfindbest();
	afx_msg void OnBtnfindbetter();
	afx_msg void OnBtnfindnormal();
	afx_msg void OnBtnfindworse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADE_LEVELINFODLG_H__E07BE569_1121_440F_ACA7_2C6A13949FDC__INCLUDED_)
