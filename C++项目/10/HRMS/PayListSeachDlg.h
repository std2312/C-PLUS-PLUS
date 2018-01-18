#if !defined(AFX_PAYLISTSEACHDLG_H__C7C3D017_1645_4E4A_AF0E_A20D7BC5FA18__INCLUDED_)
#define AFX_PAYLISTSEACHDLG_H__C7C3D017_1645_4E4A_AF0E_A20D7BC5FA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PayListSeachDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPayListSeachDlg dialog

class CPayListSeachDlg : public CDialog
{
// Construction
public:
	CString GetSeachExpression();
	CPayListSeachDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPayListSeachDlg)
	enum { IDD = IDD_PAYLIST_SEACH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPayListSeachDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPayListSeachDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_SearchExpression;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYLISTSEACHDLG_H__C7C3D017_1645_4E4A_AF0E_A20D7BC5FA18__INCLUDED_)
