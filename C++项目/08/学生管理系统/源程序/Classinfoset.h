#if !defined(AFX_CLASSINFOSET_H__14B9286D_2327_44BC_9A70_6A784E9C8075__INCLUDED_)
#define AFX_CLASSINFOSET_H__14B9286D_2327_44BC_9A70_6A784E9C8075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Classinfoset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClassinfoset recordset

class CClassinfoset : public CRecordset
{
public:
	CClassinfoset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClassinfoset)

// Field/Param Data
	//{{AFX_FIELD(CClassinfoset, CRecordset)
	CString	m_classname;
	CString	m_teacher;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassinfoset)
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

#endif // !defined(AFX_CLASSINFOSET_H__14B9286D_2327_44BC_9A70_6A784E9C8075__INCLUDED_)
