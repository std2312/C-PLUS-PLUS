// HRMS.h : main header file for the HRMS application
//

#if !defined(AFX_HRMS_H__6C0670E8_FF79_4A15_9E34_EB54306DBA80__INCLUDED_)
#define AFX_HRMS_H__6C0670E8_FF79_4A15_9E34_EB54306DBA80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHRMSApp:
// See HRMS.cpp for the implementation of this class
//

class CHRMSApp : public CWinApp
{
public:
	CHRMSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHRMSApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHRMSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


extern BOOL G_IsLanded;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HRMS_H__6C0670E8_FF79_4A15_9E34_EB54306DBA80__INCLUDED_)
