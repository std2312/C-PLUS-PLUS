// ApplerInfo.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ApplerInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApplerInfo dialog


CApplerInfo::CApplerInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CApplerInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CApplerInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CApplerInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CApplerInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CApplerInfo, CDialog)
	//{{AFX_MSG_MAP(CApplerInfo)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApplerInfo message handlers

BOOL CApplerInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	CComboBox* pDept = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CFileRecord::InitDeptComboBox(pDept);

	m_CurrentApplerNumber.Replace(" ", "");
	if(!m_CurrentApplerNumber.IsEmpty())
	{
		SetDlgContent(m_CurrentApplerNumber);
		SetModifyModeDlg();
		return TRUE;
	}
	
	OnSelchangeCombo1();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CApplerInfo::OnOK() 
{
	// TODO: Add extra validation here
	if(!m_CurrentApplerNumber.IsEmpty())
	{
		if(SaveModify())
		{
			MessageBox("保存成功！");
			CDialog::OnOK();
			return ;
		}
		return ;
	}
	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	if(!SaveApplicantInfo())
	{
		edit->GetFocus();
		edit->SetSel(0, -1);
	}
	else
	{
		if(IDYES != MessageBox("保存成功！是否继续操作？", "提示", MB_YESNO))
			CDialog::OnOK();
		edit->GetFocus();
		edit->SetSel(0, -1);
	}
}

BOOL CApplerInfo::SaveApplicantInfo()
{
	CADOOperation applicant;
	CString content;
	SYSTEMTIME sysTime;
	BOOL ret = TRUE;
	DWORD number = 0;

	applicant.OpenTable("tb_applicant");
	applicant.AddNew();
	GetDlgItemText(IDC_EDIT1, content);										//得到编号
	ret = applicant.SetItemContent("applicant_id", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}

	GetDlgItemText(IDC_EDIT2, content);										//得到姓名
	ret = applicant.SetItemContent("applicant_name", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}

	GetDlgItemText(IDC_COMBO3, content);									//得到性别
	ret = applicant.SetItemContent("applicant_sex", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);	//得到生日
	ret = applicant.SetItemContent("applicant_birthday", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO2, content);									//得到学历
	ret = applicant.SetItemContent("applicant_eduoflev", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT3, content);										//得到专业
	ret = applicant.SetItemContent("applicant_specialty", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return false;
	}
	GetDlgItemText(IDC_EDIT4, content);										//得到说明
	ret = applicant.SetItemContent("applicant_resume", CADOOperation::ADO_TYPE_TEXT, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT5, content);										//得到籍贯
	ret = applicant.SetItemContent("applicant_nativeplace", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT6, content);										//得到住址
	ret = applicant.SetItemContent("applicant_address", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT7, content);										//得到电话
	ret = applicant.SetItemContent("applicant_phone", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT8, content);										//得到ICQ
	ret = applicant.SetItemContent("applicant_ICO", CADOOperation::ADO_TYPE_STRING, &content);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, content);
	number = CFileRecord::GetDeptNumber(content);
	ret = applicant.SetItemContent("applicant_dept", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO4, content);
	number = CFileRecord::GetDutyNumber(content);
	ret = applicant.SetItemContent("applicant_duty", CADOOperation::ADO_TYPE_INT, &number);
	if(!ret)
	{
		applicant.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT4, content);
	ret = applicant.SetItemContent("applicant_resume", CADOOperation::ADO_TYPE_TEXT, &content);
	if(!ret)
	{
		applicant.CloseRecorset();
		return FALSE;
	}

	applicant.UpdateData();
	applicant.CloseTable();
	return TRUE;
}

void CApplerInfo::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pDept = (CComboBox*)GetDlgItem(IDC_COMBO1), 
		*pDuty = (CComboBox*)GetDlgItem(IDC_COMBO4);
	CString str;
	pDept->GetLBText(pDept->GetCurSel(), str);
	CFileRecord::ShowDutyComboBox(str, pDuty);
}

BOOL CApplerInfo::SetDlgContent(CString &number)
{
	CADOOperation ado;
	CString sql, constr;
	SYSTEMTIME sysTime = {0};
	CComboBox *dept = (CComboBox*)GetDlgItem(IDC_COMBO1), *duty = (CComboBox*)GetDlgItem(IDC_COMBO4);

	sql.Format("\
				  select tb_applicant.applicant_id as id, tb_applicant.applicant_name as name, \
				  tb_applicant.applicant_resume as resume, \
				  tb_applicant.applicant_sex as sex, tb_applicant.applicant_nativeplace as nativeplace,\
				  tb_applicant.applicant_birthday as birthday, tb_applicant.applicant_specialty as specialty, \
				  tb_applicant.applicant_eduoflev as edulev, tb_dept.dept_name as dept,\
				  tb_dept_duty.duty_name as duty,\
				  tb_applicant.applicant_phone as phone, tb_applicant.applicant_address as address, \
				  tb_applicant.applicant_ICO as ICQ\
				  from tb_applicant, tb_dept, tb_dept_duty\
				  where tb_applicant.applicant_dept = tb_dept.dept_id \
				  and tb_applicant.applicant_duty = tb_dept_duty.duty_id and tb_applicant.applicant_id = '%s'", number);
	PRINTRESULT(sql);
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return TRUE;
	}
	
	SetDlgItemText(IDC_EDIT1, number);
	ado.GetItemContent("name", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT2, constr);
	ado.GetItemContent("sex", CADOOperation::ADO_TYPE_STRING, &constr);
	if(0 == constr.Compare("男"))
		((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	else
		((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(1);
	ado.GetItemContent("birthday", CADOOperation::ADO_TYPE_DATE, &sysTime);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->SetTime(&sysTime);
	ado.GetItemContent("edulev", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_COMBO2, constr);
	ado.GetItemContent("specialty", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT3, constr);
	ado.GetItemContent("dept", CADOOperation::ADO_TYPE_STRING, &constr);
	constr.Replace(" ", "");
	dept->SetCurSel(dept->FindString(0, constr.GetBuffer(0)));
	OnSelchangeCombo1();
	ado.GetItemContent("duty", CADOOperation::ADO_TYPE_STRING, &constr);
	duty->SetCurSel(duty->FindString(0, constr.GetBuffer(0)));
	ado.GetItemContent("nativeplace", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT5, constr);
	ado.GetItemContent("address", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT6, constr);
	ado.GetItemContent("phone", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT7, constr);
	ado.GetItemContent("ICQ", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT8, constr);
	ado.GetItemContent("resume", CADOOperation::ADO_TYPE_STRING, &constr);
	SetDlgItemText(IDC_EDIT4, constr);
	ado.CloseRecorset();
	return TRUE;
}

void CApplerInfo::SetCurrentApplerNumber(CString &number)
{
	m_CurrentApplerNumber = number;
}

void CApplerInfo::SetModifyModeDlg()
{
	SetWindowText("修改应聘者信息");
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	SetDlgItemText(IDOK, "修改");
}

BOOL CApplerInfo::SaveModify()
{
	CADOOperation ado;
	CString sql, constr;
	SYSTEMTIME sysTime = {0};
	DWORD serial = -1;

	sql.Format("select * from tb_applicant where applicant_id = '%s'", m_CurrentApplerNumber);
	ado.OpenRecordset(sql);
	GetDlgItemText(IDC_EDIT2, constr);
	ado.SetItemContent("applicant_name", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_COMBO3, constr);
	ado.SetItemContent("applicant_sex", CADOOperation::ADO_TYPE_STRING, &constr);
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ado.SetItemContent("applicant_birthday", CADOOperation::ADO_TYPE_DATE, &sysTime);
	GetDlgItemText(IDC_COMBO2, constr);
	ado.SetItemContent("applicant_eduoflev", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT3, constr);
	ado.SetItemContent("applicant_specialty", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT5, constr);
	ado.SetItemContent("applicant_nativeplace", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT6, constr);
	ado.SetItemContent("applicant_address", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT7, constr);
	ado.SetItemContent("applicant_phone", CADOOperation::ADO_TYPE_STRING, &constr);
	GetDlgItemText(IDC_EDIT8, constr);
	ado.SetItemContent("applicant_ICO", CADOOperation::ADO_TYPE_STRING, &constr);

	GetDlgItemText(IDC_COMBO1, constr);
	serial = CFileRecord::GetDeptNumber(constr);
	ado.SetItemContent("applicant_dept", CADOOperation::ADO_TYPE_INT, &serial);
	GetDlgItemText(IDC_COMBO4, constr);
	serial = CFileRecord::GetDutyNumber(constr);
	ado.SetItemContent("applicant_duty", CADOOperation::ADO_TYPE_INT, &serial);
	GetDlgItemText(IDC_EDIT4, constr);
	ado.SetItemContent("applicant_resume", CADOOperation::ADO_TYPE_TEXT, &constr);
	ado.UpdateData();
	ado.CloseRecorset();

	return TRUE;
}
