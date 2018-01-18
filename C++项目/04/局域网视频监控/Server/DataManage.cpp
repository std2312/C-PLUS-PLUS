// DataManage.cpp: implementation of the CDataManage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Server.h"
#include "DataManage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString CDataManage::m_ConnectStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=db_Video.mdb;Persist Security Info=False";

CDataManage::CDataManage()
{

}

CDataManage::~CDataManage()
{

}

BOOL CDataManage::InitDatabase()
{
	try
	{
		m_pConnect.CreateInstance("ADODB.Connection");
		m_pCommand.CreateInstance("ADODB.Command");
		m_pRecord.CreateInstance("ADODB.Recordset");
		m_pConnect->ConnectionString = m_ConnectStr.AllocSysString();
		m_pConnect->Open("","","",-1);
	}
	catch(_com_error &err)
	{
		MessageBox(NULL,"数据库初始化失败","提示",MB_ICONINFORMATION);
		return FALSE;
	}
	return TRUE;
}
