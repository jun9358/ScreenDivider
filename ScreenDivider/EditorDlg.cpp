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
	, m_isMouseDown(false)
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
	m_pointStart = point;
	m_isMouseDown = TRUE;

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_isMouseDown = FALSE;

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_isMouseDown)
	{
		InvalidateRect(NULL,TRUE);
		UpdateWindow();
		CClientDC dc(this); // device context for painting
		dc.Rectangle(m_pointStart.x, m_pointStart.y
					, point.x, point.y);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}