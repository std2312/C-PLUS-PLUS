#if !defined(AFX_USERDLG_H__A1945941_D629_4F31_BC0D_6AD6B116F9E4__INCLUDED_)
#define AFX_USERDLG_H__A1945941_D629_4F31_BC0D_6AD6B116F9E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Userdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserdlg dialog

class CUserdlg : public CDialog
{
// Construction
public:
	void AddToList();
	CUserdlg(CWnd* pParent = NULL);   // standard constructor
	CImageList     m_ImageList;
	CString        m_oName;
// Dialog Data
	//{{AFX_DATA(CUserdlg)
	enum { IDD = IDD_USER_DIALOG };
	CListCtrl	m_List;
	CComboBox	m_Combo;
	CString	m_Name;
	CString	m_PassWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__A1945941_D629_4F31_BC0D_6AD6B116F9E4__INCLUDED_)
