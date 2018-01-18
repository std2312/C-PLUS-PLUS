// Report.h: interface for the CReport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_)
#define AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int maxcount = 20; //报表字段的最大数量

class CReport  
{
public:
	CReport();
	virtual ~CReport();
	LPCSTR title;//报表标题
	LPCTSTR framtilte;//打印窗口标题
	CString * fields; //报表字段数
	CListCtrl * m_plist; //报表数据
	int fieldcount;//报表字段数
	int lmargin,rmargin; //左右边距
	int verinterval; //报表数据间距
};

#endif // !defined(AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_)
