#if !defined(AFX_STAGEBUTTON_H__F4D2A66A_ACB8_49B8_9876_2C4E14F2EE14__INCLUDED_)
#define AFX_STAGEBUTTON_H__F4D2A66A_ACB8_49B8_9876_2C4E14F2EE14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StageButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStageButton window

//按钮控制类型,上 下 左 右 自动,焦聚减,焦聚增,倍长减,倍长增,光圈减,光圈增,雨刷减,雨刷增
enum  ControlType {ctUp,ctDown,ctLeft,ctRight,ctAuto,ctReFoci,
      ctInFoci,ctReLen,ctInLen,ctReAperture,ctInAperture,ctReBrush,ctInBrush};
class CStageButton : public CButton
{
// Construction
public:
	CStageButton();

// Attributes
public:
	ControlType m_Type;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStageButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStageButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStageButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAGEBUTTON_H__F4D2A66A_ACB8_49B8_9876_2C4E14F2EE14__INCLUDED_)
