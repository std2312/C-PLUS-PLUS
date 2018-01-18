#if !defined(AFX_DLGBOOKPRICE2_H__67AF4CD8_91A8_4CCF_80F3_34CDCAEB1D31__INCLUDED_)
#define AFX_DLGBOOKPRICE2_H__67AF4CD8_91A8_4CCF_80F3_34CDCAEB1D31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookPrice2.h : header file
//
#include "KeyEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgBookPrice2 dialog

class CDlgBookPrice2 : public CDialog
{
// Construction
public:
	void CancelOperate();
	void BookFixPrice();
	CDlgBookPrice2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookPrice2)
	enum { IDD = IDD_BOOK_PRICE2 };
	CKeyEdit	m_sellprice;
	CComboBox	m_value;
	CButton	m_query;
	CComboBox	m_field;
	CListCtrl	m_list;
	CKeyEdit	m_barcode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookPrice2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookPrice2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeFields();
	afx_msg void OnQuery();
	afx_msg void OnDblclkDetaillist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKPRICE2_H__67AF4CD8_91A8_4CCF_80F3_34CDCAEB1D31__INCLUDED_)
