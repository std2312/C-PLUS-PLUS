// ADOView.cpp: implementation of the CADOView class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hrms.h"
#include "ADOView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CADOView::CADOView()
{

}

CADOView::~CADOView()
{

}

void CADOView::ShowItemMenu(BOOL isLanded, int x, int y, CWnd* wnd)
{

	CMenu menu;
	CMenu *subMenu;
	menu.LoadMenu(IDR_ITEM);
	subMenu = menu.GetSubMenu(0);

	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, x, y, wnd);
	if(!isLanded)
	{
		menu.EnableMenuItem(IDM_DELETEITEM, MF_BYCOMMAND  | MF_DISABLED | MF_GRAYED);
		menu.EnableMenuItem(IDM_EDIT, MF_BYCOMMAND  | MF_DISABLED | MF_GRAYED);
	}
	else
	{
		menu.EnableMenuItem(IDM_DELETEITEM, MF_BYCOMMAND  | MF_ENABLED);
		menu.EnableMenuItem(IDM_EDIT, MF_BYCOMMAND  | MF_ENABLED);
	}
}
