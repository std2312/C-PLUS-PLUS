// Playdlg.cpp : implementation file
//

#include "stdafx.h"
#include "capture.h"
#include "Playdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaydlg dialog


CPlaydlg::CPlaydlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlaydlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlaydlg)
	//}}AFX_DATA_INIT
}


void CPlaydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlaydlg)
	DDX_Control(pDX, IDC_PATH, m_Path);
	DDX_Control(pDX, IDC_MEDIAPLAYER1, m_MediaPlay);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlaydlg, CDialog)
	//{{AFX_MSG_MAP(CPlaydlg)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaydlg message handlers

void CPlaydlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fDlg(TRUE,"","",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"AVI|*.avi",this);
	if(fDlg.DoModal()==IDOK)
	{
		CString path = fDlg.GetPathName();
		m_Path.SetWindowText(path);
		m_MediaPlay.Open(path);
		CTime m_LogTime = CTime::GetCurrentTime();
		CString strText;
		strText.Format("%s\t%s\tÂ¼Ïñ»Ø·Å\r\n",m_UserName,
			m_LogTime.Format("%y-%m-%d %H:%M:%S"));
		CFile file;
		file.Open(m_LogPath,CFile::modeWrite);
		file.SeekToEnd();
		file.Write(strText,strText.GetLength());
		file.Close();
	}
}

void CPlaydlg::OnOK()
{
}

void CPlaydlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	m_MediaPlay.Stop();
	CDialog::OnClose();
}
