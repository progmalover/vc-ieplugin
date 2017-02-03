

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "SwfDetector_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _SwfDetector_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } SwfDetector_MIDL_TYPE_FORMAT_STRING;

typedef struct _SwfDetector_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } SwfDetector_MIDL_PROC_FORMAT_STRING;

typedef struct _SwfDetector_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } SwfDetector_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const SwfDetector_MIDL_TYPE_FORMAT_STRING SwfDetector__MIDL_TypeFormatString;
extern const SwfDetector_MIDL_PROC_FORMAT_STRING SwfDetector__MIDL_ProcFormatString;
extern const SwfDetector_MIDL_EXPR_FORMAT_STRING SwfDetector__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICDetector_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICDetector_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICHtmlDocDetector_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICHtmlDocDetector_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICLinkDoc2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICLinkDoc2_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const SwfDetector_MIDL_PROC_FORMAT_STRING SwfDetector__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const SwfDetector_MIDL_TYPE_FORMAT_STRING SwfDetector__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICDetector, ver. 0.0,
   GUID={0xA8D2D468,0x36E9,0x4BD1,{0x83,0x6F,0x6C,0xB6,0x14,0xF6,0x12,0xEC}} */

#pragma code_seg(".orpc")
static const unsigned short ICDetector_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICDetector_ProxyInfo =
    {
    &Object_StubDesc,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICDetector_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICDetector_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICDetector_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ICDetectorProxyVtbl = 
{
    0,
    &IID_ICDetector,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ICDetector_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ICDetectorStubVtbl =
{
    &IID_ICDetector,
    &ICDetector_ServerInfo,
    7,
    &ICDetector_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ICHtmlDocDetector, ver. 0.0,
   GUID={0x103BDA32,0x5A97,0x40DD,{0xB7,0x18,0xFF,0xBD,0x7D,0x53,0x00,0x4A}} */

#pragma code_seg(".orpc")
static const unsigned short ICHtmlDocDetector_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICHtmlDocDetector_ProxyInfo =
    {
    &Object_StubDesc,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICHtmlDocDetector_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICHtmlDocDetector_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICHtmlDocDetector_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ICHtmlDocDetectorProxyVtbl = 
{
    0,
    &IID_ICHtmlDocDetector,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ICHtmlDocDetector_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ICHtmlDocDetectorStubVtbl =
{
    &IID_ICHtmlDocDetector,
    &ICHtmlDocDetector_ServerInfo,
    7,
    &ICHtmlDocDetector_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ICLinkDoc2, ver. 0.0,
   GUID={0x4F9D4FEE,0x0D12,0x41B3,{0xA6,0xBA,0x1A,0x46,0x1E,0x94,0xE0,0x6F}} */

#pragma code_seg(".orpc")
static const unsigned short ICLinkDoc2_FormatStringOffsetTable[] =
    {
    (unsigned short) -1
    };

static const MIDL_STUBLESS_PROXY_INFO ICLinkDoc2_ProxyInfo =
    {
    &Object_StubDesc,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICLinkDoc2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICLinkDoc2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    SwfDetector__MIDL_ProcFormatString.Format,
    &ICLinkDoc2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ICLinkDoc2ProxyVtbl = 
{
    &ICLinkDoc2_ProxyInfo,
    &IID_ICLinkDoc2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* ICLinkDoc2::ConnectDoc2 */
};

const CInterfaceStubVtbl _ICLinkDoc2StubVtbl =
{
    &IID_ICLinkDoc2,
    &ICLinkDoc2_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    SwfDetector__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _SwfDetector_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ICHtmlDocDetectorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICDetectorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICLinkDoc2ProxyVtbl,
    0
};

const CInterfaceStubVtbl * _SwfDetector_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ICHtmlDocDetectorStubVtbl,
    ( CInterfaceStubVtbl *) &_ICDetectorStubVtbl,
    ( CInterfaceStubVtbl *) &_ICLinkDoc2StubVtbl,
    0
};

PCInterfaceName const _SwfDetector_InterfaceNamesList[] = 
{
    "ICHtmlDocDetector",
    "ICDetector",
    "ICLinkDoc2",
    0
};

const IID *  _SwfDetector_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    0
};


#define _SwfDetector_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _SwfDetector, pIID, n)

int __stdcall _SwfDetector_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _SwfDetector, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _SwfDetector, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _SwfDetector, 3, *pIndex )
    
}

const ExtendedProxyFileInfo SwfDetector_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _SwfDetector_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _SwfDetector_StubVtblList,
    (const PCInterfaceName * ) & _SwfDetector_InterfaceNamesList,
    (const IID ** ) & _SwfDetector_BaseIIDList,
    & _SwfDetector_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

