#if !defined(AFX_DLGBOOKSALE2_H__E7020F0A_0C63_4577_9140_017F0E9BA487__INCLUDED_)
#define AFX_DLGBOOKSALE2_H__E7020F0A_0C63_4577_9140_017F0E9BA487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookSale2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBookSale2 dialog
#include "KeyEdit.h"

class CDlgBookSale2 : public CDialog
{
// Construction
public:
	void AddOperate();
	bool ListInfoIsNull();
	bool HeaderInfoIsNull();
	void DeleteListData();
	float CalculateMoney();
	void AddDataToList();
	void OnOK();
	void LoadCounterInfo();
	void CancelOperate();
	CDlgBookSale2(CWnd* pParent = NULL);   // standard constructor
	bool changed;
// Dialog Data
	//{{AFX_DATA(CDlgBookSale2)
	enum { IDD = IDD_BOOK_SALE2 };
	CKeyEdit	m_bookrebate;
	CKeyEdit	m_summoney;
	CKeyEdit	m_sellprice;
	CKeyEdit	m_rebate;
	CKeyEdit	m_paymoney;
	CKeyEdit	m_operator;
	CKeyEdit	m_booknum;
	CListCtrl	m_list;
	CKeyEdit	m_factmoney;
	CDateTimeCtrl	m_date;
	CKeyEdit	m_customer;
	CComboBox	m_counter;
	CKeyEdit	m_bookname;
	CKeyEdit	m_bookconcern;
	CKeyEdit	m_barcode;
	CKeyEdit	m_author;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookSale2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookSale2)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeAuthor();
	afx_msg void OnChangeBarcode();
	afx_msg void OnChangeRebate();
	afx_msg void OnChangeSummoney();
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKSALE2_H__E7020F0A_0C63_4577_9140_017F0E9BA487__INCLUDED_)
