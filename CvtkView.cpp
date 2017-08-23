// CvtkView.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "CvtkView.h"

#include "vtkCallbackCommand.h"
// CvtkView

IMPLEMENT_DYNAMIC(CvtkView, CStatic)

CvtkView::CvtkView()
{

}

CvtkView::~CvtkView()
{
	
}



void CvtkView::PreSubclassWindow()
{

	CRect rect;

	GetClientRect(rect);
	m_Renderer = vtkSmartPointer<vtkRenderer>::New();

	m_RenderWindow = vtkSmartPointer<vtkRenderWindow>::New();

	m_RenderWindow->SetParentId(this->m_hWnd);  // vtkRenderWindow需要通过函数vtkRenderWindow::SetParentId()来建立与控件本身的关联

	m_RenderWindow->SetSize(rect.Width(), rect.Height());  // 显示与窗口同等大小的图片 

	m_RenderWindow->AddRenderer(m_Renderer);

	if (m_RenderWindow->GetInteractor() == NULL)
	{
		vtkSmartPointer<vtkRenderWindowInteractor> RenderWindowInteractor =vtkSmartPointer<vtkRenderWindowInteractor>::New();   //窗口交互 

		RenderWindowInteractor->SetRenderWindow(m_RenderWindow);  // 渲染窗口的交互 

		RenderWindowInteractor->Initialize();
	}

	m_RenderWindow->Start();   //开始渲染窗口 

	
}





BEGIN_MESSAGE_MAP(CvtkView, CStatic)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CvtkView, CStatic)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IvtkView 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {2921EF08-2E25-43DD-9271-E1110510E94F}
static const IID IID_IvtkView =
{ 0x2921EF08, 0x2E25, 0x43DD, { 0x92, 0x71, 0xE1, 0x11, 0x5, 0x10, 0xE9, 0x4F } };

BEGIN_INTERFACE_MAP(CvtkView, CStatic)
	INTERFACE_PART(CvtkView, IID_IvtkView, Dispatch)
END_INTERFACE_MAP()


// CvtkView 消息处理程序


