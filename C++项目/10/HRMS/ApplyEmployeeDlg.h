#if !defined(AFX_APPLYEMPLOYEEDLG_H__641B97F8_3F46_45D5_B078_1880ED58CDBE__INCLUDED_)
#define AFX_APPLYEMPLOYEEDLG_H__641B97F8_3F46_45D5_B078_1880ED58CDBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ApplyEmployeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CApplyEmployeeDlg dialog

class CApplyEmployeeDlg : public CDialog
{
// Construction
public:
	BOOL SaveModify();
	BOOL SetModifyMode();
	BOOL SetDlgContent(CString &applicationSerial);
	void SetApplicationSerial(CString &applicationSerial);
	BOOL RequestEmployee();
	BOOL CheckPrincipal(const CString& id);
	CApplyEmployeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CApplyEmployeeDlg)
	enum { IDD = IDD_APPLY_EMPLOYEE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApplyEmployeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CApplyEmployeeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo5();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_ApplicationSerial;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPLYEMPLOYEEDLG_H__641B97F8_3F46_45D5_B078_1880ED58CDBE__INCLUDED_)
