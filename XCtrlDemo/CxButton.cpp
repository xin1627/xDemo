#include "stdafx.h"
#include "CxButton.h"


CxButton::CxButton()
{
    
}


CxButton::~CxButton()
{
}
BEGIN_MESSAGE_MAP(CxButton, CButton)
END_MESSAGE_MAP()

//used to draw this item.
void CxButton::DrawItem(LPDRAWITEMSTRUCT lpds)
{
    //Gdiplus::Graphics g;
    CDC *pDC = CDC::FromHandle(lpds->hDC);
    CRect r = lpds->rcItem;

    //Gdiplus::Graphics g(pDC->m_hDC);

    //Gdiplus::SolidBrush bk(Gdiplus::Color::Blue);
    //g.FillRectangle(&bk, 0, 0, r.Width(), r.Height());

    DrawButtonGdiplus(*pDC, 0, 0, r.Width(), r.Height(), PBST_NORMAL,RGB(158, 0, 158));
    //DrawButtonGdi(pDC, 0, 0, r.Width(), r.Height(), PBST_NORMAL, RGB(158, 0, 158));
}

void CxButton::DrawButtonGdiplus(CDC& dc, int x, int y, int width, int height, int statusId, DWORD backgroundColor)
{
    //using namespace Gdiplus;
    // create graphics and clear background with default color (prevent flicker)
    Gdiplus::Graphics graphics(dc.m_hDC);

    //GetWindowRect()
    Gdiplus::Rect rect(x, y, width, height);
    Gdiplus::Color bkColor;
    Gdiplus::Color borderColor;

    bkColor.SetFromCOLORREF(backgroundColor);
    borderColor.SetFromCOLORREF(RGB(0, 158, 0));

    //draw border
    Gdiplus::SolidBrush border(borderColor);
    graphics.FillRectangle(&border, rect);
    rect.Inflate(-1, -1);
    //draw background

    //DWORD backgroundColor  the color format is wrong
    Gdiplus::SolidBrush background(bkColor);
    graphics.FillRectangle(&background, rect);

    Gdiplus::Font font(dc.m_hDC);

    //draw text
    Gdiplus::StringFormat sf = new  Gdiplus::StringFormat();
    sf.SetLineAlignment(Gdiplus::StringAlignmentCenter);
    sf.SetAlignment(Gdiplus::StringAlignmentCenter);
    CString str = L"xbutton";
    Gdiplus::RectF rf(rect.X, rect.Y, rect.Width, rect.Height);

    graphics.DrawString(L"xbutton", 7, &font, rf, &sf, &border);
}


void CxButton::DrawButtonGdi(CDC *pDC, int x, int y, int width, int height, int statusId, DWORD backgroundColor)
{
    CRect rect(x, y, width, height);
    pDC->SelectStockObject(NULL_BRUSH);
    pDC->FillSolidRect(rect, backgroundColor);
}
