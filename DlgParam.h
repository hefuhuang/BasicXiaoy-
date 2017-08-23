#pragma once


// DlgParam dialog

class DlgParam : public CDialogEx
{
	DECLARE_DYNAMIC(DlgParam)

public:
	DlgParam(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgParam();

// Dialog Data
	enum { IDD = IDD_DIALOGParam };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
