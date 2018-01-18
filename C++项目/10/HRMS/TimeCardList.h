#if !defined(AFX_TIMECARDLIST_H__352904AE_4165_420B_8BA7_FA13AB3B5CD8__INCLUDED_)
#define AFX_TIMECARDLIST_H__352904AE_4165_420B_8BA7_FA13AB3B5CD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeCardList.h : header file
//
#include	"EditableListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CTimeCardList dialog

class CTimeCardList : public CDialog
{
// Construction
public:
	DWORD GetLeaveEarlyCount(CString&name, int year, int month);
	DWORD GetLateCount(CString &name, int year, int month);
	double GetCollectWorkTime(CString&name, int year, int month);
	DWORD GetAbsenceDuty(CString&name, int year, int month);
	BOOL CollectTimeCard(CString &name, int year, int month);
	DWORD GetRecordCount(_RecordsetPtr pRecordset);
	BOOL ExportToWord(CString& file);
	BOOL InitMonthComboBox(CString name, int year);
	BOOL InitYearComboBox(CString name);
	void UpdateTimeCardList(void);
	BOOL ShowTimeCardList(CString name, int year, int month);
	CTimeCardList(CWnd* pParent = NULL);   // standard constructor
	ExportToWord(CString &file, CString &sql);

// Dialog Data
	//{{AFX_DATA(CTimeCardList)
	enum { IDD = IDD_ABSENCE };
	CListCtrl	m_TimeCardList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeCardList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeCardList)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnExport();
	afx_msg void OnDeleteitem();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnQuit();
	afx_msg void OnSearchRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_CurSel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECARDLIST_H__352904AE_4165_420B_8BA7_FA13AB3B5CD8__INCLUDED_)
