// NoteManageDlg.h : header file
//

#if !defined(AFX_NOTEMANAGEDLG_H__349D30F7_7161_4903_BB11_A5A8D7F21533__INCLUDED_)
#define AFX_NOTEMANAGEDLG_H__349D30F7_7161_4903_BB11_A5A8D7F21533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoteManageDlg dialog

class CNoteManageDlg : public CDialog
{
// Construction
public:
	CNoteManageDlg(CWnd* pParent = NULL);	// standard constructor
	CToolBar   m_ToolBar;
	CImageList m_ImageList;
	virtual void OnOK();
// Dialog Data
	//{{AFX_DATA(CNoteManageDlg)
	enum { IDD = IDD_NOTEMANAGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoteManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNoteManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPhoneBook();
	afx_msg void OnOftenNote();
	afx_msg void OnSendNote();
	afx_msg void OnRecvNote();
	afx_msg void OnNoteSet();
	afx_msg void OnUser();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEMANAGEDLG_H__349D30F7_7161_4903_BB11_A5A8D7F21533__INCLUDED_)
