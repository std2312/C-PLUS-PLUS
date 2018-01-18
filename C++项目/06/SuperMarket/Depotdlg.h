#if !defined(AFX_DEPOTDLG_H__B9755690_1D52_403B_A81A_BC293050068E__INCLUDED_)
#define AFX_DEPOTDLG_H__B9755690_1D52_403B_A81A_BC293050068E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Depotdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepotdlg dialog

class CDepotdlg : public CDialog
{
// Construction
public:
	CDepotdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepotdlg)
	enum { IDD = IDD_DEPOT_DIALOG };
	CEdit	m_Jhsl;
	CComboBox	m_Spjj;
	CComboBox	m_Spmc;
	CComboBox	m_Spbh;
	CDateTimeCtrl	m_Jhsj;
	CComboBox	m_Gysmc;
	CComboBox	m_Gysbh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepotdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepotdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnButsave();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnSelchangeCombo4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPOTDLG_H__B9755690_1D52_403B_A81A_BC293050068E__INCLUDED_)
