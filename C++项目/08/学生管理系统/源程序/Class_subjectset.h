#if !defined(AFX_CLASS_SUBJECTSET_H__78864F1F_1137_4491_B812_1591245C4FA3__INCLUDED_)
#define AFX_CLASS_SUBJECTSET_H__78864F1F_1137_4491_B812_1591245C4FA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Class_subjectset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClass_subjectset recordset

class CClass_subjectset : public CRecordset
{
public:
	CClass_subjectset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClass_subjectset)

// Field/Param Data
	//{{AFX_FIELD(CClass_subjectset, CRecordset)
	CString	m_classname;
	CString	m_code;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClass_subjectset)
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

#endif // !defined(AFX_CLASS_SUBJECTSET_H__78864F1F_1137_4491_B812_1591245C4FA3__INCLUDED_)
