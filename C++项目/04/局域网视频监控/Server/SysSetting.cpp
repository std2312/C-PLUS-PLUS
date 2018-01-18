// SysSetting.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "SysSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//
#include "DataManage.h"
/////////////////////////////////////////////////////////////////////////////
// CSysSetting dialog

CSysSetting::CSysSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CSysSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysSetting)
	//}}AFX_DATA_INIT
}


void CSysSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysSetting)
	DDX_Control(pDX, IDC_CONFIRM, m_BTConfirm);
	DDX_Control(pDX, IDC_CANCEL, m_BTCancel);
	DDX_Control(pDX, IDC_CLIENTIP, m_IP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSysSetting, CDialog)
	//{{AFX_MSG_MAP(CSysSetting)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysSetting message handlers

void CSysSetting::OnOK() 
{

}

void CSysSetting::OnConfirm() 
{
	CString ip;
	m_IP.GetWindowText(ip);
	if (!ip.IsEmpty())  //判断IP地址是否为空
	{
		CServerApp* pApp = (CServerApp*)AfxGetApp();
	
		CString sql = "select * from tb_ClientInfo";
		pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
		pApp->m_DataManage.m_pRecord->Open((_variant_t)sql, pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText );
		
		if (pApp->m_DataManage.m_pRecord->RecordCount>0)
		{
label:	    try
			{
			
				pApp->m_DataManage.m_pRecord->GetFields()->GetItem("ClientIP")->Value = (_bstr_t)ip;
				pApp->m_DataManage.m_pRecord->Update();
				MessageBox("操作成功,重启本系统后生效!","提示");
			}
			catch (_com_error &err)
			{
				MessageBox("操作失败!","提示");
			}
		
		}
		else
		{
			pApp->m_DataManage.m_pRecord->AddNew();
			goto label;
		}
		pApp->m_DataManage.m_pRecord->Close();

		OnCancel();
	}
	else  //IP地址为空
	{
		MessageBox("请输入IP地址");
	}
}


void CSysSetting::OnCancel() 
{
	CDialog::OnCancel();	
}
