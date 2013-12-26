
// EX32ADoc.h : CEX32ADoc 클래스의 인터페이스
//


#pragma once


class CEX32ASrvrItem;

class CEX32ADoc : public COleServerDoc
{
protected: // serialization에서만 만들어집니다.
	CEX32ADoc();
	DECLARE_DYNCREATE(CEX32ADoc)

// 특성입니다.
public:
	CEX32ASrvrItem* GetEmbeddedItem()
		{ return reinterpret_cast<CEX32ASrvrItem*>(COleServerDoc::GetEmbeddedItem()); }

// 작업입니다.
public:

// 재정의입니다.
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CEX32ADoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
