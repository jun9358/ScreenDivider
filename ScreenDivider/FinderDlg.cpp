// FinderDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "FinderDlg.h"
#include "afxdialogex.h"


// CFinderDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFinderDlg, CDialogEx)

CFinderDlg::CFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinderDlg::IDD, pParent)
{
	m_btnFinder.LoadBitmaps(IDB_FINDER, IDB_FINDER, IDB_FINDER, IDB_FINDER);
	m_Y = 0;
	m_X = 0;
	m_WIDTH = 0;
	m_HEIGHT = 0;
}

CFinderDlg::~CFinderDlg()
{
}

void CFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_FINDER, m_btnFinder);
	DDX_Text(pDX, IDC_STATIC_Y, m_Y);
	DDX_Text(pDX, IDC_STATIC_X, m_X);
	DDX_Text(pDX, IDC_STATIC_WIDTH, m_WIDTH);
	DDX_Text(pDX, IDC_STATIC_HEIGHT, m_HEIGHT);
}


BEGIN_MESSAGE_MAP(CFinderDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CFinderDlg �޽��� ó�����Դϴ�.
BOOL CFinderDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CButton *pButton;
	pButton = (CButton *)GetDlgItem(IDC_BUTTON_FINDER);
		
	CRect rectButton;
	pButton->GetWindowRect(rectButton);

	if (rectButton.PtInRect(pMsg->pt))
	{
		switch (pMsg->message)
		{
		case WM_LBUTTONDOWN:
			SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_FINDER)));
			SetCapture();
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONUP:
			break;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}