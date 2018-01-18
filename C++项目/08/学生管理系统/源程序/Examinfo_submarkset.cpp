// Examinfo_submarkset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Examinfo_submarkset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkset

IMPLEMENT_DYNAMIC(CExaminfo_submarkset, CRecordset)

CExaminfo_submarkset::CExaminfo_submarkset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CExaminfo_submarkset)
	m_studentid = _T("");
	m_code = _T("");
	m_grade = 0.0;
	m_kind = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CExaminfo_submarkset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CExaminfo_submarkset::GetDefaultSQL()
{
	return _T("[dbo].[tb_examinfo_sub]");
}

void CExaminfo_submarkset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CExaminfo_submarkset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentid]"), m_studentid);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Double(pFX, _T("[grade]"), m_grade);
	RFX_Text(pFX, _T("[kind]"), m_kind);
	RFX_Date(pFX, _T("[examdate]"), m_examdate);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CExaminfo_submarkset diagnostics

#ifdef _DEBUG
void CExaminfo_submarkset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CExaminfo_submarkset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
