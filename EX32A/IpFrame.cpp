
// IpFrame.cpp : CInPlaceFrame Ŭ������ ����
//

#include "stdafx.h"
#include "EX32A.h"

#include "IpFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInPlaceFrame

IMPLEMENT_DYNCREATE(CInPlaceFrame, COleIPFrameWndEx)

BEGIN_MESSAGE_MAP(CInPlaceFrame, COleIPFrameWndEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CInPlaceFrame ����/�Ҹ�

CInPlaceFrame::CInPlaceFrame()
{
}

CInPlaceFrame::~CInPlaceFrame()
{
}

int CInPlaceFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleIPFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// CResizeBar�� ���� ũ�� ������ �����մϴ�.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("Failed to create resize bar\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	// �⺻������, ���� ����� ������� â �����Ӱ� ������ ���� ������
	//  ����ϴ� ���� �����ϴ�. �̷��� �ϸ� ��� ���⸦ �����ϴ�
	//  �����̳ʿ� ���� �۾��� "����"���� �ʽ��ϴ�.
	m_dropTarget.Register(this);

	return 0;
}

// �����̳� ���� ���α׷��� â�� ��Ʈ�� ������ ����� ���� �����ӿ�ũ���� OnCreateControlBars��
//  ȣ���մϴ�. pWndFrame�� �����̳��� �ֻ��� ���� ������ â�̸�
//  �׻� NULL�� �ƴ� ���� �����ϴ�. pWndDoc�� ���� ���� ������ â����
//  �����̳ʰ� SDI ���� ���α׷��� ��� NULL�� �˴ϴ�.
//  ���� ���� ���α׷��� �� â �� �ϳ��� MFC ��Ʈ�� ������ ��ġ�� �� �ֽ��ϴ�.
BOOL CInPlaceFrame::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// pWndDoc�� ����� ��쿡�� �� ���� �����Ͻʽÿ�.
	UNREFERENCED_PARAMETER(pWndDoc);

	// �� â�� ���� �����ڸ� �����ϹǷ� �޽����� �ùٸ� ���� ���α׷��� ���޵˴ϴ�.
	m_wndToolBar.SetOwner(this);

	// Ŭ���̾�Ʈ�� ������ â�� ���� ������ ����ϴ�.
	if (!m_wndToolBar.CreateEx(pWndFrame, TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_SRVR_INPLACE))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;
	}

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);

	return TRUE;
}

BOOL CInPlaceFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return COleIPFrameWndEx::PreCreateWindow(cs);
}


// CInPlaceFrame ����

#ifdef _DEBUG
void CInPlaceFrame::AssertValid() const
{
	COleIPFrameWndEx::AssertValid();
}

void CInPlaceFrame::Dump(CDumpContext& dc) const
{
	COleIPFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CInPlaceFrame ���

