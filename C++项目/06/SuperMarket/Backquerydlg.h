#if !defined(AFX_BACKQUERYDLG_H__37B653CF_DC77_4AF2_9623_9C64C4B8243E__INCLUDED_)
#define AFX_BACKQUERYDLG_H__37B653CF_DC77_4AF2_9623_9C64C4B8243E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Backquerydlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackquerydlg dialog

class CBackquerydlg : public CDialog
{
// Construction
public:
	CBackquerydlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBackquerydlg)
	enum { IDD = IDD_BACKQ_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackquerydlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBackquerydlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButquery();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKQUERYDLG_H__37B653CF_DC77_4AF2_9623_9C64C4B8243E__INCLUDED_)
