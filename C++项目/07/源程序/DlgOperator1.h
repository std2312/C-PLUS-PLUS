#if !defined(AFX_DLGOPERATOR1_H__5ABCE7D6_96BF_4445_B527_D50940FA4250__INCLUDED_)
#define AFX_DLGOPERATOR1_H__5ABCE7D6_96BF_4445_B527_D50940FA4250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOperator1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgOperator1 dialog

class CDlgOperator1 : public CDialog
{
// Construction
public:
	void DeleteOperator();
	bool InfoIsExist(LPTSTR name);
	void UpdateOperator();
	void ClearInterface();
	bool InfoIsNull();
	void AddOperator();
	void LoadOperatorInfo();
	CDlgOperator1(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CDlgOperator1)
	enum { IDD = IDD_OPERATOR1 };
	CEdit	m_password;
	CEdit	m_operator;
	CListCtrl	m_list;
	CComboBox	m_level;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOperator1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOperator1)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDel();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOPERATOR1_H__5ABCE7D6_96BF_4445_B527_D50940FA4250__INCLUDED_)
