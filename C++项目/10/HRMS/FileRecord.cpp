// FileRecord.cpp : implementation file
//

#include "stdafx.h"
#include "HRMS.h"
#include "FileRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileRecord dialog


CFileRecord::CFileRecord(CWnd* pParent /*=NULL*/)
	: CDialog(CFileRecord::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileRecord)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsModifyDlg = FALSE;
	m_Index = -1;
	m_CurSel = -1;
}


void CFileRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileRecord)
	DDX_Control(pDX, IDC_COMBO3, m_Duty);
	DDX_Control(pDX, IDC_COMBO4, m_Dept);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileRecord, CDialog)
	//{{AFX_MSG_MAP(CFileRecord)
	ON_BN_CLICKED(IDC_LOADPICTURE, OnLoadPicture)
	ON_BN_CLICKED(IDB_FILE_RECORD_SAVE, OnFileRecordSave)
	ON_BN_CLICKED(IDB_FILE_RECORD_RESET, OnFileRecordReset)
	ON_WM_PAINT()
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_COMPACT_EDIT, OnCompactEdit)
	ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
	ON_BN_CLICKED(IDC_SEELIST, OnSeelist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileRecord message handlers

BOOL CFileRecord::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//部门组合框初始化
	InitDeptComboBox(&m_Dept);

	SendMessage(WM_COMMAND, MAKEWPARAM(IDC_COMBO4, CBN_SELCHANGE), (LPARAM)m_Dept.m_hWnd);

	//显示修改员工信息视图
	if(m_IsModifyDlg)
	{
		InitModiView();
		return TRUE;
	}
	//从应聘者中增加新员工
	if(m_IsAppler && !m_ApplerId.IsEmpty())
	{
		SetApplerInfo(m_ApplerId);
		return TRUE;
	}
	
	((CComboBox* )GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox* )GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	SetDlgItemInt(IDC_EDIT5, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFileRecord::OnLoadPicture() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(TRUE, "bmp", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "位图文件(*.bmp)|*.bmp||", this);

	if(IDOK != fileDlg.DoModal())
		return ;
	m_PhotoFileName = fileDlg.GetFileName();

	m_Photo = (HBITMAP)::LoadImage(::AfxGetInstanceHandle(), m_PhotoFileName, IMAGE_BITMAP, 128, 128, 
		LR_LOADFROMFILE | LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
	//((CStatic*)GetDlgItem(IDC_PHOTO))->SetBitmap(m_Photo);
	this->Invalidate();
}

void CFileRecord::OnFileRecordSave() 
{
	// TODO: Add your control notification handler code here
	if(m_IsModifyDlg && m_Index > -1)
	{
		if(!ModifyRecord(m_Index))
			MessageBox("保存出现错误！", "注意", MB_OK | MB_ICONHAND);
		else
		{
			MessageBox("保存成功！", "提示", MB_OK | MB_ICONHAND);
			EndDialog(0);
		}
		return ;
	}
	if(!SaveFile())
		MessageBox("保存出现错误请注意序号的唯一性！", "注意", MB_OK | MB_ICONHAND);
	else
	{
		int ret;
		ret = MessageBox("保存成功！\n是否继续录入？", "提示", MB_YESNO | MB_ICONWARNING);
		if(ret == IDYES)
			OnFileRecordReset();
		else if(ret = IDNO)
			EndDialog(0);
	}
}

void CFileRecord::OnFileRecordReset()
{
	// TODO: Add your control notification handler code here
	CTime tm;

	tm.GetLocalTm(NULL);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	SetDlgItemInt(IDC_EDIT5, 0);
	SetDlgItemText(IDC_EDIT6, "");
	SetDlgItemText(IDC_EDIT3, "");
	((CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER2))->SetTime(&tm);
	((CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&tm);
	m_Dept.SetCurSel(0);
	m_Duty.SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	::DeleteObject(m_Photo);
	m_Photo = NULL;
	UpdateData();
	Invalidate();
}

BOOL CFileRecord::SaveFile()
{

	
	CString str;
	SYSTEMTIME sysTime = {0};
	int integer = 0;
	BOOL ret;
	
	CADOOperation dbo;
	dbo.OpenTable("tb_employee");
	dbo.AddNew();

	GetDlgItemText(IDC_EDIT1, str);			//保存员工ID
	ret = dbo.SetItemContent("employee_id",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT2, str);			//保存员工名字
	ret = dbo.SetItemContent("employee_name",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, str);		//保存员工性别
	ret = dbo.SetItemContent("employee_sex",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(			//保存员工生日
		IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ret = dbo.SetItemContent("employee_birthday", 
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	integer = GetDlgItemInt(IDC_EDIT5);		//保存员工工龄
	ret = dbo.SetItemContent("employee_lenofser", 
		CADOOperation::ADO_TYPE_INT, &integer);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	if(!m_PhotoFileName.IsEmpty())			//保存员工相片
		ret = dbo.SetItemContent("employee_photo", 
			CADOOperation::ADO_TYPE_BITMAP_FIEL, &m_PhotoFileName);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO2, str);	//保存员工学历
	ret = dbo.SetItemContent("employee_edulev",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, str);		//保存员工家庭住址
	ret = dbo.SetItemContent("employee_dwel",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, str);		//保存员工家庭住址
	ret = dbo.SetItemContent("employee_dwel",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT6, str);		//保存员工电话
	ret = dbo.SetItemContent("employee_phone",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(		//保存员工入职时间
		IDC_DATETIMEPICKER2))->GetTime(&sysTime);
	ret = dbo.SetItemContent("employee_timeofser", 
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	DWORD numDept = 0;					//保存员工所在部门
	m_Dept.GetWindowText(str);
	numDept = GetDeptNumber(str);
	ret = dbo.SetItemContent("employee_dept", CADOOperation::ADO_TYPE_INT, &numDept);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	DWORD numDuty = 0;					//保存员工所在职位
	m_Duty.GetWindowText(str);
	numDuty = GetDutyNumber(str);
	ret = dbo.SetItemContent("employee_duty", CADOOperation::ADO_TYPE_INT, &numDuty);
	if(!ret)
	{
		dbo.CloseTable();
		return FALSE;
	}
	dbo.UpdateData();
	dbo.CloseTable();
	
	return TRUE;
}

BOOL CFileRecord::ShowRecord(int index)
{
	CADOOperation dbo;
	CString str;
	SYSTEMTIME sysTime = {0};
	HBITMAP hBitmap = NULL;
	int integer = 0;

	CClientDC dc(this);
	dbo.SetClientDC(dc.m_hDC);
	dbo.OpenTable("tb_employee");
	dbo.MoveTo(index);
	dbo.GetItemContent("employee_id",			//读取员工ID
		CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_EDIT1, str);
	dbo.GetItemContent("employee_name",			//读取员工姓名
		CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_EDIT2, str);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);
	dbo.GetItemContent("employee_photo",		//读取员工相片
		CADOOperation::ADO_TYPE_BITMAP_HANDLE, &m_Photo);
	dbo.GetItemContent("employee_lenofser",		//读取员工工龄
		CADOOperation::ADO_TYPE_INT, &integer);
	SetDlgItemInt(IDC_EDIT5, integer);
	dbo.GetItemContent("employee_birthday",		//读取员工生日
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);
	dbo.GetItemContent("employee_timeofser",	//读取员工入职时间
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2))->SetTime(&sysTime);
	dbo.GetItemContent("employee_sex",			//读取员工性别
		CADOOperation::ADO_TYPE_STRING, &str);
	str.Replace(" ", "");
	if(str.Compare("男") == 0)
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	else
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(1);
	dbo.GetItemContent("employee_edulev",		//读取员工学历
		CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_COMBO2, str);
	dbo.GetItemContent("employee_dwel",			//读取员工家庭住址
		CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_EDIT3, str);
	dbo.GetItemContent("employee_phone",		//读取员工电话
		CADOOperation::ADO_TYPE_STRING, &str);
	SetDlgItemText(IDC_EDIT6, str);

	dbo.GetItemContent("employee_dept",			//读取员工所在部门
		CADOOperation::ADO_TYPE_INT, &integer);
	str = GetDeptName(integer);
	m_Dept.SetCurSel(m_Dept.FindString(0, str.GetBuffer(0)));
	OnSelchangeCombo4();

	dbo.GetItemContent("employee_duty",			//读取员工职务
		CADOOperation::ADO_TYPE_INT, &integer);
	str = GetDutyName(integer);
	m_Duty.SetCurSel(m_Duty.FindString(0, str.GetBuffer(0)));
	dbo.CloseTable();
	return TRUE;
}

void CFileRecord::SetShowItem(int index)
{
	m_Index = index;
}

void CFileRecord::SetModifyDlg(BOOL is)
{
	m_IsModifyDlg = is;
}

void CFileRecord::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if(NULL != m_Photo)
	{
		CDC memDC;
		CBitmap bitmap;
		BITMAP bm;

		bitmap.Attach(m_Photo);
		memDC.CreateCompatibleDC((CDC* )&dc);
		memDC.SelectObject(&bitmap);
		bitmap.GetBitmap(&bm);
		dc.StretchBlt(BITMAP_X, BITMAP_Y, 128, 128, &memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		memDC.DeleteDC();
		bitmap.Detach();	
	}
	// Do not call CDialog::OnPaint() for painting messages
}

void CFileRecord::OnCancelMode() 
{
	CDialog::OnCancelMode();
	// TODO: Add your message handler code here
}

void CFileRecord::OnCompactEdit() 
{
	// TODO: Add your control notification handler code here
	CBargainDlg dlg;
	CString name;

	GetDlgItemText(IDC_EDIT2, name);
	if(m_IsModifyDlg)
		dlg.SetEdiable(FALSE);
	dlg.SetEmployName(name);
	dlg.DoModal();
}

void CFileRecord::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	CString con;

	UpdateData();
	m_Dept.GetWindowText(con);
	ShowDutyComboBox(con, &m_Duty);
}

BOOL CFileRecord::ShowDutyComboBox(CString dept, CComboBox* pDept)
{

	CADOOperation duty;
	CString sql, con;

	pDept->ResetContent();
	sql.Format("select duty_name from tb_dept_duty, \
		tb_dept where tb_dept.dept_name = '%s' and \
		tb_dept.dept_id = tb_dept_duty.dept_id", dept);
	duty.OpenRecordset(sql);
	if(duty.IsLastRow())
	{
		duty.CloseRecorset();
		return TRUE;
	}
	duty.MoveFirst();
	do
	{
		duty.GetItemContent("duty_name", CADOOperation::ADO_TYPE_STRING, &con);
		pDept->AddString(con);
		duty.MoveNext();
	}while(!duty.IsLastRow());
	duty.CloseRecorset();
	pDept->SetCurSel(0);

	return TRUE;
}

DWORD CFileRecord::GetDeptNumber(CString str)
{

	DWORD number = 0;
	CString sql;
	CADOOperation dept;

	sql.Format("select dept_id from tb_dept where dept_name = '%s' ", str);
	dept.OpenRecordset(sql);
	dept.GetItemContent("dept_id", CADOOperation::ADO_TYPE_INT, &number);
	dept.CloseRecorset();

	return number;
}

DWORD CFileRecord::GetDutyNumber(CString str)
{
	DWORD number = 0;
	CString sql;
	CADOOperation dept;

	sql.Format("select duty_id from tb_dept_duty where duty_name =  '%s' ", str);
	dept.OpenRecordset(sql);
	dept.GetItemContent("duty_id", CADOOperation::ADO_TYPE_INT, &number);
	dept.CloseRecorset();

	return number;
}

BOOL CFileRecord::InitModiView()
{
	if(m_Index < 0)
		return TRUE;

	SetWindowText("员工详细信息");
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDB_FILE_RECORD_RESET)->SetWindowText("恢复");
	ShowRecord(m_Index);

	return TRUE;
}

CString CFileRecord::GetDeptName(DWORD num)
{
	CString str, sql;
	CADOOperation dept;
	sql.Format("select dept_name from tb_dept where dept_id = %d", num);
	dept.OpenRecordset(sql);
	dept.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
	dept.CloseRecorset();
	return str;
}

CString CFileRecord::GetDutyName(DWORD num)
{
	CString str, sql;
	CADOOperation duty;
	sql.Format("select duty_name from tb_dept_duty where duty_id = %d", num);
	duty.OpenRecordset(sql);
	duty.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &str);
	duty.CloseRecorset();
	return str;
}

BOOL CFileRecord::ModifyRecord(int index)
{
	CADOOperation employee;
	BOOL ret;
	CString str;
	SYSTEMTIME sysTime = {0};
	DWORD integer;

	employee.OpenTable("tb_employee");
	if(employee.IsLastRow())
	{
		employee.CloseTable();
		return TRUE;
	}
	employee.MoveTo(index);
	GetDlgItemText(IDC_EDIT2, str);			//保存员工名字
	ret = employee.SetItemContent("employee_name",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		
		employee.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, str);		//保存员工性别
	ret = employee.SetItemContent("employee_sex",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(			//保存员工生日
		IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ret = employee.SetItemContent("employee_birthday", 
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	integer = GetDlgItemInt(IDC_EDIT5);		//保存员工工龄
	ret = employee.SetItemContent("employee_lenofser", 
		CADOOperation::ADO_TYPE_INT, &integer);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	if(!m_PhotoFileName.IsEmpty())			//保存员工相片
		ret = employee.SetItemContent("employee_photo", 
			CADOOperation::ADO_TYPE_BITMAP_FIEL, &m_PhotoFileName);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO2, str);	//保存员工学历
	ret = employee.SetItemContent("employee_edulev",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, str);		//保存员工家庭住址
	ret = employee.SetItemContent("employee_dwel",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, str);		//保存员工家庭住址
	ret = employee.SetItemContent("employee_dwel",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT6, str);		//保存员工电话
	ret = employee.SetItemContent("employee_phone",
		CADOOperation::ADO_TYPE_STRING, &str);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(		//保存员工入职时间
		IDC_DATETIMEPICKER2))->GetTime(&sysTime);
	ret = employee.SetItemContent("employee_timeofser", 
		CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}
	DWORD numDept = 0;					//保存员工所在部门
	m_Dept.GetWindowText(str);
	numDept = GetDeptNumber(str);
	ret = employee.SetItemContent("employee_dept", CADOOperation::ADO_TYPE_INT, &numDept);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}

	DWORD numDuty = 0;					//保存员工所在职位
	m_Duty.GetWindowText(str);
	numDuty = GetDutyNumber(str);
	ret = employee.SetItemContent("employee_duty", CADOOperation::ADO_TYPE_INT, &numDuty);
	if(!ret)
	{
		employee.CloseTable();
		return FALSE;
	}

	employee.UpdateData();
	employee.CloseTable();
	return TRUE;
}

BOOL CFileRecord::InitDeptComboBox(CComboBox* pDept)
{
	CADOOperation dept;
	CString str;
	dept.OpenTable("tb_dept");
	if(dept.IsLastRow())
		return TRUE;
	dept.MoveFirst();
	do
	{
		dept.GetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &str);
		pDept->AddString(str);
		dept.MoveNext();
	}while(!dept.IsLastRow());
	pDept->SetCurSel(0);
	dept.CloseTable();
	return TRUE;
}

void CFileRecord::OnSeelist() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
	CApplerList list;
	list.DoModal();
}

void CFileRecord::SetAppler(BOOL is)
{
	m_IsAppler = is;
}

void CFileRecord::SetApplerId(CString &id)
{
	m_ApplerId = id;
}

BOOL CFileRecord::SetApplerInfo(CString &id)
{
	CADOOperation ado;
	CString sql;
	CString constr;
	SYSTEMTIME sysTime = {0};
	sql.Format("select * from tb_applicant, tb_dept, tb_dept_duty\
		where tb_applicant.applicant_id = '%s' and \
		tb_dept_duty.duty_id = tb_applicant.applicant_duty and \
		tb_dept.dept_id = tb_applicant.applicant_dept", id);
	ado.OpenRecordset(sql);
	ado.GetItemContent("applicant_name", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT2, constr);
	ado.GetItemContent("applicant_sex", CADOOperation::ADO_TYPE_STRING, &constr);
	constr.Replace(" ", "");
	if(constr.Compare("女")==0)
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(1);
	else
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);

	ado.GetItemContent("applicant_eduoflev", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_COMBO2, constr);

	ado.GetItemContent("applicant_address", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT3, constr);
	ado.GetItemContent("applicant_phone", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT6, constr);
	ado.GetItemContent("dept_name", CADOOperation::ADO_TYPE_STRING, &constr);
	CComboBox* dept = (CComboBox*)GetDlgItem(IDC_COMBO4);
	dept->SetCurSel(dept->FindString(0, constr));
	OnSelchangeCombo4();
	ado.GetItemContent("duty_name", CADOOperation::ADO_TYPE_STRING, &constr);
	CComboBox* duty = (CComboBox*)GetDlgItem(IDC_COMBO3);
	duty->SetCurSel(duty->FindString(0, constr));
	ado.GetItemContent("applicant_birthday", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);

	ado.CloseRecorset();
	return TRUE;
}
