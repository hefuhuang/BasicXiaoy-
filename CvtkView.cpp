// CvtkView.cpp : ʵ���ļ�
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

	m_RenderWindow->SetParentId(this->m_hWnd);  // vtkRenderWindow��Ҫͨ������vtkRenderWindow::SetParentId()��������ؼ�����Ĺ���

	m_RenderWindow->SetSize(rect.Width(), rect.Height());  // ��ʾ�봰��ͬ�ȴ�С��ͼƬ 

	m_RenderWindow->AddRenderer(m_Renderer);

	if (m_RenderWindow->GetInteractor() == NULL)
	{
		vtkSmartPointer<vtkRenderWindowInteractor> RenderWindowInteractor =vtkSmartPointer<vtkRenderWindowInteractor>::New();   //���ڽ��� 

		RenderWindowInteractor->SetRenderWindow(m_RenderWindow);  // ��Ⱦ���ڵĽ��� 

		RenderWindowInteractor->Initialize();
	}

	m_RenderWindow->Start();   //��ʼ��Ⱦ���� 

	
}





BEGIN_MESSAGE_MAP(CvtkView, CStatic)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CvtkView, CStatic)
END_DISPATCH_MAP()

// ע��: ������� IID_IvtkView ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {2921EF08-2E25-43DD-9271-E1110510E94F}
static const IID IID_IvtkView =
{ 0x2921EF08, 0x2E25, 0x43DD, { 0x92, 0x71, 0xE1, 0x11, 0x5, 0x10, 0xE9, 0x4F } };

BEGIN_INTERFACE_MAP(CvtkView, CStatic)
	INTERFACE_PART(CvtkView, IID_IvtkView, Dispatch)
END_INTERFACE_MAP()


// CvtkView ��Ϣ�������


