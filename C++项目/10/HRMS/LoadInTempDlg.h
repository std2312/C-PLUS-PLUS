#if !defined(AFX_LOADINTEMPDLG_H__F3C9D608_3C45_4716_AD92_5143D12D0CD1__INCLUDED_)
#define AFX_LOADINTEMPDLG_H__F3C9D608_3C45_4716_AD92_5143D12D0CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoadInTempDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoadInTempDlg dialog

class CLoadInTempDlg : public CDialog
{
// Construction
public:
	CString GetTemplateName();
	CString GetTemplateType();
	void SetTemplateType(CString type);
	CLoadInTempDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoadInTempDlg)
	enum { IDD = IDD_LOAD_IN_TEMPLATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadInTempDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadInTempDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_TmpName;
	CString m_TmpType;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADINTEMPDLG_H__F3C9D608_3C45_4716_AD92_5143D12D0CD1__INCLUDED_)
