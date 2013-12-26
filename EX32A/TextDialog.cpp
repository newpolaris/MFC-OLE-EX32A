// TextDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EX32A.h"
#include "EX32ADoc.h"
#include "TextDialog.h"
#include "afxdialogex.h"


// CTextDialog 대화 상자입니다.

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


// CTextDialog 메시지 처리기입니다.


void CTextDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
