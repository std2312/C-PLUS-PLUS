#if !defined(AFX_PROVIDEDLG_H__0F626F1D_CDC4_4DCF_B4F3_A85D1151DB13__INCLUDED_)
#define AFX_PROVIDEDLG_H__0F626F1D_CDC4_4DCF_B4F3_A85D1151DB13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Providedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg dialog

class CProvidedlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CProvidedlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProvidedlg)
	enum { IDD = IDD_PROVIDE_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CString	m_Gysbh;
	CString	m_Gysmc;
	CString	m_Gysjc;
	CString	m_Gysdz;
	CString	m_Lxr;
	CString	m_Gysdh;
	CString	m_Gyscz;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProvidedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProvidedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButsave();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROVIDEDLG_H__0F626F1D_CDC4_4DCF_B4F3_A85D1151DB13__INCLUDED_)
