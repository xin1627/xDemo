
// XCtrlDemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CXCtrlDemoApp:
// See XCtrlDemo.cpp for the implementation of this class
//

class CXCtrlDemoApp : public CWinApp
{
public:
	CXCtrlDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();
    virtual int ExitInstance();
// Implementation

	DECLARE_MESSAGE_MAP()

protected:
    ULONG_PTR m_token;

};

extern CXCtrlDemoApp theApp;
