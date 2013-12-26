
// SrvrItem.cpp : CEX32ASrvrItem 클래스의 구현
//

#include "stdafx.h"
#include "EX32A.h"

#include "EX32ADoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX32ASrvrItem 구현

IMPLEMENT_DYNAMIC(CEX32ASrvrItem, COleServerItem)

CEX32ASrvrItem::CEX32ASrvrItem(CEX32ADoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	//  (예: 항목의 데이터 소스에 추가 클립보드 형식 추가)
}

CEX32ASrvrItem::~CEX32ASrvrItem()
{
	// TODO: 여기에 정리 코드를 추가합니다.
}

void CEX32ASrvrItem::Serialize(CArchive& ar)
{
	// 항목이 클립보드에 복사되면 프레임워크에서 CEX32ASrvrItem::Serialize를
	//  호출합니다. 이러한 호출은
	//  OLE 콜백 OnGetClipboardData를 통해 자동으로 발생시킬 수 있습니다.
	//  포함 항목의 경우 기본적으로 해당 문서의 Serialize 함수에 위임하는 것이
	//  좋습니다. 연결을 지원할 경우에는 문서의 일부만
	//  serialization할 수 있습니다.

	if (!IsLinkedItem())
	{
		CEX32ADoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL CEX32ASrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// 이 응용 프로그램과 같은 대부분의 응용 프로그램은 항목의
	//  내용 모양 그리기만 처리합니다.
	//  OnDrawEx를 재정의하여 DVASPECT_THUMBNAIL과 같은 다른 모양을 지원하려면
	//  이 OnGetExtent의 구현을 수정하여 추가 모양을  처리하도록
	//  해야 합니다.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CEX32ASrvrItem::OnGetExtent를 호출합니다.
	//  전체 항목의 범위를 HIMETRIC 단위로 가져오기 위해서입니다. 여기에서의 기본 구현은 단순히
	//  하드 코드된 단위 수를 반환하는 것입니다.

	// TODO: 이 임의의 크기를 바꿉니다.

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC 단위

	return TRUE;
}

BOOL CEX32ASrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// rSize를 사용할 경우 이 줄을 제거하십시오.
	UNREFERENCED_PARAMETER(rSize);

	// TODO: 매핑 모드와 범위를 설정합니다.
	//  범위는 보통 OnGetExtent에서 반환된 크기와 같습니다.
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: 여기에 그리기 코드를 추가합니다. 옵션으로 HIMETRIC 범위를 채울 수도 있습니다.
	//  모든 그리기 작업은 메타 파일 디바이스 컨텍스트(pDC)에서 발생합니다.

	return TRUE;
}


// CEX32ASrvrItem 진단

#ifdef _DEBUG
void CEX32ASrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CEX32ASrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

