#if !defined(AFX_SUBJECTINFO_H__194F67E3_72CB_4E0A_99A5_8FA4D9C3A8B6__INCLUDED_)
#define AFX_SUBJECTINFO_H__194F67E3_72CB_4E0A_99A5_8FA4D9C3A8B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Subjectinfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectinfo recordset

class CSubjectinfo : public CRecordset
{
public:
	virtual void OnOK();
	CSubjectinfo(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSubjectinfo)

// Field/Param Data
	//{{AFX_FIELD(CSubjectinfo, CRecordset)
	CString	m_subject;
	CString	m_code;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectinfo)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTINFO_H__194F67E3_72CB_4E0A_99A5_8FA4D9C3A8B6__INCLUDED_)
