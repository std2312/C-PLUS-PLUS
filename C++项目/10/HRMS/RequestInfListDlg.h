#if !defined(AFX_REQUESTINFLISTDLG_H__10ED52CC_C3F3_46C0_A311_A338F37645C5__INCLUDED_)
#define AFX_REQUESTINFLISTDLG_H__10ED52CC_C3F3_46C0_A311_A338F37645C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RequestInfListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRequestInfListDlg dialog

class CRequestInfListDlg : public CDialog, public CADOView
{
// Construction
public:
	BOOL ShowRequestList(CString &seaExpr);
	BOOL UpdateTable();
	BOOL ExportToWord(CString &file);
	BOOL ShowRequestList();
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	CRequestInfListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRequestInfListDlg)
	enum { IDD = IDD_REQUESTLIST };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRequestInfListDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRequestInfListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnExporttoword();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitem();
	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnFindEmployee();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEdit();
	afx_msg void OnSearchRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HACCEL m_hAccel;
	int m_CurSel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQUESTINFLISTDLG_H__10ED52CC_C3F3_46C0_A311_A338F37645C5__INCLUDED_)
