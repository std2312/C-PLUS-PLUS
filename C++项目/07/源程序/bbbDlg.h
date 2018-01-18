// bbbDlg.h : header file
//

#if !defined(AFX_BBBDLG_H__196B6212_A7A5_4CCC_92EA_C9F39A7D892F__INCLUDED_)
#define AFX_BBBDLG_H__196B6212_A7A5_4CCC_92EA_C9F39A7D892F__INCLUDED_

#include "MyCoolMenu.h"
//#include "DlgStoreInfoM.h"
//#include "DlgQueryM.h"
#include "DlgConfigM.h"
#include "DlgLogin.h"
#include "DlgOperator1.h"
#include "DlgBookKinds1.h"
#include "DlgBookInput2.h"
#include "DlgBookPrice2.h"
#include "DlgBookAdjustPrice2.h"
#include "DlgInputBack2.h"
#include "DlgBookAdjust2.h"
#include "DlgBookSale2.h"
#include "DlgSaleBack2.h"
//#include "DlgBaseInfoM.h"
#include "DlgProviderInfo1.h"
#include "DlgBookInfo1.h"
#include "DlgStoreInfo1.h"
#include "DlgDeskInfo1.h"
#include "DlgInputQuery3.h"
#include "DlgInputBackQuery3.h"
#include "DlgSaleQuery3.h"
#include "DlgSaleBackQuery3.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBbbDlg dialog

class CBbbDlg : public CDialog
{
public:
	int x;
	int y;
	CToolBar m_toolbar;
	CImageList m_imagelist;
	BOOL bFlag;
	CDlgOperator1  *pdlgoperator1;
	CDlgBookKinds1 *pdlgbookkinds1;
	CDlgProviderInfo1 *pdlgproviderinfo1;
	CDlgBookInfo1      *pdlgbookinfo1;
	CDlgStoreInfo1     *pdlgstoreinfo1;
	CDlgDeskInfo1     *pdlgdeskinfo1;

	CDlgBookInput2        *pbookinput2;
	CDlgBookPrice2        *pbookprice2;
	CDlgBookAdjustPrice2  *pbookadjustprice2;
	CDlgBookAdjust2     *pbookadjust2;
	CDlgInputBack2     *pinputback2;
	CDlgBookSale2      *pbooksale2;
	CDlgSaleBack2      *psaleback2;

	CDlgInputQuery3		*pinputquery3;
	CDlgInputBackQuery3  *pinputbackquery3;
	CDlgSaleQuery3        *psalequery;
	CDlgSaleBackQuery3    *psalebackquery;

//	CDlgBaseInfoM  *pdlgBaseInfoM;
//	CDlgStoreInfoM *pdlgStoreInfoM;
//	CDlgQueryM     *pdlgQueryM;
	CToolBarCtrl m_tbctrl;
	CReBar		m_wndReBar;//RebarÌõ
// Construction
public:
	void OnCancel();
	void OnOK();
	void AdoInit();
	CMyCoolMenu m_mnu;
	CBbbDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBbbDlg)
	enum { IDD = IDD_BBB_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBbbDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBbbDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNew();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnButton5();
	afx_msg void OnOperatorM();
	afx_msg void OnButton4();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAboutbox();
	afx_msg void OnBookInfo();
	afx_msg void OnProviderInfo();
	afx_msg void OnBookType();
	afx_msg void OnCkInfo();
	afx_msg void OnDeskInfo();
	afx_msg void OnBookInput();
	afx_msg void OnBookPrice();
	afx_msg void OnBookPriceAdjust();
	afx_msg void OnInputBack();
	afx_msg void OnBookAdjust();
	afx_msg void OnSaleM();
	afx_msg void OnSaleBack();
	afx_msg void OnInputQuery();
	afx_msg void OnInputBackQuery();
	afx_msg void OnSaleQuery();
	afx_msg void OnSaleBackQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBBDLG_H__196B6212_A7A5_4CCC_92EA_C9F39A7D892F__INCLUDED_)
