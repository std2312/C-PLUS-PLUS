#if !defined(AFX_NOTEDLG_H__484AC034_8450_4932_98B3_209DC42392F4__INCLUDED_)
#define AFX_NOTEDLG_H__484AC034_8450_4932_98B3_209DC42392F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Notedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotedlg dialog

class CNotedlg : public CDialog
{
// Construction
public:
	CString m_Note;
	CNotedlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNotedlg)
	enum { IDD = IDD_NOTE_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNotedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEDLG_H__484AC034_8450_4932_98B3_209DC42392F4__INCLUDED_)
