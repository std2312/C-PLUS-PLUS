// Regbrreakinfoset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Regbrreakinfoset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegbrreakinfoset

IMPLEMENT_DYNAMIC(CRegbrreakinfoset, CRecordset)

CRegbrreakinfoset::CRegbrreakinfoset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRegbrreakinfoset)
	m_studentid = _T("");
	m_breakcontent = _T("");
	m_handleresult = _T("");
	m_memo = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRegbrreakinfoset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CRegbrreakinfoset::GetDefaultSQL()
{
	return _T("[dbo].[tb_regbreakinfo]");
}

void CRegbrreakinfoset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRegbrreakinfoset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentid]"), m_studentid);
	RFX_Text(pFX, _T("[breakcontent]"), m_breakcontent);
	RFX_Text(pFX, _T("[handleresult]"), m_handleresult);
	RFX_Text(pFX, _T("[memo]"), m_memo);
	RFX_Date(pFX, _T("[breaktime]"), m_breaktime);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRegbrreakinfoset diagnostics

#ifdef _DEBUG
void CRegbrreakinfoset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRegbrreakinfoset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
