
// SrvrItem.h : CEX32ASrvrItem 클래스의 인터페이스
//

#pragma once

class CEX32ASrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CEX32ASrvrItem)

// 생성자입니다.
public:
	CEX32ASrvrItem(CEX32ADoc* pContainerDoc);

// 특성입니다.
	CEX32ADoc* GetDocument() const
		{ return reinterpret_cast<CEX32ADoc*>(COleServerItem::GetDocument()); }

// 재정의입니다.
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// 구현입니다.
public:
	~CEX32ASrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // 문서 입/출력을 위해 재정의되었습니다.
};

