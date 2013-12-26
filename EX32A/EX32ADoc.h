
// EX32ADoc.h : CEX32ADoc Ŭ������ �������̽�
//


#pragma once


class CEX32ASrvrItem;

class CEX32ADoc : public COleServerDoc
{
protected: // serialization������ ��������ϴ�.
	CEX32ADoc();
	DECLARE_DYNCREATE(CEX32ADoc)

// Ư���Դϴ�.
public:
	CEX32ASrvrItem* GetEmbeddedItem()
		{ return reinterpret_cast<CEX32ASrvrItem*>(COleServerDoc::GetEmbeddedItem()); }

// �۾��Դϴ�.
public:

// �������Դϴ�.
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CEX32ADoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
