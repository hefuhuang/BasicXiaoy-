#pragma once



// CBFunction ������ͼ

class CBFunction : public CFormView
{
	DECLARE_DYNCREATE(CBFunction)

protected:
	CBFunction();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnPaint();
};


