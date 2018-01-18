#if !defined(AFX_DLGSTOREINFO1_H__DD356691_2BC9_418D_8534_31A0FA7E95E5__INCLUDED_)
#define AFX_DLGSTOREINFO1_H__DD356691_2BC9_418D_8534_31A0FA7E95E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgStoreInfo1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgStoreInfo1 dialog

class CDlgStoreInfo1 : public CDialog
{
// Construction
public:
	void UpdateStorageInfo();
	void DeleteStorageInfo();
	void AddStorageInfo();
	void LoadStorageInfo();
	void OnOK();
	CDlgStoreInfo1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgStoreInfo1)
	enum { IDD = IDD_STORE_INFO1 };
	CListCtrl	m_list;
	CEdit	m_storage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgStoreInfo1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgStoreInfo1)
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

#endif // !defined(AFX_DLGSTOREINFO1_H__DD356691_2BC9_418D_8534_31A0FA7E95E5__INCLUDED_)
