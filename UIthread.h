#pragma once
#include "stdafx.h"
#include "MFC_OCT.h"
#include "MFC_OCTDlg.h"
// UIthread

class UIthread : public CWinThread
{
	DECLARE_DYNCREATE(UIthread)

protected:
	UIthread();           // protected constructor used by dynamic creation
	virtual ~UIthread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();  

	//CMFC_OCTDlg  mMainDlg;

protected:
	//CMFC_OCTDlg *m_dlg;

	DECLARE_MESSAGE_MAP()
};
