#if !defined(AFX_INSERTDLG_H__67AA07A6_371D_4B2C_BA38_195683A0A46D__INCLUDED_)
#define AFX_INSERTDLG_H__67AA07A6_371D_4B2C_BA38_195683A0A46D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Insertdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInsertdlg dialog

class CInsertdlg : public CDialog
{
// Construction
public:
	int m_Condition;
	CInsertdlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CInsertdlg)
	enum { IDD = IDD_INSERT_DIALOG };
	CComboBox	m_Combo;
	CString	m_Text;
	int		m_Num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInsertdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSERTDLG_H__67AA07A6_371D_4B2C_BA38_195683A0A46D__INCLUDED_)
