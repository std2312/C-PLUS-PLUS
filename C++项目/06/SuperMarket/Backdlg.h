#if !defined(AFX_BACKDLG_H__4976D492_F73B_45A3_B862_83E6A6D125CC__INCLUDED_)
#define AFX_BACKDLG_H__4976D492_F73B_45A3_B862_83E6A6D125CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Backdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackdlg dialog

class CBackdlg : public CDialog
{
// Construction
public:
	CBackdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBackdlg)
	enum { IDD = IDD_BACK_DIALOG };
	CComboBox	m_Xsje;
	CComboBox	m_Spmc;
	CComboBox	m_Spbh;
	CComboBox	m_Xsph;
	CDateTimeCtrl	m_Thrq;
	CString	m_Thph;
	CString	m_Czy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBackdlg)
	afx_msg void OnButadd();
	virtual BOOL OnInitDialog();
	afx_msg void OnButsave();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSelchangeCombo3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKDLG_H__4976D492_F73B_45A3_B862_83E6A6D125CC__INCLUDED_)
