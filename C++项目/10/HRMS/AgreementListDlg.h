#if !defined(AFX_AGREEMENTLISTDLG_H__B3B6A689_10B2_41CF_93F7_49EAF0EDB6FB__INCLUDED_)
#define AFX_AGREEMENTLISTDLG_H__B3B6A689_10B2_41CF_93F7_49EAF0EDB6FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AgreementListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAgreementListDlg dialog

class CAgreementListDlg : public CDialog, CADOView
{
// Construction
public:
	BOOL ShowList();
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	CAgreementListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAgreementListDlg)
	enum { IDD = IDD_AGREEMENT_LIST };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAgreementListDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAgreementListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFindEmployee();
	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnSearchRecord();
	afx_msg void OnDelitem();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HACCEL m_hAccel;
	int m_CurSel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGREEMENTLISTDLG_H__B3B6A689_10B2_41CF_93F7_49EAF0EDB6FB__INCLUDED_)
