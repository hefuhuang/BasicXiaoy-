#pragma once


// SeconedInterface dialog

class SeconedInterface : public CDialogEx
{
	DECLARE_DYNAMIC(SeconedInterface)

public:
	SeconedInterface(CWnd* pParent = NULL);   // standard constructor
	virtual ~SeconedInterface();

	virtual void OnFinalRelease();

// Dialog Data
	enum { IDD = IDD_DIALOG_3DOCT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	int vtkMfcWindow;
	int MfcVtkWindow;
};
