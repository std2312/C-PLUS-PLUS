// ExamOnline.h : main header file for the EXAMONLINE application
//

#if !defined(AFX_EXAMONLINE_H__1BDE99F5_1F31_4EF9_AC30_18B3BAAB1104__INCLUDED_)
#define AFX_EXAMONLINE_H__1BDE99F5_1F31_4EF9_AC30_18B3BAAB1104__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "ADOConn.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineApp:
// See ExamOnline.cpp for the implementation of this class
//

class CExamOnlineApp : public CWinApp
{
public:
	int studentid;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CExamOnlineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamOnlineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExamOnlineApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMONLINE_H__1BDE99F5_1F31_4EF9_AC30_18B3BAAB1104__INCLUDED_)
