// Copy.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "Copy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCopy dialog


CCopy::CCopy(CWnd* pParent /*=NULL*/)
	: CDialog(CCopy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCopy)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CCopy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCopy)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCopy, CDialog)
	//{{AFX_MSG_MAP(CCopy)
	ON_BN_CLICKED(IDC_BUTTON_checkml, OnBUTTONcheckml)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCopy message handlers

void CCopy::OnBUTTONcheckml() 
{
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];
	BROWSEINFO bi;
	bi.hwndOwner=NULL;
	bi.pidlRoot=NULL;
	bi.lpszTitle=_T("请选择备份文件夹");
	bi.pszDisplayName=szPath;
	bi.ulFlags=BIF_RETURNONLYFSDIRS;
	bi.lpfn=NULL;
	bi.lParam=NULL;
	LPITEMIDLIST pItemIDList=SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath))
			ReturnPach=szPath;	
	}
	else
		ReturnPach="";
	m_Edit.SetWindowText(ReturnPach);	
}

void CCopy::OnButtonOk() 
{
	UpdateData();
	CString str,strpath;
	m_Edit.GetWindowText(str);
	strpath = str+"\\"+m_Name+".mdb";
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\ExamOnline.mdb");
	CopyFile(buf,strpath,false);//复制文件
	MessageBox("备份完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	CDialog::OnOK();	
}

void CCopy::OnButtonCancel() 
{
	CDialog::OnCancel();	
}
