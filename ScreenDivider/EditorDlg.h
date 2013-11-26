#pragma once
#include "../Common/SDForm.h"
#include "../Common/common.h"
#include "EditorToolDlg.h"

// CEditorDlg ��ȭ �����Դϴ�.

class CEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorDlg)

public:
	CEditorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

private:
	CEditorToolDlg *m_pDlgEditorTool;
	CPoint m_start,m_end;
	bool m_isDown;
	CSDForm form;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};