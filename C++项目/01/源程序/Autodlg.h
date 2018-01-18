#if !defined(AFX_AUTODLG_H__9C727C50_88A5_4425_8C12_11C804A03507__INCLUDED_)
#define AFX_AUTODLG_H__9C727C50_88A5_4425_8C12_11C804A03507__INCLUDED_
#include "CaptureDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Autodlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutodlg dialog

class CAutodlg : public CDialog
{
// Construction
public:
	CAutodlg(CWnd* pParent = NULL);   // standard constructor
	CCaptureDlg* m_pMain;   //主窗口指针
	HANDLE       m_hThread; //线程句柄
	UINT         m_Num;     //监控方向
	BOOL         m_Time;    //定时监控
	BOOL         m_Count;
	CString      m_UserName;
	CString      m_LogPath;
	CTime starttime,stoptime;
// Dialog Data
	//{{AFX_DATA(CAutodlg)
	enum { IDD = IDD_AUTOMATISM_DIALOG };
	CDateTimeCtrl	m_StopTime;
	CDateTimeCtrl	m_StartTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAutodlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	afx_msg void OnAmplitude();
	afx_msg void OnHorizontal();
	afx_msg void OnVertical();
	afx_msg void OnTimecheck();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTODLG_H__9C727C50_88A5_4425_8C12_11C804A03507__INCLUDED_)
