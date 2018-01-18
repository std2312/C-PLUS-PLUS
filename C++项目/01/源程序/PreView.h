#if !defined(AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_)
#define AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreView window
//����Ԥ��״̬,ֹͣ,Ԥ��,�ָ�Ԥ��
enum PreState  {psStop,psPreview,psRestore};

class CPreView : public CStatic
{
// Construction
public:
	CPreView();

// Attributes
public:
	
// Operations
public:
	BOOL       m_Selected;  //��ǰ�Ƿ�ѡ��
	static int m_CurIndex;  //Ԥ�����ڵ�ǰ����
	int        m_Index;     //����������
	BOOL	   m_ShowImage; //�Ƿ���ʾͼ��,����·�Ƿ����ź�
	BOOL       m_Dbled;     //˫��ʱ�����Ƿ���丸����
	PreState   m_Stop;      //Ԥ��״̬
	CBitmap    m_Bitmap;    //���ź�����ʾ��λͼ��Դ
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreView)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPreView();
	afx_msg void OnPaint();
	// Generated message map functions
protected:
	//{{AFX_MSG(CPreView)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__805863AD_EB69_41E7_A176_358E22BA6FE3__INCLUDED_)
