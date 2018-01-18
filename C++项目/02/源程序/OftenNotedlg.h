#if !defined(AFX_OFTENNOTEDLG_H__5AECC988_AC63_46B9_8837_6E4C45CD371B__INCLUDED_)
#define AFX_OFTENNOTEDLG_H__5AECC988_AC63_46B9_8837_6E4C45CD371B__INCLUDED_
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OftenNotedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COftenNotedlg dialog

class COftenNotedlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	virtual void OnOK();
	COftenNotedlg(CWnd* pParent = NULL);   // standard constructor
	int m_ID;
// Dialog Data
	//{{AFX_DATA(COftenNotedlg)
	enum { IDD = IDD_OFTENNOTE_DIALOG };
	CBmpButton	m_ButDel;
	CBmpButton	m_ButMod;
	CBmpButton	m_ButAdd;
	CListCtrl	m_Grid;
	CString	m_Note;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COftenNotedlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COftenNotedlg)
	afx_msg void OnButadd();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OFTENNOTEDLG_H__5AECC988_AC63_46B9_8837_6E4C45CD371B__INCLUDED_)
