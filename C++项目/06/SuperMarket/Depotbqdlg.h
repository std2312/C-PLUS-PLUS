#if !defined(AFX_DEPOTBQDLG_H__218CBA98_1741_4C9F_B6E9_F27E8374357F__INCLUDED_)
#define AFX_DEPOTBQDLG_H__218CBA98_1741_4C9F_B6E9_F27E8374357F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Depotbqdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepotbqdlg dialog

class CDepotbqdlg : public CDialog
{
// Construction
public:
	CDepotbqdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepotbqdlg)
	enum { IDD = IDD_BDEPOTQ_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepotbqdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepotbqdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButquery();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPOTBQDLG_H__218CBA98_1741_4C9F_B6E9_F27E8374357F__INCLUDED_)
