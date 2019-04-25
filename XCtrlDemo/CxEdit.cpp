#include "stdafx.h"
#include "CxEdit.h"


CxEdit::CxEdit()
{
    m_bkclr = RGB(158, 158, 158);
    m_txtclr = RGB(0, 158, 0);
    m_borderclr = RGB(0, 0, 158);
}


CxEdit::~CxEdit()
{
}
BEGIN_MESSAGE_MAP(CxEdit, CEdit)
    ON_CONTROL_REFLECT(EN_KILLFOCUS, &CxEdit::OnEnKillfocus)
    ON_CONTROL_REFLECT(EN_SETFOCUS, &CxEdit::OnEnSetfocus)
    ON_WM_CTLCOLOR_REFLECT()
    ON_WM_NCPAINT()
END_MESSAGE_MAP()


void CxEdit::OnEnKillfocus()
{
    // TODO: Add your control notification handler code here
    this->SetWindowText(L"Input Text");
}


void CxEdit::OnEnSetfocus()
{
    // TODO: Add your control notification handler code here
    this->SetWindowText(L"");
}


HBRUSH CxEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
    // TODO:  Change any attributes of the DC here
    pDC->SetBkColor(m_bkclr);
    pDC->SetTextColor(m_txtclr);

    HBRUSH bkBrush = CreateSolidBrush(m_bkclr);
    // TODO:  Return a non-NULL brush if the parent's handler should not be called
    return bkBrush;
}

//OnNcPaint just draw border.
void CxEdit::OnNcPaint()
{
    // TODO: Add your message handler code here
    // Do not call CEdit::OnNcPaint() for painting messages
    CRect rect;
    GetWindowRect(&rect);
    ScreenToClient(&rect);
    rect.OffsetRect(-rect.left, -rect.top);

    Gdiplus::Graphics g(GetWindowDC()->m_hDC);

    //g.draw

    CDC* pDC = GetWindowDC();

    if (pDC != NULL)
    {
        if (GetFocus() == this)
        {
            m_borderclr = RGB(0, 158, 0);
        }
        else 
        {
            m_borderclr = RGB(0, 0, 158);
        }
        pDC->Draw3dRect(&rect, m_borderclr, m_borderclr);
        rect.InflateRect(-1, -1);
        pDC->Draw3dRect(&rect, m_bkclr, m_bkclr);
        ReleaseDC(pDC);
    }
}
