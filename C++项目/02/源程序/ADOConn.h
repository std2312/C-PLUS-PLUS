// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)
#define AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_
#import "C:\Program Files\Common Files\System\ado\msado15.dll"no_namespace \
rename("EOF","adoEOF")rename("BOF","adoBOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	
	ADOConn();
	virtual ~ADOConn();

	//添加一个指向Connection对象的指针
	_ConnectionPtr m_pConnection;
	//添加一个指向Recordset对象的指针
	_RecordsetPtr m_pRecordset;
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void ExitConnect();
	void OnInitADOConn();
};

#endif // !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)
