// CDlgDetector.h : Declaration of the CCDlgDetector

#pragma once

#include "resource.h"       // main symbols

#include <atlhost.h>

#include "atlstr.h"
// CCDlgDetector

class CCDlgDetector : 
	public CAxDialogImpl<CCDlgDetector>
{
public:
	CCDlgDetector()
	{
		m_bShow = TRUE;
	}

	CCDlgDetector(IDispatch *pDisp)
	{
		_pIDisp = pDisp;
	}
	~CCDlgDetector()
	{
	}
	
	enum { IDD = IDD_CDLGDETECTOR };

BEGIN_MSG_MAP(CCDlgDetector)
//	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, OnBnClickedButton1)
	CHAIN_MSG_MAP(CAxDialogImpl<CCDlgDetector>)
END_MSG_MAP()

	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}
 
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
public:
	void SetSwf(CString &urlSwf)
	{
		m_UrlSwf = urlSwf;
		m_UrlSwf.MakeUpper();
	};
	LRESULT OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	BOOL SetShow(BOOL bShow);
public:
	UINT_PTR m_uTimer;
	IDispatch  *_pIDisp;
	CString   m_UrlSwf;
	BOOL   m_bShow;
};


