// StageButton.cpp : implementation file
//

#include "stdafx.h"
#include "Capture.h"
#include "StageButton.h"
#include "CaptureDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStageButton

CStageButton::CStageButton()
{
	m_Type = ctLeft;
}

CStageButton::~CStageButton()
{

}

BEGIN_MESSAGE_MAP(CStageButton, CButton)
	//{{AFX_MSG_MAP(CStageButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStageButton message handlers

//在鼠标按钮时根据按钮的类型标识,调用不同的方法
void CStageButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	switch(m_Type)
	{
	case ctUp:
		{
			((CCaptureDlg*)GetParent())->OnUp();
			break;
		}
	case ctDown:
		{
			((CCaptureDlg*)GetParent())->OnDown();
			break;
		}
	case ctLeft:
		{
			((CCaptureDlg*)GetParent())->OnLeft();
			break;
		}
	case ctRight:
		{
			((CCaptureDlg*)GetParent())->OnRight();
			break;
		}
	case ctInFoci:
		{
			((CCaptureDlg*)GetParent())->OnInFoci();
			break;
		}
	case ctReFoci:
		{
			((CCaptureDlg*)GetParent())->OnReFoci();
			break;
		}
	case ctInLen:
		{
			((CCaptureDlg*)GetParent())->OnInLen();
			break;
		}
	case ctReLen:
		{
			((CCaptureDlg*)GetParent())->OnReLen();
			break;
		}
	case ctInAperture:
		{
			((CCaptureDlg*)GetParent())->OnInAperture();
			break;
		}
	case ctReAperture:
		{
			((CCaptureDlg*)GetParent())->OnReAperture();
			break;
		}
	case ctInBrush:
		{
			((CCaptureDlg*)GetParent())->OnInBrush();
			break;
		}
	case ctReBrush:
		{
			((CCaptureDlg*)GetParent())->OnReBrush();
			break;		
		}
	default:
		{
			//......
			break;
		}
	}
	CButton::OnLButtonDown(nFlags, point);
}

//在释放鼠标按钮时停止对云台的控制
void CStageButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	((CCaptureDlg*)GetParent())->OnReset();
	CButton::OnLButtonUp(nFlags, point);
}
