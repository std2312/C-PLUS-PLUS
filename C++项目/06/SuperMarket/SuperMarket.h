// SuperMarket.h : main header file for the SUPERMARKET application
//

#if !defined(AFX_SUPERMARKET_H__F7E7383C_78F8_415A_B0C4_F4A81583DC68__INCLUDED_)
#define AFX_SUPERMARKET_H__F7E7383C_78F8_415A_B0C4_F4A81583DC68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSuperMarketApp:
// See SuperMarket.cpp for the implementation of this class
//

class CSuperMarketApp : public CWinApp
{
public:
	CSuperMarketApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperMarketApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSuperMarketApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPERMARKET_H__F7E7383C_78F8_415A_B0C4_F4A81583DC68__INCLUDED_)
