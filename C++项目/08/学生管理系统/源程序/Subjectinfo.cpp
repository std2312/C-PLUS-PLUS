// Subjectinfo.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Subjectinfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectinfo

IMPLEMENT_DYNAMIC(CSubjectinfo, CRecordset)

CSubjectinfo::CSubjectinfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSubjectinfo)
	m_subject = _T("");
	m_code = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSubjectinfo::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CSubjectinfo::GetDefaultSQL()
{
	return _T("[dbo].[tb_subject]");
}

void CSubjectinfo::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSubjectinfo)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Text(pFX, _T("[code]"), m_code);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSubjectinfo diagnostics

#ifdef _DEBUG
void CSubjectinfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSubjectinfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

void CSubjectinfo::OnOK()
{

}
