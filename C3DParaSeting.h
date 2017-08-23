#pragma once


// C3DParaSeting dialog

class C3DParaSeting : public CPropertyPage
{
	DECLARE_DYNAMIC(C3DParaSeting)

public:
	C3DParaSeting();
	virtual ~C3DParaSeting();

// Dialog Data
	enum { IDD = IDD_DIALOG3DParam };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnApply();
	afx_msg void OnPaint();
};
