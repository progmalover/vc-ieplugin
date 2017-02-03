#if !defined(AFX_INTERNETEXPLORER_H__B2ADB93F_B700_4146_8387_801E2E89E1DA__INCLUDED_)
#define AFX_INTERNETEXPLORER_H__B2ADB93F_B700_4146_8387_801E2E89E1DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InternetExplorer.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CInternetExplorer command target

class CInternetExplorer : public CCmdTarget
{
	DECLARE_DYNCREATE(CInternetExplorer)

	CInternetExplorer();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetExplorer)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInternetExplorer();

	// Generated message map functions
	//{{AFX_MSG(CInternetExplorer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CInternetExplorer)

 
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	
	afx_msg long GetSWFFile(LPDISPATCH pDispatch);
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETEXPLORER_H__B2ADB93F_B700_4146_8387_801E2E89E1DA__INCLUDED_)
