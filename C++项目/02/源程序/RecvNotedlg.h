#if !defined(AFX_RECVNOTEDLG_H__E1012E54_0C53_4EFC_9A75_FA5C35721826__INCLUDED_)
#define AFX_RECVNOTEDLG_H__E1012E54_0C53_4EFC_9A75_FA5C35721826__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecvNotedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecvNotedlg dialog

class CRecvNotedlg : public CDialog
{
// Construction
public:
	CRecvNotedlg(CWnd* pParent = NULL);   // standard constructor
	virtual void OnOK();
// Dialog Data
	//{{AFX_DATA(CRecvNotedlg)
	enum { IDD = IDD_RECVNOTE_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecvNotedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRecvNotedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECVNOTEDLG_H__E1012E54_0C53_4EFC_9A75_FA5C35721826__INCLUDED_)
