// TimeCardList.cpp : implementation file
//

#include "stdafx.h"
#include "hrms.h"
#include "TimeCardList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeCardList dialog


CTimeCardList::CTimeCardList(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeCardList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeCardList)
	//}}AFX_DATA_INIT
	m_CurSel = -1;
}


void CTimeCardList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeCardList)
	DDX_Control(pDX, IDC_LIST1, m_TimeCardList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeCardList, CDialog)
	//{{AFX_MSG_MAP(CTimeCardList)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_EXPORT, OnExport)
	ON_COMMAND(IDM_DELETEITEM, OnDeleteitem)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_QUIT, OnQuit)
	ON_COMMAND(IDM_SEARCH_RECORD, OnSearchRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeCardList message handlers



BOOL CTimeCardList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox * pCom = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CTimeCardDlg::InitEmployeeList(pCom);
	m_TimeCardList.SetExtendedStyle(
		LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES );
	m_TimeCardList.InsertColumn(0, "日期", LVCFMT_LEFT, 80);
	m_TimeCardList.InsertColumn(1, "姓名", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(2, "迟到", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(3, "早退", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(4, "缺勤", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(5, "缺勤类型", LVCFMT_LEFT, 80);
	m_TimeCardList.InsertColumn(6, "工作时间", LVCFMT_LEFT, 80);

	OnSelchangeCombo1();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CTimeCardList::ShowTimeCardList(CString name, int year, int month)
{
	ASSERT(!name.IsEmpty());
	ASSERT(month > 0 && month < 13);

	CADOOperation tmCard;
	CString sql, str;
	DWORD num = 0;
	int i = 0; 

	sql.Format("\
				  select timecart_date,\
				  timecart_reason,\
				  timecart_worklong, \
				  timecart_late_leave_early & 1 as late, \
				  timecart_late_leave_early & 2 as leave_early\
				  from tb_timecard, tb_employee\
				  where year(timecart_date) = %d \
				  and month(timecart_date) = %d \
				  and tb_employee.employee_name = '%s' and\
				  tb_employee.employee_id = tb_timecard.employee_id", year, month, name);
	tmCard.OpenRecordset(sql);
	m_TimeCardList.DeleteAllItems();
	if(tmCard.IsLastRow())
	{
		tmCard.CloseRecorset();
		return TRUE;
	}
	tmCard.MoveFirst();
	do
	{
		tmCard.GetItemContent("timecart_date", CADOOperation::ADO_TYPE_STRING, &str);
		m_TimeCardList.InsertItem(i, str.GetBuffer(0));
		m_TimeCardList.SetItemText(i, 1, name);
		tmCard.GetItemContent("late", CADOOperation::ADO_TYPE_INT, &num);
		if(0!=num)
			m_TimeCardList.SetItemText(i, 2, "是");
		else
			m_TimeCardList.SetItemText(i, 2, "否");

		tmCard.GetItemContent("leave_early", CADOOperation::ADO_TYPE_INT, &num);
		if(0!=num)
			m_TimeCardList.SetItemText(i, 3, "是");
		else
			m_TimeCardList.SetItemText(i, 3, "否");

		tmCard.GetItemContent("timecart_reason", CADOOperation::ADO_TYPE_INT, &num);
		switch(num)
		{
		case 0:
			m_TimeCardList.SetItemText(i, 4, "否");
			break;
		case 1:
			m_TimeCardList.SetItemText(i, 4, "是");
			m_TimeCardList.SetItemText(i, 5, "事假");
			break;
		case 2:
			m_TimeCardList.SetItemText(i, 4, "是");
			m_TimeCardList.SetItemText(i, 5, "公假");
			break;
		case 3:
			m_TimeCardList.SetItemText(i, 4, "是");
			m_TimeCardList.SetItemText(i, 5, "病假");
			break;
		default:
			tmCard.CloseRecorset();
			return FALSE;
		}
		tmCard.GetItemContent("timecart_worklong", CADOOperation::ADO_TYPE_INT, &num);
		str.Format("%d小时%d分", num/60, num%60);
		m_TimeCardList.SetItemText(i, 6, str);
		i++;
		tmCard.MoveNext();
	}while(!tmCard.IsLastRow());

	tmCard.CloseRecorset();

	return TRUE;
}

void CTimeCardList::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here

	CString name;
	GetDlgItemText(IDC_COMBO1, name);
	InitYearComboBox(name);

	OnSelchangeCombo2();
}

void CTimeCardList::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CString name;
	int year;

	GetDlgItemText(IDC_COMBO1, name);
	year = GetDlgItemInt(IDC_COMBO2);
	InitMonthComboBox(name, year);

	UpdateTimeCardList();
}

void CTimeCardList::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	UpdateTimeCardList();
}

void CTimeCardList::UpdateTimeCardList()
{

	CString str;
	int year, month;

	GetDlgItemText(IDC_COMBO1, str);
	str.Replace(" ", "");
	if(str.IsEmpty())
	{
		MessageBox("请输入一个合法的名字！", "提示", MB_OK | MB_ICONWARNING);
		return ;
	}
	year = GetDlgItemInt(IDC_COMBO2);
	month = GetDlgItemInt(IDC_COMBO3);
	if(year < 0 || (month >12 && month < 0))
	{
		MessageBox("请选择合理的日期范围！", "提示", MB_OK | MB_ICONWARNING);
		return ;
	}
	if(month > 12 || month < 1)
	{
		m_TimeCardList.DeleteAllItems();
		return;
	}
	
	ShowTimeCardList(str, year, month);
	CollectTimeCard(str, year, month);

}

BOOL CTimeCardList::InitYearComboBox(CString name)
{

	CComboBox* pYear;
	CADOOperation yl;
	CString sql, con;

	pYear = (CComboBox* )GetDlgItem(IDC_COMBO2);
	pYear->ResetContent();

	sql.Format("\
				  select distinct year(timecart_date) as yea\
				  from tb_timecard, tb_employee \
				  where tb_employee.employee_name = '%s' \
				  and tb_employee.employee_id = tb_timecard.employee_id", name);
	yl.OpenRecordset(sql);
	if(yl.IsLastRow())
	{
		yl.CloseRecorset();
		return TRUE;
	}
	yl.MoveFirst();
	do
	{
		yl.GetItemContent("yea", CADOOperation::ADO_TYPE_STRING, &con);
		pYear->AddString(con);
		yl.MoveNext();
	}while(!yl.IsLastRow());
	yl.CloseRecorset();

	pYear->SetCurSel(pYear->GetCount()-1);
	return TRUE;
}

BOOL CTimeCardList::InitMonthComboBox(CString name, int year)
{

	CComboBox* pMonth;
	CADOOperation ml;
	CString sql, con;

	pMonth = (CComboBox* )GetDlgItem(IDC_COMBO3);
	sql.Format("\
				  select distinct month(timecart_date) as mon\
				  from tb_timecard, tb_employee\
				  where year(timecart_date) = %d and tb_employee.employee_name = '%s'\
				  and tb_employee.employee_id = tb_timecard.employee_id", year, name);
	pMonth->ResetContent();
	ml.OpenRecordset(sql);
	if(ml.IsLastRow())
	{
		ml.CloseRecorset();
		return TRUE;
	}
	ml.MoveFirst();
	do
	{
		ml.GetItemContent("mon", CADOOperation::ADO_TYPE_STRING, &con);
		pMonth->AddString(con);
		ml.MoveNext();
	}while(!ml.IsLastRow());
	ml.CloseRecorset();
	pMonth->SetCurSel(pMonth->GetCount()-1);

	return TRUE;
}

void CTimeCardList::OnExport() 
{
	// TODO: Add your control notification handler code here
	SYSTEMTIME sysTime;
	::GetSystemTime(&sysTime);
	CString str;
	str.Format("%d-%d-%d", sysTime.wYear, sysTime.wMonth, sysTime.wDay);
	CFileDialog file(FALSE, ".doc", str,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Word 文件(*.doc) | .doc||", NULL);
	if(IDOK != file.DoModal())
		return ;

	str = file.GetPathName();
	ExportToWord(str);
}

BOOL CTimeCardList::ExportToWord(CString &file)
{

	CADOOperation tmCard;
	CString sql, name;
	int year, month;
	GetDlgItemText(IDC_COMBO1, name);
	year = GetDlgItemInt(IDC_COMBO2);
	month = GetDlgItemInt(IDC_COMBO3);

	sql.Format("\
				  select tb_employee.employee_id as 员工编号, \
				  tb_employee.employee_name as 员工姓名, \
				  timecart_date as 考勤卡日期,\
				  timecart_reason as 缺勤原因,\
				  timecart_worklong 工作时间, \
				  timecart_late_leave_early & 1  是否迟到, \
				  timecart_late_leave_early & 2  是否早退\
				  from tb_timecard, tb_employee\
				  where year(timecart_date) = %d \
				  and month(timecart_date) = %d \
				  and tb_employee.employee_name = '%s' and\
				  tb_employee.employee_id = tb_timecard.employee_id", year, month, name);
	ExportToWord(file, sql);
	return TRUE;
}


BOOL CTimeCardList::ExportToWord(CString &file, CString &sql)
{
	/*
		以下代码为数据库初始化操作部分
	*/
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordset;
	Fields* fields = NULL;
	_bstr_t bstrSQL = sql;
	long count = 0;			//表头元素个数
	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pConnection->Open(_bstr_t(Provider), "", "", adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		exit(0);
	}
	pRecordset.CreateInstance(_uuidof(Recordset));
	pRecordset->Open(bstrSQL, 
		pConnection.GetInterfacePtr(), 
		adOpenDynamic, adLockOptimistic, adCmdText);
	pRecordset->get_Fields(&fields);
	count = fields->Count;		//得到表头元素个数


	/*
		以下代码为Word应用对象的初始化过程
	*/
	_Application	application;		//创建一个Word应用对象
	_Document		document;
	Documents		documents;
	Tables			tables;
	Range			range;
	Selection		selection;
	COleVariant		colevariant;

	CComVariant Template(_T("")), NewTemplate(false), DocumentType(0), Visible(true);

	application.CreateDispatch("Word.Application");
	documents.AttachDispatch(application.GetDocuments());
	document.AttachDispatch(documents.Add(&Template,	//无模板
		&NewTemplate,									//不是新建模板
		&DocumentType,									//无类型
		&Visible));										//初始不可见
	range.AttachDispatch(document.GetContent());
	tables.AttachDispatch(document.GetTables());
	tables.Add(range, GetRecordCount(pRecordset),	//记录数
		count, colevariant, colevariant);						//添加表格
	selection.AttachDispatch(application.GetSelection());

	
	CString strText;
	BSTR bstr;

	_variant_t varField[20];
	for(long num = 0; num < count; num++)
	{
		strText.Format("%d", num);
		(fields->Item[(long)num])->get_Name(&bstr);
		varField[num] = bstr;

		selection.TypeText((char*)(_bstr_t)bstr);	//插入数据
		selection.MoveRight((COleVariant)"1", (COleVariant)"1", (COleVariant)"0");

	}

	CString content;
	if(!pRecordset->adoBOF)
		pRecordset->MoveFirst();
	while(!pRecordset->adoEOF)
	{
		for(long num = 0; num < (pRecordset->GetFields())->GetCount(); num++)
		{
			strText.Format("%d", num);
			if(num == 3)
			{
				content = (char *)(_bstr_t)pRecordset->GetCollect(varField[num]);
				content.Replace(" ", "");
				switch(atoi(content))
				{
				case 0:
					selection.TypeText("全勤");
					break;
				case 1:
					selection.TypeText("事假");
					break;
				case 2:
					selection.TypeText("公假");
					break;
				case 3:
					selection.TypeText("病假");
					break;
				default:
					{
						MessageBox("系统出现错误！");
						exit(0);
					}
				}
				
			}
			else if(num == 5 || num == 6)
			{
				content = (char *)(_bstr_t)pRecordset->GetCollect(varField[num]);
				content.Replace(" ", "");
				if(atoi(content) > 0)
					selection.TypeText("是");
				else
					selection.TypeText("否");
			}
			else
				selection.TypeText((char *)(_bstr_t)pRecordset->GetCollect(varField[num]));	//把对应表头的相关信息输入到Word的表中
			selection.MoveRight((COleVariant)"1", (COleVariant)"1", (COleVariant)"0");	//移动光标
		}
		pRecordset->MoveNext();
	}
	//断开连接
	if(pConnection != NULL)
		pConnection->Close();
	pConnection = NULL;

	//保存代码
	_Document saveDoc = application.GetActiveDocument();	//得到ActiveDocument

	CComVariant FileName("");		//保存的位置
	if(file.IsEmpty())
		FileName = "C:\\DataBaseTable.doc";
	else
		FileName = file;

	CComVariant FileFormat(0);						//这是重点看下面的说明
	CComVariant LockComments(FALSE), Password(_T(""));
	CComVariant AddToRecentFiles(true),WritePassword("");
	CComVariant ReadOnlyRecommended(false), EmbedTrueTypeFonts(false);
	CComVariant SaveNativePictureFormat(false), SaveFormsData(false);
	CComVariant SaveAsAOCELetter(false);
	saveDoc.SaveAs(&FileName, &FileFormat, &LockComments, &Password, 
		&AddToRecentFiles, &WritePassword, &ReadOnlyRecommended, 
		&EmbedTrueTypeFonts, &SaveNativePictureFormat, &SaveFormsData,&SaveAsAOCELetter);

	//设置Word窗口可见并释放应用程序的资源
	application.SetVisible(TRUE);
	tables.ReleaseDispatch();
	selection.ReleaseDispatch();
	documents.ReleaseDispatch();
	document.ReleaseDispatch();
	application.ReleaseDispatch();

	return TRUE;
}

DWORD CTimeCardList::GetRecordCount(_RecordsetPtr pRecordset)
{
	DWORD count = 1;
	if(!pRecordset->adoEOF)
		pRecordset->MoveFirst();
	else
		return 0;
	do{
		pRecordset->MoveNext();
		count++;

	} while(!pRecordset->adoEOF);

	return count;
}

void CTimeCardList::OnDeleteitem() 
{
	// TODO: Add your command handler code here
	if(m_CurSel < 0)
	{
		MessageBox("请选择一个所要删除的项！");
		return ;
	}
	CADOOperation ado;
	CString date = m_TimeCardList.GetItemText(m_CurSel, 0);
	CString name = m_TimeCardList.GetItemText(m_CurSel, 1);
	CString sql;
	sql.Format("\
				  delete from tb_timecard \
				  where tb_timecard.employee_id in \
				  (select tb_employee.employee_id from tb_employee, tb_timecard\
				  where tb_timecard.employee_id = tb_bargain.employee_id and employee_name = '%s')\
				  and timecart_date = '%s'", name, date);
	ado.OpenRecordset(sql);
	ado.CloseRecorset();
	m_CurSel = -1;
	UpdateTimeCardList();
}

void CTimeCardList::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_CurSel = ((LPNMLISTVIEW)pNMHDR)->iItem;
/*	if(m_CurSel < 0)
		goto end;
	POINT pt;
	::GetCursorPos(&pt);
	CADOView::ShowItemMenu(G_IsLanded, pt.x, pt.y, this);*/

end:
	*pResult = 0;
}

void CTimeCardList::OnQuit() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}

void CTimeCardList::OnSearchRecord() 
{
	// TODO: Add your command handler code here
	MessageBox("检索");
}

BOOL CTimeCardList::CollectTimeCard(CString &name, int year, int month)
{
	int count = m_TimeCardList.GetItemCount();
	CString con;

	m_TimeCardList.InsertItem(count, "早退总数：");
	con.Format("%d", GetLeaveEarlyCount(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "迟到总数：");
	con.Format("%d", GetLateCount(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "缺勤总数：");
	con.Format("%d", GetAbsenceDuty(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "总工作时间：");
	con.Format("%.1f", GetCollectWorkTime(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);

	return TRUE;
}

DWORD CTimeCardList::GetAbsenceDuty(CString &name, int year, int month)
{
	DWORD count = 0;
	CString sql;
	sql.Format("\
				  select count(*) from tb_timecard, tb_employee\
				  where tb_employee.employee_name = '%s' and tb_employee.employee_id = tb_timecard.employee_id and \
				  year(tb_timecard.timecart_date) = %d and month(tb_timecard.timecart_date) = %d\
				  and tb_timecard.timecart_reason > 0", name, year, month);
	CADOOperation ado;
	ado.OpenRecordset(sql);
	ado.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	ado.CloseRecorset();
	return count;
}

double CTimeCardList::GetCollectWorkTime(CString &name, int year, int month)
{
	double collect = 0.0;
	DWORD count = 0;
	CString sql;
	CADOOperation ado;
	sql.Format("\
				  select sum(tb_timecard.timecart_worklong) as sum from tb_timecard, tb_employee\
				  where tb_employee.employee_name = '%s' and tb_employee.employee_id = tb_timecard.employee_id and \
				  year(tb_timecard.timecart_date) = %d and month(tb_timecard.timecart_date) = %d", name, year, month);
	PRINTRESULT(sql)
	ado.OpenRecordset(sql);
	ado.GetItemContent("sum", CADOOperation::ADO_TYPE_INT, &count);
	collect = (double)count/(double)60;
	ado.CloseRecorset();
	return collect;

}

DWORD CTimeCardList::GetLateCount(CString &name, int year, int month)
{
	DWORD count = 0;
	CADOOperation ado;
	CString sql;
	sql.Format("\
				  select count(*) from tb_timecard,tb_employee\
				  where timecart_late_leave_early & 1 >0\
				  and year(timecart_date) = %d \
				  and month(timecart_date) = %d\
				  and tb_employee.employee_name = '%s'\
				  and tb_employee.employee_id = tb_timecard.employee_id", year, month, name);
	ado.OpenRecordset(sql);
	ado.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	ado.CloseRecorset();
	return count;
}

DWORD CTimeCardList::GetLeaveEarlyCount(CString &name, int year, int month)
{
	DWORD count = 0;
	CADOOperation ado;
	CString sql;
	sql.Format("select count(*) from tb_timecard,tb_employee\
				  where timecart_late_leave_early & 2 >0\
				  and year(timecart_date) = %d \
				  and month(timecart_date) = %d\
				  and tb_employee.employee_name = '%s'\
				  and tb_employee.employee_id = tb_timecard.employee_id", year, month, name);
	ado.OpenRecordset(sql);
	ado.GetItemContent(0, CADOOperation::ADO_TYPE_INT, &count);
	ado.CloseRecorset();
	return count;
}
