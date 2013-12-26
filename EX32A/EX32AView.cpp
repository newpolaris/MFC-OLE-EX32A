
// EX32AView.cpp : CEX32AView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "EX32A.h"
#endif

#include "EX32ADoc.h"
#include "EX32AView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX32AView

IMPLEMENT_DYNCREATE(CEX32AView, CView)

BEGIN_MESSAGE_MAP(CEX32AView, CView)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CEX32AView::OnCancelEditSrvr)
END_MESSAGE_MAP()

// CEX32AView ����/�Ҹ�

CEX32AView::CEX32AView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CEX32AView::~CEX32AView()
{
}

BOOL CEX32AView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CEX32AView �׸���

void CEX32AView::OnDraw(CDC* /*pDC*/)
{
	CEX32ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

// OLE ���� ����

// ���� ��� ó����� ǥ�� Ű���� ����� �������̽��� �����Ͽ�
//  ���� ���� ������ ����մϴ�. �׷���
//  ����(�����̳ʰ� �ƴ�)�� ��Ȱ��ȭ�˴ϴ�.
void CEX32AView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CEX32AView ����

#ifdef _DEBUG
void CEX32AView::AssertValid() const
{
	CView::AssertValid();
}

void CEX32AView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX32ADoc* CEX32AView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX32ADoc)));
	return (CEX32ADoc*)m_pDocument;
}
#endif //_DEBUG


// CEX32AView �޽��� ó����
