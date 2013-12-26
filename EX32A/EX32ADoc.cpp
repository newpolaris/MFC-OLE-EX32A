
// EX32ADoc.cpp : CEX32ADoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "EX32A.h"
#endif

#include "EX32ADoc.h"
#include "SrvrItem.h"
#include "TextDialog.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEX32ADoc

IMPLEMENT_DYNCREATE(CEX32ADoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CEX32ADoc, COleServerDoc)
	ON_COMMAND(ID_MODIFY, &CEX32ADoc::OnModify)
END_MESSAGE_MAP()


// CEX32ADoc ����/�Ҹ�

CEX32ADoc::CEX32ADoc()
{
	// OLE ���� ������ ����մϴ�.
	EnableCompoundFile();

	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CEX32ADoc::~CEX32ADoc()
{
}

BOOL CEX32ADoc::OnNewDocument()
{
	m_strText = "Initial default text";

	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	return TRUE;
}


// CEX32ADoc ���� ����

COleServerItem* CEX32ADoc::OnGetEmbeddedItem()
{
	// ������ ���õ� COleServerItem�� �������� ���� �����ӿ�ũ���� OnGetEmbeddedItem��
	//  ȣ���մϴ�. �̰��� �ʿ��� ���� ȣ��˴ϴ�.

	CEX32ASrvrItem* pItem = new CEX32ASrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}




// CEX32ADoc serialization

void CEX32ADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_strText;
	}
	else
	{
		ar >> m_strText;
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CEX32ADoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CEX32ADoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CEX32ADoc ����
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

// CEX32ADoc ���
void CEX32ADoc::OnModify()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTextDialog dlg;
	dlg.m_strText = m_strText;
	if (dlg.DoModal() == IDOK) {
		m_strText = dlg.m_strText;
		UpdateAllViews(NULL); // Trigger CX32AView::OnDraw
		UpdateAllItems(NULL); // Trigger CX32AItem::OnDraw
		SetModifiedFlag();
	}
}
