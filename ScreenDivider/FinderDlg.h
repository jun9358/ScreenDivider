#pragma once
#include "afxwin.h"


// CFinderDlg ��ȭ �����Դϴ�.

class CFinderDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CFinderDlg)

public:
	CFinderDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFinderDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CBitmapButton m_btnFinder;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_Y;
	int m_X;
	int m_WIDTH;
	int m_HEIGHT;
	virtual BOOL OnInitDialog();
};
