// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__D71216FD_D166_4CBC_BD9A_3D1429541AC8__INCLUDED_)
#define AFX_SERVERDLG_H__D71216FD_D166_4CBC_BD9A_3D1429541AC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CustomButton.h"
#include "SysSetting.h"
#include "OprManage.h"
/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog


#define CM_RECEIVED  WM_USER+1001

class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
public:
	void OnButtonDown(UINT nID);
	void OnReceived();
	

	SOCKET  m_Socket;		//定义套接字
	char*	m_BmpData;		//位图数据指针
	char*   m_TempData;		//临时数据指针
	char*   m_Header;		//临时指针
	BOOL    m_ShowBmp;		//是否显示位图
	int     m_BmpSize;		//记录位图大小
	int     m_RecSize;		//实际接收的大小
	CString m_ClientIP;		//客户端IP
	UINT    m_ClientPort;	//客户端端口
	WORD    m_LeftTopX;		//位图在屏幕中的x轴坐标
	WORD    m_LeftTopY;		//位图在屏幕中的y轴坐标




	// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CCustomButton	m_SysSetting;
	CCustomButton	m_Quit;
	CCustomButton	m_OperatorMge;
	CCustomButton	m_BtUp;
	CCustomButton	m_BtRight;
	CCustomButton	m_BtRestore;
	CCustomButton	m_BtLeft;
	CCustomButton	m_BtDown;
	CStatic	m_BK;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void ShowImage();
	afx_msg void OnSyssetting();
	afx_msg void OnOperatormge();
	afx_msg void OnQuit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__D71216FD_D166_4CBC_BD9A_3D1429541AC8__INCLUDED_)
