#if !defined(AFX_EXAMINFO_SUBMARKSET_H__AE60F83E_4A81_4A83_9752_EB39D3BDE2EE__INCLUDED_)
#define AFX_EXAMINFO_SUBMARKSET_H__AE60F83E_4A81_4A83_9752_EB39D3BDE2EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Examinfo_submarkset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkset recordset

class CExaminfo_submarkset : public CRecordset
{
public:
	CExaminfo_submarkset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CExaminfo_submarkset)

// Field/Param Data
	//{{AFX_FIELD(CExaminfo_submarkset, CRecordset)
	CString	m_studentid;
	CString	m_code;
	double	m_grade;
	CString	m_kind;
	CTime	m_examdate;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExaminfo_submarkset)
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

#endif // !defined(AFX_EXAMINFO_SUBMARKSET_H__AE60F83E_4A81_4A83_9752_EB39D3BDE2EE__INCLUDED_)
