#pragma once


// OCTProgressBar

class OCTProgressBar : public CStatusBar
{
	DECLARE_DYNAMIC(OCTProgressBar)

public:
	OCTProgressBar();
	virtual ~OCTProgressBar();
	CProgressCtrl& GetProgressCtrl()
	{
		return m_Progress;
	};

int OnCreate(LPCREATESTRUCT lpCreateStruct);
void OnSize(UINT nType, int cx, int cy);
	
private:
	CProgressCtrl m_Progress;

protected:
	DECLARE_MESSAGE_MAP()
};


