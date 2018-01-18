#if !defined(AFX_DLGDESKINFO1_H__86442305_2265_4526_A751_50A24DE685DC__INCLUDED_)
#define AFX_DLGDESKINFO1_H__86442305_2265_4526_A751_50A24DE685DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDeskInfo1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDeskInfo1 dialog

class CDlgDeskInfo1 : public CDialog
{
// Construction
public:
	void UpdateCounterInfo();
	void DeleteCounterInfo();
	void AddCounterInfo();
	void LoadCounterInfo();
	CDlgDeskInfo1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDeskInfo1)
	enum { IDD = IDD_DESK_INOF1 };
	CListCtrl	m_list;
	CEdit	m_counter;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDeskInfo1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDeskInfo1)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCancel();
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDESKINFO1_H__86442305_2265_4526_A751_50A24DE685DC__INCLUDED_)
