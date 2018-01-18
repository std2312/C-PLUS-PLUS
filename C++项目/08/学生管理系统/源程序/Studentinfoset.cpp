// Studentinfoset.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Studentinfoset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentinfoset

IMPLEMENT_DYNAMIC(CStudentinfoset, CRecordset)

CStudentinfoset::CStudentinfoset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentinfoset)
	m_studentid = _T("");
	m_studentname = _T("");
	m_sex = _T("");
	m_age = 0.0;
	m_addr = _T("");
	m_phone = _T("");
	m_class = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStudentinfoset::GetDefaultConnect()
{
	return _T("ODBC;DSN=mystudentsys");
}

CString CStudentinfoset::GetDefaultSQL()
{
	return _T("[dbo].[tb_studentinfo]");
}

void CStudentinfoset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentinfoset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentid]"), m_studentid);
	RFX_Text(pFX, _T("[studentname]"), m_studentname);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Double(pFX, _T("[age]"), m_age);
	RFX_Text(pFX, _T("[addr]"), m_addr);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[class]"), m_class);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentinfoset diagnostics

#ifdef _DEBUG
void CStudentinfoset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentinfoset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
