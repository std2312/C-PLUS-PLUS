#if !defined(AFX_ASSESSLIST_H__1C3FA85E_58A9_42C5_95EE_95250EA03610__INCLUDED_)
#define AFX_ASSESSLIST_H__1C3FA85E_58A9_42C5_95EE_95250EA03610__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssessList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssessList dialog

#include	"StdAfx.h"

class CAssessList : public CDialog, public CADOView
{
// Construction
public:
	BOOL SaveModify(int iItem, int subItem);
	BOOL ShowAssessList(CString& seaExpr);
	BOOL ExportToWord(CString& file);
	BOOL ShowAssessList();
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	CAssessList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAssessList)
	enum { IDD = IDD_ASSESSLIST };
	CEditableListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssessList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssessList)
	virtual BOOL OnInitDialog();
	afx_msg void OnExporttoword();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitem();
	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnSearchRecord();
	afx_msg void OnFindEmployee();
	afx_msg LRESULT OnListEditKillFocus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnListEditDBClick(WPARAM wParam, LPARAM lParam);
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LPNMLISTVIEW m_pNMListView;
	HACCEL m_hAccel;
	int m_CurSel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSESSLIST_H__1C3FA85E_58A9_42C5_95EE_95250EA03610__INCLUDED_)
