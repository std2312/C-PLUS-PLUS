#if !defined(AFX_LOGIN_H__CCE9319C_9D1C_454B_8EA6_F55518A73C56__INCLUDED_)
#define AFX_LOGIN_H__CCE9319C_9D1C_454B_8EA6_F55518A73C56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

class CLogin : public CDialog
{
// Construction
public:
	CLogin(CWnd* pParent = NULL);   // standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr  m_pRecordset;
	int m_Time;
// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_LOGIN_DIALOG };
	CButton	m_OK;
	CButton	m_Cancel;
	CString	m_Name;
	CString	m_PassWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__CCE9319C_9D1C_454B_8EA6_F55518A73C56__INCLUDED_)
