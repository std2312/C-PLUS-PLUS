#if !defined(AFX_EMPLOYEEDLG_H__2BFACE18_39C3_4230_A0C3_37AC24EA2D86__INCLUDED_)
#define AFX_EMPLOYEEDLG_H__2BFACE18_39C3_4230_A0C3_37AC24EA2D86__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmployeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg dialog

class CEmployeeDlg : public CDialog
{
// Construction
public:
	void Clear();
	void AddToList();
	CEmployeeDlg(CWnd* pParent = NULL);   // standard constructor
	CImageList m_ImageList;
	int        num;
// Dialog Data
	//{{AFX_DATA(CEmployeeDlg)
	enum { IDD = IDD_EMPLOYEES_DIALOG };
	CBaseButton	m_ButSave;
	CBaseButton	m_ButMod;
	CBaseButton	m_ButDel;
	CBaseButton	m_ButAdd;
	CComboBox	m_Sex;
	CListCtrl	m_List;
	CString	m_Id;
	CString	m_Name;
	CString	m_UserName;
	CString	m_Password;
	CString	m_Culture;
	CString	m_IdCard;
	CString	m_Phone;
	CString	m_Remark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployeeDlg)
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

#endif // !defined(AFX_EMPLOYEEDLG_H__2BFACE18_39C3_4230_A0C3_37AC24EA2D86__INCLUDED_)
