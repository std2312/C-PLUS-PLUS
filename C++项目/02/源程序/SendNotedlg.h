#if !defined(AFX_SENDNOTEDLG_H__A951B636_A916_4B24_BC2D_B76231BEE467__INCLUDED_)
#define AFX_SENDNOTEDLG_H__A951B636_A916_4B24_BC2D_B76231BEE467__INCLUDED_
#include "BmpButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendNotedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendNotedlg dialog

class CSendNotedlg : public CDialog
{
// Construction
public:
	CSendNotedlg(CWnd* pParent = NULL);   // standard constructor
	virtual void OnOK();
// Dialog Data
	//{{AFX_DATA(CSendNotedlg)
	enum { IDD = IDD_SENDNOTE_DIALOG };
	CBmpButton	m_ButSend;
	CBmpButton	m_ButNote;
	CBmpButton	m_ButClear;
	CBmpButton	m_ButBook;
	CBmpButton	m_ButDel;
	CListCtrl	m_Grid;
	CString	m_Note;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendNotedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendNotedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButbook();
	afx_msg void OnButdel();
	afx_msg void OnButclear();
	afx_msg void OnButnote();
	afx_msg void OnButsend();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDNOTEDLG_H__A951B636_A916_4B24_BC2D_B76231BEE467__INCLUDED_)
