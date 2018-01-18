// PhoneRecordDlg.h : header file
//

#if !defined(AFX_PHONERECORDDLG_H__A05E5F7C_E3E0_4F22_9950_C42A2C3378DC__INCLUDED_)
#define AFX_PHONERECORDDLG_H__A05E5F7C_E3E0_4F22_9950_C42A2C3378DC__INCLUDED_
#include "BaseButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordDlg dialog
typedef struct LINESTRUCT
{
	int     nType;
	int     State;
	CString CallerID;
	BOOL    IsReceiving;
//	BOOL    Inited;
} *lpLINESTRUCT;

enum CHANNEL_STATE {
	CH_FREE,
	CH_DIAL,
	CH_INCEPT,     //接到电话
	CH_CHECKSIG,
	CH_CONNECT,    //对方摘机，可以进行通话
	CH_BUSY,       //检测到对方占线的忙音
	CH_NOBODY,     //振铃若干次，无人接听电话
	CH_NOSIGNAL,   //没有信号音
	CH_NODIALTONE, //没有拨号音
	CH_NORESULT,   //尚未得出结果
};



class CPhoneRecordDlg : public CDialog
{
// Construction
public:
	void AddToDataBase(CString name,CTime time);
	void Record(WORD num);
	virtual void OnOK();
	void ReadNumber(WORD nID);
	CPhoneRecordDlg(CWnd* pParent = NULL);	// standard constructor
	CMenu         m_Menu;
	WORD          m_ChanelCount;
	BOOL          m_IsReceiving;
	lpLINESTRUCT  m_pLines;
	CString       m_CurNumber;
	CString       m_CurTime;
	CString       m_Number;
	int           m_CurChanel;  //当前通道
	BOOL          m_IsOffHook;   //是否摘机
	CString       m_RecordFile;
	WORD          m_RecordNum;
	BOOL          m_IsBusy;
// Dialog Data
	//{{AFX_DATA(CPhoneRecordDlg)
	enum { IDD = IDD_PHONERECORD_DIALOG };
	CBaseButton	m_PhoneBook;
	CEdit	m_PhoneNum;
	CComboBox	m_Chanel;
	CBaseButton	m_Dialup;
	CBaseButton	m_Hangup;
	CBaseButton	m_Record;
	CBaseButton	m_PhoneOut;
	CBaseButton	m_PhoneIn;
	CBaseButton	m_Manufacture;
	CListCtrl	m_Grid;
	CBaseButton	m_Employee;
	CBaseButton	m_Client;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPhoneRecordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTray(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnMenushow();
	afx_msg void OnMenuhide();
	afx_msg void OnMenuclose();
	afx_msg void OnMenuphoneout();
	afx_msg void OnMenuphonein();
	afx_msg void OnMenurecord();
	afx_msg void OnMenuclient();
	afx_msg void OnMenuemployees();
	afx_msg void OnMenumanufacture();
	afx_msg void OnMenuabout();
	afx_msg void OnMenuexit();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDialup();
	afx_msg void OnHangup();
	afx_msg void OnPhonebook();
	afx_msg void OnPhonein();
	afx_msg void OnPhoneout();
	afx_msg void OnRecord();
	afx_msg void OnClient();
	afx_msg void OnEmployee();
	afx_msg void OnManufacture();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONERECORDDLG_H__A05E5F7C_E3E0_4F22_9950_C42A2C3378DC__INCLUDED_)
