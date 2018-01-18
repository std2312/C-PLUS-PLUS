#if !defined(AFX_DLGBOOKADJUST2_H__87C1168E_36B9_4E8B_BEDA_56D7C4EB483A__INCLUDED_)
#define AFX_DLGBOOKADJUST2_H__87C1168E_36B9_4E8B_BEDA_56D7C4EB483A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBookAdjust2.h : header file
//
#include "CustomGrid.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgBookAdjust2 dialog

class CDlgBookAdjust2 : public CDialog
{
// Construction
public:
	void AddOperate();
	void MoveFocus();
	void ShowListinfo();
	void LimitEdit();
	void ShowListInfo();
	void EditChange();
	bool DetailInfoIsNull();
	void DeleteCurRow();
	bool CurrentRowIsNull();
	void AddNewRow();
	void OnOK();
	void CancelOperate();
	void LoadCounterInfo();
	void LoadStorageInfo();
	CDlgBookAdjust2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgBookAdjust2)
	enum { IDD = IDD_BOOK_ADJUST2 };
	CListCtrl	m_auxilist;
	CComboBox	m_storage;
	CEdit	m_operator;
	CCustomGrid	m_list;
	CDateTimeCtrl	m_date;
	CComboBox	m_counter;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBookAdjust2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgBookAdjust2)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBOOKADJUST2_H__87C1168E_36B9_4E8B_BEDA_56D7C4EB483A__INCLUDED_)
