#if !defined(AFX_TIMECARDDLG_H__008F63FA_A12B_4393_A7AE_786EA2FE77DC__INCLUDED_)
#define AFX_TIMECARDDLG_H__008F63FA_A12B_4393_A7AE_786EA2FE77DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeCardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeCardDlg dialog

class CTimeCardDlg : public CDialog
{
// Construction
public:
	CString GetLeaveItem(CString&num);
	static BOOL InitEmployeeList(CComboBox *pCom);
	DWORD GetAbsenceState();
	static	CString GetEmployIDByName(CString);
	BOOL SaveTimeCard();
	DWORD GetLeaveStyle();
	void IsAbsence(BOOL abs = FALSE);
	CTimeCardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeCardDlg)
	enum { IDD = IDD_TIMECARD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeCardDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRadio2();
	afx_msg void OnRadio1();
	afx_msg void OnAbout();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_IsAbsence;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECARDDLG_H__008F63FA_A12B_4393_A7AE_786EA2FE77DC__INCLUDED_)
