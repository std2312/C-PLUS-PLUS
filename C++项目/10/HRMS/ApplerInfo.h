#if !defined(AFX_APPLERINFO_H__4973D191_4B6E_40F3_8992_9B15905BE754__INCLUDED_)
#define AFX_APPLERINFO_H__4973D191_4B6E_40F3_8992_9B15905BE754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ApplerInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CApplerInfo dialog

class CApplerInfo : public CDialog
{
// Construction
public:
	BOOL SaveModify();
	void SetModifyModeDlg();
	void SetCurrentApplerNumber(CString &number);
	BOOL SetDlgContent(CString &number);
	BOOL SaveApplicantInfo();
	CApplerInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CApplerInfo)
	enum { IDD = IDD_APPLERINFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApplerInfo)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CApplerInfo)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_CurrentApplerNumber;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPLERINFO_H__4973D191_4B6E_40F3_8992_9B15905BE754__INCLUDED_)
