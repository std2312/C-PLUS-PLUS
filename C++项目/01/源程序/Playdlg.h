//{{AFX_INCLUDES()
#include "mediaplayer2.h"
//}}AFX_INCLUDES
#if !defined(AFX_PLAYDLG_H__35AC635C_A0C9_4897_ACAC_168AAFDA3F5B__INCLUDED_)
#define AFX_PLAYDLG_H__35AC635C_A0C9_4897_ACAC_168AAFDA3F5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Playdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlaydlg dialog

class CPlaydlg : public CDialog
{
// Construction
public:
	CPlaydlg(CWnd* pParent = NULL);   // standard constructor
	virtual void OnOK();
	CString m_UserName;
	CString m_LogPath;
// Dialog Data
	//{{AFX_DATA(CPlaydlg)
	enum { IDD = IDD_PLAY_DIALOG };
	CStatic	m_Path;
	CMediaPlayer2	m_MediaPlay;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaydlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlaydlg)
	afx_msg void OnPlay();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYDLG_H__35AC635C_A0C9_4897_ACAC_168AAFDA3F5B__INCLUDED_)
