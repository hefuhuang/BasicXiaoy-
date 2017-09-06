// OCTProgressBar.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "OCTProgressBar.h"


// OCTProgressBar

IMPLEMENT_DYNAMIC(OCTProgressBar, CStatusBar)

OCTProgressBar::OCTProgressBar()
{

}

OCTProgressBar::~OCTProgressBar()
{
}


BEGIN_MESSAGE_MAP(OCTProgressBar, CStatusBar)
END_MESSAGE_MAP()

int OCTProgressBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	VERIFY(CStatusBar::OnCreate(lpCreateStruct) == 0);
	VERIFY(m_Progress.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_PROGRESSBar));
	return 0;
}
void OCTProgressBar::OnSize(UINT nType, int cx, int cy)
{
	CStatusBar::OnSize(nType, cx, cy);
	CRect rect;
	GetItemRect(1, &rect);
	m_Progress.MoveWindow(rect);
}

// OCTProgressBar 消息处理程序


