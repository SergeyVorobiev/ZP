
// ZarplataDoc.h : интерфейс класса CZarplataDoc
//


#pragma once

#include "MyTable.h"
class CZarplataDoc : public CDocument
{
protected: // создать только из сериализации
	CZarplataDoc();
	DECLARE_DYNCREATE(CZarplataDoc)

// Атрибуты
public:
	CMyTable table;
	MyCollection* myColl; 
	CSize GetDocSize() const {return m_DocSize;}
	void tempInitial();
protected:
	CSize m_DocSize;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CZarplataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
