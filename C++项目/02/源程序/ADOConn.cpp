// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NoteManage.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitADOConn()
{
	//��ʼ��OLE/COM�⻷��
    ::CoInitialize(NULL);
	try
	{
		//����connection����
		m_pConnection.CreateInstance("ADODB.Connection");	   
		//���������ַ���
		_bstr_t strConnect="uid=;pwd=;DRIVER={Microsoft Access Driver (*.mdb)};DBQ=shujuku.mdb;";
		//SERVER��UID,PWD�����ø���ʵ�����������
		m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	//��׽�쳣
	catch(_com_error e)
	{
		//��ʾ������Ϣ
		AfxMessageBox(e.Description());
	}

}

void ADOConn::ExitConnect()
{
	//�رռ�¼��������
    if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	//�ͷŻ���
	::CoUninitialize();

}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
    try
	{
		if(m_pConnection==NULL)
              OnInitADOConn();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
    catch(_com_error e)
	{
		e.Description();
	}
	return m_pRecordset;
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		//�Ƿ����������ݿ�
        if(m_pConnection==NULL)
	     	OnInitADOConn();
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}
