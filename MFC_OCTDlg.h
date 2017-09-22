
#pragma once
#include <functional>   // STl标准库 
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <afxinet.h>
#include <vtkMultiThreader.h>
#include <vtkCallbackCommand.h>
#include <vtkStructuredGridReader.h>
#include <vector> 

#include <vtkAutoInit.h> 

#include "UIthread.h"
#include "afxwin.h"  
#include "glaux.h"
#include "vtktiff/libtiff/tiff.h" 
#include "CvImgCtrl.h"
#include "AddSheet.h"

#include "vtkMFCWindow.h"
#include "RegenvtkColor.h"
#include "SysReadAndWrite.h"

#include "vtkClientServerInterpreterInternals.h"
#include "OpencvShowVedio.h"
#include "OCTProgressBar.h"
#include "MFCVtkWindow.h"

#include <vtkTextMapper.h>
#include <vtkActor.h>
#include <vtkActor2D.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkArrowSource.h>
#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkDiskSource.h>
#include <vtkLineSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkSphereSource.h>
#include <vtkAutoInit.h>

//#include "BCGHeader.h"
//#include "SysReadAndWrite.h"

/////////////////////////////////////

VTK_MODULE_INIT(vtkRenderingFreeType);

/*///////////
//功能：opencv划线响应函数
//参数： 5个，意思由变量名可知
//返回值：无
*////////////
void KeyPressCallbackFunction(vtkObject* caller, long unsigned int eventId, void* clientData, void* callData);

void on_mouse(int event, int x, int y, int flags, void* ustc);    //opencv鼠标响应按钮 

void GetTwoPoint(int event, int x, int y, int flags, void* ustc);   //opencv鼠标响应函数 

void calDistanceOfTwoPoint(cv::Point PointBegin, cv::Point PointEnd, double& length, double& angle);  // 传引用 length angle

UINT ShowVedio(LPVOID mDParam);   // 播放OCT摄像头图片 

void TestVtk();


#ifndef AFX_TESTDIDLG_H__6EA700CE_0AF3_11D2_9768_0080C858DB41__INCLUDED_
#define AFX_TESTDIDLG_H__6EA700CE_0AF3_11D2_9768_0080C858DB41__INCLUDED_
#endif
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000 


// CMFC_OCTDlg 对话框
class CFreeMenu;  
class CMFC_OCTDlg : public CDialogEx
{
	// 构造
public:
	~CMFC_OCTDlg();

	CMFC_OCTDlg(CWnd* pParent = NULL);	// 标准构造函数
	// 对话框数据
	enum { IDD = IDD_MFC_OCT_DIALOG };

	CFreeMenu  *m_menu;
	CFont font;

//	SysReadAndWrite  SysLog;

public:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	virtual void ReadTiffParam(char* fileName, int &width, int &height, int &nTotalFrame, unsigned short &nComp, int &nStrip, uint16 &samplesperpixel, uint16 &bitsPersample);

	virtual void SaveTif2Bmp(char* pszTif, LPTSTR pszBmp);

	virtual void SaveBmpFile(LPTSTR pszBmp, int nW, int nH, int nBpp, LPBYTE pBuf);

	void DrawMatToPic(Mat cvImg, UINT ID);

	int Mat2CImage(Mat *mat, CImage &img);

	virtual CButton* NewMyButton(int nID, CRect rect, int nStyle);  // 创建新按钮 

	void showMat();

	void showBmpImage(int ID);
	 
	void Close3Dwindow();

	static UINT Threadone(LPVOID param);  //线程函数1 

	static UINT ThreadOCT(LPVOID lpParam);  //申明工作线程  

	void Model3Dstyle1();

	int Model3Dstyle2();

	void Model3Dstyledefault();
	// 实现 
	void DrawLine(CDC* pDC);

	void ChangeSize(UINT nID, int x, int y);  

	void  SetBkground();

protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//CBCGPRibbonStatusBar m_wndStatusBar;          
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

	afx_msg void OnPaint();

	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg LRESULT ReadMatShow(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP();
private:

	CWinThread*  OCTthreadHandle;

	CWinThread*  DrawThreadHandle;

	CStatusBar m_Statusbar;   // status 

	CStatusBarCtrl bkStatus; 

	CToolBar m_ToolBar    ; 

	CRect  m_TotalRect; 

	CBrush m_brush;

	CMenu* m_MenuBar;

	vtkNew<vtkInteractorEventRecorder> recorder;

	vtkNew<vtkRenderWindowInteractor> InteractorCp;

public:

	CStatic m_Picture;

	CSliderCtrl mScrollLight;

	CSliderCtrl mScrollLaser;

	CSliderCtrl mScrollGrayLevel;

	CEdit m_EDITX;

	CEdit m_EDITY;

	CEdit m_EDITZ;

	CComboBox mModel3DChioce;

	CStatic m_ImageVedio;
	//POINT  ptBorder;
	afx_msg LRESULT onFrame(WPARAM wp, LPARAM lp);

	afx_msg void OnBnClickedButtonAddpicture();

	afx_msg void OnBnClickedButton3d();

	afx_msg void OnBnClickedButtonStart();

	afx_msg void OnBnClickedButtonparam();

	afx_msg void OnBnClickedButton3dparam();

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnNMCustomdrawSliderLifgt(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNMCustomdrawSliderLaser(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNMCustomdrawSliderLifgt3(NMHDR *pNMHDR, LRESULT *pResult);

	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);

	afx_msg void OnBnClickedButtonSnippintool();

	afx_msg void OnCbnSelchangeComb3dmodel();

	afx_msg void OnSize(UINT nType, int cx, int cy);

};

class Timer {
public:
	void start() {
		start_count = clock();
	}
	double get_seconds() {
		return static_cast<double>(clock() - start_count) / CLOCKS_PER_SEC;
	}

private:
	
	clock_t start_count;

}; 

struct NewCallbackInfo    // VTK进程参数
{
	const char* Type;
	unsigned long ID;
};