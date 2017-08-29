
#pragma once
#include <functional>   // STl��׼�� 
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <vtkMultiThreader.h>
#include <vtkCallbackCommand.h>

#include "vtkMFCWindow.h"
#include "RegenvtkColor.h"
#include "vtkClientServerInterpreterInternals.h"

#include "UIthread.h"
#include "afxwin.h"  
#include "glaux.h"
#include "glut.h"
#include "vtktiff/libtiff/tiff.h" 
#include "CvImgCtrl.h"
#include "AddSheet.h"
#include "OpencvShowVedio.h"
#include "vtkMFCWindow.h"
//#include "SysReadAndWrite.h"

/////////////////////////////////////
VTK_MODULE_INIT(vtkRenderingFreeType);
/*///////////
//���ܣ�opencv������Ӧ����
//������ 5������˼�ɱ�������֪
//����ֵ����
*////////////
void KeyPressCallbackFunction(vtkObject* caller, long unsigned int eventId, void* clientData, void* callData);

void on_mouse(int event, int x, int y, int flags, void* ustc);    //opencv�����Ӧ��ť 

void GetTwoPoint(int event, int x, int y, int flags, void* ustc);   //opencv�����Ӧ���� 

void calDistanceOfTwoPoint(cv::Point PointBegin, cv::Point PointEnd, double& length, double& angle);  // ������ length angle

UINT ShowVedio(LPVOID mDParam);   // ����OCT����ͷͼƬ 

// CMFC_OCTDlg �Ի���
class CMFC_OCTDlg : public CDialogEx
{
	// ����
public:
	~CMFC_OCTDlg();

	CMFC_OCTDlg(CWnd* pParent = NULL);	// ��׼���캯��
	// �Ի�������
	enum { IDD = IDD_MFC_OCT_DIALOG };


public:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	virtual void ReadTiffParam(char* fileName, int &width, int &height, int &nTotalFrame, unsigned short &nComp, int &nStrip, uint16 &samplesperpixel, uint16 &bitsPersample);

	virtual void SaveTif2Bmp(char* pszTif, LPTSTR pszBmp);
	virtual void SaveBmpFile(LPTSTR pszBmp, int nW, int nH, int nBpp, LPBYTE pBuf);

	void DrawMatToPic(Mat cvImg, UINT ID);

	int Mat2CImage(Mat *mat, CImage &img);

	virtual CButton* NewMyButton(int nID, CRect rect, int nStyle);  // �����°�ť 

	void showMat();

	void showBmpImage(int ID);
	 
	void Close3Dwindow();

	static UINT Threadone(LPVOID param);  //�̺߳���1 

	static UINT ThreadOCT(LPVOID lpParam);  //���������߳�  

	void Model3Dstyle1();

	int Model3Dstyle2();

	void Model3Dstyledefault();
	// ʵ�� 
	void DrawLine(CDC* pDC);

protected:
	//SysReadAndWrite  mSysWandR;
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT ReadMatShow(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT MyMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP();
private:
	//vtkSmartPointer<vtkVolumeProperty> volumeProperty;  //��������� 
	//vtkSmartPointer<vtkColorTransferFunction> color;
	//vtkSmartPointer<vtkPiecewiseFunction> gradient;
	//vtkSmartPointer<vtkPiecewiseFunction> opacityTransferFunction; // һά�ֶκ���ת�� 
	//vtkSmartPointer<vtkStructuredPointsReader> StruVtkreader;
	//vtkSmartPointer<vtkVolume> volume; //��ʾ͸ʾͼ�е�һ����ά����
	//vtkSmartPointer<vtkGPUVolumeRayCastMapper> VolMapper; //���������
	//vtkSmartPointer<vtkRenderer> ren;

	vtkNew<vtkInteractorEventRecorder> recorder;
	vtkNew<vtkRenderWindowInteractor> InteractorCp;
	//vtkSmartPointer<vtkWin32OpenGLRenderWindow> renWin;
	//vtkSmartPointer<vtkRenderWindowInteractor> iren;
	
	//vtkSmartPointer<vtkAxesActor> axes;
	//vtkSmartPointer<vtkOrientationMarkerWidget> widget;
	//vtkSmartPointer<vtkInteractorStyleTrackballCamera> style;//���������
	//vtkSmartPointer<vtkCamera> camera;
	//vtkSmartPointer<vtkClientServerInterpreterInternals> client;
public:
	CStatic m_Picture;
	//POINT  ptBorder;
	afx_msg LRESULT onFrame(WPARAM wp, LPARAM lp);
	afx_msg void OnBnClickedButtonAddpicture();
	afx_msg void OnBnClickedButton3d();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonparam();
	afx_msg void OnBnClickedButton3dparam();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_EDITX;
	CEdit m_EDITY;
	CEdit m_EDITZ;
	afx_msg void OnNMCustomdrawSliderLifgt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderLaser(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderLifgt3(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl mScrollLight;
	CSliderCtrl mScrollLaser;
	CSliderCtrl mScrollGrayLevel;
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	
	afx_msg void OnBnClickedButtonSnippintool();
	CComboBox mModel3DChioce;
	afx_msg void OnCbnSelchangeComb3dmodel();
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

struct NewCallbackInfo    // VTK���̲���
{
	const char* Type;
	unsigned long ID;
};