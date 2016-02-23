
// ZarplataView.cpp : реализация класса CZarplataView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Zarplata.h"
#endif

#include "ZarplataDoc.h"
#include "ZarplataView.h"
#include "DialogAddPerson.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZarplataView

IMPLEMENT_DYNCREATE(CZarplataView, CScrollView)

BEGIN_MESSAGE_MAP(CZarplataView, CScrollView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CZarplataView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ADD_PERSON, &CZarplataView::OnAddPerson)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32775, &CZarplataView::FindOnId)
	ON_COMMAND(ID_SORTFAMILY, &CZarplataView::OnSortfamily)
	ON_COMMAND(ID_SORT_ID, &CZarplataView::OnSortId)
	ON_COMMAND(ID_SORT_PAYMENT, &CZarplataView::OnSortPayment)
	ON_COMMAND(ID_SORT_HOURS, &CZarplataView::OnSortHours)
	ON_COMMAND(ID_SELECT, &CZarplataView::OnSelect)
	ON_WM_LBUTTONDBLCLK()
	ON_UPDATE_COMMAND_UI(ID_SORTFAMILY, &CZarplataView::OnUpdateSortfamily)
	ON_UPDATE_COMMAND_UI(ID_SORT_ID, &CZarplataView::OnUpdateSortId)
	ON_UPDATE_COMMAND_UI(ID_SORT_PAYMENT, &CZarplataView::OnUpdateSortPayment)
	ON_UPDATE_COMMAND_UI(ID_SORT_HOURS, &CZarplataView::OnUpdateSortHours)
	ON_COMMAND(ID_GRAPHIC, &CZarplataView::OnGraphic)
END_MESSAGE_MAP()

// создание/уничтожение CZarplataView

CZarplataView::CZarplataView()
{
	SetScrollSizes(MM_TEXT, CSize(0, 0));
	tRed = new CBitmap();
	tBlue = new CBitmap();
	tSort = new CBitmap();
	tBlue->LoadBitmapW(IDB_BITMAP2);
	tSort->LoadBitmapW(IDB_BITMAP3);
	tRed->LoadBitmapW(IDB_BITMAP4);
	curCell = 0;
}

CZarplataView::~CZarplataView()
{
	delete(tRed);
	delete(tBlue);
	delete(tSort);
}

BOOL CZarplataView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// рисование CZarplataView

void CZarplataView::OnDraw(CDC* pDC)
{
	CZarplataDoc* pDoc = GetDocument();
	MyCollection* myColl = pDoc->myColl;
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->table.Draw(pDC, myColl);
	pDoc->table.DrawCap(pDC);
	CBitmap* bitmap;
	if(myColl->isReverse)
		bitmap = tRed;
	else
		bitmap = tBlue;
	pDoc->table.drawTriangleSort(pDC, myColl, bitmap, tSort);
	if(myColl->GetLength() > 0)
	{
		CString summa;
		Person* p = myColl->getOnIndex(myColl->curMap, 1);
		summa = p->ToCString(myColl->getSumSalary());
		pDoc->table.DrawDedicated(pDC);
		pDoc->table.DrawCellar(pDC, pDoc->table.sumCell, summa);
	}
	else
		curCell = 0;
	
	//pDC->Rectangle(0, 0, 1390, 300); //
	
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CZarplataView::OnInitialUpdate()
{
	ResetScrollSizes();
	CScrollView::OnInitialUpdate();
	
	//CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	//sizeTotal.cx = sizeTotal.cy = 100;
	//CSize DocSize(1300, 465); // на пятьдесят листов по длине
	//SetScrollSizes(MM_LOENGLISH, DocSize, CSize(500, 500), CSize(50, 50));
}


// печать CZarplataView


void CZarplataView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CZarplataView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CZarplataView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CZarplataView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CZarplataView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	//OnContextMenu(this, point);
	CZarplataDoc* pDoc = GetDocument();
	pDoc->table.dedicatCell = 0;
	curCell = 0;
	this->InvalidateRect(NULL, true);
}

void CZarplataView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CZarplataView

#ifdef _DEBUG
void CZarplataView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CZarplataView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CZarplataDoc* CZarplataView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZarplataDoc)));
	return (CZarplataDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CZarplataView


void CZarplataView::OnAddPerson()
{
	CZarplataDoc* pDoc = GetDocument();
	DialogAddPerson dial;
	dial.myColl = pDoc->myColl;
	dial.DoModal();
	if(dial.change)
		pDoc->SetModifiedFlag();
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	CScrollView::OnPrepareDC(pDC, pInfo);//добавляем код после вызова базового класса
	float m_Scale = 1;
	CZarplataDoc* pDoc = this->GetDocument();
	pDC->SetMapMode(MM_ANISOTROPIC);
	CSize DocSize = pDoc->GetDocSize();
	pDC->SetWindowExt(DocSize);
	int xLog = pDC->GetDeviceCaps(LOGPIXELSX);
	int yLog = pDC->GetDeviceCaps(LOGPIXELSY);
	int xExtent = (DocSize.cx * m_Scale * xLog) / 100;
	int yExtent = (DocSize.cy * m_Scale * yLog) / 100;
	pDC->SetViewportExt(xExtent, yExtent);
	
}
void CZarplataView::ResetScrollSizes(void)
{
	CClientDC aDC(this);
	OnPrepareDC(&aDC);
	CSize DocSize = GetDocument()->GetDocSize();
	aDC.LPtoDP(&DocSize);
	SetScrollSizes(MM_TEXT, DocSize, CSize(300, 300));	
}

void CZarplataView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC aDC(this);
	OnPrepareDC(&aDC);
	aDC.DPtoLP(&point);
	CZarplataDoc* pDoc = GetDocument();
	int tableCell = pDoc->table.dedicatCell;
	if(point.x > 45 && point.x < 1360 && point.y < 80 && point.y > 50)
	{
		MyCollection* myColl = pDoc->myColl;
		pDoc->table.dedicatCell = 0;
		curCell = 0;
		if(point.x < 380)
		{
			if(myColl->curMap == MyCollection::INITIAL)
				myColl->isReverse = !myColl->isReverse;
			else
				myColl->curMap = MyCollection::INITIAL;
		}
		else if(point.x > 380 && point.x < 525)
		{
			if(myColl->curMap == MyCollection::HOURS)
				myColl->isReverse = !myColl->isReverse;
			else
				myColl->curMap = MyCollection::HOURS;
		}
		else if(point.x > 670 && point.x < 1010)
		{
			if(myColl->curMap == MyCollection::SALARY)
				myColl->isReverse = !myColl->isReverse;
			else
				myColl->curMap = MyCollection::SALARY;
		}
		else if(point.x > 1010 && point.x < 1350)
		{
			if(myColl->curMap == MyCollection::ID)
				myColl->isReverse = !myColl->isReverse;
			else
				myColl->curMap = MyCollection::ID;
		}
		this->InvalidateRect(NULL, true);
		return;
	}
	else if(point.x > 45 && point.x < 1360 && point.y > 80)
	{
		
		curCell = (point.y - 80) / 30 + 1;
		if(curCell <= pDoc->table.sumCell)
		{
			if(tableCell == curCell)
			{
				EditPerson dial;
				dial.table = &pDoc->table;
				dial.findIndex = true;
				dial.myColl = pDoc->myColl;
				dial.numPerson = curCell;
				dial.DoModal();
				if(dial.change)
					pDoc->SetModifiedFlag();
				this->InvalidateRect(NULL, true);
				return;//cоздать окно
			}
			else
			{
				pDoc->table.dedicatCell = curCell;
				this->InvalidateRect(NULL, true);
				return;
			}
		}
	}
	if(tableCell)
	{
		pDoc->table.dedicatCell = 0;
		curCell = 0;
		this->InvalidateRect(NULL, true);
	}
	//CScrollView::OnLButtonDown(nFlags, point);
}


void CZarplataView::FindOnId()
{
	CZarplataDoc* pDoc = GetDocument();
	DialogFindId dial;
	dial.myColl = pDoc->myColl;
	dial.DoModal();
	if(dial.isOk)
	{
		EditPerson dial2;
		dial2.p = dial.p;				//передаем объект персоны
		dial2.myColl = pDoc->myColl;
		dial2.findIndex = false;		//искать объект по индексу не надо, объект уже передан
		dial2.table = &pDoc->table;
		dial2.DoModal();
		if(dial2.change)
			pDoc->SetModifiedFlag();
		this->InvalidateRect(NULL, true);
	}		
	return;								//cоздать окно
}


void CZarplataView::OnSortfamily()
{
	CZarplataDoc* pDoc = GetDocument();
	pDoc->myColl->curMap = MyCollection::INITIAL;
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnSortId()
{
	CZarplataDoc* pDoc = GetDocument();
	pDoc->myColl->curMap = MyCollection::ID;
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnSortPayment()
{
	CZarplataDoc* pDoc = GetDocument();
	pDoc->myColl->curMap = MyCollection::SALARY;
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnSortHours()
{
	CZarplataDoc* pDoc = GetDocument();
	pDoc->myColl->curMap = MyCollection::HOURS;
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnSelect()
{
	CZarplataDoc* pDoc = GetDocument();
	DiaSelection dia;
	dia.coll = pDoc->myColl;
	if(dia.DoModal() == IDOK)
		pDoc->table.dedicatCell = 0;
	this->InvalidateRect(NULL, true);
}


void CZarplataView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CZarplataDoc* pDoc = GetDocument();
	if(curCell <= pDoc->table.sumCell && curCell != 0)
	{
		EditPerson dial;
		dial.findIndex = true;
		dial.myColl = pDoc->myColl;
		dial.numPerson = curCell;
		dial.table = &pDoc->table;
		dial.DoModal();
		if(dial.change)
			pDoc->SetModifiedFlag();
		this->InvalidateRect(NULL, true); // необходимо при удалении персонажа после открытия по двойному щелчку
		return;//cоздать окно
	}
}


void CZarplataView::OnUpdateSortfamily(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->myColl->curMap == MyCollection::INITIAL);
}

void CZarplataView::OnUpdateSortId(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->myColl->curMap == MyCollection::ID);
}

void CZarplataView::OnUpdateSortPayment(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->myColl->curMap == MyCollection::SALARY);
}

void CZarplataView::OnUpdateSortHours(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->myColl->curMap == MyCollection::HOURS);
}

void CZarplataView::OnGraphic()
{
	DialogPicture dia;
	dia.coll = GetDocument()->myColl;
	dia.curPerson = GetDocument()->table.sumCell;
	dia.DoModal();
}
