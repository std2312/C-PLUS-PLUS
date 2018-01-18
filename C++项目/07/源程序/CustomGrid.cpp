// CustomGrid.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "CustomGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomGrid
IMPLEMENT_DYNAMIC(CCustomGrid, CWnd )

CCustomGrid::CCustomGrid()
{
	showedit= true;
	row = -1;
	col = -1;
}

CCustomGrid::~CCustomGrid()
{
}


BEGIN_MESSAGE_MAP(CCustomGrid, CListCtrl)
	//{{AFX_MSG_MAP(CCustomGrid)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomGrid message handlers

void CCustomGrid::PreSubclassWindow() 
{
	ModifyStyle(LVS_EDITLABELS,0);
	ModifyStyle(0,LVS_REPORT);
	//ModifyStyle(0,LVS_SHOWSELALWAYS);
	SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE|LVS_EX_FLATSB);
	edit.Create(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER,CRect(0,40,10,50),this,1001);
	
	CListCtrl::PreSubclassWindow();
}

void CCustomGrid::ShowEdit()
{
	CRect rect; //记录当前单元格的坐标
	GetSubItemRect(row,col,LVIR_LABEL,rect);
	CString str;
	str = GetItemText(row,col);
	edit.MoveWindow(rect);
	edit.SetWindowText(str);
	edit.ShowWindow(SW_SHOW);
	edit.SetSel(0,100);
	edit.SetFocus();
	edit.SetReadOnly(!showedit);
	UpdateWindow();
}

void CCustomGrid::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CListCtrl::OnLButtonDown(nFlags, point);
	LVHITTESTINFO p;
	p.pt = point;
	if (SubItemHitTest(&p)!= -1)
	{
		col = p.iSubItem;
		row = p.iItem;
		ShowEdit();
	}
}
