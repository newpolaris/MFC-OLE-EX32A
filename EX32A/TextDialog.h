#pragma once


// CTextDialog ��ȭ �����Դϴ�.

class CTextDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDialog)

public:
	CTextDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_strText;
};
