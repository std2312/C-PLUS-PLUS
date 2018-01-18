#if !defined(AFX_LABORAGERECORDDLG_H__AE9B4295_7169_4C5F_A3EA_71C90EE09BD4__INCLUDED_)
#define AFX_LABORAGERECORDDLG_H__AE9B4295_7169_4C5F_A3EA_71C90EE09BD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LaborageRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLaborageRecordDlg dialog

class CLaborageRecordDlg : public CDialog, public CADOView
{
// Construction
public:
	void ExportToWord(CString&file);
	BOOL ShowLaborageRecord(CString &seaExpr);
	BOOL SaveModify(int iItem, int iSubItem);
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	BOOL ShowLaborageRecord();
	CLaborageRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLaborageRecordDlg)
	enum { IDD = IDD_LABORAGE_RECORD };
	CEditableListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLaborageRecordDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLaborageRecordDlg)
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnListEditDBClick(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnListEditKillFocus(WPARAM wParam, LPARAM lParam);
	afx_msg void OnFindEmployee();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSearchRecord();
	afx_msg void OnQuit();
	afx_msg void OnAbout();
	afx_msg void OnDeleteitem();
	afx_msg void OnEdit();
	afx_msg void OnExportToWord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LPNMLISTVIEW m_lpNMListView;
	int m_CurSel;
	HACCEL m_hAccel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABORAGERECORDDLG_H__AE9B4295_7169_4C5F_A3EA_71C90EE09BD4__INCLUDED_)
