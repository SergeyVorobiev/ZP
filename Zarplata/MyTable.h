#pragma once
#include "MyCollection.h"
// CMyTable command target

class CMyTable : public CObject
{
public:
	CMyTable(void);
	virtual ~CMyTable();
	void Draw(CDC* pDC, MyCollection* coll);
	void DrawCap(CDC* pDC);
	int dedicatCell;
	int sumCell;
	void DrawDedicated(CDC* pDC);
	void drawTriangleSort(CDC* pDC,  MyCollection* coll, CBitmap* tRB, CBitmap* tSort);
	void DrawCellar(CDC* pDC, int numStr, CString summa);
private:
	int cellHeight;
	int f_cellWidth;
	int o_cellWidth;
	int numCell;
	int numString;
	int X;
	int Y;
};


