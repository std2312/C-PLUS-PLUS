// TimeCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "TimeCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeCardDlg dialog


CTimeCardDlg::CTimeCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeCardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsAbsence = FALSE;
}


void CTimeCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeCardDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeCardDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeCardDlg)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeCardDlg message handlers

BOOL CTimeCardDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
	IsAbsence(FALSE);


	//初始化员工姓名组合框
	CComboBox* pCom = (CComboBox* )GetDlgItem(IDC_COMBO1);
	InitEmployeeList(pCom);
	OnSelchangeCombo1();
	SetDlgItemText(IDC_EDIT2, "0");
	SetDlgItemText(IDC_EDIT1, "8");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTimeCardDlg::OnOK() 
{
	// TODO: Add extra validation here
	BOOL ret = FALSE;
	ret =  SaveTimeCard();
	if(!ret)
	{
		MessageBox("每人每天只能有一次考勤！");
		return ;
	}
	CDialog::OnOK();
}

void CTimeCardDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("sdafsa");
	if(!m_IsAbsence)
	{
		IsAbsence(TRUE);
		m_IsAbsence = TRUE;
	}
}

void CTimeCardDlg::IsAbsence(BOOL abs)
{
	
	if(abs)
	{
		GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO5)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);

		return ;
	}
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);

}

void CTimeCardDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	if(m_IsAbsence)
	{
		IsAbsence(FALSE);
		m_IsAbsence = FALSE;
	}
}

DWORD CTimeCardDlg::GetLeaveStyle()
{
	DWORD style = 0;		//没请假为0
	if(!m_IsAbsence)
		return 0;

	if(1 == ((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck())
		style = 1;			//事假为1
	else if(1 == ((CButton*)GetDlgItem(IDC_RADIO4))->GetCheck())
		style = 2;			//公假为2
	else if(1 == ((CButton*)GetDlgItem(IDC_RADIO5))->GetCheck())
		style = 3;			//病假为3

	return style;
}



BOOL CTimeCardDlg::SaveTimeCard()
{
	CADOOperation tmCard;
	BOOL ret;
	SYSTEMTIME sysTime = {0};
	CString name, id;
	int hour, minute, lStyle, absState, worklong = 0;

	hour	= GetDlgItemInt(IDC_EDIT1);
	minute	= GetDlgItemInt(IDC_EDIT2);
	if(hour > 8)
	{
		MessageBox("每天工作小于8小时！", "提示", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	if(minute > 60)
	{
		MessageBox("一小时只有60分钟！", "提示", MB_OK | MB_ICONWARNING);
		return FALSE;
	}

	ret = tmCard.OpenTable("tb_timecard");
	if(!ret)
		return FALSE;
	tmCard.AddNew();
	::GetSystemTime(&sysTime);					//保存出勤卡日期
	ret = tmCard.SetItemContent("timecart_date", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
	{
		tmCard.CloseTable();
		return FALSE;
	}
	GetDlgItemText(IDC_COMBO1, name);
	id = GetEmployIDByName(name);				//保存签到员工ID号
	ret = tmCard.SetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &id);
	if(!ret)
	{
		tmCard.CloseTable();
		return FALSE;
	}
	worklong = hour*60 + minute;				//保存员工工作时间
	ret = tmCard.SetItemContent("timecart_worklong", CADOOperation::ADO_TYPE_INT, &worklong);
	if(!ret)
	{
		tmCard.CloseTable();
		return FALSE;
	}
	lStyle = GetLeaveStyle();					//是否迟到早退
	tmCard.SetItemContent("timecart_reason", CADOOperation::ADO_TYPE_INT, &lStyle);
	absState = GetAbsenceState();
	tmCard.SetItemContent("timecart_late_leave_early", CADOOperation::ADO_TYPE_INT, &absState);

	ret = tmCard.UpdateData();
	if(!ret)
	{
		tmCard.CloseTable();
		return FALSE;
	}
	ret = tmCard.CloseTable();
	if(!ret)
		return FALSE;

	return TRUE;
}

CString CTimeCardDlg::GetEmployIDByName(CString name)
{
	CString id, sql;
	CADOOperation emp;
	BOOL ret;

	sql.Format("select employee_id from tb_employee where employee_name = '%s'", name);
	emp.OpenRecordset(sql);
	if(emp.IsLastRow())
	{
		emp.CloseRecorset();
		return "";
	}
	ret = emp.GetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &id);
	if(!ret)
	{
		emp.CloseRecorset();
		return "";
	}
	emp.CloseRecorset();

	return id;
}

DWORD CTimeCardDlg::GetAbsenceState()
{
	DWORD absState = 0;

	if(1 == ((CButton* )GetDlgItem(IDC_CHECK1))->GetCheck())
		absState |= 1;			//迟到最低位置1
	if(1 == ((CButton* )GetDlgItem(IDC_CHECK2))->GetCheck())
		absState |= 2;			//早退倒数第二位置1

	return absState;
}

BOOL CTimeCardDlg::InitEmployeeList(CComboBox *pCom)
{
	CADOOperation emp;
	CString con;
	emp.OpenRecordset("select employee_name from tb_employee");
	if(emp.IsLastRow())
	{
		emp.CloseRecorset();
		return TRUE;
	}
	emp.MoveFirst();
	do
	{
		emp.GetItemContent("employee_name", CADOOperation::ADO_TYPE_STRING, &con);
		pCom->AddString(con);
		emp.MoveNext();
	}
	while(!emp.IsLastRow());
	emp.CloseRecorset();
	pCom->SetCurSel(0);
	pCom->SetEditSel(0, -1);

	return TRUE;
}

void CTimeCardDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

CString CTimeCardDlg::GetLeaveItem(CString &num)
{
	CString str, sql;
	_ConnectionPtr con;
	_RecordsetPtr rec;
	VARIANT var;
	try
	{
		con.CreateInstance(_uuidof(Connection));
		con->Open(_bstr_t(Provider), "", "", adModeUnknown);
		rec.CreateInstance(_uuidof(Recordset));
		sql.Format("\
					  select req_stl from tb_req_leave, tb_employee where (getdate() between req_frm and req_to) \
					  and tb_employee.employee_name = '%s'  and tb_employee.employee_id = req_emp", num);
		PRINTRESULT(sql);
		rec->Open(_bstr_t(sql), con.GetInterfacePtr(), adOpenDynamic, 
			adLockOptimistic, adCmdText);
		if(rec->adoEOF)
		{
			rec->Close();
			con->Close();
			return "";
		}
		var = rec->GetCollect(_variant_t((long)0));
		if(VT_NULL == var.vt)
			return "";
		rec->Close();
		con->Close();
	}
	catch(_com_error e)
	{
		MessageBox(e.Description());
		return str;
	}
	str = (char*)_bstr_t(var);
	return str;
}

void CTimeCardDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CComboBox *com = (CComboBox*)GetDlgItem(IDC_COMBO1);
	com->GetLBText(com->GetCurSel(), str);
	str = GetLeaveItem(str);
	if(str.IsEmpty())
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		IsAbsence(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);
		IsAbsence(TRUE);
		if(0 == str.Compare("病假"))
		{
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(0);
		}
		if(0 == str.Compare("事假"))
		{
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(1);
		}
		if(0 == str.Compare("其它"))
		{
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(1);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(0);
		}
	}

	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	edit->SetFocus();
	edit->SetSel(0, -1);
}
