// C2dParamSeting.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "C2dParamSeting.h"
#include "afxdialogex.h"


// C2dParamSeting dialog

IMPLEMENT_DYNAMIC(C2dParamSeting, CPropertyPage)

C2dParamSeting::C2dParamSeting()
	: CPropertyPage(C2dParamSeting::IDD)
{

}

C2dParamSeting::~C2dParamSeting()
{
}

void C2dParamSeting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C2dParamSeting, CPropertyPage)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// C2dParamSeting message handlers


BOOL C2dParamSeting::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class

	return CPropertyPage::OnApply();
}


void C2dParamSeting::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect prect;
	GetClientRect(&prect);   //获取区域
	FillRect(GetDC()->GetSafeHdc(), &prect, CBrush(RGB(255, 255, 255)));     //填充颜色

	// TODO: Add your message handler code here
	// Do not call CPropertyPage::OnPaint() for painting messages
}
