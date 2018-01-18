#if !defined(AFX_MONTHDLG_H__5545CD35_382E_4E66_89B3_5A85960D846F__INCLUDED_)
#define AFX_MONTHDLG_H__5545CD35_382E_4E66_89B3_5A85960D846F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Monthdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonthdlg dialog

class CMonthdlg : public CDialog
{
// Construction
public:
	CMonthdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMonthdlg)
	enum { IDD = IDD_MONTH_DIALOG };
	CListCtrl	m_Grid;
	CDateTimeCtrl	m_Month;
	CString	m_Money;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonthdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMonthdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONTHDLG_H__5545CD35_382E_4E66_89B3_5A85960D846F__INCLUDED_)
