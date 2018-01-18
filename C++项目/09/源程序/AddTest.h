#if !defined(AFX_ADDTEST_H__0A514D3D_0BB8_4EA3_9A5E_5FE6BE525F50__INCLUDED_)
#define AFX_ADDTEST_H__0A514D3D_0BB8_4EA3_9A5E_5FE6BE525F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddTest dialog

class CAddTest : public CDialog
{
// Construction
public:
	CString ComboText;
	void OnOK();
	CAddTest(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddTest)
	enum { IDD = IDD_ADDTEST };
	CComboBox	m_SubjectCombo;
	CString	m_Question;
	CString	m_Answer;
	CString	m_AnswerA;
	CString	m_AnswerB;
	CString	m_AnswerC;
	CString	m_AnswerD;
	CString	m_Totle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddTest)
	afx_msg void OnButtonOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTEST_H__0A514D3D_0BB8_4EA3_9A5E_5FE6BE525F50__INCLUDED_)
