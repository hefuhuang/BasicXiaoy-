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
	ON_WM_PAINT()
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


BOOL CBFunction::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO:  �ڴ����ר�ô����/����û���

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CBFunction::OnPaint()
{
	
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(1, 1, 1));     //����Ϊ��ɫ����  

	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
}
