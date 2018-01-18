// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__924AC6D0_55BB_4C59_BB77_9FA275A18624__INCLUDED_)
#define AFX_STDAFX_H__924AC6D0_55BB_4C59_BB77_9FA275A18624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace \
rename("EOF","adoEOF") rename("BOF","adoBOF")

#define Provider	"Provider=SQLOLEDB.1;Integrated Security=SSPI;\
Persist Security Info=False;Initial Catalog=HRMS"

#include	<atlbase.h>

#define BITMAP_X	259	
#define BITMAP_Y	16
#define DAYSOFYEAR	365				//一年按365天处理
#define ICONSUM		5
#define IDC_LISTEDIT	200				//列表编辑时候的编辑框控件的ID号

#include	"resource.h"
#include	"ADOOperation.h"
#include	"FileRecord.h"
#include	"FileInfo.h"
#include	"ADOView.h"
#include	"DeptInfoDlg.h"
#include	"DeptDutyDlg.h"
#include	"BargainDlg.h"
#include	"TemLoadDlg.h"
#include	"LoadInTempDlg.h"
#include	"FindEmployeeDlg.h"
#include	"DeptInfoDlg.h"
#include	"TimeCardDlg.h"
#include	"TimeCardList.h"
#include	"PayClipDlg.h"
#include	"LandingDlg.h"
#include	"UserRegDlg.h"
#include	"PayListDlg.h"
#include	"ApplyEmployeeDlg.h"
#include	"ApplerInfo.h"
#include	"AssessDlg.h"
#include	"ApplerList.h"
#include	"AssessList.h"
#include	"RequestInfListDlg.h"
#include	"msword9.h"
#include	"EditableListCtrl.h"
#include	"AgreementListDlg.h"
#include	"ApplerSearchDlg.h"
#include	"SearchRequestDlg.h"
#include	"AssessSearchDlg.h"
#include	"EditableListCtrl.h"
#include	"PayListSeachDlg.h"
#include	"LaborageRecordDlg.h"
#include	"LabRecSearchDlg.h"
#include	"LaborRecorDlg.h"
#include	"PrintPreviewDlg.h"
#include	"PrintView.h"
#include	"HumanRemoveDlg.h"
#include	"ReqCheckDlg.h"
#include	"ReqChkList.h"
#include	"LeaveItemDlg.h"
#include	"LeaveList.h"
#include	"ReqSeachDlg.h"
#include	"FindDlg.h"

void PrintResult(CString &result);


//#define TESTING

#ifdef	_DEBUG
#define PRINTRESULT(result)	\
	::PrintResult(result);
#else
#define	PRINTRESULT(result)
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__924AC6D0_55BB_4C59_BB77_9FA275A18624__INCLUDED_)
