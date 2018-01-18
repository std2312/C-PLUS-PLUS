// LeaveItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LeaveItemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeaveItemDlg dialog


CLeaveItemDlg::CLeaveItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLeaveItemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeaveItemDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLeaveItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeaveItemDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeaveItemDlg, CDialog)
	//{{AFX_MSG_MAP(CLeaveItemDlg)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeaveItemDlg message handlers

void CLeaveItemDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(SaveLeaveItem())
	{
		MessageBox("±£´æ³É¹¦£¡");
		CDialog::OnOK();
		return ;
	}
	return ;
}

BOOL CLeaveItemDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLeaveItemDlg::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	CComboBox *num = (CComboBox*)GetDlgItem(IDC_COMBO3);
	CString name;
	GetDlgItemText(IDC_EDIT1, name);
	InitNumberComboBox(name, num);
}

BOOL CLeaveItemDlg::SaveLeaveItem()
{
	BOOL ret = TRUE;
	CADOOperation ado;
	CString constr;
	SYSTEMTIME sysTime = {0};

	ado.OpenTable("tb_req_leave");
	ado.AddNew();
	GetDlgItemText(IDC_COMBO3, constr);
	ret = ado.SetItemContent("req_emp", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_COMBO2, constr);
	ret = ado.SetItemContent("req_stl", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	//GetDlgItem
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2))->GetTime(&sysTime);
	ret = ado.SetItemContent("req_frm", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
		goto end;
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER3))->GetTime(&sysTime);
	ret = ado.SetItemContent("req_to", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
		goto end;
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ret = ado.SetItemContent("req_date", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_EDIT11, constr);
	ret = ado.SetItemContent("req_res", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_EDIT10, constr);
	ret = ado.SetItemContent("req_lng", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;

	ado.UpdateData();
end:
	ado.CloseTable();
	return ret;
}

BOOL CLeaveItemDlg::InitNumberComboBox(CString &name, CComboBox *pCmbx)
{
	CADOOperation  ado;
	CString sql, con;

	pCmbx->ResetContent();
	if(!name.IsEmpty())
		sql.Format("select employee_id from tb_employee where employee_name = '%s'", name);
	else
		sql.Format("select employee_id from tb_employee");
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return TRUE;
	}
	do
	{
		if(!ado.GetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &con))
		{
			ado.CloseRecorset();
			return FALSE;
		}
		pCmbx->AddString(con);
		ado.MoveNext();
	}while(!ado.IsLastRow());
	ado.CloseRecorset();
	pCmbx->SetCurSel(0);

	return TRUE;
}
