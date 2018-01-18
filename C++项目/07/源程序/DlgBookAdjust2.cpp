// DlgBookAdjust2.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgBookAdjust2.h"

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
// CDlgBookAdjust2 dialog


CDlgBookAdjust2::CDlgBookAdjust2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBookAdjust2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBookAdjust2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgBookAdjust2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBookAdjust2)
	DDX_Control(pDX, IDC_LIST2, m_auxilist);
	DDX_Control(pDX, IDC_STORAGE, m_storage);
	DDX_Control(pDX, IDC_OPERATOR, m_operator);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_COUNTER, m_counter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBookAdjust2, CDialog)
	//{{AFX_MSG_MAP(CDlgBookAdjust2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBookAdjust2 message handlers

BOOL CDlgBookAdjust2::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_auxilist.ModifyStyle(LVS_EDITLABELS,0);//禁止编辑标题
	m_auxilist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_INFOTIP|LVS_EX_SUBITEMIMAGES|LVS_EX_GRIDLINES );

	//向表格中添加列
	m_list.InsertColumn(1,"条形码",LVCFMT_LEFT,100);
	m_list.InsertColumn(2,"书籍名称",LVCFMT_LEFT,120);
	m_list.InsertColumn(3,"作者",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"出版社",LVCFMT_LEFT,100);
	m_list.InsertColumn(5,"数量",LVCFMT_LEFT,80);

	m_auxilist.InsertColumn(0,"条形码",LVCFMT_LEFT,100);
	m_auxilist.InsertColumn(1,"书籍名称",LVCFMT_LEFT,80);
	m_auxilist.InsertColumn(2,"作者",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(3,"出版社",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(4,"默认价格",LVCFMT_LEFT,60);

	//添加空行
	m_list.InsertItem(1,"");
	m_auxilist.SetParent(&m_list);	

	LoadStorageInfo();
	LoadCounterInfo();

	m_operator.SetWindowText(user);
	CancelOperate();//exeute cancel operate
	return TRUE;  
}

void CDlgBookAdjust2::LoadStorageInfo()
{
	m_storage.ResetContent();//删除所有的数据
	CString sql;
	sql = "select distinct storagename from tb_storageinfo";
	m_pRs->raw_Close();
	m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	while (!m_pRs->adoEOF)
	{
		m_storage.AddString((TCHAR *)(_bstr_t)m_pRs->GetFields()->GetItem("storagename")->Value);
		m_pRs->MoveNext();
	}
}


void CDlgBookAdjust2::LoadCounterInfo()
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

void CDlgBookAdjust2::CancelOperate()
{
	m_storage.SetCurSel(-1);
	m_counter.SetCurSel(-1);
	m_list.DeleteAllItems();
	CTime date = CTime::GetCurrentTime();
	m_date.SetTime(&date);
	m_list.InsertItem(1,"");
	m_list.edit.SetWindowText("");
}

void CDlgBookAdjust2::OnOK()
{

//prevent pressing enter key to close form
}

void CDlgBookAdjust2::AddNewRow()
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

bool CDlgBookAdjust2::CurrentRowIsNull()
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

void CDlgBookAdjust2::DeleteCurRow()
{
	int currow;
	currow = m_list.row;
	if (currow!=-1)
	{		
	//	m_list.SetFocus();		
		if (MessageBox("确实要删除当前行吗?","提示",MB_YESNO)==IDYES)
		{

			int m = m_list.GetItemCount();
			if (m >1)
			{
				for (int i = currow+1;i<m_list.GetItemCount();i++)
				{
					for(int c = 0; c<5 ;c++)
					{
						m_list.SetItemText(i-1,c,m_list.GetItemText(i,c));
					}
				}
				m_list.DeleteItem(m_list.GetItemCount()-1);
			}
			else
			{
				for (int i = 0;i< 5;i++)
				{
					m_list.SetItemText(0,i,"");
				}
			}
			m_auxilist.ShowWindow(SW_HIDE);
		}
	}
}

bool CDlgBookAdjust2::DetailInfoIsNull()
{
	int rowcount = m_list.GetItemCount();
	if (rowcount ==-1)
		return true;
	for (int r = 0;r <rowcount;r++)
		for (int i = 0;i<5;i++)
		{
			CString temp;
			temp = m_list.GetItemText(r,i);
			if (temp.IsEmpty())
				return true;
		}
	return false;
}

void CDlgBookAdjust2::EditChange()
{
	CString str;
	m_list.edit.GetWindowText(str);
		CString sql = "";
		switch (m_list.col)
		{
		case 0 : 
			{
				if (!str.IsEmpty())
					sql.Format("select barcode,bookname,author,bookconcern,price from tb_bookinfo where barcode like '%s%%' or shortname like '%s%%' ",str,str);
				break;
			}
		case 1 : 
			{
				if (!str.IsEmpty())
					sql.Format("select barcode,bookname,author,bookconcern,price from tb_bookinfo where bookname like '%s%%' or shortname like '%s%%'",str,str);
				break;
			}
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

void CDlgBookAdjust2::ShowListInfo()
{
	CRect rect;
	m_list.GetSubItemRect(m_list.row,m_list.col,LVIR_BOUNDS,rect);
	m_auxilist.MoveWindow(rect.left,rect.bottom+1,300,150);
	m_auxilist.ShowWindow(SW_SHOW);
}

void CDlgBookAdjust2::LimitEdit()
{
	m_list.edit.IsNumber = false;
	//在修改商品数据,价格,折扣时只允许输入数字
	if (m_list.col ==4)
	{
		m_list.edit.IsNumber = true;
	}
}

void CDlgBookAdjust2::ShowListinfo()
{
	if (m_auxilist.IsWindowVisible())
	{
		m_auxilist.SetFocus();
		m_auxilist.PostMessage(WM_KEYDOWN,VK_UP);
	}
}

void CDlgBookAdjust2::MoveFocus()
{
	m_list.SetFocus();
	if (m_list.col <5)
	{
		if ((m_list.col ==0) || (m_list.col==1))
		{
			CString c_barcode,c_bookname;
			c_barcode = m_list.GetItemText(m_list.row,0);
			c_bookname = m_list.GetItemText(m_list.row,1);
			if (m_list.col==0)
			{
				if (!c_barcode.IsEmpty()&&c_bookname.IsEmpty())
				{
					m_pRs->raw_Close();
					CString sql;
					sql.Format("select barcode,bookname,author,bookconcern from tb_bookinfo where barcode = '%s' or shortname = '%s'",c_barcode,c_barcode);
					m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					if (m_pRs->RecordCount>0)
					{
						m_list.SetItemText(m_list.row,0,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)0)->Value);
						m_list.SetItemText(m_list.row,1,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)1)->Value);
						m_list.SetItemText(m_list.row,2,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)2)->Value);
						m_list.SetItemText(m_list.row,3,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)3)->Value);
						
					}
					else
					{
						m_list.SetItemText(m_list.row,0,"");
						MessageBox("条形码不存在","提示",64);
						return;
					}				
				}			
			}
			else  //m_list.col ==1
			{
				if (!c_bookname.IsEmpty()&&c_barcode.IsEmpty())
				{
					m_pRs->raw_Close();
					CString sql;
					sql.Format("select barcode,bookname from tb_bookinfo where barcode = '%s' or shortname = '%s'",c_bookname,c_bookname);
					m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					if (m_pRs->RecordCount>0)
					{
						m_list.SetItemText(m_list.row,0,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)0)->Value);
						m_list.SetItemText(m_list.row,1,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)1)->Value);
						m_list.SetItemText(m_list.row,2,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)2)->Value);
						m_list.SetItemText(m_list.row,3,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)3)->Value);
					}
					else
					{
						m_list.SetItemText(m_list.row,1, "");
						MessageBox("书籍名称不存在","提示",64);
						return;
					}				
				}			
				
			}		
		}
		m_list.col = m_list.col+1;
		CString tempID,tempname;
		tempID = m_list.GetItemText(m_list.row,0);
		tempname = m_list.GetItemText(m_list.row,1);
		m_list.showedit = true;
		if ((tempname.IsEmpty()==false)&&(m_list.col == 0))
			m_list.showedit =false;
		else if((tempID.IsEmpty()==false)&&(m_list.col == 1))
			m_list.showedit =false;
		else if ((m_list.col==2 )||(m_list.col== 3))
			m_list.showedit =false;
		m_list.ShowEdit();
	}
	else
	{
		AddNewRow();
	}
}

BOOL CDlgBookAdjust2::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message ==WM_KEYDOWN)	
	{		
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
		说明:  辅助录入表格获得焦点时,按Enter键会将当前数据显示在表格中
		****************************************************************/
		else if ((pMsg->hwnd ==m_auxilist.m_hWnd)&&(pMsg->wParam == 13))
		{
			OnDblclkList2(NULL,NULL);
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
			tempID = m_list.GetItemText(row,0);
			tempname = m_list.GetItemText(row,1);	
			m_list.showedit =true;
			if ((col==2)||(col ==3)) //如果单击金额列,不显示编辑框
				m_list.showedit =false;
			if ((tempname.IsEmpty()==false)&&(col == 0))
				m_list.showedit =false;
			else if((tempID.IsEmpty()==false)&&(col == 1))
				m_list.showedit =false;
		}
	}	
	return CDialog::PreTranslateMessage(pMsg);	
}

void CDlgBookAdjust2::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_auxilist.GetSelectionMark();
	if (row!=-1)
	{
		CString temp;
		temp = m_auxilist.GetItemText(row,0);
		//设置条形码
		m_list.SetItemText(m_list.row,0,temp);
		//设置书籍名称
		m_list.SetItemText(m_list.row,1,m_auxilist.GetItemText(row,1));
		//设置默认价格
		m_list.SetItemText(m_list.row,2,m_auxilist.GetItemText(row,2));
		m_list.SetItemText(m_list.row,3,m_auxilist.GetItemText(row,3));
		m_auxilist.ShowWindow(SW_HIDE);
	}
	//移动编辑框
	//MoveFocus();
	m_list.col =4;
	m_list.ShowEdit();	
}

void CDlgBookAdjust2::AddOperate()
{
	if ((m_storage.GetCurSel()==-1)||(m_counter.GetCurSel()==-1))
	{
		MessageBox("仓库或柜台信息不能为空.","提示",64);
		return;
	}
	if (DetailInfoIsNull())
	{
		MessageBox("商品列表不能为空.","提示",64);
		return;
	}
	CString c_storage,c_operator,c_counter,c_date,c_id;
	m_storage.GetWindowText(c_storage);
	m_operator.GetWindowText(c_operator);
	m_counter.GetWindowText(c_counter);
	m_date.GetWindowText(c_date);

	m_pCom->ActiveConnection = m_pCon.GetInterfacePtr();
	_ParameterPtr a,b,c,d,e;

	a = m_pCom->CreateParameter("a1",adVarChar,adParamInput,30);
	a->Value = (_bstr_t)c_storage;
	
	b = m_pCom->CreateParameter("a2",adVarChar,adParamInput,30);
	b->Value = (_bstr_t)c_counter;

	c = m_pCom->CreateParameter("a3",adVarChar,adParamInput,30);
	c->Value = (_bstr_t)c_operator;

	d = m_pCom->CreateParameter("a4",adVarChar,adParamInput,30);
	d->Value = (_bstr_t)c_date;

	e = m_pCom->CreateParameter("a5",adVarChar,adParamOutput,30);

	m_pCom->Parameters->Append(a);
	m_pCom->Parameters->Append(b);
	m_pCom->Parameters->Append(c);
	m_pCom->Parameters->Append(d);
	m_pCom->Parameters->Append(e);
	m_pCom->CommandText = "sp_adjuststorage";
	try
	{
		m_pCom->Execute(0,NULL,adCmdStoredProc);
		c_id = (TCHAR*)(_bstr_t)e->Value;
		m_pCom->Parameters->Delete("a1");
		m_pCom->Parameters->Delete("a2");
		m_pCom->Parameters->Delete("a3");
		m_pCom->Parameters->Delete("a4");
		m_pCom->Parameters->Delete("a5");
		
		CString sql,c_barcode,c_booknum;
		float f_booknum;

		for (int row = 0 ;row<m_list.GetItemCount();row++)
		{
			m_pRs->raw_Close();
			c_barcode = m_list.GetItemText(row,0);
			c_booknum = m_list.GetItemText(row,4);
			
			f_booknum = atof(c_booknum);

			sql.Format("insert into tb_bookmove_sub values ('%s','%s',%f)",c_id,c_barcode,f_booknum);
			m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			
			m_pRs->raw_Close();
			sql.Format("update tb_bookstorage set booknum = booknum- %f where barcode = '%s' and storagename = '%s'",f_booknum,c_barcode,c_storage);
			m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);

			m_pRs->raw_Close();

			sql.Format("select * from tb_counterbook where barcode = '%s' and counter = '%s'",c_barcode,c_counter);
			m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			if (m_pRs->RecordCount>0) 
			{
				m_pRs->raw_Close();
				sql.Format("update tb_counterbook set booknum = booknum+ %f where barcode = '%s' and counter = '%s'",f_booknum,c_barcode,c_counter);
				m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			}
			else
			{
				m_pRs->raw_Close();
				sql.Format("insert into  tb_counterbook values ('%s','%s',%f)",c_barcode,c_counter,f_booknum);
				m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);				
			}


		}
		MessageBox("操作成功.","提示",64);
		CancelOperate();
	}
	catch(...)
	{
		MessageBox("操作失败.","提示",64);
	}

}

void CDlgBookAdjust2::OnAdd() 
{
	AddOperate();	
}

void CDlgBookAdjust2::OnCancel() 
{
	CancelOperate();	
}

void CDlgBookAdjust2::OnExit() 
{
	CDialog::OnCancel();	
}
