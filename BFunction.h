#pragma once



// CBFunction 窗体视图

class CBFunction : public CFormView
{
	DECLARE_DYNCREATE(CBFunction)

protected:
	CBFunction();           // 动态创建所使用的受保护的构造函数
	virtual ~CBFunction();

public:
	enum { IDD = IDD_FORMVIEWbutton };

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif

#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnPaint();
};


