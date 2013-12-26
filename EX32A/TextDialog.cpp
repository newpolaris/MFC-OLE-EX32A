// TextDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EX32A.h"
#include "EX32ADoc.h"
#include "TextDialog.h"
#include "afxdialogex.h"


// CTextDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTextDialog, CDialogEx)

CTextDialog::CTextDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextDialog::IDD, pParent)
	, m_strText(_T(""))
{

}

CTextDialog::~CTextDialog()
{
}

void CTextDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strText);
}


BEGIN_MESSAGE_MAP(CTextDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTextDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTextDialog �޽��� ó�����Դϴ�.


void CTextDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
