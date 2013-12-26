
// EX32ADoc.cpp : CEX32ADoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "EX32A.h"
#endif

#include "EX32ADoc.h"
#include "SrvrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEX32ADoc

IMPLEMENT_DYNCREATE(CEX32ADoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CEX32ADoc, COleServerDoc)
END_MESSAGE_MAP()


// CEX32ADoc 생성/소멸

CEX32ADoc::CEX32ADoc()
{
	// OLE 복합 파일을 사용합니다.
	EnableCompoundFile();

	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CEX32ADoc::~CEX32ADoc()
{
}

BOOL CEX32ADoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}


// CEX32ADoc 서버 구현

COleServerItem* CEX32ADoc::OnGetEmbeddedItem()
{
	// 문서와 관련된 COleServerItem을 가져오기 위해 프레임워크에서 OnGetEmbeddedItem을
	//  호출합니다. 이것은 필요할 때만 호출됩니다.

	CEX32ASrvrItem* pItem = new CEX32ASrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}




// CEX32ADoc serialization

void CEX32ADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CEX32ADoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CEX32ADoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CEX32ADoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CEX32ADoc 진단

#ifdef _DEBUG
void CEX32ADoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CEX32ADoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG


// CEX32ADoc 명령
