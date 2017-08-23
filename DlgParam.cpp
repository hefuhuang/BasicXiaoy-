// DlgParam.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "DlgParam.h"
#include "afxdialogex.h"


// DlgParam dialog

IMPLEMENT_DYNAMIC(DlgParam, CDialogEx)

DlgParam::DlgParam(CWnd* pParent /*=NULL*/)
: CDialogEx(DlgParam::IDD, pParent)
{

}

DlgParam::~DlgParam()
{
}

void DlgParam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgParam, CDialogEx)
END_MESSAGE_MAP()


// DlgParam message handlers
