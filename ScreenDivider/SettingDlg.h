#pragma once


// CSettingDlg ��ȭ �����Դϴ�.

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSettingDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETTING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
private:
//	unsigned int m_uiSettingSub;
public:
	afx_msg void OnBnClickedButton1();
};
