// CDlgDetector.cpp : Implementation of CCDlgDetector

#include "stdafx.h"
#include "CDlgDetector.h"
#include "CDetector.h"
#include "atltypes.h"

static CString   _PreCatchURL;
bool IsFirstPopWindow(HWND hParent,HWND hPopChild)
{
	HWND hChild  =  ::GetWindow(hParent,GW_ENABLEDPOPUP|GW_CHILD );
	
	TCHAR  tTxt[_MAX_PATH];
	while(hChild)
	{
		::GetClassName(hChild,tTxt,_MAX_PATH);
		hChild =   ::GetWindow(hChild,GW_HWNDNEXT );
	}

	return true;
}

LRESULT CCDlgDetector::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	CCDetector *p = (CCDetector *)_pIDisp;
	ATLTRACE("timer is run !!\n"); 
    DWORD  dwStyle;
	
	if(!m_bShow) return S_OK;

	if(NULL == p->m_hwndBrowserObj)
		p->m_hwndBrowserObj = FindBrowserObjWnd(p->m_hwndBrowser);
	//if(::GetParent(m_hWnd)!= p->m_hwndBrowserObj)
		//::SetParent(m_hWnd,p->m_hwndBrowserObj);
	
	if(p->NeedScan())
			p->SwfDetector();//http://www.163.com/
	if(p->_SwfList.empty())
	{
		ATLTRACE("_SwfList empty ,so return !! \n");
		return S_OK;
	}
 
	POINT  point;
	RECT   cliRect;
	::GetCursorPos(&point);

	::GetWindowRect(p->m_hwndBrowserObj,&cliRect);

	if( ::PtInRect(&cliRect,point))
	{

		ATLTRACE("in client !! \n");
		POINT pt = point;
		::ScreenToClient(p->m_hwndBrowserObj,&pt);

		CRect wndRect;
		GetWindowRect(&wndRect);

		dwStyle = this->GetStyle();
		 
		if(dwStyle & WS_VISIBLE) // if show dont move...
		{
			   return 0;
		}

		CComPtr<IDispatch> pIDisp;
		CComQIPtr<IHTMLDocument2> pIDoc2;
		p->m_spWebBrowser2->get_Document(&pIDisp);
		pIDoc2 = pIDisp;

		CComPtr<IHTMLElement> pElement ;
		pIDoc2->elementFromPoint(pt.x,pt.y,&pElement);

		if(p->IsSwfElement2(pElement))
		{
			if(_PreCatchURL == this->m_UrlSwf)
			{

				if(this->GetStyle() & WS_MINIMIZE) // minimized mode to show again....
					goto _T;
				 
				//if(IsFirstPopWindow( p->m_hwndBrowserObj,this->m_hWnd))
					//goto _T;

				if(!(this->GetStyle() & WS_VISIBLE))
					goto _T;

				return  0;
			}

_T:
			MoveWindow(point.x,point.y,wndRect.Width(),wndRect.Height());
			ShowWindow(SW_NORMAL);
			p->EndTimer();
			_PreCatchURL = this->m_UrlSwf;
			ATLTRACE("window is showed !! \n");
		}else
		{
            ATLTRACE("window is hidden !! \n");
			ShowWindow(SW_HIDE);
		}
	}


	return S_OK;
}

LRESULT CCDlgDetector::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
}
 

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}


MIDL_DEFINE_GUID(IID, LIBID_SWFDecompiler,0xA71667E0,0x5792,0x4A49,0xA8,0x5E,0x25,0x9C,0x22,0x97,0x8E,0x6F);
MIDL_DEFINE_GUID(IID, DIID_IInternetExplorer,0x4FBE2BCC,0xAF98,0x4580,0xA8,0x9E,0xF3,0x4E,0xCA,0xF9,0x14,0xCE);
MIDL_DEFINE_GUID(CLSID, CLSID_InternetExplorer1,0xE19ADC6E,0x3909,0x43E4,0x9A,0x89,0xB7,0xB6,0x76,0x37,0x7E,0xE3);

LRESULT CCDlgDetector::OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add your control notification handler code here
	HRESULT hRes;
		 
	IDispatch * pExplorer;
	IDispatch* piDisp;
	hRes = ::CoCreateInstance(CLSID_InternetExplorer1,0,CLSCTX_ALL,__uuidof(IDispatch) ,(LPVOID *)&piDisp);
	if(hRes != S_OK)
	{
		::MessageBox(m_hWnd,_T("Can't  find  sothink catcher!"),_T("sothink"),MB_OK);
		return 0;
	}

	pExplorer = (IDispatch *)(piDisp);
	CCDetector *p = (CCDetector *)_pIDisp;
	
	p->m_spWebBrowser2->get_Document(&piDisp);


	DISPID dispid;
	LPOLESTR  funcname;
	DISPPARAMS dispParam;
	VARIANT varParam;
	CComVariant  varRet;

	//invoke setFileName  
    funcname = L"SetSwfNameVariant";
	hRes = pExplorer->GetIDsOfNames(IID_NULL,&funcname,1,LOCALE_SYSTEM_DEFAULT, &dispid);

	if(hRes != S_OK)
	{
		::MessageBox(m_hWnd,_T("Can't  find  Method : SetSwfNameVariant!"),_T("sothink"),MB_OK);
		return 0;
	}

	memset(&dispParam,0,sizeof(dispParam));
    dispParam.cArgs = 1;
	 
	::VariantInit(&varParam);
#if 0
	varParam.vt = VT_BSTR ;
	BSTR bSTR = ::SysAllocString(m_UrlSwf.GetBuffer());
	m_UrlSwf.ReleaseBuffer();
	varParam.bstrVal = bSTR;
	dispParam.rgvarg = &varParam;
	hRes = pExplorer->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispParam, &varRet, NULL, NULL);
	::SysFreeString( bSTR);
#endif
	CComVariant  Var;
	Var.vt = VT_BSTR;
	Var.bstrVal = ::SysAllocString(m_UrlSwf.GetBuffer());
	varParam.vt = VT_VARIANT | VT_BYREF;
	varParam.pvarVal = &Var; 
	dispParam.rgvarg = &varParam;
    hRes = pExplorer->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispParam, &varRet, NULL, NULL);
	::SysFreeString( (BSTR)Var.bstrVal);
	//invoke GetSWFFile

	funcname = L"GetSWFFile";
	hRes = pExplorer->GetIDsOfNames(IID_NULL,&funcname,1,LOCALE_SYSTEM_DEFAULT, &dispid);
    if(hRes != S_OK)
	{
		::MessageBox(m_hWnd,_T("Can't  find  Method : SetSWFName!"),_T("sothink"),MB_OK);
		return 0;
	}
	 
	memset(&dispParam,0,sizeof(dispParam));
	dispParam.cArgs = 1;
	
	::VariantInit(&varParam);
	varParam.vt = VT_DISPATCH;
	varParam.pdispVal = piDisp;
	dispParam.rgvarg = &varParam;

	
	this->SetShow(FALSE);
	hRes = pExplorer->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispParam, &varRet, NULL, NULL);
	this->SetShow(TRUE);
	//

	pExplorer->Release();
	piDisp->Release();
	return 0;
}

BOOL CCDlgDetector::SetShow(BOOL bShow)
{
    m_bShow = bShow;
	if(bShow)
		this->ShowWindow(SW_NORMAL);
	else
		this->ShowWindow(SW_HIDE);
	return 0;
}
