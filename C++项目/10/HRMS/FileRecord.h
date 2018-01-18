#if !defined(AFX_FILERECORD_H__F51D07DB_46DD_4EA7_976D_DB116B728530__INCLUDED_)
#define AFX_FILERECORD_H__F51D07DB_46DD_4EA7_976D_DB116B728530__INCLUDED_

#include "ADOOperation.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileRecord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileRecord dialog

class CFileRecord : public CDialog
{
// Construction
public:
	BOOL SetApplerInfo(CString&id);
	void SetApplerId(CString &id);
	void SetAppler(BOOL is);
	static BOOL InitDeptComboBox(CComboBox* pDept);
	static 	BOOL ShowDutyComboBox(CString dept, CComboBox* pDept);
	static	CString GetDutyName(DWORD num);
	static	CString GetDeptName(DWORD num);
	static DWORD GetDutyNumber(CString str);
	static DWORD GetDeptNumber(CString str);

	void SetModifyDlg(BOOL is = TRUE);
	void SetShowItem(int index);
	BOOL ModifyRecord(int index);
	BOOL InitModiView();
	BOOL ShowRecord(int index);
	BOOL SaveFile();
	CFileRecord(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFileRecord)
	enum { IDD = IDD_FILE_RECORD };
	CComboBox	m_Duty;
	CComboBox	m_Dept;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileRecord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileRecord)
	virtual BOOL OnInitDialog();
	afx_msg void OnLoadPicture();
	afx_msg void OnFileRecordSave();
	afx_msg void OnFileRecordReset();
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	afx_msg void OnCompactEdit();
	afx_msg void OnSelchangeCombo4();
	afx_msg void OnSeelist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_CurSel;
	CString m_ApplerId;
	BOOL m_IsAppler;
	int m_Index;
	CString m_PhotoFileName;
	BOOL m_IsModifyDlg;
	HBITMAP m_Photo;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILERECORD_H__F51D07DB_46DD_4EA7_976D_DB116B728530__INCLUDED_)
