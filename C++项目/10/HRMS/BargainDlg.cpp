// BargainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "BargainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBargainDlg dialog


CBargainDlg::CBargainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBargainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBargainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsEditable = TRUE;
	m_Available = TRUE;
}


void CBargainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBargainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBargainDlg, CDialog)
	//{{AFX_MSG_MAP(CBargainDlg)
	ON_BN_CLICKED(IDC_BARGAIN_SAVE, OnBargainSave)
	ON_BN_CLICKED(IDC_LOAD_BARGAIN_ITEM, OnLoadBargainItem)
	ON_COMMAND(IDM_OPEN, OnOpen)
	ON_COMMAND(IDM_LOAD_OUT, OnLoadOut)
	ON_COMMAND(IDM_LOAD_IN, OnLoadIn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBargainDlg message handlers

void CBargainDlg::SetEmployName(CString name)
{
	m_EmployeeName = name;
}

CBargainDlg::CBargainDlg(CString name)
{
	CBargainDlg();
}

void CBargainDlg::OnLoadBargainItem() 
{
	// TODO: Add your control notification handler code here
	RECT rect;
	POINT point;
	GetDlgItem(IDC_LOAD_BARGAIN_ITEM)->GetWindowRect(&rect);
	CMenu menu, *subMenu;
	menu.LoadMenu(IDR_FILE_SEARCH_MENU);
	subMenu = menu.GetSubMenu(0);
	if(!m_Available)
	{
		subMenu->EnableMenuItem(1, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
		subMenu->EnableMenuItem(2, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
	}

	point.x = rect.left;
	point.y = rect.bottom;
	subMenu->TrackPopupMenu(TPM_LEFTBUTTON, point.x, point.y, this);
}

void CBargainDlg::OnBargainSave() 
{
	// TODO: Add your control notification handler code here
	if(!m_IsEditable)
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);
		if(IDYES != MessageBox("确定终止本合同吗？", "提示", MB_YESNO | MB_ICONWARNING))
			return ;
		if(InvalidateBargain(str, 2))
		{
			((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(2);
			GetDlgItem(IDC_BARGAIN_SAVE)->EnableWindow(FALSE);
			MessageBox("成功终止！", "提示", MB_OK);
		}

		return ;
	}
	if(SaveBargain())
	{
		MessageBox("保存成功！");
		EndDialog(0);
		return ;
	}
}

BOOL CBargainDlg::SaveBargain()
{
	CADOOperation bargain;
	CString str;
	DWORD interger;
	SYSTEMTIME sysTime;
	BOOL ret = FALSE;

	bargain.OpenTable("tb_bargain");
	bargain.AddNew();
	GetDlgItemText(IDC_EDIT1, str);							//合约编号
	if(str.IsEmpty())
	{
		MessageBox("请输入有效的编号！", "提示", MB_ICONWARNING | MB_OK);
		bargain.CloseRecorset();
		return FALSE;
	}
	ret = bargain.SetItemContent("bargain_id", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT5, str);							//合约条款
	if(str.IsEmpty())
	{
		MessageBox("请输入合同的条款！", "提示", MB_ICONWARNING | MB_OK);
		bargain.CloseRecorset();
		return FALSE;
	}
	ret = bargain.SetItemContent("bargain_item", CADOOperation::ADO_TYPE_TEXT, &str);
	if(!ret)
	{
		bargain.CloseRecorset();
		bargain.UpdateData();
		return FALSE;
	}
	interger = GetDlgItemInt(IDC_EDIT3);					//合约有效期
	ret = bargain.SetItemContent("bargain_useful_life", CADOOperation::ADO_TYPE_INT, &interger);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}
															//合约生效日期
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ret = bargain.SetItemContent("bargain_timeofbeceff", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}
															//得到合同状态
	interger = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	ret = bargain.SetItemContent("bargain_state", CADOOperation::ADO_TYPE_INT, &interger);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT4, str);							//得到签约人
	if(str.IsEmpty())
	{
		MessageBox("合约人不能为空！", "提示", MB_OK | MB_ICONWARNING);
		bargain.CloseRecorset();
		return FALSE;
	}
	ret = bargain.SetItemContent("bargain_employee", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, str);						//得到合同类型
	ret = bargain.SetItemContent("bargain_type", CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		bargain.CloseRecorset();
		return FALSE;
	}

	bargain.UpdateData();
	bargain.CloseRecorset();
	return TRUE;
}

BOOL CBargainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdataState();

	if(!m_IsEditable)
	{
		ShowBargain(m_EmployeeName);
		DisableBargain();
		return TRUE;
	}
	SetDlgItemText(IDC_EDIT4, m_EmployeeName);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	SetDlgItemText(IDC_EDIT4, m_EmployeeName);
	CComboBox* pCom = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CADOOperation barType;
	CString str;
	barType.OpenRecordset("select distinct template_type from tb_bargain_template");
	if(barType.IsLastRow())
	{
		barType.CloseRecorset();
		return TRUE;
	}
	barType.MoveFirst();
	do
	{
		barType.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
		pCom->AddString(str);
		barType.MoveNext();
	}
	while(!barType.IsLastRow());
	barType.CloseRecorset();
	pCom->SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBargainDlg::OnOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog fileDlg(TRUE, ".txt", 
		NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"文本文件 (*.txt)|*.txt||", this);
	if(IDOK != fileDlg.DoModal())
		return ;
	CString fileName = fileDlg.GetPathName();

	CFile file(fileName, CFile::modeRead);
	DWORD fileLen;
	char *buffer;
	fileLen = file.GetLength() + 1;
	if(fileLen < 0)
	{
		MessageBox("无效的文件！", "错误", MB_ICONWARNING);
		return ;
	}
	if(NULL == (buffer = new char[fileLen]))
	{
		MessageBox("没有可用的内存！", "致命错误", MB_ICONERROR);
		exit(0);
		return ;
	}
	memset(buffer, 0, fileLen);
	file.Read(buffer, fileLen);
	CString str;
	str.Format("%s", buffer);
	SetDlgItemText(IDC_EDIT5, str);
	delete buffer;
}

void CBargainDlg::OnLoadOut() 
{
	// TODO: Add your command handler code here
	CLoadInTempDlg dlg;
	CString str, type, name;

	GetDlgItemText(IDC_COMBO1, str);
	dlg.SetTemplateType(str);
	if(IDOK != dlg.DoModal())
		return ;
	name = dlg.GetTemplateName();
	type = dlg.GetTemplateType();
	if(SaveTemplate(type, name))
		MessageBox("保存成功！");
}

void CBargainDlg::OnLoadIn() 
{
	// TODO: Add your command handler code here
	CTemLoadDlg dlg;
	CADOOperation temp;
	CString type, name, sql, str;
	if(IDOK != dlg.DoModal())
		return ;
	type = dlg.GetTemplateType();
	name = dlg.GetTemplateName();
	sql.Format("select template_item from tb_bargain_template \
		where template_type = '%s' and template_name = '%s'", type, name);
	temp.OpenRecordset(sql);
	if(temp.IsLastRow())
	{
		MessageBox("没有合适的模板！");
		temp.CloseRecorset();
		return ;
	}
	
	temp.GetItemContent("template_item", CADOOperation::ADO_TYPE_TEXT, &str);
	temp.CloseRecorset();
	SetDlgItemText(IDC_EDIT5, str);
	SetDlgItemText(IDC_COMBO1, type);
} 

BOOL CBargainDlg::SaveTemplate(CString type, CString name)
{

	CADOOperation tmp;
	CString str;
	BOOL ret;
	tmp.OpenTable("tb_bargain_template");
	tmp.AddNew();
	ret = tmp.SetItemContent("template_type", CADOOperation::ADO_TYPE_STRING, &type);
	if(!ret)
	{
		tmp.CloseTable();
		return FALSE;
	}
	ret = tmp.SetItemContent("template_name", CADOOperation::ADO_TYPE_STRING, &name);
	if(!ret)
	{
		tmp.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT5, str);
	ret = tmp.SetItemContent("template_item", CADOOperation::ADO_TYPE_TEXT, &str);
	if(!ret)
	{
		tmp.CloseTable();
		return FALSE;
	}
	tmp.UpdateData();
	tmp.CloseTable();
	return TRUE;
}

void CBargainDlg::SetEdiable(BOOL editable)
{
	m_IsEditable = editable;
}

void CBargainDlg::DisableBargain()
{
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);

	((CEdit*)GetDlgItem(IDC_EDIT5))->SetReadOnly(TRUE);
	GetDlgItem(IDC_BARGAIN_RESET)->EnableWindow(FALSE);
//	GetDlgItem(IDC_LOAD_BARGAIN_ITEM)->EnableWindow(TRUE);
	GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
	SetDlgItemText(IDC_BARGAIN_SAVE, "终止");


	if(!m_Available)
		GetDlgItem(IDC_BARGAIN_SAVE)->EnableWindow(FALSE);
	
}

BOOL CBargainDlg::ShowBargain(CString name)
{
	CADOOperation barg;
	CString sql, str, id;
	DWORD life, state;
	SYSTEMTIME sysTime = {0};
	CTime cur;

	sql.Format("select * from tb_bargain where bargain_employee = '%s'", name);
	barg.OpenRecordset(sql);
	barg.GetItemContent("bargain_id", CADOOperation::ADO_TYPE_STRING, &id);
	SetDlgItemText(IDC_EDIT1, id);

	barg.GetItemContent("bargain_state", CADOOperation::ADO_TYPE_INT, &state);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(state);

	barg.GetItemContent("bargain_type", CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_COMBO1, str);
	barg.GetItemContent("bargain_item", CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_EDIT5, str);
	barg.GetItemContent("bargain_useful_life", CADOOperation::ADO_TYPE_INT, &life);
	SetDlgItemInt(IDC_EDIT3, life);
	barg.GetItemContent("bargain_timeofbeceff", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);
	cur.GetCurrentTime();
	cur = sysTime;
	barg.CloseRecorset();
	if(state != 0)
		m_Available = FALSE;

	return TRUE;
}

BOOL CBargainDlg::InvalidateBargain(CString num, DWORD state)
{

	CADOOperation bar;
	CString sql;
	BOOL ret;

	sql.Format("select bargain_state from tb_bargain where bargain_id = '%s'", num);
	ret = bar.OpenRecordset(sql);
	if(!ret)
	{
		bar.CloseRecorset();
		return FALSE;
	}
	ret = bar.SetItemContent("bargain_state", CADOOperation::ADO_TYPE_INT, &state);
	if(!ret)
	{
		bar.CloseRecorset();
		return FALSE;
	}
	ret = bar.UpdateData();
	if(!ret)
	{
		bar.CloseRecorset();
		return FALSE;
	}
	bar.CloseRecorset();

	return TRUE;
}

BOOL CBargainDlg::UpdataState()
{

	CADOOperation state;
	BOOL ret;
	ret = state.OpenRecordset("update tb_bargain set \
													bargain_state = 2 where getdate() > \
													bargain_timeofbeceff + bargain_useful_life * 365");
	state.CloseRecorset();

	return ret ;
}
