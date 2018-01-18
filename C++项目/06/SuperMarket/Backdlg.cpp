// Backdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Backdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString m_UserName;
/////////////////////////////////////////////////////////////////////////////
// CBackdlg dialog


CBackdlg::CBackdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBackdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBackdlg)
	m_Thph = _T("");
	m_Czy = _T("");
	//}}AFX_DATA_INIT
}


void CBackdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBackdlg)
	DDX_Control(pDX, IDC_COMBO4, m_Xsje);
	DDX_Control(pDX, IDC_COMBO3, m_Spmc);
	DDX_Control(pDX, IDC_COMBO2, m_Spbh);
	DDX_Control(pDX, IDC_COMBO1, m_Xsph);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Thrq);
	DDX_Text(pDX, IDC_EDIT1, m_Thph);
	DDX_Text(pDX, IDC_EDIT6, m_Czy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBackdlg, CDialog)
	//{{AFX_MSG_MAP(CBackdlg)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackdlg message handlers

void CBackdlg::OnButadd() 
{
	// TODO: Add your control notification handler code here
	CTime time = CTime::GetCurrentTime();
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_BACK where TO_DATE(THRQ)=\
		TO_DATE('%s','MMDDYYYY')",time.Format("%m%d%Y"));
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		while(!m_AdoConn.m_pRecordset->adoEOF)
		{
			ph = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("THPH");
			m_AdoConn.m_pRecordset->MoveNext();
		}
		m_Thph.Format("TH%s%04d",time.Format("%y%m%d"),atoi(ph.Right(4))+1);
	}
	else
		m_Thph.Format("TH%s0001",time.Format("%y%m%d"));
	m_AdoConn.ExitConnect();
	UpdateData(FALSE);
}

BOOL CBackdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString sql,ph;
	sql.Format("select distinct XSPH from CTXSYS.TB_SELL");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Xsph.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSPH"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	CTime time = CTime::GetCurrentTime();
	m_Thrq.SetTime(&time);
	m_Czy = m_UserName;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBackdlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString xsph,spbh,spmc,xsje;
	m_Xsph.GetLBText(m_Xsph.GetCurSel(),xsph);
	m_Spbh.GetLBText(m_Spbh.GetCurSel(),spbh);
	m_Spmc.GetLBText(m_Spmc.GetCurSel(),spmc);
	m_Xsje.GetLBText(m_Xsje.GetCurSel(),xsje);
	CTime time;
	m_Thrq.GetTime(time);
	CString sql;
	sql.Format("insert into CTXSYS.TB_BACK(THPH,XSPH,SPBH,SPMC,XSJE,CZY,THRQ)values(\
		'%s','%s','%s','%s',%f,'%s',TO_DATE('%s','MMDDYYYY'))",m_Thph,xsph,spbh,spmc,
		atof(xsje),m_UserName,time.Format("%m%d%Y"));
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	sql.Format("select * from CTXSYS.TB_SELL where XSPH='%s' and SPBH='%s'",xsph,spbh);
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		int str;
		str = atoi((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSSL"));
		sql.Format("update CTXSYS.TB_DEPOT set SPSL=SPSL+%d where SPBH='%s'",str,spbh);	
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql.Format("delete from CTXSYS.TB_SELL where XSPH='%s' and SPBH='%s'",xsph,spbh);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	m_AdoConn.ExitConnect();
	CDialog::OnCancel();
}

void CBackdlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	m_Spbh.ResetContent();
	m_Spmc.ResetContent();
	m_Xsje.ResetContent();
	CString xsph;
	m_Xsph.GetLBText(m_Xsph.GetCurSel(),xsph);
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_SELL where XSPH='%s'",xsph);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Spbh.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Spmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		CString xssl,spdj,xsje;
		xssl = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("XSSL");
		spdj = (char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPDJ");
		xsje.Format("%f",atoi(xssl)*atof(spdj));
		m_Xsje.AddString(xsje);
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

void CBackdlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spbh.GetCurSel();
	m_Spmc.SetCurSel(sel);
	m_Xsje.SetCurSel(sel);
}

void CBackdlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spmc.GetCurSel();
	m_Spbh.SetCurSel(sel);
	m_Xsje.SetCurSel(sel);
}

