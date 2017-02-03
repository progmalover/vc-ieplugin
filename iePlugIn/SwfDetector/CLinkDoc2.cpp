// CLinkDoc2.cpp : Implementation of CCLinkDoc2

#include "stdafx.h"
#include "CLinkDoc2.h"

// CCLinkDoc2


HRESULT CCLinkDoc2::Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,
	DISPPARAMS* pDispParams, VARIANT* pvarResult,
    EXCEPINFO*  pExcepInfo,  UINT* puArgErr)
{
   if (!pDispParams)
      return E_INVALIDARG;
   
   if(dispidMember == (LONG) -606)
   {
	   ATLTRACE("dispidMember :-606");
	   ::MessageBox(NULL,_T("adf"),_T("sadfsdf"),IDOK);

   }
   return S_OK;
}

HRESULT CCLinkDoc2::ConnectToDoc2( IDispatch *pDoc2)
{
	
	CComPtr<IDispatch> pcDisp(pDoc2);
  /*  if(m_dwCookie != 0)
	{
		  CComPtr<IConnectionPoint>spCP;
		  m_spCPC->FindConnectionPoint(DIID_HTMLDocumentEvents2,&spCP);
		  spCP->Unadvise(m_dwCookie);
	}*/

	//ATLTRACE("m_dwCookie:%d \n",m_dwCookie);
	if(pcDisp != NULL)
	{
		m_spCPC  = pcDisp;

	   CComPtr<IConnectionPoint>spCP;
	   m_spCPC->FindConnectionPoint(DIID_HTMLDocumentEvents2,&spCP);
		  // Pass the event handlers to the container
		HRESULT hres = spCP->Advise(
			reinterpret_cast<IDispatch*>(this), 
			&m_dwCookie);

	 
		return S_OK;
	}

	return S_FALSE;
}
STDMETHODIMP CCLinkDoc2::ConnectDoc2(void * pDoc2)
{
	// TODO: Add your implementation code here

	return ConnectToDoc2( (IDispatch *)pDoc2);
}
