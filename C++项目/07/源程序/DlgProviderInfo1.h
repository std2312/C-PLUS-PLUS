#if !defined(AFX_DLGPROVIDERINFO1_H__415C2D54_091C_46AA_8F36_FEBF801FEEA1__INCLUDED_)
#define AFX_DLGPROVIDERINFO1_H__415C2D54_091C_46AA_8F36_FEBF801FEEA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgProviderInfo1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgProviderInfo1 dialog

class CDlgProviderInfo1 : public CDialog
{
// Construction
public:
	void UpdateProvider();
	void DeleteProvider();
	void ClearInterface();
	void AddProvider();
	bool InfoIsNull();
	CDlgProviderInfo1(CWnd* pParent = NULL);   // standard constructor
	void LoadProviderInfo();//加载供应商信息

// Dialog Data
	//{{AFX_DATA(CDlgProviderInfo1)
	enum { IDD = IDD_PROVIDER_INFO1 };
	CEdit	m_provider;
	CEdit	m_phone;
	CEdit	m_email;
	CEdit	m_corporation;
	CEdit	m_addr;
	CEdit	m_netaddr;
	CEdit	m_principal;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgProviderInfo1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgProviderInfo1)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCancel();
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROVIDERINFO1_H__415C2D54_091C_46AA_8F36_FEBF801FEEA1__INCLUDED_)
