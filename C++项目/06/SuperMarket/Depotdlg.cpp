// Depotdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "Depotdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepotdlg dialog


CDepotdlg::CDepotdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepotdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepotdlg)
	//}}AFX_DATA_INIT
}


void CDepotdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepotdlg)
	DDX_Control(pDX, IDC_EDIT4, m_Jhsl);
	DDX_Control(pDX, IDC_COMBO5, m_Spjj);
	DDX_Control(pDX, IDC_COMBO4, m_Spmc);
	DDX_Control(pDX, IDC_COMBO3, m_Spbh);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Jhsj);
	DDX_Control(pDX, IDC_COMBO2, m_Gysmc);
	DDX_Control(pDX, IDC_COMBO1, m_Gysbh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepotdlg, CDialog)
	//{{AFX_MSG_MAP(CDepotdlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepotdlg message handlers

BOOL CDepotdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString sql,ph;
	sql.Format("select * from CTXSYS.TB_PROVIDE");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Gysbh.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Gysmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	sql.Format("select * from CTXSYS.TB_SHANGPIN");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Spbh.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Spmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Spjj.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("JHJG"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	CTime time = CTime::GetCurrentTime();
	m_Jhsj.SetTime(&time);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDepotdlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Gysbh.GetCurSel();
	m_Gysmc.SetCurSel(sel);
}

void CDepotdlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Gysmc.GetCurSel();
	m_Gysbh.SetCurSel(sel);
}

void CDepotdlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	CString spbh,spmc,spjj,jhsl,jhsj,gysbh,gysmc;
	CTime time;
	m_Spbh.GetWindowText(spbh);
	m_Spmc.GetWindowText(spmc);
	m_Spjj.GetWindowText(spjj);
	m_Jhsl.GetWindowText(jhsl);
	m_Jhsj.GetTime(time);
	m_Gysbh.GetWindowText(gysbh);
	m_Gysmc.GetWindowText(gysmc);
	
	CString sql;
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	sql.Format("select * from CTXSYS.TB_DEPOT where SPBH='%s'");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		sql.Format("update CTXSYS.TB_DEPOT set SPSL=SPSL+%d,JHSJ=TO_DATE('%s',\
			'MMDDYYYY HH24:MI'),GYSBH='%s',GYSMC='%s' where SPBH='%s'",atoi(jhsl),
			time.Format("%m%d%Y %H:%M"),gysbh,gysmc,m_Spbh);
	}
	else
	{
		sql.Format("insert into CTXSYS.TB_DEPOT(SPBH,SPMC,SPJJ,SPSL,JHSJ,GYSBH,\
			GYSMC)values('%s','%s',%f,%d,TO_DATE('%s','MMDDYYYY HH24:MI'),'%s',\
			'%s')",spbh,spmc,atof(spjj),atoi(jhsl),time.Format("%m%d%Y %H:%M"),
			gysbh,gysmc);
	}
	if(m_AdoConn.ExecuteSQL((_bstr_t)sql))
		MessageBox("±£´æ³É¹¦");
	m_AdoConn.ExitConnect();
}

void CDepotdlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spbh.GetCurSel();
	m_Spmc.SetCurSel(sel);
	m_Spjj.SetCurSel(sel);
}

void CDepotdlg::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spmc.GetCurSel();
	m_Spbh.SetCurSel(sel);
	m_Spjj.SetCurSel(sel);
}


