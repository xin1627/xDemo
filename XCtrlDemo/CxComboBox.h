#pragma once
#include "afxwin.h"
class CxComboBox :
    public CComboBox
{
public:
    CxComboBox();
    ~CxComboBox();
    DECLARE_MESSAGE_MAP()
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT /*lpMeasureItemStruct*/);
    afx_msg void OnPaint();
};

