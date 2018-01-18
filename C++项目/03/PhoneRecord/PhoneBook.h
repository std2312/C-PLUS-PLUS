#if !defined(AFX_PHONEBOOK_H__18EA23D0_97A8_41AD_B2B3_92BE0CBE7D44__INCLUDED_)
#define AFX_PHONEBOOK_H__18EA23D0_97A8_41AD_B2B3_92BE0CBE7D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhoneBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhoneBook dialog

class CPhoneBook : public CDialog
{
// Construction
public:
	CPhoneBook(CWnd* pParent = NULL);   // standard constructor
	CString m_Num;
// Dialog Data
	//{{AFX_DATA(CPhoneBook)
	enum { IDD = IDD_PHONEBOOK_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPhoneBook)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONEBOOK_H__18EA23D0_97A8_41AD_B2B3_92BE0CBE7D44__INCLUDED_)
