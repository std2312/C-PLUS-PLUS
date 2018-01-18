#if !defined(AFX_MANUFACTUREDLG_H__0C3C365D_6FBB_4048_934C_DB9090BA0D74__INCLUDED_)
#define AFX_MANUFACTUREDLG_H__0C3C365D_6FBB_4048_934C_DB9090BA0D74__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManufactureDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManufactureDlg dialog

class CManufactureDlg : public CDialog
{
// Construction
public:
	void AddToList();
	CManufactureDlg(CWnd* pParent = NULL);   // standard constructor
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CManufactureDlg)
	enum { IDD = IDD_MANUFACTURE_DIALOG };
	CBaseButton	m_ButSave;
	CBaseButton	m_ButMod;
	CBaseButton	m_ButDel;
	CBaseButton	m_ButAdd;
	CListCtrl	m_List;
	CString	m_Name;
	CString	m_Intro;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManufactureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManufactureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButsave();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANUFACTUREDLG_H__0C3C365D_6FBB_4048_934C_DB9090BA0D74__INCLUDED_)
