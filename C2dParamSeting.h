#pragma once


// C2dParamSeting dialog

class C2dParamSeting : public CPropertyPage
{
	DECLARE_DYNAMIC(C2dParamSeting)

public:
	C2dParamSeting();
	virtual ~C2dParamSeting();

// Dialog Data
	enum { IDD = IDD_DIALOGParam };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnApply();
	afx_msg void OnPaint();
};
