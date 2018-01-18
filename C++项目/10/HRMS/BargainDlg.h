#if !defined(AFX_BARGAINDLG_H__8A76E4E3_62E7_4858_9198_B5356E720809__INCLUDED_)
#define AFX_BARGAINDLG_H__8A76E4E3_62E7_4858_9198_B5356E720809__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BargainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBargainDlg dialog

class CBargainDlg : public CDialog
{
// Construction
public:
	BOOL UpdataState();
	BOOL InvalidateBargain(CString num, DWORD state);
	BOOL ShowBargain(CString id);
	void DisableBargain();
	void SetEdiable(BOOL editable = TRUE);
	BOOL SaveTemplate(CString type, CString name);
	BOOL SaveBargain();
	CBargainDlg(CString name);
	void SetEmployName(CString name);
	CBargainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBargainDlg)
	enum { IDD = IDD_EMPLOYEE_BARGAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBargainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBargainDlg)
	afx_msg void OnBargainSave();
	afx_msg void OnLoadBargainItem();
	virtual BOOL OnInitDialog();
	afx_msg void OnOpen();
	afx_msg void OnLoadOut();
	afx_msg void OnLoadIn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_Available;
	BOOL m_IsEditable;
	CString m_EmployeeIdentifier;
	CString m_EmployeeName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARGAINDLG_H__8A76E4E3_62E7_4858_9198_B5356E720809__INCLUDED_)
