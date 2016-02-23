
// Zarplata.h : ������� ���� ��������� ��� ���������� Zarplata
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������
#include "MyGlobal.h"

// CZarplataApp:
// � ���������� ������� ������ ��. Zarplata.cpp
//

class CZarplataApp : public CWinAppEx
{
public:
	CZarplataApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZarplataApp theApp;
