#if !defined(AFX_FILEINFO_H__F9B69CF6_249D_4702_AFF0_62CC02910971__INCLUDED_)
#define AFX_FILEINFO_H__F9B69CF6_249D_4702_AFF0_62CC02910971__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileInfo.h : header file
//
#include	"ADOView.h"
#include	"EditableListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CFileInfo dialog

class CFileInfo : public CDialog, CADOView
{
// Construction
public:
	BOOL ExportToWord(CString &file);
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int len);
	BOOL ShowAllRecords();
	CFileInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFileInfo)
	enum { IDD = IDD_FILESEARCH_DLG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileInfo)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnFindEmployee();
	afx_msg void OnExporttoword();
	afx_msg void OnDeleteitem();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnSearchRecord();
	afx_msg void OnAddnew();
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_CurSel;
	HACCEL m_hAccel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEINFO_H__F9B69CF6_249D_4702_AFF0_62CC02910971__INCLUDED_)
