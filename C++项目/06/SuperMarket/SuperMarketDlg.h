// SuperMarketDlg.h : header file
//

#if !defined(AFX_SUPERMARKETDLG_H__9224F808_3263_4DB7_AB5A_F94B412479A2__INCLUDED_)
#define AFX_SUPERMARKETDLG_H__9224F808_3263_4DB7_AB5A_F94B412479A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSuperMarketDlg dialog

class CSuperMarketDlg : public CDialog
{
// Construction
public:
	CSuperMarketDlg(CWnd* pParent = NULL);	// standard constructor
	CToolBar   m_ToolBar;
	CImageList m_ImageList;

// Dialog Data
	//{{AFX_DATA(CSuperMarketDlg)
	enum { IDD = IDD_SUPERMARKET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperMarketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSuperMarketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShangp();
	afx_msg void OnSellq();
	afx_msg void OnDepot();
	afx_msg void OnNdepot();
	afx_msg void OnDay();
	afx_msg void OnUser();
	afx_msg void OnMenuShangp();
	afx_msg void OnMenuEmp();
	afx_msg void OnMenuProvide();
	afx_msg void OnMenuBack();
	afx_msg void OnMenuSellq();
	afx_msg void OnMenuBackq();
	afx_msg void OnMenuDepot();
	afx_msg void OnMenuNdepot();
	afx_msg void OnMenuDay();
	afx_msg void OnMenuMonth();
	afx_msg void OnMenuUser();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuBdepot();
	afx_msg void OnMenuBdepotq();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPERMARKETDLG_H__9224F808_3263_4DB7_AB5A_F94B412479A2__INCLUDED_)
