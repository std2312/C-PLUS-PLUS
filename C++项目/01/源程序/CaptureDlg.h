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


#define FLEFTBAR      1   //��߿�
#define FLEFTTITLE    2   //�����
#define FRIGHTTITLE   4   //�ұ���
#define FMIDTITLE     8   //�м����
#define FRIGHTBAR     16  //�ұ߿�
#define FBOTTOMBAR    32  //�ױ߿�
#define FMINBUTTON    64  //��С����ť
#define FMAXBUTTON    128 //��󻯰�ť
#define FCLOSEBUTTON  256 //�رհ�ť
#define FALL          511 //���б�ʶ
#define MAXNUM        100

//��ť״̬
enum CButtonState{bsNone,bsMin,bsMax,bsRes,bsClose};

class CCaptureDlg : public CDialog
{
public:
	CBitmap      m_BKGround;
	CString      m_Caption;
	BOOL         m_IsMax;
	CButtonState m_ButtonState;     //��ť״̬
	int          m_BorderWidth;     //�߿���
	int          m_BorderHeight;    //�߿�߶�
	int          m_FrameWidth ;     //����3D���
	int          m_FrameHeight;     //����3D�߶�
	int          m_CaptionHeight;   //�������ĸ߶�
	int          m_TitleDrawHeight; //������ʵ�ʵĻ��Ƹ߶�
	int          m_ButtonWidth;     //��ťλͼ���
	int          m_ButtonHeight;    //��ťλͼ�߶�
	COLORREF     m_CapitonColor;    //����������ɫ
	CFont        m_CaptionFont;     //��������
	BOOL         m_IsDrawForm ;
	CRect m_LTitleRc, m_MTitleRc,m_RTitleRc; //��,��,�ұ�����ʾ����
	CRect m_MinRect,m_MaxRect,m_CloseRect;   //��������ť����ʾ����
public:
	int     m_DevNum; //��ǰоƬ��,Ҳ�����ж���·
	BOOL    m_BStop;  //�Ƿ�ֹͣԤ�� 
	CPanel  m_Frame;  //Ԥ�����ڵĸ�����
public:
	unsigned char (*m_pData) [MAXNUM]; //�洢��̨������
	int      m_Len;                    //��̨Э��ʹ�õ��ֽ���
	int      m_ActoinCount;            //��̨���ƶ�����
	int      m_Port;                   //Com�˿�
	CString  m_Setting;                //����
	HANDLE   m_hThread;                //�߳̾��
	UINT     m_Num;
	CTime    m_StopTime;
	BOOL     m_Time;         
    CString  m_LogPath;
	CString  m_UserName;
	CTime    m_LogTime;
public:
	BOOL    m_Kinescope; //�Ƿ�¼��
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
