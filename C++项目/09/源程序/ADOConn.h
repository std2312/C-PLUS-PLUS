// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__DE5F366E_0B7D_4AA9_85DC_89B767A4FB2F__INCLUDED_)
#define AFX_ADOCONN_H__DE5F366E_0B7D_4AA9_85DC_89B767A4FB2F__INCLUDED_

#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"no_namespace\
		 rename("EOF","adoEOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void ExitConn();
	void OnInitADOConn();
	ADOConn();
	virtual ~ADOConn();
	_ConnectionPtr m_pCon;
	_RecordsetPtr m_pRs;

};

#endif // !defined(AFX_ADOCONN_H__DE5F366E_0B7D_4AA9_85DC_89B767A4FB2F__INCLUDED_)
