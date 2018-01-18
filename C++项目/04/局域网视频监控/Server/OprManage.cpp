// OprManage.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "OprManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COprManage dialog


COprManage::COprManage(CWnd* pParent /*=NULL*/)
	: CDialog(COprManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(COprManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COprManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COprManage)
	DDX_Control(pDX, IDC_BTUPDATE, m_BTUpdate);
	DDX_Control(pDX, IDC_BTDELETE, m_BTDelete);
	DDX_Control(pDX, IDC_BTADD, m_BTAdd);
	DDX_Control(pDX, IDC_CONFIRMPASS, m_ConfirmInfo);
	DDX_Control(pDX, IDC_USER, m_User);
	DDX_Control(pDX, IDC_PASS, m_Pass);
	DDX_Control(pDX, IDC_LISTINFO, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COprManage, CDialog)
	//{{AFX_MSG_MAP(COprManage)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTINFO, OnDblclkListInfo)
	ON_BN_CLICKED(IDC_BTADD, OnBtAdd)
	ON_BN_CLICKED(IDC_BTDELETE, OnBtdDelete)
	ON_BN_CLICKED(IDC_BTUPDATE, OnBtUpdate)
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LISTINFO, OnGetdispinfoListinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COprManage message handlers

void COprManage::OnOK() 
{

}

BOOL COprManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//设置列表视图的扩展风格
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);
	m_List.InsertColumn(0,"用户名称",LVCFMT_LEFT,250);
	m_List.InsertColumn(1,"用户密码",LVCFMT_LEFT,200);
	m_ImageList.Create(16,16,TRUE,2,2);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_List.SetImageList(&m_ImageList,LVSIL_SMALL);	
	//加载操作员信息
	LoadOperatorInfo();
	return TRUE;
}

//加载操作员信息
void COprManage::LoadOperatorInfo()
{
	CServerApp* pApp = (CServerApp*)AfxGetApp();
	CString sql = "select * from tb_userinfo";
	pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	//清空表格内容
	m_List.DeleteAllItems();
	int row = 0;
	CString user,password;
	while (! pApp->m_DataManage.m_pRecord->ADOEof)
	{
		//添加新行
		m_List.InsertItem(row,"",0);
		//设置列文本
		user = (char*)(_bstr_t)pApp->m_DataManage.m_pRecord->GetFields()->GetItem(0L)->Value;
		password = (char*)(_bstr_t)pApp->m_DataManage.m_pRecord->GetFields()->GetItem(1L)->Value;
		m_List.SetItemText(row,0,user);
		m_List.SetItemText(row,1,password);
		row++;
		pApp->m_DataManage.m_pRecord->MoveNext();
	}
	pApp->m_DataManage.m_pRecord->Close();
}

BOOL COprManage::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN )
	{
		CString str;
		//获取类名
		GetClassName(pMsg->hwnd,str.GetBuffer(0),MAX_PATH);
		if (str=="Edit")
			pMsg->wParam = VK_TAB ;
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

//处理列表控件的双击事件
void COprManage::OnDblclkListInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int selrow =  m_List.GetSelectionMark();
	if (selrow != -1)
	{
		m_User.SetWindowText(m_List.GetItemText(selrow,0));		
		m_Pass.SetWindowText(m_List.GetItemText(selrow,1));
	}
	*pResult = 0;	
}

//添加操作员信息
void COprManage::OnBtAdd() 
{
	CString user,pass,confirm;

	m_User.GetWindowText(user);
	m_Pass.GetWindowText(pass);
	m_ConfirmInfo.GetWindowText(confirm);
	//判断操作员信息是否为空
	if (user.IsEmpty() || pass.IsEmpty() || confirm.IsEmpty())
	{
		MessageBox("操作员信息不能为空!","提示");
		m_User.SetFocus();
		return;
	}
	//验证密码
	if (pass!= confirm)
	{
		MessageBox("两次密码不一致!","提示");
		return;
	}
	//验证用户是否存在
	CServerApp* pApp = (CServerApp*)AfxGetApp();
	CString sql;
	sql.Format("select * from tb_userInfo where username = '%s'", user);
	pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
	pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	
	if (pApp->m_DataManage.m_pRecord->RecordCount>0)
	{
		pApp->m_DataManage.m_pRecord->Close();
		MessageBox("该用户已存在","提示");
	}
	else  //插入数据
	{
		pApp->m_DataManage.m_pRecord->Close();
		sql.Format("insert into tb_userInfo values ( '%s','%s')",user,pass);

		try
		{
			pApp->m_DataManage.m_pConnect->Execute((_bstr_t)sql,NULL,-1);
			MessageBox("操作成功","提示");
			ClearText();         //清空编辑框文本
			LoadOperatorInfo();  //刷新信息
		}
		catch(...)
		{
			MessageBox("操作失败");
		}
	}
}
//清空编辑框文本
void COprManage::ClearText()
{
	HWND pWnd =NULL;
	pWnd = ::GetWindow(m_hWnd,GW_CHILD);
	char clsname[MAX_PATH];
	memset(clsname,0,MAX_PATH);

	if (pWnd != NULL)
	{
		if (::GetClassName(pWnd,clsname,MAX_PATH)!=0)
		{
			if (strcmp(clsname,"Edit") ==0)	
				::SetWindowText(pWnd,"");
		}
		HWND hWnd = ::GetNextWindow(pWnd,GW_HWNDNEXT);
		do
		{
			if (::GetClassName(hWnd,clsname,MAX_PATH)!=0)
			{
				if (strcmp(clsname,"Edit") ==0)	
					::SetWindowText(hWnd,"");
			}
			hWnd = ::GetNextWindow(hWnd,GW_HWNDNEXT);
		}
		while (hWnd != NULL);
	}
}

//删除操作员信息
void COprManage::OnBtdDelete() 
{
	if (m_List.GetItemCount()>1)
	{
		int selrow = m_List.GetSelectionMark();
		if (selrow != -1)
		{
			if (MessageBox("确实要删除当前数据吗?","提示",MB_YESNO)==IDYES)
			{
				CString user = m_List.GetItemText(selrow,0);
				try
				{
					CString sql;
					sql.Format("delete from tb_userinfo where username = '%s'",user);
					CServerApp* pApp = (CServerApp*)AfxGetApp();
					pApp->m_DataManage.m_pConnect->Execute((_bstr_t)sql,NULL,-1);
					MessageBox("删除成功!","提示");
					LoadOperatorInfo();
				}
				catch(...)
				{
					MessageBox("操作失败!","提示");
				}
			}
		}
		else
		{
			MessageBox("请在列表中选择删除的数据!");
		}
	}
	else
	{
		MessageBox("不能删除所有的操作员信息!");
	}
}

//修改操作员信息
void COprManage::OnBtUpdate() 
{
	int selrow = m_List.GetSelectionMark();
	if (selrow != -1)
	{
		CString user,pass,confirm;
		m_User.GetWindowText(user);
		m_Pass.GetWindowText(pass);
		m_ConfirmInfo.GetWindowText(confirm);
		//判断操作员信息是否为空
		if (user.IsEmpty() || pass.IsEmpty() || confirm.IsEmpty())
		{
			MessageBox("操作员信息不能为空!","提示");
			m_User.SetFocus();
			return;
		}
		//验证密码
		if (pass!= confirm)
		{
			MessageBox("两次密码不一致!","提示");
			return;
		}
		//验证用户是否存在
		CServerApp* pApp = (CServerApp*)AfxGetApp();
		CString sql;
		sql.Format("select * from tb_userInfo where username = '%s'", user);
		pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
		pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		
		if (pApp->m_DataManage.m_pRecord->RecordCount>1)
		{
			pApp->m_DataManage.m_pRecord->Close();
			MessageBox("该用户已存在","提示");
		}
		else  //修改数据
		{	
			pApp->m_DataManage.m_pRecord->Close();
			//获取列表中操作员姓名
			CString listuser = m_List.GetItemText(selrow,0);
			CString updatesql;
			updatesql.Format("update tb_userInfo set [password] = '%s' where username = '%s'" , pass ,listuser);
			try
			{
				pApp->m_DataManage.m_pCommand->ActiveConnection = pApp->m_DataManage.m_pConnect;
				pApp->m_DataManage.m_pCommand->CommandText = (_bstr_t)updatesql;
				pApp->m_DataManage.m_pCommand->Execute(NULL,NULL,adCmdText);
				MessageBox("修改成功!","提示");
				LoadOperatorInfo();
			}
			catch(_com_error & e)
			{
				MessageBox("操作失败!","提示");
			}
		}	
	}
	else
	{
		MessageBox("请选择需要修改的操作员信息!","提示");
	}
}


void COprManage::OnGetdispinfoListinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{

	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	
	*pResult = 0;
}
