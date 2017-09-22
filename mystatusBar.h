#pragma once


// mystatusBar

class mystatusBar : public CStatusBar
{
	DECLARE_DYNAMIC(mystatusBar)

public:

	mystatusBar();
	virtual ~mystatusBar(); 
	void Create();

	//virtual COLORREF OnFillBackground(CDC* pDC) override
	//{
	//	return RGB(255, 0, 0); //return whatever new color you want
	//} 

protected:
	DECLARE_MESSAGE_MAP()
};


