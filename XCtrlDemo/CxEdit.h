#pragma once
#include "afxwin.h"
class CxEdit :
    public CEdit
{
public:
    CxEdit();
    ~CxEdit();
    DECLARE_MESSAGE_MAP()
    afx_msg void OnEnKillfocus();
    afx_msg void OnEnSetfocus();
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    afx_msg void OnNcPaint();


private:
    COLORREF m_bkclr;
    COLORREF m_txtclr;
    COLORREF m_borderclr;
};

