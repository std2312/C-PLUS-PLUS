// DlgSaleQuery3.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgSaleQuery3.h"
#include "PrintDoc.h"
#include "PrintFram.h"
#include "PrintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern CBbbApp theApp;

extern CReport report;
/////////////////////////////////////////////////////////////////////////////
// CDlgSaleQuery3 dialog


CDlgSaleQuery3::CDlgSaleQuery3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSaleQuery3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSaleQuery3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSaleQuery3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSaleQuery3)
	DDX_Control(pDX, IDC_EDIT1, m_value);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_endtime);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_strtime);
	DDX_Control(pDX, IDC_COMBO1, m_fields);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSaleQuery3, CDialog)
	//{{AFX_MSG_MAP(CDlgSaleQuery3)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_check, Oncheck)
	ON_BN_CLICKED(IDC_print, Onprint)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSaleQuery3 message handlers

BOOL CDlgSaleQuery3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_INFOTIP|LVS_EX_SUBITEMIMAGES|LVS_EX_GRIDLINES );
	
	//向表格中添加列
	m_list.InsertColumn(0,"书籍名称");

	m_list.InsertColumn(1,"条形码");

	m_list.InsertColumn(2,"作者");

	m_list.InsertColumn(3,"出版社");

	m_list.InsertColumn(4,"定价");

	m_list.InsertColumn(5,"数量");

	m_list.SetColumnWidth(0,150);
	m_list.SetColumnWidth(1,100);
	m_list.SetColumnWidth(2,100);
	m_list.SetColumnWidth(3,100);
	m_list.SetColumnWidth(4,80);
	m_list.SetColumnWidth(5,75);

	arrays[0] ="图书名称";
	arrays[1] ="条形码";
	arrays[2] ="作者";
	arrays[3] ="出版社";
	arrays[4] ="定价";
	arrays[5] ="数量";	
	CancelQuery();
	return TRUE;  
}

BOOL CDlgSaleQuery3::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==	WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam =9;
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgSaleQuery3::CancelQuery()
{
	m_check1.SetCheck(0);
	m_check2.SetCheck(0);
	m_fields.SetCurSel(-1);
	m_value.SetWindowText("");
	CTime temp = CTime::GetCurrentTime();
	m_strtime.SetTime(&temp);
	m_endtime.SetTime(&temp);
	m_list.DeleteAllItems();
}

void CDlgSaleQuery3::Query()
{
	if ((m_check1.GetCheck() ==false)&&(m_check2.GetCheck()==false))
	{
		MessageBox("请设置查询条件","提示",64);
		return;
	}
	if ( (m_check1.GetCheck()==true)&&(m_check2.GetCheck()==false))
	{
		CString c_field,c_value;
		m_fields.GetWindowText(c_field);
		m_value.GetWindowText(c_value);
		if (c_field.IsEmpty()||(c_value.IsEmpty()))
		{
			MessageBox("请设置查询条件","提示",64);
			return;
		}
		CString sql;
		m_list.DeleteAllItems();
		switch (m_fields.GetCurSel())
		{
			case 0: 
			{ 
				c_field = "bookname"; 
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub group by barcode)as b  on a.barcode = b.barcode and a.bookname = '%s' order by b.numbers desc",c_value);
				break;
			}
			case 1: 
			{ 
				c_field = "barcode";
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub group by barcode)as b  on a.barcode = b.barcode and a.barcode = '%s' order by b.numbers desc",c_value);
				break;
			}
			case 2: 
			{ 
				c_field = "author";
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub group by barcode)as b  on a.barcode = b.barcode and a.author = '%s' order by b.numbers desc",c_value);
				break;
			}
			case 3:
			{ 
				c_field = "bookconcern" ;
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub group by barcode)as b  on a.barcode = b.barcode and a.bookconcern = '%s' order by b.numbers desc",c_value);
				break;
			}
		}
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		int row = 0;
		while (! m_pRs->adoEOF)
		{
			CString temp;
			m_list.InsertItem(1000,"");
			for (int i = 0;i<6;i++)
			{
				temp = (TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
				m_list.SetItemText(row,i,temp);
			}
			m_pRs->MoveNext();
			row +=1;
		}		
	}
	else if ((m_check1.GetCheck()==false)&&(m_check2.GetCheck()==true))
	{
		m_list.DeleteAllItems();
		CString sql,c_starttime,c_endtime;
		m_strtime.GetWindowText(c_starttime);
		m_endtime.GetWindowText(c_endtime);

		sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub where sellid in ( select sellid from tb_sell_main where intime between  '%s'and '%s' ) group by barcode )as b  on a.barcode = b.barcode order by b.numbers desc",c_starttime,c_endtime);
		
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		int row = 0;
		while (! m_pRs->adoEOF)
		{
			CString temp;
			m_list.InsertItem(1000,"");
			for (int i = 0;i<6;i++)
			{
				temp = (TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
				m_list.SetItemText(row,i,temp);
			}
			m_pRs->MoveNext();
			row +=1;
		}				
	}
	else
	{
		CString c_field,c_value;
		m_fields.GetWindowText(c_field);
		m_value.GetWindowText(c_value);
		if (c_field.IsEmpty()||(c_value.IsEmpty()))
		{
			MessageBox("请设置查询条件","提示",64);
			return;
		}
		CString sql,c_starttime,c_endtime;
		m_strtime.GetWindowText(c_starttime);
		m_endtime.GetWindowText(c_endtime);
		if (c_field.IsEmpty()||(c_value.IsEmpty()))
		{
			MessageBox("请设置查询条件","提示",64);
			return;
		}
		m_list.DeleteAllItems();
		switch (m_fields.GetCurSel())
		{
			case 0: 
			{ 
				c_field = "bookname"; 
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub where sellid in (select sellid from tb_sell_main where intime between '%s' and '%s') group by barcode)as b  on a.barcode = b.barcode and a.bookname = '%s' order by b.numbers desc",c_starttime,c_endtime, c_value);
				break;
			}
			case 1: 
			{ 
				c_field = "barcode";
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub where sellid in (select sellid from tb_sell_main where intime between '%s' and '%s') group by barcode)as b  on a.barcode = b.barcode and a.barcode = '%s' order by b.numbers desc",c_starttime,c_endtime, c_value);
				break;
			}
			case 2: 
			{ 
				c_field = "author";
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub where sellid in (select sellid from tb_sell_main where intime between '%s' and '%s') group by barcode)as b  on a.barcode = b.barcode and a.author = '%s' order by b.numbers desc",c_starttime,c_endtime, c_value);
				break;
			}
			case 3:
			{ 
				c_field = "bookconcern" ;
				sql.Format("select a.bookname,a.barcode,a.author,a.bookconcern,a.price,b.numbers from tb_bookinfo a inner join (select barcode,sum(numbers) numbers from tb_sell_sub where sellid in (select sellid from tb_sell_main where intime between '%s' and '%s') group by barcode)as b  on a.barcode = b.barcode and a.bookconcern = '%s' order by b.numbers desc",c_starttime,c_endtime, c_value);
				break;
			}
		}
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		int row = 0;
		while (! m_pRs->adoEOF)
		{
			CString temp;
			m_list.InsertItem(1000,"");
			for (int i = 0;i<6;i++)
			{
				temp = (TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
				m_list.SetItemText(row,i,temp);
			}
			m_pRs->MoveNext();
			row +=1;
		}	
	}
}


void CDlgSaleQuery3::Print()
{
	CBbbApp * app=(CBbbApp*)AfxGetApp();
	app->m_main =app->m_pMainWnd;
	app->m_pMainWnd = NULL;

	report.m_plist = &m_list;
	report.verinterval = 20;
	report.title = "图书销售排行";
	report.fields = arrays;
	report.lmargin = 40;
	report.rmargin = 40;
	report.framtilte = "打印";

	app->m_pDocManager->OnFileNew();

	CPrintFram * temp=(CPrintFram*)app->m_pMainWnd;
	temp->SetTitle(report.framtilte);
}

void CDlgSaleQuery3::OnClose() 
{
	//CWnd * temp = AfxGetMainWnd();
	CDialog::OnClose();
}


void CDlgSaleQuery3::Oncheck() 
{
	Query();
	
}

void CDlgSaleQuery3::OnCancel() 
{
	CancelQuery();	
}

void CDlgSaleQuery3::Onprint() 
{
	Print();	
}

void CDlgSaleQuery3::OnExit() 
{
	CDialog::OnCancel();	
}
