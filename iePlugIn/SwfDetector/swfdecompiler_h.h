

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Dec 26 14:06:43 2008
 */
/* Compiler settings for .\SWFDecompiler.odl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
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


#ifndef __SWFDecompiler_h_h__
#define __SWFDecompiler_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInternetExplorer_FWD_DEFINED__
#define __IInternetExplorer_FWD_DEFINED__
typedef interface IInternetExplorer IInternetExplorer;
#endif 	/* __IInternetExplorer_FWD_DEFINED__ */


#ifndef __InternetExplorer_FWD_DEFINED__
#define __InternetExplorer_FWD_DEFINED__

#ifdef __cplusplus
typedef class InternetExplorer InternetExplorer;
#else
typedef struct InternetExplorer InternetExplorer;
#endif /* __cplusplus */

#endif 	/* __InternetExplorer_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __SWFDecompiler_LIBRARY_DEFINED__
#define __SWFDecompiler_LIBRARY_DEFINED__

/* library SWFDecompiler */
/* [version][uuid] */ 


//DEFINE_GUID(LIBID_SWFDecompiler,0xA71667E0,0x5792,0x4A49,0xA8,0x5E,0x25,0x9C,0x22,0x97,0x8E,0x6F);

#ifndef __IInternetExplorer_DISPINTERFACE_DEFINED__
#define __IInternetExplorer_DISPINTERFACE_DEFINED__

/* dispinterface IInternetExplorer */
/* [uuid] */ 


//DEFINE_GUID(DIID_IInternetExplorer,0x4FBE2BCC,0xAF98,0x4580,0xA8,0x9E,0xF3,0x4E,0xCA,0xF9,0x14,0xCE);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4FBE2BCC-AF98-4580-A89E-F34ECAF914CE")
    IInternetExplorer : public IDispatch
    {
	public:
		// virtual  long GetSWFFile(LPDISPATCH pDispatch);
    };
    
#else 	/* C style interface */

    typedef struct IInternetExplorerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInternetExplorer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInternetExplorer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInternetExplorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInternetExplorer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInternetExplorer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInternetExplorer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInternetExplorer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IInternetExplorerVtbl;

    interface IInternetExplorer
    {
        CONST_VTBL struct IInternetExplorerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInternetExplorer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInternetExplorer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInternetExplorer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInternetExplorer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInternetExplorer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInternetExplorer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInternetExplorer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IInternetExplorer_DISPINTERFACE_DEFINED__ */


//DEFINE_GUID(CLSID_InternetExplorer,0xE19ADC6E,0x3909,0x43E4,0x9A,0x89,0xB7,0xB6,0x76,0x37,0x7E,0xE3);

#ifdef __cplusplus

//class DECLSPEC_UUID("E19ADC6E-3909-43E4-9A89-B7B676377EE3")
//InternetExplorer;
#endif
#endif /* __SWFDecompiler_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


