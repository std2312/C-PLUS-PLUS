// Report.h: interface for the CReport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_)
#define AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int maxcount = 20; //�����ֶε��������

class CReport  
{
public:
	CReport();
	virtual ~CReport();
	LPCSTR title;//�������
	LPCTSTR framtilte;//��ӡ���ڱ���
	CString * fields; //�����ֶ���
	CListCtrl * m_plist; //��������
	int fieldcount;//�����ֶ���
	int lmargin,rmargin; //���ұ߾�
	int verinterval; //�������ݼ��
};

#endif // !defined(AFX_REPORT_H__8DAD8F86_988F_4948_A971_034D468B69D5__INCLUDED_)
