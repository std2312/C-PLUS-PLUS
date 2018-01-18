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
	//�����б���ͼ����չ���
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);
	m_List.InsertColumn(0,"�û�����",LVCFMT_LEFT,250);
	m_List.InsertColumn(1,"�û�����",LVCFMT_LEFT,200);
	m_ImageList.Create(16,16,TRUE,2,2);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_List.SetImageList(&m_ImageList,LVSIL_SMALL);	
	//���ز���Ա��Ϣ
	LoadOperatorInfo();
	return TRUE;
}

//���ز���Ա��Ϣ
void COprManage::LoadOperatorInfo()
{
	CServerApp* pApp = (CServerApp*)AfxGetApp();
	CString sql = "select * from tb_userinfo";
	pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	//��ձ������
	m_List.DeleteAllItems();
	int row = 0;
	CString user,password;
	while (! pApp->m_DataManage.m_pRecord->ADOEof)
	{
		//�������
		m_List.InsertItem(row,"",0);
		//�������ı�
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
		//��ȡ����
		GetClassName(pMsg->hwnd,str.GetBuffer(0),MAX_PATH);
		if (str=="Edit")
			pMsg->wParam = VK_TAB ;
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

//�����б�ؼ���˫���¼�
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

//��Ӳ���Ա��Ϣ
void COprManage::OnBtAdd() 
{
	CString user,pass,confirm;

	m_User.GetWindowText(user);
	m_Pass.GetWindowText(pass);
	m_ConfirmInfo.GetWindowText(confirm);
	//�жϲ���Ա��Ϣ�Ƿ�Ϊ��
	if (user.IsEmpty() || pass.IsEmpty() || confirm.IsEmpty())
	{
		MessageBox("����Ա��Ϣ����Ϊ��!","��ʾ");
		m_User.SetFocus();
		return;
	}
	//��֤����
	if (pass!= confirm)
	{
		MessageBox("�������벻һ��!","��ʾ");
		return;
	}
	//��֤�û��Ƿ����
	CServerApp* pApp = (CServerApp*)AfxGetApp();
	CString sql;
	sql.Format("select * from tb_userInfo where username = '%s'", user);
	pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
	pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	
	if (pApp->m_DataManage.m_pRecord->RecordCount>0)
	{
		pApp->m_DataManage.m_pRecord->Close();
		MessageBox("���û��Ѵ���","��ʾ");
	}
	else  //��������
	{
		pApp->m_DataManage.m_pRecord->Close();
		sql.Format("insert into tb_userInfo values ( '%s','%s')",user,pass);

		try
		{
			pApp->m_DataManage.m_pConnect->Execute((_bstr_t)sql,NULL,-1);
			MessageBox("�����ɹ�","��ʾ");
			ClearText();         //��ձ༭���ı�
			LoadOperatorInfo();  //ˢ����Ϣ
		}
		catch(...)
		{
			MessageBox("����ʧ��");
		}
	}
}
//��ձ༭���ı�
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

//ɾ������Ա��Ϣ
void COprManage::OnBtdDelete() 
{
	if (m_List.GetItemCount()>1)
	{
		int selrow = m_List.GetSelectionMark();
		if (selrow != -1)
		{
			if (MessageBox("ȷʵҪɾ����ǰ������?","��ʾ",MB_YESNO)==IDYES)
			{
				CString user = m_List.GetItemText(selrow,0);
				try
				{
					CString sql;
					sql.Format("delete from tb_userinfo where username = '%s'",user);
					CServerApp* pApp = (CServerApp*)AfxGetApp();
					pApp->m_DataManage.m_pConnect->Execute((_bstr_t)sql,NULL,-1);
					MessageBox("ɾ���ɹ�!","��ʾ");
					LoadOperatorInfo();
				}
				catch(...)
				{
					MessageBox("����ʧ��!","��ʾ");
				}
			}
		}
		else
		{
			MessageBox("�����б���ѡ��ɾ��������!");
		}
	}
	else
	{
		MessageBox("����ɾ�����еĲ���Ա��Ϣ!");
	}
}

//�޸Ĳ���Ա��Ϣ
void COprManage::OnBtUpdate() 
{
	int selrow = m_List.GetSelectionMark();
	if (selrow != -1)
	{
		CString user,pass,confirm;
		m_User.GetWindowText(user);
		m_Pass.GetWindowText(pass);
		m_ConfirmInfo.GetWindowText(confirm);
		//�жϲ���Ա��Ϣ�Ƿ�Ϊ��
		if (user.IsEmpty() || pass.IsEmpty() || confirm.IsEmpty())
		{
			MessageBox("����Ա��Ϣ����Ϊ��!","��ʾ");
			m_User.SetFocus();
			return;
		}
		//��֤����
		if (pass!= confirm)
		{
			MessageBox("�������벻һ��!","��ʾ");
			return;
		}
		//��֤�û��Ƿ����
		CServerApp* pApp = (CServerApp*)AfxGetApp();
		CString sql;
		sql.Format("select * from tb_userInfo where username = '%s'", user);
		pApp->m_DataManage.m_pRecord->CursorLocation = adUseServer;
		pApp->m_DataManage.m_pRecord->Open((_bstr_t)sql,pApp->m_DataManage.m_pConnect.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		
		if (pApp->m_DataManage.m_pRecord->RecordCount>1)
		{
			pApp->m_DataManage.m_pRecord->Close();
			MessageBox("���û��Ѵ���","��ʾ");
		}
		else  //�޸�����
		{	
			pApp->m_DataManage.m_pRecord->Close();
			//��ȡ�б��в���Ա����
			CString listuser = m_List.GetItemText(selrow,0);
			CString updatesql;
			updatesql.Format("update tb_userInfo set [password] = '%s' where username = '%s'" , pass ,listuser);
			try
			{
				pApp->m_DataManage.m_pCommand->ActiveConnection = pApp->m_DataManage.m_pConnect;
				pApp->m_DataManage.m_pCommand->CommandText = (_bstr_t)updatesql;
				pApp->m_DataManage.m_pCommand->Execute(NULL,NULL,adCmdText);
				MessageBox("�޸ĳɹ�!","��ʾ");
				LoadOperatorInfo();
			}
			catch(_com_error & e)
			{
				MessageBox("����ʧ��!","��ʾ");
			}
		}	
	}
	else
	{
		MessageBox("��ѡ����Ҫ�޸ĵĲ���Ա��Ϣ!","��ʾ");
	}
}


void COprManage::OnGetdispinfoListinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{

	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	
	*pResult = 0;
}
