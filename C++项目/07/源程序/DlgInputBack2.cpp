// DlgInputBack2.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgInputBack2.h"

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
// CDlgInputBack2 dialog


CDlgInputBack2::CDlgInputBack2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputBack2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInputBack2)
	//}}AFX_DATA_INIT
}


void CDlgInputBack2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInputBack2)
	DDX_Control(pDX, IDC_FACTMONEY, m_factmoney);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_SUMMONEY, m_summoney);
	DDX_Control(pDX, IDC_STORAGELIST, m_storagelist);
	DDX_Control(pDX, IDC_REBATE, m_rebate);
	DDX_Control(pDX, IDC_PROVIDERLIST, m_providerlist);
	DDX_Control(pDX, IDC_PROVIDER, m_provider);
	DDX_Control(pDX, IDC_PAYMONEY, m_paymoney);
	DDX_Control(pDX, IDC_OPERATOR, m_operator);
	DDX_Control(pDX, IDC_LIST2, m_auxilist);
	DDX_Control(pDX, IDC_DATETIME, m_date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInputBack2, CDialog)
	//{{AFX_MSG_MAP(CDlgInputBack2)
	ON_EN_CHANGE(IDC_REBATE, OnChangeRebate)
	ON_EN_CHANGE(IDC_SUMMONEY, OnChangeSummoney)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	ON_LBN_DBLCLK(IDC_PROVIDERLIST, OnDblclkProviderlist)
	ON_LBN_DBLCLK(IDC_STORAGELIST, OnDblclkStoragelist)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST2, OnKillfocusList2)
	ON_LBN_KILLFOCUS(IDC_STORAGELIST, OnKillfocusStoragelist)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInputBack2 message handlers

void CDlgInputBack2::AddNewRow()
{
	int counts = m_list.GetItemCount();
	if (m_list.row == counts-1)//当前行为最后一行
	{
		m_list.InsertItem(100,"");
		m_list.row+=1;			
		m_list.SetItemText(m_list.row,5,"1.0");

		m_list.col = 0;
		m_list.ShowEdit();
	}
	else
	{
		m_list.row+=1;
		m_list.col = 0;
		m_list.ShowEdit();
	}
}

float CDlgInputBack2::CalculateMoney()
{
	float money,temp;
	money = 0.0;
	CString c_money;	
	int rowcounts = m_list.GetItemCount();
	for (int i = 0;i<rowcounts;i++)
	{
		c_money = m_list.GetItemText(i,6);
		if (!c_money.IsEmpty())
		{
			temp = atof(c_money);
			money += temp;
		}
	}
	return money;
}

bool CDlgInputBack2::CurrentRowIsNull()
{
	int row = m_list.GetSelectionMark();
	if (row !=-1)
	{
		for (int index = 0;index <7;index++)
		{
			CString str;
			str = m_list.GetItemText(m_list.row,index);
			if (str.IsEmpty())
			{
				return true;
			}
		}
	}
	else
		return true;
	return false;
}

void CDlgInputBack2::DeleteCurRow()
{
	int currow;
	currow = m_list.row;
	if (currow!=-1)
	{
		if (MessageBox("确实要删除当前行吗?","提示",MB_YESNO)==IDYES)
		{
			int m = m_list.GetItemCount();
			if (m >1)
			{
				for (int i = currow+1;i<m_list.GetItemCount();i++)
				{
					for(int c = 0; c<7 ;c++)
					{
						m_list.SetItemText(i-1,c,m_list.GetItemText(i,c));
					}
				}
				m_list.DeleteItem(m_list.GetItemCount()-1);
			}
			else
			{
				for (int i = 0;i< 7;i++)
				{
					m_list.SetItemText(0,i,"");
				}
			}
			CString temp;
			temp.Format("%10.2f",CalculateMoney());//重新统计数据
			temp.TrimLeft();
			m_summoney.SetWindowText(temp);
		}
	}
}

bool CDlgInputBack2::DetailInfoIsNull()
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

void CDlgInputBack2::EditChange()
{
	CString str;
	m_list.edit.GetWindowText(str);
		CString sql = "";
		switch (m_list.col)
		{
		case 1 : 
			{
				if (!str.IsEmpty())
					sql.Format("select barcode,bookname,author,shortname,price from tb_bookinfo where barcode like '%s%%' or shortname like '%s%%' ",str,str);
				break;
			}
		case 2 : 
			{
				if (!str.IsEmpty())
					sql.Format("select barcode,bookname,author,shortname,price from tb_bookinfo where bookname like '%s%%' or shortname like '%s%%'",str,str);
				break;
			}
		case 3:
			{
				CString c_price,c_num,c_rebate,c_money;
				float f_price,f_num,f_rebate,f_money;
				c_price = str;
				c_num = m_list.GetItemText(m_list.row,4);
				c_rebate = m_list.GetItemText(m_list.row,5);
				if (c_price.IsEmpty()||c_num.IsEmpty()||c_rebate.IsEmpty())
				{
					//如果单价\数量\折扣为空,金额将为空
					m_list.SetItemText(m_list.row,6,""); 
				}
				else
				{
					f_price = atof(c_price);
					f_num = atof(c_num);
					f_rebate = atof(c_rebate);
					f_money = f_price*f_num*f_rebate;
					c_money.Format("%10.2f",f_money);
					c_money.TrimLeft();
					m_list.SetItemText(m_list.row,6,c_money);
				}
				str.Format("%10.2f",CalculateMoney());
				str.TrimLeft();
				m_summoney.SetWindowText(str);
				break;
			}

		case 4:
			{
				CString c_price,c_num,c_rebate,c_money;
				float f_price,f_num,f_rebate,f_money;
				c_price = m_list.GetItemText(m_list.row,3);
				c_num = str;
				c_rebate = m_list.GetItemText(m_list.row,5);
				if (c_price.IsEmpty()||c_num.IsEmpty()||c_rebate.IsEmpty())
				{
					//如果单价\数量\折扣为空,金额将为空
					m_list.SetItemText(m_list.row,6,""); 
				}
				else
				{
					f_price = atof(c_price);
					f_num = atof(c_num);
					f_rebate = atof(c_rebate);
					f_money = f_price*f_num*f_rebate;
					c_money.Format("%10.2f",f_money);
					c_money.TrimLeft();
					m_list.SetItemText(m_list.row,6,c_money);
				}
				str.Format("%10.2f",CalculateMoney());
				str.TrimLeft();
				m_summoney.SetWindowText(str);
				break;
			}
		case 5:
			{
				CString c_price,c_num,c_rebate,c_money;
				float f_price,f_num,f_rebate,f_money;
				c_price = m_list.GetItemText(m_list.row,3);
				c_num = m_list.GetItemText(m_list.row,4);
				c_rebate = str;
				if (c_price.IsEmpty()||c_num.IsEmpty()||c_rebate.IsEmpty())
				{
					//如果单价\数量\折扣为空,金额将为空
					m_list.SetItemText(m_list.row,6,""); 
				}
				else
				{
					f_price = atof(c_price);
					f_num = atof(c_num);
					f_rebate = atof(c_rebate);
					f_money = f_price*f_num*f_rebate;
					c_money.Format("%10.2f",f_money);
					c_money.TrimLeft();
					m_list.SetItemText(m_list.row,6,c_money);
				}
				str.Format("%10.2f",CalculateMoney());
				str.TrimLeft();
				m_summoney.SetWindowText(str);
				break;
			}
		default:
			break;
		}
		if (! sql.IsEmpty())
		{
			m_pRs->raw_Close();
			m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			if (m_pRs->RecordCount>0)
			{
				m_auxilist.DeleteAllItems();
				int i=0;
				while(! m_pRs->adoEOF)
				{
					m_auxilist.InsertItem(100,"");
					for (int m = 0;m<5;m++)
					m_auxilist.SetItemText(i,m,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)m)->Value);
					m_pRs->MoveNext();
					i +=1;
				}
				ShowListInfo();
			}
			else
				m_auxilist.ShowWindow(SW_HIDE);
		}
		else
			m_auxilist.ShowWindow(SW_HIDE);
}

void CDlgInputBack2::InputCancel()
{
	m_rebate.SetWindowText("1.0");
	CTime time = CTime::GetCurrentTime();
	m_date.SetTime(&time);
	m_list.DeleteAllItems();
	m_list.InsertItem(1,"");
	m_list.SetItemText(0,5,"1.0");
	m_provider.SetWindowText("");
	m_factmoney.SetWindowText("");
	m_summoney.SetWindowText("");
}

bool CDlgInputBack2::InputInfoIsNull()
{
	CString c_provider,c_totalmoney,c_rebate,c_paymoney,c_factmoney;
	m_provider.GetWindowText(c_provider);
	m_summoney.GetWindowText(c_totalmoney);
	m_rebate.GetWindowText(c_rebate);
	m_paymoney.GetWindowText(c_paymoney);
	m_factmoney.GetWindowText(c_factmoney);
	if ((c_provider.IsEmpty())||(c_totalmoney.IsEmpty())||(c_rebate.IsEmpty())||(c_paymoney.IsEmpty())||(c_factmoney.IsEmpty()))
		return true;
	else
		return false;
}

void CDlgInputBack2::LimitEdit()
{
	m_list.edit.IsNumber = false;
	//在修改商品数据,价格,折扣时只允许输入数字
	if ((m_list.col ==3)||(m_list.col ==4)||(m_list.col==5))
	{
		m_list.edit.IsNumber = true;
	}
}

void CDlgInputBack2::LoadProvider()
{
	m_providerlist.SetRedraw(FALSE);
	m_providerlist.ResetContent();//删除所有的数据
	CString sql;
	sql = "select provider from tb_providerinfo";
	m_pRs->raw_Close();
	m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	while (!m_pRs->adoEOF)
	{
		m_providerlist.AddString((TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem("provider")->Value);
		m_pRs->MoveNext();
	}
	m_providerlist.SetRedraw(TRUE);
	m_providerlist.Invalidate();
}

void CDlgInputBack2::LoadStorage()
{
	m_storagelist.SetRedraw(FALSE);
	m_storagelist.ResetContent();//删除所有的数据
	CString sql;
	sql = "select distinct storagename from tb_storageinfo";
	m_pRs->raw_Close();
	m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	while (!m_pRs->adoEOF)
	{
		m_storagelist.AddString((TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem("storagename")->Value);
		m_pRs->MoveNext();
	}
	m_storagelist.SetRedraw(TRUE);
	m_storagelist.Invalidate();	
}

void CDlgInputBack2::MoveFocus()
{
	m_list.SetFocus();
	if (m_list.col <7)
	{
		m_list.col = m_list.col+1;
		CString tempID,tempname;
		tempID = m_list.GetItemText(m_list.row,1);
		tempname = m_list.GetItemText(m_list.row,2);
		m_list.showedit = true;
		if ((tempname.IsEmpty()==false)&&(m_list.col == 1))
			m_list.showedit =false;
		else if((tempID.IsEmpty()==false)&&(m_list.col == 2))
			m_list.showedit =false;
		m_list.ShowEdit();
	}
	else
	{
		AddNewRow();
	}
}

void CDlgInputBack2::OnChangeRebate() 
{
	CString c_totalmoney,c_rebate,c_paymoney;
	float f_totalmoney,f_rebate,f_paymoney;
	m_summoney.GetWindowText(c_totalmoney);
	m_rebate.GetWindowText(c_rebate);
	if(!c_totalmoney.IsEmpty()&&!c_rebate.IsEmpty())
	{
		f_totalmoney = atof(c_totalmoney);
		f_rebate = atof(c_rebate);
		f_paymoney = f_totalmoney *f_rebate;
		c_paymoney.Format("%10.2f",f_paymoney);
		c_paymoney.TrimLeft();
		m_paymoney.SetWindowText(c_paymoney);
	}
	else
	{
		m_paymoney.SetWindowText("");
	}	
}

void CDlgInputBack2::OnChangeSummoney() 
{
	//调用折扣改变时的事件
	OnChangeRebate();	
}

void CDlgInputBack2::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_auxilist.GetSelectionMark();
	if (row!=-1)
	{
		CString temp;
		temp = m_auxilist.GetItemText(row,0);
		//设置条形码
		m_list.SetItemText(m_list.row,1,temp);
		//设置书籍名称
		m_list.SetItemText(m_list.row,2,m_auxilist.GetItemText(row,1));
		//设置默认价格
		m_list.SetItemText(m_list.row,3,m_auxilist.GetItemText(row,4));
		m_auxilist.ShowWindow(SW_HIDE);
	}
	//移动编辑框
	//MoveFocus();
	m_list.col =3;
	m_list.ShowEdit();	
}

void CDlgInputBack2::OnDblclkProviderlist() 
{
	CString temp;
	int index = m_providerlist.GetCurSel();
	if (index != -1)
	{
		m_providerlist.GetText(index,temp);
		if (! temp.IsEmpty())
			m_provider.SetWindowText(temp);
		m_provider.SetFocus();
		m_providerlist.ShowWindow(SW_HIDE);
	}	
}

void CDlgInputBack2::OnDblclkStoragelist() 
{
	CString temp;
	int index = m_storagelist.GetCurSel();
	if (index != -1)
	{
		m_storagelist.GetText(index,temp);
		if (! temp.IsEmpty())
			m_list.SetItemText(m_list.row,m_list.col,temp);
		m_list.SetFocus();
		m_storagelist.ShowWindow(SW_HIDE);
		m_list.col+=1;
		m_list.ShowEdit();
	}		
}

BOOL CDlgInputBack2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//添加供应商
	LoadProvider();
	//添加仓库信息
	LoadStorage();
	m_storagelist.SetParent(&m_list);
	//读取操作员名称
	m_operator.SetWindowText(user);
	
	//设置编辑框颜色
	SetEditColor(RGB(255,0,0));

	m_auxilist.ModifyStyle(LVS_EDITLABELS,0);//禁止编辑标题
	m_auxilist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_INFOTIP|LVS_EX_SUBITEMIMAGES|LVS_EX_GRIDLINES );

	//向表格中添加列
	m_list.InsertColumn(0,"仓库名称",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"条形码",LVCFMT_LEFT,100);
	m_list.InsertColumn(2,"书籍名称",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"单价",LVCFMT_LEFT,60);
	m_list.InsertColumn(4,"数量",LVCFMT_LEFT,60);
	m_list.InsertColumn(5,"折扣",LVCFMT_LEFT,60);
	m_list.InsertColumn(6,"金额",LVCFMT_LEFT,60);

	m_auxilist.InsertColumn(0,"条形码",LVCFMT_LEFT,100);
	m_auxilist.InsertColumn(1,"书籍名称",LVCFMT_LEFT,80);
	m_auxilist.InsertColumn(2,"作者",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(3,"助记码",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(4,"默认价格",LVCFMT_LEFT,60);

	//添加空行
	m_list.InsertItem(1,"");
	m_list.SetItemText(0,5,"1.0");
	m_auxilist.SetParent(&m_list);

	m_rebate.SetWindowText("1.0");

	m_rebate.IsNumber = true;
	m_factmoney.IsNumber = true;
	
	m_providerlist.SetParent(&m_list);
	//m_list.SetParent(&m_provider);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputBack2::OnKillfocusList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_auxilist.ShowWindow(SW_HIDE);	

}

void CDlgInputBack2::OnKillfocusStoragelist() 
{
	m_providerlist.ShowWindow(SW_HIDE);		
}

void CDlgInputBack2::OnOK()
{
//
}

void CDlgInputBack2::SetEditColor(COLORREF Color)
{
	CWnd* temp;
	temp = this;
	for (int i = 0;i<11;i++)
	{
		temp = GetNextDlgTabItem(temp);
		if (temp->IsKindOf(RUNTIME_CLASS(CKeyEdit))==true)
		{
			((CKeyEdit*)(temp))->SetEditTextColor(Color);
		}
	}
}

void CDlgInputBack2::ShowListInfo()
{
	CRect rect;
	m_list.GetSubItemRect(m_list.row,m_list.col,LVIR_BOUNDS,rect);
	m_auxilist.MoveWindow(rect.left,rect.bottom+1,300,150);
	m_auxilist.ShowWindow(SW_SHOW);
}

void CDlgInputBack2::ShowListinfo()
{
	if (m_auxilist.IsWindowVisible())
	{
		m_auxilist.SetFocus();
		m_auxilist.PostMessage(WM_KEYDOWN,VK_UP);
	}
}

void CDlgInputBack2::ShowStorage()
{
	if (m_list.col ==0)
		if (!m_storagelist.IsWindowVisible())
		{
			CRect rect;
			m_list.GetSubItemRect(m_list.row,m_list.col,LVIR_BOUNDS,rect);
			m_storagelist.MoveWindow(rect.left,rect.bottom,100,80,0);
			m_storagelist.ShowWindow(SW_SHOW);
			m_storagelist.SetFocus();
			m_storagelist.SetCurSel(0);
		}
}

void CDlgInputBack2::AddOperate()
{
	if (InputInfoIsNull())
	{
		MessageBox("入库信息不能为空","提示",64);
		return;
	}
	if (DetailInfoIsNull())
	{
		MessageBox("商品信息不能为空","提示",64);
		return;
	}
	try
	{		
		CString sql;
		CString c_provider,c_operator,c_rebate,c_sumtotal,c_paymoney,c_factmoney,c_intime;
		float f_rebate,f_sumtotal,f_paymoney,f_factmoney;
		m_provider.GetWindowText(c_provider);
		m_operator.GetWindowText(c_operator);
		m_rebate.GetWindowText(c_rebate);
		m_summoney.GetWindowText(c_sumtotal);
		m_paymoney.GetWindowText(c_paymoney);
		m_factmoney.GetWindowText(c_factmoney);
		f_rebate = atof(c_rebate);
		f_sumtotal = atof(c_sumtotal);
		f_paymoney = atof(c_paymoney);
		f_factmoney = atof(c_factmoney);
		CTime temptime;
		m_date.GetTime(temptime);
		c_intime = temptime.Format("%Y-%m-%d");

		m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
		_ParameterPtr a1,a2,a3,a4,a5,a6,a7,a8;
		

		a1 = m_pCom->CreateParameter("a1",adVarChar,adParamInput,30);
		a1->Value = (_bstr_t)c_provider;

		a2 = m_pCom->CreateParameter("a2",adVarChar,adParamInput,30);
		a2->Value = (_bstr_t)c_operator;

		a3 = m_pCom->CreateParameter("a3",adSingle,adParamInput,10);
		a3->Value = f_rebate;
		a4 = m_pCom->CreateParameter("a4",adCurrency,adParamInput,10);
		a4->Value = f_sumtotal;	
		
		a5 = m_pCom->CreateParameter("a5",adCurrency,adParamInput,10);
		a5->Value = f_paymoney;

		a6 = m_pCom->CreateParameter("a6",adCurrency,adParamInput,10);
		a6->Value = f_factmoney;		
		a7 = m_pCom->CreateParameter("a7",adVarChar,adParamInput,30);
		a7->Value = (_bstr_t)c_intime;
		a8 = m_pCom->CreateParameter("a8",adVarChar,adParamOutput,30);
		a8->Value = (_bstr_t)c_provider;
		m_pCom->CommandText = " sp_cancelinstore ";
		m_pCom->CommandType = adCmdStoredProc;
		m_pCom->Parameters->Append(a1);
		m_pCom->Parameters->Append(a2);
		m_pCom->Parameters->Append(a3);
		m_pCom->Parameters->Append(a4);
		m_pCom->Parameters->Append(a5);
		m_pCom->Parameters->Append(a6);
		m_pCom->Parameters->Append(a7);
		m_pCom->Parameters->Append(a8);

			m_pCom->Execute(0,NULL,adCmdStoredProc);

			CString id; //记录返回的票号
			id = (TCHAR*)(_bstr_t)m_pCom->Parameters->GetItem("a8")->Value;
			m_pCom->Parameters->Delete("a1");
			m_pCom->Parameters->Delete("a2");
			m_pCom->Parameters->Delete("a3");
			m_pCom->Parameters->Delete("a4");
			m_pCom->Parameters->Delete("a5");
			m_pCom->Parameters->Delete("a6");
			m_pCom->Parameters->Delete("a7");
			m_pCom->Parameters->Delete("a8");
			//记录入库明细信息	
			int rows = m_list.GetItemCount();
			for (int c = 0;c<rows;c++)
			{
				CString c_id,c_storage,c_num,c_price,c_rebate,c_money;
				float f_num,f_price,f_rebate,f_money;
				c_id = m_list.GetItemText(c,1);
				c_storage = m_list.GetItemText(c,0);
				c_num = m_list.GetItemText(c,4);
				c_price = m_list.GetItemText(c,3);
				c_rebate = m_list.GetItemText(c,5);
				c_money = m_list.GetItemText(c,6);
				f_price = atof(c_price);
				f_rebate = atof(c_rebate);
				f_money = atof(c_money);
				f_num = atof(c_num);
				CString detailsql;
				m_pRs->raw_Close();
				detailsql.Format("insert into tb_cancelinstock_sub values ('%s','%s',%f,%f,%f,%f,'%s')",id,c_id,f_price,f_num,f_rebate,f_money,c_storage);
				m_pRs->Open((_variant_t)detailsql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockPessimistic,adCmdText);
				//修改商品库存
				m_pRs->raw_Close();
				detailsql.Format("update tb_bookstorage set booknum = booknum - %f where barcode = '%s' and storagename = '%s'", f_num ,c_id,c_storage);
				m_pRs->Open((_bstr_t)detailsql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockPessimistic,adCmdText);

			}
			InputCancel();
			MessageBox("操作成功,票号为: "+id,"提示",64);
	}
	catch(_com_error &e)
	{
		MessageBox(e.Description(),"提示",64);
	}
}

BOOL CDlgInputBack2::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message ==WM_KEYDOWN)	
	{		
		/****************************************************************
		说明:  在供应商编辑框获得焦点并按PageDown键,调用DoEditKeyDown方法
		****************************************************************/
		if ((pMsg->wParam == 34)&&(pMsg->hwnd==m_provider.m_hWnd))
		{
			DoEditKeyDown(34,IDC_PROVIDER);
		}
		/****************************************************************
		说明:  表格中编辑框获得焦点时,按Enter键控制单元格焦点移动
		****************************************************************/
		if ((pMsg->wParam == 13)&&(pMsg->hwnd==m_list.edit.m_hWnd))
		{
			MoveFocus();
			return true;
		}	
		/****************************************************************
		说明:  表格中获得焦点时,按Enter键添加新行
		****************************************************************/		
		if ((pMsg->wParam == 13)&&(pMsg->hwnd == m_list.m_hWnd))
		{
			AddNewRow();
			return true;
		}
		if ((pMsg->wParam ==VK_DELETE)&&(pMsg->hwnd == m_list.m_hWnd))
		{
			DeleteCurRow();
			//return true;
		}		
		/****************************************************************
		说明:  列表框获得焦点时,按Enter键会将当前数据显示在编辑框中
		****************************************************************/
		else if ((pMsg->hwnd ==m_providerlist.m_hWnd)&&(pMsg->wParam == 13))
		{
			OnDblclkProviderlist();
			return true;
		}
		/****************************************************************
		说明:  辅助录入表格获得焦点时,按Enter键会将当前数据显示在表格中
		****************************************************************/
		else if ((pMsg->hwnd ==m_auxilist.m_hWnd)&&(pMsg->wParam == 13))
		{
			OnDblclkList2(NULL,NULL);
			return true;
		}
		else if ((pMsg->wParam ==13)&&(pMsg->hwnd == m_storagelist.m_hWnd))
		{
			OnDblclkStoragelist();
			return true;
		}
		else if (pMsg->wParam ==13)
		{
			pMsg->wParam = 9;
			//return;
		}						
		else if (pMsg->wParam == VK_ESCAPE)
			return true;
	}
	/****************************************************************
	说明:  表格中编辑框按键时的事件,用于判断是否限制字符输入,如果用户按
	PageDown键,将使辅助录入表格获得焦点
	****************************************************************/
	if ((pMsg->message == WM_KEYDOWN)&&(pMsg->hwnd == m_list.edit.m_hWnd))
	{
		LimitEdit();	
		if (pMsg->wParam == 34)
		{
			ShowListinfo();
			ShowStorage();
		}
		else if (pMsg->wParam ==VK_DELETE)//按delete键删除表格当前行
			DeleteCurRow();
	}	
	/****************************************************************
	说明:  表格中编辑框改变时的事件
	****************************************************************/
	if ((pMsg->message == WM_KEYUP)&&(pMsg->hwnd == m_list.edit.m_hWnd))
	{
		EditChange();	
	}
	/****************************************************************
	说明:  在窗体中控件获得焦点时,使提示列表不可见
	****************************************************************/
	if (pMsg->message==WM_LBUTTONDOWN)
	{
		if (pMsg->hwnd!= m_auxilist.m_hWnd)
			m_auxilist.ShowWindow(SW_HIDE);
		if (pMsg->hwnd != m_storagelist.m_hWnd)
			m_storagelist.ShowWindow(SW_HIDE);
	
	}
	/****************************************************************
	说明:  在单击表格时,根据当前列判断是否显示编辑框
	****************************************************************/
	if ((pMsg->message ==WM_LBUTTONDOWN)&&(pMsg->hwnd ==m_list.m_hWnd))
	{
		//当前列为商品编号,商品名称为空,显示编辑框,在当前列为商品名称,商品编号为空,显示编辑框,
		CString tempID,tempname;
		LVHITTESTINFO pos;
		pos.pt.x = LOWORD(pMsg->lParam);
		pos.pt.y = HIWORD(pMsg->lParam);
		pos.flags = LVHT_ABOVE;
		int row,col;
		row = -1;
		col = -1;
		if (m_list.SubItemHitTest(&pos)>=0)
		{
			m_list.SetFocus();
			row = pos.iItem;
			col = pos.iSubItem;		
			tempID = m_list.GetItemText(row,1);
			tempname = m_list.GetItemText(row,2);			
			if (col==6) //如果单击金额列,不显示编辑框
				return true;
			m_list.showedit =true;	
			if ((tempname.IsEmpty()==false)&&(col == 1))
				m_list.showedit =false;
			else if((tempID.IsEmpty()==false)&&(col == 2))
				m_list.showedit =false;
		}
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgInputBack2::DoEditKeyDown(UINT nChar, UINT CtrlID)
{
	if ((nChar ==34)&&(CtrlID ==IDC_PROVIDER))
	{
		
	//	CRect rect,rect1;
	//	m_providerlist.GetWindowRect(rect1);
	//	m_provider.GetWindowRect(rect);
	//	ScreenToClient(rect);
	//	ScreenToClient(rect1);
	//	m_providerlist.MoveWindow(rect.left,rect.bottom+2,rect.right-rect.left,rect1.bottom-rect1.top);	
		m_providerlist.ShowWindow(SW_SHOW);
	//	m_providerlist.BringWindowToTop();
	//	SetWindowPos(&m_providerlist,rect.left,rect.bottom+2,rect.right-rect.left,rect1.bottom-rect1.top,SWP_SHOWWINDOW);
		m_providerlist.SetSel(0);
		m_providerlist.SetFocus();
			
	}
}

void CDlgInputBack2::OnAdd() 
{
	AddOperate();	
}

void CDlgInputBack2::OnCancel() 
{
	InputCancel();
	
}

void CDlgInputBack2::OnExit() 
{
	CDialog::OnCancel();	
}
