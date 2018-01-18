// ADOOperation.cpp: implementation of the CADOOperation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hrms.h"
#include "ADOOperation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const DWORD CADOOperation::ADO_TYPE_STRING			= 100;
const DWORD CADOOperation::ADO_TYPE_BITMAP_FIEL		= 101;
const DWORD CADOOperation::ADO_TYPE_INT				= 102;
const DWORD CADOOperation::ADO_TYPE_FLOAT			= 103;
const DWORD CADOOperation::ADO_TYPE_DATE			= 104;
const DWORD CADOOperation::ADO_TYPE_BITMAP_HANDLE	= 105;
const DWORD CADOOperation::ADO_TYPE_TEXT			= 106;

CADOOperation::CADOOperation()
{
	try{
		m_pConnection.CreateInstance(_uuidof(Connection));
		m_pConnection->Open(_bstr_t(Provider), "", "", adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description(), MB_OK);
		exit(0);
	}
	m_pRecordset.CreateInstance(_uuidof(Recordset));
	m_CurrentRecord = -1;
}

CADOOperation::~CADOOperation()
{
	m_pConnection->Close();
}

BOOL CADOOperation::OpenTable(CString name)
{

	ASSERT(!name.IsEmpty());
	CString sql;
	sql.Format("select * from %s" , name);
	try
	{
		m_pRecordset->Open(_bstr_t(sql), 
			m_pConnection.GetInterfacePtr(), 
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}

	return TRUE;
}

BOOL CADOOperation::CloseTable()
{

	try
	{
		if(adStateOpen == m_pRecordset->GetState())
			m_pRecordset->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

HRESULT CADOOperation::AddNew()
{
	return m_pRecordset->AddNew();
}

BOOL CADOOperation::UpdateData()
{
	try
	{
		  m_pRecordset->Update();
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}

	return  TRUE;
}

BOOL CADOOperation::SetItemContent(CString field, 
								   DWORD type, 
								   const void *variable)
{
	ASSERT(!field.IsEmpty());
	ASSERT(variable != NULL);

	try
	{
		switch(type)
		{
		case ADO_TYPE_STRING:
			m_pRecordset->PutCollect(_bstr_t(field), _bstr_t(*(CString*)(variable)));
			break;
		case ADO_TYPE_BITMAP_FIEL:
			{
				CString* lpStr = (CString*)variable;
				VARIANT bitData = {0};
				CFile file(*lpStr, CFile::modeRead);
				DWORD fileSize = file.GetLength() + 1;
				char* bitBuffer = new char[fileSize];

				file.ReadHuge(bitBuffer, fileSize);
				file.Close();
				
				bitData.vt = VT_ARRAY | VT_UI1;
				SAFEARRAY* pSafeArray;
				SAFEARRAYBOUND arrayBound[1];
				arrayBound[0].cElements = fileSize - 1;
				arrayBound[0].lLbound = 0;
				
				pSafeArray = ::SafeArrayCreate(VT_UI1, 1, arrayBound);
				for(long i = 0; i < fileSize-1; i++)
					::SafeArrayPutElement(pSafeArray, &i, bitBuffer++);
				bitData.parray = pSafeArray;

				m_pRecordset->GetFields()->GetItem(_bstr_t(field))->AppendChunk(bitData);
			}
			break;
		case ADO_TYPE_TEXT:
			{
				CString* lpStr = (CString*)variable;
				VARIANT data;
				SAFEARRAY* pSafeArray;
				SAFEARRAYBOUND arrayBound;
				char *buf;

				data.vt = VT_ARRAY | VT_UI1;
				arrayBound.cElements = lpStr->GetLength();
				arrayBound.lLbound = 0;
				pSafeArray = ::SafeArrayCreate(VT_UI1, 1, &arrayBound);
				buf = lpStr->GetBuffer(0);
				for(unsigned long i = 0; i < arrayBound.cElements; i++)
					::SafeArrayPutElement(pSafeArray, (long*)&i, buf++);
				data.parray = pSafeArray;

				m_pRecordset->GetFields()->GetItem(_bstr_t(field))->AppendChunk(data);
			}
			break;
		case ADO_TYPE_DATE:
			{
				CString str;
				LPSYSTEMTIME lpSystemTime = (LPSYSTEMTIME)variable;

				str.Format("%d-%d-%d", 
					lpSystemTime->wYear, lpSystemTime->wMonth, lpSystemTime->wDay);
				m_pRecordset->PutCollect(_bstr_t(field), 
					_bstr_t(str));
			}
			break;
		case ADO_TYPE_INT:
			{
				CString str;
				str.Format("%d", *(int*)variable);
				m_pRecordset->PutCollect(_bstr_t(field), _bstr_t(str));
			}
			break;
		case ADO_TYPE_FLOAT:
			{
				CString str;
				str.Format("%.2f", *(float*)variable);
				m_pRecordset->PutCollect(_bstr_t(field), _bstr_t(str));
			}
			break;
		default:
			return FALSE;
		}
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}

	return TRUE;
}

BOOL CADOOperation::GetItemContent(CString field,
								   DWORD type, 
								   void *variable)
{
	ASSERT(!field.IsEmpty());
	_variant_t variant;
	try
	{
		if(type != ADO_TYPE_BITMAP_HANDLE && type != ADO_TYPE_TEXT)
		{
			variant = GetSubItem(field);
			ChangeTypeTo(variant, type, variable, 0);
			return TRUE;
		}
		if(type == ADO_TYPE_BITMAP_HANDLE || ADO_TYPE_TEXT == type)
		{
			long bits;

			bits = m_pRecordset->GetFields()->GetItem(_bstr_t(field))->ActualSize;
			if(bits <= 0)
				return TRUE;
			variant = m_pRecordset->GetFields()->GetItem(_bstr_t(field))->GetChunk(bits);
			ChangeTypeTo(variant, type, variable, bits);
		}
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}
	return TRUE;
}

BOOL CADOOperation::IsLastRow()
{

	if(m_pRecordset->adoEOF)
		return TRUE;

	return FALSE;
}

BOOL CADOOperation::MoveTo(DWORD index)
{
	try
	{
		m_pRecordset->Move(index);
		m_CurrentRecord = index;
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}
	return TRUE;
}

DWORD CADOOperation::GetRecordCount()
{
	DWORD count = 1;
	if(m_pRecordset->adoEOF)
		return 0;

	m_pRecordset->MoveFirst();
	do
	{
		count++;
		m_pRecordset->MoveNext();
	}while(!m_pRecordset->adoEOF);

	return count;
}

BOOL CADOOperation::ShowADOView(CString fields[], int len, CADOView *view)
{
	int i=0; 
	CString *str = new CString[len];

	view->DeleteAllRows();
	if(m_pRecordset->adoEOF)
			return TRUE;
	do
	{
		for(int j=0; j < len; j++)
			str[j] = (char *)_bstr_t(m_pRecordset->GetCollect(_bstr_t(fields[j])));
		view->SetRow(i, str, len);
		m_pRecordset->MoveNext();
		i++;
	}
	while(!m_pRecordset->adoEOF);

	delete []str;
	return TRUE;
}

BOOL CADOOperation::OpenRecordset(CString sql)
{
	ASSERT(!sql.IsEmpty());
	try
	{
		m_pRecordset->Open(_bstr_t(sql), m_pConnection.GetInterfacePtr(), 
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}

	return TRUE;
}

BOOL CADOOperation::GetItemContent(DWORD field, DWORD type, void *variable)
{
	ASSERT(type != ADO_TYPE_BITMAP_HANDLE);
	_variant_t variant;
	BOOL ret = TRUE;

	try{
		variant = m_pRecordset->GetCollect(_variant_t((long)field));
		ret = ChangeTypeTo(variant, type, variable, 0);
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}
	
	return ret;
}


_variant_t CADOOperation::GetSubItem(DWORD index)
{
	_variant_t var;
	try{

			var = m_pRecordset->GetCollect(_variant_t((long)index));
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return var;
	}

	return var;
}

_variant_t CADOOperation::GetSubItem(CString field)
{
	_variant_t var;
	try{

			var = m_pRecordset->GetCollect(_bstr_t(field));
	}
	catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return var;
	}

	return var;
}

BOOL CADOOperation::ChangeTypeTo(_variant_t from, DWORD type, void *pTo, long add)
{
	ASSERT(NULL != pTo);
	switch(type)
	{
	case ADO_TYPE_DATE:
		{
			if(from.vt == VT_NULL)
				return FALSE;

			LPSYSTEMTIME sysTime = (LPSYSTEMTIME)pTo;
			int n, l;
			CString str	= (char*)_bstr_t(from);
			CString d ,m,y;
			
			n = str.Find("-", 0);
			y = str.Left(n);
			l = str.Find("-", n + 1);
			d = str.Right(str.GetLength() - l - 1);
			m = str.Mid(n + 1, l-n-1);
			sysTime->wDay	= atoi(d.GetBuffer(0));
			sysTime->wMonth	= atoi(m.GetBuffer(0));
			sysTime->wYear	= atoi(y.GetBuffer(0));
		}
		break;
	case ADO_TYPE_FLOAT:
		if(from.vt == VT_NULL)
		{
			(*(double*)pTo) = 0;
			break;
		}
		(*(double*)pTo) = (double)from;
		break;
	case ADO_TYPE_BITMAP_HANDLE:
		{
			if(from.vt == VT_NULL)
				return FALSE;
			if(add > 0)
			{
				char *pBuffer;
				if((pBuffer = new char[add]) != NULL)
				{
					if(from.vt == (VT_ARRAY | VT_UI1))
					{
						char *pBuf;
						::SafeArrayAccessData(from.parray, (void**)&pBuf);
						::memcpy(pBuffer, pBuf, add);
						::SafeArrayUnaccessData(from.parray);
						
						char *pDib;
						LPVOID lpDibBits;
						BITMAPFILEHEADER &bmfHeader = *(BITMAPFILEHEADER*)pBuffer;
						DWORD bmfHeaderLen = sizeof(bmfHeader);
						if(bmfHeader.bfType != (*(DWORD*)"BM"))
							return TRUE;
						pDib = pBuffer + bmfHeaderLen;
						BITMAPINFOHEADER &bmiHeader = *(LPBITMAPINFOHEADER)pDib;
						BITMAPINFO &bmInfo = *(LPBITMAPINFO)pDib;
						lpDibBits = pBuffer + ((BITMAPFILEHEADER*)pBuffer)->bfOffBits;
						
						*(HBITMAP*)pTo = ::CreateDIBitmap(m_hDC, 
							&bmiHeader, CBM_INIT, lpDibBits, &bmInfo, DIB_RGB_COLORS);
					}
				}
			}
		}
		break;
	case ADO_TYPE_TEXT:
		{
			CString *pStr = (CString* )pTo;
			*pStr = (char*)_bstr_t(from);
		}
		break;
	case ADO_TYPE_INT:
		if(from.vt == VT_NULL)
		{
			(*(long*)pTo) = 0;
			break;
		}
		(*(long*)pTo) = (long)from;
		break ;
	case ADO_TYPE_STRING:
		*(CString* )pTo = 
			(char*)_bstr_t(from);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

void CADOOperation::CloseRecorset()
{
	try
	{
		if(adStateOpen == m_pRecordset->GetState())
			m_pRecordset->Close();
	}
	catch(_com_error e)
	{
		return ;
	}
}

BOOL CADOOperation::DeleteItem(DWORD index)
{
	ASSERT(index >= 0);
	try
	{
		m_pRecordset->Move(index);
		m_pRecordset->Delete(adAffectCurrent);
	}catch(_com_error e)
	{
#ifdef _DEBUG
		ShowError(e.Description());
#endif
		return FALSE;
	}

	return TRUE;
}

HRESULT CADOOperation::MoveFirst()
{
	return m_pRecordset->MoveFirst();
}

HRESULT CADOOperation::MoveNext()
{
	return m_pRecordset->MoveNext();
}


void CADOOperation::ShowError(_bstr_t error)
{
	::MessageBox(NULL, error, "ADO错误", MB_OK | MB_ICONWARNING);
}

BOOL CADOOperation::ExportToWord(CString& file)
{
	Fields* fields = NULL;
	long count = 0;			//表头元素个数

	m_pRecordset->get_Fields(&fields);
	count = fields->Count;	//得到表头元素个数
	/*
				以下代码为Word应用对象的初始化过程
	*/
	_Application	application;		//创建一个Word应用对象
	_Document		document;
	Documents		documents;
	Tables			tables;
	Range			range;
	_Document		saveDoc;
	Selection		selection;
	COleVariant		colevariant;

	CComVariant FileFormat(0);						//这是重点看下面的说明
	CComVariant LockComments(FALSE), Password(_T(""));
	CComVariant AddToRecentFiles(true),WritePassword("");
	CComVariant ReadOnlyRecommended(false), EmbedTrueTypeFonts(false);
	CComVariant SaveNativePictureFormat(false), SaveFormsData(false);
	CComVariant SaveAsAOCELetter(false);

	CComVariant FileName("");		//保存的位置
	
	CComVariant Template(_T("")), NewTemplate(false), DocumentType(0), Visible(true);
	
	application.CreateDispatch("Word.Application");
	documents.AttachDispatch(application.GetDocuments());
	document.AttachDispatch(documents.Add(&Template,	//无模板
		&NewTemplate,									//不是新建模板
		&DocumentType,									//无类型
		&Visible));										//初始不可见
	range.AttachDispatch(document.GetContent());
	tables.AttachDispatch(document.GetTables());
	tables.Add(range, GetRecordCount(),	//记录数
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
	
	if(!m_pRecordset->adoBOF)
		m_pRecordset->MoveFirst();
	else
		goto end;
	while(!m_pRecordset->adoEOF)
	{
		for(long num = 0; num < (m_pRecordset->GetFields())->GetCount(); num++)
		{
			strText.Format("%d", num);
			selection.TypeText((char *)(_bstr_t)m_pRecordset->GetCollect(varField[num]));	//把对应表头的相关信息输入到Word的表中
			selection.MoveRight((COleVariant)"1", (COleVariant)"1", (COleVariant)"0");	//移动光标
		}
		m_pRecordset->MoveNext();
	}
	
	//保存代码
	saveDoc = application.GetActiveDocument();	//得到ActiveDocument
	
	
	if(file.IsEmpty())
		FileName = "C:\\DataBaseTable.doc";
	else
		FileName = file;

	saveDoc.SaveAs(&FileName, &FileFormat, &LockComments, &Password, 
		&AddToRecentFiles, &WritePassword, &ReadOnlyRecommended, 
		&EmbedTrueTypeFonts, &SaveNativePictureFormat, &SaveFormsData,&SaveAsAOCELetter);
	
	
	//设置Word窗口可见并释放应用程序的资源
	application.SetVisible(TRUE);

end:
	tables.ReleaseDispatch();
	selection.ReleaseDispatch();
	documents.ReleaseDispatch();
	document.ReleaseDispatch();
	application.ReleaseDispatch();

	return TRUE;
	
}

void CADOOperation::SetClientDC(HDC hDC)
{
	m_hDC = hDC;
}
