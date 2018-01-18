#if !defined(AFX_SELLQUERYDLG_H__46102F9F_F1F7_48C8_9C31_3A6E7534E614__INCLUDED_)
#define AFX_SELLQUERYDLG_H__46102F9F_F1F7_48C8_9C31_3A6E7534E614__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sellquerydlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSellquerydlg dialog

class CSellquerydlg : public CDialog
{
// Construction
public:
	CSellquerydlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSellquerydlg)
	enum { IDD = IDD_SELLQ_DIALOG };
	CListCtrl	m_Grid;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSellquerydlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSellquerydlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButquery();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELLQUERYDLG_H__46102F9F_F1F7_48C8_9C31_3A6E7534E614__INCLUDED_)
