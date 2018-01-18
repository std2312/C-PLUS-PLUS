#if !defined(AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_)
#define AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreView window
//定义预览状态,停止,预览,恢复预览
enum PreState  {psStop,psPreview,psRestore};

class CPreView : public CStatic
{
// Construction
public:
	CPreView();

// Attributes
public:
	
// Operations
public:
	BOOL       m_Selected;  //当前是否被选中
	static int m_CurIndex;  //预览窗口当前索引
	int        m_Index;     //本窗口索引
	BOOL	   m_ShowImage; //是否显示图像,即该路是否有信号
	BOOL       m_Dbled;     //双击时窗口是否填充父窗口
	PreState   m_Stop;      //预览状态
	CBitmap    m_Bitmap;    //无信号是显示的位图资源
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreView)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPreView();
	afx_msg void OnPaint();
	// Generated message map functions
protected:
	//{{AFX_MSG(CPreView)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_)
