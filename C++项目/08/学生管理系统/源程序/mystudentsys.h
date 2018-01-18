// mystudentsys.h : main header file for the MYSTUDENTSYS application
//

#if !defined(AFX_MYSTUDENTSYS_H__261C5544_9E81_4754_B0FC_9E2D8E6E47D7__INCLUDED_)
#define AFX_MYSTUDENTSYS_H__261C5544_9E81_4754_B0FC_9E2D8E6E47D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMystudentsysApp:
// See mystudentsys.cpp for the implementation of this class
//

class CMystudentsysApp : public CWinApp
{
public:
	int ExitInstance();
	CMystudentsysApp();

	CDatabase m_DB;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMystudentsysApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMystudentsysApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTUDENTSYS_H__261C5544_9E81_4754_B0FC_9E2D8E6E47D7__INCLUDED_)
