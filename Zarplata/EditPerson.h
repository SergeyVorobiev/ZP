#pragma once
#include "MyCollection.h"
#include "DelPerson.h"
#include "MyTable.h"
// EditPerson dialog

class EditPerson : public CDialogEx
{
	DECLARE_DYNAMIC(EditPerson)

public:
	EditPerson(CWnd* pParent = NULL);   // standard constructor
	virtual ~EditPerson();
	MyCollection* myColl;
	CMyTable* table;
	Person* p;
	bool isEdit;
	bool change;
	int numPerson;
	bool findIndex;
	bool ValidText(CString& text);
	bool ValidValue(CString& text);
// Dialog Data
	enum { IDD = IDD_DIALOG_PERSON1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedOk();
};
