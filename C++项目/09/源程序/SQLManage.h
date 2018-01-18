#if !defined(AFX_SQLMANAGE_H__9A23D8A2_5E76_4070_AB78_C133074E59E9__INCLUDED_)
#define AFX_SQLMANAGE_H__9A23D8A2_5E76_4070_AB78_C133074E59E9__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SQLManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSQLManage dialog

class CSQLManage : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	CSQLManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSQLManage)
	enum { IDD = IDD_SQLMANAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQLManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSQLManage)
	afx_msg void OnSqlnew();
	afx_msg void OnSqlcopy();
	afx_msg void OnSqlreturn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLMANAGE_H__9A23D8A2_5E76_4070_AB78_C133074E59E9__INCLUDED_)
