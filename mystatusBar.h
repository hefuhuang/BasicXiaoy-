#pragma once


// mystatusBar

class mystatusBar : public CStatusBar
{
	DECLARE_DYNAMIC(mystatusBar)

public:

	mystatusBar();
	virtual ~mystatusBar(); 
//	void Create(); 

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);  // //重载。   //  覆盖  基类与派生类 参数与函数名相同 基类必须加virtual    // 隐藏基类  函数名相同  参数相同或是不同 基类无virtual 关键字 
//	virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM, UINT nID = AFX_IDW_STATUS_BAR);

protected:
	DECLARE_MESSAGE_MAP()

	
};
