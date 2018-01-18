// OnTheStageDlg.h : header file
//

#if !defined(AFX_ONTHESTAGEDLG_H__8C01A928_E775_436C_AD86_C9A480DCD3B1__INCLUDED_)
#define AFX_ONTHESTAGEDLG_H__8C01A928_E775_436C_AD86_C9A480DCD3B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COnTheStageDlg dialog

class COnTheStageDlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	void Print();
	COnTheStageDlg(CWnd* pParent = NULL);	// standard constructor
	int i;
	CString m_Sum;
	CFont font;
	int printx,printy;
	int screenx,screeny;
	double ratex,ratey;
	CFont pfont;
	CString str[100][7];
// Dialog Data
	//{{AFX_DATA(COnTheStageDlg)
	enum { IDD = IDD_ONTHESTAGE_DIALOG };
	CStatic	m_Zstatic;
	CEdit	m_Zl;
	CEdit	m_Sje;
	CEdit	m_Yje;
	CStatic	m_Date;
	CStatic	m_Time;
	CStatic	m_Tstatic;
	CStatic	m_Dstatic;
	CStatic	m_Title;
	CStatic	m_Sstatic;
	CStatic	m_Ystatic;
	CButton	m_Ok;
	CButton	m_Add;
	CListCtrl	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnTheStageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COnTheStageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonadd();
	afx_msg void OnChangeEdit2();
	afx_msg void OnButtonok();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONTHESTAGEDLG_H__8C01A928_E775_436C_AD86_C9A480DCD3B1__INCLUDED_)
