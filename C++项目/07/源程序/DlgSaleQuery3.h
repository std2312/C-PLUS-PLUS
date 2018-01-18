#if !defined(AFX_DLGSALEQUERY3_H__00268256_2B96_451B_973D_51F7E5EBC6F6__INCLUDED_)
#define AFX_DLGSALEQUERY3_H__00268256_2B96_451B_973D_51F7E5EBC6F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSaleQuery3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSaleQuery3 dialog

class CDlgSaleQuery3 : public CDialog
{
// Construction
public:
	void Print();
	void Query();
	void CancelQuery();
	CDlgSaleQuery3(CWnd* pParent = NULL);   // standard constructor
	CString arrays[6] ;
// Dialog Data
	//{{AFX_DATA(CDlgSaleQuery3)
	enum { IDD = IDD_SALE_QUERY3 };
	CEdit	m_value;
	CListCtrl	m_list;
	CDateTimeCtrl	m_endtime;
	CDateTimeCtrl	m_strtime;
	CComboBox	m_fields;
	CButton	m_check2;
	CButton	m_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSaleQuery3)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSaleQuery3)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void Oncheck();
	afx_msg void OnCancel();
	afx_msg void Onprint();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSALEQUERY3_H__00268256_2B96_451B_973D_51F7E5EBC6F6__INCLUDED_)
