// DialogAddPerson.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "DialogAddPerson.h"
#include "afxdialogex.h"


// DialogAddPerson dialog

IMPLEMENT_DYNAMIC(DialogAddPerson, CDialogEx)

DialogAddPerson::DialogAddPerson(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogAddPerson::IDD, pParent)
{
	change = false;
}

DialogAddPerson::~DialogAddPerson()
{
}
BOOL DialogAddPerson::OnInitDialog()
{
	CDialog::OnInitDialog();
	CEdit* e_surname = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT1));
	CEdit* e_name = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT2));
	CEdit* e_secondname = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT3));
	CEdit* e_tarif = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT4));
	CEdit* e_koef = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT5));
	CEdit* e_minsize = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT6));
	CEdit* e_sumhour = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT7));
	CEdit* e_overhour = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT8));
	CEdit* e_dependents = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT9));
	CEdit* e_id = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT10));
	e_surname->SetLimitText(30);
	e_name->SetLimitText(30);
	e_secondname->SetLimitText(30);
	e_tarif->SetLimitText(10);
	e_koef->SetLimitText(4);
	e_minsize->SetLimitText(10);
	e_sumhour->SetLimitText(3);
	e_overhour->SetLimitText(3);
	e_dependents->SetLimitText(2);
	e_id->SetLimitText(8);
	return TRUE;
}
void DialogAddPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	if(pDX->m_bSaveAndValidate)
	{
		CString name;
		CString surname;
		CString secondname;
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
		DDX_Text(pDX, IDC_EDIT1, surname);
		if(!surname.GetLength())			{AfxMessageBox(L"Поле \"Фамилия\" не заполнено.");										pDX->Fail();}
		else if(!ValidText(surname))		{AfxMessageBox(L"Поле \"Фамилия\" должно состоять только из букв русского алфавита.");	pDX->Fail();}
		DDX_Text(pDX, IDC_EDIT2, name);
		if(!name.GetLength())				{AfxMessageBox(L"Поле \"Имя\" не заполнено.");											pDX->Fail();}
		else if(!ValidText(name))			{AfxMessageBox(L"Поле \"Имя\" должно состоять только из букв русского алфавита.");		pDX->Fail();}
		DDX_Text(pDX, IDC_EDIT3, secondname);
		if(!secondname.GetLength())			{AfxMessageBox(L"Поле \"Отчество\" не заполнено.");										pDX->Fail();}
		else if(!ValidText(secondname))		{AfxMessageBox(L"Поле \"Отчество\" должно состоять только из букв русского алфавита."); pDX->Fail();}
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
		Person* p = new Person(surname, name, secondname, Id);
		p->computSalary(normHours, overHours, dependents, minOplata, tarif, koef);
		if(!myColl->Insert(p))				{AfxMessageBox(L"Служащий с таким идентификатором уже существует"); delete(p);			pDX->Fail();}
		else
			change = true;
	}
}


BEGIN_MESSAGE_MAP(DialogAddPerson, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogAddPerson::OnBnClickedOk)
	ON_EN_UPDATE(IDC_EDIT1, &DialogAddPerson::OnEnUpdateEdit1)
END_MESSAGE_MAP()

	
// DialogAddPerson message handlers


void DialogAddPerson::OnBnClickedOk()
{
	
	//if(!name.GetLength()) AfxMessageBox(L"Поле \"Имя\" не заполнено.");
	//else if(!surname.GetLength()) AfxMessageBox(L"Поле \"Фамилия\" не заполнено.");
	//else if(!secondname.GetLength())  AfxMessageBox(L"Поле \"Отчество\" не заполнено.");
	//else if(Id < 10000000) AfxMessageBox(L"Поле \"ID\" должно иметь 8 знаков.");
	CDialogEx::OnOK();
}
bool DialogAddPerson::ValidText(CString& text)
{
	CString validStr("ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ");
	for(int i = 0; i < text.GetLength(); i++)
		if(validStr.Find(text[i]) == -1) return false;
	return true;
}
bool DialogAddPerson::ValidValue(CString& text)
{
	CString validStr("0123456789.");
	for(int i = 0; i < text.GetLength(); i++)
		if(validStr.Find(text[i]) == -1) return false;
	return true;
}

void DialogAddPerson::OnEnUpdateEdit1()
{
	
}

