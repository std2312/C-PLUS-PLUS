#if !defined(AFX_SYSSETTING_H__CB814267_B1E4_40C7_912B_0C56D0E1A34D__INCLUDED_)
#define AFX_SYSSETTING_H__CB814267_B1E4_40C7_912B_0C56D0E1A34D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SysSetting.h : header file
//
#include "CustomButton.h"
/////////////////////////////////////////////////////////////////////////////
// CSysSetting dialog
class CSysSetting : public CDialog
{
// Construction
public:
	CSysSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSysSetting)
	enum { IDD = IDD_SYSSETTING_DIALOG };
	CCustomButton	m_BTConfirm;
	CCustomButton	m_BTCancel;
	CIPAddressCtrl	m_IP;
	//}}AFX_DATA


	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSysSetting)
	virtual void OnOK();
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSSETTING_H__CB814267_B1E4_40C7_912B_0C56D0E1A34D__INCLUDED_)
