#if !defined(AFX_REGISTER_H__98177865_561A_4EFC_A917_38B543FC5AD1__INCLUDED_)
#define AFX_REGISTER_H__98177865_561A_4EFC_A917_38B543FC5AD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Register.h : header file
//
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog

class CRegister : public CDialog
{
// Construction
public:
	CRegister(CWnd* pParent = NULL);
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegister)
	enum { IDD = IDD_REGISTER };
	CStatic	m_TiShiStatic;
	CComboBox	m_QuestionCombo;
	UINT	m_Age;
	CString	m_Answer;
	CString	m_Passwd;
	CString	m_PasswdRepeat;
	UINT	m_Phone;
	CString	m_RealName;
	CString	m_UserName;
	int	radio;
	CString	m_IDcard;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegister)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegister)
	afx_msg void OnReg();
	afx_msg void OnSexmale();
	afx_msg void OnSexfemale();
	afx_msg void OnCheckname();
	afx_msg void OnChangeUsername();
	afx_msg void OnReset();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__98177865_561A_4EFC_A917_38B543FC5AD1__INCLUDED_)
