// DialogFindId.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "DialogFindId.h"
#include "afxdialogex.h"


// DialogFindId dialog

IMPLEMENT_DYNAMIC(DialogFindId, CDialogEx)

DialogFindId::DialogFindId(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogFindId::IDD, pParent)
{
	this->isOk = false;
}

DialogFindId::~DialogFindId()
{
}

void DialogFindId::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	if(pDX->m_bSaveAndValidate && isOk)
	{
		unsigned int Id;
		DDX_Text(pDX, IDC_EDIT1, Id);
		DDV_MinMaxInt(pDX, Id, 0, 100000000);
		if(Id < 10000000) {AfxMessageBox(L"Поле \"ID\" должно состоять из 8 цифр."); pDX->Fail();}
		p = myColl->getOnId(Id);
		if(p == NULL) {AfxMessageBox(L"Служащий с таким ID не найден."); pDX->Fail(); isOk = false;}
	}
}


BEGIN_MESSAGE_MAP(DialogFindId, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogFindId::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL10, &DialogFindId::OnBnClickedCancel10)
END_MESSAGE_MAP()


// DialogFindId message handlers


void DialogFindId::OnBnClickedOk()
{
	isOk = true;
	CDialogEx::OnOK();
}




BOOL DialogFindId::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CEdit* e_id = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT1));
	e_id->SetLimitText(8);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void DialogFindId::OnBnClickedCancel10()
{
	isOk = false;
	CDialogEx::OnOK();
}
