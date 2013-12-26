#pragma once


// CTextDialog 대화 상자입니다.

class CTextDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDialog)

public:
	CTextDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTextDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_strText;
};
