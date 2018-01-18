// DlgInputBackQuery3.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgInputBackQuery3.h"
#include "PrintDoc.h"
#include "PrintFram.h"
#include "PrintView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO���Ӷ���
extern _RecordsetPtr m_pRs; 
extern CBbbApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgInputBackQuery3 dialog


CDlgInputBackQuery3::CDlgInputBackQuery3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputBackQuery3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInputBackQuery3)
	//}}AFX_DATA_INIT
}


void CDlgInputBackQuery3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInputBackQuery3)
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_endtime);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_value);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_strtime);
	DDX_Control(pDX, IDC_COMBO1, m_fields);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInputBackQuery3, CDialog)
	//{{AFX_MSG_MAP(CDlgInputBackQuery3)
	ON_BN_CLICKED(IDC_check, Oncheck)
	ON_BN_CLICKED(IDC_print, Onprint)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInputBackQuery3 message handlers

void CDlgInputBackQuery3::CancelQuery()
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

BOOL CDlgInputBackQuery3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_INFOTIP|LVS_EX_SUBITEMIMAGES|LVS_EX_GRIDLINES );
	
	//�����������
	m_list.InsertColumn(0,"�˻�����");

	m_list.InsertColumn(1,"�鼮����");

	m_list.InsertColumn(2,"������");

	m_list.InsertColumn(3,"����");

	m_list.InsertColumn(4,"������");

	m_list.InsertColumn(5,"����");

	m_list.InsertColumn(6,"����");

	m_list.SetColumnWidth(0,100);
	m_list.SetColumnWidth(1,100);
	m_list.SetColumnWidth(2,100);
	m_list.SetColumnWidth(3,80);
	m_list.SetColumnWidth(4,80);
	m_list.SetColumnWidth(5,60);
	m_list.SetColumnWidth(6,60);

	arrays[1] ="ͼ������";
	arrays[2] ="������";
	arrays[3] ="����";
	arrays[4] ="������";
	arrays[5] ="�۸�";
	arrays[6] ="����";	
	arrays[0] ="��ⵥ��";	
	CancelQuery();
	
	return TRUE;  
}

void CDlgInputBackQuery3::OnOK()
{
//
}

BOOL CDlgInputBackQuery3::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==	WM_KEYDOWN)
		if (pMsg->wParam ==13)
			pMsg->wParam =9;	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgInputBackQuery3::Print()
{
	CBbbApp * app=(CBbbApp*)AfxGetApp();
	app->m_main =app->m_pMainWnd;
	app->m_pMainWnd = NULL;

	report.m_plist = &m_list;
	report.verinterval = 20;
	report.title = "����˻���";
	report.fields = arrays;
	report.lmargin = 40;
	report.rmargin = 40;
	report.framtilte = "��ӡ";

	app->m_pDocManager->OnFileNew();

	CPrintFram * temp=(CPrintFram*)app->m_pMainWnd;
	temp->SetTitle(report.framtilte);
}

void CDlgInputBackQuery3::Query()
{
	if ((m_check1.GetCheck() ==false)&&(m_check2.GetCheck()==false))
	{
		MessageBox("�����ò�ѯ����","��ʾ",64);
		return;
	}
	if ( (m_check1.GetCheck()==true)&&(m_check2.GetCheck()==false))
	{
		CString c_field,c_value;
		m_fields.GetWindowText(c_field);
		m_value.GetWindowText(c_value);
		if (c_field.IsEmpty()||(c_value.IsEmpty()))
		{
			MessageBox("�����ò�ѯ����","��ʾ",64);
			return;
		}
		CString sql;
		m_list.DeleteAllItems();
		switch (m_fields.GetCurSel())
		{
			case 0: 
			{ 
				c_field = "bookname"; 
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and b.%s = '%s' ",c_field,c_value);
				break;
			}
			case 1: 
			{ 
				c_field = "barcode";
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and b.%s = '%s' ",c_field,c_value);
				break;
			}
			case 2: 
			{ 
				c_field = "cancelid";
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and a.%s = '%s' ",c_field,c_value);
				break;
			}
			case 3:
			{ 
				c_field = "Operator" ;
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode inner join tb_cancelinstock_main c  on a.cancelid = c.cancelid and  c.%s = '%s' ",c_field,c_value);		
				break;
			}
			case 4:
			{ 
				c_field = "provider" ;
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode inner join tb_cancelinstock_main c  on a.cancelid = c.cancelid and  c.%s = '%s' ",c_field,c_value);		
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
			for (int i = 0;i<7;i++)
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

		sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and c.intime between '%s' and '%s' ",c_starttime,c_endtime);
		
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		int row = 0;
		while (! m_pRs->adoEOF)
		{
			CString temp;
			m_list.InsertItem(1000,"");
			for (int i = 0;i<7;i++)
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
			MessageBox("�����ò�ѯ����","��ʾ",64);
			return;
		}
		CString sql,c_starttime,c_endtime;
		m_strtime.GetWindowText(c_starttime);
		m_endtime.GetWindowText(c_endtime);
		if (c_field.IsEmpty()||(c_value.IsEmpty()))
		{
			MessageBox("�����ò�ѯ����","��ʾ",64);
			return;
		}
		m_list.DeleteAllItems();
		switch (m_fields.GetCurSel())
		{
			case 0: 
			{ 
				c_field = "bookname"; 
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and b.%s = '%s' inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and c.intime between '%s' and '%s' ",c_field,c_value,c_starttime,c_endtime);
				break;
			}
			case 1: 
			{ 
				c_field = "barcode";
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and b.%s = '%s' inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and c.intime between '%s' and '%s' ",c_field,c_value,c_starttime,c_endtime);
				break;
			}
			case 2: 
			{ 
				c_field = "cancelid";
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode and a.%s = '%s' inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and c.intime between '%s' and '%s' ",c_field,c_value,c_starttime,c_endtime);
				break;
			}
			case 3:
			{ 
				c_field = "Operator" ;
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and c.%s = '%s' and c.intime between '%s' and '%s' ",c_field,c_value,c_starttime,c_endtime);
				break;
			}
			case 4:
			{ 
				c_field = "provider" ;
				sql.Format(" select a.cancelid,b.bookname,b.barcode,b.author,b.bookconcern,a.unitprice,a.numbers from tb_cancelinstock_sub a inner join tb_bookinfo b on a.barcode = b.barcode  inner join tb_cancelinstock_main c on a.cancelid = c.cancelid and  c.%s = '%s' and  c.intime between '%s' and '%s' ",c_field,c_value,c_starttime,c_endtime);
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
			for (int i = 0;i<7;i++)
			{
				temp = (TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem((long)i)->Value;
				m_list.SetItemText(row,i,temp);
			}
			m_pRs->MoveNext();
			row +=1;
		}	
	}
}

void CDlgInputBackQuery3::Oncheck() 
{
	Query();
	
}

void CDlgInputBackQuery3::OnCancel() 
{
	CancelQuery();
	
}

void CDlgInputBackQuery3::Onprint() 
{
	Print();
	
}

void CDlgInputBackQuery3::OnExit() 
{
	CDialog::OnCancel();	
}


