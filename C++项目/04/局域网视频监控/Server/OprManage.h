#if !defined(AFX_OPRMANAGE_H__08813F26_CC14_4F47_961F_9CDA7B47337D__INCLUDED_)
#define AFX_OPRMANAGE_H__08813F26_CC14_4F47_961F_9CDA7B47337D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OprManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COprManage dialog
#include "CustomListCtrl.h"
#include "CustomButton.h"
class COprManage : public CDialog
{
// Construction
public:
	void ClearText();
	void LoadOperatorInfo();
	COprManage(CWnd* pParent = NULL); 
	CImageList    m_ImageList;

// Dialog Data
	//{{AFX_DATA(COprManage)
	enum { IDD = IDD_OPRMANAGE_DIALOG };
	CCustomButton	m_BTUpdate;
	CCustomButton	m_BTDelete;
	CCustomButton	m_BTAdd;
	CEdit	m_ConfirmInfo;
	CEdit	m_User;
	CEdit	m_Pass;
	CCustomListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COprManage)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COprManage)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtAdd();
	afx_msg void OnBtdDelete();
	afx_msg void OnBtUpdate();
	afx_msg void OnGetdispinfoListinfo(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPRMANAGE_H__08813F26_CC14_4F47_961F_9CDA7B47337D__INCLUDED_)
