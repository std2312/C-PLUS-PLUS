#if !defined(AFX_BASEBUTTON_H__DC880CB1_F48D_4976_90BF_21D60C143DA4__INCLUDED_)
#define AFX_BASEBUTTON_H__DC880CB1_F48D_4976_90BF_21D60C143DA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CBaseButton window

class CBaseButton : public CButton
{
// Construction
public:
	CBaseButton(UINT NomalPic=IDB_BUT_UP,UINT MovePic=IDB_BUT_MOVE,UINT DownPic=IDB_BUT_DOWN);
//,UINT EnablePic=IDB_BUT_ENABLED
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	bool Drawit(CDC* pDC,UINT ResID);
	virtual ~CBaseButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBaseButton)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	UINT m_DownPic;
	UINT m_NomalPic;
//	UINT m_EnablePic;
	UINT m_MovePic;
	bool m_IsInRect;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEBUTTON_H__DC880CB1_F48D_4976_90BF_21D60C143DA4__INCLUDED_)
