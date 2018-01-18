// bbb.h : main header file for the BBB application
//

#if !defined(AFX_BBB_H__4611E090_1F9D_4AA0_8624_0CDCA8D6D672__INCLUDED_)
#define AFX_BBB_H__4611E090_1F9D_4AA0_8624_0CDCA8D6D672__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBbbApp:
// See bbb.cpp for the implementation of this class
//

class CBbbApp : public CWinApp
{
public:
	void IniAdo();
	CString ExtractFilePath(LPTSTR filename);
	CBbbApp();
	CFrameWnd * m_mainfram;
	CWnd * m_main;//´æ´¢Ö÷´°¿ÚÖ¸Õë
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBbbApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBbbApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBB_H__4611E090_1F9D_4AA0_8624_0CDCA8D6D672__INCLUDED_)
