

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICDetector,0xA8D2D468,0x36E9,0x4BD1,0x83,0x6F,0x6C,0xB6,0x14,0xF6,0x12,0xEC);


MIDL_DEFINE_GUID(IID, IID_ICHtmlDocDetector,0x103BDA32,0x5A97,0x40DD,0xB7,0x18,0xFF,0xBD,0x7D,0x53,0x00,0x4A);


MIDL_DEFINE_GUID(IID, IID_ICLinkDoc2,0x4F9D4FEE,0x0D12,0x41B3,0xA6,0xBA,0x1A,0x46,0x1E,0x94,0xE0,0x6F);


MIDL_DEFINE_GUID(IID, LIBID_SwfDetectorLib,0xAF75FD85,0x2F95,0x438A,0xBF,0x1A,0x68,0x65,0x0D,0xD9,0x00,0xAF);


MIDL_DEFINE_GUID(CLSID, CLSID_CDetector,0xD9ADE6D8,0x82AB,0x4DF3,0x82,0xFC,0xD8,0x60,0x29,0x1D,0xA5,0x76);


MIDL_DEFINE_GUID(CLSID, CLSID_CHtmlDocDetector,0x1ADA3F81,0xBC57,0x41FF,0x96,0x1E,0x95,0x23,0x6F,0x33,0xFD,0xA0);


MIDL_DEFINE_GUID(CLSID, CLSID_CLinkDoc2,0x63DF4C2B,0x7AAD,0x4C95,0x96,0xF2,0x13,0x08,0x76,0x83,0x2D,0x6A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



