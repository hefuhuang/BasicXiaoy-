// AddSheet.cpp : implementation file
//
#include "stdafx.h"
#include "MFC_OCT.h"
#include "AddSheet.h"

// CAddSheet

IMPLEMENT_DYNAMIC(CAddSheet, CPropertySheet)

CAddSheet::CAddSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m2DParam);
	AddPage(&m3Dparam);
	


#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CAddSheet::CAddSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
//	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	AddPage(&m2DParam);
	AddPage(&m3Dparam);

#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

void CAddSheet::SetModifyed()
{
  GetParent()->GetDlgItem(ID_APPLY_NOW)->EnableWindow(TRUE);
}

CAddSheet::~CAddSheet()
{
}


BEGIN_MESSAGE_MAP(CAddSheet, CPropertySheet)
END_MESSAGE_MAP()


// CAddSheet message handlers
