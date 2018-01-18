#if !defined(AFX_RESULTSELECT_H__0FDB8D5D_9115_4515_A78C_1C791D635344__INCLUDED_)
#define AFX_RESULTSELECT_H__0FDB8D5D_9115_4515_A78C_1C791D635344__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResultSelect dialog

class CResultSelect : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CResultSelect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResultSelect)
	enum { IDD = IDD_RESULTSELECT };
	CListCtrl	m_ResultList;
	CComboBox	m_Type;
	CString	m_Mark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResultSelect)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnDblclkResultlist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTSELECT_H__0FDB8D5D_9115_4515_A78C_1C791D635344__INCLUDED_)
