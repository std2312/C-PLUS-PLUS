#if !defined(AFX_REGBRREAKINFOSET_H__F571F0D7_720F_4F03_B94E_A1CD10B4FED5__INCLUDED_)
#define AFX_REGBRREAKINFOSET_H__F571F0D7_720F_4F03_B94E_A1CD10B4FED5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Regbrreakinfoset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegbrreakinfoset recordset

class CRegbrreakinfoset : public CRecordset
{
public:
	CRegbrreakinfoset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRegbrreakinfoset)

// Field/Param Data
	//{{AFX_FIELD(CRegbrreakinfoset, CRecordset)
	CString	m_studentid;
	CString	m_breakcontent;
	CString	m_handleresult;
	CString	m_memo;
	CTime	m_breaktime;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegbrreakinfoset)
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

#endif // !defined(AFX_REGBRREAKINFOSET_H__F571F0D7_720F_4F03_B94E_A1CD10B4FED5__INCLUDED_)
