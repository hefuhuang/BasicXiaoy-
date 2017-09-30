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
