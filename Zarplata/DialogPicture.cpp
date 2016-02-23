// DialogPicture.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "DialogPicture.h"
#include "afxdialogex.h"


// DialogPicture dialog

IMPLEMENT_DYNAMIC(DialogPicture, CDialogEx)

DialogPicture::DialogPicture(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogPicture::IDD, pParent)
{
	
}

DialogPicture::~DialogPicture()
{
}

void DialogPicture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	
	
}


BEGIN_MESSAGE_MAP(DialogPicture, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogPicture::OnBnClickedOk)
END_MESSAGE_MAP()


// DialogPicture message handlers


BOOL DialogPicture::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void DialogPicture::OnBnClickedOk()
{
	CClientDC aDC(this);
	aDC.SetDCBrushColor(RGB(255, 0, 0));
	aDC.MoveTo(10, 400);
	aDC.LineTo(10, 30);
	aDC.MoveTo(10, 400);
	aDC.LineTo(1000, 400);
	coll->startPos = true;
	int wLine;
	if(curPerson > 0) wLine = 900 / curPerson;
	int hLine;
	for(int i = 0; i < coll->GetLength(); i++)
	{
		Person* p = coll->getPerson();
		if(p == NULL) break;
		hLine = p->getSumHours() * 4 / 5;
		aDC.Rectangle(10 + i * wLine, 400, 10 + wLine + i * wLine, 400 - hLine);
	}
	CRect rect;
	//CDialogEx::OnOK();
}
