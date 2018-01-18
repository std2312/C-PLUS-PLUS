// Logindlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "Logindlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog


CLogindlg::CLogindlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogindlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogindlg)
	m_Name = _T("");
	m_Pwd = _T("");
	//}}AFX_DATA_INIT
	m_Time = 0;
}


void CLogindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogindlg)
	DDX_Control(pDX, IDOK, m_Ok);
	DDX_Control(pDX, IDCANCEL, m_Canel);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogindlg, CDialog)
	//{{AFX_MSG_MAP(CLogindlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogindlg message handlers


void CLogindlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_Name.IsEmpty() || m_Pwd.IsEmpty()) //�ж������Ƿ�Ϊ��
	{
		MessageBox("�û��������벻��Ϊ��");
		return;
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_Time++; //�����¼����
	CString sql;
	sql.Format("select * from tb_employees where �û��� = '%s' and ���� = '%s'",
		m_Name,m_Pwd); //����SQL���
	m_AdoConn.m_pRecordset = m_AdoConn.m_pConnection->Execute((_bstr_t)sql,
		NULL,adCmdText); //ִ��SQL���
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		CDialog::OnOK(); //���������岢�رյ�¼��
	}
	else
	{
		if(m_Time == 3) //�жϴ����Ƿ񳬹�3��
		{
			MessageBox("����3�β���ȷ");
			CDialog::OnCancel(); //�رնԻ���
		}
		else
		{
			MessageBox("�û��������벻��ȷ");
			m_Name = "";
			m_Pwd = "";
			UpdateData(FALSE); //���¿ؼ���ʾ
		}
	}
	m_AdoConn.ExitConnect();
}
