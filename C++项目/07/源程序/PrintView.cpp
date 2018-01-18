// PrintView.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "PrintView.h"
#include "Report.h"
#include "PrintDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintView
IMPLEMENT_DYNCREATE(CPrintView, CScrollView)

BEGIN_MESSAGE_MAP(CPrintView, CScrollView)
	//{{AFX_MSG_MAP(CPrintView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()



CPrintView::CPrintView()
{
	ispreview = false;
}

CPrintView::~CPrintView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView drawing

void CPrintView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	CDC* pDC;
	pDC=this->GetDC();
	//逻辑设备大小
	caps.cx=pDC->GetDeviceCaps(HORZRES);
	caps.cy=pDC->GetDeviceCaps(VERTRES);
}

void CPrintView::OnDraw(CDC* pDC)
{
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//pInfo->m_pPD->GetDevMode();
	

	caps.cx=pDC->GetDeviceCaps(HORZRES);
	caps.cy=pDC->GetDeviceCaps(VERTRES);

	DrawReportTitle( pDC,report.title,false);
	
	report.fieldcount = 6;

	DrawBody(pDC,false);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView diagnostics

void CPrintView::DrawReportTitle(CDC* pDC,LPCSTR r_title,bool printed)
{
	PrintRate factrate;
	factrate.x =1.0;
	factrate.y =1.0;
	if (printed ==true)
	{
		factrate = rate;
	}	
	titlefont.CreatePointFont(200,"黑体",pDC);
	CRect rect;
	GetClientRect(rect);
	CString temp,line;
	pDC->SelectObject(&titlefont);
	line = "";

	temp = r_title;
	int len =temp.GetLength();
	for (int i = 0; i<len;i++)
	{
		line += "_";
	}

	//打印标题
	if (printed)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->DrawText(line,CRect(0,factrate.y*20, caps.cx,factrate.y*100),DT_CENTER|DT_TOP|DT_SINGLELINE);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->DrawText(r_title,CRect(0,factrate.y*10, caps.cx,factrate.y*100),DT_CENTER|DT_TOP|DT_SINGLELINE);	
	}
	else
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->DrawText(line,CRect(0,20, rect.right,100),DT_CENTER|DT_TOP|DT_SINGLELINE);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->DrawText(r_title,CRect(0,10, rect.right,100),DT_CENTER|DT_TOP|DT_SINGLELINE);

	}
	titlefont.DeleteObject();
}
/***********************************************************************************************
说明:  打印报表字段
***********************************************************************************************/
void CPrintView::DrawBody(CDC *pDC,bool printed)
{
	PrintRate factrate;
	factrate.x =1.0;
	factrate.y =1.0;
	if (printed ==true)
	{
		factrate = rate;
	}
	bodyfont.CreatePointFont(100,"宋体",pDC);
	CRect rect;
	GetClientRect(rect);
	pDC->SelectObject(&bodyfont);
	//计算字段的总长度
	int fieldwidth = 0;
	for (int index = 0; index <report.fieldcount;index++)
	{
		fieldwidth +=  pDC->GetTextExtent(report.fields[index]).cx;
	}
	//计算字段间距
	int fieldinterval = 0;
	if (printed)
		fieldinterval = (caps.cx- factrate.x*report.lmargin- factrate.x*(report.rmargin+fieldwidth))/(report.fieldcount-1);
	else
		fieldinterval = (rect.right- factrate.x*report.lmargin- factrate.x*report.rmargin-fieldwidth)/(report.fieldcount-1);

	int temp = 0;

	//打印字段
	for (int i =0; i< report.fieldcount;i++)
	{
		if (printed)
		{
			pDC->TextOut( factrate.x*report.lmargin+ (i*fieldinterval+temp),factrate.x*80,report.fields[i]);
			
			//pDC->TextOut(factrate.x*(report.lmargin)+ (i*fieldinterval+temp),factrate.x*80,report.fields[i]);
			temp+= factrate.x*pDC->GetTextExtent(report.fields[i]).cx;
		}
		else
		{
			pDC->TextOut((report.lmargin)+ i*fieldinterval+temp,80,report.fields[i]);
			temp+= pDC->GetTextExtent(report.fields[i]).cx;				
		}
	}
	if (printed)
	{
		pDC->MoveTo( factrate.x *report.lmargin, factrate.x*100);
		pDC->LineTo(factrate.x *report.lmargin +temp+(i-1)*fieldinterval-50,factrate.x*100); 
	}
	else
	{
		pDC->MoveTo( report.lmargin, 100);
		pDC->LineTo((report.lmargin)+ temp+(i-1)*fieldinterval,100); 	

	}

	//绘制报表数据
	if (report.m_plist != NULL)
	{
		for (int row =0; row< report.m_plist->GetItemCount();row++)
		{
			temp = 0;
			for (int col = 0;col< report.fieldcount;col++)
			{
				if (printed)
				{
					pDC->TextOut(factrate.x*report.lmargin+ col*fieldinterval+temp, factrate.x*( 120+ row* report.verinterval),report.m_plist->GetItemText(row,col));
					temp+=  factrate.x*pDC->GetTextExtent(report.fields[col]).cx;			
				}
				else
				{					
					pDC->TextOut(report.lmargin+ col*fieldinterval+temp,( 120+ row* report.verinterval),report.m_plist->GetItemText(row,col));
					temp+= pDC->GetTextExtent(report.fields[col]).cx;								
				}
			}
		}
	}
	bodyfont.DeleteObject();
}

void CPrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	if(pInfo->m_nCurPage==1)
	{
		//画主标题
		DrawReportTitle( pDC,report.title,true);
		//画报表主体数据
		DrawBody(pDC,true);
	}
	else
	{	
		DrawBody(pDC,true);
	}
	//PrintPage(pDC,pInfo);
}

void CPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	LPDEVMODE mode;
	//pInfo->m_pPD->GetDevMode();
	mode=pInfo->m_pPD->GetDevMode();
	//打印纸大小
	pagesize.cx =mode->dmPaperLength;
	pagesize.cy= mode->dmPaperWidth;
	//逻辑设备大小

	caps.cx=pDC->GetDeviceCaps(HORZRES);
	caps.cy=pDC->GetDeviceCaps(VERTRES);

	//比率
	rate.x=(float)pagesize.cx/(float)caps.cx;
	rate.y=(float)pagesize.cy/(float)caps.cy;
	//打印页数
	//pInfo->SetMaxPage(100);
	ispreview = true;	
	//Deffont.CreatePointFont(280*Ratio.x,"宋体",NULL);
//	CScrollView::OnBeginPrinting(pDC, pInfo);
}

void CPrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CScrollView::OnPrepareDC(pDC, pInfo);
}

void CPrintView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	
	//CScrollView::OnEndPrinting(pDC, pInfo);
}

BOOL CPrintView::PreCreateWindow(CREATESTRUCT& cs) 
{
	
	return CScrollView::PreCreateWindow(cs);
}

BOOL CPrintView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	return DoPreparePrinting(pInfo);
	//return CScrollView::OnPreparePrinting(pInfo);
}

#ifdef _DEBUG
void CPrintView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPrintView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPrintDoc* CPrintView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDoc)));
	return (CPrintDoc*)m_pDocument;
}
#endif //_DEBUG

void CPrintView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView) 
{
	ispreview = false;
	CScrollView::OnEndPrintPreview(pDC, pInfo, point, pView);
}
