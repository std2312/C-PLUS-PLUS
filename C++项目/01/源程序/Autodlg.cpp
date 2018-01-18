// Autodlg.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
#include "Autodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutodlg dialog


CAutodlg::CAutodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutodlg)
	//}}AFX_DATA_INIT
}


void CAutodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutodlg)
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_StopTime);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_StartTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutodlg, CDialog)
	//{{AFX_MSG_MAP(CAutodlg)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_AMPLITUDE, OnAmplitude)
	ON_BN_CLICKED(IDC_HORIZONTAL, OnHorizontal)
	ON_BN_CLICKED(IDC_VERTICAL, OnVertical)
	ON_BN_CLICKED(IDC_TIMECHECK, OnTimecheck)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutodlg message handlers

BOOL CAutodlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CButton* pButton = (CButton*)GetDlgItem(IDC_AMPLITUDE);
	pButton->SetCheck(1);
	m_Num = 0;
	m_Time  = FALSE;
	m_Count = FALSE;
	GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAutodlg::OnOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CAutodlg::OnAmplitude() 
{
	// TODO: Add your control notification handler code here
	CButton* pAButton = (CButton*)GetDlgItem(IDC_AMPLITUDE);
	pAButton->SetCheck(1);	
	CButton* pHButton = (CButton*)GetDlgItem(IDC_HORIZONTAL);
	pHButton->SetCheck(0);
	CButton* pVButton = (CButton*)GetDlgItem(IDC_VERTICAL);
	pVButton->SetCheck(0);
	m_Num = 0;
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t设置广角监控\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CAutodlg::OnHorizontal() 
{
	// TODO: Add your control notification handler code here
	CButton* pAButton = (CButton*)GetDlgItem(IDC_AMPLITUDE);
	pAButton->SetCheck(0);	
	CButton* pHButton = (CButton*)GetDlgItem(IDC_HORIZONTAL);
	pHButton->SetCheck(1);
	CButton* pVButton = (CButton*)GetDlgItem(IDC_VERTICAL);
	pVButton->SetCheck(0);
	m_Num = 1;
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t设置水平监控\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CAutodlg::OnVertical() 
{
	// TODO: Add your control notification handler code here
	CButton* pAButton = (CButton*)GetDlgItem(IDC_AMPLITUDE);
	pAButton->SetCheck(0);	
	CButton* pHButton = (CButton*)GetDlgItem(IDC_HORIZONTAL);
	pHButton->SetCheck(0);
	CButton* pVButton = (CButton*)GetDlgItem(IDC_VERTICAL);
	pVButton->SetCheck(1);
	m_Num = 2;
	CTime m_LogTime = CTime::GetCurrentTime();
	CString strText;
	strText.Format("%s\t%s\t设置垂直监控\r\n",m_UserName,
		m_LogTime.Format("%y-%m-%d %H:%M:%S"));
	CFile file;
	file.Open(m_LogPath,CFile::modeWrite);
	file.SeekToEnd();
	file.Write(strText,strText.GetLength());
	file.Close();
}

void CAutodlg::OnTimecheck() 
{
	// TODO: Add your control notification handler code here
	m_Count = !m_Count;
	if(m_Count)
	{
		CButton* pButton = (CButton*)GetDlgItem(IDC_TIMECHECK);
		pButton->SetCheck(1);
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(TRUE);
		m_Time = TRUE;
		CTime m_LogTime = CTime::GetCurrentTime();
		CString strText;
		strText.Format("%s\t%s\t设置定时监控\r\n",m_UserName,
			m_LogTime.Format("%y-%m-%d %H:%M:%S"));
		CFile file;
		file.Open(m_LogPath,CFile::modeWrite);
		file.SeekToEnd();
		file.Write(strText,strText.GetLength());
		file.Close();
	}
	else
	{
		CButton* pButton = (CButton*)GetDlgItem(IDC_TIMECHECK);
		pButton->SetCheck(0);
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
		m_Time = FALSE;
	}
}

void CAutodlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Time)
	{
		CTime time= CTime::GetCurrentTime();
		m_StartTime.GetTime(starttime);
		m_StopTime.GetTime(stoptime);
		
		if(time == starttime)
		{
			OnOK();		
			KillTimer(1);
		}
	}
	CDialog::OnTimer(nIDEvent);
}
