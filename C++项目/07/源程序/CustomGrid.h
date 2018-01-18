#if !defined(AFX_CUSTOMGRID_H__0BDB73F9_B587_4BCF_8417_AB267B9183FB__INCLUDED_)
#define AFX_CUSTOMGRID_H__0BDB73F9_B587_4BCF_8417_AB267B9183FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomGrid.h : header file
//
#include "KeyEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CCustomGrid window

class CCustomGrid : public CListCtrl
{
// Construction
public:
	CCustomGrid();
	bool showedit;
	int row;
	int col;
	CKeyEdit edit;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomGrid)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowEdit();
	virtual ~CCustomGrid();
	DECLARE_DYNAMIC( CCustomGrid)

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomGrid)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMGRID_H__0BDB73F9_B587_4BCF_8417_AB267B9183FB__INCLUDED_)
