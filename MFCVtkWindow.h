#pragma once
#include "RegenvtkColor.h"
#include "vtkGUISupportMFCModule.h" // For export macro
#include "afxwin.h"
// MFCVtkWindow �Ի���

class MFCVtkWindow : public CDialogEx
{
	DECLARE_DYNAMIC(MFCVtkWindow)

public:
	MFCVtkWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MFCVtkWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG_3DOCT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

private:
	//vtkWin32OpenGLRenderWindow* pvtkWin32OpenGLRW;


	DECLARE_MESSAGE_MAP()
};
