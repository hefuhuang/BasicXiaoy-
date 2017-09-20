// SeconedInterface.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_OCT.h"
#include "SeconedInterface.h"
#include "afxdialogex.h"


// SeconedInterface dialog

IMPLEMENT_DYNAMIC(SeconedInterface, CDialogEx)

SeconedInterface::SeconedInterface(CWnd* pParent /*=NULL*/)
	: CDialogEx(SeconedInterface::IDD, pParent)
	, vtkMfcWindow(0)
	, MfcVtkWindow(0)
{

	EnableAutomation();

}

SeconedInterface::~SeconedInterface()
{
}

void SeconedInterface::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialogEx::OnFinalRelease();
}

void SeconedInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SeconedInterface, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(SeconedInterface, CDialogEx)
END_DISPATCH_MAP()

// Note: we add support for IID_ISeconedInterface to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {BFB60BDC-8188-439E-8837-0EBBD7D241C1}
static const IID IID_ISeconedInterface =
{ 0xBFB60BDC, 0x8188, 0x439E, { 0x88, 0x37, 0xE, 0xBB, 0xD7, 0xD2, 0x41, 0xC1 } };

BEGIN_INTERFACE_MAP(SeconedInterface, CDialogEx)
	INTERFACE_PART(SeconedInterface, IID_ISeconedInterface, Dispatch)
END_INTERFACE_MAP()


// SeconedInterface message handlers
