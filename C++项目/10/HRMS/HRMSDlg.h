// HRMSDlg.h : header file
//

#if !defined(AFX_HRMSDLG_H__CBEFB943_D221_4053_AACC_EEA96AC2DB0B__INCLUDED_)
#define AFX_HRMSDLG_H__CBEFB943_D221_4053_AACC_EEA96AC2DB0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHRMSDlg dialog

class CHRMSDlg : public CDialog
{
// Construction
public:
	void NonLoading(BOOL isLoading = FALSE);

	CHRMSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHRMSDlg)
	enum { IDD = IDD_HRMS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHRMSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHRMSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileRecord();
	afx_msg void OnFileSearch();
	afx_msg void OnInsertdept();
	afx_msg void OnDeptDuty();
	afx_msg void OnHelp();
	afx_msg void OnAbout();
	afx_msg void OnAttendanceRecord();
	afx_msg void OnTimecardList();
	afx_msg void OnPay();
	afx_msg void OnPaylip();
	afx_msg void OnApplerfile();
	afx_msg void OnRequestEmployee();
	afx_msg void OnUserRegister();
	afx_msg void OnModiCode();
	afx_msg void OnExit();
	afx_msg void OnPortfolio();
	afx_msg void OnPortfolioList();
	afx_msg void OnExport();
	afx_msg void OnApplerlist();
	afx_msg void OnResetland();
	afx_msg void OnQuitland();
	afx_msg void OnReauestlist();
	afx_msg void OnAgreementlist();
	afx_msg void OnLaborage();
	afx_msg void OnHumanRedeploy();
	afx_msg void OnExamineApplicant();
	afx_msg void OnExamineList();
	afx_msg void OnLaborageRecord();
	afx_msg void OnLeaveitem();
	afx_msg void OnLeavelist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_CurUserName;
	CStatusBar m_StatusBar;
	CBitmap m_Background;
	CImageList m_ImageList;
	CToolBarCtrl m_ToolBar;
	CMenu m_Menu;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HRMSDLG_H__CBEFB943_D221_4053_AACC_EEA96AC2DB0B__INCLUDED_)
