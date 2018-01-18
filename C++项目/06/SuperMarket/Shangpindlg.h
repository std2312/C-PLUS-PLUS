#if !defined(AFX_SHANGPINDLG_H__CDDF93EB_9621_458A_A91A_F8AB5D221BE4__INCLUDED_)
#define AFX_SHANGPINDLG_H__CDDF93EB_9621_458A_A91A_F8AB5D221BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shangpindlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShangpindlg dialog

class CShangpindlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CShangpindlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShangpindlg)
	enum { IDD = IDD_SHANGPIN_DIALOG };
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CListCtrl	m_Grid;
	CString	m_Spbh;
	CString	m_Spmc;
	CString	m_Spjm;
	CString	m_Splb;
	CString	m_Spdw;
	CString	m_Txm;
	double	m_Jhjg;
	double	m_Xsjg;
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShangpindlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShangpindlg)
	afx_msg void OnButadd();
	afx_msg void OnButmod();
	afx_msg void OnButsave();
	virtual BOOL OnInitDialog();
	afx_msg void OnButdel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHANGPINDLG_H__CDDF93EB_9621_458A_A91A_F8AB5D221BE4__INCLUDED_)
