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
	CPreView * m_pList;    //Ԥ������
	UINT       m_Num;      //��¼Ԥ�����ڵ�����
	UINT       m_UnitNum;  //m_Num�Ŀ�ƽ��
	UINT       m_Div;      //Ԥ�����ڵļ��
	CRect      m_PreRC;    //����Ԥ�����ڵ���ʾ����
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
