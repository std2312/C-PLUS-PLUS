// AgreementListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "AgreementListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAgreementListDlg dialog


CAgreementListDlg::CAgreementListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAgreementListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAgreementListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}

void CAgreementListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAgreementListDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAgreementListDlg, CDialog)
	//{{AFX_MSG_MAP(CAgreementListDlg)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(ID_FIND_EMPLOYEE, OnFindEmployee)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	ON_COMMAND(ID_DELITEM, OnDelitem)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAgreementListDlg message handlers

BOOL CAgreementListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAccel = ::LoadAccelerators(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_DELITEM));

	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT
		| LVS_EX_TWOCLICKACTIVATE
		| LVS_EX_GRIDLINES );

	m_ListCtrl.InsertColumn(0, "编号", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(1, "类型", LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(2, "状态", LVCFMT_LEFT, 40);
	m_ListCtrl.InsertColumn(3, "签约人", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4, "有效期", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5, "生效日期", LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6, "合约条款", LVCFMT_LEFT, 120);
	ShowList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CAgreementListDlg::SetRow(int row, CString *strArray, int count)
{

	m_ListCtrl.InsertItem(row, strArray[0].GetBuffer(0));
	for(int i = 1; i < count; i++)
	{
		if(i == 2)
		{
			switch(atoi(strArray[i]))
			{
			case 0:
				m_ListCtrl.SetItemText(row, i, "有效");
				break;
			case 1:
				m_ListCtrl.SetItemText(row, i, "期满");
				break;
			case 2:
				m_ListCtrl.SetItemText(row, i, "终止");
				break;
			}
		}
		else
			m_ListCtrl.SetItemText(row, i, strArray[i].GetBuffer(0));
	}

	return TRUE;
}

BOOL CAgreementListDlg::DeleteAllRows()
{
	m_ListCtrl.DeleteAllItems();
	return TRUE;
}

BOOL CAgreementListDlg::ShowList()
{
	CADOOperation list;
	CString fields[] = {"bargain_id", "bargain_type", "bargain_state", 
		"bargain_employee", 
		"bargain_useful_life", "bargain_timeofbeceff", "bargain_item"};
	list.OpenTable("tb_bargain");
	list.ShowADOView(fields, 7, this);
	list.CloseTable();
	return TRUE;
}

void CAgreementListDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	m_CurSel = lpnmlv->iItem;
	*pResult = 0;
}

void CAgreementListDlg::OnFindEmployee() 
{
	// TODO: Add your command handler code here
	MessageBox("检索！");
}

void CAgreementListDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CDialog about(IDD_ABOUTBOX);
	about.DoModal();
}

void CAgreementListDlg::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CAgreementListDlg::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	MessageBox("检索");
}

BOOL CAgreementListDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(NULL != m_hAccel)
	{
		if(0 != ::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CAgreementListDlg::OnDelitem() 
{
	// TODO: Add your command handler code here
	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要删除的项！", "提示", MB_OK);
		return ;
	}
	CADOOperation ado;
	ado.OpenTable("tb_bargain");
	ado.DeleteItem(m_CurSel);
	ado.CloseTable();
	ShowList();
	m_CurSel = -1;
}

void CAgreementListDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW lpnmlv = (LPNMLISTVIEW)pNMHDR;
	m_CurSel = lpnmlv->iItem;
	*pResult = 0;
}
