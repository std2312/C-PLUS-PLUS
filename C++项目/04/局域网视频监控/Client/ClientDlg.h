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

	SOCKET  m_Socket;		//�ͻ����׽���
	CString m_ServerIP;		//������IP
	int     m_X,m_Y;		//ץȡ��Ļ����ʼ����
	WORD    m_RecvX,m_RecvY;//�յ�������������ץȡ��Ļ����ʼ����
	BOOL	m_Confirm;		//ȷ����Ϣ
	int     m_FrameIndex;	//��¼����
	int     mod;			//��¼����
	int     count;			//ÿһ��λͼ�ֱ�������
	int     bmpsize;		//λͼ��ʵ�ʴ�С
	char*	pSendBuf;		//���ͻ�����ָ��
	char*	pHeader;		//��ʱָ��
	sockaddr_in  addr1;		//�׽��ֵ�ַ
	BOOL    m_Received;		//�Ƿ���յ�������������ȷ����Ϣ
	int     m_Counter;		//������

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
