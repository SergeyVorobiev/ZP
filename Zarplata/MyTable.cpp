// MyTable.cpp : implementation file
//

#include "stdafx.h"
#include "MyTable.h"


// CMyTable


CMyTable::CMyTable(void)
{
	f_cellWidth = 400;
	o_cellWidth = 200;
	cellHeight = 30;
	numCell = 4;
	numString = 4;
	X = 40;
	Y = 50;
	dedicatCell = 0;
	sumCell = 0;
}

CMyTable::~CMyTable()
{
}
void CMyTable::Draw(CDC* pDC, MyCollection* coll)
{
	//pDC->MoveTo(X, Y);
	int startX = X, startY = Y + cellHeight, finishX, finishY;
	CRect rect;
	CPen aPen;
	aPen.CreatePen(PS_SOLID, 1, RGB(150, 150, 150));
	CPen* oldPen;
	oldPen = pDC->SelectObject(&aPen);
	coll->startPos = true;
	sumCell = 0;
	for(int i = 0; i < coll->GetLength(); i++)
	{
		Person* p = coll->getPerson();
		if(p == NULL)break;
		sumCell++;
		finishY = startY + cellHeight;
		for(int j = 0; j < 5; j++)
		{
			if(j == 0)
			{
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				rect.SetRect(startX + 20, startY, finishX + 20 + 1, finishY + 1);
				pDC->SetTextColor(RGB(20, 20, 20));
				pDC->DrawTextW(p->getInitial(), &rect, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
				//pDC->SelectObject(oldPen);
			}
			if(j == 1)
			{
				startX = finishX;
				finishX = startX + 145;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				CString str = p->ToCString(p->getSumHours());
				pDC->DrawTextW(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 2)
			{
				startX = finishX;
				finishX = startX + 145;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				CString str = p->ToCString(p->getTarif());
				str = str + ' ' + 'p';
				pDC->DrawTextW(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 3)
			{
				startX = finishX;
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				CString str = p->ToCString(p->getSalary());
				str = str + ' ' + 'p';
				pDC->DrawTextW(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 4)
			{
				startX = finishX;
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				CString str = p->ToCString(p->getId());
				pDC->DrawTextW(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
		}
		startX = X;
		startY += cellHeight;
	}
	pDC->SelectObject(oldPen);
}
void CMyTable::DrawCap(CDC* pDC)
{
	CRect rect;
	int startX = X, startY = Y, finishX, finishY;
	finishY = startY + cellHeight;
	for(int j = 0; j < 5; j++)
		{
			if(j == 0)
			{
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				pDC->DrawTextW(_T("Ф. И. О."), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 1)
			{
				startX = finishX;
				finishX = startX + 145;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				pDC->DrawTextW(_T("Всего часов"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 2)
			{
				startX = finishX;
				finishX = startX + 145;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				pDC->DrawTextW(_T("Тариф"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 3)
			{
				startX = finishX;
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				pDC->DrawTextW(_T("Зарплата"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
			if(j == 4)
			{
				startX = finishX;
				finishX = startX + 340;
				rect.SetRect(startX, startY, finishX + 1, finishY + 1);
				pDC->Rectangle(&rect);
				pDC->DrawTextW(_T("ID"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
			}
		}
		startX = X;
		startY += cellHeight;
}
void CMyTable::DrawDedicated(CDC* pDC)
{
	if(dedicatCell != 0)
	{
		CPen aPen;
		aPen.CreatePen(PS_DOT, 1, RGB(220, 0, 100));
		CPen* oldPen = pDC->SelectObject(&aPen);
		int startX = X, finishX = 1350, startY = dedicatCell * 30 + 50, finishY = startY + cellHeight;
		pDC->MoveTo(startX, startY);
		pDC->LineTo(startX, finishY);
		pDC->LineTo(finishX, finishY);
		pDC->LineTo(finishX, startY);
		pDC->LineTo(startX, startY);
		pDC->SelectObject(oldPen);
	}
}
void CMyTable::drawTriangleSort(CDC* pDC,  MyCollection* coll, CBitmap* tRB, CBitmap* tSort)
{
	CPoint point;
	if(coll->curMap == MyCollection::HOURS)
		point.SetPoint(372, 58);
	else if(coll->curMap == MyCollection::ID)
		point.SetPoint(980, 58);
	else if(coll->curMap == MyCollection::INITIAL)
		point.SetPoint(45, 58);
	else if(coll->curMap == MyCollection::SALARY)
		point.SetPoint(650, 58);
	pDC->DrawState(point, CSize(20, 20), tRB, 0);
	if(coll->sortHours > 0)
	{	
		point.SetPoint(482, 55);
		pDC->DrawState(point, CSize(20, 20), tSort, 0);
	}
}
void CMyTable::DrawCellar(CDC* pDC, int numStr, CString summa)
{

		int startY = Y + numStr * cellHeight + cellHeight * 2;
		int finishY = startY + cellHeight;
		CRect rect(525, startY, 670 + 1, finishY + 1);
		pDC->Rectangle(&rect);
		pDC->DrawTextW(_T("Итого: "), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
		rect.SetRect(670, startY, 1010, finishY + 1);
		pDC->Rectangle(&rect);
		summa += ' ';
		summa += 'p';
		pDC->DrawTextW(summa, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
		pDC->MoveTo(1010, finishY);
		pDC->LineTo(1350, finishY);
}
// CMyTable member functions
