#include "stdafx.h"
#include "RegenvtkColor.h"



//RegenvtkColor* New()
//{
//	RegenvtkColor *cb = new RegenvtkColor;
//	return cb;
//}
RegenvtkColor::RegenvtkColor()
{
}

RegenvtkColor::~RegenvtkColor()
{
   
	//ExtractVOI->Delete();
	//axes->Delete();
	//widget->Delete();
	//// ÊÍ·Åvtk¿Õ¼ä 
	//ren->Delete();
	//renWin->Delete();
	//iren->Delete();
	//readerImageCast->Delete();
	//reader->Delete();
	//volumeProperty->Delete();
	//compositeFunction->Delete();
	//volume->Delete();
	//VolMapper->Delete();
	//ploymapper->Delete();
	//style->Delete();
	//readerP->Delete();
	//TiffReader->Delete();
	//SmvoluMapper->Delete();
	//opacityTransferFunction->Delete();
	//fileOutputWindow->Delete();
	////OutPutWin->Delete();
	//imageActor->Delete();
	//reader2->Delete();
	//viewer2->Delete();
	//ployData->Delete();
	//LodActor->Delete();
	//MarchCube->Delete();
	//camera->Delete();
	//locator->Delete();
	//p16reader->Delete();
	//pVectorNormal->Delete();
	//vtkrender->Delete();
	//prop->Delete();
	//hiresMapper->Delete();
	//color->Delete();
	//surfaceFunction->Delete();
	//gradient->Delete();
	//render3D->Delete();
	//vtkGridReader->Delete();
	//mapperdata->Delete();
	////readerM->Delete();
	//if (NULL != actor)
	//{
	//	actor->Delete();
	//}
}

void RegenvtkColor::Execute(vtkObject* caller, unsigned long eventId, void* callData)
{ 
	vtkSmartPointer<vtkRenderWindowInteractor>iren = static_cast<vtkRenderWindowInteractor*>(caller);
	//m_volumeProperty = reinterpret_cast<vtkVolumeProperty* >(caller);
	//	
	//m_volumeProperty->SetColor(m_color);
	//m_volumeProperty->SetScalarOpacity(m_opacityTransferFunction);


	//vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
	//volume->SetProperty(m_volumeProperty);
	
}
//
//void RegenvtkColor::SetVolumeProperty(vtkSmartPointer<vtkVolumeProperty> volumeProperty)
//{
//	m_volumeProperty=volumeProperty;
//}
//
//
//void RegenvtkColor::setVolumeOpacity(vtkSmartPointer<vtkPiecewiseFunction>opacityTransferFunction)
//{
//	m_opacityTransferFunction = opacityTransferFunction;
//}
//
//
//void RegenvtkColor::setVolumecolor(vtkSmartPointer<vtkColorTransferFunction>color)
//{
//	m_color = color;
//}