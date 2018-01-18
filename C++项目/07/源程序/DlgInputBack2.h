#if !defined(AFX_DLGINPUTBACK2_H__4927405C_2446_4914_A79D_0CC2F1802F6E__INCLUDED_)
#define AFX_DLGINPUTBACK2_H__4927405C_2446_4914_A79D_0CC2F1802F6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInputBack2.h : header file
//
#include "KeyEdit.h"
#include "CustomGrid.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgInputBack2 dialog

class CDlgInputBack2 : public CDialog
{
// Construction
public:
	void DoEditKeyDown(UINT nChar, UINT CtrlID);
	void AddOperate();
	void ShowStorage();
	void ShowListinfo();
	void ShowListInfo();
	void SetEditColor(COLORREF Color);
	void OnOK();
	void MoveFocus();
	void LoadStorage();
	void LoadProvider();
	void LimitEdit();
	bool InputInfoIsNull();
	void InputCancel();
	void EditChange();
	bool DetailInfoIsNull();
	void DeleteCurRow();
	bool CurrentRowIsNull();
	float CalculateMoney();
	void AddNewRow();
	CDlgInputBack2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgInputBack2)
	enum { IDD = IDD_INPUT_BACK2 };
	CKeyEdit	m_factmoney;
	CCustomGrid	m_list;
	CKeyEdit	m_summoney;
	CListBox	m_storagelist;
	CKeyEdit	m_rebate;
	CListBox	m_providerlist;
	CKeyEdit	m_provider;
	CKeyEdit	m_paymoney;
	CKeyEdit	m_operator;
	CListCtrl	m_auxilist;
	CDateTimeCtrl	m_date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInputBack2)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInputBack2)
	afx_msg void OnChangeRebate();
	afx_msg void OnChangeSummoney();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkProviderlist();
	afx_msg void OnDblclkStoragelist();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusStoragelist();
	afx_msg void OnAdd();
	afx_msg void OnCancel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINPUTBACK2_H__4927405C_2446_4914_A79D_0CC2F1802F6E__INCLUDED_)
