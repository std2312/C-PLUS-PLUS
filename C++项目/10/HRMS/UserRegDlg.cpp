// UserRegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "UserRegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserRegDlg dialog


CUserRegDlg::CUserRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsModiCode = FALSE;
}


void CUserRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserRegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserRegDlg, CDialog)
	//{{AFX_MSG_MAP(CUserRegDlg)
	ON_BN_CLICKED(IDC_CHECK_USER_NAME, OnCheckUserName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserRegDlg message handlers

void CUserRegDlg::OnCheckUserName() 
{
	// TODO: Add your control notification handler code here
	CString name;
	GetDlgItemText(IDC_EDIT1, name);
	if(!CheckRegName(name))
	{
		MessageBox("您的用户名已经被注册！");
		return ;
	}
	else
		MessageBox("恭喜您你的用户名可以使用！");
}

void CUserRegDlg::SetModiCodeDlg(BOOL isCode)
{

	m_IsModiCode = isCode;
}

BOOL CUserRegDlg::InitCodeDlg()
{

	SetWindowText("修改用户密码");
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_USER_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDOK)->SetWindowText("保存");

	return TRUE;
}

BOOL CUserRegDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_IsModiCode)
	{
		InitCodeDlg();
		InitUserInfo(m_UserName);
		return TRUE;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserRegDlg::SetUserName(CString &name)
{
	m_UserName = name;
}

BOOL CUserRegDlg::InitUserInfo(const CString &name)
{

	ASSERT(!name.IsEmpty());

	CADOOperation userInfo;
	CString sql, con;

	SetDlgItemText(IDC_EDIT1, name);
	sql.Format("\
				  select tb_employee.employee_name as name,\
				  tb_dept.dept_name as dept,\
				  tb_dept_duty.duty_name as duty\
				  from tb_dept_duty, tb_dept, tb_employee, tb_user_loader\
				  where tb_user_loader.user_name = '%s'\
				  and tb_dept_duty.duty_id = tb_employee.employee_duty\
				  and tb_employee.employee_dept = tb_dept.dept_id\
				  and tb_employee.employee_id = tb_user_loader.employee_id", name);
	userInfo.OpenRecordset(sql);
	if(userInfo.IsLastRow())
	{
		userInfo.CloseRecorset();
		return FALSE;
	}
	userInfo.GetItemContent("name", CADOOperation::ADO_TYPE_STRING, &con);
	SetDlgItemText(IDC_EDIT4, con);
	userInfo.GetItemContent("dept", CADOOperation::ADO_TYPE_STRING, &con);
	SetDlgItemText(IDC_EDIT5, con);
	userInfo.GetItemContent("duty", CADOOperation::ADO_TYPE_STRING, &con);
	SetDlgItemText(IDC_EDIT6, con);
	userInfo.CloseRecorset();

	return TRUE;
}

void CUserRegDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString name, dept, duty;
	GetDlgItemText(IDC_EDIT4, name);

	if(!m_IsModiCode)
	{
		GetDlgItemText(IDC_EDIT5, dept);
		GetDlgItemText(IDC_EDIT6, duty);
		if(!CheckUser(name, dept, duty))
		{
			MessageBox("您所注册的用户不存在！");
			((CEdit*)GetDlgItem(IDC_EDIT4))->SetFocus();
			((CEdit*)GetDlgItem(IDC_EDIT4))->SetSel(0, -1);
			return ;
		}
		if(SaveUserInfo(name))
		{
			MessageBox("注册成功！", "提示", MB_OK | MB_ICONWARNING);
			CDialog::OnOK();
		}
		else
			return ;
	}
	else
	{
		CString regName;
		GetDlgItemText(IDC_EDIT1, regName);
		if(ModiCode(regName))
		{
			CDialog::OnOK();
			MessageBox("修改成功！");
		}
	}
}

BOOL CUserRegDlg::CheckUser(CString &name, CString &dept, CString &duty)
{
	CADOOperation con;
	CString sql;
	DWORD count = 0;

	sql.Format("\
				  select count(*)\
				  from tb_dept_duty, tb_dept, tb_employee\
				  where tb_employee.employee_name = '%s' \
				  and tb_dept_duty.duty_name = '%s'\
				  and tb_dept.dept_name = '%s'\
				  and tb_dept_duty.duty_id = tb_employee.employee_duty\
				  and tb_employee.employee_dept = tb_dept.dept_id", name, duty, dept);
	con.OpenRecordset(sql);
	con.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	con.CloseRecorset();
	if(count <= 0)
		return FALSE;

	return TRUE;
}

BOOL CUserRegDlg::SaveUserInfo(CString& name)
{
	CString id, regName, regCode, reCode;
	CADOOperation user;

	id = CTimeCardDlg::GetEmployIDByName(name);
	GetDlgItemText(IDC_EDIT1, regName);
	GetDlgItemText(IDC_EDIT2, regCode);
	GetDlgItemText(IDC_EDIT3, reCode);
	regName.Replace(" ", "");
	if(regName.IsEmpty())
	{
		MessageBox("用户名不能为空！", "提示", MB_OK | MB_ICONWARNING);
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return FALSE;
	}
	if(regCode.IsEmpty())
	{
		MessageBox("密码不能为空！", "提示", MB_OK | MB_ICONWARNING);
		GetDlgItem(IDC_EDIT2)->SetFocus();
		return FALSE;
	}
	if(0 != reCode.Compare(regCode.GetBuffer(0)))
	{
		MessageBox("密码不一至！", "提示", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	user.OpenTable("tb_user_loader");
	user.AddNew();
	user.SetItemContent("user_name", CADOOperation::ADO_TYPE_STRING, &regName);
	user.SetItemContent("user_code", CADOOperation::ADO_TYPE_STRING, &regCode);
	user.SetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &id);
	user.UpdateData();
	user.CloseTable();
	return TRUE;
}

BOOL CUserRegDlg::CheckRegName(CString &regName)
{
	CString sql;
	DWORD count = 0;
	CADOOperation list;

	sql.Format("select count(*) from tb_user_loader where user_name = '%s'", regName);
	list.OpenRecordset(sql);
	list.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	list.CloseRecorset();

	if(count <=0)
		return TRUE;

	return FALSE;
}

BOOL CUserRegDlg::ModiCode(CString &regName)
{
	CADOOperation update;
	CString sql, regCode;

	GetDlgItemText(IDC_EDIT2, regCode);
	sql.Format("update tb_user_loader \
		set user_code = '%s' \
		where user_name = '%s'", regCode, regName);
	update.OpenRecordset(sql);
	update.CloseRecorset();

	return TRUE;
}
