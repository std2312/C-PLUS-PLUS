#if !defined(AFX_DLGCONFIGM_H__2C4C46E7_CB79_4700_A338_2A6A73826A46__INCLUDED_)
#define AFX_DLGCONFIGM_H__2C4C46E7_CB79_4700_A338_2A6A73826A46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgConfigM.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CDlgConfigM dialog

class CDlgConfigM : public CDialog
{
// Construction
public:
	void EnumServers();
	
	CDlgConfigM(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgConfigM)
	enum { IDD = IDD_CONFIG };
	CEdit	password;
	CEdit	users;
	CEdit	database;
	CComboBox	server;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgConfigM)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgConfigM)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButton1();
	virtual void OnCancel();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONFIGM_H__2C4C46E7_CB79_4700_A338_2A6A73826A46__INCLUDED_)
