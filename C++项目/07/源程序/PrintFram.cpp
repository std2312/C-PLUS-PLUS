// PrintFram.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "PrintFram.h"
#include "PrintView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CPrintFram
extern CBbbApp theApp;
IMPLEMENT_DYNCREATE(CPrintFram, CFrameWnd)

CPrintFram::CPrintFram()
{
}

CPrintFram::~CPrintFram()
{
	
}


BEGIN_MESSAGE_MAP(CPrintFram, CFrameWnd)
	//{{AFX_MSG_MAP(CPrintFram)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintFram message handlers
#ifdef _DEBUG
void CPrintFram::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CPrintFram::Dump(CDumpContext &dc) const
{
	CFrameWnd::Dump(dc);
}
#endif

int CPrintFram::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;  // fail to create
	}

	m_ToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_ToolBar);
	theApp.m_mainfram = this;
	this->SetTitle(report.framtilte);
	this->ShowWindow(SW_SHOWMAXIMIZED);
	//this->UpdateWindow();
	return 0;
}

void CPrintFram::OnClose() 
{
	theApp.m_mainfram = NULL;
	CPrintView* temp = (CPrintView*)this->GetActiveView();
	if (! temp->ispreview)
		theApp.m_pMainWnd = theApp.m_main;
	CFrameWnd::OnClose();
}
