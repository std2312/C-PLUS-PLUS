#if !defined(AFX_DEPTINFODLG_H__800D2391_00E7_4DE4_AA69_3F9D307C8D03__INCLUDED_)
#define AFX_DEPTINFODLG_H__800D2391_00E7_4DE4_AA69_3F9D307C8D03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptInfoDlg dialog

class CDeptInfoDlg : public CDialog, CADOView
{
// Construction
public:
	BOOL SaveModify(CString name);
	BOOL ShowDeptInfo(CString name);
	void SetDeptName(CString name);
	void SetEditable(BOOL isModify = FALSE);
	BOOL ShowDutyList();
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString *strArray, int count);
	DWORD GetCurNum();
	void SetEnlarge(BOOL isEnlarge = TRUE);
	CDeptInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeptInfoDlg)
	enum { IDD = IDD_DEPT_INFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptInfoDlg)
	afx_msg void OnDutylist();
	virtual BOOL OnInitDialog();
	afx_msg void OnAppend();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnSelchangeList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_DeptName;
	BOOL m_IsModify;
	int m_CurSelItem;
	long m_EnlargeWidth;
	BOOL m_Enlarge;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTINFODLG_H__800D2391_00E7_4DE4_AA69_3F9D307C8D03__INCLUDED_)
