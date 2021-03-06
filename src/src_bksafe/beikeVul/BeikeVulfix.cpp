// test_bkwin.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <wtlhelper/whwindow.h>
#include <process.h>
#include <algorithm>
#include <functional>
#include "BeikeVulfix.h"
#include "BeikeVulfixUtils.h"
#include "BeikeVulfixEngine.h"
#include "DlgMain.h"

CAppModule _Module;
CVulEngine *theEngine=NULL;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
#   ifdef _DEBUG
	bkconsole theConsole;
#   endif
	
    BkSkin::LoadSkins(IDR_BK_SKIN_DEF);
    BkStyle::LoadStyles(IDR_BK_STYLE_DEF);
    BkString::Load(IDR_BK_STRING_DEF);
	
	HMODULE hModRiched = ::LoadLibrary(_T("riched20.dll"));
	
    CDlgMain dlg;
	theEngine = new CVulEngine(dlg);
    dlg.Load(IDR_BK_TEST_DIALOG);
    dlg.DoModal();
	delete theEngine;
	theEngine = NULL;
	
	::FreeLibrary( hModRiched );
    return 0;
}
