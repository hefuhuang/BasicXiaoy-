
// MFC_OCT.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_OCTApp: 
// �йش����ʵ�֣������ MFC_OCT.cpp
//

class CMFC_OCTApp : public CWinApp
{
public:
	CMFC_OCTApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_OCTApp theApp;