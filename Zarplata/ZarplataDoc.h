
// ZarplataDoc.h : ��������� ������ CZarplataDoc
//


#pragma once

#include "MyTable.h"
class CZarplataDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CZarplataDoc();
	DECLARE_DYNCREATE(CZarplataDoc)

// ��������
public:
	CMyTable table;
	MyCollection* myColl; 
	CSize GetDocSize() const {return m_DocSize;}
	void tempInitial();
protected:
	CSize m_DocSize;
// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CZarplataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
