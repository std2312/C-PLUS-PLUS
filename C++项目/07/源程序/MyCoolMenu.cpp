// MyCoolMenu.cpp: implementation of the CMyCoolMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyCoolMenu.h"
#include "bbb.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern CBbbApp theApp;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyCoolMenu::CMyCoolMenu()
{
	index = 0;
	m_ImageList.Create(32,32,ILC_COLOR32,0,0);
	m_ImageList.Add(theApp.LoadIcon(IDI_ICON1));
}

CMyCoolMenu::~CMyCoolMenu()
{
	index = 0;
}
/**********************************************************
��  ��  ��: GetImageFromToolBar
��      ��: �ӹ�������ȡ��ͼƬ
��  ��  ��: UINT uToolBarID, CSize sz, CImageList *pImageList,  CUIntArray *uIDArray
��	��  ֵ: ���� ImageCount
***********************************************************/
int		CMyCoolMenu::GetImageFromToolBar(UINT uToolBarID, CSize sz, CImageList *pImageList,  CUIntArray *uIDArray)
{
	if(uToolBarID <= 0 || pImageList == NULL || uIDArray == NULL)
		return -1;
	CToolBar wndToolBar;
	if(!wndToolBar.Create(AfxGetMainWnd()) || !wndToolBar.LoadToolBar(uToolBarID))
	{
		return -1;
	}
	int nCount = wndToolBar.GetCount();
	if(nCount <= 0)
	{
		return -1;
	}
	pImageList->Create(uToolBarID, sz.cx, sz.cy, RGB(192, 192, 192));
	int nImageCount = pImageList->GetImageCount();
	for(int i = 0; i < nCount; i ++)
	{
		UINT uID = wndToolBar.GetItemID(i);
		if(uID != ID_SEPARATOR)
		{
			uIDArray->Add(uID);
		}
	}
	int nSize = uIDArray->GetSize();
	ASSERT(nSize == nImageCount);
	return nSize;
}
/**********************************************************
��  ��  ��: GetIconIndexByID
��      ��: ��ImageList ��ȡ��ͼ�������
��  ��  ��: UINT uID
��	��  ֵ: �ɹ�ʱ�������������򷵻�-1
***********************************************************/
int	CMyCoolMenu::GetIconIndexByID(UINT uID)
{	
	for(int i = 0; i < m_menuIDs.GetSize(); i ++)
	{
		if(uID == m_menuIDs[i])
		{
			ASSERT(i < m_ImageList.GetImageCount());
			return i;
		}
	}
	return -1;
}
/**********************************************************
��  ��  ��: ChangeMenuStyle
��      ��: �ı����˵��ķ��
��  ��  ��: HMENU hMenu, BOOL bTop
��	��  ֵ: BOOL,dndn�ɹ�ʱ�����棬ʧ��ʱ����
***********************************************************/
BOOL	CMyCoolMenu::ChangeMenuStyle(HMENU hMenu, BOOL bTop = FALSE)
{
	CMenu *pMenu = CMenu::FromHandle(hMenu);
	if(pMenu != NULL)
	{
		//CMenuItemContext array[50];
		
		for(UINT i = 0; i < pMenu->GetMenuItemCount(); i ++)
		{
			//CMenuItemContext * lpMenu = new CMenuItemContext();
			lpMenu[index].nMenuID = pMenu->GetMenuItemID(i);
			if(lpMenu[index].nMenuID < 0 && bTop)
			{
				lpMenu[index].nMenuID = -2;
			}
			pMenu->GetMenuString(i, lpMenu[index].strText, MF_BYPOSITION);
			pMenu->ModifyMenu(i,  MF_OWNERDRAW|MF_BYPOSITION |MF_STRING,//MF_BYPOSITION |
				lpMenu[index].nMenuID,LPCTSTR(&lpMenu[index]));
			CMenu *pSubMenu = pMenu->GetSubMenu(i);
			if(pSubMenu && lpMenu[index].nMenuID != -2 && !bTop)
			{
				lpMenu[index].nMenuID = -1;
			}
			index += 1;
			//delete (lpMenu);
			if(pSubMenu)
			{
				ChangeMenuStyle(pSubMenu->GetSafeHmenu());
			}
			

		}
		

	}
	return TRUE;
}
/**********************************************************
��  ��  ��: AttachMenu
��      ��: ����ǰ���ڵĲ˵����ҵĲ˵�����
��  ��  ��: HMENU hMenu,UINT uToolBarID,CSize sz
��	��  ֵ: BOOL,dndn�ɹ�ʱ�����棬ʧ��ʱ����
***********************************************************/
BOOL	CMyCoolMenu::AttachMenu(HMENU hMenu,UINT uToolBarID,CSize sz)
{
	Attach(hMenu);
	ChangeMenuStyle(hMenu, TRUE);//GetSafeHmenu()
//	GetImageFromToolBar(uToolBarID, sz, &m_ImageList, &m_menuIDs);
	return TRUE;
}
/**********************************************************
��  ��  ��: AddToolBar
��      ��: ���б����
��  ��  ��: UINT uToolBarID, CSize sz
��	��  ֵ: ������ӵĸ���
***********************************************************/
UINT CMyCoolMenu::AddToolBar(UINT uToolBarID, CSize sz=CSize(16,15))
{
	CImageList Image;
	CUIntArray IDArray;
	int nRet = GetImageFromToolBar(uToolBarID, sz, &Image, &IDArray);
	if(nRet > 0)
	{
		for(int i = 0; i < Image.GetImageCount(); i ++)
		{
			HICON hIcon = Image.ExtractIcon(i);
			if(hIcon != NULL)
			{
				m_ImageList.Add(hIcon);
				m_menuIDs.Add(IDArray[i]);
			}
		}
	}
	return nRet;
	
}
/**********************************************************
��  ��  ��: DrawBestRect
��      ��: ������������Ч����
��  ��  ��: CDC *pDC, CRect rect, COLORREF cr1,COLORREF cr2, BOOL bHor
��	��  ֵ: NULL
***********************************************************/
void CMyCoolMenu::DrawBestRect(CDC *pDC, CRect rect, COLORREF cr1,COLORREF cr2, BOOL bHor)
{
	int r1 = GetRValue(cr1);//Red color1
	int g1 = GetGValue(cr1);//Green color1
	int b1 = GetBValue(cr1);//blue color1
	int r2 = GetRValue(cr2);//red color2
	int g2 = GetGValue(cr2);//green color2
	int b2 = GetBValue(cr2);//blue color2
	if(bHor)
	{
		float dr = ((float)(r2 - r1))/(float)(rect.Width());
		float dg = ((float)(g2 - g1))/(float)(rect.Width());
		float db = ((float)(b2 - b1))/(float)(rect.Width());
		for(int i = rect.left; i < rect.right; i ++)
		{
			int r = r1 + (int)(dr*((float)(i - rect.left)));
			int g = g1 + (int)(dg*((float)(i - rect.left)));
			int b = b1 + (int)(db*((float)(i - rect.left)));
			CPen pen(PS_SOLID, 1, RGB(r, g, b));
			CPen *old = pDC->SelectObject(&pen);
			pDC->MoveTo(i, rect.top);
			pDC->LineTo(i, rect.bottom);
			pDC->SelectObject(old);
		}
	}
	else
	{
		float dr = ((float)(r2 - r1))/(float)(rect.Height());
		float dg = ((float)(g2 - g1))/(float)(rect.Height());
		float db = ((float)(b2 - b1))/(float)(rect.Height());
		for(int i = rect.top; i < rect.bottom; i ++)
		{
			int r = r1 + (int)(dr*((float)(i - rect.top)));
			int g = g1 + (int)(dg*((float)(i - rect.top)));
			int b = b1 + (int)(db*((float)(i - rect.top)));
			CPen pen(PS_SOLID, 1, RGB(r, g, b));
			CPen *old = pDC->SelectObject(&pen);
			pDC->MoveTo(rect.left, i);
			pDC->LineTo(rect.right, i);
			pDC->SelectObject(old);
		}
	}
}
/**********************************************************
��  ��  ��: DrawTop
��      ��: ����˲˵�
��  ��  ��: CDC *pDC,CRect rect,BOOL bSelected
��	��  ֵ: NULL
***********************************************************/
void CMyCoolMenu::DrawTop(CDC *pDC,CRect rect,BOOL bSelected)
{	
	if(bSelected)
	{
		
		pDC->SelectStockObject(BLACK_PEN);
		pDC->Rectangle(&rect);//a rectangle
		rect.DeflateRect(1, 1);
		pDC->FillSolidRect(&rect, RGB(185, 185, 255));
	}
	else
	{		
		CRect rtWnd;		
		AfxGetMainWnd()->GetClientRect(&rtWnd);
		CRect rcGray(rect);
		rcGray.left = 413;
		rcGray.right = rtWnd.right + 4;		
		pDC->FillSolidRect(&rcGray,RGB(255, 176, 55));//190 125 255

		CRect rcWhite(rect);		
		pDC->FillSolidRect(&rcWhite,RGB(255, 176, 55));	
		
	}
}
/**********************************************************
��  ��  ��: DrawBGColor
��      ��: �˵���ı������������
��  ��  ��: CDC* pDC, CRect rect, BOOL bSelected
��	��  ֵ: NULL
***********************************************************/
void CMyCoolMenu::DrawBGColor(CDC* pDC, CRect rect, BOOL bSelected)
{
	if(bSelected)
	{
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SelectStockObject(BLACK_PEN);
		pDC->Rectangle(&rect);
		rect.DeflateRect(1, 1);
		DrawBestRect(pDC,rect,0xf100,0xff20ff,TRUE);
	}
	else
	{
		CRect rcGray(rect);
		rcGray.right = rcGray.left + Public_Area;
		pDC->FillSolidRect(&rcGray, RGB(0x000000DB, 0x000000D8, 0x000000D1));
		CRect rcWhite(rect);
		rcWhite.left = rcGray.right;
		pDC->FillSolidRect(&rcWhite,RGB(0x000000F9, 0x000000F8, 0x000000F7));
	}
}
/**********************************************************
��  ��  ��: DrawIcon
��      ��: ����ͼ��
��  ��  ��: CDC* pDC, CRect rect, UINT uIndex, BOOL IsEnabled
��	��  ֵ: NULL
***********************************************************/
void	CMyCoolMenu::DrawIcon(CDC* pDC, CRect rect, UINT uIndex, BOOL IsEnabled)
{
	rect.DeflateRect(3, 3, 3, 3);
	UINT	uStyle =ILD_TRANSPARENT; //CImageList::Draw()����λͼ�ķ��
	if(IsEnabled)
	{
		uStyle |=ILD_BLEND50; //�˵���Ч����λͼҲҪ��������
	}
	else
	{
		uStyle |=ILD_BLEND25	;
	}
	m_ImageList.Draw(pDC, uIndex, CPoint(rect.left, rect.top), uStyle);
	
}
/**********************************************************
��  ��  ��: DrawText
��      ��: �����˵�����ı�
��  ��  ��: CDC* pDC, CRect rect, CString sText
��	��  ֵ: NULL
***********************************************************/
void CMyCoolMenu::DrawText(CDC* pDC, CRect rect, CString sText)
{
	rect.DeflateRect(8,0,0,0);
	pDC->DrawText(sText, &rect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
}
/**********************************************************
��  ��  ��: DrawGray
��      ��: �����Ч�˵�����ı�
��  ��  ��: CDC* pDC, CRect rect, CString sText
��	��  ֵ: NULL
***********************************************************/
void CMyCoolMenu::DrawGray(CDC* pDC, CRect rect, CString sText)
{
	rect.DeflateRect(8, 0, 0, 0);
	rect.DeflateRect(8, 0, 0, 0);
	CRect	rt(rect);
	int nMode =pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(127,127,127));
	pDC->DrawText("   "+sText,&rect,DT_EXPANDTABS|DT_VCENTER|DT_SINGLELINE);
	
}
/**********************************************************
��  ��  ��: DrawItem
��      ��: �ֿ���ÿһ�˵���
��  ��  ��: LPDRAWITEMSTRUCT  lpDIS���˵�������
��	��  ֵ: NULL
***********************************************************/
void	CMyCoolMenu::DrawItem(LPDRAWITEMSTRUCT  lpDIS)
{	
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);	// get dc
	VERIFY(pDC);pDC->SetBkMode(TRANSPARENT);// get position
	CRect rcItem = lpDIS->rcItem;// get states
	UINT uState = lpDIS->itemState;	// the data of menu item is NULL then return
	if(lpDIS->itemData == NULL)	return;
	CString strText     = ((CMenuItemContext*)(lpDIS->itemData))->strText;
	UINT nMenuID        = ((CMenuItemContext*)(lpDIS->itemData))->nMenuID;
	CRect rcIcon(rcItem);
	rcIcon.right = rcIcon.left ;//+ Public_Area;
	CRect rcText(rcItem);
	rcText.left  = rcIcon.right;
	switch(nMenuID)
	{
	case -2:// -2:����˵���   
		if(uState&ODS_SELECTED)
		{
			DrawTop(pDC,rcItem,TRUE);
		}
		else
		{
			DrawTop(pDC,rcItem,FALSE);
		}
		DrawText(pDC,rcItem,strText);
		break;
	case -1://-1:�����˵�  
		strText= "\t   "+strText;
		if(uState&ODS_SELECTED)
			DrawBestRect(pDC,rcItem,0xff00ff,0xfffff,TRUE);
		else
			DrawTop(pDC,rcItem,TRUE);
		//DrawTop(pDC,rcItem,FALSE);
		DrawText(pDC,rcText,strText);
		
		break;
	case 0://0:�ָ���  
		rcText.top =rcText.Height()/2+rcText.top ;
		rcText.bottom =rcText.top +2;
		rcText.left +=2;
		rcText.right -=2;
		pDC->Draw3dRect(rcText,RGB(64,0,128),RGB(255,255,255));
		break;
	default://>0:һ��Ĳ˵�	
		
		if(uState&ODS_SELECTED)//��ѡ��
		{
			rcItem.left -= 20;
			rcItem.right -= 0;
			DrawBGColor(pDC,rcItem,TRUE);
		}
		else
		{
			rcItem.left -= 20;
			rcItem.right -= 0;
			DrawBGColor(pDC,rcItem,FALSE);//
		}
		
		int nIndex = GetIconIndexByID(nMenuID);
		if(uState&ODS_GRAYED)
		{
			if(nIndex >= 0) 
			{
				DrawIcon(pDC,rcItem,nIndex,TRUE);
			}
			DrawGray(pDC,rcText,strText);
			break;
		}
		else
		{
			if(nIndex >= 0) 
			{
				DrawIcon(pDC,rcItem,nIndex,FALSE);
			}
		}
		if(uState&ODS_CHECKED)//�Ǳ�check����,
		{
			
			DrawText(pDC,rcText,"   "+strText);//��ǰ״̬��check!
			break;
		}
		else
		{
			DrawText(pDC,rcText,"      "+strText);//δѡȡ
			break;
		}
		
		break;
	}
}
/**********************************************************
��  ��  ��: MeasureItem
��      ��: ����ÿһ��ķ���
��  ��  ��: LPMEASUREITEMSTRUCT lpMISҪ�õ��Ľṹ
��	��  ֵ: NULL
***********************************************************/
void	CMyCoolMenu::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{	
	lpMIS->itemWidth = 130;
	lpMIS->itemHeight = 26;
	UINT nMenuID= ((CMenuItemContext*)(lpMIS->itemData))->nMenuID;
	switch(nMenuID)
	{
	case -2:// -2:����˵���  
		lpMIS->itemWidth =((CMenuItemContext*)(lpMIS->itemData))->strText.GetLength()*5;
		break;
	case -1://-1:�����˵�  
		lpMIS->itemWidth =((CMenuItemContext*)(lpMIS->itemData))->strText.GetLength()*10;
		break;
	case 0://0:�ָ���
		lpMIS->itemHeight =10;
		break;
	default://>0:һ��Ĳ˵�		
		break;	
	}
}


