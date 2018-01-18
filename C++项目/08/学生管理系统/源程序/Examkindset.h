#if !defined(AFX_EXAMKINDSET_H__E319E516_FC91_4DF1_9E78_4125B916C934__INCLUDED_)
#define AFX_EXAMKINDSET_H__E319E516_FC91_4DF1_9E78_4125B916C934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Examkindset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamkindset recordset

class CExamkindset : public CRecordset
{
public:
	CExamkindset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CExamkindset)

// Field/Param Data
	//{{AFX_FIELD(CExamkindset, CRecordset)
	CString	m_kind;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamkindset)
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

#endif // !defined(AFX_EXAMKINDSET_H__E319E516_FC91_4DF1_9E78_4125B916C934__INCLUDED_)
