#if !defined(AFX_DLGSALEBACK2_H__7CBED37D_8A1E_44C3_8AC6_C93E1B9E1368__INCLUDED_)
#define AFX_DLGSALEBACK2_H__7CBED37D_8A1E_44C3_8AC6_C93E1B9E1368__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSaleBack2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSaleBack2 dialog
#include "KeyEdit.h"
class CDlgSaleBack2 : public CDialog
{
// Construction
public:
	void OnOK();
	void LoadCounterInfo();
	bool ListInfoIsNull();
	bool HeaderInfoIsNull();
	void DeleteListData();
	void CancelOperate();
	float CalculateMoney();
	void AddOperate();
	void AddDataToList();
	CDlgSaleBack2(CWnd* pParent = NULL);   // standard constructor
	bool changed;
// Dialog Data
	//{{AFX_DATA(CDlgSaleBack2)
	enum { IDD = IDD_SALE_BACK2 };
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
	CKeyEdit	m_bookrebate;
	CKeyEdit	m_bookname;
	CKeyEdit	m_barcode;
	CKeyEdit	m_author;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSaleBack2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSaleBack2)
	afx_msg void OnChangeBarcode();
	afx_msg void OnChangeRebate();
	afx_msg void OnChangeSummoney();
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSALEBACK2_H__7CBED37D_8A1E_44C3_8AC6_C93E1B9E1368__INCLUDED_)
