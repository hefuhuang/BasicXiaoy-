
// MFC_OCTDlg.cpp : 实现文件
//
#include "stdafx.h"
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <chrono>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <vtkTIFFReader.h> 
#include <vtkImageData.h>
#include <vtkMetaImageReader.h>
#include "vtkSurfaceReconstructionFilter.h"
#include "vtkReverseSense.h"
#include "MFC_OCT.h"


#include "MFC_OCTDlg.h" 
#include "DlgParam.h"
#include "Dlg3DParam.h"
#include "afxdialogex.h"

using namespace std;
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif 

#define  MY_MSG WM_USER+2
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

bool flag = true;
bool flag3D = true;
bool flagAc = true;

bool GetLine = false;
bool GetBeginPoint = false;
static CvPoint BeginPoint = Point(0, 0); //初始化起始点
static CvPoint EndPoint = Point(0, 0); //初始化  
int Model3dStyle=0;
CRect GlobalRect; 

static UINT BASED_CODE indicators[] =
{
	ID_INDICATOR_NISH,
	ID_INDICATOR_TIME
};

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


//process ezch vedio Frame 
LRESULT CMFC_OCTDlg::onFrame(WPARAM wp, LPARAM lp)
{
	Mat frame(cvarrToMat((IplImage*)lp, false));
	return 0;
}

// CMFC_OCTDlg 对话框

CMFC_OCTDlg::CMFC_OCTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_OCTDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();  //体绘器属性 
	//color = vtkSmartPointer<vtkColorTransferFunction>::New();
	//gradient = vtkSmartPointer<vtkPiecewiseFunction>::New();
	//opacityTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New(); // 一维分段函数转换 
	//StruVtkreader = vtkSmartPointer<vtkStructuredPointsReader>::New();
	//volume = vtkSmartPointer<vtkVolume>::New(); //表示透示图中的一组三维数据
	//VolMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New(); //定义绘制者
	//ren = vtkSmartPointer<vtkRenderer>::New();
	//renWin = vtkSmartPointer<vtkWin32OpenGLRenderWindow>::New();
	//iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//axes = vtkSmartPointer<vtkAxesActor>::New();
	//widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
	//style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();//交互摄像机
	//camera = vtkSmartPointer <vtkCamera>::New();
	//client = vtkSmartPointer<vtkClientServerInterpreterInternals>::New();
}

CMFC_OCTDlg::~CMFC_OCTDlg()
{
	//StruVtkreader->FastDelete();
	////StruVtkreader->Delete();
	//volumeProperty->Delete();
	//opacityTransferFunction->Delete();
	//color->Delete();
	//VolMapper->RemoveAllInputConnections(0);
	//VolMapper->Delete();
	//camera->Delete();
	//axes->Delete();
	//widget->Delete();
	//volume->Delete();
	//ren->RemoveVolume(volume);
	//ren->Clear();
	//ren->FastDelete();
	//renWin->RemoveRenderer(ren);

//vtkSmartPointer<vtkClientServerInterpreterInternals>client = vtkSmartPointer<vtkClientServerInterpreterInternals>::New();
//iren->AddObserver(vtkCommand::AnyEvent,client);
//this->renWin->Finalize();
//this->iren->GetRenderWindow()->Render();
//Close the window
//this->iren->GetRenderWindow()->Finalize();
// Stop the interactor
//this->iren->TerminateApp();

	//if (nullptr != renWin)
	//{ 
 //    renWin->Delete();
	//}
	// //iren->RemoveAllObservers();
	//if (nullptr !=iren)
	//{
	// iren->Delete();
	//}
	//gradient->Delete();
	//style->Delete();
	//iren->SetRenderWindow(NULL);
} 

void CMFC_OCTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Xiaoy_STATIC, m_Picture);
	DDX_Control(pDX, IDC_EDITPX, m_EDITX);
	DDX_Control(pDX, IDC_EDITPY, m_EDITY);
	DDX_Control(pDX, IDC_EDITPZ, m_EDITZ);
	DDX_Control(pDX, IDC_SLIDER_LIFGT, mScrollLight);
	DDX_Control(pDX, IDC_SLIDER_Laser, mScrollLaser);
	DDX_Control(pDX, IDC_SLIDER_LIFGT3, mScrollGrayLevel);
	DDX_Control(pDX, IDC_COMB3dModel, mModel3DChioce);
	DDX_Control(pDX, IDC_STATIC_Vedio, m_ImageVedio);
}

BEGIN_MESSAGE_MAP(CMFC_OCTDlg, CDialogEx)
	ON_MESSAGE(MsgVideoFrame, onFrame)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_AddPicture, &CMFC_OCTDlg::OnBnClickedButtonAddpicture)
	ON_BN_CLICKED(IDC_BUTTON_3D, &CMFC_OCTDlg::OnBnClickedButton3d)
	ON_BN_CLICKED(IDC_BUTTON_Start, &CMFC_OCTDlg::OnBnClickedButtonStart)
	ON_MESSAGE(MY_MSG, &CMFC_OCTDlg::ReadMatShow)
	ON_BN_CLICKED(IDC_BUTTONParam, &CMFC_OCTDlg::OnBnClickedButtonparam)
	ON_BN_CLICKED(IDC_BUTTON_3DParam, &CMFC_OCTDlg::OnBnClickedButton3dparam)
	ON_WM_TIMER()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LIFGT, &CMFC_OCTDlg::OnNMCustomdrawSliderLifgt)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_Laser, &CMFC_OCTDlg::OnNMCustomdrawSliderLaser)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LIFGT3, &CMFC_OCTDlg::OnNMCustomdrawSliderLifgt3)

	ON_BN_CLICKED(IDC_BUTTON_Snippintool, &CMFC_OCTDlg::OnBnClickedButtonSnippintool)
	ON_CBN_SELCHANGE(IDC_COMB3dModel, &CMFC_OCTDlg::OnCbnSelchangeComb3dmodel)
	ON_WM_SIZE()
END_MESSAGE_MAP()
// CMFC_OCTDlg 消息处理程序

BOOL CMFC_OCTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CString strTime;
	CTime tm;
	tm = CTime::GetCurrentTime();         //获取当前系统时间
	strTime = tm.Format("%y/%m/%d %X");   //格式化系统时间。即使系统时 间按照Format中设置的格式显示
	SetDlgItemText(IDC_EDIT_ShowTime, strTime);        //初始化编辑框显示
	SetTimer(1, 1000, NULL);         //启动定时器

	mModel3DChioce.AddString(_T("3D模式四"));
	mModel3DChioce.AddString(_T("3D模式一"));
	mModel3DChioce.AddString(_T("3D模式二"));
	mModel3DChioce.AddString(_T("3D模式三"));
	
	mModel3DChioce.SetCurSel(0);

	GetDlgItem(IDC_STATIC_Vedio)->GetClientRect(&GlobalRect);
	//ShowWindow(SW_MAXIMIZE);

	m_Statusbar.Create(this);
	m_Statusbar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));  // set the number of status 
	CRect rect;
	GetClientRect(&rect);
	m_Statusbar.SetPaneInfo(0, ID_INDICATOR_NISH, SBPS_NORMAL, rect.Width() / 2);
	m_Statusbar.SetPaneInfo(1, ID_INDICATOR_TIME, SBPS_STRETCH, rect.Width() / 2);
	//在ping屏幕上绘制状态栏
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, ID_INDICATOR_TIME);

	SetWindowText(_T("regenovo"));

	GetClientRect(m_TotalRect);
	namedWindow("OCTShow", CV_WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("OCTShow");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC_Vedio)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CMFC_OCTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_OCTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);

		//////////////////////////////////////////
	}
	else
	{
		CRect rect;
		CPaintDC dc(this);
		m_Picture.GetClientRect(rect);
		dc.FillSolidRect(rect, RGB(1, 1, 1));     //设置为黑色背景  

		CWnd *pwnd = GetDlgItem(IDC_Xiaoy_STATIC);
		CDC *pDC = this->GetDC();
		this->DrawLine(pDC);
		////////////////////
		CDialogEx::OnPaint();
	}
} 

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_OCTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC_OCTDlg::OnBnClickedButtonAddpicture()
{ 
	RedrawWindow();
	if (true == flagAc)
	{
		flagAc = !flagAc;
		GetDlgItem(IDC_BUTTON_AddPicture)->SetWindowTextW(_T("CLOSE"));
		
		namedWindow("show", WINDOW_AUTOSIZE);
		HWND hWnd = (HWND)cvGetWindowHandle("show");
		HWND hParent = ::GetParent(hWnd);
		::SetParent(hWnd, GetDlgItem(IDC_STATIC_Vedio)->m_hWnd);
		::ShowWindow(hParent, SW_HIDE);

		AfxBeginThread(&ShowVedio, NULL);
		//Mat  img = imread("..//test//tiled.tif");
	}
	else{
		flagAc = !flagAc;
		GetDlgItem(IDC_BUTTON_AddPicture)->SetWindowTextW(_T("SCAN"));
		//WaitForMultipleObjects(1, handle, TRUE, INFINITE);
		UpdateData(true);
		RedrawWindow();
		destroyWindow("show");

	}
}

UINT ShowVedio(LPVOID mDParam)
{ 
	cv::setMouseCallback("show", GetTwoPoint, 0);
	double length=0, angle=0;
	calDistanceOfTwoPoint(BeginPoint, EndPoint, length, angle);

	while (true)
	{ 
		cv::Mat m_dst;
	cv::Mat img = imread("..//test//tiled.tif", 1);  //1:为原图颜色,0:为灰度图
	cv::line(img,BeginPoint,EndPoint,Scalar(255,0,0),2);   // 设置线粗与颜色
	waitKey(10);
	cv::Rect dst(GlobalRect.left, GlobalRect.top, GlobalRect.right, GlobalRect.bottom);
	cv::resize(img,m_dst, cv::Size(GlobalRect.Width(), GlobalRect.Height()));
	imshow("show", m_dst);
	if (true==flagAc)
		{
			break;
		}
	}
	return TRUE;
}

void calDistanceOfTwoPoint(cv::Point PointBegin,cv::Point PointEnd,double& length,double& angle)  // 传引用 length angle
{
	length = sqrt((PointEnd.x - PointBegin.x)*(PointEnd.x - PointBegin.x) + (PointEnd.y - PointBegin.y)*(PointEnd.y - PointBegin.y)); 
	angle = atan((PointEnd.y - PointBegin.y) / (PointEnd.x - PointBegin.x))*180/3.1415;  
}

void GetTwoPoint(int event, int x, int y, int flags, void* ustc)
{

	switch(event)
	{
		case CV_EVENT_LBUTTONDOWN:
			BeginPoint = Point(x,y);
			EndPoint = BeginPoint;
			GetBeginPoint = !GetBeginPoint;
			break;
		case CV_EVENT_MOUSEMOVE:
			if (GetBeginPoint && !GetLine)
			{
				EndPoint = Point(x,y);
			}
			break;
		case CV_EVENT_LBUTTONUP:

			GetLine = !GetLine;
			EndPoint = Point(x,y);
			break;
		default:
			break;
	}
}

void on_mouse(int event, int x, int y, int flags, void* ustc)   //opencv鼠标响应按钮 
{

	//if (!ustc)   //无正常响应直接退出  
	//	return;
	static CvPoint beginPoint;  // 记住加static
	static CvPoint endPoint;   
	char temp_1[20];
	/*//////////
	//初始点位置，若以任意点为起始点，则不需要这两个初始值
	*//////////
	//beginPoint = CvPoint(-1, -1);
	//endPoint = CvPoint(-1, -1);
	cv::Mat img;
	cv::Mat dest;

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:   //左键键按下
		{  
			dest.copyTo(img);
			beginPoint = CvPoint(x, y);
			//putText(img, temp_1, beginPoint, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255)); //初始点坐标
			cv::circle(img, beginPoint, 3, cvScalar(255, 0, 0), CV_FILLED, CV_AA, 0);   //显示初始点 
			imshow("show", img);	
			img.copyTo(dest);  
		}
	case EVENT_MOUSEMOVE:  //键移动
		{
			if (flags & CV_EVENT_FLAG_LBUTTON)
			{
				dest.copyTo(img);
				endPoint = CvPoint(x, y);
				sprintf(temp_1, "x:%d,y:%d", x, y);
				cv::putText(img, temp_1,endPoint, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255));
				cv::line(img, beginPoint, endPoint, cvScalar(0, 255, 0), 1, CV_AA, 0);
				imshow("show", img);
				// img.copyTo(dest);  
				break;
			}
			else
			{
				break;
			}
		}
	case CV_EVENT_LBUTTONUP:
	{       dest.copyTo(img);
			endPoint = CvPoint(x, y);
			sprintf(temp_1, "x:%d,y:%d", x, y);
			cv::putText(img, temp_1, CvPoint(x, y), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(0, 255, 255));
			cv::circle(img, endPoint, 3, cvScalar(255, 0, 0), CV_FILLED, CV_AA, 0);  // 显示线未点
			cv::line(img, beginPoint, endPoint, cvScalar(0, 255, 0), 1, CV_AA, 0);
			imshow("show", img);
			img.copyTo(dest);
			break;
		}

	default:
		break;
	}
	

}


void CMFC_OCTDlg::OnBnClickedButton3d()
{ 

	switch (Model3dStyle)
	{
	case 0:
		Model3Dstyledefault();
		break; 
	case 2: 
		Model3Dstyle1();
		break;
	default:
		Model3Dstyledefault();
		break;
	}

}

void CMFC_OCTDlg::Model3Dstyledefault()
{
	vtkObject::GlobalWarningDisplayOff();
	vtkSmartPointer<vtkGenericDataObjectReader> StruVtkreader = vtkSmartPointer<vtkGenericDataObjectReader>::New();
	vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
	vtkSmartPointer<vtkRenderer> ren = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkWin32OpenGLRenderWindow> renWin = vtkSmartPointer<vtkWin32OpenGLRenderWindow>::New();
	vtkSmartPointer<vtkWin32RenderWindowInteractor> iren = vtkSmartPointer<vtkWin32RenderWindowInteractor>::New();
	vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();  //体绘器属性 
	vtkSmartPointer<vtkVolumeRayCastIsosurfaceFunction> surfaceFunction = vtkSmartPointer<vtkVolumeRayCastIsosurfaceFunction>::New();  //等值面绘制函数
	vtkSmartPointer<vtkVolumeRayCastCompositeFunction> compositeFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();  // 合成体绘制函数
	vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New(); //表示透示图中的一组三维数据
	vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New();
	vtkSmartPointer<vtkOrientationMarkerWidget> widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
	vtkSmartPointer<vtkContourFilter> Extract = vtkSmartPointer<vtkContourFilter>::New();
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();//交互摄像机
	vtkSmartPointer<vtkStripper> strip = vtkSmartPointer<vtkStripper>::New();
	vtkSmartPointer<vtkPiecewiseFunction> opacityTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New(); // 一维分段函数转换 
	vtkSmartPointer<vtkExtractVOI> ExtractVOI = vtkSmartPointer<vtkExtractVOI>::New();
	vtkSmartPointer<vtkMarchingCubes> MarchCube = vtkSmartPointer<vtkMarchingCubes>::New();
	vtkSmartPointer<vtkDataSetMapper> mapperdata = vtkSmartPointer<vtkDataSetMapper>::New();
	vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
	vtkSmartPointer<vtkPiecewiseFunction> gradient = vtkSmartPointer<vtkPiecewiseFunction>::New();

	vtkSmartPointer<vtkGPUVolumeRayCastMapper> VolMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New(); 

	vtkSmartPointer<vtkClientServerInterpreterInternals>client = vtkSmartPointer<vtkClientServerInterpreterInternals>::New();
	//vtkNew<vtkImagData> transferFunc; 

	renWin->StereoCapableWindowOff();
	renWin->GlobalWarningDisplayOff();
	if (true == flag3D)
	{
		//actor->SetGlobalWarningDisplay(0);
		double scalarRange[2];
		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
		char* vtkfilePath = "../test/volume.vtk";
		StruVtkreader->SetFileName(vtkfilePath);
		StruVtkreader->Update();

		//double bounds[6];
		//StruVtkreader->GetOutput()->GetBounds(bounds);
		double spacing[3];
		double distance = spacing[0];
		if (distance>spacing[1])
		{
			distance = spacing[1];
		}
		if (distance>spacing[2])
		{
			distance = spacing[2];
		}
		distance = distance / 2.0;
		VolMapper->SetSampleDistance(static_cast<float>(distance));
		VolMapper->SetBlendModeToComposite();
		VolMapper->SetInputConnection(StruVtkreader->GetOutputPort());
		VolMapper->GetInput()->GetScalarRange(scalarRange);

		volumeProperty->ShadeOff();
		volumeProperty->SetAmbient(0.3);   // 周围的光照环境 
		volumeProperty->SetDiffuse(0.7);   //扩散光系数
		volumeProperty->SetSpecular(0.0);  //反射光系数
		volumeProperty->SetSpecularPower(50.0);  //反射度
		volumeProperty->SetInterpolationTypeToLinear();
		//不透明度映射函数
		double opacityLevel = 120;
		double opacityWindow = 240;
		//灰度值与不透明度  为零则是全透明 为1 则为完全不透明 
		//opacityTransferFunction->AddSegment(-69, 0, 89, 1);
		opacityTransferFunction->AddPoint(scalarRange[0], 0);
		opacityTransferFunction->AddPoint(scalarRange[1], 1);
		volumeProperty->SetScalarOpacity(opacityTransferFunction.GetPointer());

		color->RemoveAllPoints();
		color->AddRGBPoint(scalarRange[0], 0, 0, 0);
		color->AddRGBPoint(scalarRange[1], 1.0, 1, 1);

		volumeProperty->SetColor(color.GetPointer());
		//volumeProperty->SetTransferMode(vtkVolumeProperty::TF_1D);
		//volumeProperty->SetTransferMode(vtkVolumeProperty::TF_2D);

		volume->SetMapper(VolMapper.GetPointer());
		volume->SetProperty(volumeProperty.GetPointer());

		renWin->SetParentId(m_hWnd);
		//ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
		ren->AddVolume(volume.GetPointer());
		volume->FastDelete();
		ren->SetActiveCamera(camera.GetPointer());
		ren->SetBackground(1, 1, 1);
		ren->ResetCamera();
		if (nullptr != renWin)
		{
			renWin->RemoveRenderer(ren);
		}
		renWin->AddRenderer(ren);
		//iren->CreateRepeatingTimer();
		iren->SetInteractorStyle(style.GetPointer());
		iren->SetRenderWindow(renWin);
		CRect rect;
		GetClientRect(&rect);
		CRect prect;
		m_Picture.GetClientRect(&prect);
		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
		renWin->Render();  ////窗口进行绘制
		renWin->MakeCurrent();
		axes->SetXAxisLabelText("X");
		axes->SetYAxisLabelText("Y");
		axes->SetZAxisLabelText("Z");
		//widget = vtkOrientationMarkerWidget::New();
		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
		widget->SetOrientationMarker(axes.GetPointer());
		widget->SetInteractor(iren.GetPointer());
		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
		widget->SetEnabled(true);
		//widget->InteractiveOff();
		iren->Initialize();
		iren->AddObserver(vtkCommand::KeyPressEvent,client);
		iren->Start();   //初始化并进行交互绘制
		ren->ResetCameraClippingRange();
		recorder->SetInteractor(iren.GetPointer());   //生成渲染日志 
		recorder->SetFileName("vtkInteractorEventRecorder.log");
		recorder->On();
		recorder->Record();
		return ;
	    
	}
	else{

		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));

	
	}
}

void CMFC_OCTDlg::Model3Dstyle1()
{
	vtkObject::GlobalWarningDisplayOff();
	vtkStructuredPointsReader* StruVtkreader = vtkStructuredPointsReader::New();
	vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();  //体绘器属性 
	vtkVolumeRayCastIsosurfaceFunction* surfaceFunction = vtkVolumeRayCastIsosurfaceFunction::New();  //等值面绘制函数
	vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();  // 合成体绘制函数
	vtkGPUVolumeRayCastMapper *VolMapper = vtkGPUVolumeRayCastMapper::New(); //定义绘制者
	vtkPiecewiseFunction* gradient = vtkPiecewiseFunction::New();
	vtkColorTransferFunction* color = vtkColorTransferFunction::New();
	vtkVolume *volume = vtkVolume::New(); //表示透示图中的一组三维数据
	vtkAxesActor* axes = vtkAxesActor::New();
	vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New(); // 一维分段函数转换 
	vtkInteractorStyleTrackballCamera *style = vtkInteractorStyleTrackballCamera::New();//交互摄像机
	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();
	vtkWin32OpenGLRenderWindow *renWin = vtkWin32OpenGLRenderWindow::New();
	vtkWin32RenderWindowInteractor *iren = vtkWin32RenderWindowInteractor::New();
	vtkPolyDataReader* vtkGridReader = vtkPolyDataReader::New();
	vtkDataSetMapper* mapperdata = vtkDataSetMapper::New();
	vtkCamera* camera = vtkCamera::New();
	vtkStripper* strip = vtkStripper::New();
	vtkContourFilter*  Extract = vtkContourFilter::New();
	vtkExtractVOI*   ExtractVOI = vtkExtractVOI::New();
	vtkMultiThreader *threadEnd = vtkMultiThreader::New();
	vtkRenderer* ren = vtkRenderer::New();
	renWin->StereoCapableWindowOff();
	renWin->GlobalWarningDisplayOff();
	if (true == flag3D)
	{
		double scalarRange[2];
		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
		char* vtkfilePath = "../test/volume.vtk";
		StruVtkreader->SetFileName(vtkfilePath);
		StruVtkreader->Update();

		double spacing[3];
		double distance = spacing[0];
		if (distance > spacing[1])
		{
			distance = spacing[1];
		}
		if (distance > spacing[2])
		{
			distance = spacing[2];
		}
		distance = distance / 2.0;
		VolMapper->SetSampleDistance(static_cast<float>(distance));
		VolMapper->SetBlendModeToComposite();
		VolMapper->SetInputConnection(StruVtkreader->GetOutputPort());
		VolMapper->GetInput()->GetScalarRange(scalarRange);

		volumeProperty->ShadeOff();
		volumeProperty->SetAmbient(0.3);   // 周围的光照环境 
		volumeProperty->SetDiffuse(0.7);   //扩散光系数
		volumeProperty->SetSpecular(0.0);  //反射光系数
		volumeProperty->SetSpecularPower(50.0);  //反射度
		volumeProperty->SetInterpolationTypeToLinear();
		//不透明度映射函数
		//灰度值与不透明度  为零则是全透明 为1 则为完全不透明 
		//opacityTransferFunction->AddSegment(-69, 0, 89, 1);
		opacityTransferFunction->AddPoint(scalarRange[0], 0);
		opacityTransferFunction->AddPoint(scalarRange[1], 1);
		volumeProperty->SetScalarOpacity(opacityTransferFunction);
		//gradient->AddPoint(0, 1, 0.0, 0);
		//gradient->AddPoint(-69.8, 0, -8.037, 0.414);
		//gradient->AddPoint(-8.037, 0.414, 89.3, 1);
		//volumeProperty->SetGradientOpacity(gradient);
		//opacityTransferFunction->AddSegment(opacityLevel - 0.5*opacityWindow, 0.2, // 0.0, 0.01
		//	opacityLevel + 0.5*opacityWindow, 10.0); // 1.0, 0.01
		//opacityTransferFunction->AddSegment(0, -1, 255, 13);     // 设置灰度与透明度的线性方程函数 
		//透明度设置 
		//volumeProperty->SetGradientOpacity(gradient);
		//color->AddRGBSegment(1, 0.1, 0.0, 0.0, 
		//	                 255, 1.0, 1.0, 0.0);   // 设置渲染的色彩 
		//颜色映射函数
		//color->AddRGBPoint(-69, 0, 0, 0); //灰度值及RGB颜色值
		//color->AddRGBPoint(33.9152, 0, 0,0);
		//color->AddRGBPoint(43.0, 0.865, 0.865,0.865);
		//color->AddRGBPoint(89.345, 1, 1, 1);
		color->RemoveAllPoints();
		color->AddRGBPoint(scalarRange[0], 0, 0, 0);
		color->AddRGBPoint(scalarRange[1], 1.0, 1, 1);
		volumeProperty->SetColor(color);

		volume->SetMapper(VolMapper);
		volume->SetProperty(volumeProperty);

		renWin->SetParentId(m_hWnd);
		//ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
		ren->AddVolume(volume);
		volume->FastDelete();
		ren->SetActiveCamera(camera);
		ren->SetBackground(1, 1, 1);
		ren->ResetCamera();
		renWin->AddRenderer(ren);
		//iren->CreateRepeatingTimer();
		iren->SetInteractorStyle(style);
		iren->SetRenderWindow(renWin);
		CRect rect;
		GetClientRect(&rect);
		CRect prect;
		m_Picture.GetClientRect(&prect);
		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
		renWin->Render();  ////窗口进行绘制
		renWin->MakeCurrent();
		axes->SetXAxisLabelText("X");
		axes->SetYAxisLabelText("Y");
		axes->SetZAxisLabelText("Z");
		//widget = vtkOrientationMarkerWidget::New();
		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
		widget->SetOrientationMarker(axes);
		axes->Delete();
		widget->SetInteractor(iren);
		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
		widget->SetEnabled(true);
		//widget->InteractiveOff();
		iren->Initialize();
		//iren->Start();   //初始化并进行交互绘制
		ren->ResetCameraClippingRange();

		recorder->SetInteractor(iren);   //生成渲染日志 
		recorder->SetFileName("vtkInteractorEventRecorder.log");
		recorder->On();
		recorder->Record();
	}
	else{

		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
		// 释放vtk空间 
		StruVtkreader->FastDelete();
		//StruVtkreader->Delete();
		volumeProperty->Delete();
		opacityTransferFunction->Delete();
		color->Delete();
		VolMapper->RemoveAllInputConnections(0);
		VolMapper->Delete();
		camera->Delete();
		ExtractVOI->Delete();
		axes->Delete();
		widget->Delete();
		volume->Delete();
		ren->RemoveVolume(volume);
		ren->Clear();
		ren->FastDelete();
		renWin->RemoveRenderer(ren);
		renWin->Delete();
		iren->RemoveAllObservers();
		iren->Delete();
		mapperdata->Delete();
		gradient->Delete();
		surfaceFunction->Delete();
		style->Delete();
		UpdateData(true);
		RedrawWindow();
		iren->SetRenderWindow(NULL);
		recorder->Off();
	}

}

int CMFC_OCTDlg::Model3Dstyle2()
{ 
	vtkObject::GlobalWarningDisplayOff(); 

	vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();  //体绘器属性 
	vtkSmartPointer<vtkColorTransferFunction>color = vtkSmartPointer<vtkColorTransferFunction>::New();
	vtkSmartPointer<vtkPiecewiseFunction>gradient = vtkSmartPointer<vtkPiecewiseFunction>::New();
	vtkSmartPointer<vtkPiecewiseFunction>opacityTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New(); // 一维分段函数转换 
	vtkSmartPointer<vtkStructuredPointsReader>StruVtkreader = vtkSmartPointer<vtkStructuredPointsReader>::New();
	vtkSmartPointer<vtkVolume>volume = vtkSmartPointer<vtkVolume>::New(); //表示透示图中的一组三维数据
	vtkSmartPointer<vtkGPUVolumeRayCastMapper>VolMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New(); //定义绘制者
	vtkSmartPointer<vtkRenderer>ren = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkWin32OpenGLRenderWindow>renWin = vtkSmartPointer<vtkWin32OpenGLRenderWindow>::New();
	vtkSmartPointer<vtkRenderWindowInteractor>iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkAxesActor>axes = vtkSmartPointer<vtkAxesActor>::New();
	vtkSmartPointer<vtkOrientationMarkerWidget>widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
	vtkSmartPointer<vtkInteractorStyleTrackballCamera>style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();//交互摄像机
	vtkSmartPointer <vtkCamera>camera = vtkSmartPointer <vtkCamera>::New();
	vtkSmartPointer<vtkClientServerInterpreterInternals>client = vtkSmartPointer<vtkClientServerInterpreterInternals>::New();
	vtkSmartPointer<vtkExtractVOI> ExtractVOI = vtkSmartPointer<vtkExtractVOI>::New();
	//vtkMFCWindow* vtkMfcwin = new vtkMFCWindow(this->GetDlgItem(IDD_MFC_OCT_DIALOG));
	//vtkSmartPointer<vtkCallbackCommand> MouseCallBack = vtkSmartPointer<vtkCallbackCommand>::New();
	//vtkSmartPointer<vtkMFCWindow> renWin = vtkSmartPointer<vtkMFCWindow>::New();
	if (true == flag3D)
	{
		
		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
		
		int TotalExten[6];
		double scalarRange[2];
		char* vtkfilePath = "../test/volume.vtk";
		StruVtkreader->SetFileName(vtkfilePath);
		StruVtkreader->Update();
		StruVtkreader->GetOutput()->GetExtent(TotalExten);

		int XExtent[6] = { 1, TotalExten[1]-1, 1, 2, 1, TotalExten[5]-1};
		int YExtent[6] = { 0, 500, 0, 1, 0, 500 };
		int ZExtent[6] = { 0, 500, 0, 1, 0, 500 };
		ExtractVOI->SetInputConnection(StruVtkreader->GetOutputPort());
		//xtractXMin ,extractXMax ,extractYMin ,extractYMax ,extractZMin ,extractZMax
		ExtractVOI->SetVOI(XExtent);   //Extract special part  
		ExtractVOI->Update();

		double spacing[3] = {10,10,10};
		double distance = spacing[0];
		if (distance > spacing[1])
		{
			distance = spacing[1];
		}
		if (distance > spacing[2])
		{
			distance = spacing[2];
		}
		distance = distance / 2.0;
		VolMapper->GetGradientMagnitudeBias();
		VolMapper->SetInputConnection(StruVtkreader->GetOutputPort());
		VolMapper->GetInput()->GetScalarRange(scalarRange);

		volumeProperty->ShadeOn();
		volumeProperty->SetAmbient(0.3);   // 周围的光照环境 
		volumeProperty->SetDiffuse(0.7);   //扩散光系数
		volumeProperty->SetSpecular(0.0);  //反射光系数
		volumeProperty->SetSpecularPower(50.0);  //反射度
		volumeProperty->SetInterpolationTypeToLinear();
		//不透明度映射函数

		opacityTransferFunction->AddPoint(scalarRange[0], -3);
		opacityTransferFunction->AddPoint(scalarRange[1], 2);
		volumeProperty->SetScalarOpacity(opacityTransferFunction);

		color->AddRGBPoint(scalarRange[0], 0, 0, 0);
		color->AddRGBPoint(scalarRange[1]/2,0, 0, 0);
		color->AddRGBPoint(scalarRange[1], 1.0, 1, 1);
		volumeProperty->SetColor(color);

		volume->SetMapper(VolMapper);
		volume->SetProperty(volumeProperty);

		//vtkSmartPointer <RegenvtkColor> VolumePro = vtkSmartPointer<RegenvtkColor>:: New();
		//volume->AddObserver(vtkCommand::InteractionEvent, VolumePro);

		 renWin->Register(nullptr);
		// renWin->SetWindowId(::GetParent( GetSafeHwnd()));
		 renWin->SetParentId(m_hWnd);

		//ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
		ren->AddVolume(volume);
		volume->FastDelete();
		ren->SetActiveCamera(camera);
		ren->SetBackground(1, 1, 1);
		ren->ResetCamera();
		renWin->AddRenderer(ren);
		//vtkMfcwin->GetRenderWindow()->AddRenderer(ren);
		iren->SetInteractorStyle(style);
		iren->SetRenderWindow( renWin);
		iren->Initialize();

		CRect rect;
		GetClientRect(&rect);
		CRect prect;
		m_Picture.GetClientRect(&prect);
		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
		// renWin->UnRegister(nullptr);
		renWin->Render();  //draw window 
		renWin->MakeCurrent();
		axes->SetXAxisLabelText("X");
		axes->SetYAxisLabelText("Y");
		axes->SetZAxisLabelText("Z");

		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
		widget->SetOrientationMarker(axes);
		axes->Delete();
		widget->SetInteractor( iren);
		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
		widget->SetEnabled(true);

		//int timerId =   iren->CreateRepeatingTimer(100);
		//MouseCallBack->SetCallback(KeyPressCallbackFunction);
		iren->AddObserver(vtkCommand::KeyPressEvent, client);
		// iren->AddObserver(vtkCommand::MouseMoveEvent, client);
		iren->Start();   

	}
	else
	{
		flag3D = !flag3D;
		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
		UpdateData(true);
		iren->EnableRenderOff();
		iren->DestroyTimer();
		iren->ExitCallback();
	
		//renWin->RemoveRenderer(ren);
		//renWin->GetMapped();
		//renWin->Finalize();
		//renWin->UnRegister(nullptr);
		//renWin->Delete();
		//RedrawWindow();
	}

	return EXIT_SUCCESS;
}

void KeyPressCallbackFunction(vtkObject* caller, long unsigned int eventId, void* clientData, void* callData)
{ 

	vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	if (true==flag3D)
	{ 
	iren = static_cast<vtkRenderWindowInteractor*>(caller);
	iren->GetRenderWindow()->Render();
	// Close the window
	iren->GetRenderWindow()->Finalize();
	// Stop the interactor
	iren->TerminateApp();
	}
	else
	{
		return;
	}

}

//
//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//
//
//	if (true == flag3D)
//	{
//
//		actor->SetGlobalWarningDisplay(0);
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
//
//		char* RawfilePath = "../test/volume.raw";  //数据地址 
//
//		TiffReader->SetFileName(RawfilePath);
//		TiffReader->SetDataExtent(0,400,0,400,0,100); 
//		TiffReader->SetDataOrigin(0,0,0);
//		TiffReader->SetDataSpacing(3.2,3.2,1.5);
//		TiffReader->SetDataScalarTypeToUnsignedChar();
//		TiffReader->UpdateWholeExtent();
//		
//		//获取图片参数 
//		int extent[6];
//		double spacing[3];
//		double origin[3];
//		TiffReader->GetOutput()->GetExtent(extent);
//		TiffReader->GetOutput()->GetSpacing(spacing);
//		TiffReader->GetOutput()->GetOrigin(origin); 
//
//		// 计算中心位置。  
//		double center[3];
//		center[0] = origin[0] + spacing[0] * 0.5 * (extent[0] + extent[1]);
//		center[1] = origin[1] + spacing[1] * 0.5 * (extent[2] + extent[3]);
//		center[2] = origin[2] + spacing[2] * 0.5 * (extent[4] + extent[5]);
//
//		// ZSlice对应原图像矢状面（即重切的z轴方向为原x轴方向）  
//		static double sagittalX[3] = { 0, 1, 0 };
//		static double sagittalY[3] = { 0, 0, -1 };
//		static double sagittalZ[3] = { -1, 0, 0 };
//
//		// ZSlice对应原图像斜面  
//		static double obliqueX[3] = { 1, 0, 0 };
//		static double obliqueY[3] = { 0, 0.866025, 0.5 };
//		static double obliqueZ[3] = { 0, -0.5, 0.866025 }; 
//		
//		ploymapper->SetInputConnection(TiffReader->GetOutputPort());
//
//		actor->SetMapper(ploymapper);
//
//		renWin->SetParentId(m_hWnd);
//		ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
//	//	ren->SetActiveCamera(camera);
//		ren->SetBackground(.8, .9, .8);
//		ren->ResetCamera();
//
//		renWin->AddRenderer(ren);
//		iren->SetInteractorStyle(style);
//		iren->SetRenderWindow(renWin);
//		CRect rect;
//		GetClientRect(&rect);
//		CRect prect;
//		m_Picture.GetClientRect(&prect);
//
//		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
//		renWin->Render();////窗口进行绘制
//
//		axes->SetXAxisLabelText("X");
//		axes->SetYAxisLabelText("Y");
//		axes->SetZAxisLabelText("Z");
//		//widget = vtkOrientationMarkerWidget::New();
//		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//		widget->SetOrientationMarker(axes);
//		axes->Delete();
//		widget->SetInteractor(iren);
//		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
//		widget->SetEnabled(true);
//		//widget->InteractiveOff();
//		//vtkOutputWindowDisplayWarningText("hello");
//		iren->Initialize();
//		iren->Start();//初始化并进行交互绘制
//	//	ren->ResetCameraClippingRange();
//
//	}
//	else{
//
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
//		renWin->Clean(); //窗口清除  
//		renWin->RemoveRenderer(ren);
//		UpdateData(true);
//		RedrawWindow();
//		//destroyWindow("MFC_OCT");
//	}
//
//}


//
////////  碎片化 
//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//
//	if (true == flag3D)
//	{
//
//		actor->SetGlobalWarningDisplay(0);
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
//
//		char* RawfilePath = "../test/volume.vtk";  //数据地址 
//		int extent[6]={0,225,0,225,0,1};
//		//int spacing[3];
//		//int origin[3]; 
//
//		reader2->SetFileName(RawfilePath);
//
//		//reader2->GetOutput()->GetExtent(extent);
//		//reader2->GetOutput()->GetSpacing(spacing);
//		
//	//	reader->SetDataScalarType(VTK_UNSIGNED_SHORT);
//		reader2->SetFileDimensionality(3);
//		reader2->SetDataExtent(extent);
//		reader2->SetDataSpacing(.1, .1, 0.1); //设置像素间间距  
//		reader2->SetNumberOfScalarComponents(1);
//		reader2->SetDataByteOrderToBigEndian();
//		reader2->SetDataOrigin(0.0, 0.0, 0.0); //设置基准点，（一般没有用）做虚拟切片时可能会用的上
//		 ///reader->SetDataScalarTypeToInt();
//	
//		//reader2->Update();
//		
//		//Extract the region of interest
//		ExtractVOI->SetInputConnection(reader2->GetOutputPort());
//		ExtractVOI->SetVOI(extent);   // 提取指定部分 
//		ExtractVOI->SetSampleRate(1, 1, 1); // 三维放大 
//
//		
//		locator->SetDivisions(32,32,46);
//		locator->SetNumberOfPointsPerBucket(1);
//	    locator->AutomaticOff();
//
//		//Generate an isosurface
//		MarchCube->SetInputConnection(ExtractVOI->GetOutputPort());
//		//MarchCube->ComputeGradientsOn();
//	//	MarchCube->ComputeScalarsOff();
//	//	MarchCube->
//	//	MarchCube->ComputeNormalsOn();
//		//MarchCube->SetNumberOfContours(1);
//		//MarchCube->SetLocator(locator);
//		MarchCube->SetValue(0,1150);    //cube的数量 
//
//		pVectorNormal->SetInputConnection(MarchCube->GetOutputPort());
//		double Rang[2];
//		pVectorNormal->GetOutput()->GetScalarRange(Rang);
//
//		// Take the isosurface data and create geometry
//		ploymapper->SetInputConnection(MarchCube->GetOutputPort());
//		ploymapper->ScalarVisibilityOff(); 
//
//		//ploymapper->SetScalarRange(0,1250);
//		LodActor->SetNumberOfCloudPoints(1000000);
//	    actor->SetMapper(ploymapper);
//	    actor->GetProperty()->SetColor(1, 1, 1);
//
//		//camera->SetPosition(1, 1, 1);
//		//camera->SetFocalPoint(0, 0, 0);
//
//		renWin->SetParentId(m_hWnd);
//		ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
//	//	ren->SetActiveCamera(camera);
//		ren->SetBackground(.8, .9, .8);
//		ren->ResetCamera();
//
//		renWin->AddRenderer(ren);
//		iren->SetInteractorStyle(style);
//		iren->SetRenderWindow(renWin);
//		CRect rect;
//		GetClientRect(&rect);
//		CRect prect;
//		m_Picture.GetClientRect(&prect);
//
//		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
//		renWin->Render();////窗口进行绘制
//
//		axes->SetXAxisLabelText("X");
//		axes->SetYAxisLabelText("Y");
//		axes->SetZAxisLabelText("Z");
//		//widget = vtkOrientationMarkerWidget::New();
//		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//		widget->SetOrientationMarker(axes);
//		axes->Delete();
//		widget->SetInteractor(iren);
//		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
//		widget->SetEnabled(true);
//		//widget->InteractiveOff();
//		//vtkOutputWindowDisplayWarningText("hello");
//		iren->Initialize();
//		iren->Start();//初始化并进行交互绘制
//	//	ren->ResetCameraClippingRange();
//
//	}
//	else{
//
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
//		//renWin->Clean(); //窗口清除  
//		renWin->RemoveRenderer(ren);
//		UpdateData(true);
//		RedrawWindow();
//		//destroyWindow("MFC_OCT");
//	}
//
//}

//      //////固定板砖
//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//	//Extract = vtkContourFilter::New();
//	//Poly = vtkPolyDataNormals::New();
//	//style = vtkInteractorStyleTrackballCamera::New();//交互摄像机
//	//strip = vtkStripper::New();
//
//	if (true == flag3D)
//	{
//
//		actor->SetGlobalWarningDisplay(0);
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
//		
//		char* RawfilePath = "../test/volume.vtk";  //数据地址 
//		
//		reader->SetFileDimensionality(3);
//		//reader->SetDataScalarType(VTK_UNSIGNED_SHORT);
//		reader->SetDataExtent(0, 400, 0, 400, 1, 50);
//		reader->SetDataSpacing(1, 1, 1); //设置像素间间距  
//		reader->SetNumberOfScalarComponents(1);
//		reader->SetDataByteOrderToBigEndian();
//		reader->SetDataOrigin(0.0, 0.0, 0.0); //设置基准点，（一般没有用）做虚拟切片时可能会用的上
//		reader->SetFileName(RawfilePath);
//		reader->Update();
//	 
//		readerImageCast->SetInputConnection(reader->GetOutputPort());
//		readerImageCast->SetOutputScalarTypeToUnsignedShort();
//		readerImageCast->ClampOverflowOn(); //阀值
//
//		// 一维分段函数转换 
//		opacityTransferFunction->AddPoint(20, 0.0);
//		opacityTransferFunction->AddPoint(80, 0.3);
//		opacityTransferFunction->AddPoint(255, 0.8);
//		volumeProperty->SetScalarOpacity(opacityTransferFunction); //不透明度
//
//		vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();   //颜色传递函数
//		colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.5, 0.0); //添加色彩点（第一个参数索引）
//		colorTransferFunction->AddRGBPoint(60.0, 1.0, 0.0, 0.0);
//		colorTransferFunction->AddRGBPoint(128.0, 0.2, 0.1, 0.9);
//		colorTransferFunction->AddRGBPoint(196.0, 0.27, 0.21, 0.1);
//		colorTransferFunction->AddRGBPoint(255.0, 0.8, 0.8, 0.8);
//		volumeProperty->SetColor(colorTransferFunction); //设置颜色
//
//		vtkPiecewiseFunction *gradientTransferFunction = vtkPiecewiseFunction::New();//设置梯度传递函数
//		gradientTransferFunction->AddPoint(20, 0.0);
//		gradientTransferFunction->AddPoint(255, 2.0);
//		gradientTransferFunction->AddSegment(600, 0.73, 900, 0.9);
//		gradientTransferFunction->AddPoint(1300, 0.1);
//		volumeProperty->SetGradientOpacity(gradientTransferFunction);
//		
//		volumeProperty->ShadeOn(); //阴影
//		volumeProperty->SetInterpolationTypeToLinear(); //直线与样条插值之间逐发函数
//		volumeProperty->SetAmbient(0.2); //环境光系数
//		volumeProperty->SetDiffuse(0.9); //漫反射
//		volumeProperty->SetSpecular(0.2); //高光系数
//		volumeProperty->SetSpecularPower(10); //高光强度 
//
//		VolMapper->SetVolumeRayCastFunction(compositeFunction); //载入绘制方法
//		VolMapper->SetInputConnection(readerImageCast->GetOutputPort()); //图像数据输入
//		VolMapper->SetNumberOfThreads(3);
//		//定义Volume
//		volume->SetMapper(VolMapper);
//		volume->SetProperty(volumeProperty); //设置体属性
//
//		renWin->SetParentId(m_hWnd);
//		renWin->AddRenderer(ren);
//		ren->AddVolume(volume);                 ///把渲染的数据添加到渲染的工具里
//		iren->SetInteractorStyle(style);
//		iren->SetRenderWindow(renWin);
//		CRect rect;
//		GetClientRect(&rect);
//		CRect prect;
//		m_Picture.GetClientRect(&prect);
//		ren->SetBackground(.1, .1, .1);
//		ren->ResetCamera();
//		renWin->SetSize((prect.right - prect.left), (prect.bottom - prect.top));//设置背景颜色和绘制窗口大小
//		renWin->Render();////窗口进行绘制
//
//		axes->SetXAxisLabelText("X");
//		axes->SetYAxisLabelText("Y");
//		axes->SetZAxisLabelText("Z");
//		//widget = vtkOrientationMarkerWidget::New();
//		widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//		widget->SetOrientationMarker(axes);
//		axes->Delete();
//		widget->SetInteractor(iren);
//		widget->SetViewport(0.0, 0.0, 0.2, 0.2);
//		widget->SetEnabled(true);
//		//widget->InteractiveOff();
//		//vtkOutputWindowDisplayWarningText("hello");
//		iren->Initialize();
//		iren->Start();//初始化并进行交互绘制
//		//ren->ResetCameraClippingRange();
//	}
//	else{
//
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
//		renWin->Clean(); //窗口清除  
//		renWin->RemoveRenderer(ren);
//		UpdateData(true);
//		RedrawWindow();
//		//destroyWindow("MFC_OCT");
//	}
//
//
//}


//   //点读取 
//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//	 //Extract = vtkContourFilter::New();
//	 //Poly = vtkPolyDataNormals::New();
//	 //style = vtkInteractorStyleTrackballCamera::New();//交互摄像机
//	 //strip = vtkStripper::New();
//
//	/* 
//	    DataHandle Data = createData();
//    	exportData2D(Data, Data2DExport_RAW, "C:\\DispCorrectedBscan_Orig.raw"); 
//
//		exportData2DAsImage(DataHandle Data, Coloring32BitHandle Color, ColoredDataExportFormat format,
//		const char* fileName, BOOL drawScale, BOOL drawMarkers, BOOL physicalAspectRatio);
//
//		ofstream data("C:\\volume.raw", ios::binary);
//		data.write(reinterpret_cast<char*>(getDataPtr(BScan)), sizeof(float)*size_x * 512 * 1); 
//
//		exportData3D(DataHandle Volume, Data3DExportFormat Format, const char* Path);  
//
//		exportData3DAsImage(DataHandle Data, Coloring32BitHandle Color, ColoredDataExportFormat format, Direction SliceNormalDirection,
//		const char* fileName, BOOL drawScale, BOOL drawMarkers, BOOL physicalAspectRatio);
//
//*/
//
//
//	 if (true == flag3D)
//	{
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("CLOSE"));
//		char* RawfilePath = "../test/Filename.raw";  //数据地址 
//		// TIFF* pTif = TIFFOpen(RawfilePath,"r");
//	/*	TiffReader->SetFileName(RawfilePath);
//		TiffReader->SetDataExtent(0, 63, 0, 63, 188, 230);
//		TiffReader->SetDataSpacing(3.2, 3.2, 1.5);
//		TiffReader->SetDataOrigin(0.0, 0.0, 0.0);
//		TiffReader->SetDataScalarTypeToUnsignedShort();
//		TiffReader->UpdateWholeExtent();
//		*/
//		readerP->SetFileName(RawfilePath);
//		readerP->SetDataByteOrderToLittleEndian();
//		//readerP_;
//		readerP->Update();
//		//renWin->GlobalWarningDisplayOff();
//		//vtkObject::GlobalWarningDisplayOff();
//	
//		ploymapper->SetInputConnection(readerP->GetOutputPort());
//		//ploymapper->SetScalarMaterialModeToAmbientAndDiffuse();
//		ploymapper->SetScalarRange(1,10);
//		
//		actor->SetMapper(ploymapper);
//		actor->GetProperty()->SetPointSize(0.1);
//
//		//映射的多边形数据,使之到绘制图形
//		renWin->SetParentId(m_hWnd);
//		renWin->AddRenderer(ren);
//		ren->AddActor(actor);                 ///把渲染的数据添加到渲染的工具里
//		iren->SetInteractorStyle(style);
//		iren->SetRenderWindow(renWin);
//		CRect rect;
//		m_Picture.GetClientRect(&rect);
//		
//		ren->SetBackground(.1, .1, .1);
//		ren->ResetCamera();
//		renWin->SetSize(rect.right-rect.left, (rect.bottom - rect.top));//设置背景颜色和绘制窗口大小
//		renWin->Render();////窗口进行绘制
//
//		//vtkOutputWindowDisplayWarningText("hello");
//		iren->Initialize();
//		iren->Start();//初始化并进行交互绘制
//		ren->ResetCameraClippingRange();
//
//	}
//	else{
//
//		flag3D = !flag3D;
//		GetDlgItem(IDC_BUTTON_3D)->SetWindowTextW(_T("OCT3D"));
//		renWin->Clean(); //窗口清除  
//		renWin->RemoveRenderer(ren);
//		UpdateData(true);
//		RedrawWindow();
//		//destroyWindow("MFC_OCT");
//	}	
//}



//  // 黑白板砖
//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//	////////////////////数据的读取 
//	char* RawfilePath = "../test/Filename.raw";
//	//raw 图片
//	reader->SetFileName(RawfilePath);    //数据的读取 
//	reader->SetFileDimensionality(3);   //设置显示图像的维数
//	reader->SetDataScalarType(VTK_SIGNED_CHAR); //VTK_UNSIGNED_short将数据转换为unsigned char型
//	reader->SetDataExtent(0, 74, 0, 74, 0, 74); //图片属性图片像素256x256，最后两参数表示有124张图
//	reader->SetDataSpacing(0.5, 0.5, 0.9);  //设置像素间间距
//	//reader->SetDataOrigin(0.0, 0.0, 0.0);  //设置基准点，（一般没有用）做虚拟切片时可能会用的上 
//
//  ///////////////////////////数据处理 
//	readerImageCast->SetInputConnection(reader->GetOutputPort());  
//	readerImageCast->SetOutputScalarTypeToUnsignedShort(); 
//  ////////////////////////// 窗口绘制实现 
//    ren->SetBackground(0.1, 0.1, 0.1); // 设置渲染背景
//	renWin->AddRenderer(ren);  //将绘制者加入绘制窗口
//	renWin->SetParentId(this->m_hWnd);
//	iren->SetRenderWindow(renWin);  //设置交互窗口  
//	vtkInteractorStyleTrackballCamera *style = vtkInteractorStyleTrackballCamera::New();//交互摄像机
//	iren->SetInteractorStyle(style);//style为交互模式
//	CRect rect; 
//	m_Picture.GetClientRect(&rect);
//
//	renWin->SetSize((rect.right-rect.left)-120,(rect.bottom-rect.top)); 
//	//renWin->SetSize(500, 500);//设置背景颜色和绘制窗口大小
//	renWin->Render();////窗口进行绘制
//	
//	////////////////////////////////////////////数据载入窗口  
//	ren->ResetCamera();  
//	VolMapper->SetVolumeRayCastFunction(compositeFunction); //载入绘制方法   对光线进行混合操作
//	VolMapper->SetInputConnection(readerImageCast->GetOutputPort());//图像数据输入
//	VolMapper->SetNumberOfThreads(3);
//	volume->SetMapper(VolMapper);
//	volume->SetProperty(volumeProperty);  //设置体属性
//	ren->AddVolume(volume);   //将Volume装载到绘制类中
///////////////////////////////////////////////////////坐标轴的绘制  
//	//widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//	//widget->SetOrientationMarker(axes);
//	//widget->SetInteractor(iren);
//	//widget->SetViewport(0.0, 0.0, 0.4, 0.4);
//	//widget->SetEnabled(1);
//	//widget->InteractiveOn();
/////////////////////////////////////////////
//	iren->Initialize();
//	iren->Start();//初始化并进行交互绘制
//	ren->ResetCameraClippingRange();
//
//}


//void CMFC_OCTDlg::OnBnClickedButton3d()
//{
//	char* RawfilePath = "../test/volume.raw"; 
//
//	//raw 图片
//	vtkImageReader *reader = vtkImageReader::New();
//	reader->SetFileName(RawfilePath);     //数据的读取 
//	reader->SetFileDimensionality(3);//设置显示图像的维数
//	//reader->SetDataScalarType(VTK_UNSIGNED_CHAR);//VTK_UNSIGNED_short将数据转换为unsigned char型
//	reader->SetDataExtent(0, 255, 0, 255, 0, 255);//图片属性图片像素256x256，最后两参数表示有124张图
//	reader->SetDataSpacing(0.9, 0.9, 0.9); //设置像素间间距
//	reader->SetDataOrigin(0.0, 0.0, 0.0);//设置基准点，（一般没有用）做虚拟切片时可能会用的上
//
//
//	vtkImageCast *readerImageCast = vtkImageCast::New();//数据类型转换
//	readerImageCast->SetInputConnection(reader->GetOutputPort());
//	readerImageCast->SetOutputScalarTypeToUnsignedShort();
//	
//
//	vtkRenderer *ren = vtkRenderer::New();//设置绘制者(绘制对象指针)
//	 ren->SetBackground(0, 0, 0); // 设置渲染背景
//
//	vtkWin32OpenGLRenderWindow  *renWin = vtkWin32OpenGLRenderWindow::New();
//	//vtkRenderWindow *renWin = vtkRenderWindow::New();//设置绘制窗口
//	renWin->AddRenderer(ren);//将绘制者加入绘制窗口
//
//	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();//设置绘制交互操作窗口的
//	iren->SetRenderWindow(renWin);//将绘制窗口添加到交互窗口
//
//	vtkInteractorStyleTrackballCamera *style = vtkInteractorStyleTrackballCamera::New();//交互摄像机
//	iren->SetInteractorStyle(style);//style为交互模式
//
//	/////////////////////////
//	//搭上一个显示用的MFC窗口框架。
//	//CWnd *pWnd = AfxGetMainWnd();  // 获取对话框指针
//	//CWnd *viewer_Wnd;
//	//viewer_Wnd = this->GetDlgItem(IDD_MFC_OCT_DIALOG);
//	//HWND hWnd = (HWND)viewer_Wnd->m_hWnd;
//	//HWND hParent = ::GetParent(hWnd);
//	////::ShowWindow(hParent, SW_HIDE);  
//	//::ShowWindow(hParent, 1);
//	//renWin->SetParentId(this->m_hWnd);
//	/////////////////////////
//
//	//readerImageCast->ClampOverflowOn();//阀值
//	//reader->Delete();
//	//设置不透明度传递函数//该函数确定各体绘像素或单位长度值的不透明度
//	//vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();//一维分段函数变换
//	//opacityTransferFunction->AddPoint(20, 0.0);
//	//opacityTransferFunction->AddPoint(25, 0.2);
//
//	//设置颜色传递函数//该函数确定体绘像素的颜色值或者灰度值
//	//vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
//	//colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.5, 0.0);//添加色彩点（第一个参数索引）
//
//	//colorTransferFunction->AddRGBPoint(60.0, 1.0, 0.0, 0.0);
//	//colorTransferFunction->AddRGBPoint(128.0, 0.2, 0.1, 0.9);
//	//colorTransferFunction->AddRGBPoint(196.0, 0.27, 0.21, 0.1);
//	//colorTransferFunction->AddRGBPoint(255.0, 0.8, 0.8, 0.8);
//
//	vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
//	//设定一个体绘容器的属性
//
//	//volumeProperty->SetColor(colorTransferFunction);//设置颜色
//	//volumeProperty->SetScalarOpacity(opacityTransferFunction);//不透明度
//	volumeProperty->ShadeOn();//影阴
//	volumeProperty->SetInterpolationTypeToLinear();//直线与样条插值之间逐发函数
//
//	volumeProperty->SetAmbient(0.2);//环境光系数
//	volumeProperty->SetDiffuse(0.9);//漫反射
//	volumeProperty->SetSpecular(0.2);//高光系数
//	volumeProperty->SetSpecularPower(10); //高光强度 
//
//	//定义光线投射方法为MIP体绘制方法,MIP为体绘制经典算法
//	//  vtkVolumeRayCastMIPFunction*mipRaycastFunction = vtkVolumeRayCastMIPFunction::New();
//	//  mipRaycastFunction->SetMaximizeMethodToOpacity();
//
//	vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();
//	//运行沿着光线合成
//
//	//定义绘制者
//	vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();   //体绘制器
//
//	volumeMapper->SetVolumeRayCastFunction(compositeFunction); //载入绘制方法
//	volumeMapper->SetInputConnection(readerImageCast->GetOutputPort());//图像数据输入
//	volumeMapper->SetNumberOfThreads(3);
//	//定义Volume
//	vtkVolume *volume = vtkVolume::New();//表示透示图中的一组三维数据
//	volume->SetMapper(volumeMapper);
//	volume->SetProperty(volumeProperty);//设置体属性
//
//
//	//保存
//	//
//	//vtkVolumeWriter *wSP=vtkVolumeWriter::New();
//	//wSP->SetInputConnection(readerImageCast->GetOutputPort());
//	//wSP->SetFileName("e://ct/mmmm.vtk");
//	//wSP->Write();
//	//wSP->Delete();
//	
//	////////////////////////////
//	// 绘制坐标轴 
//	//vtkAxesActor* axes1 = vtkAxesActor::New();
//	//vtkOrientationMarkerWidget *widet = vtkOrientationMarkerWidget::New();
//
//	//widet->SetOrientationMarker(axes1);
//	//widet->SetOutlineColor(0.93, 0.57, 0.13);
//	//widet->SetInteractor(QVTKWidget *AvtkWin->GetInteractor());
//
//	//widet->SetViewport(0, 0, 0.3, 0.3);
//	//widet->SetEnabled(1);
//	//widet->InteractiveOn();
//	//////////////////////
//	  
//
//	ren->AddVolume(volume);//将Volume装载到绘制类中
//	ren->SetBackground(1, 1, 1);
//	renWin->SetSize(600, 600);//设置背景颜色和绘制窗口大小
//	renWin->Render();////窗口进行绘制
//
//	iren->Initialize();
//	iren->Start();//初始化并进行交互绘制
//	ren->ResetCameraClippingRange();
//
//	volumeMapper->Delete();//释放类存
//	readerImageCast->Delete();
//	iren->Delete();
//	ren->Delete();
//	renWin->Delete();
////opacityTransferFunction->Delete();
//	volumeProperty->Delete();
//	compositeFunction->Delete();
//	volume->Delete();
//	//colorTransferFunction->Delete();
//} 


void CMFC_OCTDlg::OnBnClickedButtonStart()
{
	TRACE(" __________微软基础库输出 ____________");

	if (true == flag)
	{
		flag = !flag;
		GetDlgItem(IDC_BUTTON_Start)->SetWindowTextW(_T("CLOSE"));
		UpdateWindow();
		RedrawWindow();
		Invalidate(true);

		CMutex mutex;                    //互斥量对象 
		CEvent g_Event;               //事件对象实现同步   实现多进程中的多线程的同步  

		CSemaphore mySemaphore(4, 4);   //信号量 
		CCriticalSection g_cs;         //临界区对象  
		
		//WSAAsyncSelect();  // 异步套嵌字  自动设置为非阻塞模式。
		//WSAStartup(); 
		//SOCKET socket(int af, int type, int protocol);
		//int bind( SOCKET s, const struct sockaddr FAR*name, intnamelen);

		char g_str[] = "how to use the CEvent synchronization classes";

		OCTthreadHandle = AfxBeginThread(Threadone, this);  // 启动线程 
		DrawThreadHandle = AfxBeginThread(&ThreadOCT, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);  // THREAD_PRIORITY_IDLE  优先级 
		DrawThreadHandle->m_bAutoDelete = true;     // 线程解决方案 

		CProgressCtrl myProCtrl;
		CRect rect,proRect;
		m_Picture.GetClientRect(&rect);
		proRect.left = rect.left + rect.Width() / 2 - 200;
		proRect.top = rect.top + rect.Height() / 2;
		proRect.right = rect.right - rect.Width() / 2 + 200;
		proRect.bottom = rect.bottom - rect.Height() / 2 + 20;
		myProCtrl.Create(WS_VISIBLE, proRect, this, 99); //创建位置、大小
		myProCtrl.SetRange(0, 100);

		for (int i = 0; i < 100; i++)
		{
			myProCtrl.OffsetPos(1);
			CString str;
			str.Format(_T("%d%%"), i); //百分比
			(GetDlgItem(IDC_EDIT_TestScroll))->SetWindowText(str);
			Sleep(10);
		}

		CString str("..\\sys\\systemConfig.txt");
		//mSysWandR.InitLog(str);
		//mSysWandR.WriteString(str);
		//mSysWandR.EndLog();
	}
	else{
		flag = !flag;
		GetDlgItem(IDC_BUTTON_Start)->SetWindowTextW(_T("START"));
	
		UpdateData(true);
		RedrawWindow();
	}
}


UINT CMFC_OCTDlg::ThreadOCT(LPVOID lpParam)
{
	while (true)
	{
		printf("OCT线程 ！");
		Sleep(20);

		if (true == flag)
		{
			break;
		}
	}
	return 0;
}

UINT CMFC_OCTDlg::Threadone(LPVOID param)
{
	CMFC_OCTDlg* pDlg = reinterpret_cast<CMFC_OCTDlg*>(param);
	
	while (true)
	{
		pDlg->PostMessageW(MY_MSG, 1, 0);
		Sleep(100);
		if (true == flag)
		{
			Sleep(100);
			break;
		}
	}
	return 0;
}

LRESULT CMFC_OCTDlg::ReadMatShow(WPARAM wParam, LPARAM lParam)
{
	Mat mat1 = imread("..//test//AdvancedSnapshot.png");
	//mat1 = mat1(Range(50,500),Range(1,300));
	showMat();
	//mat1.release();
	return 0;
}

void CMFC_OCTDlg::showMat()
{

	CBitmap bitmap;
	BITMAP bmap, bmaps;
	CDC memdc, memdcs;
	CDC*mdc = this->GetDC();

	CImage img;
	CRect mrect;
	CWnd *pWnd = GetDlgItem(IDC_Xiaoy_STATIC);//参数为控件ID。
	pWnd->GetClientRect(&mrect);//rc为控件的大小。

	HBITMAP hbitmap;
	HRESULT ret;

	if (!img.IsNull())
		img.Destroy();
	ret = img.Load(_T("..//test//AdvancedSnapshot.png"));//加载背景图,S_OK:成功，E_FAIL:加载失败  
	if (ret == S_OK)//加载成功  
	{
		if (!img.IsNull())
		{
			hbitmap = img.Detach();
			bitmap.Attach(hbitmap);
			memdc.CreateCompatibleDC(mdc);
			memdc.SelectObject(hbitmap);
			bitmap.GetBitmap(&bmap);
			bitmap.Detach();
		}
	}
	if (!img.IsNull())
		img.Destroy();
	ret = img.Load(_T("..//test//AdvancedSnapshot.png"));//加载滑条  
	if (!img.IsNull())
	{
		hbitmap = img.Detach();//获得位图句柄，用以转换  
		bitmap.Attach(hbitmap);//转换为CBITMAP对象  
		memdcs.CreateCompatibleDC(mdc);
		memdcs.SelectObject(hbitmap);
		bitmap.GetBitmap(&bmaps);

		CRect rect;
		CWnd *pWnd = GetDlgItem(IDC_Xiaoy_STATIC);//参数为控件ID。
		pWnd->GetClientRect(&rect);//rc为控件的大小。
		
		if (memdc != NULL)
		{//加载到同一个内存DC中   //height=1024  wieght=512 
			memdc.StretchBlt(bmap.bmWidth / mrect.Width(), bmap.bmHeight / mrect.Height(), bmap.bmWidth / mrect.Width(),
				bmap.bmHeight / mrect.Height(), &memdcs, 0, 0, bmaps.bmWidth, bmaps.bmHeight, SRCCOPY);

		} // height =576  weight =578   
		mdc->SetStretchBltMode(HALFTONE);
		::SetStretchBltMode(memdc, HALFTONE);
		::SetBrushOrgEx(memdc, 0, 0, NULL);
		double mZoom = 1.5;   // 缩放倍数 
		int Weight = static_cast<int>((rect.right - (bmap.bmWidth / (mZoom))) / 2);
		int Height = static_cast<int>((rect.bottom - (bmap.bmHeight / (mZoom))) / 2);
		//mdc->FillSolidRect(rect,RGB(1,1,1));  //很大程度上影响渲染的速度 改到zoom
		mdc->StretchBlt(Weight, Height, static_cast<int>((bmap.bmWidth / mZoom)>rect.right ? (rect.right - Weight) : (bmap.bmWidth / mZoom)),
			static_cast<int>((bmap.bmHeight / mZoom)>rect.bottom ? (rect.bottom - Height) : (bmap.bmHeight / mZoom)),
			&memdc, 0, 0, bmap.bmWidth, bmap.bmHeight, SRCCOPY);
		//mdc->StretchBlt(Weight, Height, bmap.bmWidth / mZoom, bmap.bmHeight / mZoom, &memdc, 0, 0, bmap.bmWidth, bmap.bmHeight, SRCCOPY);
		bitmap.Detach();
	}
}

//
//void CMFC_OCTDlg::showMat(Mat mat1)
//{
//	if (mat1.empty())
//	{
//	MessageBox(_T("图片不能加载！请检查重新"));
//	exit(201);
//	}
//	
//	CImage imgDst;
//	imgDst.Destroy(); //释放资源 
//	Mat2CImage(&mat1, imgDst);  //格式转换 
//	CRect rect;
//	PAINTSTRUCT ps;
//	// HDC hdc = BeginPaint(hwnd, &ps);
//	CDC *pDstDC = BeginPaint(&ps);
//	CRect rcClient;
//	GetClientRect(&rcClient);
//	//GetClientRect(&rect);
//	CMemDC memDC(*pDstDC, rcClient);
//	CDC *pDC = &memDC.GetDC();
//	//填充背景色  
//	pDC->FillSolidRect(&rcClient, RGB(100, 100, 100));
//	pDC->SetStretchBltMode(HALFTONE);
//	//GetDlgItem(IDC_Xiaoy_STATIC)->GetWindowRect(&rect);  //
//	//ScreenToClient(&rect);
//	//CWnd* pWnd = GetDlgItem(IDC_Xiaoy_STATIC);
//	//pWnd->GetClientRect(&rect); 
//	//CDC *pDC = pWnd->GetDC();
//	//imgDst.Draw(pDC->m_hDC, rect);
//	if (!imgDst.IsNull())
//	{
//		//原图大小  
//		CRect rcSrc(0, 0, imgDst.GetWidth(), imgDst.GetHeight());
//		//锁定原图比例  
//		double fZoomRate = min((double)rcClient.Width() / (double)rcSrc.Width(),
//			(double)rcClient.Height() / (double)rcSrc.Height());
//		int cx = (int)(rcSrc.Width()*fZoomRate), cy = (int)(rcSrc.Height()*fZoomRate);
//		CRect rcDst(0, 0, cx, cy); //目标大小  
//		rcDst.OffsetRect((rcClient.Width() - cx) / 2, (rcClient.Height() - cy) / 2-45);//居中										
//		//绘图  
//		imgDst.Draw(pDC->m_hDC, rcDst, rcSrc);
//	}
//	Sleep(100);
//	ReleaseDC(pDC);
//	imgDst.Destroy(); //释放资源 
//	//InvalidateRect(rcClient,true);
//
//}


void CMFC_OCTDlg::DrawMatToPic(Mat cvImg, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDCDst = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);

	int NewWidth = cvImg.cols;
	int NewHeight = cvImg.rows;
	double XScale = double(rect.right) / double(cvImg.cols);
	double YScale = double(rect.bottom) / double(cvImg.rows);

	if (XScale > YScale)
	{
		NewWidth = cvImg.cols*YScale;
		NewHeight = rect.bottom;
	}
	else if (XScale < YScale)
	{
		NewWidth = rect.right;
		NewHeight = cvImg.rows*XScale;
	}
	cv::Size NewSize(NewWidth, NewHeight);
	cv::Mat cvImgScaled(NewSize, CV_8UC3);
	resize(cvImg, cvImgScaled, NewSize);
	imshow("MFC_OCT", cvImgScaled);
}


// 将Mat图像转换成CImage格式

int CMFC_OCTDlg::Mat2CImage(Mat *mat, CImage &img) {
	if (!mat || mat->empty())
		return -1;
	int nBPP = mat->channels() * 8;
	img.Create(mat->cols, mat->rows, nBPP);
	if (nBPP == 8)
	{
		static RGBQUAD pRGB[256];
		for (int i = 0; i < 256; i++)
			pRGB[i].rgbBlue = pRGB[i].rgbGreen = pRGB[i].rgbRed = i;
		img.SetColorTable(0, 256, pRGB);
	}
	uchar* psrc = mat->data;
	uchar* pdst = (uchar*)img.GetBits();
	int imgPitch = img.GetPitch();
	for (int y = 0; y < mat->rows; y++)
	{
		memcpy(pdst, psrc, mat->cols*mat->channels());//mat->step is incorrect for those images created by roi (sub-images!)  
		psrc += mat->step;
		pdst += imgPitch;
	}
	return 0;
}


void CMFC_OCTDlg::ReadTiffParam(char* fileName, int &width, int &height,
	int &nTotalFrame,  // 总帧数
	unsigned short &nComp,  //压缩方法
	int &nStrip,
	uint16 &samplesperpixel,
	uint16 &bitsPersample)
{
	TIFF* tiff = TIFFOpen(fileName, "r");//打开Tiff文件，得到指针，以后所有的操作都通过指针进行 
	TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &width);
	TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &height);
	TIFFGetField(tiff, TIFFTAG_COMPRESSION, &nComp);   //压缩方法
	nTotalFrame = TIFFNumberOfDirectories(tiff);    //得到图像的总帧数  
	nStrip = TIFFNumberOfStrips(tiff);              //数条
	TIFFGetField(tiff, TIFFTAG_SAMPLESPERPIXEL, &samplesperpixel);		//每个像素占多少机器字，24位图samplesperpixel应该等于3。  
	TIFFGetField(tiff, TIFFTAG_BITSPERSAMPLE, &bitsPersample);         //每一个机器字长，这里应为8。
}


void CMFC_OCTDlg::SaveTif2Bmp(char* pszTif, LPTSTR pszBmp)
{
	TIFF* pTif = TIFFOpen(pszTif, "r");
	if (!pTif)
		return;

	int i, nret, nw, nh, npage, nrps;
	unsigned short nComp, nPho, nBps, nSpp;
	//TIFFSetErrorHandler(TIFFErrorHandler);
	nret = TIFFGetField(pTif, TIFFTAG_IMAGEWIDTH, &nw);
	nret = TIFFGetField(pTif, TIFFTAG_IMAGELENGTH, &nh);
	nret = TIFFGetField(pTif, TIFFTAG_COMPRESSION, &nComp);
	nret = TIFFGetField(pTif, TIFFTAG_PHOTOMETRIC, &nPho);
	nret = TIFFGetField(pTif, TIFFTAG_BITSPERSAMPLE, &nBps);
	nret = TIFFGetField(pTif, TIFFTAG_SAMPLESPERPIXEL, &nSpp);
	nret = TIFFGetField(pTif, TIFFTAG_ROWSPERSTRIP, &nrps);
	npage = TIFFNumberOfDirectories(pTif);
	int nSize = TIFFStripSize(pTif);
	int nStrip = TIFFNumberOfStrips(pTif);
	uint32* bc; // wrong size
	nret = TIFFGetField(pTif, TIFFTAG_STRIPBYTECOUNTS, &bc);
	int nwb = (nw*nBps*nSpp + 31) / 32 * 4; // 4-byte align for bmp
	LPBYTE pBufBmp = new BYTE[nwb*nh];
	//uint32 stripsize = bc[0];
	//tdata_t buf = _TIFFmalloc(nSize);//stripsize);
	LPBYTE pStripBmp = pBufBmp;
	for (i = 0; i<nStrip; i++)
	{
		nret = TIFFReadEncodedStrip(pTif, i, pStripBmp, nSize);
		int nHStrip = nret / (nw*nBps*nSpp / 8);
		pStripBmp += nHStrip * nwb;
	}
	//uint32* raster = (uint32*) _TIFFmalloc(nw*nh*sizeof(uint32));
	//TIFFReadRGBAImage(tif, nw, nh, raster, 0);
	SaveBmpFile(pszBmp, nw, nh, nBps*nSpp, (LPBYTE)pBufBmp);
	//_TIFFfree(buf);
	delete[] pBufBmp;
	TIFFClose(pTif);
}

void CMFC_OCTDlg::SaveBmpFile(LPTSTR pszBmp, int nW, int nH, int nBpp, LPBYTE pBuf)
{
	BITMAPFILEHEADER bfh = { 0 };
	BITMAPINFOHEADER bih = { 0 };
	DWORD pal[256] = { 0, 0XFFFFFF };
	int nLineByte, nwb, y;

	bfh.bfType = 'MB';
	bfh.bfSize = sizeof bfh;
	bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
	if (nBpp == 1)
		bfh.bfOffBits += 8;
	bih.biSize = sizeof bih;
	bih.biWidth = nW;
	bih.biHeight = nH;
	bih.biBitCount = nBpp;
	bih.biPlanes = 1;
	nwb = (nW*nBpp + 31) / 32 * 4; //bmp 4 bytes align
	bih.biSizeImage = nwb*nH;

	CFile fBmp(pszBmp, CFile::modeCreate | CFile::modeWrite);
	fBmp.Write(&bfh, sizeof bfh);
	fBmp.Write(&bih, sizeof bih);
	if (nBpp == 1)
		fBmp.Write(pal, 8);

	nLineByte = (nW*nBpp + 7) / 8; //tif 1 bytes align
	LPBYTE pLine = pBuf + nLineByte*(nH - 1);
	for (y = 0; y<nH; y++)
	{
		fBmp.Write(pLine, nLineByte);
		if (nwb > nLineByte)
			fBmp.Write(pal, nwb - nLineByte);
		pLine -= nLineByte;
	}
	fBmp.Close();
}



CButton* CMFC_OCTDlg::NewMyButton(int nID, CRect rect, int nStyle)
{
	CString m_Caption;

	m_Caption.LoadString(nID);    //取按钮标题

	CButton *p_Button = new CButton();

	ASSERT_VALID(p_Button);

	p_Button->Create(m_Caption, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID); //创建按钮
	return p_Button;
}

void CMFC_OCTDlg::showBmpImage(int ID)
{
	CBitmap bitmap;  // CBitmap对象，用于加载位图   
	//SyncAcquisition();
	CRect rectClient;
	GetClientRect(rectClient);

	bitmap.LoadBitmap(ID);  // 将位图IDB_BITMAP1加载到bitmap   
	//bitmap.CreateCompatibleBitmap(IDB_BITMAP1,50,60);
	BITMAP m_BitM;
	bitmap.GetBitmap(&m_BitM);  //获取位图的信息 

	CDC *pDC = GetDC();
	CBrush brush(RGB(0, 0, 0));//定义一个黑色的画刷 
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);  // 创建与当前DC（pDC）兼容的DC
	dcCompatible.SelectObject(&bitmap);
	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_Xiaoy_STATIC);//参数为控件ID。
	pWnd->GetClientRect(&rect);//rc为控件的大小。
	pDC->StretchBlt(rect.left, 10, rect.Width(), rect.Height(), &dcCompatible, 0, 0, m_BitM.bmWidth, m_BitM.bmHeight, SRCCOPY);

	//hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	//m_Picture.SetBitmap(hBmp);    // 设置图片控件m_Picture的位图图片为IDB_BITMAP1   
	ReleaseDC(pDC); //free pDC 

	//pDC.DeleteDC();//释放设备上下文  
	bitmap.DeleteObject();//释放位图对象 

}


//void CMFC_OCTDlg::Pipeline() {
//	//创建球
//	sphere->SetRadius(1);  
//	sphere->SetThetaResolution(18); 
//	sphere->SetPhiResolution(18);
//	sphere->LatLongTessellationOn();  
//	sphereMapper->SetInputData(sphere->GetOutput());
//	sphereActor->SetMapper(sphereMapper); 
//	ren->AddActor(sphereActor); 
//} 


void CMFC_OCTDlg::OnBnClickedButtonparam()
{
	CAddSheet sheet(_T("参数设置"));
	//sheet.m_Page1.GetDlgItem(ID_APPLY_NOW)->EnableWindow(TRUE);
	//sheet.m_Page2.GetDlgItem(ID_APPLY_NOW)->EnableWindow(TRUE);
	//sheet.GetDlgItem(ID_APPLY_NOW)->EnableWindow(TRUE);
	sheet.DoModal(); 


}


void CMFC_OCTDlg::OnBnClickedButton3dparam()
{

	Dlg3DParam dlg;
	dlg.DoModal();

}


void CMFC_OCTDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CString strTime;
	CTime tm;
	tm = CTime::GetCurrentTime();         //获取当前系统时间
	strTime = tm.Format("%y/%m/%d %X");   //格式化系统时间。即使系统时 间按照Format中设置的格式显示
	SetDlgItemText(IDC_EDIT_ShowTime, strTime);        //初始化编辑框显示
	SetTimer(1, 1000, NULL);         //启动定时器

	CPoint   point;
	GetCursorPos(&point);
	CString str;
	str.Format(_T("%d"),point.x);
	GetDlgItem(IDC_EDITPX)->SetWindowText(str);
	str.Format(_T("%d"), point.y);
	GetDlgItem(IDC_EDITPY)->SetWindowText(str);
	GetDlgItem(IDC_EDITPZ)->SetWindowText(str);
	strTime= tm.Format("%y-%m-%d %H:%M:%S");

	CRect rect;
	GetClientRect(&rect);
	m_Statusbar.SetPaneInfo(0, ID_INDICATOR_NISH, SBPS_NORMAL, rect.Width() / 2);
	m_Statusbar.SetPaneInfo(1, ID_INDICATOR_TIME, SBPS_STRETCH, rect.Width() / 2);
	m_Statusbar.SetPaneText(1, strTime);
	m_Statusbar.SetPaneText(0, _T("一直被模仿，从未被超越！"));
	//RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	CDialogEx::OnTimer(nIDEvent);
}


void CMFC_OCTDlg::OnNMCustomdrawSliderLifgt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	CString str; 
	mScrollLight.SetRange(0, 100);

	mScrollLight.SetLineSize(2);
	str.Format(_T("%d"),mScrollLight.GetPos());
	GetDlgItem(IDC_EDIT_TestScroll)->SetWindowText(str);

	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMFC_OCTDlg::OnNMCustomdrawSliderLaser(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	CString str;
	mScrollLaser.SetRange(0, 100);
	
	str.Format(_T("%d"), mScrollLaser.GetPos());
	GetDlgItem(IDC_EDIT_TestScroll)->SetWindowText(str);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMFC_OCTDlg::OnNMCustomdrawSliderLifgt3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	CString str;
	mScrollGrayLevel.SetRange(0, 100);
	str.Format(_T("%d"), mScrollGrayLevel.GetPos());
	GetDlgItem(IDC_EDIT_TestScroll)->SetWindowText(str);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMFC_OCTDlg::WinHelp(DWORD dwData, UINT nCmd)
{
	// TODO: Add your specialized code here and/or call the base class

	CDialogEx::WinHelp(dwData, nCmd);
}


void CMFC_OCTDlg::Close3Dwindow()
{
	//axes->Delete();
	//widget->Delete();
	//// 释放vtk空间 
	//ren->Delete();
	//renWin->Delete();
	//iren->Delete();
	//readerImageCast->Delete();
	//reader->Delete();
	//volumeProperty->Delete();
	//compositeFunction->Delete();
	//volume->Delete();
	//VolMapper->Delete();
	//mapper->Delete();
	////actor->Delete();
	//style->Delete();
	//readerP->Delete();
	//TiffReader->Delete();
	//SmvoluMapper->Delete();
	//opacityTransferFunction->Delete();
	//fileOutputWindow->Delete();
	//OutPutWin->Delete();
	//imageActor->Delete();

	//if (NULL != actor)
	//{
	//	actor->Delete();
	//}
}

map<int, vector<float>> ClipPartImage(float* data)    //将二维的数据加载到map容器中 
{
	int Weight=100,Height=20; 
	vector < float > mImgDataVector;    
	map<int, vector<float>> mImgMap;
	map<int, vector<float>>::iterator iter = mImgMap.begin();  // 可以遍历所有的map的成员  

	for (int i = 0; i < Height;i++)
	{ 
		for (int j = 0; j < Weight;j++)
		{
			mImgDataVector.push_back(*data);
			data++;
		}
		mImgMap.insert(make_pair(i, mImgDataVector));
	}
	return mImgMap;
}


void CMFC_OCTDlg::OnBnClickedButtonSnippintool()
{
	LoadLibrary(_T("kernel32.dll"));   // 4C801d7b  
	WinExec("snippingtool.exe", SW_SHOW);
}

void CMFC_OCTDlg::OnCbnSelchangeComb3dmodel()
{ 

	Model3dStyle =mModel3DChioce.GetCurSel();
	//mModel3DChioce.SetCurSel(Model3dStyle);
}



void CMFC_OCTDlg::DrawLine(CDC* pDC)
{
	CRect ClientRect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	m_Picture.GetClientRect(ClientRect);
	CPoint StartPoint(0, 0), EndPoint(50, 50);
	int height = ClientRect.bottom*2.5;
	int width = ClientRect.right*2.5;
	pDC->SelectObject(&pen);
	pDC->SetMapMode(MM_LOMETRIC);  // cast light upon x positive value point right, Y positive value point upon 
	pDC->MoveTo(0, 10);
	pDC->LineTo(width - 100, 10);
	CString Scalestr("1.5");
	// draw scale  
	for (int i = 0; i < width; i += 10)
	{
		if (i % 100 == 0)  //the diatance of scale is 1cm 
		{
			Scalestr.Format(_T("%d"), (i / 100));
			pDC->SetTextAlign(TA_CENTER);
			pDC->SetTextColor(RGB(255, 0, 0));
			pDC->TextOutW(65, -height + i, Scalestr);
		}
		if (i % 50 == 0) //the distance of little scale is 50mm
		{

			pDC->MoveTo(i, 0);
			pDC->LineTo(i, -60);

			pDC->MoveTo(0, -height + i);
			pDC->LineTo(60, -height + i);


			pDC->MoveTo(width - i, -height + 100);
			pDC->LineTo(width - i, -height + 40);


			pDC->MoveTo(width, -i);
			pDC->LineTo(width - 60, -i);

		}
		else
		{
			pDC->MoveTo(i, 0);
			pDC->LineTo(i, -50);

			pDC->MoveTo(0, -height + i);
			pDC->LineTo(50, -height + i);

			pDC->MoveTo(width - i, -height + 100);
			pDC->LineTo(width - i, -height + 50);

			pDC->MoveTo(width, -i);
			pDC->LineTo(width - 50, -i);
		}
	}

}


void CMFC_OCTDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (nType != SIZE_MINIMIZED) 
	{
		ChangeSize(IDC_LIST1, cx, cy);  //对每一个控件依次做调整
		ChangeSize(IDC_LIST2, cx, cy);
		ChangeSize(IDC_Xiaoy_STATIC, cx, cy);
		ChangeSize(IDC_BUTTONParam, cx, cy);
		ChangeSize(IDC_STATIC, cx, cy);
		ChangeSize(IDC_BUTTON_Start, cx, cy);
		ChangeSize(IDC_BUTTON_3D, cx, cy);
		ChangeSize(IDC_STATIC_LIGHT, cx, cy);
		ChangeSize(IDC_SLIDER_LIFGT, cx, cy);
		ChangeSize(IDC_SLIDER_Laser, cx, cy);
		ChangeSize(IDC_SLIDER_LIFGT3, cx, cy);
		ChangeSize(IDC_3Dmodel, cx, cy);
		ChangeSize(IDC_COMB3dModel, cx, cy);
		ChangeSize(IDC_STATIC_Vedio, cx, cy);
		ChangeSize(IDC_EDITPX, cx, cy);
		ChangeSize(IDC_BUTTON_Snippintool, cx, cy);
		ChangeSize(IDC_BUTTON_AddPicture, cx, cy);
		ChangeSize(IDC_EDIT_TestScroll, cx, cy);
		ChangeSize(IDC_EDITPY, cx, cy);
		ChangeSize(IDC_EDITPZ, cx, cy);
		ChangeSize(IDC_EDIT_ShowTime, cx, cy);
		ChangeSize(IDC_STATIC, cx, cy);
		//ChangeSize(IDC_STATIC_model, cx, cy);

		GetClientRect(&m_TotalRect);   //最后要更新对话框的大小，当做下一次变化的旧坐标；
	}

}


void CMFC_OCTDlg::ChangeSize(UINT nID, int x, int y)
{
	CWnd *pWnd;
	pWnd = this->GetDlgItem(nID);
	if (pWnd != NULL)     //判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，Pwnd为空
	{
		CRect rec;
		pWnd->GetWindowRect(&rec);                          //获取控件变化前的大小
		ScreenToClient(&rec);                               //将控件大小装换位在对话框中的区域坐标
		rec.left = rec.left*x / this->m_TotalRect.Width();  //按照比例调整空间的新位置
		rec.top = rec.top*y / this->m_TotalRect.Height();
		rec.bottom = rec.bottom*y / this->m_TotalRect.Height();
		rec.right = rec.right*x / this->m_TotalRect.Width();
		pWnd->MoveWindow(rec);   //伸缩控件
	}



}
