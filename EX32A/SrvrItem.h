
// SrvrItem.h : CEX32ASrvrItem Ŭ������ �������̽�
//

#pragma once

class CEX32ASrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CEX32ASrvrItem)

// �������Դϴ�.
public:
	CEX32ASrvrItem(CEX32ADoc* pContainerDoc);

// Ư���Դϴ�.
	CEX32ADoc* GetDocument() const
		{ return reinterpret_cast<CEX32ADoc*>(COleServerItem::GetDocument()); }

// �������Դϴ�.
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// �����Դϴ�.
public:
	~CEX32ASrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // ���� ��/����� ���� �����ǵǾ����ϴ�.
};

