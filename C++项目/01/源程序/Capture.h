// Capture.h : main header file for the CAPTURE application
//

#if !defined(AFX_CAPTURE_H__49776372_3704_428B_8D4D_134D7E593509__INCLUDED_)
#define AFX_CAPTURE_H__49776372_3704_428B_8D4D_134D7E593509__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCaptureApp:
// See Capture.cpp for the implementation of this class
//


class CCaptureApp : public CWinApp
{
public:
	CCaptureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCaptureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTURE_H__49776372_3704_428B_8D4D_134D7E593509__INCLUDED_)
