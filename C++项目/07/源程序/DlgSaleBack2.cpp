// DlgSaleBack2.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgSaleBack2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _RecordsetPtr m_pRs1; 
extern _CommandPtr m_pCom;
extern CString user;
/////////////////////////////////////////////////////////////////////////////
// CDlgSaleBack2 dialog


CDlgSaleBack2::CDlgSaleBack2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSaleBack2::IDD, pParent)
{
	changed = true;
	//{{AFX_DATA_INIT(CDlgSaleBack2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSaleBack2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSaleBack2)
	DDX_Control(pDX, IDC_SUMMONEY, m_summoney);
	DDX_Control(pDX, IDC_SELLPRICE, m_sellprice);
	DDX_Control(pDX, IDC_REBATE, m_rebate);
	DDX_Control(pDX, IDC_PAYMONEY, m_paymoney);
	DDX_Control(pDX, IDC_OPERATOR, m_operator);
	DDX_Control(pDX, IDC_NUM, m_booknum);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_FACTMONEY, m_factmoney);
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_CUSTOMER, m_customer);
	DDX_Control(pDX, IDC_COUNTERNAME, m_counter);
	DDX_Control(pDX, IDC_BOOKREBATE, m_bookrebate);
	DDX_Control(pDX, IDC_BOOKNAME, m_bookname);
	DDX_Control(pDX, IDC_BARCODE, m_barcode);
	DDX_Control(pDX, IDC_AUTHOR, m_author);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSaleBack2, CDialog)
	//{{AFX_MSG_MAP(CDlgSaleBack2)
	ON_EN_CHANGE(IDC_BARCODE, OnChangeBarcode)
	ON_EN_CHANGE(IDC_REBATE, OnChangeRebate)
	ON_EN_CHANGE(IDC_SUMMONEY, OnChangeSummoney)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSaleBack2 message handlers

void CDlgSaleBack2::AddDataToList()
{
	CString c_barcode,c_bookname,c_booknum,c_bookrebate,c_sellprice,c_author,c_subtotal;
	float f_booknum,f_bookrebate,f_sellprice,f_subtotal;

	m_barcode.GetWindowText(c_barcode);
	m_bookname.GetWindowText(c_bookname);
	m_booknum.GetWindowText(c_booknum);
	m_bookrebate.GetWindowText(c_bookrebate);
	m_author.GetWindowText(c_author);
	m_sellprice.GetWindowText(c_sellprice);
	f_booknum = atof(c_booknum);
	f_bookrebate = atof(c_bookrebate);
	f_sellprice = atof(c_sellprice);
	f_subtotal = f_booknum*f_bookrebate*f_sellprice;
	c_subtotal.Format("%f",f_subtotal);
	if (c_barcode.IsEmpty()||c_bookname.IsEmpty()||c_booknum.IsEmpty()||c_bookrebate.IsEmpty()||c_sellprice.IsEmpty())
	{
		return;
	}
	else
	{
		//Add data to list
		m_list.InsertItem(100,"");
		int rows = m_list.GetItemCount();
		m_list.SetItemText(rows-1,0,c_barcode);
		m_list.SetItemText(rows-1,1,c_bookname);
		m_list.SetItemText(rows-1,2,c_author);
		m_list.SetItemText(rows-1,3,c_sellprice);
		m_list.SetItemText(rows-1,4,c_bookrebate);
		m_list.SetItemText(rows-1,5,c_booknum);
		m_list.SetItemText(rows-1,6,c_subtotal);
		//Clear Edit Text

		m_barcode.SetWindowText("");
		m_booknum.SetWindowText("");
		m_bookrebate.SetWindowText("1.0");
		m_sellprice.SetWindowText("");
		
		m_barcode.SetFocus();

		//统计
		float money = CalculateMoney();
		CString temp;
		temp.Format("%f",money);
		m_summoney.SetWindowText(temp);
	}
}

void CDlgSaleBack2::AddOperate()
{
	if (HeaderInfoIsNull())
	{
		MessageBox("销售主表信息不能为空");
		return;
	}
	if (ListInfoIsNull())
	{
		MessageBox("商品列表不能为空");
		return;
	}
	CString c_id,c_customer,c_operator,c_rebate,c_summoney,c_paymoney,c_factmoney,c_selltime,c_counter;
	float f_rebate,f_summoney,f_paymoney,f_factmoney;

	m_customer.GetWindowText(c_customer);
	m_operator.GetWindowText(c_operator);
	m_rebate.GetWindowText(c_rebate);
	m_summoney.GetWindowText(c_summoney);
	m_paymoney.GetWindowText(c_paymoney);
	m_factmoney.GetWindowText(c_factmoney);
	m_date.GetWindowText(c_selltime);
	m_counter.GetWindowText(c_counter);
	
	f_rebate = atof(c_rebate);
	f_summoney = atof(c_summoney);
	f_paymoney = atof(c_paymoney);
	f_factmoney = atof(c_factmoney);
	
	m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
	
	//define parameter information

	_ParameterPtr arrays[9];
	// utilize command object to create parameter
	arrays[0] = m_pCom->CreateParameter("a1",adVarChar,adParamInput,30);
	arrays[1] = m_pCom->CreateParameter("a2",adVarChar,adParamInput,30);
	arrays[2] = m_pCom->CreateParameter("a3",adSingle,adParamInput,30);
	arrays[3] = m_pCom->CreateParameter("a4",adCurrency,adParamInput,10);	
	arrays[4] = m_pCom->CreateParameter("a5",adCurrency,adParamInput,10);
	arrays[5] = m_pCom->CreateParameter("a6",adCurrency,adParamInput,10);
	arrays[6] = m_pCom->CreateParameter("a7",adVarChar,adParamInput,30);
	arrays[7] = m_pCom->CreateParameter("a8",adVarChar,adParamInput,30);
	arrays[8] = m_pCom->CreateParameter("a9",adVarChar,adParamOutput,30);
	// set parameter values
	arrays[0]->Value = (_bstr_t)c_customer;
	arrays[1]->Value = (_bstr_t)c_operator;
	arrays[2]->Value = f_rebate;
	arrays[3]->Value = f_summoney;
	arrays[4]->Value = f_paymoney;
	arrays[5]->Value = f_factmoney;
	arrays[6]->Value = (_bstr_t)c_selltime;
	arrays[7]->Value = (_bstr_t)c_counter;
	//add parameter to command object
	
	m_pCom->CommandText = "sp_cancelsell";
		m_pCom->CommandType = adCmdStoredProc;
	for (int m = 0;m<9;m++)
	{
		m_pCom->Parameters->Append(arrays[m]);
	}

	try
	{
		m_pCom->Execute(0,NULL,adCmdStoredProc);
		//Get Sell ID
		c_id = (TCHAR*)(_bstr_t)arrays[8]->Value;
		for (int i = 9 ;i >0;i--)
		{
			m_pCom->Parameters->Delete((long)(i-1));
		}	
		for(int row = 0; row< m_list.GetItemCount();row++)
		{
			CString c_barcode;
			float f_unitprice,f_number,f_bookrebate,f_money;
			c_barcode = m_list.GetItemText(row,0);
			f_unitprice = atof(m_list.GetItemText(row,3));
			f_number = atof(m_list.GetItemText(row,5));
			f_bookrebate = atof(m_list.GetItemText(row,4));
			f_money = atof(m_list.GetItemText(row,6));
			m_pRs->raw_Close();
			CString sql;
			sql.Format("insert into tb_cancelsell_sub values ('%s','%s',%f,%f,%f,%f)",c_id,c_barcode,f_unitprice,f_number,f_rebate,f_money);
			m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			// Update Counter Book Number
			sql.Format("update tb_counterbook set booknum = booknum+ %f where barcode = '%s' and counter = '%s'",f_number,c_barcode,c_counter);
			
			m_pRs->raw_Close();
			m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);			
		}

		MessageBox("操作成功,票号为: "+c_id);
		CancelOperate();
	}
	catch(...)
	{
		MessageBox("操作失败");
	
	}
}

float CDlgSaleBack2::CalculateMoney()
{
	int row = m_list.GetItemCount();
	CString str;
	float money = 0.0;
	for (int i = 0 ;i < row;i++)
	{
		str = m_list.GetItemText(i,6);
		money+= atof(str);
	}
	return money;
}

void CDlgSaleBack2::CancelOperate()
{
	m_list.DeleteAllItems();
	m_author.SetWindowText("");
	m_barcode.SetWindowText("");
	m_bookrebate.SetWindowText("1.0");
	m_bookname.SetWindowText("");
	m_booknum.SetWindowText("");
	m_counter.SetCurSel(-1);
	m_customer.SetWindowText("无记名");
	CTime date = CTime::GetCurrentTime();
	m_date.SetTime(&date);
	m_factmoney.SetWindowText("");
	m_operator.SetWindowText(user);
	m_paymoney.SetWindowText("");
	m_rebate.SetWindowText("1.0");
	m_sellprice.SetWindowText("");
	m_summoney.SetWindowText("");
}

void CDlgSaleBack2::DeleteListData()
{
	int m = m_list.GetItemCount();
	if ( m >0)
	{
		int row = m_list.GetSelectionMark();
		if (row != -1)
		{
			if (MessageBox("确实要删除当前行数据吗?","提示",MB_YESNO)==IDYES)
			{
				for (int i = row+1;i<m_list.GetItemCount();i++)
				{
					for(int c = 0; c<7 ;c++)
					{
						m_list.SetItemText(i-1,c,m_list.GetItemText(i,c));
					}
				}
				m_list.DeleteItem(m_list.GetItemCount()-1);
				//统计
				float money = CalculateMoney();
				CString temp;
				temp.Format("%f",money);
				m_summoney.SetWindowText(temp);
			}
		}
	}
}

bool CDlgSaleBack2::HeaderInfoIsNull()
{
	CString str,c_totalmoney,c_rebate,c_paymoney,c_factmoney;
	int index;
	m_customer.GetWindowText(str);
	index = m_counter.GetCurSel();
	m_summoney.GetWindowText(c_totalmoney);
	m_rebate.GetWindowText(c_rebate);
	m_paymoney.GetWindowText(c_paymoney);
	m_factmoney.GetWindowText(c_factmoney);
	if (str.IsEmpty()||index ==-1||c_totalmoney.IsEmpty()||c_rebate.IsEmpty()||c_paymoney.IsEmpty()||c_factmoney.IsEmpty())
		return true;
	else
		return false;
}

bool CDlgSaleBack2::ListInfoIsNull()
{
	int rowcount = m_list.GetItemCount();
	if (rowcount ==-1)
		return true;
	for (int r = 0;r <rowcount;r++)
		for (int i = 0;i<7;i++)
		{
			CString temp;
			temp = m_list.GetItemText(r,i);
			if (temp.IsEmpty()==true)
				return true;
		}
	return false;
}

void CDlgSaleBack2::LoadCounterInfo()
{
	m_counter.ResetContent();//删除所有的数据
	CString sql;
	sql = "select distinct counter from tb_counterinfo";
	m_pRs->raw_Close();
	m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	while (!m_pRs->adoEOF)
	{
		m_counter.AddString((TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem("counter")->Value);
		m_pRs->MoveNext();
	}
}

void CDlgSaleBack2::OnChangeBarcode() 
{
	CString str;

	m_barcode.GetWindowText(str);
	if (changed)
	{
	if (str.IsEmpty())
	{
		m_bookname.SetWindowText("");
		m_author.SetWindowText("");
	}
	else
	{
		CString sql;
		sql.Format("select a.barcode,a.bookname,a.author,b.sellprice from tb_bookinfo a inner join tb_fixprice b on a.barcode = b.barcode and (a.barcode = '%s' or a.bookname = '%s' or a.shortname = '%s' )",str,str,str);
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		if (m_pRs->RecordCount>0)
		{
			changed = false;
			m_barcode.SetWindowText((TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)0)->Value);
			changed = true;
			m_bookname.SetWindowText((TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)1)->Value);
			m_author.SetWindowText((TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)2)->Value);
			m_sellprice.SetWindowText((TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)3)->Value);
		}
		else
		{
			changed = true;
			m_bookname.SetWindowText("");
			m_author.SetWindowText("");
			m_sellprice.SetWindowText("");
		}
	}
	}
	
}

void CDlgSaleBack2::OnChangeRebate() 
{
	CString str1,str2,str3;
	float f_summoney,f_rebate,f_paymoney;
	m_summoney.GetWindowText(str1);
	m_rebate.GetWindowText(str2);
	if (str1.IsEmpty()||str2.IsEmpty())
	{
		m_paymoney.SetWindowText("");
		return;		
	}
	else
	{
		f_summoney= atof(str1);
		f_rebate = atof(str2);
		f_paymoney = f_summoney*f_rebate;
		str3.Format("%f",f_paymoney);
		m_paymoney.SetWindowText(str3);
	}	
}

void CDlgSaleBack2::OnChangeSummoney() 
{
	//Invoke Rebate EditBox OnChangeEvent
	OnChangeRebate();	
}

BOOL CDlgSaleBack2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_rebate.IsNumber = true;
	m_factmoney.IsNumber = true;
	m_sellprice.IsNumber = true;
	m_booknum.IsNumber = true;
	m_bookrebate.IsNumber = true;
	CancelOperate();
	LoadCounterInfo();

	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//Add Column and Set Column Width
	m_list.InsertColumn(0,"条形码",LVCFMT_LEFT,100);
	m_list.InsertColumn(1,"书籍名称",LVCFMT_LEFT,110);
	m_list.InsertColumn(2,"作者",LVCFMT_LEFT,60);
	m_list.InsertColumn(3,"售价",LVCFMT_LEFT,60);
	m_list.InsertColumn(4,"折扣",LVCFMT_LEFT,60);
	m_list.InsertColumn(5,"数量",LVCFMT_LEFT,60);
	m_list.InsertColumn(6,"金额",LVCFMT_LEFT,60);

	return TRUE;  
}

BOOL CDlgSaleBack2::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam ==13)
			pMsg->wParam =9;
		else if ((pMsg->hwnd==m_barcode.m_hWnd)||(pMsg->hwnd==m_booknum.m_hWnd)||(pMsg->hwnd==m_rebate)||(pMsg->hwnd==m_sellprice.m_hWnd))
			if (pMsg->wParam == VK_INSERT)
				AddDataToList();
		if (pMsg->hwnd == m_list.m_hWnd)
			if (pMsg->wParam ==	VK_DELETE)
				DeleteListData();
	}
	return CDialog::PreTranslateMessage(pMsg);	
}

void CDlgSaleBack2::OnOK()
{
//
}

void CDlgSaleBack2::OnAdd() 
{
	AddOperate();
	
}

void CDlgSaleBack2::OnCancel() 
{
	CancelOperate();
	
}

void CDlgSaleBack2::OnExit() 
{
	CDialog::OnCancel();	
}
