// Examkindset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Examkindset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamkindset

IMPLEMENT_DYNAMIC(CExamkindset, CRecordset)

CExamkindset::CExamkindset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CExamkindset)
	m_kind = _T("");
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CExamkindset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CExamkindset::GetDefaultSQL()
{
	return _T("[dbo].[tb_examkinds]");
}

void CExamkindset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CExamkindset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[kind]"), m_kind);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CExamkindset diagnostics

#ifdef _DEBUG
void CExamkindset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CExamkindset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
