#include "stdafx.h"
#include "CxComboBox.h"


CxComboBox::CxComboBox()
{
}


CxComboBox::~CxComboBox()
{
}
BEGIN_MESSAGE_MAP(CxComboBox, CComboBox)
    ON_WM_PAINT()
END_MESSAGE_MAP()



//virtual function
void CxComboBox::DrawItem(LPDRAWITEMSTRUCT lpds)
{
    CDC *pdc = CDC::FromHandle(lpds->hDC);

    CRect rect = lpds->rcItem;
    Gdiplus::Graphics g(pdc->m_hDC);

    Gdiplus::Rect r(0, rect.top, rect.Width(), rect.Height());
    Gdiplus::Color bkcolor(158, 158, 158);
    Gdiplus::Color bordercolor(158, 0, 158);
    Gdiplus::Color forecolor(0, 158, 0);

    //draw border
    Gdiplus::SolidBrush bkbrush(bkcolor);
    Gdiplus::SolidBrush borderbrush(bordercolor);
    g.FillRectangle(&borderbrush, r);
    r.Inflate(-1, -1);

    //draw background
    g.FillRectangle(&bkbrush, r);
    
    CString text;
    this->GetLBText(lpds->itemID, text);

    //draw text
    Gdiplus::Font font(pdc->m_hDC);

    Gdiplus::StringFormat sf = new  Gdiplus::StringFormat();
    sf.SetLineAlignment(Gdiplus::StringAlignmentNear);
    //sf.SetAlignment(Gdiplus::StringAlignmentCenter);
    
    Gdiplus::RectF rf(r.X, r.Y, r.Width, r.Height);
    g.DrawString(text, text.GetLength(), &font, rf, &sf, &borderbrush);

}


void CxComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpms)
{
    //owner draw = Variable
    lpms->itemHeight = 32;
}



void CxComboBox::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: Add your message handler code here
                       // Do not call CComboBox::OnPaint() for painting messages
    CRect rc;
    GetWindowRect(&rc);

    Gdiplus::Graphics g(dc.m_hDC);
    Gdiplus::SolidBrush color(Gdiplus::Color::Purple);
    Gdiplus::Rect rect(0, 0, rc.Width(), rc.Height());

    g.FillRectangle(&color,rect);

    //draw cedit
}
