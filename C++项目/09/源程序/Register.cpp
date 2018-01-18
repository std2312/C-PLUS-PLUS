// Register.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "Register.h"
#include "LOGIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog


CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegister)
	m_Age = 0;
	m_Answer = _T("");
	m_Passwd = _T("");
	m_PasswdRepeat = _T("");
	m_Phone = 0;
	m_RealName = _T("");
	m_UserName = _T("");
	m_IDcard = _T("");
	//}}AFX_DATA_INIT
}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegister)
	DDX_Control(pDX, IDC_TISHI, m_TiShiStatic);
	DDX_Control(pDX, IDC_QUESTION, m_QuestionCombo);
	DDX_Text(pDX, IDC_AGE, m_Age);
	DDX_Text(pDX, IDC_ANSWER, m_Answer);
	DDX_Text(pDX, IDC_PASSWD, m_Passwd);
	DDX_Text(pDX, IDC_PASSWDREPEAT, m_PasswdRepeat);
	DDX_Text(pDX, IDC_PHONE, m_Phone);
	DDX_Text(pDX, IDC_REALNAME, m_RealName);
	DDX_Text(pDX, IDC_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_IDCARD, m_IDcard);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	//{{AFX_MSG_MAP(CRegister)
	ON_BN_CLICKED(IDC_REG, OnReg)
	ON_BN_CLICKED(IDC_SEXMALE, OnSexmale)
	ON_BN_CLICKED(IDC_SEXFEMALE, OnSexfemale)
	ON_BN_CLICKED(IDC_CHECKNAME, OnCheckname)
	ON_EN_CHANGE(IDC_USERNAME, OnChangeUsername)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

void CRegister::OnReg() 
{
	UpdateData();
	if(m_UserName.IsEmpty())
	{
		AfxMessageBox("�������û���");
		return;
	}
	if(m_Passwd.IsEmpty())
	{
		AfxMessageBox("����������");
		return;
	}
	if(m_Passwd!=m_PasswdRepeat)
	{
		AfxMessageBox("�����������벻һ�£�����������");
		return;
	}
	if(m_QuestionCombo.GetCurSel()==-1||m_QuestionCombo.GetCurSel()==0)
	{
		AfxMessageBox("��ѡ��������ʾ����");
		return;
	}
	if(m_Answer.IsEmpty())
	{
		AfxMessageBox("��������ʾ����Ĵ�");
		return;
	}
	if(m_RealName.IsEmpty())
	{
		AfxMessageBox("��������ʵ����");
		return;
	}
	if(m_IDcard.GetLength() != 18)
	{
		AfxMessageBox("�������֤������Ч");
		return;
	}
	else
	{
		int num=0;
		char ch;
		for(int i=0;i<17;i++)
		{
			ch = m_IDcard.GetAt(i);
			if(ch>47 && ch<58)
				num++;
		}
		if(i==17)
		{
			ch = m_IDcard.GetAt(i);
			if((ch>47 && ch<58) || (ch==88 || ch==120))
				num++;
		}	
		if(num != 18)
		{
			AfxMessageBox("�������֤������Ч");
			return;
		}
		else
		{
			CString syear = m_IDcard.Mid(6,4);
			int year = atoi(syear);
			CString smonth = m_IDcard.Mid(10,2);
			int month = atoi(smonth);
			CString sday = m_IDcard.Mid(12,2);
			int day = atoi(sday);
			BOOL leap;
			if(month<1||month>12)				
			{
				AfxMessageBox("�������֤������Ч");
				return;
			}
			switch(month)
			{
			case 1:	case 3: case 5: case 7: case 8: case 10: case 12:
				if(day<0 || day>31)
				{
					AfxMessageBox("�������֤������Ч");
					return;
				}
				break;
			case 4:	case 6: case 9: case 11:
				if(day<0 || day>30)
				{
					AfxMessageBox("�������֤������Ч");
					return;
				}
				break;
			case 2:
				if(year % 4 == 0)
				{
					if(year % 100 != 0)
						leap = TRUE;
					else if(year % 400 == 0)
						leap = TRUE;
					else
						leap = FALSE;
				}
				else
					leap = FALSE;
				
				if(leap)
					if(day<0 || day>29)
					{
						AfxMessageBox("�������֤������Ч");
						return;
					}
					else
						if(day<0 || day>28)
						{
							AfxMessageBox("�������֤������Ч");
							return;
						}
						break;
			}
		}
	}
	CString str;
	m_QuestionCombo.GetLBText(m_QuestionCombo.GetCurSel(),str);
	CString sex;
	if(radio==0)
		sex.Format("");
	if(radio==1)
		sex.Format("��");
	if(radio==2)
		sex.Format("Ů");
	CTime time;
	time=CTime::GetCurrentTime();
	CString nowtime=time.Format("%Y-%m-%d");
	int id;

	try
	{
		m_AdoConn.OnInitADOConn();
		CString sql="select*from register where username='"+m_UserName+"'";		
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(!m_pRs->adoEOF)
		{
			AfxMessageBox("�û����Ѵ���");
			return;
		}
		else
		{
			sql.Format("select studentid from register");
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(m_pRs->adoEOF)
				id=1001;
			else
			{
				m_pRs->MoveLast();	
				id=atoi((_bstr_t)m_pRs->GetCollect("studentid"));
				id+=1;		
			}
			sql.Format("insert into register(username,[password],question,answer,name,\
				age,sex,phone,studentid,power,idcard,login_date)values('%s','%s','%s','%s','%s',\
				%d,'%s',%d,%d,'ѧ��','%s','%s')",m_UserName,m_Passwd,str,m_Answer,m_RealName,m_Age,\
				sex,m_Phone,id,m_IDcard,nowtime);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConn();
			AfxMessageBox("ע��ɹ�");
			CDialog::OnCancel();
			CLOGIN dlg;
			dlg.DoModal();
		}		
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}	
}

void CRegister::OnSexmale() 
{
	radio=1;	
}

void CRegister::OnSexfemale() 
{
	radio=2;	
}





void CRegister::OnCheckname() 
{
	UpdateData();
	_bstr_t sql="select*from register where username='"+m_UserName+"'";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet(sql);
		if(m_pRs->adoEOF)
			m_TiShiStatic.SetWindowText("�û�������ʹ��");
		else
			m_TiShiStatic.SetWindowText("�û����Ѵ���");
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}
	m_AdoConn.ExitConn();	
}

void CRegister::OnChangeUsername() 
{
	m_TiShiStatic.SetWindowText("");	
}

void CRegister::OnReset() 
{
	m_UserName="";
	m_Passwd="";
	m_PasswdRepeat="";
	m_QuestionCombo.SetCurSel(0);
	m_Answer="";
	m_RealName="";
	m_Phone=0;
	m_Age=0;
	radio=0;
	UpdateData(FALSE);
}

BOOL CRegister::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_QuestionCombo.AddString("��ѡ��һ������");
	m_QuestionCombo.AddString("��ĸ������������죿");
	m_QuestionCombo.AddString("���ĸ�����������죿");
	m_QuestionCombo.AddString("���Ů���ѵ����������죿");
	m_QuestionCombo.AddString("�������è��ʲô��");
	m_QuestionCombo.AddString("��ĳ��ƺŵĺ���λ��ʲô��");
	m_QuestionCombo.SetCurSel(0);
	return TRUE;  
}
