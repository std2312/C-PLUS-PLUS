// PrintView.cpp: implementation of the CPrintView class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hrms.h"
#include "PrintView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPrintView::CPrintView(CDC * dc)
{
	m_pPrinterDC = dc;
	m_ColumnCount = 0;
	m_BorderWidth = 10;
	m_RowCount = 0;
	m_RowHigth = 50;
	m_TextFormat =  DT_CENTER | DT_VCENTER | DT_SINGLELINE;
	m_XRate = 1;
	m_YRate = 1;
	m_RowSizePerPage = 20;
	m_PagesCount = 0;
	m_PlotArea.left = 0;
	m_PlotArea.top = 0;
	m_PlotArea.bottom = dc->GetDeviceCaps(VERTRES);
	m_PlotArea.right = dc->GetDeviceCaps(HORZRES);
	m_IsPrint = FALSE;
	m_Font.CreatePointFont(110,"ËÎÌו", m_pPrinterDC);
	m_pPrinterDC->SelectObject(&m_Font);
}

CPrintView::~CPrintView()
{}

BOOL CPrintView::SetRow(int row, CString *strArray, int count)
{
	CString str;
	for(int i = 0; i<count; i++)
		DrawSubItem(row + 1, i, strArray[i]);
	str.Format("%.2f", CPayListDlg::GetTotalSum(strArray[2], atoi(strArray[0]), atoi(strArray[1])));
	DrawSubItem(row + 1, i, str);
	return TRUE;
}

BOOL CPrintView::DeleteAllRows()
{
	return TRUE;
}

void CPrintView::InsertColumn(CString field, int width)
{
	m_FieldsName.Add(field);
	m_FieldsWidth.Add(width);
	m_ColumnCount++;
}

void CPrintView::ShowColumn()
{
	RECT textRc;

	textRc.left = m_PlotArea.left + int(m_BorderWidth*m_XRate);
	textRc.top = m_PlotArea.top + int(m_BorderWidth*m_YRate);
	textRc.right = m_PlotArea.right - int(m_BorderWidth*m_XRate);
	textRc.bottom = int(m_RowHigth*m_YRate) + int(m_BorderWidth*m_YRate);

	m_pPrinterDC->Rectangle(&textRc);
	m_pPrinterDC->DrawText(m_TableHeader, &textRc, m_TextFormat);
	for(int i=0; i < m_ColumnCount; i++)
		DrawSubItem(0, i, m_FieldsName.GetAt(i));

}

void CPrintView::SetBorder(int width)
{
	m_BorderWidth = width;
}

void CPrintView::SetRowHigth(int higth)
{
	m_RowHigth = higth;
}

void CPrintView::SetTableHeader(CString &header)
{
	m_TableHeader = header;
}

void CPrintView::DrawSubItem(int iItem, int iSubItem, CString &con)
{
	RECT rc = {0};
	DWORD curWidth = GetCurrentWidth(iSubItem);
	DWORD width = 0;

	rc.left = long(m_BorderWidth*m_XRate) + long(curWidth*m_XRate);
	rc.top = long((iItem+1) * m_RowHigth*m_YRate) + long(m_BorderWidth*m_YRate);
	width = m_FieldsWidth.GetAt(iSubItem);

	if(65535 == width)
		rc.right = long(m_PlotArea.right - m_BorderWidth*m_XRate);
	else
		rc.right = long(rc.left + width*m_XRate);
	rc.bottom = rc.top + long(m_RowHigth*m_YRate);
	m_pPrinterDC->Rectangle(&rc);
	m_pPrinterDC->DrawText(con, &rc, m_TextFormat);
}

DWORD CPrintView::GetCurrentWidth(int iSubItem)
{
	DWORD width = 0;
	for(int i=0; i<iSubItem; i++)
		width += m_FieldsWidth.GetAt(i);
	return width;
}

void CPrintView::SetTextFormate(UINT nFormat)
{
	this->m_TextFormat = nFormat;
}

void CPrintView::SetPrinterRate(float xRate, float yRate)
{
	m_XRate = xRate;
	m_YRate = yRate;
}

void CPrintView::BeginPrint()
{
	m_pPrinterDC->StartDoc("printstart");
}

void CPrintView::EndPrint()
{
	m_pPrinterDC->EndDoc();
}

int CPrintView::BasterPageRows(int rows)
{
	m_RowSizePerPage = rows;
	return m_RowSizePerPage;
}

void CPrintView::SetBountsRect(RECT *plotArea)
{
	m_PlotArea.bottom = plotArea->bottom;
	m_PlotArea.left = plotArea->left;
	m_PlotArea.right = plotArea->right;
	m_PlotArea.top = plotArea->top;
}

void CPrintView::SetPrint(BOOL isPrint)
{
	m_IsPrint = isPrint;
}

void CPrintView::SetFont(CFont &font)
{
	LOGFONT logFont;
	font.GetLogFont(&logFont);
	m_Font.CreateFontIndirect(&logFont);
	m_pPrinterDC->SelectObject(&m_Font);
}
