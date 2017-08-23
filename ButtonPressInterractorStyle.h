#pragma once
#include "vtkInteractorStyleTrackballCamera.h"

class ButtonPressInterractorStyle :public vtkInteractorStyleTrackballCamera
{
public:
	ButtonPressInterractorStyle();
	~ButtonPressInterractorStyle();
};

