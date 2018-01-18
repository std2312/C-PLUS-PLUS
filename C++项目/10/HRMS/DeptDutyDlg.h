#if !defined(AFX_DEPTDUTYDLG_H__0386273F_FAE4_48F1_9B50_57264822594D__INCLUDED_)
#define AFX_DEPTDUTYDLG_H__0386273F_FAE4_48F1_9B50_57264822594D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptDutyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptDutyDlg dialog

class CDeptDutyDlg : public CDialog, CADOView
{
// Construction
public:
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	CDeptDutyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeptDutyDlg)
	enum { IDD = IDD_DEPT_DUTY_INFO };
	CListBox	m_DutyList;
	CComboBox	m_Dept;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptDutyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptDutyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnEditdeptinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTDUTYDLG_H__0386273F_FAE4_48F1_9B50_57264822594D__INCLUDED_)
