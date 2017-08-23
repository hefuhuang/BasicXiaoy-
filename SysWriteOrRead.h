#pragma once
#include <functional>   // STl±ê×¼¿â 
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "glaux.h"
#include "glut.h"
#include "CvImgCtrl.h"

//using namespace std;
class SysWriteOrRead
{
	
public:
	SysWriteOrRead();
	~SysWriteOrRead();

	void WriteSys();
	void ReadSys();
	
private:
	cv::Point StartPoint;
	cv::Point EndPoint;

};

