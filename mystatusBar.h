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
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);  // //���ء�   //  ����  ������������ �����뺯������ͬ ��������virtual    // ���ػ���  ��������ͬ  ������ͬ���ǲ�ͬ ������virtual �ؼ��� 
//	virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM, UINT nID = AFX_IDW_STATUS_BAR);

protected:
	DECLARE_MESSAGE_MAP()

	
};
