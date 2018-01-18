// Report.cpp: implementation of the CReport class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bbb.h"
#include "Report.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReport::CReport()
{
	m_plist = NULL;
	fieldcount = 0;
	verinterval = 0;
	fields = NULL;
	title = "";
}

CReport::~CReport()
{
	fieldcount = 0;
	fields = NULL;
	title = "";
	m_plist = NULL;
}
