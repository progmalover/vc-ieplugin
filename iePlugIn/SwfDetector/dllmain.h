// dllmain.h : Declaration of module class.

class CSwfDetectorModule : public CAtlDllModuleT< CSwfDetectorModule >
{
public :
	DECLARE_LIBID(LIBID_SwfDetectorLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CDETECTOR, "{08070DB7-0E85-454E-828E-8CDF705DCD6E}")
};

extern class CSwfDetectorModule _AtlModule;
