// DepotBackdlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperMarket.h"
#include "DepotBackdlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepotBackdlg dialog


CDepotBackdlg::CDepotBackdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepotBackdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepotBackdlg)
	//}}AFX_DATA_INIT
}


void CDepotBackdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepotBackdlg)
	DDX_Control(pDX, IDC_EDIT4, m_Thsl);
	DDX_Control(pDX, IDC_COMBO5, m_Spjj);
	DDX_Control(pDX, IDC_COMBO4, m_Spmc);
	DDX_Control(pDX, IDC_COMBO3, m_Spbh);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Thsj);
	DDX_Control(pDX, IDC_COMBO2, m_Gysmc);
	DDX_Control(pDX, IDC_COMBO1, m_Gysbh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepotBackdlg, CDialog)
	//{{AFX_MSG_MAP(CDepotBackdlg)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepotBackdlg message handlers

BOOL CDepotBackdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString sql,ph;
	sql.Format("select distinct GYSBH,GYSMC from CTXSYS.TB_DEPOT");
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Gysbh.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSBH"));
		m_Gysmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("GYSMC"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	sql.Format("select * from CTXSYS.TB_DEPOT");
	m_AdoConn.m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_AdoConn.m_pRecordset->adoEOF)
	{
		m_Spbh.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPBH"));
		m_Spmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPMC"));
		m_Spjj.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("SPJJ"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	CTime time = CTime::GetCurrentTime();
	m_Thsj.SetTime(&time);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDepotBackdlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString spbh,spmc,spjj,thsl,gysbh,gysmc;
	CTime time;
	m_Spbh.GetWindowText(spbh);
	m_Spmc.GetWindowText(spmc);
	m_Spjj.GetWindowText(spjj);
	m_Thsl.GetWindowText(thsl);
	m_Thsj.GetTime(time);
	m_Gysbh.GetWindowText(gysbh);
	m_Gysmc.GetWindowText(gysmc);
	
	CString sql;
	sql.Format("insert into CTXSYS.TB_BDEPOTQ(SPBH,SPMC,SPJJ,THSL,THSJ,GYSBH,\
		GYSMC)values('%s','%s',%f,%d,TO_DATE('%s','MMDDYYYY HH24:MI'),'%s','%s')",
		spbh,spmc,atof(spjj),atoi(thsl),time.Format("%m%d%Y %H:%M"),gysbh,gysmc);
		
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	if(m_AdoConn.ExecuteSQL((_bstr_t)sql))
		MessageBox("±£´æ³É¹¦");
	sql.Format("update CTXSYS.TB_DEPOT set SPSL=SPSL-%d where SPBH='%s'",
			atoi(thsl),spbh);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CDepotBackdlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Gysbh.GetCurSel();
	m_Gysmc.SetCurSel(sel);
}

void CDepotBackdlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Gysmc.GetCurSel();
	m_Gysbh.SetCurSel(sel);
}

void CDepotBackdlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spbh.GetCurSel();
	m_Spmc.SetCurSel(sel);
	m_Spjj.SetCurSel(sel);
}

void CDepotBackdlg::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	int sel = m_Spmc.GetCurSel();
	m_Spbh.SetCurSel(sel);
	m_Spjj.SetCurSel(sel);
}

