#if !defined(AFX_EXAMINFO_H__DEFA0F27_85C5_4C72_90CE_3B76579DF2C9__INCLUDED_)
#define AFX_EXAMINFO_H__DEFA0F27_85C5_4C72_90CE_3B76579DF2C9__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExamInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamInfo dialog

class CExamInfo : public CDialog
{
// Construction
public:
	void OnOK();
	CString Subject;
	int Sid;
	CString Question;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CExamInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExamInfo)
	enum { IDD = IDD_EXAMINFO };
	CComboBox	m_SubjectCombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMINFO_H__DEFA0F27_85C5_4C72_90CE_3B76579DF2C9__INCLUDED_)
