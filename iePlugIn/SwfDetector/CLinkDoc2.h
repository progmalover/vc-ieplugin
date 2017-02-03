// CLinkDoc2.h : Declaration of the CCLinkDoc2

#pragma once
#include "resource.h"       // main symbols

#include "SwfDetector_i.h"
#include "mshtml.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CCLinkDoc2

class  CCLinkDoc2 :
	/*public IDispatchImpl<CCLinkDoc2, &CLSID_CLinkDoc2>*/
	
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCLinkDoc2, &CLSID_CLinkDoc2>,
	public IDispatchImpl<ICLinkDoc2, &IID_ICLinkDoc2, &LIBID_SwfDetectorLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCLinkDoc2()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CLINKDOC2)


BEGIN_COM_MAP(CCLinkDoc2)
	COM_INTERFACE_ENTRY(ICLinkDoc2)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{

		m_dwCookie = 0;
		return S_OK;
	}

	void FinalRelease()
	{
	}
public:
	STDMETHOD(Invoke)(DISPID, REFIID, LCID, WORD, DISPPARAMS*, 
		              VARIANT*, EXCEPINFO*, UINT*);

public:
	HRESULT ConnectToDoc2( IDispatch *pDoc2);

protected:
	DWORD  m_dwCookie;
	CComQIPtr<IConnectionPointContainer, &IID_IConnectionPointContainer> m_spCPC;
public:
	STDMETHOD(ConnectDoc2)(void * pDoc2);
};

OBJECT_ENTRY_AUTO(__uuidof(CLinkDoc2), CCLinkDoc2)
