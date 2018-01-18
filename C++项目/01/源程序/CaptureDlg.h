// CaptureDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_CAPTUREDLG_H__03C7FD01_013C_4EAC_9D74_5CF3316EF48F__INCLUDED_)
#define AFX_CAPTUREDLG_H__03C7FD01_013C_4EAC_9D74_5CF3316EF48F__INCLUDED_
#include "PreView.h"
#include "Panel.h"
#include "StageButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CCaptureDlg dialog


#define FLEFTBAR      1   //左边框
#define FLEFTTITLE    2   //左标题
#define FRIGHTTITLE   4   //右标题
#define FMIDTITLE     8   //中间标题
#define FRIGHTBAR     16  //右边框
#define FBOTTOMBAR    32  //底边框
#define FMINBUTTON    64  //最小化按钮
#define FMAXBUTTON    128 //最大化按钮
#define FCLOSEBUTTON  256 //关闭按钮
#define FALL          511 //所有标识
#define MAXNUM        100

//按钮状态
enum CButtonState{bsNone,bsMin,bsMax,bsRes,bsClose};

class CCaptureDlg : public CDialog
{
public:
	CBitmap      m_BKGround;
	CString      m_Caption;
	BOOL         m_IsMax;
	CButtonState m_ButtonState;     //按钮状态
	int          m_BorderWidth;     //边框宽度
	int          m_BorderHeight;    //边框高度
	int          m_FrameWidth ;     //窗体3D宽度
	int          m_FrameHeight;     //窗体3D高度
	int          m_CaptionHeight;   //标题栏的高度
	int          m_TitleDrawHeight; //标题栏实际的绘制高度
	int          m_ButtonWidth;     //按钮位图宽度
	int          m_ButtonHeight;    //按钮位图高度
	COLORREF     m_CapitonColor;    //标题字体颜色
	CFont        m_CaptionFont;     //标题字体
	BOOL         m_IsDrawForm ;
	CRect m_LTitleRc, m_MTitleRc,m_RTitleRc; //左,中,右标题显示区域
	CRect m_MinRect,m_MaxRect,m_CloseRect;   //标题栏按钮的显示区域
public:
	int     m_DevNum; //当前芯片数,也就是有多少路
	BOOL    m_BStop;  //是否停止预览 
	CPanel  m_Frame;  //预览窗口的父窗口
public:
	unsigned char (*m_pData) [MAXNUM]; //存储云台控制吗
	int      m_Len;                    //云台协议使用的字节数
	int      m_ActoinCount;            //云台控制动作数
	int      m_Port;                   //Com端口
	CString  m_Setting;                //环境
	HANDLE   m_hThread;                //线程句柄
	UINT     m_Num;
	CTime    m_StopTime;
	BOOL     m_Time;         
    CString  m_LogPath;
	CString  m_UserName;
	CTime    m_LogTime;
public:
	BOOL    m_Kinescope; //是否录像
	BOOL    m_Cancel;
	CString m_PathText;
// Construction
public:
	void OnInBrush();
	void OnReBrush();
	void OnInAperture();
	void OnReAperture();
	void OnReLen();
	void OnInLen();
	void OnReFoci();
	void OnInFoci();
	void OnRight();
	void OnLeft();
	void OnDown();
	void OnReset();
	void OnUp();
	void MoveCapture(UINT num);
	void OnCancel();
	CCaptureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCaptureDlg)
	enum { IDD = IDD_CAPTURE_DIALOG };
	CStageButton	m_ReBrush;
	CStageButton	m_InBrush;
	CStageButton	m_InAperture;
	CStageButton	m_ReAperture;
	CStageButton	m_ReLen;
	CStageButton	m_InLen;
	CStageButton	m_ReFoci;
	CStageButton	m_InFoci;
	CStageButton	m_ButtonRight;
	CStageButton	m_ButtonLeft;
	CStageButton	m_ButtonUp;
	CStageButton	m_ButtonDown;
	CMSComm	m_Com;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawCaption();
	void DrawDialog(UINT Flags);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCaptureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	afx_msg void OnSnapshot();
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnBmp();
	afx_msg void OnJpg();
	afx_msg void OnVga();
	afx_msg void OnPci();
	afx_msg void OnSetting();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnControl();
	afx_msg void OnAutomatism();
	afx_msg void OnStop();
	afx_msg void OnKinescope();
	afx_msg void OnPlay();
	afx_msg void OnManage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREDLG_H__03C7FD01_013C_4EAC_9D74_5CF3316EF48F__INCLUDED_)
