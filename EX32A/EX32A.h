
// EX32A.h : EX32A ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CEX32AApp:
// �� Ŭ������ ������ ���ؼ��� EX32A.cpp�� �����Ͻʽÿ�.
//

class CEX32AApp : public CWinApp
{
public:
	CEX32AApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	COleTemplateServer m_server;
		// ���� ����⿡ ���� ���� ��ü�Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEX32AApp theApp;
