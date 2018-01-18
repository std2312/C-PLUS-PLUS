// LoginSet.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "LoginSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginSet

IMPLEMENT_DYNAMIC(CLoginSet, CRecordset)

CLoginSet::CLoginSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLoginSet)
	m_username = _T("");
	m_password = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CLoginSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CLoginSet::GetDefaultSQL()
{
	return _T("[dbo].[tb_user]");
}

void CLoginSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLoginSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[username]"), m_username);
	RFX_Text(pFX, _T("[pwd]"), m_password);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLoginSet diagnostics

#ifdef _DEBUG
void CLoginSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLoginSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
