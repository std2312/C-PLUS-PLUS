// ReqCheckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "ReqCheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReqCheckDlg dialog


CReqCheckDlg::CReqCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReqCheckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReqCheckDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReqCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReqCheckDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReqCheckDlg, CDialog)
	//{{AFX_MSG_MAP(CReqCheckDlg)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReqCheckDlg message handlers

void CReqCheckDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(SaveReqChk())
	{
		MessageBox("±£´æ³É¹¦£¡");
		CDialog::OnOK();
		return ;
	}
}

BOOL CReqCheckDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	InitReqNumberComboBox((CString)"");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CReqCheckDlg::SaveReqChk()
{
	BOOL ret = TRUE;
	CString constr;
	CADOOperation ado;
	SYSTEMTIME sysTime = {0};
	ado.OpenTable("tb_req_chk");
	ado.AddNew();
	GetDlgItemText(IDC_COMBO2, constr);
	ret = ado.SetItemContent("chk_num", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_EDIT12, constr);
	ret = ado.SetItemContent("chk_sjt", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_EDIT10, constr);
	ret = ado.SetItemContent("chk_pal", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_COMBO3, constr);
	ret = ado.SetItemContent("chk_stl", CADOOperation::ADO_TYPE_STRING, &constr);
	if(!ret)
		goto end;
	GetDlgItemText(IDC_EDIT11, constr);
	ret = ado.SetItemContent("chk_ade", CADOOperation::ADO_TYPE_TEXT, &constr);
	if(!ret)
		goto end;
	((CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1))->GetTime(&sysTime);
	ret = ado.SetItemContent("chk_dte", CADOOperation::ADO_TYPE_DATE, &sysTime);
	if(!ret)
		goto end;
	ado.UpdateData();
end:
	ado.CloseTable();
	return ret;
}

void CReqCheckDlg::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	CString constr;
	GetDlgItemText(IDC_EDIT2, constr);
	InitReqNumberComboBox(constr);
}

BOOL CReqCheckDlg::InitReqNumberComboBox(CString &name)
{
	BOOL ret = TRUE;
	CADOOperation ado;
	CString sql, constr;

	CComboBox *com = (CComboBox*)GetDlgItem(IDC_COMBO2);
	com->ResetContent();

	if(name.IsEmpty())
		sql.Format("select applicant_id from tb_applicant");
	else
		sql.Format("select applicant_id from tb_applicant where  applicant_name = '%s'", name);
	ado.OpenRecordset(sql);
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return ret;
	}
	do
	{
		ret = ado.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &constr);
		if(!ret)
			goto end;
		com->AddString(constr);
		ado.MoveNext();
	}while(!ado.IsLastRow());
end:
	ado.CloseRecorset();
	com->SetCurSel(0);
	return ret;
}
