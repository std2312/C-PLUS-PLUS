#if !defined(AFX_OFFICESET_H__57DB5877_44F2_43BC_8B24_D47413D74D6B__INCLUDED_)
#define AFX_OFFICESET_H__57DB5877_44F2_43BC_8B24_D47413D74D6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// officeset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// officeset recordset

class officeset : public CRecordset
{
public:
	officeset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(officeset)

// Field/Param Data
	//{{AFX_FIELD(officeset, CRecordset)
	CString	m_Office;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(officeset)
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

#endif // !defined(AFX_OFFICESET_H__57DB5877_44F2_43BC_8B24_D47413D74D6B__INCLUDED_)
