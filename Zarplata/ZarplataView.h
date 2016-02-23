
// ZarplataView.h : ��������� ������ CZarplataView
//

#pragma once
#include "EditPerson.h"
#include "DialogFindId.h"
#include "DiaSelection.h"
#include "DialogPicture.h"
class CZarplataView : public CScrollView
{
protected: // ������� ������ �� ������������
	CZarplataView();
	DECLARE_DYNCREATE(CZarplataView)
	CPoint curPoint;
	int curCell;
// ��������
public:
	CZarplataDoc* GetDocument() const;
	void ResetScrollSizes(void);
	CBitmap* tRed;
	CBitmap* tBlue;
	CBitmap* tSort;
// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CZarplataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddPerson();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void FindOnId();
	afx_msg void OnSortfamily();
	afx_msg void OnSortId();
	afx_msg void OnSortPayment();
	afx_msg void OnSortHours();
	afx_msg void OnSelect();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnUpdateSortfamily(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSortId(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSortPayment(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSortHours(CCmdUI *pCmdUI);
	afx_msg void On32792();
	afx_msg void OnGraphic();
};

#ifndef _DEBUG  // ���������� ������ � ZarplataView.cpp
inline CZarplataDoc* CZarplataView::GetDocument() const
   { return reinterpret_cast<CZarplataDoc*>(m_pDocument); }
#endif

