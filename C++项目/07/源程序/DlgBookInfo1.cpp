// DlgBookInfo1.cpp : implementation file
//

#include "stdafx.h"
#include "bbb.h"
#include "DlgBookInfo1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr m_pCon;  //ADO连接对象
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;
/////////////////////////////////////////////////////////////////////////////
// CDlgBookInfo1 dialog


CDlgBookInfo1::CDlgBookInfo1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBookInfo1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBookInfo1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgBookInfo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBookInfo1)
	DDX_Control(pDX, IDC_COMBO1, m_kinds);
	DDX_Control(pDX, IDC_BOOK_ZHJ_CODE1, m_shortcode);
	DDX_Control(pDX, IDC_BOOK_MARK1, m_memo);
	DDX_Control(pDX, IDC_BOOK_TX_CODE1, m_barcode);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BOOK_PUBLIC1, m_public);
	DDX_Control(pDX, IDC_BOOK_PRICE1, m_price);
	DDX_Control(pDX, IDC_BOOK_AUTHOR1, m_author);
	DDX_Control(pDX, IDC_BOOK_NAME1, m_bookname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBookInfo1, CDialog)
	//{{AFX_MSG_MAP(CDlgBookInfo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBookInfo1 message handlers

BOOL CDlgBookInfo1::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_KEYDOWN)
		if (pMsg->wParam == 13)
			pMsg->wParam = 9;
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDlgBookInfo1::OnInitDialog() 
{
	CDialog::OnInitDialog();
    
    //设置表格风格
	m_list.ModifyStyle(LVS_EDITLABELS,0);
	m_list.ModifyStyle(0,LVS_REPORT);
	m_list.ModifyStyle(0,LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE|LVS_EX_FLATSB);
	
	//添加列
	m_list.InsertColumn(0,"书籍名称");
	m_list.InsertColumn(1,"助记码");
	m_list.InsertColumn(2,"条形码");
	m_list.InsertColumn(3,"作者");
	m_list.InsertColumn(4,"出版社");
	m_list.InsertColumn(5,"价格");
	m_list.InsertColumn(6,"备注");
	m_list.InsertColumn(7,"种类");

	//设置列宽度
	m_list.SetColumnWidth(0,100);
	m_list.SetColumnWidth(1,60);
	m_list.SetColumnWidth(2,80);	
	m_list.SetColumnWidth(3,60);
	m_list.SetColumnWidth(4,80);
	m_list.SetColumnWidth(5,60);
	m_list.SetColumnWidth(6,80);
	m_list.SetColumnWidth(7,60);
	
	//加载图书种类
	AddBookkinds();

	//加载图书信息
	LoadBookInfo();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgBookInfo1::OnOK()
{
//
}

void CDlgBookInfo1::OnCancel()
{
	CDialog::OnCancel();
}

void CDlgBookInfo1::AddBookkinds()
{
	m_kinds.ResetContent();
	m_pRs->raw_Close();
	CString sql;
	sql.Format("select * from tb_bookkinds");
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	while (! m_pRs->adoEOF)
	{
		m_kinds.AddString((TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)0)->Value);
		m_pRs->MoveNext();
	}
}
/***********************************************************************************
说明:  清空界面数据
***********************************************************************************/
void CDlgBookInfo1::ClearInterface()
{
	m_list.DeleteAllItems();
	m_author.SetWindowText("");
	m_barcode.SetWindowText("");
	m_bookname.SetWindowText("");
	m_kinds.SetWindowText("");
	m_list.SetWindowText("");
	m_memo.SetWindowText("");
	m_price.SetWindowText("");
	m_public.SetWindowText("");
	m_shortcode.SetWindowText("");
	m_kinds.SetCurSel(-1);
}


/***************************************************************************************
说明: 判断信息是否为空
****************************************************************************************/
bool CDlgBookInfo1::InfoIsNull()
{
	CWnd * temp;
	temp = this;
	CString text;
	for (int index = 0; index <8;index++)
	{
		temp = this->GetNextDlgTabItem(temp);
		temp->GetWindowText(text);
		if (text.IsEmpty())
			return true;
	}
	return false;
}

/***************************************************************************************
说明: 加载图书信息
****************************************************************************************/

void CDlgBookInfo1::LoadBookInfo()
{
	m_pRs->raw_Close();
	CString sql;
	sql.Format("select * from tb_bookinfo");
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int row = 0;
	m_list.DeleteAllItems();
	while (!m_pRs->adoEOF)
	{
		m_list.InsertItem(100,"");
		for (int col = 0;col <8;col++)
		{
			m_list.SetItemText(row,col,(TCHAR*)(_bstr_t)m_pRs->GetFields()->GetItem((long)col)->Value);
		}
		row += 1;
		m_pRs->MoveNext();
	}
}
/***************************************************************************************
说明:  判断条形码是否存在
****************************************************************************************/
bool CDlgBookInfo1::BarcodeIsExist(LPTSTR barcode)
{
	m_pRs->raw_Close();
	CString sql;
	sql.Format("select * from tb_bookinfo where barcode = '%s'",barcode);
	m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	if (m_pRs->RecordCount>0)
		return true;
	return false;
}
/***************************************************************************************
说明:  添加图书信息
****************************************************************************************/
void CDlgBookInfo1::AddBookInfo()
{
	if (InfoIsNull())
	{
		MessageBox("图书信息不能为空.","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}
	CString c_barcode;
	m_barcode.GetWindowText(c_barcode);
	if (BarcodeIsExist((_bstr_t)c_barcode))
	{
		MessageBox("条形码已经存在.","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}

	CString c_name,c_shortname,c_author,c_press,c_price,c_memo,c_kinds;
	m_bookname.GetWindowText(c_name);
	m_shortcode.GetWindowText(c_shortname);
	m_author.GetWindowText(c_author);
	m_public.GetWindowText(c_press);
	m_price.GetWindowText(c_price);
	m_memo.GetWindowText(c_memo);
	m_kinds.GetWindowText(c_kinds);

	CString sql;
	sql.Format("Insert into tb_bookinfo values ( '%s','%s','%s','%s','%s',%f,'%s','%s')",c_name,c_shortname,c_barcode,c_author,c_press,atof(c_price),c_memo,c_kinds);
	try
	{
		m_pRs->raw_Close();
		m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
		MessageBox("操作成功.","提示",MB_OK|MB_ICONINFORMATION);
		ClearInterface();
		LoadBookInfo();
	}
	catch(...)
	{
		MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
	}
	
}

void CDlgBookInfo1::UpdateBookInfo()
{
	if (!InfoIsNull())
	{
		if (m_list.GetSelectionMark()!=-1)
		{
			if (MessageBox("确实要修改数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
			{
				CString c_barcode;
				c_barcode = m_list.GetItemText(m_list.GetSelectionMark(),2);

				CString c_name,c_newcode,c_shortname,c_author,c_press,c_price,c_memo,c_kinds;
				m_bookname.GetWindowText(c_name);
				m_barcode.GetWindowText(c_newcode);
				m_shortcode.GetWindowText(c_shortname);
				m_author.GetWindowText(c_author);
				m_public.GetWindowText(c_press);
				m_price.GetWindowText(c_price);
				m_memo.GetWindowText(c_memo);
				m_kinds.GetWindowText(c_kinds);

				CString sql;
				sql.Format("update tb_bookinfo set bookname = '%s',shortname = '%s',barcode = '%s',author = '%s',bookconcern = '%s',price = %f,memo = '%s',kind = '%s' where barcode = '%s'"
					,c_name,c_shortname,c_newcode,c_author,c_press,atof(c_price),c_memo,c_kinds,c_barcode);
				m_pRs->raw_Close();
				try
				{
					m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					ClearInterface();
					LoadBookInfo();
					MessageBox("操作成功.","提示",64);
				}
				catch(...)
				{
					MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
				}
			}
		}
		else
			MessageBox("请选择欲修改的信息.","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
		MessageBox("基础信息不完整.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgBookInfo1::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int row = m_list.GetSelectionMark();
	if (row !=-1)
	{
		m_bookname.SetWindowText(m_list.GetItemText(row,0));
		m_shortcode.SetWindowText(m_list.GetItemText(row,1));
		m_barcode.SetWindowText(m_list.GetItemText(row,2));
		m_author.SetWindowText(m_list.GetItemText(row,3));
		m_public.SetWindowText(m_list.GetItemText(row,4));
		m_price.SetWindowText(m_list.GetItemText(row,5));
		m_memo.SetWindowText(m_list.GetItemText(row,6));
		m_kinds.SetCurSel(m_kinds.FindString(0,m_list.GetItemText(row,7)));
	}
	*pResult = 0;
}

void CDlgBookInfo1::DeleteBookInfo()
{
	if (m_list.GetSelectionMark()!=-1)
	{
		if (MessageBox("确实要删除数据吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{
			int i = m_list.GetSelectionMark();
			CString c_barcode = m_list.GetItemText(i,2);
			CString sql;
			sql.Format("delete tb_bookinfo where barcode= '%s'",c_barcode);
			m_pRs->raw_Close();
			try
			{
				m_pRs->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
				ClearInterface();
				LoadBookInfo();
				MessageBox("操作成功.","提示",64);
			}
			catch(...)
			{
				MessageBox("操作失败.","提示",MB_OK|MB_ICONERROR);
			}
		}
	}
	else
		MessageBox("请选择欲删除的信息.","提示",MB_OK|MB_ICONINFORMATION);
}

void CDlgBookInfo1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

}

void CDlgBookInfo1::OnAdd() 
{
	AddBookInfo();	
}

void CDlgBookInfo1::OnChange() 
{
	UpdateBookInfo();
	
}

void CDlgBookInfo1::OnDel() 
{
	DeleteBookInfo();
	
}


