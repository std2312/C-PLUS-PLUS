#if !defined(AFX_APPLERLIST_H__C3470BE0_18C4_4CFF_BF28_57DE5870E9E2__INCLUDED_)
#define AFX_APPLERLIST_H__C3470BE0_18C4_4CFF_BF28_57DE5870E9E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ApplerList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CApplerList dialog

class CApplerList : public CDialog, public CADOView
{
// Construction
public:
	void SetCurrentApplerNumber(CString &number);
	BOOL ShowApplerList(CString &condition);
	BOOL ExportToWord(CString& file);
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	BOOL ShowApplerList();
	CApplerList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CApplerList)
	enum { IDD = IDD_APPLERLIST };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApplerList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CApplerList)
	virtual BOOL OnInitDialog();
	afx_msg void OnExporttoword();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitem();
	afx_msg void OnFindEmployee();
	afx_msg void OnQuit();
	afx_msg void OnAbout();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEdit();
	afx_msg void OnSearchRecord();
	afx_msg void OnAddnew();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SeachExpression;
	HACCEL m_SearchAccel;
	int m_CurSel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPLERLIST_H__C3470BE0_18C4_4CFF_BF28_57DE5870E9E2__INCLUDED_)
