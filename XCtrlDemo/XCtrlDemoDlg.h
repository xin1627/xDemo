
// XCtrlDemoDlg.h : header file
//

#pragma once
#include "CxEdit.h"
#include "afxwin.h"
#include "CxButton.h"
#include "CxComboBox.h"

// CXCtrlDemoDlg dialog
class CXCtrlDemoDlg : public CDialogEx
{
// Construction
public:
	CXCtrlDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XCTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    CxEdit m_edit;
    CxButton m_button;
    CxComboBox m_xcombo;
};
