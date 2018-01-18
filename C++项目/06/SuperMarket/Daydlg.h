#if !defined(AFX_DAYDLG_H__5F180CA3_3352_49E8_9567_AD56FD7DD071__INCLUDED_)
#define AFX_DAYDLG_H__5F180CA3_3352_49E8_9567_AD56FD7DD071__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Daydlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDaydlg dialog

class CDaydlg : public CDialog
{
// Construction
public:
	CDaydlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDaydlg)
	enum { IDD = IDD_DAY_DIALOG };
	CListCtrl	m_Grid;
	CDateTimeCtrl	m_Day;
	CString	m_Money;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDaydlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDaydlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAYDLG_H__5F180CA3_3352_49E8_9567_AD56FD7DD071__INCLUDED_)
