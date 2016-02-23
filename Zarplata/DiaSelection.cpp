// DiaSelection.cpp : implementation file
//

#include "stdafx.h"
#include "Zarplata.h"
#include "DiaSelection.h"
#include "afxdialogex.h"


// DiaSelection dialog

IMPLEMENT_DYNAMIC(DiaSelection, CDialogEx)

DiaSelection::DiaSelection(CWnd* pParent /*=NULL*/)
	: CDialogEx(DiaSelection::IDD, pParent)
{

}

DiaSelection::~DiaSelection()
{
}

void DiaSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CComboBox* box = static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO1));
	CEdit* edit = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT1));
	if(!pDX->m_bSaveAndValidate)
	{
		
		if(coll->moreHours)
			box->SelectString(1, _T("Больше"));
		else
			box->SelectString(1, _T("Меньше"));
		
		edit->SetWindowTextW(ToCString(coll->sortHours));
	}
	else if(pDX->m_bSaveAndValidate)
	{
		CString str;
		box->GetWindowText(str);
		if(str == _T("Больше"))
			coll->moreHours = true;
		else
			coll->moreHours = false;
		DDX_Text(pDX, IDC_EDIT1, coll->sortHours);
	}
}
CString DiaSelection::ToCString(unsigned int value)const
{
	int c, i = 0; 
	CString current;
	CString str;
	while(value > 0)
	{
		i++;
		c = value % 10;
		value/= 10;
		c += 48;
		current = static_cast<char>(c);
		str = current + str;
	}	
	return str;
}

BEGIN_MESSAGE_MAP(DiaSelection, CDialogEx)
END_MESSAGE_MAP()


// DiaSelection message handlers


BOOL DiaSelection::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CEdit* e_hour = static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT1));
	e_hour->SetLimitText(3);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
