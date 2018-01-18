// DataManage.h: interface for the CDataManage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAMANAGE_H__11E0EBE6_D4C3_4B16_BB81_1D6B544556A7__INCLUDED_)
#define AFX_DATAMANAGE_H__11E0EBE6_D4C3_4B16_BB81_1D6B544556A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDataManage  
{
public:
	//初始化数据库
	BOOL InitDatabase();
	CDataManage();
	virtual ~CDataManage();
	_ConnectionPtr m_pConnect;
	_CommandPtr    m_pCommand;
	_RecordsetPtr  m_pRecord;
	static CString m_ConnectStr;
};

#endif // !defined(AFX_DATAMANAGE_H__11E0EBE6_D4C3_4B16_BB81_1D6B544556A7__INCLUDED_)
