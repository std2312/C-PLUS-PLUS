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
	m_TimeCardList.InsertColumn(0, "����", LVCFMT_LEFT, 80);
	m_TimeCardList.InsertColumn(1, "����", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(2, "�ٵ�", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(3, "����", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(4, "ȱ��", LVCFMT_LEFT, 50);
	m_TimeCardList.InsertColumn(5, "ȱ������", LVCFMT_LEFT, 80);
	m_TimeCardList.InsertColumn(6, "����ʱ��", LVCFMT_LEFT, 80);

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
			m_TimeCardList.SetItemText(i, 2, "��");
		else
			m_TimeCardList.SetItemText(i, 2, "��");

		tmCard.GetItemContent("leave_early", CADOOperation::ADO_TYPE_INT, &num);
		if(0!=num)
			m_TimeCardList.SetItemText(i, 3, "��");
		else
			m_TimeCardList.SetItemText(i, 3, "��");

		tmCard.GetItemContent("timecart_reason", CADOOperation::ADO_TYPE_INT, &num);
		switch(num)
		{
		case 0:
			m_TimeCardList.SetItemText(i, 4, "��");
			break;
		case 1:
			m_TimeCardList.SetItemText(i, 4, "��");
			m_TimeCardList.SetItemText(i, 5, "�¼�");
			break;
		case 2:
			m_TimeCardList.SetItemText(i, 4, "��");
			m_TimeCardList.SetItemText(i, 5, "����");
			break;
		case 3:
			m_TimeCardList.SetItemText(i, 4, "��");
			m_TimeCardList.SetItemText(i, 5, "����");
			break;
		default:
			tmCard.CloseRecorset();
			return FALSE;
		}
		tmCard.GetItemContent("timecart_worklong", CADOOperation::ADO_TYPE_INT, &num);
		str.Format("%dСʱ%d��", num/60, num%60);
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
		MessageBox("������һ���Ϸ������֣�", "��ʾ", MB_OK | MB_ICONWARNING);
		return ;
	}
	year = GetDlgItemInt(IDC_COMBO2);
	month = GetDlgItemInt(IDC_COMBO3);
	if(year < 0 || (month >12 && month < 0))
	{
		MessageBox("��ѡ���������ڷ�Χ��", "��ʾ", MB_OK | MB_ICONWARNING);
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
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Word �ļ�(*.doc) | .doc||", NULL);
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
				  select tb_employee.employee_id as Ա�����, \
				  tb_employee.employee_name as Ա������, \
				  timecart_date as ���ڿ�����,\
				  timecart_reason as ȱ��ԭ��,\
				  timecart_worklong ����ʱ��, \
				  timecart_late_leave_early & 1  �Ƿ�ٵ�, \
				  timecart_late_leave_early & 2  �Ƿ�����\
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
		���´���Ϊ���ݿ��ʼ����������
	*/
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordset;
	Fields* fields = NULL;
	_bstr_t bstrSQL = sql;
	long count = 0;			//��ͷԪ�ظ���
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
	count = fields->Count;		//�õ���ͷԪ�ظ���


	/*
		���´���ΪWordӦ�ö���ĳ�ʼ������
	*/
	_Application	application;		//����һ��WordӦ�ö���
	_Document		document;
	Documents		documents;
	Tables			tables;
	Range			range;
	Selection		selection;
	COleVariant		colevariant;

	CComVariant Template(_T("")), NewTemplate(false), DocumentType(0), Visible(true);

	application.CreateDispatch("Word.Application");
	documents.AttachDispatch(application.GetDocuments());
	document.AttachDispatch(documents.Add(&Template,	//��ģ��
		&NewTemplate,									//�����½�ģ��
		&DocumentType,									//������
		&Visible));										//��ʼ���ɼ�
	range.AttachDispatch(document.GetContent());
	tables.AttachDispatch(document.GetTables());
	tables.Add(range, GetRecordCount(pRecordset),	//��¼��
		count, colevariant, colevariant);						//��ӱ��
	selection.AttachDispatch(application.GetSelection());

	
	CString strText;
	BSTR bstr;

	_variant_t varField[20];
	for(long num = 0; num < count; num++)
	{
		strText.Format("%d", num);
		(fields->Item[(long)num])->get_Name(&bstr);
		varField[num] = bstr;

		selection.TypeText((char*)(_bstr_t)bstr);	//��������
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
					selection.TypeText("ȫ��");
					break;
				case 1:
					selection.TypeText("�¼�");
					break;
				case 2:
					selection.TypeText("����");
					break;
				case 3:
					selection.TypeText("����");
					break;
				default:
					{
						MessageBox("ϵͳ���ִ���");
						exit(0);
					}
				}
				
			}
			else if(num == 5 || num == 6)
			{
				content = (char *)(_bstr_t)pRecordset->GetCollect(varField[num]);
				content.Replace(" ", "");
				if(atoi(content) > 0)
					selection.TypeText("��");
				else
					selection.TypeText("��");
			}
			else
				selection.TypeText((char *)(_bstr_t)pRecordset->GetCollect(varField[num]));	//�Ѷ�Ӧ��ͷ�������Ϣ���뵽Word�ı���
			selection.MoveRight((COleVariant)"1", (COleVariant)"1", (COleVariant)"0");	//�ƶ����
		}
		pRecordset->MoveNext();
	}
	//�Ͽ�����
	if(pConnection != NULL)
		pConnection->Close();
	pConnection = NULL;

	//�������
	_Document saveDoc = application.GetActiveDocument();	//�õ�ActiveDocument

	CComVariant FileName("");		//�����λ��
	if(file.IsEmpty())
		FileName = "C:\\DataBaseTable.doc";
	else
		FileName = file;

	CComVariant FileFormat(0);						//�����ص㿴�����˵��
	CComVariant LockComments(FALSE), Password(_T(""));
	CComVariant AddToRecentFiles(true),WritePassword("");
	CComVariant ReadOnlyRecommended(false), EmbedTrueTypeFonts(false);
	CComVariant SaveNativePictureFormat(false), SaveFormsData(false);
	CComVariant SaveAsAOCELetter(false);
	saveDoc.SaveAs(&FileName, &FileFormat, &LockComments, &Password, 
		&AddToRecentFiles, &WritePassword, &ReadOnlyRecommended, 
		&EmbedTrueTypeFonts, &SaveNativePictureFormat, &SaveFormsData,&SaveAsAOCELetter);

	//����Word���ڿɼ����ͷ�Ӧ�ó������Դ
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
		MessageBox("��ѡ��һ����Ҫɾ�����");
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
	MessageBox("����");
}

BOOL CTimeCardList::CollectTimeCard(CString &name, int year, int month)
{
	int count = m_TimeCardList.GetItemCount();
	CString con;

	m_TimeCardList.InsertItem(count, "����������");
	con.Format("%d", GetLeaveEarlyCount(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "�ٵ�������");
	con.Format("%d", GetLateCount(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "ȱ��������");
	con.Format("%d", GetAbsenceDuty(name, year, month));
	m_TimeCardList.SetItemText(count, 1, con);
	count++;
	m_TimeCardList.InsertItem(count, "�ܹ���ʱ�䣺");
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
