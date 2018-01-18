// PrintView.h: interface for the CPrintView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTVIEW_H__693E2EFA_032B_493D_9EBB_1258C851C4BC__INCLUDED_)
#define AFX_PRINTVIEW_H__693E2EFA_032B_493D_9EBB_1258C851C4BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ADOView.h"

class CPrintView : public CADOView  
{
public:
	void SetFont(CFont &font);
	void SetPrint(BOOL isPrint);
	void SetBountsRect(RECT *plotArea);
	int BasterPageRows(int rows);
	void EndPrint();
	void BeginPrint();
	void SetPrinterRate(float xRate, float yRate);
	void SetTextFormate(UINT nFormat);
	DWORD GetCurrentWidth(int iSubItem);
	void DrawSubItem(int iItem, int iSubItem, CString& con);
	void SetTableHeader(CString &header);
	void SetRowHigth(int higth);
	void SetBorder(int width);
	void ShowColumn();
	void InsertColumn(CString field, int width);
	BOOL DeleteAllRows();
	BOOL SetRow(int row, CString* strArray, int count);
	CPrintView(CDC * dc);
	virtual ~CPrintView();

private:
	BOOL m_IsPrint;
	RECT m_PlotArea;
	int m_PagesCount;
	int m_RowSizePerPage;
	float m_YRate;
	float m_XRate;
	UINT m_TextFormat;
	int m_RowCount;
	CString m_TableHeader;
	int m_RowHigth;
	int m_BorderWidth;
	int m_ColumnCount;
	CWordArray m_FieldsWidth;
	CStringArray m_FieldsName;
	CDC* m_pPrinterDC;
	CFont m_Font;

};

#endif // !defined(AFX_PRINTVIEW_H__693E2EFA_032B_493D_9EBB_1258C851C4BC__INCLUDED_)
