
// SrvrItem.cpp : CEX32ASrvrItem Ŭ������ ����
//

#include "stdafx.h"
#include "EX32A.h"

#include "EX32ADoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX32ASrvrItem ����

IMPLEMENT_DYNAMIC(CEX32ASrvrItem, COleServerItem)

CEX32ASrvrItem::CEX32ASrvrItem(CEX32ADoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	//  (��: �׸��� ������ �ҽ��� �߰� Ŭ������ ���� �߰�)
}

CEX32ASrvrItem::~CEX32ASrvrItem()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

void CEX32ASrvrItem::Serialize(CArchive& ar)
{
	// �׸��� Ŭ�����忡 ����Ǹ� �����ӿ�ũ���� CEX32ASrvrItem::Serialize��
	//  ȣ���մϴ�. �̷��� ȣ����
	//  OLE �ݹ� OnGetClipboardData�� ���� �ڵ����� �߻���ų �� �ֽ��ϴ�.
	//  ���� �׸��� ��� �⺻������ �ش� ������ Serialize �Լ��� �����ϴ� ����
	//  �����ϴ�. ������ ������ ��쿡�� ������ �Ϻθ�
	//  serialization�� �� �ֽ��ϴ�.

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
	// �� ���� ���α׷��� ���� ��κ��� ���� ���α׷��� �׸���
	//  ���� ��� �׸��⸸ ó���մϴ�.
	//  OnDrawEx�� �������Ͽ� DVASPECT_THUMBNAIL�� ���� �ٸ� ����� �����Ϸ���
	//  �� OnGetExtent�� ������ �����Ͽ� �߰� �����  ó���ϵ���
	//  �ؾ� �մϴ�.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CEX32ASrvrItem::OnGetExtent�� ȣ���մϴ�.
	//  ��ü �׸��� ������ HIMETRIC ������ �������� ���ؼ��Դϴ�. ���⿡���� �⺻ ������ �ܼ���
	//  �ϵ� �ڵ�� ���� ���� ��ȯ�ϴ� ���Դϴ�.

	// TODO: �� ������ ũ�⸦ �ٲߴϴ�.

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC ����

	return TRUE;
}

BOOL CEX32ASrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// rSize�� ����� ��� �� ���� �����Ͻʽÿ�.
	UNREFERENCED_PARAMETER(rSize);

	// TODO: ���� ���� ������ �����մϴ�.
	//  ������ ���� OnGetExtent���� ��ȯ�� ũ��� �����ϴ�.
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�. �ɼ����� HIMETRIC ������ ä�� ���� �ֽ��ϴ�.
	//  ��� �׸��� �۾��� ��Ÿ ���� ����̽� ���ؽ�Ʈ(pDC)���� �߻��մϴ�.

	return TRUE;
}


// CEX32ASrvrItem ����

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

