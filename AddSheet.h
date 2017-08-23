#pragma once

#include "C2dParamSeting.h"
#include "C3DParaSeting.h"
#include "Dlg3DParam.h"
#include "DlgParam.h"
// CAddSheet

class CAddSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CAddSheet)

public:
	CAddSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CAddSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual void SetModifyed();


	virtual ~CAddSheet();
private:
	C3DParaSeting m3Dparam;
	C2dParamSeting m2DParam;

protected:
	DECLARE_MESSAGE_MAP()
};


