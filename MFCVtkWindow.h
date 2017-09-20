#pragma once
#include "RegenvtkColor.h"
#include "vtkGUISupportMFCModule.h" // For export macro
#include "afxwin.h"
// MFCVtkWindow 对话框

class MFCVtkWindow : public CDialogEx
{
	DECLARE_DYNAMIC(MFCVtkWindow)

public:
	MFCVtkWindow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MFCVtkWindow();

// 对话框数据
	enum { IDD = IDD_DIALOG_3DOCT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

private:
	//vtkWin32OpenGLRenderWindow* pvtkWin32OpenGLRW;


	DECLARE_MESSAGE_MAP()
};
