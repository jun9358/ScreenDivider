// EditorTransDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorTransDlg.h"
#include "afxdialogex.h"
#include "EditorDlg.h"


// CEditorTransDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorTransDlg, CFlatDialogEx)

CEditorTransDlg::CEditorTransDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorTransDlg::IDD, pParent)
{

}

CEditorTransDlg::~CEditorTransDlg()
{
}

void CEditorTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_TRANS, m_scCtrl);
}


BEGIN_MESSAGE_MAP(CEditorTransDlg, CFlatDialogEx)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_TRANS, &CEditorTransDlg::OnNMCustomdrawSliderTrans)
END_MESSAGE_MAP()


// CEditorTransDlg �޽��� ó�����Դϴ�.


BOOL CEditorTransDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.


	
      m_scCtrl.SetRange(0, 255);//Set area
	  m_scCtrl.SetRangeMin(0);//Set Minumum
	  m_scCtrl.SetRangeMax(255);//Set Maximum
      m_scCtrl.SetPos(128);//Set first location
      m_scCtrl.SetLineSize(1);//Set each of width
	  m_scCtrl.SetPageSize(1);
 

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


HBRUSH CEditorTransDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFlatDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


void CEditorTransDlg::OnNMCustomdrawSliderTrans(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	int nPos = m_scCtrl.GetPos();
	
	HWND hEditorDlg;
	hEditorDlg = ((CEditorDlg *)(GetParent()->GetParent()))->GetSafeHwnd();
	
	SetTransparentWindow(hEditorDlg, nPos);
}
