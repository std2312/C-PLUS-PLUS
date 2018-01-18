#if !defined(AFX_TEACHERINFOSET_H__D33D28E8_2E76_4EFE_815F_CD2DA489D431__INCLUDED_)
#define AFX_TEACHERINFOSET_H__D33D28E8_2E76_4EFE_815F_CD2DA489D431__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Teacherinfoset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeacherinfoset recordset

class CTeacherinfoset : public CRecordset
{
public:
	CTeacherinfoset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTeacherinfoset)

// Field/Param Data
	//{{AFX_FIELD(CTeacherinfoset, CRecordset)
	CString	m_teacherid;
	CString	m_teachername;
	CString	m_sex;
	CString	m_office;
	CString	m_knowledge;
	CString	m_Level;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherinfoset)
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

#endif // !defined(AFX_TEACHERINFOSET_H__D33D28E8_2E76_4EFE_815F_CD2DA489D431__INCLUDED_)
