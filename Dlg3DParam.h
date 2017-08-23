#pragma once


// Dlg3DParam dialog

class Dlg3DParam : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg3DParam)

public:
	Dlg3DParam(CWnd* pParent = NULL);   // standard constructor
	virtual ~Dlg3DParam();

// Dialog Data
	enum { IDD = IDD_DIALOG3DParam };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
