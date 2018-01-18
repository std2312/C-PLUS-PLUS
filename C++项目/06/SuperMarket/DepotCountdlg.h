#if !defined(AFX_DEPOTCOUNTDLG_H__FA36A3F5_35BA_40EC_B386_115388BA6E64__INCLUDED_)
#define AFX_DEPOTCOUNTDLG_H__FA36A3F5_35BA_40EC_B386_115388BA6E64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepotCountdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepotCountdlg dialog

class CDepotCountdlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CDepotCountdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepotCountdlg)
	enum { IDD = IDD_NDEPOT_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepotCountdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepotCountdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButquery();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPOTCOUNTDLG_H__FA36A3F5_35BA_40EC_B386_115388BA6E64__INCLUDED_)
