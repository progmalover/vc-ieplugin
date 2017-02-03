// CDetector.h : Declaration of the CCDetector

#pragma once
#include "resource.h"       // main symbols

#include "SwfDetector_i.h"
#include "CLinkDoc2.h"
#include "list"
#include "map"
#include "vector"
#include "CDlgDetector.h"
#include "mshtml.h"
#include "atlstr.h"
#include "atlsafe.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif
using namespace std;
typedef vector<CString>  DOC_VECT;
typedef struct SwfUrl{
 DOC_VECT  strDocs;
 DOC_VECT  strSwfs;
} SWF_URLS;
typedef  list<SWF_URLS>  ELEMENT_LIST;
typedef  map<HANDLE ,void *>  HANDLE_MAP;
// CCDetector
extern HWND FindBrowserObjWnd(HWND  hWnd);
class ATL_NO_VTABLE CCDetector :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCDetector, &CLSID_CDetector>,
	public IObjectWithSiteImpl<CCDetector>,
	public IDispatchImpl<ICDetector, &IID_ICDetector, &LIBID_SwfDetectorLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{


public:
	CCDetector()
	{
		m_hwndBrowserObj = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CDETECTOR)


BEGIN_COM_MAP(CCDetector)
	COM_INTERFACE_ENTRY(ICDetector)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{

		m_dwDocCookie = 0;
		m_bOpened =FALSE;
		_Dlg = new CCDlgDetector(this);
		return S_OK;
	}

	void FinalRelease()
	{
		if( _Dlg->IsWindow())
			_Dlg->DestroyWindow();
		delete _Dlg;
	}
 
	 
public:
	
	STDMETHOD(SetSite)(IUnknown *pUnkSite);
   
	STDMETHOD(Invoke)(DISPID, REFIID, LCID, WORD, DISPPARAMS*, 
		              VARIANT*, EXCEPINFO*, UINT*);

private:
	STDMETHOD(Connect)(void);
	STDMETHOD(Disconnect)(void);
	STDMETHOD(OnQuit)(void);
	
public:
	HRESULT  LinkToDoc2(IDispatch *pDoc);
protected:
	DWORD  m_dwDocCookie;
	CComQIPtr<IConnectionPointContainer, &IID_IConnectionPointContainer> m_spDocCPC;
public:
	HRESULT ConnectDoc2(IDispatch * pDisp);
	void   UnConnectDoc2(void);
	 
	void Reset(void)
	{
		_SwfList.clear();
		m_bOpened = FALSE;
	};
	bool EnableScan(){ return (_SwfList.size() > 0 || m_bOpened == FALSE);};
	bool NeedScan(){return (_SwfList.size() <= 0 && m_bOpened == FALSE);};
public:
	BOOL  SwfDetector(void); //detector the swf in docs

	ELEMENT_LIST  _SwfList;
	BOOL  m_bOpened;
	void SwfScan(void);
	HRESULT DoSwfScan(CComQIPtr<IHTMLDocument2,&IID_IHTMLDocument2> );
	BOOL GetMainDoc2URL(CString &url);

public:
	CComQIPtr<IWebBrowser2, &IID_IWebBrowser2> m_spWebBrowser2;
    CComQIPtr<IConnectionPointContainer, &IID_IConnectionPointContainer> m_spCPC;
	CComPtr<IHTMLElement> m_pBody;
	BOOL m_bDocumentCompleted;
	DWORD m_dwCookie;
//	DWORD m_dwDocCookie;
	HWND m_hwndBrowser;
	HWND m_hwndBrowserObj ;
	 
	CCDlgDetector  *_Dlg;
	
private:
	UINT_PTR  m_uTimer;
	
public:
	void StartTimer(void);
	void EndTimer(void);
	bool IsSwfElement2(IHTMLElement *p);
};

OBJECT_ENTRY_AUTO(__uuidof(CDetector), CCDetector)
