// DlgBookInput2.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgBookInput2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO���Ӷ���
extern _RecordsetPtr m_pRs; 
extern _RecordsetPtr m_pRs1; 
extern _CommandPtr m_pCom;
extern CString user;
/////////////////////////////////////////////////////////////////////////////
// CDlgBookInput2 dialog



CDlgBookInput2::CDlgBookInput2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBookInput2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBookInput2)
	//}}AFX_DATA_INIT
}


void CDlgBookInput2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBookInput2)
	DDX_Control(pDX, IDC_SUMMONEY, m_summoney);
	DDX_Control(pDX, IDC_STORAGELIST, m_storagelist);
	DDX_Control(pDX, IDC_REBATE, m_rebate);
	DDX_Control(pDX, IDC_PROVIDERLIST, m_providerlist);
	DDX_Control(pDX, IDC_PAYMONEY, m_paymoney);
	DDX_Control(pDX, IDC_OPERATOR, m_operator);
	DDX_Control(pDX, IDC_LIST2, m_auxilist);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_FACTMONEY, m_factmoney);
	DDX_Control(pDX, IDC_DATETIME, m_date);
	DDX_Control(pDX, IDC_PROVIDER, m_provider);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBookInput2, CDialog)
	//{{AFX_MSG_MAP(CDlgBookInput2)
	ON_EN_CHANGE(IDC_REBATE, OnChangeRebate)
	ON_EN_CHANGE(IDC_SUMMONEY, OnChangeSummoney)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	ON_LBN_DBLCLK(IDC_PROVIDERLIST, OnDblclkProviderlist)
	ON_LBN_DBLCLK(IDC_STORAGELIST, OnDblclkStoragelist)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST2, OnKillfocusList2)
	ON_LBN_KILLFOCUS(IDC_PROVIDERLIST, OnKillfocusProviderlist)
	ON_LBN_KILLFOCUS(IDC_STORAGELIST, OnKillfocusStoragelist)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBookInput2 message handlers

BOOL CDlgBookInput2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//��ӹ�Ӧ��
	LoadProvider();
	//��Ӳֿ���Ϣ
	LoadStorage();
	m_storagelist.SetParent(&m_list);
	//��ȡ����Ա����
	m_operator.SetWindowText(user);
	
	//���ñ༭����ɫ
	SetEditColor(RGB(255,0,0));

	m_auxilist.ModifyStyle(LVS_EDITLABELS,0);//��ֹ�༭����
	m_auxilist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_INFOTIP|LVS_EX_SUBITEMIMAGES|LVS_EX_GRIDLINES );

	//�����������
	m_list.InsertColumn(0,"�ֿ�����",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"������",LVCFMT_LEFT,100);
	m_list.InsertColumn(2,"�鼮����",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"����",LVCFMT_LEFT,60);
	m_list.InsertColumn(4,"����",LVCFMT_LEFT,60);
	m_list.InsertColumn(5,"�ۿ�",LVCFMT_LEFT,60);
	m_list.InsertColumn(6,"���",LVCFMT_LEFT,60);

	m_auxilist.InsertColumn(0,"������",LVCFMT_LEFT,100);
	m_auxilist.InsertColumn(1,"�鼮����",LVCFMT_LEFT,80);
	m_auxilist.InsertColumn(2,"����",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(3,"������",LVCFMT_LEFT,60);
	m_auxilist.InsertColumn(4,"Ĭ�ϼ۸�",LVCFMT_LEFT,60);

	//��ӿ���
	m_list.InsertItem(1,"");
	m_list.SetItemText(0,5,"1.0");
	m_auxilist.SetParent(&m_list);

	m_rebate.SetWindowText("1.0");

	m_rebate.IsNumber = true;
	m_factmoney.IsNumber = true;
	
	m_providerlist.SetParent(&m_list);
	//m_list.SetParent(&m_provider);
	return TRUE; 
}

void CDlgBookInput2::OnOK()
{
//
}

void CDlgBookInput2::SetEditColor(COLORREF Color)
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

void CDlgBookInput2::LoadProvider()
{
	m_providerlist.SetRedraw(FALSE);
	m_providerlist.ResetContent();//ɾ�����е�����
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

void CDlgBookInput2::LoadStorage()
{
	m_storagelist.SetRedraw(FALSE);
	m_storagelist.ResetContent();//ɾ�����е�����
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

void CDlgBookInput2::AddNewRow()
{
	int counts = m_list.GetItemCount();
		if (m_list.row == counts-1)//��ǰ��Ϊ���һ��
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

float CDlgBookInput2::CalculateMoney()
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

bool CDlgBookInput2::CurrentRowIsNull()
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

void CDlgBookInput2::DeleteCurRow()
{
	int currow;
	currow = m_list.row;
	if (currow!=-1)
	{
		if (MessageBox("ȷʵҪɾ����ǰ����?","��ʾ",MB_YESNO)==IDYES)
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
			temp.Format("%10.2f",CalculateMoney());//����ͳ������
			temp.TrimLeft();
			m_summoney.SetWindowText(temp);
		}
	}
}

bool CDlgBookInput2::DetailInfoIsNull()
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

void CDlgBookInput2::DoEditKeyDown(UINT nChar, UINT CtrlID)
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

void CDlgBookInput2::EditChange()
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
					//�������\����\�ۿ�Ϊ��,��Ϊ��
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
					//�������\����\�ۿ�Ϊ��,��Ϊ��
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
					//�������\����\�ۿ�Ϊ��,��Ϊ��
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

bool CDlgBookInput2::InputInfoIsNull()
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

void CDlgBookInput2::LimitEdit()
{
	m_list.edit.IsNumber = false;
	//���޸���Ʒ����,�۸�,�ۿ�ʱֻ������������
	if ((m_list.col ==3)||(m_list.col ==4)||(m_list.col==5))
	{
		m_list.edit.IsNumber = true;
	}
}

void CDlgBookInput2::MoveFocus()
{
	m_list.SetFocus();
//	m_list.edit.PostMessage(WM_KILLFOCUS,0,0);
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

void CDlgBookInput2::OnChangeRebate() 
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

void CDlgBookInput2::OnChangeSummoney() 
{
	//�����ۿ۸ı�ʱ���¼�
	OnChangeRebate();	
}

void CDlgBookInput2::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_auxilist.GetSelectionMark();
	if (row!=-1)
	{
		CString temp;
		temp = m_auxilist.GetItemText(row,0);
		//����������
		m_list.SetItemText(m_list.row,1,temp);
		//�����鼮����
		m_list.SetItemText(m_list.row,2,m_auxilist.GetItemText(row,1));
		//����Ĭ�ϼ۸�
		m_list.SetItemText(m_list.row,3,m_auxilist.GetItemText(row,4));
		m_auxilist.ShowWindow(SW_HIDE);
	}
	//�ƶ��༭��
	//MoveFocus();
	m_list.col =3;
	m_list.ShowEdit();
}

void CDlgBookInput2::OnDblclkProviderlist() 
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

void CDlgBookInput2::OnDblclkStoragelist() 
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

void CDlgBookInput2::OnKillfocusList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_auxilist.ShowWindow(SW_HIDE);
}

void CDlgBookInput2::OnKillfocusProviderlist() 
{
	m_providerlist.ShowWindow(SW_HIDE);	
}

void CDlgBookInput2::OnKillfocusStoragelist() 
{
	m_storagelist.ShowWindow(SW_HIDE);	
}


void CDlgBookInput2::ShowListinfo()
{
	if (m_auxilist.IsWindowVisible())
	{
		m_auxilist.SetFocus();
		m_auxilist.SetSelectionMark(1);
	}
}

void CDlgBookInput2::ShowListInfo()
{
	CRect rect;
	m_list.GetSubItemRect(m_list.row,m_list.col,LVIR_BOUNDS,rect);
	m_auxilist.MoveWindow(rect.left,rect.bottom+1,300,150);
	m_auxilist.ShowWindow(SW_SHOW);
}

void CDlgBookInput2::ShowStorage()
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

BOOL CDlgBookInput2::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message ==WM_KEYDOWN)	
	{		
		/****************************************************************
		˵��:  �ڹ�Ӧ�̱༭���ý��㲢��PageDown��,����DoEditKeyDown����
		****************************************************************/
		if ((pMsg->wParam == 34)&&(pMsg->hwnd==m_provider.m_hWnd))
		{
			DoEditKeyDown(34,IDC_PROVIDER);
		}
		/****************************************************************
		˵��:  ����б༭���ý���ʱ,��Enter�����Ƶ�Ԫ�񽹵��ƶ�
		****************************************************************/
		if ((pMsg->wParam == 13)&&(pMsg->hwnd==m_list.edit.m_hWnd))
		{
			MoveFocus();
			return true;
		}	
		/****************************************************************
		˵��:  ����л�ý���ʱ,��Enter���������
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
		˵��:  �б���ý���ʱ,��Enter���Ὣ��ǰ������ʾ�ڱ༭����
		****************************************************************/
		else if ((pMsg->hwnd ==m_providerlist.m_hWnd)&&(pMsg->wParam == 13))
		{
			OnDblclkProviderlist();
			return true;
		}
		/****************************************************************
		˵��:  ����¼�����ý���ʱ,��Enter���Ὣ��ǰ������ʾ�ڱ����
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
	˵��:  ����б༭�򰴼�ʱ���¼�,�����ж��Ƿ������ַ�����,����û���
	PageDown��,��ʹ����¼�����ý���
	****************************************************************/
	if ((pMsg->message == WM_KEYDOWN)&&(pMsg->hwnd == m_list.edit.m_hWnd))
	{
		LimitEdit();	
		if (pMsg->wParam == 34)
		{
			ShowListinfo();
			ShowStorage();
		}
		else if (pMsg->wParam ==VK_DELETE)//��delete��ɾ�����ǰ��
			DeleteCurRow();
	}	
	/****************************************************************
	˵��:  ����б༭��ı�ʱ���¼�
	****************************************************************/
	if ((pMsg->message == WM_KEYUP)&&(pMsg->hwnd == m_list.edit.m_hWnd))
	{
		EditChange();	
	}
	/****************************************************************
	˵��:  �ڴ����пؼ���ý���ʱ,ʹ��ʾ�б��ɼ�
	****************************************************************/
	if (pMsg->message==WM_LBUTTONDOWN)
	{
		if (pMsg->hwnd!= m_auxilist.m_hWnd)
			m_auxilist.ShowWindow(SW_HIDE);
		if (pMsg->hwnd != m_storagelist.m_hWnd)
			m_storagelist.ShowWindow(SW_HIDE);
	
	}
	/****************************************************************
	˵��:  �ڵ������ʱ,���ݵ�ǰ���ж��Ƿ���ʾ�༭��
	****************************************************************/
	if ((pMsg->message ==WM_LBUTTONDOWN)&&(pMsg->hwnd ==m_list.m_hWnd))
	{
		//��ǰ��Ϊ��Ʒ���,��Ʒ����Ϊ��,��ʾ�༭��,�ڵ�ǰ��Ϊ��Ʒ����,��Ʒ���Ϊ��,��ʾ�༭��,
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
			if (col==6) //������������,����ʾ�༭��
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

void CDlgBookInput2::AddOperator()
{
	if (InputInfoIsNull())
	{
		MessageBox("�����Ϣ����Ϊ��","��ʾ",64);
		return;
	}
	if (DetailInfoIsNull())
	{
		MessageBox("��Ʒ��Ϣ����Ϊ��","��ʾ",64);
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
		//m_pCon->BeginTrans();
		sql.Format(" sp_instore '%s','%s',%10.2f,%10.2f,%10.2f,%10.2f,'%s','%s'",c_provider,c_operator,f_rebate,f_sumtotal,f_paymoney,f_factmoney,c_intime,"temp");
		m_pRs->raw_Close();
		//��¼���������Ϣ
		m_pRs->Open((_bstr_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		CString id; //��¼���ص�Ʊ��
		id = m_pRs->GetFields()->GetItem("tempID")->Value.bstrVal;
		//��¼�����ϸ��Ϣ		
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
			detailsql.Format("insert into tb_instock_sub values ('%s','%s',%f,%f,%f,%f,'%s')",id,c_id,f_price,f_num,f_rebate,f_money,c_storage);
			m_pRs->Open((_variant_t)detailsql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			//�޸���Ʒ���
			m_pRs1->raw_Close();
			detailsql.Format("select * from tb_bookstorage where barcode = '%s' and storagename = '%s'",c_id,c_storage);
			m_pRs1->Open((_bstr_t)detailsql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			if (m_pRs1->RecordCount>0)  //�޸���Ʒ�������
			{
				m_pRs1->raw_Close();
				detailsql.Format("update tb_bookstorage set booknum = booknum + %f where barcode = '%s' and storagename = '%s'", f_num ,c_id,c_storage);
				m_pRs1->Open((_bstr_t)detailsql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
			}
			else //�����Ʒ�����Ϣ
			{
				m_pRs1->raw_Close();
				detailsql.Format("insert into tb_bookstorage values ( '%s','%s',%f)",c_id,c_storage,f_num );
				m_pRs1->Open((_bstr_t)detailsql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);				
			}
		}
		//m_pCon->CommitTrans();
		InputCancel();
		MessageBox("�����ɹ�,Ʊ��Ϊ: "+id,"��ʾ",64);
	}
	catch(...)
	{
		//m_pCon->CommitTrans();
		MessageBox("����ʧ��.","��ʾ",64);
	}
}
	

void CDlgBookInput2::InputCancel()
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

void CDlgBookInput2::OnAdd() 
{
	AddOperator();
	
}

void CDlgBookInput2::OnCancel() 
{
	InputCancel();
}

void CDlgBookInput2::OnExit() 
{
	CDialog::OnCancel();	
}
