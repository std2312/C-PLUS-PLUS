// mystudentsysDlg.h : header file
//

#if !defined(AFX_MYSTUDENTSYSDLG_H__D7A3F2F7_898D_4B0A_B462_DF0578D65699__INCLUDED_)
#define AFX_MYSTUDENTSYSDLG_H__D7A3F2F7_898D_4B0A_B462_DF0578D65699__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMystudentsysDlg dialog
//定义按钮状态
enum ButtonState  {bsNormal,bsHot,bsDown};
//按钮包装类
class CDrawButton  
{
public:
	ButtonState m_State;           //按钮当前状态
	WNDPROC     m_OldProc;         //记录按钮的窗口函数
	int         m_Flag;            //是否释放关联按钮的CDrawButton对象
	static int  m_Style;           //按钮风格
public:

	CDrawButton( )
	{
		m_State   = bsNormal;
		m_OldProc = NULL;
		m_Flag    = 0;
	}

	virtual ~CDrawButton()
	{
		m_State   = bsNormal;
		m_OldProc = NULL;		
	};

	LRESULT OnPaint( HWND hWnd ) 
	{
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		
		CPaintDC	dc(pWnd);
		CString		Text;
		CRect		RC;
		CFont		Font;
		CFont		*pOldFont;
		CBrush		Brush;
		CBrush		*pOldBrush;
		CPoint		PT(2,2);
		
		dc.SetBkMode( TRANSPARENT );
		Font.CreateFont( 12, 0, 0, 0, FW_HEAVY, 0, 0, 0, ANSI_CHARSET, \
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, \
			VARIABLE_PITCH | FF_SWISS, "MS Sans Serif" );

		pOldFont = dc.SelectObject( &Font );
		
		if( m_State == bsNormal)
		{
			
			if (m_Style==2)
			{
				CBitmap bmp;
				bmp.LoadBitmap(IDB_BKBUTTON);
				Brush.CreatePatternBrush(&bmp); 
			}
			else
				Brush.CreateSolidBrush( RGB( 200,200,200 ) );
			dc.SetTextColor( RGB( 80, 80, 80) );
		}
		else if( m_State == bsDown )
		{
			Brush.CreateSolidBrush( RGB( 160, 160, 160 ) );
			dc.SetTextColor( RGB( 50, 50, 250 ) );
		}
		else if( m_State == bsHot )
		{
			Brush.CreateSolidBrush( RGB( 100, 100, 180 ) );
			dc.SetTextColor( RGB( 250, 250, 0 ) );
		}
		
		pOldBrush = dc.SelectObject( &Brush );
		pWnd->GetClientRect( &RC );
		dc.RoundRect( &RC, PT );
		
		HRGN hRgn = CreateRectRgn( RC.left, RC.top, RC.right, RC.bottom );
		pWnd->SetWindowRgn( hRgn, TRUE );
		DeleteObject( hRgn );
		
		pWnd->GetWindowText(Text );
		dc.DrawText( Text, &RC, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		
		dc.SelectObject( pOldFont );
		dc.SelectObject( pOldBrush );
		
		return TRUE;
	}
	LRESULT OnLButtonDown( HWND hWnd, UINT nFlags, CPoint point )
	{
		m_State = bsDown;		
		SetCapture(hWnd);
		SetFocus(hWnd);
		return TRUE;
	}
	
	LRESULT OnLButtonUp( HWND hWnd, UINT nFlags, CPoint point )
	{
		if( m_State != bsNormal )
		{
			m_State = bsNormal;
			ReleaseCapture();
			InvalidateRect(hWnd,NULL,TRUE);
			SendMessage( GetParent(hWnd), WM_COMMAND, GetDlgCtrlID(hWnd), (LPARAM) (hWnd) );
		}
		return TRUE;
	}

	LRESULT LoseFocus(HWND  hWnd)
	{
		m_State = bsNormal;
		InvalidateRect(hWnd,NULL,TRUE);
		SendMessage( hWnd, WM_KILLFOCUS, (long)hWnd, 0);	
		return TRUE;
	}

	LRESULT OnMouseMove(HWND hWnd, UINT nFlags, CPoint point ) {
		HRGN hRgn = CreateRectRgn( 0, 0, 0, 0 );
		GetWindowRgn( hWnd,hRgn );
		BOOL ret = PtInRegion( hRgn, point.x, point.y );
		if( ret ) 
		{
			
			if( m_State == bsDown) 
				return TRUE;
			if( m_State != bsHot ) 
			{
				m_State = bsHot;
				InvalidateRect(hWnd,NULL,TRUE);
				UpdateWindow(hWnd);
				SetCapture(hWnd);
			}
		} 
		else 
		{
			m_State = bsNormal;
			InvalidateRect(hWnd,NULL,TRUE);	
			ReleaseCapture();
		}	
		DeleteObject( hRgn );
		return TRUE;
	}
};
class CMystudentsysDlg : public CDialog
{
// Construction
public:
	virtual void OnCancel();
	CMystudentsysDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMystudentsysDlg)
	enum { IDD = IDD_MYSTUDENTSYS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMystudentsysDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMystudentsysDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENUinputmarks();
	afx_msg void OnMENUstudentinfo();
	afx_msg void OnMENUregbreakinfo();
	afx_msg void OnMENUmarkreport();
	afx_msg void OnMENUfindbreakinfo();
	afx_msg void OnAbout();
	afx_msg void OnMENUgradeleveldlg();
	afx_msg void OnMENUhelp();
	afx_msg void OnMENUuser();
	afx_msg void OnMENUexit();
	afx_msg void OnMENUinfostudent();
	afx_msg void OnMENUclassinfo();
	afx_msg void OnMENUclasssubject();
	afx_msg void OnMENUexamkind();
	afx_msg void OnMENUofficeinfo();
	afx_msg void OnMENUsubjectinfo();
	afx_msg void OnMENUteacherinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTUDENTSYSDLG_H__D7A3F2F7_898D_4B0A_B462_DF0578D65699__INCLUDED_)
