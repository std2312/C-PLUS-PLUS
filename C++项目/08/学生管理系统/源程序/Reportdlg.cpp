// Reportdlg.cpp : implementation file
//

#include "stdafx.h"
#include "mystudentsys.h"
#include "Reportdlg.h"
#include "comdef.h" 
#include "ExternDllHeader.h" 
#include <time.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HINSTANCE hInstance;
/////////////////////////////////////////////////////////////////////////////
// CReportdlg dialog


CReportdlg::CReportdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReportdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReportdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReportdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReportdlg, CDialog)
	//{{AFX_MSG_MAP(CReportdlg)
	ON_BN_CLICKED(IDC_Btnreport, OnBtnreport)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportdlg message handlers

void CReportdlg::OnBtnreport() 
{
	// TODO: Add your control notification handler code here
	
	_Application ExcelApp; 
	Workbooks wbsMyBooks; 
	_Workbook wbMyBook; 
	Worksheets wssMysheets; 
	_Worksheet wsMysheet; 
	Range rgMyRge; 	
	//创建Excel 2000服务器(启动Excel) 
	if (!ExcelApp.CreateDispatch("Excel.Application",NULL)) 
	{ 
		AfxMessageBox("创建Excel服务失败!"); 
		exit(1); 
	} 
	ExcelApp.SetVisible(false); 
	//利用模板文件建立新文档 
	char path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,path);
	CString strPath = path;
	strPath += "\\stureporttemplate";
	wbsMyBooks.AttachDispatch(ExcelApp.GetWorkbooks(),true); 
	wbMyBook.AttachDispatch(wbsMyBooks.Add(_variant_t(strPath)));
	//得到Worksheets 
	wssMysheets.AttachDispatch(wbMyBook.GetWorksheets(),true);
	//得到sheet1 
	wsMysheet.AttachDispatch(wssMysheets.GetItem(_variant_t("sheet1")),true);
	CString str1;
	wsMysheet.AttachDispatch(wssMysheets.GetItem(_variant_t("sheet1")),true);
	str1 = "第1页";
	wsMysheet.SetName(str1);
	for( int i=0;i<wssMysheets.GetCount()-1;i++)
	{
		wsMysheet = wsMysheet.GetNext();
		str1.Format("第%d页",i+2);
		wsMysheet.SetName(str1);
	}
	wsMysheet.AttachDispatch(wssMysheets.GetItem(_variant_t("第1页")),true);
	//得到全部Cells，此时,rgMyRge是cells的集合 
	rgMyRge.AttachDispatch(wsMysheet.GetCells(),true); 
	CTime tDate;
	CString sDate;
	myexamsubmarkset_report->MoveFirst();
	for(int setnum=0;setnum<myexamsubmarkset_report->GetRecordCount();setnum++)
	{
		rgMyRge.SetItem(_variant_t((long)(3+setnum)),_variant_t((long)(1)),
			_variant_t(myexamsubmarkset_report->m_studentid));  
		rgMyRge.SetItem(_variant_t((long)(3+setnum)),_variant_t((long)(2)),
			_variant_t(myexamsubmarkset_report->m_code)); 
		rgMyRge.SetItem(_variant_t((long)(3+setnum)),_variant_t((long)(3)),
			_variant_t(myexamsubmarkset_report->m_grade));  
		rgMyRge.SetItem(_variant_t((long)(3+setnum)),_variant_t((long)(4)),
			_variant_t(myexamsubmarkset_report->m_kind));  
		tDate = myexamsubmarkset_report->m_examdate;
		sDate = tDate.Format("%m/%d/%y");
		rgMyRge.SetItem(_variant_t((long)(3+setnum)),_variant_t((long)(5)),_variant_t(sDate));  
		myexamsubmarkset_report->MoveNext();
	}
	//将表格保存
	strPath = path;
	strPath += "\\mystudentreport.xls";
	wsMysheet.SaveAs(strPath,vtMissing,vtMissing,vtMissing,vtMissing,
		vtMissing,vtMissing,vtMissing,vtMissing);
	ExcelApp.SetVisible(true); 
	wbMyBook.PrintPreview(_variant_t(false)); 
	//释放对象 
	rgMyRge.ReleaseDispatch(); 
	wsMysheet.ReleaseDispatch(); 
	wssMysheets.ReleaseDispatch(); 
	wbMyBook.ReleaseDispatch(); 
	wbsMyBooks.ReleaseDispatch();
	ExcelApp.ReleaseDispatch(); 	
}

BOOL CReportdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
//////////////////////////////////////////////////////////////
	hInstance =LoadLibrary("RxDLL.dll");
	CString sqlStr;
	sqlStr="SELECT * FROM tb_examinfo_sub";
	myexamsubmarkset_report = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myexamsubmarkset_report->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr))
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}
	CString sqlStr_sort;
	sqlStr_sort="SELECT * FROM tb_examinfo_sub ORDER BY tb_examinfo_sub.grade DESC ";
	myexamsubmarkset_report_sort = new CExaminfo_submarkset(&((CMystudentsysApp*)AfxGetApp())->m_DB);
	if(!myexamsubmarkset_report_sort->Open(AFX_DB_USE_DEFAULT_TYPE,sqlStr_sort))
	{
		AfxMessageBox("tb_examinfo_sub表打开失败!");
	}	
	return TRUE;
}

void CReportdlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(myexamsubmarkset_report->IsOpen())
	{
		myexamsubmarkset_report->Close();
		delete myexamsubmarkset_report;
	}
	if(myexamsubmarkset_report_sort->IsOpen())
	{
		myexamsubmarkset_report_sort->Close();
		delete myexamsubmarkset_report_sort;
	}
	CDialog::OnClose();
}

void CReportdlg::OnOK()
{

}
