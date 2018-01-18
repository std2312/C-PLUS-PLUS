// LaborRecorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "LaborRecorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLaborRecorDlg dialog


CLaborRecorDlg::CLaborRecorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborRecorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLaborRecorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLaborRecorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLaborRecorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLaborRecorDlg, CDialog)
	//{{AFX_MSG_MAP(CLaborRecorDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLaborRecorDlg message handlers

BOOL CLaborRecorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitEmpNumCom((CComboBox*)GetDlgItem(IDC_COMBO2));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLaborRecorDlg::InitEmpNumCom(CComboBox *box)
{
	CADOOperation ado;
	CString con;

	box->ResetContent();
	ado.OpenRecordset("select employee_id from tb_employee");
	if(ado.IsLastRow())
	{
		ado.CloseRecorset();
		return TRUE;
	}
	do
	{
		ado.GetItemContent(0, CADOOperation::ADO_TYPE_STRING, &con);
		box->AddString(con.GetBuffer(0));
		ado.MoveNext();
	}while(!ado.IsLastRow());
	ado.CloseRecorset();
	box->SetCurSel(0);
	return TRUE;
}

void CLaborRecorDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(SaveInfo())
	{
		if(IDYES == MessageBox("保存成功！是否继续操作？", "提示", MB_YESNO))
		{
			CComboBox * com = (CComboBox*)GetDlgItem(IDC_COMBO2);
			com->SetFocus();
			com->SetCurSel(0);
			return ;
		}
		CDialog::OnOK();
		return ;
	}

	MessageBox("不要为同一名员工输入两次工资记录！", "提示", MB_OK);
}

BOOL CLaborRecorDlg::SaveInfo()
{
	CADOOperation ado;
	CString con;
	float fl;
	BOOL ret = FALSE;

	ado.OpenTable("tb_laborage");
	ado.AddNew();
	GetDlgItemText(IDC_COMBO2, con);
	ret = ado.SetItemContent("employee_id", CADOOperation::ADO_TYPE_STRING, &con);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT10, con);
	fl = (float)atof(con);
	ret = ado.SetItemContent("base_laborage", CADOOperation::ADO_TYPE_FLOAT, &fl);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT13, con);
	fl = (float)atof(con);
	ret = ado.SetItemContent("duty_laborage", CADOOperation::ADO_TYPE_FLOAT, &fl);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT12, con);
	fl = (float)atof(con);
	ret = ado.SetItemContent("leser_laborage", CADOOperation::ADO_TYPE_FLOAT, &fl);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT11, con);
	fl = (float)atof(con);
	ret = ado.SetItemContent("insurance", CADOOperation::ADO_TYPE_FLOAT, &fl);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	GetDlgItemText(IDC_EDIT14, con);
	fl = (float)atof(con);
	ret = ado.SetItemContent("recoup", CADOOperation::ADO_TYPE_FLOAT, &fl);
	if(!ret)
	{
		ado.CloseRecorset();
		return FALSE;
	}
	ado.UpdateData();
	ado.CloseTable();

	return ret;
}
