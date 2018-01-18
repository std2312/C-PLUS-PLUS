// Panel.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
#include "Panel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPanel dialog


CPanel::CPanel(CWnd* pParent /*=NULL*/)
	: CDialog(CPanel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPanel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_Num = 0;
	m_Div = 1;
	m_UnitNum = 0;
}


void CPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPanel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPanel, CDialog)
	//{{AFX_MSG_MAP(CPanel)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPanel message handlers

void CPanel::OnOK() 
{

}

CPanel::~CPanel()
{
	if (m_Num>0)
		delete [] m_pList;
	
}

BOOL CPanel::CreatePreWnd(UINT uNum)
{
	if(uNum == 0)
		return FALSE;
	m_UnitNum = uNum;
	m_Num = pow(uNum,2);
	m_pList = new CPreView[m_Num];
	CRect rc;
	GetClientRect(rc);
	//预览窗口的宽度
	int width = (rc.Width() - (uNum + 1) * m_Div) / uNum;
	//预览窗口的高度
	int height = (rc.Height() - (uNum + 1) * m_Div) / uNum;

	for (int i =0; i<m_Num; i++)
	{
		int row = i / uNum + 1;
		int col = i % uNum + 1;
		int x   = col*m_Div + (col - 1) * width;
		int y   = row*m_Div + (row - 1) * height;
		CRect rect(x,y,x+width,y+height);
		m_pList[i].Create("",WS_CHILD|WS_VISIBLE|SS_BLACKFRAME|SS_NOTIFY,rect,this);
		m_pList[i].m_Index = i;	
	}
	return TRUE;
}

void CPanel::RefreshWnd(int preIndex,int curIndex)
{
	m_pList[preIndex].Invalidate();
	m_pList[curIndex].Invalidate();
}

void CPanel::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(m_Num>0) //创建了预览窗口
	{
		CRect rc;
		GetClientRect(rc);	
		m_PreRC = rc;
		m_PreRC.DeflateRect(m_Div,m_Div,m_Div,m_Div);
		//预览窗口的宽度
		int width  = (rc.Width() - (m_UnitNum + 1) * m_Div) / m_UnitNum;
		//预览窗口的高度
		int height = (rc.Height() - (m_UnitNum + 1) * m_Div) / m_UnitNum;
		for(int i =0; i<m_Num; i++)
		{
			int row = i / m_UnitNum+1;
			int col = i % m_UnitNum+1;
			int x = col*m_Div+(col-1)*width;
			int y = row*m_Div+(row-1)*height;
			CRect rect(x,y,x+width,y+height);
			if(m_pList[i].IsWindowVisible())
			{
				if(!m_pList[i].m_Dbled)
				{
					m_pList[i].MoveWindow(rect);
					m_pList[i].Invalidate();
				}
				else
				{
					m_pList[i].MoveWindow(m_PreRC);
					m_pList[i].Invalidate();
				}
			}
		}
	}
}

void CPanel::ShowOnly(int Index)
{
	for(int i=0;i<m_Num;i++)
	{
		if(i == Index)
		{
			m_pList[i].m_Stop = psPreview;
			m_pList[i].ShowWindow(SW_SHOW);
		}
		else
		{
			if(m_pList[i].m_Stop == psPreview)
				m_pList[i].m_Stop = psRestore;
			VCAStopVideoPreview(i);
			m_pList[i].ShowWindow(SW_HIDE);
		}
		m_pList[i].Invalidate();
	}
}

void CPanel::ShowAll()
{
	for(int i=0;i<m_Num;i++)
	{
		if(m_pList[i].m_Stop == psRestore)
		{
			m_pList[i].m_Stop = psPreview;
			VCAStartVideoPreview(i);
		}
		m_pList[i].ShowWindow(SW_SHOW);
		m_pList[i].Invalidate();
	}
}


HBRUSH CPanel::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (nCtlColor == CTLCOLOR_DLG )
	{
		CBrush br(RGB(255,0,255));
		return br;
	}
	return hbr;
}

//判断是否有预览窗口被双击
int CPanel::IsDbled()
{
	for(int i=0;i<m_Num;i++)
	{
		if(m_pList[i].m_Dbled)
			return i;
	}
	return -1;
}

void CPanel::UpdateAllPreView()
{
	for(int i=0;i<m_Num;i++)
	{
		if(m_pList[i].m_ShowImage)
		{
			VCAUpdateVideoPreview(i,m_pList[i].m_hWnd);
		}
	}
}
