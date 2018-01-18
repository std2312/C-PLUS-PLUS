#if !defined(AFX_CONTROLFORM_H__F9B40D34_2EAF_41EE_B8CE_2CA73ADF7C5E__INCLUDED_)
#define AFX_CONTROLFORM_H__F9B40D34_2EAF_41EE_B8CE_2CA73ADF7C5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ControlForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControlForm dialog
#include "CaptureDlg.h"
class CControlForm : public CDialog
{
// Construction
public:
	CControlForm(CWnd* pParent = NULL);   // standard constructor

	CCaptureDlg* m_pMain;    //主窗口指针
	CEdit*       m_pEdit[8]; //控件数组
	CString      m_UserName;
	CString      m_LogPath;
// Dialog Data
	//{{AFX_DATA(CControlForm)
	enum { IDD = IDD_CONTROLFORM_DIALOG };
	CEdit	m_Setting;
	CComboBox	m_Port;
	CEdit	m_ByteNum;
	CEdit	m_Byte8;
	CEdit	m_Byte7;
	CEdit	m_Byte6;
	CEdit	m_Byte5;
	CEdit	m_Byte4;
	CEdit	m_Byte3;
	CEdit	m_Byte2;
	CEdit	m_Byte1;
	CComboBox	m_Actions;
	CEdit	m_ActionNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CControlForm)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeActions();
	afx_msg void OnPortset();
	afx_msg void OnCmdset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLFORM_H__F9B40D34_2EAF_41EE_B8CE_2CA73ADF7C5E__INCLUDED_)
