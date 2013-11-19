// SettingStyleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingStyleDlg.h"
#include "afxdialogex.h"


// CSettingStyleDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSettingStyleDlg, CDialogEx)

CSettingStyleDlg::CSettingStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingStyleDlg::IDD, pParent)
{

	m_uiStyle = 0;
	m_uiColor = 0;
}

CSettingStyleDlg::~CSettingStyleDlg()
{
}

void CSettingStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_AERO_STYLE, (int&)m_uiStyle);
	DDX_Radio(pDX, IDC_STYLE_RED, (int&)m_uiColor);
}


BEGIN_MESSAGE_MAP(CSettingStyleDlg, CDialogEx)
	ON_BN_CLICKED(IDC_AERO_STYLE, &CSettingStyleDlg::OnBnClickedAeroStyle)
	ON_BN_CLICKED(IDC_FLAT_STYLE, &CSettingStyleDlg::OnBnClickedFlatStyle)
	ON_BN_CLICKED(IDC_STYLE_RED, &CSettingStyleDlg::OnBnClickedStyleRed)
	ON_BN_CLICKED(IDC_STYLE_GREEN, &CSettingStyleDlg::OnBnClickedStyleGreen)
	ON_BN_CLICKED(IDC_STYLE_BLUE, &CSettingStyleDlg::OnBnClickedStyleBlue)
END_MESSAGE_MAP()


// CSettingStyleDlg �޽��� ó�����Դϴ�.


void CSettingStyleDlg::OnBnClickedAeroStyle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedFlatStyle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleRed()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleGreen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleBlue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
