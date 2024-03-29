
// EX32AView.h : CEX32AView 클래스의 인터페이스
//

#pragma once


class CEX32AView : public CView
{
protected: // serialization에서만 만들어집니다.
	CEX32AView();
	DECLARE_DYNCREATE(CEX32AView)

// 특성입니다.
public:
	CEX32ADoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CEX32AView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnCancelEditSrvr();
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // EX32AView.cpp의 디버그 버전
inline CEX32ADoc* CEX32AView::GetDocument() const
   { return reinterpret_cast<CEX32ADoc*>(m_pDocument); }
#endif

