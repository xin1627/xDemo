#pragma once
#include "afxwin.h"
class CxButton :
    public CButton
{
public:
    CxButton();
    ~CxButton();
    DECLARE_MESSAGE_MAP()
    virtual void DrawItem(LPDRAWITEMSTRUCT lpds);


protected:
    void DrawButtonGdiplus(CDC& dc, int x, int y, int width, int height, int statusId, DWORD backgroundColor);
    void DrawButtonGdi(CDC* pDC, int x, int y, int width, int height, int statusId, DWORD backgroundColor);
};
