#if !defined(AFX_STUDENTINFOSET_H__530F9293_B1B9_4405_9DFD_26415C5CF2B4__INCLUDED_)
#define AFX_STUDENTINFOSET_H__530F9293_B1B9_4405_9DFD_26415C5CF2B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Studentinfoset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentinfoset recordset

class CStudentinfoset : public CRecordset
{
public:
	CStudentinfoset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentinfoset)

// Field/Param Data
	//{{AFX_FIELD(CStudentinfoset, CRecordset)
	CString	m_studentid;
	CString	m_studentname;
	CString	m_sex;
	double	m_age;
	CString	m_addr;
	CString	m_phone;
	CString	m_class;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentinfoset)
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

#endif // !defined(AFX_STUDENTINFOSET_H__530F9293_B1B9_4405_9DFD_26415C5CF2B4__INCLUDED_)
