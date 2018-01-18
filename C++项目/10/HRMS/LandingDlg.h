#if !defined(AFX_LANDINGDLG_H__AB886B12_5168_48E9_8D9A_32277AFA5D4A__INCLUDED_)
#define AFX_LANDINGDLG_H__AB886B12_5168_48E9_8D9A_32277AFA5D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LandingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLandingDlg dialog

class CLandingDlg : public CDialog
{
// Construction
public:
	BOOL DrawSystemButton(CWindowDC &dc, CBitmap &bitmap);
	BOOL DrawTitleBar(CWindowDC &dc);
	CString GetUserName();
	BOOL CheckLoading(CString& name, CString& code);
	CLandingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLandingDlg)
	enum { IDD = IDD_LANDING };
	CButton	m_Cancel;
	CButton	m_OK;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLandingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLandingDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBitmap m_Cross;
	CBitmap m_Title;
	HBITMAP m_BitmapCancel;
	HBITMAP m_BitmapOK;
	CString m_UserName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANDINGDLG_H__AB886B12_5168_48E9_8D9A_32277AFA5D4A__INCLUDED_)
