#if !defined(AFX_PRINTPREVIEWDLG_H__433B8919_5A6C_4ACE_9810_B7C8EEFB1A90__INCLUDED_)
#define AFX_PRINTPREVIEWDLG_H__433B8919_5A6C_4ACE_9810_B7C8EEFB1A90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintPreviewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintPreviewDlg dialog

class CPrintPreviewDlg : public CDialog
{
// Construction
public:
	BOOL ShowListView(CDC *dc);
	CPrintPreviewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintPreviewDlg)
	enum { IDD = IDD_PRINTER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintPreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintPreviewDlg)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTPREVIEWDLG_H__433B8919_5A6C_4ACE_9810_B7C8EEFB1A90__INCLUDED_)
