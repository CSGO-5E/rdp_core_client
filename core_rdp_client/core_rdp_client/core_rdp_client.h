
// core_rdp_client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ccore_rdp_clientApp: 
// �йش����ʵ�֣������ core_rdp_client.cpp
//

class Ccore_rdp_clientApp : public CWinApp
{
public:
	Ccore_rdp_clientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ccore_rdp_clientApp theApp;