// UIthread.cpp : implementation file
//

#include "UIthread.h"
#include "stdafx.h"

// UIthread

IMPLEMENT_DYNCREATE(UIthread, CWinThread)

UIthread::UIthread()
{
}

UIthread::~UIthread()
{
}

BOOL UIthread::InitInstance()
{

//	m_pMainWnd = &mMainDlg; 
//	mMainDlg.DoModal();

	return TRUE;

}

int UIthread::ExitInstance()
{

//	mMainDlg.DestroyWindow();
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(UIthread, CWinThread)
END_MESSAGE_MAP()


// UIthread message handlers
