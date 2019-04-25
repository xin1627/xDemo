
// XCtrlDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XCtrlDemo.h"
#include "XCtrlDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXCtrlDemoDlg dialog



CXCtrlDemoDlg::CXCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_XCTRLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, m_edit);
    DDX_Control(pDX, IDC_BUTTON1, m_button);
    DDX_Control(pDX, IDC_COMBO1, m_xcombo);
}

BEGIN_MESSAGE_MAP(CXCtrlDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CXCtrlDemoDlg message handlers

BOOL CXCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    m_xcombo.AddString(L"Hello");
    m_xcombo.AddString(L"World");
    m_xcombo.AddString(L"People");
    m_xcombo.SetItemHeight(-1, 32);
    //m_xcombo.SetItemHeight()  set line height
    CRect rect;
    int h = m_xcombo.GetItemHeight(-1);
    int h2 = m_xcombo.GetItemHeight(0);
    m_xcombo.GetWindowRect(&rect);

    int height = h + h2 * 3;
    

    int border = GetSystemMetrics(SM_CYEDGE) * 2;
    height += border * 2;
    
    //m_xcombo.MoveWindow(0, 0, rect.Width(), height, SWP_NOMOVE);
    m_xcombo.SetWindowPos(NULL, 0, 0, rect.Width(), height, SWP_NOMOVE | SWP_NOZORDER);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CXCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CXCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

