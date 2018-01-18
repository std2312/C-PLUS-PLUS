#if !defined(AFX_DLGINPUTBACKQUERY3_H__76C631F1_E5BF_4F17_B2E6_ECAC51F7C33D__INCLUDED_)
#define AFX_DLGINPUTBACKQUERY3_H__76C631F1_E5BF_4F17_B2E6_ECAC51F7C33D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInputBackQuery3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgInputBackQuery3 dialog

class CDlgInputBackQuery3 : public CDialog
{
// Construction
public:
	void Query();
	void Print();
	void OnOK();
	void CancelQuery();
	CDlgInputBackQuery3(CWnd* pParent = NULL);   // standard constructor
	CString arrays[7] ;
// Dialog Data
	//{{AFX_DATA(CDlgInputBackQuery3)
	enum { IDD = IDD_INPUT_BACK_QUERY3 };
	CDateTimeCtrl	m_endtime;
	CListCtrl	m_list;
	CEdit	m_value;
	CDateTimeCtrl	m_strtime;
	CComboBox	m_fields;
	CButton	m_check2;
	CButton	m_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInputBackQuery3)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInputBackQuery3)
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

#endif // !defined(AFX_DLGINPUTBACKQUERY3_H__76C631F1_E5BF_4F17_B2E6_ECAC51F7C33D__INCLUDED_)
