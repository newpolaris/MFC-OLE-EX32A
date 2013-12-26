
// EX32AView.cpp : CEX32AView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CEX32AView 생성/소멸

CEX32AView::CEX32AView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CEX32AView::~CEX32AView()
{
}

BOOL CEX32AView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CEX32AView 그리기

void CEX32AView::OnDraw(CDC* /*pDC*/)
{
	CEX32ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

// OLE 서버 지원

// 다음 명령 처리기는 표준 키보드 사용자 인터페이스를 제공하여
//  내부 편집 세션을 취소합니다. 그러면
//  서버(컨테이너가 아님)가 비활성화됩니다.
void CEX32AView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CEX32AView 진단

#ifdef _DEBUG
void CEX32AView::AssertValid() const
{
	CView::AssertValid();
}

void CEX32AView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX32ADoc* CEX32AView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX32ADoc)));
	return (CEX32ADoc*)m_pDocument;
}
#endif //_DEBUG


// CEX32AView 메시지 처리기
