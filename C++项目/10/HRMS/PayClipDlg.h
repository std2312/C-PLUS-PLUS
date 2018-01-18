#if !defined(AFX_PAYCLIPDLG_H__5A66E231_9BA9_4E88_B1B8_F036F3F5F93B__INCLUDED_)
#define AFX_PAYCLIPDLG_H__5A66E231_9BA9_4E88_B1B8_F036F3F5F93B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PayClipDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPayClipDlg dialog

class CPayClipDlg : public CDialog
{
// Construction
public:
	float GetRecoupSum(CString &name);
	void SetDlgItemFloat(UINT id, float f);
	BOOL SetWageDlg(CString &name);
	void SetEditable(BOOL is = FALSE);
	void InitModifyDlg();
	BOOL SaveModify();
	BOOL SetDlgContent();
	void SetDlgInfo(CString &name, int year, int month,float laborage, float bonus);
	double GetDlgItemFloat(UINT id);
	BOOL SavePaySlip();
	BOOL GetLastDate(SYSTEMTIME *sysTime);
	float DeductFunds(float hours, float per);
	float GetLaveHours(const CString& name, int year, int month);
	DWORD GetAffairLeave(const CString& name, int year, int month);
	DWORD GetHolidays(const CString& name, int year, int month);
	BOOL UpdateContent();
	DWORD GetSickLeaveCount(const CString &name, int year, int month);
	DWORD GetRecentLateCount(const CString &name, int year, int month);
	CPayClipDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPayClipDlg)
	enum { IDD = IDD_PAYSLIP };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPayClipDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPayClipDlg)
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSetfocusEdit2();
	afx_msg void OnKillfocusCombo3();
	afx_msg void OnKillfocusCombo4();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnSelchangeCombo4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	float m_Bonus;
	float m_Laborage;
	BOOL m_Editable;
	int m_Month;
	int m_year;
	CString m_Name;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYCLIPDLG_H__5A66E231_9BA9_4E88_B1B8_F036F3F5F93B__INCLUDED_)
