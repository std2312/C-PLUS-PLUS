#if !defined(AFX_NEWNOTEDLG_H__0FC5C92F_2386_486C_93F2_67804F4F0814__INCLUDED_)
#define AFX_NEWNOTEDLG_H__0FC5C92F_2386_486C_93F2_67804F4F0814__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewNotedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewNotedlg dialog

class CNewNotedlg : public CDialog
{
// Construction
public:
	void AddToTable();
	CNewNotedlg(CWnd* pParent = NULL);   // standard constructor
	CString m_Phone;
	CString m_Note;
	CString m_Name;
// Dialog Data
	//{{AFX_DATA(CNewNotedlg)
	enum { IDD = IDD_NEWNOTE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewNotedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewNotedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWNOTEDLG_H__0FC5C92F_2386_486C_93F2_67804F4F0814__INCLUDED_)
