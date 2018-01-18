// FindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "FindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog


CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	//{{AFX_MSG_MAP(CFindDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDlg message handlers

BOOL CFindDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CString CFindDlg::GetSearchExpression()
{
	return m_SearchExpression;
}

void CFindDlg::OnOK() 
{
	// TODO: Add extra validation here
	int curSel = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	CString condition, field;
	GetDlgItemText(IDC_EDIT1, condition);
	switch(curSel)
	{
	case 0:			field = "ch_employee";			break;
	case 1:			field = "ch_employee";			break;

	case 2:			field = "ch_source";			break;
	case 3:			field = "ch_duty_source";		break;

	case 4:			field = "ch_destination";		break;
	case 5:			field = "ch_duty_Destination";	break;
	default:
		return ;
	}
	switch(curSel)
	{
	case 0:
		{
			CString id;
			id = CTimeCardDlg::GetEmployIDByName(condition);
			m_SearchExpression.Format("%s = '%s'", field, id);
		}
		break;
	case 1:
		m_SearchExpression.Format("%s = '%s'", field, condition);
		break;
	case 2:case 4:
		{
			DWORD deptSerail;
			deptSerail = CFileRecord::GetDeptNumber(condition);
			if(deptSerail < 1)
			{
				MessageBox("公司没目前有该部门！", "提示", MB_OK | MB_ICONWARNING);
				return ;
			}
			m_SearchExpression.Format("%s = %d", field, deptSerail);
		}
		break;
	case 3:case 5:
		{
			DWORD dutySerail;
			dutySerail = CFileRecord::GetDutyNumber(condition);
			if(dutySerail < 1)
			{
				MessageBox("公司目前没有该职务！", "提示", MB_OK | MB_ICONWARNING);
				return ;
			}
			m_SearchExpression.Format("%s = %d", field, dutySerail);
		}
		break;
	}
	CDialog::OnOK();
}
