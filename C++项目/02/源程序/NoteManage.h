// NoteManage.h : main header file for the NOTEMANAGE application
//

#if !defined(AFX_NOTEMANAGE_H__9F36D6FC_EEB6_434D_AFDD_BC71A827C4D8__INCLUDED_)
#define AFX_NOTEMANAGE_H__9F36D6FC_EEB6_434D_AFDD_BC71A827C4D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoteManageApp:
// See NoteManage.cpp for the implementation of this class
//

class CNoteManageApp : public CWinApp
{
public:
	CNoteManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoteManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoteManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEMANAGE_H__9F36D6FC_EEB6_434D_AFDD_BC71A827C4D8__INCLUDED_)
