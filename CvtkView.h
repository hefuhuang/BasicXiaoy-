
#pragma once
#include <vtkTIFFReader.h>
#include "vtkRenderWindow.h"              
#include "vtkCamera.h"                    
#include "vtkActor.h"                     
#include "vtkRenderer.h"  
#include "vtkProperty.h" 
#include "vtkSmartPointer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkImageViewer2.h"
#include "vtkCylinderSource.h"
#include "vtkInteractorStyleTrackballCamera.h" 

#include "vtkjpeg\jpeglib.h"
#include "vtkConeSource.h"   
#include "vtkPolyDataMapper.h"            
#include "vtkInteractionImageModule.h"
// CvtkView


class CvtkView : public CView
{
	DECLARE_DYNAMIC(CvtkView)

public:
	CvtkView();
	virtual ~CvtkView();

	virtual void PreSubclassWindow();

	//virtual void OnPaint();

	vtkRenderer* GetRenderer();

	//virtual void OnDraw(CDC* pDC);  // overridden to draw this view



private:
	vtkRenderer* m_Renderer;
	vtkRenderWindow* m_RenderWindow; 


protected:

	DECLARE_MESSAGE_MAP()

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


