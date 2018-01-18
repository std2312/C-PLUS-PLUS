#if !defined(AFX_TEXTMANAGE_H__E993A67C_2800_476D_9D41_D64709D6AA60__INCLUDED_)
#define AFX_TEXTMANAGE_H__E993A67C_2800_476D_9D41_D64709D6AA60__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextManage dialog

class CTextManage : public CDialog
{
// Construction
public:
	CString Answer;
	CString Question;
	void AddToList(int Sid);
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	void AddToTree();
	CTextManage(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CTextManage)
	enum { IDD = IDD_TEXTMANAGE };
	CListCtrl	m_TextList;
	CTreeCtrl	m_TextTree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTextManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddsubject();
	afx_msg void OnAddtest();
	afx_msg void OnSelchangedTextTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDel();
	afx_msg void OnChange();
	afx_msg void OnDelsubject();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTMANAGE_H__E993A67C_2800_476D_9D41_D64709D6AA60__INCLUDED_)
