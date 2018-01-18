// ExamOnlineDlg.h : header file
//

#if !defined(AFX_EXAMONLINEDLG_H__8D88895C_2D09_41E3_9AD1_125179D9F4E8__INCLUDED_)
#define AFX_EXAMONLINEDLG_H__8D88895C_2D09_41E3_9AD1_125179D9F4E8__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg dialog

class CExamOnlineDlg : public CDialog
{
// Construction
public:
	CString TimeStr;
	virtual void OnCancel();
	void CheckAnswer();
	CString Answer;
	void SaveQuestion();
	void PutAnswer();
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	int Sid;
	int testnum;
	int num;
	CExamOnlineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExamOnlineDlg)
	enum { IDD = IDD_EXAMONLINE };
	CStatic	m_Time;
	CStatic	m_TestID;
	CStatic	m_Test;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamOnlineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExamOnlineDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNext();
	afx_msg void OnBack();
	afx_msg void OnRadioA();
	afx_msg void OnRadioB();
	afx_msg void OnRadioC();
	afx_msg void OnRadioD();
	afx_msg void OnReset();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMONLINEDLG_H__8D88895C_2D09_41E3_9AD1_125179D9F4E8__INCLUDED_)
