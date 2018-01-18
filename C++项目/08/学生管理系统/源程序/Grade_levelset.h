#if !defined(AFX_GRADE_LEVELSET_H__1973D80A_F44F_4E28_9267_AF08801B0B8F__INCLUDED_)
#define AFX_GRADE_LEVELSET_H__1973D80A_F44F_4E28_9267_AF08801B0B8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Grade_levelset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGrade_levelset recordset

class CGrade_levelset : public CRecordset
{
public:
	CGrade_levelset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGrade_levelset)

// Field/Param Data
	//{{AFX_FIELD(CGrade_levelset, CRecordset)
	CString	m_grade_level;
	double	m_up_grade;
	double	m_low_grade;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrade_levelset)
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

#endif // !defined(AFX_GRADE_LEVELSET_H__1973D80A_F44F_4E28_9267_AF08801B0B8F__INCLUDED_)
