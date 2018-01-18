#if !defined(AFX_REQCHKLIST_H__14E9E626_1907_4A8B_AD2D_B7D721D17B51__INCLUDED_)
#define AFX_REQCHKLIST_H__14E9E626_1907_4A8B_AD2D_B7D721D17B51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReqChkList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReqChkList dialog

class CReqChkList : public CDialog, public CADOView
{
// Construction
public:
	HACCEL m_hAccel;
	BOOL SetRow(int row, CString *strArray, int count);
	BOOL DeleteAllRows();
	BOOL ShowList(CString&seaExp);
	BOOL ExportToWord(CString& file);
	CReqChkList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReqChkList)
	enum { IDD = IDD_REQCHECKLIST };
	CEditableListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReqChkList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg LRESULT OnListEditKillFocus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnListEditDBClick(WPARAM wParam, LPARAM lParam);

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV suppor
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReqChkList)
	virtual BOOL OnInitDialog();
	afx_msg void OnExport();
	afx_msg void OnFindEmployee();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQCHKLIST_H__14E9E626_1907_4A8B_AD2D_B7D721D17B51__INCLUDED_)
