

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Dec 30 09:41:06 2008
 */
/* Compiler settings for .\SwfDetector.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SwfDetector_i_h__
#define __SwfDetector_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICDetector_FWD_DEFINED__
#define __ICDetector_FWD_DEFINED__
typedef interface ICDetector ICDetector;
#endif 	/* __ICDetector_FWD_DEFINED__ */


#ifndef __ICHtmlDocDetector_FWD_DEFINED__
#define __ICHtmlDocDetector_FWD_DEFINED__
typedef interface ICHtmlDocDetector ICHtmlDocDetector;
#endif 	/* __ICHtmlDocDetector_FWD_DEFINED__ */


#ifndef __ICLinkDoc2_FWD_DEFINED__
#define __ICLinkDoc2_FWD_DEFINED__
typedef interface ICLinkDoc2 ICLinkDoc2;
#endif 	/* __ICLinkDoc2_FWD_DEFINED__ */


#ifndef __CDetector_FWD_DEFINED__
#define __CDetector_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDetector CDetector;
#else
typedef struct CDetector CDetector;
#endif /* __cplusplus */

#endif 	/* __CDetector_FWD_DEFINED__ */


#ifndef __CHtmlDocDetector_FWD_DEFINED__
#define __CHtmlDocDetector_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHtmlDocDetector CHtmlDocDetector;
#else
typedef struct CHtmlDocDetector CHtmlDocDetector;
#endif /* __cplusplus */

#endif 	/* __CHtmlDocDetector_FWD_DEFINED__ */


#ifndef __CLinkDoc2_FWD_DEFINED__
#define __CLinkDoc2_FWD_DEFINED__

#ifdef __cplusplus
typedef class CLinkDoc2 CLinkDoc2;
#else
typedef struct CLinkDoc2 CLinkDoc2;
#endif /* __cplusplus */

#endif 	/* __CLinkDoc2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICDetector_INTERFACE_DEFINED__
#define __ICDetector_INTERFACE_DEFINED__

/* interface ICDetector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICDetector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8D2D468-36E9-4BD1-836F-6CB614F612EC")
    ICDetector : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICDetectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICDetector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICDetector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICDetector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICDetector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICDetector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICDetector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICDetector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICDetectorVtbl;

    interface ICDetector
    {
        CONST_VTBL struct ICDetectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICDetector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICDetector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICDetector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICDetector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICDetector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICDetector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICDetector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICDetector_INTERFACE_DEFINED__ */


#ifndef __ICHtmlDocDetector_INTERFACE_DEFINED__
#define __ICHtmlDocDetector_INTERFACE_DEFINED__

/* interface ICHtmlDocDetector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICHtmlDocDetector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("103BDA32-5A97-40DD-B718-FFBD7D53004A")
    ICHtmlDocDetector : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICHtmlDocDetectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICHtmlDocDetector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICHtmlDocDetector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICHtmlDocDetector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICHtmlDocDetector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICHtmlDocDetector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICHtmlDocDetector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICHtmlDocDetector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICHtmlDocDetectorVtbl;

    interface ICHtmlDocDetector
    {
        CONST_VTBL struct ICHtmlDocDetectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICHtmlDocDetector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICHtmlDocDetector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICHtmlDocDetector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICHtmlDocDetector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICHtmlDocDetector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICHtmlDocDetector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICHtmlDocDetector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICHtmlDocDetector_INTERFACE_DEFINED__ */


#ifndef __ICLinkDoc2_INTERFACE_DEFINED__
#define __ICLinkDoc2_INTERFACE_DEFINED__

/* interface ICLinkDoc2 */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ICLinkDoc2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F9D4FEE-0D12-41B3-A6BA-1A461E94E06F")
    ICLinkDoc2 : public IUnknown
    {
    public:
        virtual /* [local][helpstring][id] */ HRESULT STDMETHODCALLTYPE ConnectDoc2( 
            /* [in] */ void *pDoc2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICLinkDoc2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLinkDoc2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLinkDoc2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLinkDoc2 * This);
        
        /* [local][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConnectDoc2 )( 
            ICLinkDoc2 * This,
            /* [in] */ void *pDoc2);
        
        END_INTERFACE
    } ICLinkDoc2Vtbl;

    interface ICLinkDoc2
    {
        CONST_VTBL struct ICLinkDoc2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLinkDoc2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLinkDoc2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLinkDoc2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLinkDoc2_ConnectDoc2(This,pDoc2)	\
    ( (This)->lpVtbl -> ConnectDoc2(This,pDoc2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLinkDoc2_INTERFACE_DEFINED__ */



#ifndef __SwfDetectorLib_LIBRARY_DEFINED__
#define __SwfDetectorLib_LIBRARY_DEFINED__

/* library SwfDetectorLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SwfDetectorLib;

EXTERN_C const CLSID CLSID_CDetector;

#ifdef __cplusplus

class DECLSPEC_UUID("D9ADE6D8-82AB-4DF3-82FC-D860291DA576")
CDetector;
#endif

EXTERN_C const CLSID CLSID_CHtmlDocDetector;

#ifdef __cplusplus

class DECLSPEC_UUID("1ADA3F81-BC57-41FF-961E-95236F33FDA0")
CHtmlDocDetector;
#endif

EXTERN_C const CLSID CLSID_CLinkDoc2;

#ifdef __cplusplus

class DECLSPEC_UUID("63DF4C2B-7AAD-4C95-96F2-130876832D6A")
CLinkDoc2;
#endif
#endif /* __SwfDetectorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


