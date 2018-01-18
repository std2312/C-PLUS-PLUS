#if !defined(AFX_LABORRECORDLG_H__8792BC14_7FD5_4D7F_BB02_1049E199C6F5__INCLUDED_)
#define AFX_LABORRECORDLG_H__8792BC14_7FD5_4D7F_BB02_1049E199C6F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LaborRecorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLaborRecorDlg dialog

class CLaborRecorDlg : public CDialog
{
// Construction
public:
	BOOL SaveInfo();
	BOOL InitEmpNumCom(CComboBox* box);
	CLaborRecorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLaborRecorDlg)
	enum { IDD = IDD_LABORAGE_REC };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLaborRecorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLaborRecorDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABORRECORDLG_H__8792BC14_7FD5_4D7F_BB02_1049E199C6F5__INCLUDED_)
