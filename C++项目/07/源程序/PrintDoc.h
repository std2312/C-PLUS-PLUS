#if !defined(AFX_PRINTDOC_H__A76D34B1_1C8F_4641_9067_48063A7A3522__INCLUDED_)
#define AFX_PRINTDOC_H__A76D34B1_1C8F_4641_9067_48063A7A3522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc document

class CPrintDoc : public CDocument
{
protected:
	CPrintDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPrintDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	virtual void SetTitle(LPCTSTR lpszTitle);
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTDOC_H__A76D34B1_1C8F_4641_9067_48063A7A3522__INCLUDED_)
