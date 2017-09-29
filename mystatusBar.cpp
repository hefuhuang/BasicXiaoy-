// mystatusBar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "mystatusBar.h"


// mystatusBar

IMPLEMENT_DYNAMIC(mystatusBar, CStatusBar)

mystatusBar::mystatusBar()
{

}

mystatusBar::~mystatusBar()
{
}


void mystatusBar::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	CRect rc;
	GetClientRect(&rc);
	HBRUSH hbr = CreateSolidBrush(RGB(255, 0, 0));
	FillRect(lpDrawItemStruct->hDC, &rc, hbr);
	DeleteObject(hbr);

	CString str;
	str = GetPaneText(1);
	SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	SetTextColor(lpDrawItemStruct->hDC, RGB(255, 0, 255));
	::TextOut(lpDrawItemStruct->hDC, 6, 6, str, str.GetLength());

	//	afxDump << lpDrawItemStruct->itemAction << "??\n";
	return;
}


HBRUSH mystatusBar::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	HBRUSH m_brush = CreateSolidBrush(RGB(255, 0, 255)); 

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	return NULL;
}

//BOOL mystatusBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
//{
//	// TODO:  �ڴ����ר�ô����/����û���
//
//	return CStatusBar::Create(pParentWnd, dwStyle, nID);
//}

BEGIN_MESSAGE_MAP(mystatusBar, CStatusBar)
//	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()


// mystatusBar ��Ϣ�������



