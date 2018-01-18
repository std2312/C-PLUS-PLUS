#if !defined(AFX_DLGINPUTQUERY3_H__8E360258_F8DD_4DE0_B488_43CD5404164B__INCLUDED_)
#define AFX_DLGINPUTQUERY3_H__8E360258_F8DD_4DE0_B488_43CD5404164B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInputQuery3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgInputQuery3 dialog

class CDlgInputQuery3 : public CDialog
{
// Construction
public:
	void Query();
	void OnOK();
	void Print();
	void CancelQuery();
	CDlgInputQuery3(CWnd* pParent = NULL);   // standard constructor
	CString arrays[7] ;
// Dialog Data
	//{{AFX_DATA(CDlgInputQuery3)
	enum { IDD = IDD_INPUT_QUERY3 };
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
	//{{AFX_VIRTUAL(CDlgInputQuery3)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInputQuery3)
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

#endif // !defined(AFX_DLGINPUTQUERY3_H__8E360258_F8DD_4DE0_B488_43CD5404164B__INCLUDED_)
