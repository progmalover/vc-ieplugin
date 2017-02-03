// CDetector.cpp : Implementation of CCDetector

#include "stdafx.h"
#include "CDetector.h"
#include "ExDispid.h"
#include "Wininet.h"
// CCDetector

 
/////////////////////////////////////////////////////////////////////////////
// SetSite - Initializes the BHO
// 
CCDlgDetector  CCDetector::*_Dlg;
HWND FindBrowserObjWnd(HWND hWnd)
{
	TCHAR  tTxt[_MAX_PATH];
	::GetClassName(hWnd,tTxt,_MAX_PATH);
	//ATLTRACE("GetClassName :%s \n",CW2A(tTxt));
	if(::_tcsicmp(tTxt,_T("Internet Explorer_Server")) == 0)
		return hWnd;
	
	HWND hChild = GetWindow(hWnd,GW_CHILD);
	while(hChild)
	{
		HWND h = FindBrowserObjWnd(hChild);
		if(h == NULL)
		{
			hChild = GetWindow(hChild,GW_HWNDNEXT);
		}else
			return h;
	}

	return NULL;
}

 
BOOL CanonicalURL(CString &strURL)
{
	bool bOK = TRUE;
	TCHAR *pszUrl = new TCHAR[_MAX_PATH + 1];
	DWORD dwLen = _MAX_PATH;
	if (!InternetCanonicalizeUrl(strURL.GetBuffer(), pszUrl, &dwLen, ICU_NO_ENCODE))
	{
		strURL.ReleaseBuffer();
		delete pszUrl;
		dwLen += 10;
		dwLen *= 2;
		pszUrl = new TCHAR[dwLen ];
		if (!InternetCanonicalizeUrl(strURL.GetBuffer(), pszUrl, &dwLen, ICU_NO_ENCODE))
		{
			strURL.ReleaseBuffer();
			bOK = FALSE;
		}else
		{
			strURL.ReleaseBuffer();
			strURL = pszUrl;
		}
		
	}else
	{
		strURL.ReleaseBuffer();
		strURL = pszUrl;
	}
	

	delete pszUrl;

	return bOK;
}

BOOL   FindParamVal(const TCHAR * strSRC,const TCHAR * paName,const TCHAR * paSec,CString &paSecVal )
{
	TCHAR *  lpEQ = _T("PARAM NAME=");
	TCHAR * lpf = (TCHAR *)StrStr(strSRC,lpEQ);
	
	while(lpf)
	{
		lpf += ::_tcslen(lpEQ);
		TCHAR *lp = lpf;

		while(*lp == ' ')
			lp++;
		while(*lp == '"')
			lp++;

		if(_tcsncmp(lp,paName,::_tcslen(paName)) == 0)
		{
			lp += _tcslen(paName);
		 
			while(*lp == '"'||*lp == ' '||*lp == '='||*lp == '\'')
				lp++;
			TCHAR *lp2 = lp;

			if(_tcsncmp(lp2,paSec,::_tcslen(paSec)) == 0)
			{
				lp2 += ::_tcslen(paSec);

				while(*lp2 == '"'||*lp2 == ' '||*lp2 == '='||*lp2 == '\'')
				lp2++;
				
				lp = lp2;

				while(*lp2 != '"'&& *lp2 != '\''&& *lp2 != '>')
					lp2++;
				if(lp2 > lp)
				{
					paSecVal.SetString(lp,lp2 - lp);
					return TRUE;
				}
			}
		}
		lpf = (TCHAR *)StrStr(lp,lpEQ);
	}

	return FALSE;
}

void ParseSwfNameUrl(CString &strSRC,CString &strURL)
{
	TCHAR *  paraSTR = _T("<PARAM");
	strSRC.MakeUpper();

	if(::_tcsncmp(strSRC,paraSTR,6) == 0) //is param str
	{
		if(!FindParamVal(strSRC,_T("MOVIE"),_T("VALUE"),strURL))
			strURL.Empty();
	}
	else //strip first swf name;
	{
		
		
		TCHAR *tpStr  = strSRC.GetBuffer();
		strSRC.ReleaseBuffer();

		if(::_tcsncmp(tpStr,_T("HTTP"),4) != 0)
		{
			strURL.Empty();
		   return  ;
		}
		TCHAR *tp1,*tp2;
		tp1 = tp2 = ::_tcsstr(tpStr,_T(".SWF"));
		tp2 += 4; 
		while( *--tp1 != '"'&& *tp1 != '\'' && *tp1 != '=' && tp1 > tpStr) ;
        
		if(tp2 - tp1 > 4)
		{
			strURL.SetString(tp1,tp2 - tp1);
		}else
			strURL.Empty();
	}
}

bool CCDetector::IsSwfElement2(IHTMLElement *p)
{
	if(p == NULL)
			return false;

	 this->_Dlg->SetSwf(CString());


	HRESULT hRes;
	CString  strSRC,strTYPE;
	CComVariant vtSRC,vtType;


	hRes = p->getAttribute(CComBSTR("src"),0,&vtSRC);

	if(vtSRC.vt != VT_NULL) 
		strSRC = vtSRC.bstrVal;
	else
	{
		CComBSTR htmlSTR;
		p->get_innerHTML(&htmlSTR);
		strSRC = htmlSTR;
	}

	//ATLTRACE("strSRC :%s \n",CW2A(strSRC.GetBuffer()));
	strSRC.ReleaseBuffer();

	if(strSRC.GetLength() < 4)
		return false;

	if(strSRC.Find(_T(".swf")) > 0) //这里还不一定确定不是 swf
	{
		CString   strSWF;

		ParseSwfNameUrl(strSRC,strSWF);

		if(strSWF.IsEmpty())
			return false;

		CString extSTR = strSWF.Right(4);

		if(extSTR.Compare(_T(".SWF")) == 0)
		{
		 this->_Dlg->SetSwf(strSWF);
		 return  true;
		}else
			return false;
	}

	
	hRes = p->getAttribute(CComBSTR("type"),0,&vtType);

	if(vtType.vt != VT_NULL)
	{
		strTYPE = vtType.bstrVal ;
		strTYPE.Remove(' ');
	
		if(strTYPE.CompareNoCase(_T("application/x-shockwave-flash")) == 0)
		{
			return true;
		}
	}

	BSTR outHTML;
	p->get_outerHTML(&outHTML);

	CanonicalURL(strSRC);
	
	/*接下来，开始进行 串的比较*/
	ELEMENT_LIST::iterator	_end  = this->_SwfList.end();
	ELEMENT_LIST::iterator  _it = this->_SwfList.begin();
	ATLTRACE("hit swf :%s  \n",CW2A(strSRC));
	for(;_it != _end;_it++)
	{
		SWF_URLS  &urls = *_it;
		//if(urls.strDocs.GetLength() == strSRC.GetLength())
		for(DOC_VECT::iterator it = urls.strDocs.begin();it != urls.strDocs.end();it++)
		{
			CString strDoc = *it;
			if(strDoc.CompareNoCase(strSRC) == 0)
			{
				this->_Dlg->SetSwf(urls.strSwfs[0]);
			
				return true; 
			}
		}

	}
	return false;
}

#if 0
void CALLBACK  CCDetector::DetectorTimer::TimerProc(HWND,UINT,UINT_PTR,WORD)
 { 
	 

		ATLTRACE( "\n mouse move !!\n");
		if(CCDetector::Instance()->m_SwfRoom.NeedScan())
			CCDetector::Instance()->m_SwfRoom.SwfDetector();//http://www.163.com/
		 if(CCDetector::Instance()->m_SwfRoom._SwfList.empty())
		{
			CCDetector::Instance()->m_DTimer.EndTimer();
			return ;
		}

		POINT  point;
		RECT   cliRect;
		::GetCursorPos(&point);
	 
		if(!CCDetector::Instance()->m_hwndBrowserObj) 
		   CCDetector::Instance()->m_hwndBrowserObj = FindBrowserObjWnd( CCDetector::Instance()->m_hwndBrowser);
		::GetWindowRect(CCDetector::Instance()->m_hwndBrowserObj,&cliRect);

		if( ::PtInRect(&cliRect,point))
		{
			POINT pt = point;
			
			::ScreenToClient( CCDetector::Instance()->m_hwndBrowserObj,&pt);
			
			CComPtr<IDispatch> pIDisp;
			CComQIPtr<IHTMLDocument2> pIDoc2;
			CCDetector::Instance()->m_spWebBrowser2->get_Document(&pIDisp);
			pIDoc2 = pIDisp;

			CComPtr<IHTMLElement> pElement ;
			pIDoc2->elementFromPoint(pt.x,pt.y,&pElement);
			


			if(IsSwfElement2(pElement))
			{
				RECT wndRect;
				CCDetector::Instance()->_Dlg.GetWindowRect(&wndRect);
				CCDetector::Instance()->_Dlg.MoveWindow(point.x,point.y,wndRect.right - wndRect.left,wndRect.bottom - wndRect.top);
				CCDetector::Instance()->_Dlg.ShowWindow(TRUE);
			}else
				CCDetector::Instance()->_Dlg.ShowWindow(FALSE);
		}

    
 }
 
#endif
HRESULT CCDetector::SetSite(IUnknown *pUnkSite)
{
	m_spWebBrowser2 = pUnkSite; 
	if (m_spWebBrowser2 == NULL)
		return E_INVALIDARG;
	
	m_spCPC = m_spWebBrowser2;
	if (m_spCPC == NULL) 
		return E_POINTER;

//    m_pcDetor = this;
	m_spWebBrowser2->get_HWND((SHANDLE_PTR*)&m_hwndBrowser);
	this->m_hwndBrowserObj =  FindBrowserObjWnd(m_hwndBrowser);


	_Dlg->Create( m_hwndBrowserObj);
	StartTimer();
	return Connect();
	
}


/////////////////////////////////////////////////////////////////////////////
// Connect - Register to the container as an event handler
// 
HRESULT CCDetector::Connect(void)
{
	HRESULT hr = S_OK;
 
	CComPtr<IConnectionPoint> spCP;

    hr = m_spCPC->FindConnectionPoint(
			DIID_DWebBrowserEvents2, 
			&spCP);
    if (FAILED(hr))
		return hr;

	hr = spCP->Advise( 
			reinterpret_cast<IDispatch*>(this), 
			&m_dwCookie);

    return hr; 
}


/////////////////////////////////////////////////////////////////////////////
// Disconnect - Unregister as an event handler module
// 
HRESULT CCDetector::Disconnect(void)
{
	HRESULT hr = S_OK;

 
	CComPtr<IConnectionPoint> spCP;

	// Receives the connection point for WebBrowser events
    hr = m_spCPC->FindConnectionPoint(
			DIID_DWebBrowserEvents2, 
			&spCP);
    if (FAILED(hr))
		return hr;

    // Stop getting event notifications
	hr = spCP->Unadvise(m_dwCookie);
    return hr;
}

void CCDetector::SwfScan(void)
{

}

typedef std::list < IHTMLDocument2 * > DOC_LIST;
BOOL  CCDetector::SwfDetector(/*IHTMLDocument2 *pHtmlDoc2*/)
{
	CComPtr<IDispatch> piDisp;
	CComQIPtr<IHTMLDocument2,&IID_IHTMLDocument2> pHtmlDoc2;

	m_spWebBrowser2->get_Document(&piDisp);
	pHtmlDoc2 = piDisp;
	m_bOpened = TRUE;


	DoSwfScan(pHtmlDoc2);

	return TRUE;
}

HRESULT CCDetector::ConnectDoc2(IDispatch * pDisp)
{

	 if(pDisp != NULL)
	{
	   m_spDocCPC  = pDisp;

	   CComPtr<IConnectionPoint>spCP;
	   m_spDocCPC->FindConnectionPoint(DIID_HTMLDocumentEvents2,&spCP);
		  
	   spCP->Advise(
			reinterpret_cast<IDispatch*>(this), 
			&m_dwDocCookie);
	 
		return S_OK;
	}

	return  S_FALSE;
}

void CCDetector::UnConnectDoc2(void)
{
	if(m_dwDocCookie == 0) return;
	 CComPtr<IConnectionPoint>spCP;
	 m_spDocCPC->FindConnectionPoint(DIID_HTMLDocumentEvents2,&spCP);
	 spCP->Unadvise(m_dwDocCookie);
}

HRESULT  CCDetector:: LinkToDoc2(IDispatch  *pDoc)
{
	//if(pDoc)

   UnConnectDoc2();
	CComPtr<IDispatch> piDisp;

	/*::offsetofclass();*/
	m_spWebBrowser2->get_Document(&piDisp) ;

	return ConnectDoc2(piDisp);

	;
}

/////////////////////////////////////////////////////////////////////////////
// Invoke - Switch-procedure for events
// 

BOOL  CCDetector:: GetMainDoc2URL(CString &url)
{
	CComPtr<IDispatch>pDisp;
	CComQIPtr<IHTMLDocument2>pDoc2;
	m_spWebBrowser2->get_Document(&pDisp);
	pDoc2 = pDisp ;
	if(pDoc2)
	{
		CComBSTR bSTR;
		pDoc2->get_URL(&bSTR);
		url = bSTR;
		return TRUE;
	}
	return FALSE;
}

HRESULT CCDetector::Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,
	DISPPARAMS* pDispParams, VARIANT* pvarResult,
    EXCEPINFO*  pExcepInfo,  UINT* puArgErr)
{
   if (!pDispParams)
      return E_INVALIDARG;

   switch(dispidMember)
   {
   case  DISPID_DOCUMENTCOMPLETE:
	   {
			LinkToDoc2(NULL);
			this->Reset();
			//StartTimer();
	   }
	   break;
   case DISPID_BEFORENAVIGATE2:
	   {
		 this->Reset();
		 if( _Dlg->IsWindow())
			   _Dlg->ShowWindow(FALSE);
	   }break;
   case DISPID_TITLEICONCHANGE:
	   {
		
	   }break;
   case DISPID_ONQUIT:
	   OnQuit();
	   break;
   case (LONG)-606:
	   {
		   CComQIPtr<IHTMLEventObj >pIEventObj(pDispParams->rgvarg->pdispVal);
		   if(!pIEventObj) return S_OK ;
		   CComPtr<IHTMLElement>pIElement;
		   pIEventObj->get_srcElement(&pIElement);
		   if(!pIElement)  return S_OK;
		   if(!this->IsSwfElement2(pIElement))
		   {
			   this->_Dlg->ShowWindow(FALSE);
		   }/*else
		       this->StartTimer();
		   */
	   }
	   break;
   default:
	   //ATLTRACE("dispidMember :%d \n", dispidMember);
	   break;
   }
 
   return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
// OnQuit - The browser (and the BHO) is terminating
// 

void  CCDetector::StartTimer(void)
{
	EndTimer();
	m_uTimer = this->_Dlg->SetTimer(0,500,0);
}
void  CCDetector::EndTimer(void)
{
 if(this->m_uTimer)
	  _Dlg->KillTimer(m_uTimer );
}

HRESULT CCDetector::OnQuit()
{
	// Unregister as an event listener 
	
	
	Disconnect();

	EndTimer();
   if( _Dlg->IsWindow())
			_Dlg->DestroyWindow();
//
	return S_OK;
}
 
CString GetFullURLName(CString &strURL)
{
   CanonicalURL(strURL);
   LPTSTR lpStr = strURL.GetBuffer();
   LPTSTR lpfnd = _tcsstr(lpStr,_T(".swf"));
   lpfnd += _tcslen(_T(".swf"));

   strURL.ReleaseBuffer();
   strURL = strURL.Left(((int)lpfnd - (int)lpStr)/sizeof(TCHAR));
   return strURL;
}

//深度遍历 
HRESULT  CCDetector::DoSwfScan(CComQIPtr<IHTMLDocument2,&IID_IHTMLDocument2> spDoc2)
{
	DOC_LIST spDocuments;

	HRESULT hr ;

	if(!spDoc2)
		return S_OK;

	spDoc2.p->AddRef();
	spDocuments.push_back(spDoc2.p);

	
	CComQIPtr <IOleContainer, &IID_IOleContainer> spContainer(spDoc2);
	if (spContainer)
	{
		CComPtr <IEnumUnknown> spEnumerator;
		hr = spContainer->EnumObjects(OLECONTF_EMBEDDINGS, &spEnumerator);
		if (SUCCEEDED(hr))
		{
			ULONG uFetched;   // Enumerate and refresh all the frames
			IUnknown * pUnk;
			for (UINT i = 0; S_OK == spEnumerator->Next(1, &pUnk, &uFetched); i++)
			{
				CComQIPtr <IWebBrowser2, &IID_IWebBrowser2> spBrowser2(pUnk);
				pUnk->Release();
				if (spBrowser2)
				{
					CComPtr <IDispatch> spDisp;
					hr = spBrowser2->get_Document(&spDisp);

					if (FAILED(hr) || !spDisp)
						continue;

					CComQIPtr <IHTMLDocument2, &IID_IHTMLDocument2> spDocDisp(spDisp);
					if(spDocDisp)
					{
						//spDocDisp.p->AddRef();
						//spDocuments.push_back(spDocDisp.p);
						DoSwfScan(spDocDisp);
					}
				}
			}
		}
		else
			return S_FALSE;
		
	}
	else
		return S_FALSE;
	

    CString  docURL;
	CString  _MainUrl;
	CComBSTR urlBSTR;
	
	SWF_URLS  sUrl;
	BOOL bGetURl;

	for (DOC_LIST::iterator it = spDocuments.begin(); it != spDocuments.end(); it++)
	{
		
		CComPtr<IHTMLDocument2> spDocument2 = *it;

		hr = spDocument2->get_URL(&urlBSTR);
        
		if(hr == S_OK)
		{
			docURL = urlBSTR;
			sUrl.strDocs.push_back(docURL);
#ifdef _DEBUG
			if(docURL == _T("http://pic.zol.com.cn/200807/almmplay120_0723.html"))
			{		
				int dsf =32;

			}
#endif
			bGetURl = FALSE;
		}

		ATLTRACE("docURL :%s  \n",CW2A(docURL));

		CanonicalURL(docURL);

		CComPtr<IHTMLElementCollection> spObjects;
		if (SUCCEEDED(spDocument2->get_applets(&spObjects)))
		{
			long count = 0;
			spObjects->get_length(&count);	
			if (count > 0)
			{
				for (long i = 0; i < count; i++)
				{
					CComVariant vtIndex = i;
					CComPtr<IDispatch> spDispatch;
					if (SUCCEEDED(spObjects->item(vtIndex, vtIndex, &spDispatch)))
					{
						CComQIPtr<IHTMLObjectElement, &IID_IHTMLObjectElement> spObject(spDispatch);
						if (spObject)
						{
							CComBSTR bstrClassId = NULL;
							if (SUCCEEDED(spObject->get_classid(&bstrClassId)))
							{
								CString strClassId = bstrClassId.m_str;
								strClassId.MakeUpper();
								if (strClassId.Find(_T("D27CDB6E-AE6D-11CF-96B8-444553540000"), 0) >= 0)
								{
									CComQIPtr<IHTMLElement, &IID_IHTMLElement> spElement(spObject);
									if (spElement)
									{
										/*save swf url here ,and save the  url*/
										CComQIPtr<IHTMLElement, &IID_IHTMLElement> spElement(spObject);
										if (spElement)
										{
											CString strMovie = _T("movie");
											CComVariant vtMovie;
											spElement->getAttribute(strMovie.AllocSysString(), 0, &vtMovie);

											strMovie = vtMovie.bstrVal;

											strMovie.Trim(' ');

											CString  strURL = GetFullURLName(strMovie);
											//ATLTRACE("    %s\n", CW2A(strURL));
										 
											
											GetMainDoc2URL(_MainUrl);
											if(docURL.CompareNoCase( _MainUrl) == 0)
											{
												CComBSTR  htmlSTR ;
												spElement->get_innerHTML(&htmlSTR);
												sUrl.strDocs.push_back(CString(htmlSTR));
											}//else
												//sUrl.strDocs.push_back(docURL);
												//sUrl.strDoc = docURL;
											
											/*save to list*/		
											//ATLTRACE("embed docUrl:    %s\n", CW2A(docURL));
                                            ATLTRACE("embed strSwf:    %s\n", CW2A(strURL));
											sUrl.strSwfs.push_back(strURL);
											
										 
										}
									}
									
								}
							}
						}
					}
				}
			_SwfList.push_back(sUrl);
			sUrl.strDocs.clear();
			sUrl.strSwfs.clear();
			bGetURl = TRUE; 
			}
		}

		if(bGetURl)
          sUrl.strDocs.push_back(docURL);
  
		CComPtr<IHTMLElementCollection> spEmbeds;
		if (SUCCEEDED(spDocument2->get_embeds(&spEmbeds)))
		{
			long count = 0;
			spEmbeds->get_length(&count);	
			if (count > 0)
			{
				for (long i = 0; i < count; i++)
				{
					CComVariant vtIndex = i;
					CComPtr<IDispatch> spDispatch;
					if (SUCCEEDED(spEmbeds->item(vtIndex, vtIndex, &spDispatch)))
					{
							CComQIPtr<IHTMLElement, &IID_IHTMLElement> spElement(spDispatch);
				
						    /*get swf url here ,and save the main url*/
							CComVariant vtSrc;
							CString strSrc, strType;
							if (SUCCEEDED(spElement->getAttribute(CComBSTR("src"), 0, &vtSrc)) && vtSrc.vt != VT_NULL)
							{
								strSrc = vtSrc.bstrVal;
								strSrc.Trim(' ');
								CComVariant vtType;
								if (SUCCEEDED(spElement->getAttribute(CComBSTR("type"), 0, &vtType)) && vtType.vt != VT_NULL)
								{
									strType = vtType.bstrVal;
									strType.Trim(' ');
								}
							}
							ATLTRACE("str SRC :%s  \n",CW2A(strSrc));
							//ATLTRACE("docURL :%s  \n",CW2A(docURL.GetBuffer()));

							if (strSrc.Right(4).CompareNoCase(_T(".swf")) == 0 || 
								strType.CompareNoCase(_T("application/x-shockwave-flash")) == 0)
							{
								
								CString  strURL = GetFullURLName(strSrc);
								
								SWF_URLS  sUrl;
								
								GetMainDoc2URL(_MainUrl);
								
								ATLTRACE("strSrc:    %s\n", CW2A(strSrc));
								if(docURL.CompareNoCase( _MainUrl) == 0)
								{
									CComBSTR  htmlSTR ;
									spElement->get_innerHTML(&htmlSTR);
									sUrl.strDocs.push_back(CString(htmlSTR));
								}//else
									//sUrl.strDocs.push_back(docURL);
								/*save to list*/
							 
								sUrl.strSwfs.push_back(strURL);
							//	this->_SwfList.push_back(sUrl);	
								
							}
						
					}
				}

			 _SwfList.push_back(sUrl);
			sUrl.strDocs.clear();
			sUrl.strSwfs.clear();
			}


		}

		spDocument2.p->Release();
	}

	return S_OK;

}
