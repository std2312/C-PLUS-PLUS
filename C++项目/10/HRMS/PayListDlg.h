#if !defined(AFX_PAYLISTDLG_H__64751458_B6A9_4719_81CE_FA2AF9FCF784__INCLUDED_)
#define AFX_PAYLISTDLG_H__64751458_B6A9_4719_81CE_FA2AF9FCF784__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PayListDlg.h : header file
//
#include	"EditableListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CPayListDlg dialog

class CPayListDlg : public CDialog, public CADOView
{
// Construction
public:
	static double GetTotalSum(CString &name, int year, int month);
	BOOL PrintList(CDC *pDC);
	BOOL ShowList(CString& seaExp);
	BOOL SaveModification(CString &sql, long item, long subItem);
	UINT m_CurrentSel;
	BOOL ExportToWord(CString& file);
	BOOL ShowList();
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString* strArray, int count);
	CPayListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPayListDlg)
	enum { IDD = IDD_PAYLIST };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPayListDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPayListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnExporttoword();
	afx_msg void OnDeleteitem();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnSearchRecord();
	afx_msg void OnFindEmployee();
	afx_msg void OnPrintmenunu();
	afx_msg void OnPrinter();
	afx_msg void OnPreview();
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HACCEL m_hAccel;
};




//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYLISTDLG_H__64751458_B6A9_4719_81CE_FA2AF9FCF784__INCLUDED_)
