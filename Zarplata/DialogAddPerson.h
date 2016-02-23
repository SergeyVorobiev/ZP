#pragma once

// DialogAddPerson dialog
#include "MyCollection.h"
class DialogAddPerson : public CDialogEx
{
	DECLARE_DYNAMIC(DialogAddPerson)

public:
	DialogAddPerson(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogAddPerson();
	MyCollection* myColl;
	bool change;
// Dialog Data
	enum { IDD = IDD_DIALOG_PERSON };
	virtual BOOL OnInitDialog();
protected:
	 void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	bool ValidText(CString& text);
	bool ValidValue(CString& text);
public:
	afx_msg void OnEnUpdateEdit1();

	
};
