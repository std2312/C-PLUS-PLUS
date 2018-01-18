#if !defined(AFX_USERREGDLG_H__E129C648_B5D8_4C10_BD95_76941475CE7F__INCLUDED_)
#define AFX_USERREGDLG_H__E129C648_B5D8_4C10_BD95_76941475CE7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserRegDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserRegDlg dialog

class CUserRegDlg : public CDialog
{
// Construction
public:
	static 	BOOL CheckUser(CString &name, CString& dept, CString& duty);
	BOOL ModiCode(CString &regName);
	BOOL CheckRegName(CString& regName);
	BOOL SaveUserInfo(CString &name);
	BOOL InitUserInfo(const CString& name);
	BOOL InitCodeDlg();
	void SetUserName(CString& name);
	void SetModiCodeDlg(BOOL isCode = TRUE);
	CUserRegDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserRegDlg)
	enum { IDD = IDD_REGISTER_USER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserRegDlg)
	afx_msg void OnCheckUserName();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_IsModiCode;
	CString m_UserName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERREGDLG_H__E129C648_B5D8_4C10_BD95_76941475CE7F__INCLUDED_)
