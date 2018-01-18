// PrintDoc.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "PrintDoc.h"
#include "Report.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CReport report;
/////////////////////////////////////////////////////////////////////////////
// CPrintDoc

IMPLEMENT_DYNCREATE(CPrintDoc, CDocument)

CPrintDoc::CPrintDoc()
{
}

BOOL CPrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPrintDoc::~CPrintDoc()
{
}


BEGIN_MESSAGE_MAP(CPrintDoc, CDocument)
	//{{AFX_MSG_MAP(CPrintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc diagnostics

#ifdef _DEBUG
void CPrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc serialization

void CPrintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc commands

void CPrintDoc::SetTitle(LPCTSTR lpszTitle) 
{
	//lpszTitle =  ;
	CDocument::SetTitle(report.title);
}
