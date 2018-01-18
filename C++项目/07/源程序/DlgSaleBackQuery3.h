#if !defined(AFX_DLGSALEBACKQUERY3_H__1319B7B0_7821_4633_88AA_649D89668A5D__INCLUDED_)
#define AFX_DLGSALEBACKQUERY3_H__1319B7B0_7821_4633_88AA_649D89668A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSaleBackQuery3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSaleBackQuery3 dialog

class CDlgSaleBackQuery3 : public CDialog
{
// Construction
public:
	void Query();
	void Print();
	void CancelQuery();
	CDlgSaleBackQuery3(CWnd* pParent = NULL);   // standard constructor
	CString arrays[6] ;
// Dialog Data
	//{{AFX_DATA(CDlgSaleBackQuery3)
	enum { IDD = IDD_SALE_BACK_QUERY3 };
	CListCtrl	m_list;
	CEdit	m_value;
	CDateTimeCtrl	m_endtime;
	CDateTimeCtrl	m_strtime;
	CComboBox	m_fields;
	CButton	m_check2;
	CButton	m_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSaleBackQuery3)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSaleBackQuery3)
	virtual BOOL OnInitDialog();
	afx_msg void Oncheck();
	afx_msg void OnCancel();
	afx_msg void Onprint();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSALEBACKQUERY3_H__1319B7B0_7821_4633_88AA_649D89668A5D__INCLUDED_)
