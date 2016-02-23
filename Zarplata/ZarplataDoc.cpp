
// ZarplataDoc.cpp : реализация класса CZarplataDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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


// создание/уничтожение CZarplataDoc

CZarplataDoc::CZarplataDoc():m_DocSize(CSize(1380, 50000)) //определим размер документа в дюймах А4
{
	// TODO: добавьте код для одноразового вызова конструктора
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

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CZarplataDoc

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

// Поддержка для эскизов
void CZarplataDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
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

// Поддержка обработчиков поиска
void CZarplataDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
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

// диагностика CZarplataDoc

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


// команды CZarplataDoc
void CZarplataDoc::tempInitial()
{
	CString surname = static_cast<CString>("Воробьев");
	CString name = static_cast<CString>("Сергей");
	CString secondname = static_cast<CString>("Вячеславович");
	Person* p = new Person(surname, name, secondname, 12345678);
	p->computSalary(205, 27, 1, 5000, 500, 1.5f);
	myColl->Insert(p);
	CString surname1 = static_cast<CString>("Боров");
	CString name1 = static_cast<CString>("Игорь");
	CString secondname1 = static_cast<CString>("Викторович");
	Person* p1 = new Person(surname1, name1, secondname1, 15345678);
	p1->computSalary(183, 11, 1, 5000, 450, 1.5f);
	myColl->Insert(p1);
	CString surname2 = static_cast<CString>("Ломоносов");
	CString name2 = static_cast<CString>("Сергей");
	CString secondname2= static_cast<CString>("Юрьевич");
	Person* p2 = new Person(surname2, name2, secondname2, 42345678);
	p2->computSalary(167, 7, 1, 5000, 270, 1.5f);
	myColl->Insert(p2);
	CString surname3 = static_cast<CString>("Эйнштейн");
	CString name3 = static_cast<CString>("Альберт");
	CString secondname3 = static_cast<CString>("Умникович");
	Person* p3 = new Person(surname3, name3, secondname3, 12745678);
	p3->computSalary(190, 12, 1, 5000, 500, 1.5f);
	myColl->Insert(p3);
	CString surname4 = static_cast<CString>("Цой");
	CString name4 = static_cast<CString>("Виктор");
	CString secondname4 = static_cast<CString>("Михайлович");
	Person* p4 = new Person(surname4, name4, secondname4, 12345878);
	p4->computSalary(115, 0, 1, 5000, 210, 1.5f);
	myColl->Insert(p4);
	CString surname5 = static_cast<CString>("Ковалев");
	CString name5 = static_cast<CString>("Роман");
	CString secondname5 = static_cast<CString>("Дмитриевич");
	Person* p5 = new Person(surname5, name5, secondname5, 12345679);
	p5->computSalary(100, 0, 1, 5000, 100, 1.5f);
	myColl->Insert(p5);
	CString surname6 = static_cast<CString>("Конышева");
	CString name6 = static_cast<CString>("Полина");
	CString secondname6 = static_cast<CString>("Владимировна");
	Person* p6 = new Person(surname6, name6, secondname6, 12045678);
	p6->computSalary(250, 40, 1, 5000, 150, 1.5f);
	myColl->Insert(p6);
	CString surname7 = static_cast<CString>("Алыкова");
	CString name7 = static_cast<CString>("Алевтина");
	CString secondname7 = static_cast<CString>("Леонидовна");
	Person* p7 = new Person(surname7, name7, secondname7, 12141678);
	p7->computSalary(157, 8, 1, 5000, 600, 1.5f);
	myColl->Insert(p7);
	CString surname8 = static_cast<CString>("Смирнов");
	CString name8 = static_cast<CString>("Михаил");
	CString secondname8 = static_cast<CString>("Викторович");
	Person* p8 = new Person(surname8, name8, secondname8, 12344678);
	p8->computSalary(175, 5, 1, 5000, 350, 1.5f);
	myColl->Insert(p8);
	CString surname9 = static_cast<CString>("Сухобрус");
	CString name9 = static_cast<CString>("Виктория");
	CString secondname9 = static_cast<CString>("Сергеевна");
	Person* p9 = new Person(surname9, name9, secondname9, 12345378);
	p9->computSalary(160, 2, 1, 5000, 213, 1.5f);
	myColl->Insert(p9);
}