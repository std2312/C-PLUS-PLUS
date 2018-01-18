// Grade_levelset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Grade_levelset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrade_levelset

IMPLEMENT_DYNAMIC(CGrade_levelset, CRecordset)

CGrade_levelset::CGrade_levelset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CGrade_levelset)
	m_grade_level = _T("");
	m_up_grade = 0.0;
	m_low_grade = 0.0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CGrade_levelset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CGrade_levelset::GetDefaultSQL()
{
	return _T("[dbo].[tb_gradelevel]");
}

void CGrade_levelset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CGrade_levelset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[grade_level]"), m_grade_level);
	RFX_Double(pFX, _T("[up_grade]"), m_up_grade);
	RFX_Double(pFX, _T("[low_grade]"), m_low_grade);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CGrade_levelset diagnostics

#ifdef _DEBUG
void CGrade_levelset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGrade_levelset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
