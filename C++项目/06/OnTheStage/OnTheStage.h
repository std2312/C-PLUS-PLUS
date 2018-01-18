// OnTheStage.h : main header file for the ONTHESTAGE application
//

#if !defined(AFX_ONTHESTAGE_H__92AF74E1_834B_4315_8C72_5316D44B2FD9__INCLUDED_)
#define AFX_ONTHESTAGE_H__92AF74E1_834B_4315_8C72_5316D44B2FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COnTheStageApp:
// See OnTheStage.cpp for the implementation of this class
//

class COnTheStageApp : public CWinApp
{
public:
	COnTheStageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnTheStageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COnTheStageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONTHESTAGE_H__92AF74E1_834B_4315_8C72_5316D44B2FD9__INCLUDED_)
