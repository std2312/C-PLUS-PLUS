// Teacherinfoset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Teacherinfoset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherinfoset

IMPLEMENT_DYNAMIC(CTeacherinfoset, CRecordset)

CTeacherinfoset::CTeacherinfoset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTeacherinfoset)
	m_teacherid = _T("");
	m_teachername = _T("");
	m_sex = _T("");
	m_office = _T("");
	m_knowledge = _T("");
	m_Level = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTeacherinfoset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CTeacherinfoset::GetDefaultSQL()
{
	return _T("[dbo].[tb_teacher]");
}

void CTeacherinfoset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTeacherinfoset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[teacherid]"), m_teacherid);
	RFX_Text(pFX, _T("[teachername]"), m_teachername);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Text(pFX, _T("[office]"), m_office);
	RFX_Text(pFX, _T("[knowledge]"), m_knowledge);
	RFX_Text(pFX, _T("[Level]"), m_Level);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTeacherinfoset diagnostics

#ifdef _DEBUG
void CTeacherinfoset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTeacherinfoset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
