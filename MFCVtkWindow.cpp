// MFCVtkWindow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "MFCVtkWindow.h"
#include "afxdialogex.h"


// MFCVtkWindow �Ի���

IMPLEMENT_DYNAMIC(MFCVtkWindow, CDialogEx)

MFCVtkWindow::MFCVtkWindow(CWnd* pParent /*=NULL*/)
	: CDialogEx(MFCVtkWindow::IDD, pParent)
{

}

MFCVtkWindow::~MFCVtkWindow()
{
	//delete MfcVtkWind;
	//MfcVtkWind=nullptr;
}

void MFCVtkWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCVtkWindow, CDialogEx)

END_MESSAGE_MAP()


// MFCVtkWindow ��Ϣ�������
