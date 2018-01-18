#if !defined(AFX_DEPOTBACKDLG_H__116567ED_60BB_46BB_90F3_621B2A7B1394__INCLUDED_)
#define AFX_DEPOTBACKDLG_H__116567ED_60BB_46BB_90F3_621B2A7B1394__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepotBackdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepotBackdlg dialog

class CDepotBackdlg : public CDialog
{
// Construction
public:
	CDepotBackdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepotBackdlg)
	enum { IDD = IDD_BDEPOT_DIALOG };
	CEdit	m_Thsl;
	CComboBox	m_Spjj;
	CComboBox	m_Spmc;
	CComboBox	m_Spbh;
	CDateTimeCtrl	m_Thsj;
	CComboBox	m_Gysmc;
	CComboBox	m_Gysbh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepotBackdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepotBackdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButsave();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnSelchangeCombo4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPOTBACKDLG_H__116567ED_60BB_46BB_90F3_621B2A7B1394__INCLUDED_)
