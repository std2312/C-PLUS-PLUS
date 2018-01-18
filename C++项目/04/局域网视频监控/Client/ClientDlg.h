// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__90DF23C1_6DC0_4F1E_85C3_34F34153A9C5__INCLUDED_)
#define AFX_CLIENTDLG_H__90DF23C1_6DC0_4F1E_85C3_34F34153A9C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	int  SendData(UINT index, int mod , int bmpsize , int frames,char *pSendBuf, sockaddr_in &addr);
	void OnReceived();
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

	SOCKET  m_Socket;		//客户端套接字
	CString m_ServerIP;		//服务器IP
	int     m_X,m_Y;		//抓取屏幕的起始坐标
	WORD    m_RecvX,m_RecvY;//收到服务器发来的抓取屏幕的起始坐标
	BOOL	m_Confirm;		//确认信息
	int     m_FrameIndex;	//记录索引
	int     mod;			//记录余数
	int     count;			//每一个位图分报的数量
	int     bmpsize;		//位图的实际大小
	char*	pSendBuf;		//发送缓冲区指针
	char*	pHeader;		//临时指针
	sockaddr_in  addr1;		//套接字地址
	BOOL    m_Received;		//是否接收到服务器发来的确认信息
	int     m_Counter;		//记数器

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__90DF23C1_6DC0_4F1E_85C3_34F34153A9C5__INCLUDED_)
