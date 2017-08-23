// C3DParaSeting.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "C3DParaSeting.h"
#include "afxdialogex.h"


// C3DParaSeting dialog

IMPLEMENT_DYNAMIC(C3DParaSeting, CPropertyPage)

C3DParaSeting::C3DParaSeting()
	: CPropertyPage(C3DParaSeting::IDD)
{

}

C3DParaSeting::~C3DParaSeting()
{
}

void C3DParaSeting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C3DParaSeting, CPropertyPage)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// C3DParaSeting message handlers


BOOL C3DParaSeting::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class

	return CPropertyPage::OnApply();
}


void C3DParaSeting::OnPaint()
{
	CPaintDC dc(this); 
	
	CRect prect;
	GetClientRect(&prect);   //获取区域
	FillRect(GetDC()->GetSafeHdc(), &prect, CBrush(RGB(255, 255, 255)));     //填充颜色
	// device context for painting
	// TODO: Add your message handler code here
	// Do not call CPropertyPage::OnPaint() for painting messages
}
