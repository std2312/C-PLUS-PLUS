// officeset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "officeset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// officeset

IMPLEMENT_DYNAMIC(officeset, CRecordset)

officeset::officeset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(officeset)
	m_Office = _T("");
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString officeset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString officeset::GetDefaultSQL()
{
	return _T("[dbo].[tb_office]");
}

void officeset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(officeset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Office]"), m_Office);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// officeset diagnostics

#ifdef _DEBUG
void officeset::AssertValid() const
{
	CRecordset::AssertValid();
}

void officeset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
