// DelPerson.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "DelPerson.h"
#include "afxdialogex.h"


// DelPerson dialog

IMPLEMENT_DYNAMIC(DelPerson, CDialogEx)

DelPerson::DelPerson(CWnd* pParent /*=NULL*/)
	: CDialogEx(DelPerson::IDD, pParent)
{
	isDeleted = false;
}

DelPerson::~DelPerson()
{
}

void DelPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DelPerson, CDialogEx)
	ON_BN_CLICKED(IDOK, &DelPerson::OnBnClickedOk)
END_MESSAGE_MAP()


// DelPerson message handlers


void DelPerson::OnBnClickedOk()
{
	isDeleted = true;
	CDialogEx::OnOK();
}
