
// ZarplataDoc.cpp : ���������� ������ CZarplataDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Zarplata.h"
#endif

#include "ZarplataDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZarplataDoc

IMPLEMENT_DYNCREATE(CZarplataDoc, CDocument)

BEGIN_MESSAGE_MAP(CZarplataDoc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CZarplataDoc

CZarplataDoc::CZarplataDoc():m_DocSize(CSize(1380, 50000)) //��������� ������ ��������� � ������ �4
{
	// TODO: �������� ��� ��� ������������ ������ ������������
	myColl = new MyCollection(MyCollection::INITIAL);
	//tempInitial();
	
	
}

CZarplataDoc::~CZarplataDoc()
{
	delete(myColl);
}

BOOL CZarplataDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ CZarplataDoc

void CZarplataDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<myColl;
	}
	else
	{
		ar>>myColl;
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CZarplataDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void CZarplataDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CZarplataDoc::SetSearchContent(const CString& value)
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

// ����������� CZarplataDoc

#ifdef _DEBUG
void CZarplataDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZarplataDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CZarplataDoc
void CZarplataDoc::tempInitial()
{
	CString surname = static_cast<CString>("��������");
	CString name = static_cast<CString>("������");
	CString secondname = static_cast<CString>("������������");
	Person* p = new Person(surname, name, secondname, 12345678);
	p->computSalary(205, 27, 1, 5000, 500, 1.5f);
	myColl->Insert(p);
	CString surname1 = static_cast<CString>("�����");
	CString name1 = static_cast<CString>("�����");
	CString secondname1 = static_cast<CString>("����������");
	Person* p1 = new Person(surname1, name1, secondname1, 15345678);
	p1->computSalary(183, 11, 1, 5000, 450, 1.5f);
	myColl->Insert(p1);
	CString surname2 = static_cast<CString>("���������");
	CString name2 = static_cast<CString>("������");
	CString secondname2= static_cast<CString>("�������");
	Person* p2 = new Person(surname2, name2, secondname2, 42345678);
	p2->computSalary(167, 7, 1, 5000, 270, 1.5f);
	myColl->Insert(p2);
	CString surname3 = static_cast<CString>("��������");
	CString name3 = static_cast<CString>("�������");
	CString secondname3 = static_cast<CString>("���������");
	Person* p3 = new Person(surname3, name3, secondname3, 12745678);
	p3->computSalary(190, 12, 1, 5000, 500, 1.5f);
	myColl->Insert(p3);
	CString surname4 = static_cast<CString>("���");
	CString name4 = static_cast<CString>("������");
	CString secondname4 = static_cast<CString>("����������");
	Person* p4 = new Person(surname4, name4, secondname4, 12345878);
	p4->computSalary(115, 0, 1, 5000, 210, 1.5f);
	myColl->Insert(p4);
	CString surname5 = static_cast<CString>("�������");
	CString name5 = static_cast<CString>("�����");
	CString secondname5 = static_cast<CString>("����������");
	Person* p5 = new Person(surname5, name5, secondname5, 12345679);
	p5->computSalary(100, 0, 1, 5000, 100, 1.5f);
	myColl->Insert(p5);
	CString surname6 = static_cast<CString>("��������");
	CString name6 = static_cast<CString>("������");
	CString secondname6 = static_cast<CString>("������������");
	Person* p6 = new Person(surname6, name6, secondname6, 12045678);
	p6->computSalary(250, 40, 1, 5000, 150, 1.5f);
	myColl->Insert(p6);
	CString surname7 = static_cast<CString>("�������");
	CString name7 = static_cast<CString>("��������");
	CString secondname7 = static_cast<CString>("����������");
	Person* p7 = new Person(surname7, name7, secondname7, 12141678);
	p7->computSalary(157, 8, 1, 5000, 600, 1.5f);
	myColl->Insert(p7);
	CString surname8 = static_cast<CString>("�������");
	CString name8 = static_cast<CString>("������");
	CString secondname8 = static_cast<CString>("����������");
	Person* p8 = new Person(surname8, name8, secondname8, 12344678);
	p8->computSalary(175, 5, 1, 5000, 350, 1.5f);
	myColl->Insert(p8);
	CString surname9 = static_cast<CString>("��������");
	CString name9 = static_cast<CString>("��������");
	CString secondname9 = static_cast<CString>("���������");
	Person* p9 = new Person(surname9, name9, secondname9, 12345378);
	p9->computSalary(160, 2, 1, 5000, 213, 1.5f);
	myColl->Insert(p9);
}