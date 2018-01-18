// Classinfoset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Classinfoset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassinfoset

IMPLEMENT_DYNAMIC(CClassinfoset, CRecordset)

CClassinfoset::CClassinfoset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CClassinfoset)
	m_classname = _T("");
	m_teacher = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CClassinfoset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CClassinfoset::GetDefaultSQL()
{
	return _T("[dbo].[tb_classinfo]");
}

void CClassinfoset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CClassinfoset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[classname]"), m_classname);
	RFX_Text(pFX, _T("[teacher]"), m_teacher);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CClassinfoset diagnostics

#ifdef _DEBUG
void CClassinfoset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClassinfoset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
