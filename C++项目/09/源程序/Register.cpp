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
		AfxMessageBox("请输入用户名");
		return;
	}
	if(m_Passwd.IsEmpty())
	{
		AfxMessageBox("请输入密码");
		return;
	}
	if(m_Passwd!=m_PasswdRepeat)
	{
		AfxMessageBox("两次输入密码不一致，请重新输入");
		return;
	}
	if(m_QuestionCombo.GetCurSel()==-1||m_QuestionCombo.GetCurSel()==0)
	{
		AfxMessageBox("请选择密码提示问题");
		return;
	}
	if(m_Answer.IsEmpty())
	{
		AfxMessageBox("请输入提示问题的答案");
		return;
	}
	if(m_RealName.IsEmpty())
	{
		AfxMessageBox("请输入真实姓名");
		return;
	}
	if(m_IDcard.GetLength() != 18)
	{
		AfxMessageBox("输入身份证号码无效");
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
			AfxMessageBox("输入身份证号码无效");
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
				AfxMessageBox("输入身份证号码无效");
				return;
			}
			switch(month)
			{
			case 1:	case 3: case 5: case 7: case 8: case 10: case 12:
				if(day<0 || day>31)
				{
					AfxMessageBox("输入身份证号码无效");
					return;
				}
				break;
			case 4:	case 6: case 9: case 11:
				if(day<0 || day>30)
				{
					AfxMessageBox("输入身份证号码无效");
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
						AfxMessageBox("输入身份证号码无效");
						return;
					}
					else
						if(day<0 || day>28)
						{
							AfxMessageBox("输入身份证号码无效");
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
		sex.Format("男");
	if(radio==2)
		sex.Format("女");
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
			AfxMessageBox("用户名已存在");
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
				%d,'%s',%d,%d,'学生','%s','%s')",m_UserName,m_Passwd,str,m_Answer,m_RealName,m_Age,\
				sex,m_Phone,id,m_IDcard,nowtime);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConn();
			AfxMessageBox("注册成功");
			CDialog::OnCancel();
			CLOGIN dlg;
			dlg.DoModal();
		}		
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
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
			m_TiShiStatic.SetWindowText("用户名可以使用");
		else
			m_TiShiStatic.SetWindowText("用户名已存在");
	}
	catch(...)
	{
		AfxMessageBox("操作失败");
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
	m_QuestionCombo.AddString("请选择一个问题");
	m_QuestionCombo.AddString("你的父亲生日是哪天？");
	m_QuestionCombo.AddString("你的母亲生日是哪天？");
	m_QuestionCombo.AddString("你的女朋友的生日是哪天？");
	m_QuestionCombo.AddString("你家养的猫叫什么？");
	m_QuestionCombo.AddString("你的车牌号的后三位是什么？");
	m_QuestionCombo.SetCurSel(0);
	return TRUE;  
}
