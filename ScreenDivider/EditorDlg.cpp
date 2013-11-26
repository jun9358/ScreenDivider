// EditorDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorDlg.h"
#include "afxdialogex.h"



// CEditorDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorDlg, CDialogEx)

	CEditorDlg::CEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorDlg::IDD, pParent)
{

}

CEditorDlg::~CEditorDlg()
{
}

void CEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CEditorDlg �޽��� ó�����Դϴ�.


void CEditorDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	m_start = point;
	m_isDown = true;
	

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_isDown = false;
	form.AddSDWindow(m_start,m_end);
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_isDown)
	{
		m_end = point;

		CDC *pDC;
		pDC = GetDC();
		pDC->Rectangle(m_start.x, m_start.y, m_end.x, m_end.y);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

BOOL CEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_isDown = false;

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// Get current dialog handle
	HWND hDlg = NULL;
	hDlg = GetSafeHwnd();

	// Set transparent
	SetTransparentWindow(hDlg, 128);
	
	// Get screen
	CWnd *pScreen;
	pScreen = GetDesktopWindow();

	CRect rectScreen;
	pScreen->GetWindowRect(rectScreen);

	// Resize to screen
	MoveWindow(rectScreen);

	// Show tool dialog
	m_pDlgEditorTool = new CEditorToolDlg();
	m_pDlgEditorTool->Create(IDD_EDITOR_TOOL_DIALOG, (CWnd *)this);
	m_pDlgEditorTool->ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
