// DlgBookPrice2.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgBookPrice2.h"
#include "KeyEdit.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBookPrice2 dialog

extern _ConnectionPtr m_pCon;  //ADO���Ӷ���
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;

CDlgBookPrice2::CDlgBookPrice2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBookPrice2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBookPrice2)
	//}}AFX_DATA_INIT
}


void CDlgBookPrice2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBookPrice2)
	DDX_Control(pDX, IDC_SELLPRICE, m_sellprice);
	DDX_Control(pDX, IDC_VALUE, m_value);
	DDX_Control(pDX, IDC_QUERY, m_query);
	DDX_Control(pDX, IDC_FIELDS, m_field);
	DDX_Control(pDX, IDC_DETAILLIST, m_list);
	DDX_Control(pDX, IDC_BARCODE, m_barcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBookPrice2, CDialog)
	//{{AFX_MSG_MAP(CDlgBookPrice2)
	ON_CBN_SELCHANGE(IDC_FIELDS, OnSelchangeFields)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_NOTIFY(NM_DBLCLK, IDC_DETAILLIST, OnDblclkDetaillist)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBookPrice2 message handlers

BOOL CDlgBookPrice2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//set the sytle of m_list
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_GRIDLINES);
	//insert column to m_list ,set column text and column width

	m_list.InsertColumn(0,"������",LVCFMT_LEFT,100);
	m_list.InsertColumn(1,"�鼮����",LVCFMT_LEFT,100);
	m_list.InsertColumn(2,"������",LVCFMT_LEFT,60);
	m_list.InsertColumn(3,"����",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"������",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,"�۸�",LVCFMT_LEFT,80);

	//set edit control color
	m_barcode.SetEditTextColor(RGB(0,0,255));
	m_sellprice.SetEditTextColor(RGB(0,0,255));

	//allow edit control to keyed number only
	m_barcode.IsNumber= true;
	m_sellprice.IsNumber = true;

	return TRUE; 
}

void CDlgBookPrice2::OnSelchangeFields() 
{
	//CString str = m_field.GetWindowText();
	int index = m_field.GetCurSel();
	if (index != -1)
	{
		CString field;
		switch (index)
		{
			case 0: 
			{
				field ="bookname";
				break;
			}
			case 1: 
			{
				field = "barcode";
				break;
			}
			case 2: 
			{
				field = "author";
				break;
			}
		}
		CString sql;
		sql.Format("select distinct %s from tb_bookinfo",field);
		m_pRs->raw_Close();
		m_pRs = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
		m_value.ResetContent(); // delete all items
		while (!m_pRs->adoEOF)
		{
			m_value.AddString((_bstr_t)m_pRs->GetCollect((long)0).bstrVal);	
			m_pRs->MoveNext();
		}

	}
}

void CDlgBookPrice2::OnQuery() 
{
	m_list.DeleteAllItems();
	m_barcode.SetWindowText("");
	m_sellprice.SetWindowText("");
	
	//judge combobox text is or not null
	CString c_field,c_value,field;
	m_field.GetWindowText(c_field);
	m_value.GetWindowText(c_value);
	
	if ((c_field.IsEmpty())||(c_value.IsEmpty()))
	{
		AfxMessageBox("��ѯ����������.",IDOK,0);
		return;
	}
	// begin querying
	
	int index = m_field.GetCurSel();
	if (index != -1)
	{
		switch (index)
		{
			case 0: 
			{
				field ="bookname";
				break;
			}
			case 1: 
			{
				field = "barcode";
				break;
			}
			case 2: 
			{
				field = "author";
				break;
			}
		}
	}
	CString sql;
	sql.Format("select barcode,bookname,shortname,author,bookconcern,price from tb_bookinfo where barcode not in (select barcode from tb_fixprice) and %s = '%s'",field,c_value);
	m_pRs = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int row = 0;
	while (! m_pRs->adoEOF)
	{
		m_list.InsertItem(1000,"");
		for (int i = 0;i <m_pRs->GetFields()->Count;i++)
		{
			CString temp = (TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
			m_list.SetItemText(row,i,temp);
		}
		row +=1;
		m_pRs->MoveNext();
	}

}

void CDlgBookPrice2::OnDblclkDetaillist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row != -1)//row is selected in m_list
	{
		m_barcode.SetWindowText(m_list.GetItemText(row,0));
	}
	else
		m_barcode.SetWindowText("");
	
	*pResult = 0;
}

void CDlgBookPrice2::BookFixPrice()
{
	CString barcode;
	m_barcode.GetWindowText(barcode);
	if (!barcode.IsEmpty())
	{
		CString c_sellprice;
		m_sellprice.GetWindowText(c_sellprice);
		if (c_sellprice.IsEmpty())
		{
			AfxMessageBox("������ͼ���ۼ�.",IDOK,0);
			return;
		}
		float f_sellprice =atof(c_sellprice);
		CString sql;
		sql.Format("insert into tb_fixprice values ('%s',%f)",barcode,f_sellprice);
		try
		{
			m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
			CancelOperate();
			MessageBox("�����ɹ�.","��ʾ",64);
		}
		catch(...)
		{
			MessageBox("����ʧ��.","��ʾ",64);
		}		
	}
	else
	{
		AfxMessageBox("���ڱ����ѡ������",IDOK,0);
	}
}

void CDlgBookPrice2::CancelOperate()
{
	m_list.DeleteAllItems();
	m_field.SetCurSel(0);
	m_value.SetCurSel(-1);
	m_barcode.SetWindowText("");
	m_sellprice.SetWindowText("");
}

void CDlgBookPrice2::OnAdd() 
{
	BookFixPrice();
	
}

void CDlgBookPrice2::OnCancel() 
{
	CancelOperate();	
}

void CDlgBookPrice2::OnExit() 
{
	CDialog::OnCancel();	
}
