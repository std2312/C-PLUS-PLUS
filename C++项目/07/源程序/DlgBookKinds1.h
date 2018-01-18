#if !defined(AFX_DLGBOOKKINDS1_H__4D528BEF_91D7_4C83_A84F_910C62638755__INCLUDED_)
#define AFX_DLGBOOKKINDS1_H__4D528BEF_91D7_4C83_A84F_910C62638755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookKinds1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBookKinds1 dialog

class CDlgBookKinds1 : public CDialog
{
// Construction
public:
	void DeleteBookKind();
	void UpdateBookKind();
	void AddBookKind();
	void LoadBookKinds();
	CDlgBookKinds1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookKinds1)
	enum { IDD = IDD_BOOK_KINDS1 };
	CListCtrl	m_list;
	CEdit	m_bookkind;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookKinds1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookKinds1)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDel();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKKINDS1_H__4D528BEF_91D7_4C83_A84F_910C62638755__INCLUDED_)
