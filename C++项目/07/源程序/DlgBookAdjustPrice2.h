#if !defined(AFX_DLGBOOKADJUSTPRICE2_H__0F5AE1ED_410A_4CBD_9F93_6B607E34AD3B__INCLUDED_)
#define AFX_DLGBOOKADJUSTPRICE2_H__0F5AE1ED_410A_4CBD_9F93_6B607E34AD3B__INCLUDED_
#include "KeyEdit.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookAdjustPrice2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBookAdjustPrice2 dialog

class CDlgBookAdjustPrice2 : public CDialog
{
// Construction
public:
	void BookAdjustPrice();
	void CancelOperate();
	void Query();
	CDlgBookAdjustPrice2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookAdjustPrice2)
	enum { IDD = IDD_BOOK_ADJUST_PRICE2 };
	CComboBox	m_value;
	CKeyEdit	m_sellprice;
	CButton	m_query;
	CComboBox	m_field;
	CListCtrl	m_list;
	CKeyEdit	m_barcode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookAdjustPrice2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookAdjustPrice2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeFields();
	afx_msg void OnQuery();
	afx_msg void OnClickDetaillist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKADJUSTPRICE2_H__0F5AE1ED_410A_4CBD_9F93_6B607E34AD3B__INCLUDED_)
