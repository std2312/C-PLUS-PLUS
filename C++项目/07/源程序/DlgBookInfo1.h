#if !defined(AFX_DLGBOOKINFO1_H__C5DD3F10_875D_463E_A59B_63C57DC4D765__INCLUDED_)
#define AFX_DLGBOOKINFO1_H__C5DD3F10_875D_463E_A59B_63C57DC4D765__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookInfo1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBookInfo1 dialog

class CDlgBookInfo1 : public CDialog
{
// Construction
public:
	void DeleteBookInfo();
	void UpdateBookInfo();
	void AddBookInfo();
	bool BarcodeIsExist(LPTSTR barcode);
	void LoadBookInfo();
	bool InfoIsNull();
	void ClearInterface();
	void AddBookkinds();
	virtual void OnCancel();
	virtual void OnOK();
	CDlgBookInfo1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookInfo1)
	enum { IDD = IDD_BOOK_INFO1 };
	CComboBox	m_kinds;
	CEdit	m_shortcode;
	CEdit	m_memo;
	CEdit	m_barcode;
	CListCtrl	m_list;
	CEdit	m_public;
	CEdit	m_price;
	CEdit	m_author;
	CEdit	m_bookname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookInfo1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookInfo1)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKINFO1_H__C5DD3F10_875D_463E_A59B_63C57DC4D765__INCLUDED_)
