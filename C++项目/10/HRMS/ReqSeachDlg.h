#if !defined(AFX_REQSEACHDLG_H__636A5B9E_5453_40F7_8C4C_F28E4A4746AA__INCLUDED_)
#define AFX_REQSEACHDLG_H__636A5B9E_5453_40F7_8C4C_F28E4A4746AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReqSeachDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReqSeachDlg dialog

class CReqSeachDlg : public CDialog
{
// Construction
public:
	CString GetSearchExpression();
	CString m_SearchExpression;
	CReqSeachDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReqSeachDlg)
	enum { IDD = IDD_REQ_CHK_SEA };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReqSeachDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReqSeachDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQSEACHDLG_H__636A5B9E_5453_40F7_8C4C_F28E4A4746AA__INCLUDED_)
