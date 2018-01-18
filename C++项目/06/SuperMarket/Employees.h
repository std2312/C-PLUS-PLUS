#if !defined(AFX_EMPLOYEES_H__65C0538B_C473_4549_B819_B3589EBD623C__INCLUDED_)
#define AFX_EMPLOYEES_H__65C0538B_C473_4549_B819_B3589EBD623C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Employees.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmployees dialog

class CEmployees : public CDialog
{
// Construction
public:
	void AddToGrid();
	CEmployees(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmployees)
	enum { IDD = IDD_EMPLOYEES_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Ygxb;
	CComboBox	m_Ygzw;
	CComboBox	m_Combo4;
	CComboBox	m_Combo3;
	CString	m_Ygbh;
	CString	m_Ygxm;
	double	m_Ygxz;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployees)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployees)
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnButsave();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButmod();
	afx_msg void OnButdel();
	afx_msg void OnButquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEES_H__65C0538B_C473_4549_B819_B3589EBD623C__INCLUDED_)
