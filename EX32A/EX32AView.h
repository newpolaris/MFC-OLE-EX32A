
// EX32AView.h : CEX32AView Ŭ������ �������̽�
//

#pragma once


class CEX32AView : public CView
{
protected: // serialization������ ��������ϴ�.
	CEX32AView();
	DECLARE_DYNCREATE(CEX32AView)

// Ư���Դϴ�.
public:
	CEX32ADoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CEX32AView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnCancelEditSrvr();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // EX32AView.cpp�� ����� ����
inline CEX32ADoc* CEX32AView::GetDocument() const
   { return reinterpret_cast<CEX32ADoc*>(m_pDocument); }
#endif

