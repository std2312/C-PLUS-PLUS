#if !defined(AFX_HUMANREMOVEDLG_H__194C7392_30BB_4399_9AA5_D1D011EE7D6B__INCLUDED_)
#define AFX_HUMANREMOVEDLG_H__194C7392_30BB_4399_9AA5_D1D011EE7D6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HumanRemoveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHumanRemoveDlg dialog

class CHumanRemoveDlg : public CDialog, public CADOView
{
// Construction
public:
	BOOL ShowList(CString&seaExp);
	BOOL SetRow(int row, CString *strArray, int count);
	BOOL DeleteAllRows();
	BOOL ShowList();
	CHumanRemoveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHumanRemoveDlg)
	enum { IDD = IDD_HUMANREMOVE };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHumanRemoveDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHumanRemoveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelitem();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_CurSel;
	HACCEL m_hAccel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUMANREMOVEDLG_H__194C7392_30BB_4399_9AA5_D1D011EE7D6B__INCLUDED_)
