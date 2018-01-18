#if !defined(AFX_PANEL_H__A2DF0530_DC5C_4A75_816F_F4587840F738__INCLUDED_)
#define AFX_PANEL_H__A2DF0530_DC5C_4A75_816F_F4587840F738__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Panel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPanel dialog
#include "PreView.h"

class CPanel : public CDialog
{
//Variable of CPanel
public:
	CPreView * m_pList;    //预览窗口
	UINT       m_Num;      //记录预览窗口的数量
	UINT       m_UnitNum;  //m_Num的开平方
	UINT       m_Div;      //预览窗口的间隔
	CRect      m_PreRC;    //所有预览窗口的显示区域
// Construction
public:
	void ShowAll();
	void ShowOnly(int Index);
	void RefreshWnd(int preIndex,int curIndex);
	BOOL CreatePreWnd(UINT uNum);
	CPanel(CWnd* pParent = NULL);   // standard constructor

	virtual ~CPanel();
// Dialog Data
	//{{AFX_DATA(CPanel)
	enum { IDD = IDD_PANEL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPanel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateAllPreView();
	int IsDbled();

	// Generated message map functions
	//{{AFX_MSG(CPanel)
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANEL_H__A2DF0530_DC5C_4A75_816F_F4587840F738__INCLUDED_)
