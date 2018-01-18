#if !defined(AFX_MANAGEDLG_H__3EC04BDC_E72F_46EA_9533_7363A886C55F__INCLUDED_)
#define AFX_MANAGEDLG_H__3EC04BDC_E72F_46EA_9533_7363A886C55F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Managedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManagedlg dialog

class CManagedlg : public CDialog
{
// Construction
public:
	void Display();
	void AddToList();
	void ExitConnect();
	void OnInitADOConn();
	CManagedlg(CWnd* pParent = NULL);   // standard constructor
	CImageList     m_ImageList;
	_ConnectionPtr m_pConnection;
	_RecordsetPtr  m_pRecordset;
	int            m_nExpandedHeight;
	int            m_nNormalHeight;
	BOOL           m_bExpand;
	CString        m_UserName;
	CString        m_LogPath;
	CString        m_PathText;
// Dialog Data
	//{{AFX_DATA(CManagedlg)
	enum { IDD = IDD_MANAGE_DIALOG };
	CListCtrl	m_List;
	CString	m_Name;
	CString	m_PassWord;
	CString	m_Log;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManagedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonadd();
	afx_msg void OnButtonmod();
	afx_msg void OnButtondel();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEDLG_H__3EC04BDC_E72F_46EA_9533_7363A886C55F__INCLUDED_)
