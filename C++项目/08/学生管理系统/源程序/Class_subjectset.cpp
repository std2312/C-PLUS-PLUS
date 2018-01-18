// Class_subjectset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Class_subjectset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClass_subjectset

IMPLEMENT_DYNAMIC(CClass_subjectset, CRecordset)

CClass_subjectset::CClass_subjectset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CClass_subjectset)
	m_classname = _T("");
	m_code = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CClass_subjectset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CClass_subjectset::GetDefaultSQL()
{
	return _T("[dbo].[tb_class_subject]");
}

void CClass_subjectset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CClass_subjectset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[classname]"), m_classname);
	RFX_Text(pFX, _T("[code]"), m_code);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CClass_subjectset diagnostics

#ifdef _DEBUG
void CClass_subjectset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClass_subjectset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
