// BFunction.cpp : ʵ���ļ�
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


// CBFunction ���

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


// CBFunction ��Ϣ�������
