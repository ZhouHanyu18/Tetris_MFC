
// 俄罗斯方块-MFC.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C俄罗斯方块MFCApp: 
// 有关此类的实现，请参阅 俄罗斯方块-MFC.cpp
//

class C俄罗斯方块MFCApp : public CWinApp
{
public:
	C俄罗斯方块MFCApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C俄罗斯方块MFCApp theApp;