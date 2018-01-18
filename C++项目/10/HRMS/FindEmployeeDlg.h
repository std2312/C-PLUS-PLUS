#if !defined(AFX_FINDEMPLOYEEDLG_H__7238E815_1818_402D_8C81_803BDCFB5C88__INCLUDED_)
#define AFX_FINDEMPLOYEEDLG_H__7238E815_1818_402D_8C81_803BDCFB5C88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindEmployeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindEmployeeDlg dialog

class CFindEmployeeDlg : public CDialog
{
// Construction
public:
	CFindEmployeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindEmployeeDlg)
	enum { IDD = IDD_FIND_EMPLOYEE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindEmployeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindEmployeeDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDEMPLOYEEDLG_H__7238E815_1818_402D_8C81_803BDCFB5C88__INCLUDED_)
