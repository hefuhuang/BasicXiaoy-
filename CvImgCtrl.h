/************************************************************************/
/*                              OpenCV MFCͼ����ʾ�ؼ� v1.0
/*    �ÿؼ������׼��ɵ�mfc����ʾ�������÷���demo��
/*                                                                               Wish: 512690069
/*                                                                      2016��4��6�� 15:28:58 
/************************************************************************/

#pragma once

#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <afxwin.h>

using namespace std ;
using namespace cv;
//�Զ�����Ϣ����ֵ
#define MsgBase					(WM_USER + 0xA0)
#define MsgLBDown			(MsgBase + 0)					//�����������µ���Ϣ
#define MsgLBUp					(MsgBase + 1)					//���̧����
#define MsgRBDown			(MsgBase + 2)					//�Ҽ�����
#define MsgMove				(MsgBase + 3)					//����ƶ�

#define MsgMBDown			(MsgBase + 4)					//�м�����
#define MsgMBUp				(MsgBase + 5)					//�м�̧��

#define MsgKeyDown			(MsgBase + 6)					//����ĳ�����̰���	
#define MsgDragFile				(MsgBase + 7)					//�϶��ļ����ؼ���ȥ��ʱ��

#define MsgVideoStart			(MsgBase + 8)					//��Ƶ��ʼ��ʱ��
#define MsgVideoOver			(MsgBase + 9)					//��Ƶ������


//�õ�һ֡��Ƶ�����ˣ����忴demo
//1����dlg��ͷ�ļ���д��afx_msg LRESULT onFrame(WPARAM wp, LPARAM lp);����
//2����dlg��BEGIN_MESSAGE_MAP����д��ON_MESSAGE(MsgVideoFrame, onFrame)
//3����dlg��cpp��д��
/*
LRESULT CdemoDlg::onFrame(WPARAM wp, LPARAM lp){
	Mat frame((IplImage*)lp, false);
	flip(frame, frame, -1);
	//��������ڴ���ÿһ֡��ͼ���ˣ����Ƶ�MsgVideoPreDisplay��ϢҲ����ô����
	return 0;
}
*/
#define MsgVideoFrame			(MsgBase + 0x0A)			
#define MsgVideoPreDisplay	(MsgBase + 0x0B)		//��Ƶһ֡����׼����ʾ�ˣ�������MsgVideoFrame֮��

//�ؼ���������Ϣ
#define MsgClick							(MsgBase + 0x0C)

//�ڲ���Ϣ���ڲ�ʹ�ã�����Ҫ���
#define InnerMsgBase					(MsgBase + 0xF0)					//������Ϣ���
#define InnerMsgVideoFrame		(InnerMsgBase + 0)				//���ܵ�һ֡����

//ͼ����ʾ�ؼ�
class CvImgCtrl : public CWnd
{
	DECLARE_DYNAMIC(CvImgCtrl)
	
public:
	//��ͼ��������
	enum ResizeType
	{
		ResizeType_Raw,					//ԭʼ��С�������Ͻ�Ϊ׼��ͼ����Ͷ�󣬲�������
		ResizeType_CenterResize,		//�������ţ�ͼ���ߵȱ������������
		ResizeType_Tensile				//���죬������쵽�ؼ�һ����
	};

	//��Ƶ���ŵ�״̬
	enum VideoState{
		VideoState_Stop,					//��Ƶֹͣ��
		VideoState_Playing,				//��Ƶ������
		VideoState_Pause					//��Ƶ��ͣ��
	};

public:
	CvImgCtrl();
	virtual ~CvImgCtrl();


	//���ӵ��Ի����ϵĿؼ������ӹ��󣬾ͱ������ӹ��ˣ����Ḻ�𽫻�����Ƶ��ؼ���ȥ
	//idd���ؼ���id
	//parent�����ؼ���ָ�룬������dialog���棬��this������
	BOOL linkDlgItem(UINT idd, CWnd* parent);

	//����һ���ؼ��������Ҫ��̬�������͵����������������������CWnd�Ĵ�������
	//pParent��������ָ�룬һ���dialog��thisָ��ͺ���
	//rcPos���ؼ�����λ�ã�����ֱ�Ӹ�CRect()Ҳ�У�Ȼ����OnSize��ߵ�����ߣ����߸�ָ��ֵҲ��
	//autoDelete�����CvImgCtrl* m_show�����֣�ָ�룬����new�ķ�ʽ�õ��Ŀؼ���������ʵ���������ô�����������true��ʱ�򣬿ؼ�����ʱ
	//                    ���Լ������ڴ棨delete this����Ҳ������Ͳ����ֶ���ȥdelete����
	//resizeType�����ŷ�ʽ������ʾͼ��ʹ��ڴ�С��һ��ʱ����������ţ���3�ַ�ʽ����ö������ResizeType�ı�ע
	//defaultColor��Ĭ����ɫ��������Ĭ��ɫ�����������ʾ��ʱ�����ܻ����գ�����ʲô��ɫ�����߸մ������ʱ��ʲô��ɫ��
	bool create(CWnd* pParent, CRect rcPos, bool autoDelete = false, ResizeType resizeType = ResizeType_Raw, CvScalar defaultColor = cvScalarAll(255));

	//��ʼ��Ƶ������ؼ�������VideoCapture����������ֱ�ӿ��Ե���openVideo������Ƶ
	//file����Ƶ�ļ�·����ֱ����VideoCapture.open�����ʧ�ܸ�ʽ��֧�֣��Ǿ�ȥ��VideoCapture
	//waitTime���ӳ�ʱ�䣬ÿһ֡������Ҫ�ӳٵ�ʱ�䣬��λ���룬������ӳ٣������ܿ�ģ���Ȼ����Ըĸĳɴ�VideoCapture�л�ȡ��
	bool openVideo(const char* file, unsigned int waitTime = 30);

	//��ʼ��Ƶ����ͷ������ؼ�������VideoCapture����������ֱ�ӿ��Ե���openVideo������Ƶ
	//cameraIndex������ͷ������һ����VideoCapture��open������opencvĬ��-1�ᵯ��ѡ����Ƶ�Ի���0-n�������n������ͷ����ţ������й̶�˳���
	//waitTime���ӳ�ʱ�䣬ÿһ֡������Ҫ�ӳٵ�ʱ�䣬��λ���룬������ӳ٣������ܿ�ģ���Ȼ����Ըĸĳɴ�VideoCapture�л�ȡ��
	bool openVideo(int cameraIndex = 0, unsigned int waitTime = 30);

	//��ͣ��Ƶ
	void pauseVideo(); 

	//������Ƶ
	void resumeVideo();

	//�ر���Ƶ
	void closeVideo();

	//����ͼ�����ú�ؼ���ˢ����ʾ����ִ��onUpdateImage����������������ͼ���ڲ����Զ�����
	//������õ�ͼ������ͬ��С����ͬͨ����ͼ����ֻ�����copy������Ч���Ǹܸܵ�

	//int  nSize;             /**< sizeof(IplImage) */
	//int  ID;                /**< version (=0)*/
	//int  nChannels;         /**< Most of OpenCV functions support 1,2,3 or 4 channels */
	//int  alphaChannel;      /**< Ignored by OpenCV */
	//int  depth;             /**< Pixel depth in bits: IPL_DEPTH_8U, IPL_DEPTH_8S, IPL_DEPTH_16S,
	//						IPL_DEPTH_32S, IPL_DEPTH_32F and IPL_DEPTH_64F are supported.  */
	//char colorModel[4];     /**< Ignored by OpenCV */
	//char channelSeq[4];     /**< ditto */
	//int  dataOrder;         /**< 0 - interleaved color channels, 1 - separate color channels.
	//						cvCreateImage can only create interleaved images */
	//int  origin;            /**< 0 - top-left origin,
	//						1 - bottom-left origin (Windows bitmaps style).  */
	//int  align;             /**< Alignment of image rows (4 or 8).
	//						OpenCV ignores it and uses widthStep instead.    */
	//int  width;             /**< Image width in pixels.                           */
	//int  height;            /**< Image height in pixels.                          */
	//struct _IplROI *roi;    /**< Image ROI. If NULL, the whole image is selected. */
	//struct _IplImage *maskROI;      /**< Must be NULL. */
	//void  *imageId;                 /**< "           " */
	//struct _IplTileInfo *tileInfo;  /**< "           " */
	//int  imageSize;         /**< Image data size in bytes
	//						(==image->height*image->widthStep
	//						in case of interleaved data)*/
	//char *imageData;        /**< Pointer to aligned image data.         */
	//int  widthStep;         /**< Size of aligned image row in bytes.    */
	//int  BorderMode[4];     /**< Ignored by OpenCV.                     */
	//int  BorderConst[4];    /**< Ditto.                                 */
	//char *imageDataOrigin;



	void setImage(const cv::Mat img){
		//IplImage mImage;
		//mImage.nSize=img.copySize;
		//mImage.ID=img.addref;
		//mImage.nChannels=img.channels;
		//mImage.alphaChannel=0;
		//mImage.depth=img.depth;
		//mImage.colorModel;
		//mImage.channelSeq;  // 
		//mImage.dataOrder=1;  // ������ɫͨ��
		//mImage.origin;
		//mImage.align;
		//mImage.width=img.cols;
		//mImage.height=img.rows;
		//mImage.roi=nullptr; //ѡ��������Ƭ
		//mImage.maskROI = nullptr;
		//mImage.imageId;
		//mImage.tileInfo;
		//mImage.imageSize=img.copySize;
		//mImage.imageData->img.data;
		//mImage.widthStep=img.colRange;
		//mImage.BorderMode;
		//mImage.BorderConst;
		//mImage.imageDataOrigin=img;
	
		
		setImage(&IplImage(img));
	}

	//����ͼ��ipl��ʽ�����ú�ؼ���ˢ����ʾ����ִ��onUpdateImage
	void setImage(const IplImage* img);

	//��ȡ��ǰͼ��
	Mat getImageMat(){ return cv::cvarrToMat(m_img, false); }

	//��ȡ��ǰͼ��
	IplImage* getImage(){return m_img;}

	//������ʾͼ�������ͨ��getImageMat�õ���Mat����IplImage�����޸���������ô��ʹ��onUpdateImage��ˢ�»���Ӧ�õ��ؼ���
	void onUpateImage();

	//��ȡ��ʾͼ����ʾͼ�񼴸��ؼ�һ����С���Ǹ�ͼ�����ſؼ���С�ı���ı�
	IplImage* getDisplayImage(){return m_imgResize;}

	//��ȡ��ʾͼ��Mat
	Mat getDisplayImageMat(){
		return cvarrToMat(m_imgResize, false);
	}

	//������ʾͼ�񣬵���ͨ��getDisplayImage��ȡ����ͼ�񣬲��޸���������ô��ʹ�����������ˢ��Ӧ�õ�������
	void onUpdateDisplayImage();
	
	//�������ŷ�ʽ����3�ַ�ʽ����ResizeType�Ķ�����д�ı�ע�����ú�������Ч��ˢ��
	void setResizeType(ResizeType rt){m_rt = rt; onUpateImage();}

	//�������ݣ���һ��int���Ա�����ʱ��ʹ�ã�����Ҫ��ʲôid֮��ģ�ָ��֮���
	void setData(int data){m_saveData = data;}
	int getData(){return m_saveData;}

	//��ȡ��Ƶ������
	VideoCapture* getVideoCapture(){return &m_videoCapture;}

	//���ص�ǰ������Ƶ״̬
	VideoState getVideoState(){return m_videoState;}

private:
	//����ͼ��ֻ������ͼ�񣬲�����ʾ���ؼ���ȥ
	void _onlySetImage(const IplImage* img);

	//������Ƶ��device_or_file���������-1����0-1024���ڵ����֣�����Ϊ��camera
	//������Ϊ���ļ�·����waittime����֡�ӳ�ʱ��
	bool _startVideo(const void* device_or_file, unsigned int waitTime = 30);

	//�ػ�image��displayimage����resizeimage��
	void redrawResize();

	//�����ʾ���Ǹ�ͼ��
	void voidResize();

	//֪ͨ���ף�Ĭ��wp��this
	LRESULT notifyParent(UINT msg, LPARAM lp = 0);

private:
	VideoCapture m_videoCapture;
	VideoState m_videoState;
	int m_videoWaitTime;  
	unsigned int m_lastdownTime;
	int m_saveData;
	IplImage* m_img;
	IplImage* m_imgResize;
	BITMAPINFO m_bmpHeader;
	bool m_autoDelete;
	CvScalar m_defaultColor;
	ResizeType m_rt;
	CRITICAL_SECTION m_resizeCS;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnNcDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDropFiles(HDROP hDropInfo);

	afx_msg LRESULT OnVideoFrame(WPARAM wp, LPARAM lp);
};


#define BEGIN_MESSAGE_MAP_EX(class_name)				\
	PTM_WARNING_DISABLE													\
	inline const AFX_MSGMAP* class_name::GetMessageMap() const	\
{return GetThisMessageMap();}			 \
	inline const AFX_MSGMAP* PASCAL class_name::GetThisMessageMap()		\
{typedef class_name ThisClass;							\
	typedef CWnd TheBaseClass;							\
	static const AFX_MSGMAP_ENTRY _messageEntries[] = {

#define IMPLEMENT_DYNAMIC_EX(class_name, super_class)			\
AFX_COMDAT const CRuntimeClass class_name::class##class_name = {	\
#class_name, sizeof(class class_name), 0xFFFF, NULL,						\
((CRuntimeClass*)(&super_class::class##super_class)), NULL, NULL };		\
inline CRuntimeClass* class_name::GetRuntimeClass() const \
{ return RUNTIME_CLASS(class_name); }

IMPLEMENT_DYNAMIC_EX(CvImgCtrl, CWnd)

inline static IplImage imgOfROI(const IplImage* img, CvRect roi, bool invalidROI=false)
{
	IplImage ret = *img;
	int imgWidth = img->roi != 0 && !invalidROI ? img->roi->width : img->width;
	int imgHeight = img->roi != 0 && !invalidROI ? img->roi->height : img->height;
	ret.roi = 0;

	if(roi.x >= imgWidth || roi.y >= imgHeight){
		ret.width = 0;
		ret.height = 0;
		ret.imageData = 0;
		return ret;
	}

	//����ü�
	if(roi.x < 0){
		roi.width += roi.x;
		roi.x = 0;
	}

	if(roi.y < 0) {
		roi.height += roi.y;
		roi.y = 0;
	}

	if(roi.x + roi.width > imgWidth)		roi.width = imgWidth - roi.x;
	if(roi.y + roi.height > imgHeight)		roi.height = imgHeight - roi.y;

	CV_Assert(roi.width > 0 && roi.height > 0);
	ret.width = roi.width;
	ret.height = roi.height;
	ret.imageSize = ret.height * ret.widthStep;
	ret.imageDataOrigin = 0;

	if (!invalidROI && img->roi != 0)
		ret.imageData = img->imageData + (img->roi->xOffset + roi.x) * img->nChannels * (img->depth & ~IPL_DEPTH_SIGN) / 8 + (img->roi->yOffset + roi.y) * img->widthStep;
	else
		ret.imageData = img->imageData + roi.x * img->nChannels * (img->depth & ~IPL_DEPTH_SIGN) / 8 + roi.y * img->widthStep;

	return ret;
}

inline static void doEvent(unsigned int waitMS = -1){
	MSG msg;
	unsigned int time = GetTickCount();

	while(GetTickCount() - time < waitMS){
		while(GetTickCount() - time < waitMS && PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			if(msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#define min(a,b) (((a) < (b)) ? (a) : (b))

inline CvImgCtrl::CvImgCtrl(){
	memset(&m_bmpHeader, 0, sizeof(m_bmpHeader));
	m_bmpHeader.bmiHeader.biSize = sizeof(m_bmpHeader);
	m_bmpHeader.bmiHeader.biXPelsPerMeter = 72;
	m_bmpHeader.bmiHeader.biYPelsPerMeter = 72;
	m_bmpHeader.bmiHeader.biPlanes = 1;
	m_imgResize = NULL;
	m_img = nullptr;
	m_rt = ResizeType_Tensile;
	m_autoDelete = false;
	m_videoState = VideoState_Stop;
	m_defaultColor = cvScalarAll(255);
	InitializeCriticalSection(&m_resizeCS);
}

inline CvImgCtrl::~CvImgCtrl(){
	DeleteCriticalSection(&m_resizeCS);
}

BEGIN_MESSAGE_MAP_EX(CvImgCtrl)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_NCDESTROY()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCHITTEST()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_DROPFILES()
	ON_MESSAGE(InnerMsgVideoFrame, OnVideoFrame)
END_MESSAGE_MAP()

inline bool CvImgCtrl::openVideo(const char* file, unsigned int waitTime){
	return _startVideo(file, waitTime);
}

inline void CvImgCtrl::pauseVideo(){
	if(m_videoState == VideoState_Playing)
		m_videoState = VideoState_Pause;
}

inline bool CvImgCtrl::openVideo(int cameraIndex, unsigned int waitTime){
	return _startVideo((const void*)cameraIndex, waitTime);
}

inline void CvImgCtrl::resumeVideo(){
	if(m_videoState == VideoState_Pause){
		m_videoState = VideoState_Playing;
		PostMessage(InnerMsgVideoFrame, 0, 0);
	}
}

inline void CvImgCtrl::closeVideo(){
	m_videoState = VideoState_Stop;
	if(m_videoCapture.isOpened())
		m_videoCapture.release();
}

inline bool CvImgCtrl::_startVideo(const void* device_or_file, unsigned int waitTime){
	if(!::IsWindow(m_hWnd)) return false;

	int dof = (int)device_or_file;
	if(m_videoCapture.isOpened())
		m_videoCapture.release();

	bool success = false;
	const int max_count_of_device_index = 1024;
	const char* file = (const char*)device_or_file;
	const int device_index = (int)device_or_file;
	m_videoWaitTime = waitTime;

	if(dof == -1 || dof >= 0 && dof <= max_count_of_device_index)
		success = m_videoCapture.open(device_index);
	else
		success = m_videoCapture.open(file);

	m_videoState = success ? VideoState_Playing : VideoState_Stop;
	if(success) {
		cv::Mat frame;
		m_videoCapture >> frame;
		if(!frame.empty()){
			_onlySetImage(&IplImage(frame));
			notifyParent(MsgVideoStart, (LPARAM)device_or_file);
			notifyParent(MsgVideoFrame, (LPARAM)m_img);

			if (m_imgResize != 0){
				redrawResize();
				notifyParent(MsgVideoPreDisplay, (LPARAM)m_imgResize);

				this->onUpdateDisplayImage();
			}

			if(m_videoState == VideoState_Playing)
				PostMessage(InnerMsgVideoFrame, 0, 0);
		}else{
			success = false;
		}
	}
	m_videoState = success ? VideoState_Playing : VideoState_Stop;
	return success;
}

inline LRESULT CvImgCtrl::notifyParent(UINT msg, LPARAM lp){
	return ::SendMessage(GetParent()->m_hWnd, msg, (WPARAM)this, lp);
}

inline LRESULT CvImgCtrl::OnVideoFrame(WPARAM wp, LPARAM lp){
	if(m_videoState == VideoState_Playing){
		bool grab = m_videoCapture.grab();
		bool retrieve = grab && m_videoCapture.retrieve(cvarrToMat(m_img, false));

		if(retrieve){
			notifyParent(MsgVideoFrame, (LPARAM)m_img);

			if (m_imgResize != 0){
				redrawResize();
				notifyParent(MsgVideoPreDisplay, (LPARAM)m_imgResize);

				this->onUpdateDisplayImage();
			}

			if(m_videoState == VideoState_Playing){
				doEvent(m_videoWaitTime);
				PostMessage(InnerMsgVideoFrame, wp, lp);
			}
		}else{
			notifyParent(MsgVideoOver);
			m_videoState = VideoState_Stop;
		}
	}
	return 0;
}

inline bool CvImgCtrl::create(
	CWnd* pParent, 
	CRect rcPos, 
	bool autoDelete /*= false*/,
	ResizeType rt /*= _ResizeType_Non*/, 
	CvScalar defaultColor /*= cvScalarAll(255)*/){

		m_defaultColor = defaultColor;
		m_autoDelete = autoDelete;
		m_rt = rt;
	return CWnd::Create(_T("Static"), 0, WS_OVERLAPPED | WS_CHILD | WS_VISIBLE, rcPos, pParent, 0, 0) != 0;
}

inline void CvImgCtrl::redrawResize(){
	if(m_imgResize == 0 || m_img == 0 || m_img->width * m_img->height == 0)
		return;

	EnterCriticalSection(&m_resizeCS);
	switch(m_rt)	{
	case ResizeType_Tensile:	{
			if(m_img->nChannels != 3){
				IplImage* re = cvCreateImage(cvGetSize(m_img), 8, 3);
				cvCvtColor(m_img, re, CV_GRAY2BGR);
				cvResize(re, m_imgResize);
				cvReleaseImage(&re);
			}
			else
				cvResize(m_img, m_imgResize);
		}
		break;

	case ResizeType_Raw: {
			voidResize();
			CvRect roi = {0, 0, min(m_img->width, m_imgResize->width), min(m_img->height, m_imgResize->height)};
			if(m_img->nChannels != 3)
				cvCvtColor(&imgOfROI(m_img, roi), &imgOfROI(m_imgResize, roi), CV_GRAY2BGR);
			else
				cvCopy(&imgOfROI(m_img, roi), &imgOfROI(m_imgResize, roi));
		}
		break;

	case ResizeType_CenterResize: {
			voidResize();
			int nw = m_imgResize->width;
			int nh = int(m_imgResize->width / (double)m_img->width * m_img->height);

			if (nh > m_imgResize->height)	{
				nh = m_imgResize->height;
				nw = int(m_imgResize->height / (double)m_img->height * m_img->width);
			}

			cvSetImageROI(m_imgResize, cvRect((m_imgResize->width - nw) / 2, (m_imgResize->height - nh) / 2, nw, nh));
			if(m_img->nChannels != 3){
				IplImage* re = cvCreateImage(cvGetSize(m_img), 8, 3);
				cvCvtColor(m_img, re, CV_GRAY2BGR);
				cvResize(re, m_imgResize);
				cvReleaseImage(&re);
			}
			else
				cvResize(m_img, m_imgResize);
			cvResetImageROI(m_imgResize);
		}
		break;
	}
	LeaveCriticalSection(&m_resizeCS);
}

inline void CvImgCtrl::onUpateImage(){
	if (m_imgResize != 0 && ::IsWindow(m_hWnd)){
		redrawResize();
		this->onUpdateDisplayImage();
	}
}

inline void CvImgCtrl::voidResize(){
	cvSet(m_imgResize, m_defaultColor);
}

inline BOOL CvImgCtrl::linkDlgItem(UINT idd, CWnd* parent){
	BOOL r = CWnd::SubclassDlgItem(idd, parent);
	if(r){
		CRect rc;
		GetWindowRect(&rc);

		OnSize(0, rc.Width(), rc.Height());
	}
	return r;
}

inline void CvImgCtrl::OnSize(UINT nType, int cx, int cy){
	if (cx < 1 || cy < 1){
		CWnd::OnSize(nType, cx, cy);
		return;
	}

	EnterCriticalSection(&m_resizeCS);
	cvReleaseImage(&m_imgResize);
	m_imgResize = cvCreateImage(cvSize(cx, cy), 8, 3);
	LeaveCriticalSection(&m_resizeCS);

	if(m_img != 0)
		redrawResize();
	else
		voidResize();

	m_bmpHeader.bmiHeader.biBitCount = m_imgResize->nChannels * m_imgResize->depth;
	m_bmpHeader.bmiHeader.biHeight = -m_imgResize->height;
	m_bmpHeader.bmiHeader.biWidth = m_imgResize->width;
	m_bmpHeader.bmiHeader.biSizeImage = m_imgResize->imageSize;
	this->onUpdateDisplayImage();
}

inline void CvImgCtrl::_onlySetImage(const IplImage* img)
{
	if (img == NULL)	
	{
		if (m_img != 0)
			cvReleaseImage(&m_img);

		if (m_imgResize != 0)
			voidResize();

		return;
	}
	if (nullptr == m_img)
	{
		m_img = (IplImage*)cvClone(img);
	}
	else
	{
		if (
			m_img->width != img->width || 
			m_img->height != img->height || 
			m_img->nChannels != img->nChannels || 
			m_img->depth != img->depth){

				cvReleaseImage(&m_img);
				m_img = (IplImage*)cvClone(img);
		}
		else
			memcpy(m_img->imageData, img->imageData, min(img->imageSize, m_img->imageSize));
		//cvCopy(img, m_img);
	}
}

inline void CvImgCtrl::setImage(const IplImage* img){
	_onlySetImage(img);
	onUpateImage();
}

inline void CvImgCtrl::OnDestroy(){
	CWnd::OnDestroy();
	if (m_img != 0)
		cvReleaseImage(&m_img);

	if (m_imgResize != 0)
		cvReleaseImage(&m_imgResize);
}

inline BOOL CvImgCtrl::OnEraseBkgnd(CDC* pDC){
	return TRUE;
}

inline void CvImgCtrl::onUpdateDisplayImage(){
	Invalidate();
	UpdateWindow();
}

inline void CvImgCtrl::OnPaint(){
	if(m_imgResize != 0){
		PAINTSTRUCT ps;
		HDC hDC = ::BeginPaint(m_hWnd, &ps);
		CRect rcPaint = ps.rcPaint;
		StretchDIBits(hDC, 0, 0, m_imgResize->width, m_imgResize->height, 0, 0, m_imgResize->width, m_imgResize->height, m_imgResize->imageData, &m_bmpHeader, DIB_RGB_COLORS, SRCCOPY);
		::EndPaint(m_hWnd, &ps);
	}
	else
		CWnd::OnPaint();
}

inline void CvImgCtrl::OnNcDestroy(){
	CWnd::OnNcDestroy();

	if (m_autoDelete)
		delete this;
}

inline void CvImgCtrl::OnMouseMove(UINT nFlags, CPoint point){
	notifyParent(MsgMove, (LPARAM)&point);
}

inline void CvImgCtrl::OnLButtonDown(UINT nFlags, CPoint point){
	m_lastdownTime = ::GetTickCount();
	notifyParent(MsgLBDown, (LPARAM)&point);
}

inline void CvImgCtrl::OnLButtonUp(UINT nFlags, CPoint point){
	notifyParent(MsgLBUp, (LPARAM)&point);

	if(GetTickCount() - m_lastdownTime <= 300)
		notifyParent(MsgClick, (LPARAM)&point);
}

inline void CvImgCtrl::OnRButtonDown(UINT nFlags, CPoint point){
	notifyParent(MsgRBDown, (LPARAM)&point);
}

inline LRESULT CvImgCtrl::OnNcHitTest(CPoint point){
	return HTCLIENT;
}

inline void CvImgCtrl::OnMButtonDown(UINT nFlags, CPoint point){
	notifyParent(MsgMBDown, (LPARAM)&point);
}

inline void CvImgCtrl::OnMButtonUp(UINT nFlags, CPoint point){
	notifyParent(MsgMBUp, (LPARAM)&point);
}

inline void CvImgCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){
	notifyParent(MsgKeyDown, nChar);
}

inline void CvImgCtrl::OnDropFiles(HDROP hDropInfo){
	CWnd::OnDropFiles(hDropInfo);
	notifyParent(MsgDragFile, (LPARAM)hDropInfo);
}