#if !defined(AFX_DLGBOOKINPUT2_H__D57CB2D7_14F3_4D10_90C0_03F3A0C45AAE__INCLUDED_)
#define AFX_DLGBOOKINPUT2_H__D57CB2D7_14F3_4D10_90C0_03F3A0C45AAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookInput2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBookInput2 dialog
#include "KeyEdit.h"
#include "CustomGrid.h"

class CDlgBookInput2 : public CDialog
{
// Construction
public:
	void InputCancel();
	void AddOperator();
	void ShowStorage();
	void ShowListInfo();
	void ShowListinfo();
	void MoveFocus();
	void LimitEdit();
	bool InputInfoIsNull();
	void EditChange();
	void DoEditKeyDown(UINT nChar,UINT CtrlID);
	bool DetailInfoIsNull();
	void DeleteCurRow();
	bool CurrentRowIsNull();
	float CalculateMoney();
	void AddNewRow();
	void LoadStorage();
	void LoadProvider();
	void SetEditColor(COLORREF Color);
	void OnOK();
	CDlgBookInput2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookInput2)
	enum { IDD = IDD_BOOK_INPUT2 };
	CCustomGrid	m_list;
	CEdit	m_summoney;
	CListBox	m_storagelist;
	CKeyEdit	m_rebate;
	CListBox	m_providerlist;
	CKeyEdit	m_paymoney;
	CKeyEdit	m_operator;
	CListCtrl	m_auxilist;

	CKeyEdit	m_factmoney;
	CDateTimeCtrl	m_date;
	CKeyEdit	m_provider;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookInput2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBookInput2)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeRebate();
	afx_msg void OnChangeSummoney();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkProviderlist();
	afx_msg void OnDblclkStoragelist();
	afx_msg void OnKillfocusList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusProviderlist();
	afx_msg void OnKillfocusStoragelist();
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKINPUT2_H__D57CB2D7_14F3_4D10_90C0_03F3A0C45AAE__INCLUDED_)
