#pragma once
#include <iostream>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSphereSource.h>
#include <vtkElevationFilter.h>
#include <vtkVectorText.h>
#include <vtkCommand.h>
#include <vtkAutoInit.h>

#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkVolumeRayCastCompositeFunction.h"
#include "vtkVolumeRayCastMapper.h"
#include "vtkVolume.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkImageCast.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkBMPReader.h"
#include "vtkVolume16Reader.h"
#include "vtkPNGReader.h"
#include "vtkJPEGReader.h"
#include "vtkImageShrink3D.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "vtkContourFilter.h"
#include "vtkDecimatePro.h" 
#include "vtkSmoothPolyDataFilter.h"
#include "vtkPolyDataNormals.h"
#include "vtkStripper.h"
#include "vtkSphereSource.h"
#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkParticleReader.h"
#include "vtkOutputWindow.h"
#include "vtkObject.h"
#include "vtkFileOutputWindow.h"
#include "afxcmn.h"

/////////////////////////////////////
#include "vtkImageActor.h"
#include "vtkVersion.h"
#include "vtkImageMapper3D.h"
#include "vtkInteractorStyleImage.h"
#include <vtkRenderer.h>
#include "vtkExtractVOI.h"
#include "vtkMarchingCubes.h"
#include "vtkStructuredPointsReader.h" 
#include "vtkGPUVolumeRayCastMapper.h"
#include "vtkLODProp3D.h"
#include "vtkImageDataGeometryFilter.h"
#include "vtkVolumeRayCastIsosurfaceFunction.h"
#include "vtkHedgeHog.h"
#include "vtkImageShrink3D.h" 
#include "vtkUnstructuredGridReader.h"
#include "vtkDataSetMapper.h"
#include "vtkPolyDataReader.h" 
#include "vtkGenericDataObjectReader.h"
#include "vtkStructuredGridReader.h"
#include "vtkImageData.h"
#include "vtkDataReader.h"
#include "vtkGraphReader.h" 
#include "vtkXMLUnstructuredGridReader.h"
#include "vtkVolume16Reader.h"
#include "vtkDataSetReader.h"
#include "vtkAbstractVolumeMapper.h"
#include "vtkAbstractMapper3D.h"
#include "vtkAbstractPointLocator.h" 

#include "vtkTIFFReader.h"             
#include "vtkCamera.h"                    
#include "vtkActor.h"                     
#include "vtkProperty.h" 
#include "vtkSmartPointer.h"

#include "vtkCylinderSource.h"
#include "vtkInteractorStyleTrackballCamera.h" 
#include "vtkjpeg\jpeglib.h"
#include "vtk_tiff.h"
#include "vtkPolyDataMapper.h"            
#include "CvtkView.h"
#include "vtkImageReader2Factory.h"
#include "vtkWindowLevelLookupTable.h"  
#include "vtkImageMapToColors.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkPolyDataMapper.h"
#include "vtkConeSource.h"   
#include "vtkImageMapper.h"
#include "vtkActor2D.h"
#include "vtkRenderingOpenGL2ObjectFactory.h"
#include "vtkRenderingOpenGL2Module.h" 
#include "vtkDICOMImageReader.h"

#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkVolumeRayCastCompositeFunction.h"
#include "vtkVolumeRayCastMapper.h"
#include "vtkVolume.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkImageCast.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkBMPReader.h"
#include "vtkVolume16Reader.h"
#include "vtkPNGReader.h"
#include "vtkJPEGReader.h"
#include "vtkImageShrink3D.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "vtkContourFilter.h"
#include "vtkDecimatePro.h" 
#include "vtkSmoothPolyDataFilter.h"
#include "vtkPolyDataNormals.h"
#include "vtkStripper.h"
#include "vtkAxesActor.h"
#include "vtkOrientationMarkerWidget.h"
#include "vtkSmartVolumeMapper.h"
#include "vtkimageActor.h"
#include "vtkMarchingCubes.h"
#include "vtkMergePoints.h" 
#include "vtkVectorNorm.h"
#include "vtkFixedPointVolumeRayCastMapper.h"
#include "vtkInteractorEventRecorder.h" 
#include "vtkColorTransferFunction.h"
#include "vtkGPUVolumeRayCastMapper.h"
#include "vtkImageData.h"

//void* mutex;
//void* handler_thread = 0;

//using namespace std; 
 class RegenvtkColor : public vtkCommand
{
public:
	/*static RegenvtkColor* New();*/
	RegenvtkColor();
	~RegenvtkColor();
	//void setVolumeOpacity(vtkSmartPointer<vtkPiecewiseFunction>opacityTransferFunction);
	//void setVolumecolor(vtkSmartPointer<vtkColorTransferFunction>color);
	//void SetVolumeProperty(vtkSmartPointer<vtkVolumeProperty> volumeProperty);
	virtual void Execute(vtkObject* caller,unsigned long eventId,void* calldata);

	unsigned long ProcessvtkThread();
	bool FinishVtkThread();
//	bool operator +(const vtkVolume& volume1, const vtkVolume& volume2);

private:   //vtk 变量  
	//vtk 变量  
	//vtkSmartPointer<vtkPiecewiseFunction>m_opacityTransferFunction;
	//vtkSmartPointer<vtkColorTransferFunction>m_color;
	//vtkSmartPointer<vtkVolumeProperty>m_volumeProperty;

	//vtkSmartPointer<vtkStructuredPointsReader> StruVtkreader;
	//vtkSmartPointer<vtkTIFFReader> TiffReader;
	//vtkSmartPointer<vtkParticleReader> readerP;
	//vtkSmartPointer<vtkImageReader> reader;
	//vtkSmartPointer<vtkImageReader2> reader2;
	////	vtkMetaImageReader *readerM;
	//vtkSmartPointer<vtkPolyData> ployData;
	//vtkSmartPointer<vtkCamera> camera;
	//vtkSmartPointer<vtkImageCast> readerImageCast;
	//vtkSmartPointer<vtkRenderer> ren;
	////vtkRenderWindow* renWin;
	////vtkRenderWindowInteractor* iren;

	//vtkSmartPointer<vtkWin32OpenGLRenderWindow>renWin;
	//vtkSmartPointer<vtkWin32RenderWindowInteractor> iren;

	////vtkRenderWindowInteractor *iren; 
	//vtkSmartPointer<vtkVolumeProperty> volumeProperty;  //体绘器属性 
	//vtkSmartPointer<vtkVolumeRayCastIsosurfaceFunction> surfaceFunction;  //等值面绘制函数
	//vtkSmartPointer<vtkVolumeRayCastCompositeFunction> compositeFunction;  // 合成体绘制函数

	//vtkSmartPointer<vtkVolumeRayCastMapper> VolMapper; //定义绘制者
	//vtkSmartPointer<vtkSmartVolumeMapper> SmvoluMapper;
	//vtkSmartPointer<vtkVolume> volume; //表示透示图中的一组三维数据
	//vtkSmartPointer<vtkAxesActor> axes;
	//vtkSmartPointer<vtkOrientationMarkerWidget> widget;
	//vtkSmartPointer<vtkPolyDataMapper> ploymapper;
	//vtkSmartPointer<vtkMapper> mapper;
	//vtkSmartPointer<vtkActor> actor;
	//vtkSmartPointer<vtkImageActor> imageActor;
	//vtkSmartPointer<vtkContourFilter>  Extract;
	//vtkSmartPointer<vtkPolyDataNormals> Poly;
	//vtkSmartPointer<vtkInteractorStyleTrackballCamera> style;//交互摄像机
	//vtkSmartPointer<vtkStripper> strip;
	//vtkSmartPointer<vtkPiecewiseFunction> opacityTransferFunction; // 一维分段函数转换 
	//vtkSmartPointer<vtkFileOutputWindow> fileOutputWindow;
	//vtkSmartPointer<vtkOutputWindow> OutPutWin;
	////vtkScalarBarActor *scalarBar;
	//vtkSmartPointer<vtkImageViewer2> viewer2;
	//vtkSmartPointer<vtkExtractVOI>   ExtractVOI;
	//vtkSmartPointer<vtkMarchingCubes>  MarchCube;
	//vtkSmartPointer<vtkLODActor> LodActor;
	//vtkSmartPointer<vtkMergePoints> locator;
	//vtkSmartPointer<vtkVolume16Reader> p16reader;
	//vtkSmartPointer<vtkVectorNorm> pVectorNormal;
	//vtkSmartPointer<vtkStructuredPointsReader> vtkrender;
	//vtkSmartPointer<vtkGPUVolumeRayCastMapper>  hiresMapper;
	//vtkSmartPointer<vtkLODProp3D> prop;
	//vtkSmartPointer<vtkColorTransferFunction> color;
	//vtkSmartPointer<vtkPiecewiseFunction> gradient;
	//vtkSmartPointer<vtkImageShrink3D> render3D;
	//vtkSmartPointer<vtkInformation> vtkinfo;
	//vtkSmartPointer<vtkPolyDataReader> vtkGridReader;
	//vtkSmartPointer<vtkDataSetMapper> mapperdata;

};

