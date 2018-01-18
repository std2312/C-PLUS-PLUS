#if !defined(AFX_LEAVELIST_H__2069753D_05A3_4C29_93C4_A0F7C52916AF__INCLUDED_)
#define AFX_LEAVELIST_H__2069753D_05A3_4C29_93C4_A0F7C52916AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeaveList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeaveList dialog

class CLeaveList : public CDialog, public CADOView
{
// Construction
public:
	void ExportToWord(CString&file);
	BOOL DeleteItem();
	BOOL ShowList(CString& num, int year, int month);
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	BOOL InitMonthComboBox(CString &num, int year);
	BOOL InitYearComboBox(CString&num);
	BOOL UpdateDialog();
	CLeaveList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeaveList)
	enum { IDD = IDD_LEAVELIST };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeaveList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeaveList)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSetfocusCombo5();
	afx_msg void OnKillfocusCombo1();
	afx_msg void OnSetfocusCombo6();
	afx_msg void OnSelchangeCombo5();
	afx_msg void OnSelchangeCombo6();
	afx_msg void OnKillfocusCombo5();
	afx_msg void OnDelitem();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_CurSel;
	HACCEL m_hDelAccel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAVELIST_H__2069753D_05A3_4C29_93C4_A0F7C52916AF__INCLUDED_)
