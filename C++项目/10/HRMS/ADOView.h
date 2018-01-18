// ADOView.h: interface for the CADOView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOVIEW_H__D59A745B_E8E9_400F_983A_B626F6DE2980__INCLUDED_)
#define AFX_ADOVIEW_H__D59A745B_E8E9_400F_983A_B626F6DE2980__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CADOView  
{
public:
	CADOView();
	virtual ~CADOView();

public:
	static	void ShowItemMenu(BOOL isLanded, int x, int y, CWnd* wnd);
	virtual BOOL SetRow(int row, CString *strArray, int count) = 0;
	virtual BOOL DeleteAllRows() = 0;
};

#endif // !defined(AFX_ADOVIEW_H__D59A745B_E8E9_400F_983A_B626F6DE2980__INCLUDED_)
