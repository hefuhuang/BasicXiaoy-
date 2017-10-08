// BFunction.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "BFunction.h"


// CBFunction

IMPLEMENT_DYNCREATE(CBFunction, CFormView)

CBFunction::CBFunction()
	: CFormView(CBFunction::IDD)
{

}

CBFunction::~CBFunction()
{
}

void CBFunction::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBFunction, CFormView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CBFunction 诊断

#ifdef _DEBUG
void CBFunction::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBFunction::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBFunction 消息处理程序


BOOL CBFunction::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO:  在此添加专用代码和/或调用基类

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CBFunction::OnPaint()
{
	
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(1, 1, 1));     //设置为黑色背景  

	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFormView::OnPaint()
}
