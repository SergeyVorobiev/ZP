// EditPerson.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "EditPerson.h"
#include "afxdialogex.h"


// EditPerson dialog

IMPLEMENT_DYNAMIC(EditPerson, CDialogEx)

EditPerson::EditPerson(CWnd* pParent /*=NULL*/)
	: CDialogEx(EditPerson::IDD, pParent)
{
	change = false;
}

EditPerson::~EditPerson()
{
}

void EditPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	if(!pDX->m_bSaveAndValidate)
	{
		if(findIndex)
			p = myColl->getOnIndex(myColl->curMap, numPerson);
		DDX_Text(pDX, IDC_EDIT1, p->getSurname());
		DDX_Text(pDX, IDC_EDIT2, p->getName());
		DDX_Text(pDX, IDC_EDIT3, p->getSecondname());
		DDX_Text(pDX, IDC_EDIT4, p->ToCString(p->getTarif()));
		DDX_Text(pDX, IDC_EDIT5, p->ToCString(p->getKoef()));
		DDX_Text(pDX, IDC_EDIT6, p->ToCString(p->getMinPayment()));
		DDX_Text(pDX, IDC_EDIT7, p->ToCString(p->getSumHours()));
		DDX_Text(pDX, IDC_EDIT8, p->ToCString(p->getOverHours()));
		DDX_Text(pDX, IDC_EDIT9, p->ToCString(p->getDependents()));
		DDX_Text(pDX, IDC_EDIT10, p->ToCString(p->getId()));
	}
	if(pDX->m_bSaveAndValidate && isEdit)
	{
		CString c_tarif;
		CString c_koef;
		CString c_minOplata;
		CEdit* e_tarif = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT4));
		e_tarif->GetWindowTextW(c_tarif);
		CEdit* e_koef = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT5));
		e_koef->GetWindowTextW(c_koef);
		CEdit* e_minOplata = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT6));
		e_minOplata->GetWindowTextW(c_minOplata);
		float koef;
		float minOplata;
		float tarif;
		int sumHours;
		int overHours;
		int dependents;
		int Id;
		if(!c_tarif.GetLength())			{AfxMessageBox(L"Поле \"Тариф\" не заполнено.");										pDX->Fail();}
		else if(!ValidValue(c_tarif))		{AfxMessageBox(L"Поле \"Тариф\" должно состоять только из цифр и точки.");				pDX->Fail();}
		DDX_Text(pDX, IDC_EDIT4, tarif);
		DDV_MinMaxFloat(pDX, tarif, 0, 200000000);
		if(!c_koef.GetLength())				{AfxMessageBox(L"Поле \"Коэффициент\" не заполнено.");									pDX->Fail();}
		else if(!ValidValue(c_tarif))		{AfxMessageBox(L"Поле \"Коэффициент\" должно состоять только из цифр и точки.");		pDX->Fail();}
		DDX_Text(pDX, IDC_EDIT5, koef);
		DDV_MinMaxFloat(pDX, koef, 0, 10000);
		if(!c_minOplata.GetLength())		{AfxMessageBox(L"Поле \"Размер оплаты\" не заполнено.");								pDX->Fail();}
		else if(!ValidValue(c_tarif))		{AfxMessageBox(L"Поле \"Размер оплаты\" должно состоять только из цифр и точки.");		pDX->Fail();}
		DDX_Text(pDX, IDC_EDIT6, minOplata);
		DDV_MinMaxFloat(pDX, minOplata, 0, 10000000);
		DDX_Text(pDX, IDC_EDIT7, sumHours);
		DDV_MinMaxInt(pDX, sumHours, 0, 1000);
		DDX_Text(pDX, IDC_EDIT8, overHours);
		DDV_MinMaxInt(pDX, overHours, 0, 1000);
		DDX_Text(pDX, IDC_EDIT9, dependents);
		DDV_MinMaxInt(pDX, dependents, 0, 100);
		DDX_Text(pDX, IDC_EDIT10, Id);
		DDV_MinMaxInt(pDX, Id, 0, 100000000);
		int normHours = sumHours - overHours;
		if(normHours < 0) {AfxMessageBox(L"Сверхурочных часов должно быть меньше общего количества");								pDX->Fail();}
		if(Id < 10000000)					{AfxMessageBox(L"Поле \"ID\" должно состоять из 8 цифр.");								pDX->Fail();}
		float tempSalary = p->getSalary();
		p->computSalary(normHours, overHours, dependents, minOplata, tarif, koef);
		tempSalary = p->getSalary() - tempSalary;
		myColl->addToSumSalary(tempSalary);
		change = true;
	}
	//CButton* ok = static_cast<CButton*>(this->GetDlgItem(IDC_BUTTON3));
	//ok->ShowWindow(SW_HIDE);
	//ok->SetFocus();
	//CEdit* edit = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT1));
	//edit->SetTabStops(WS_TABSTOP);
	//edit->SetReadOnly(false);
	//edit->SetTabStops(2);
	//edit->SetWindowPos(this, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}


BEGIN_MESSAGE_MAP(EditPerson, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EditPerson::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &EditPerson::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &EditPerson::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL2, &EditPerson::OnBnClickedCancel2)
	ON_BN_CLICKED(IDOK, &EditPerson::OnBnClickedOk)
END_MESSAGE_MAP()


// EditPerson message handlers


BOOL EditPerson::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	isEdit = false;
	CEdit* e_tarif = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT4));
	CEdit* e_koef = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT5));
	CEdit* e_minsize = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT6));
	CEdit* e_sumhour = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT7));
	CEdit* e_overhour = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT8));
	CEdit* e_dependents = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT9));
	CEdit* e_id = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT10));
	e_tarif->SetLimitText(10);
	e_koef->SetLimitText(4);
	e_minsize->SetLimitText(10);
	e_sumhour->SetLimitText(3);
	e_overhour->SetLimitText(3);
	e_dependents->SetLimitText(2);
	e_id->SetLimitText(8);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void EditPerson::OnBnClickedButton1()
{
	CDialogEx::OnOK();
}


void EditPerson::OnBnClickedButton2()
{
	DelPerson del;
	del.DoModal();
	if(del.isDeleted)
	{
		this->myColl->Deleted(p);
		table->dedicatCell = 0;
		change = true;
		CDialogEx::OnOK();
	}
	else{}
}


void EditPerson::OnBnClickedButton3()
{
	CButton* ok = static_cast<CButton*>(this->GetDlgItem(IDC_BUTTON1));
	ok->ShowWindow(SW_HIDE);
	CButton* deleted = static_cast<CButton*>(this->GetDlgItem(IDC_BUTTON2));
	deleted->ShowWindow(SW_HIDE);
	CButton* edit = static_cast<CButton*>(this->GetDlgItem(IDC_BUTTON3));
	edit->ShowWindow(SW_HIDE);
	CButton* change = static_cast<CButton*>(this->GetDlgItem(IDOK));
	change->ShowWindow(true);
	CButton* cancel = static_cast<CButton*>(this->GetDlgItem(IDCANCEL2));
	cancel->ShowWindow(true);
	CEdit* edit4 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT4));
	edit4->SetReadOnly(false);
	CEdit* edit5 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT5));
	edit5->SetReadOnly(false);
	CEdit* edit6 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT6));
	edit6->SetReadOnly(false);
	CEdit* edit7 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT7));
	edit7->SetReadOnly(false);
	CEdit* edit8 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT8));
	edit8->SetReadOnly(false);
	CEdit* edit9 = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT9));
	edit9->SetReadOnly(false);
	//edit->SetTabStops(WS_TABSTOP);
	//edit->SetReadOnly(false);
}


void EditPerson::OnBnClickedCancel2()
{
	isEdit = false;
	CDialogEx::OnOK();
}


void EditPerson::OnBnClickedOk()
{
	isEdit = true;
	CDialogEx::OnOK();
}
bool EditPerson::ValidText(CString& text)
{
	CString validStr("ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ");
	for(int i = 0; i < text.GetLength(); i++)
		if(validStr.Find(text[i]) == -1) return false;
	return true;
}
bool EditPerson::ValidValue(CString& text)
{
	CString validStr("0123456789.");
	for(int i = 0; i < text.GetLength(); i++)
		if(validStr.Find(text[i]) == -1) return false;
	return true;
}