#if !defined(AFX_PRINTVIEW_H__EE768648_E995_419E_914B_E72E192FF099__INCLUDED_)
#define AFX_PRINTVIEW_H__EE768648_E995_419E_914B_E72E192FF099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintView.h : header file

#include "PrintDoc.h"
#include "Report.h"

extern CReport report;
/////////////////////////////////////////////////////////////////////////////
// CPrintView view
 struct PrintRate
{
	float x,y;
};


class CPrintView : public CScrollView
{
protected:
	CPrintView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPrintView)

// Attributes
public:
	CSize caps;
// Operations
public:
	void DrawBody(CDC* pDC,bool printed);
	void DrawReportTitle(CDC* pDC,LPCSTR r_title,bool printed);
	CPrintDoc* GetDocument();
	CSize pagesize;
	PrintRate rate;
	bool ispreview;
	CFont titlefont;
	CFont bodyfont;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintView)
	public:
	virtual void OnDraw(CDC* pDC); 
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPrintView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrintView.cpp
inline CPrintDoc* CPrintView::GetDocument()
   { return (CPrintDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTVIEW_H__EE768648_E995_419E_914B_E72E192FF099__INCLUDED_)
