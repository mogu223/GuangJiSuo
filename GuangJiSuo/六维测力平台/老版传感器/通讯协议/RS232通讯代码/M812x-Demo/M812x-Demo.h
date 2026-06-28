
// M812x-Demo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CM812xDemoApp:
// See M812x-Demo.cpp for the implementation of this class
//

class CM812xDemoApp : public CWinAppEx
{
public:
	CM812xDemoApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CM812xDemoApp theApp;